/*----------------------------------------------------------------------------
 *      RL-ARM - CAN
 *----------------------------------------------------------------------------
 *      Name:    CAN_Ex1.c
 *      Purpose: RTX CAN Driver usage example
 *      Rev.:    V4.70
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <RTL.h>                      /* RTX kernel functions & defines      */
#include <71x_lib.h>                  /* STR71x definitions                  */
#include <RTX_CAN.h>                  /* CAN Generic functions & defines     */ 

__task void task_init     (void);
__task void task_send_CAN (void);
__task void task_rece_CAN (void);
__task void task_disp     (void);

U32 Tx_val = 0, Rx_val = 0;           /* Global variables used for display   */


/*----------------------------------------------------------------------------
 *  Functions for init and getting input value
 *---------------------------------------------------------------------------*/

void In_Init (void) {
  GPIO_Config(GPIO1, 0x0001, GPIO_HI_AIN_TRI);    /* P1.0: Analog Input      */
  ADC12_Init();                         /* Initialize the converter registers*/
  ADC12_PrescalerConfig(500);           /* Configure the prescaler           */
  ADC12_ModeConfig(ADC12_SINGLE);       /* Enable Single mode of conversion  */
  ADC12_ChannelSelect(ADC12_CHANNEL0);  /* Select channel 0 for conversion   */
  ADC12_ConversionStart();              /* Start the conversion              */
}

unsigned char In_Get (void) {
  U16 val;

  val = ADC12_ConversionValue(ADC12_CHANNEL0);      /* Get conversion result */
                                      /* Converted value is two's complement */
  val = (val + 0x800) & 0xFFF;        /* Convert to U16 (0 - 4095)           */
  val = val >> 4;                     /* Scale AD result to 1 byte           */

  return (val);
}

/*----------------------------------------------------------------------------
 *  Functions for init and output of value on visual element
 *---------------------------------------------------------------------------*/

void Out_Init (void) {
  /* Configure LED pins the GPIO2[8 :15] port pins as Push-Pull Output       */
  GPIO_Config (GPIO2, 0xFF00, GPIO_OUT_PP);
}

void Out_Val (void) {
  U32 val;

  val = Rx_val;                       /* Read value  to local variable       */

  /* Set LED pins the GPIO2[8 :15] port pins to Rx_val value                 */
  GPIO_ByteWrite(GPIO2, GPIO_MSB, val);
}


/*----------------------------------------------------------------------------
 *  Task 0: Initializes and starts other tasks
 *---------------------------------------------------------------------------*/

__task void task_init (void)  {
  os_tsk_create (task_send_CAN, 3);   /* Start          transmit task        */
  os_tsk_create (task_rece_CAN, 4);   /* Start           receive task        */
  os_tsk_create (task_disp    , 2);   /* Start displaying to LCD task        */
  os_tsk_delete_self();               /* End      initialization task        */
}

/*----------------------------------------------------------------------------
 *  Task 1: Sends message with input value in data[0] over CAN periodically
 *---------------------------------------------------------------------------*/

__task void task_send_CAN (void)  {
  /* Initialize message  = { ID, {data[0] .. data[7]}, LEN, CHANNEL, FORMAT, TYPE } */
  CAN_msg msg_send       = { 33, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   
                              1, 1, STANDARD_FORMAT, DATA_FRAME };

  CAN_init (1, 500000);               /* CAN controller 1 init, 500 kbit/s   */

  /* Transmit object does not have to be enabled but channel has to be 
     reserved for tansmitting, in this example channel 1 is reserved for 
     transmission                                                            */

  CAN_rx_object (1, 2,  33, DATA_TYPE | STANDARD_TYPE); /* Enable reception  */
                                      /* of message on controller 1, channel */
                                      /* 2, data frame with standard id 33   */
  CAN_start (1);                      /* Start controller 1                  */

  /* The activation of test mode in line below is used for enabling 
     self-testing mode when CAN controller receives the message it sends so 
     program functionality can be tested without another CAN device          */
  /* COMMENT THE LINE BELOW TO ENABLE DEVICE TO PARTICIPATE IN CAN NETWORK   */
  CAN_EnterTestMode (CAN_TESTR_LBACK | CAN_TESTR_SILENT);   /* Loopback and  */
                                      /* Silent Mode (self-test)             */

  os_dly_wait (10);                   /* Wait for AD to get first data       */

  for (;;)  {
    msg_send.data[0] = In_Get ();     /* Data[0] field = analog value from   */
                                      /* potentiometer                       */

    CAN_send (1, &msg_send, 0x0F00);  /* Send msg_send on controller 1       */
    Tx_val = msg_send.data[0];
    os_dly_wait (100);                /* Wait 1 second                       */
  }
}

/*----------------------------------------------------------------------------
 *  Task 2: Received CAN message
 *---------------------------------------------------------------------------*/

__task void task_rece_CAN (void)  {
  CAN_msg msg_rece;

  for (;;)  {
    /* When message arrives store received value to global variable Rx_val   */
    if (CAN_receive (1, &msg_rece, 0x00FF) == CAN_OK)  {
      Rx_val = msg_rece.data[0];
    }
  }
}

/*----------------------------------------------------------------------------
 *  Task 3: Activate visual outputs
 *---------------------------------------------------------------------------*/

__task void task_disp (void)  {
  for (;;)  {
    Out_Val ();                       /* Output info on visual outputs       */
    os_dly_wait (10);                 /* Wait 100 ms and display again       */
  }
}


/*----------------------------------------------------------------------------
 *        Main: Initialize and start RTX Kernel
 *---------------------------------------------------------------------------*/

int main (void)  {                    /* Program execution starts here       */
  RCCU_MCLKConfig(RCCU_DEFAULT);      /* MCLK = RCLK                         */
  RCCU_FCLKConfig(RCCU_RCLK_2);       /* FCLK = RCLK/2 (for CAN)             */
  RCCU_PCLKConfig(RCCU_RCLK_4);       /* PCLK = RCLK/4                       */
  RCCU_PLL1Config(RCCU_PLL1_Mul_12, RCCU_Div_2);  /* 48MHz PLL @ 16MHz XTAL  */

  while (RCCU_FlagStatus(RCCU_PLL1_LOCK) == RESET); /* Wait for PLL to Lock  */
  RCCU_RCLKSourceConfig(RCCU_PLL1_Output);        /* Select PLL for RCLK     */

  In_Init  ();                        /* Initialize input                    */
                                      /* - Analog voltage                    */
  Out_Init ();                        /* Initialize visual outputs           */
                                      /* - LEDs, LCD display (2x16 chars)    */

  os_sys_init (task_init);            /* Initialize OS and start init task   */
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/

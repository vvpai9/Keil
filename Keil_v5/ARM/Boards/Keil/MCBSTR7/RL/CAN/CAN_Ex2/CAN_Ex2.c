/*----------------------------------------------------------------------------
 *      RL-ARM - CAN
 *----------------------------------------------------------------------------
 *      Name:    CAN_Ex2.c
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
__task void task_set_CAN  (void);
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

  val = Tx_val;                       /* Read value  to local variable       */

  /* Set LED pins the GPIO2[8 :15] port pins to Rx_val value                 */
  GPIO_ByteWrite(GPIO2, GPIO_MSB, val);
}


/*----------------------------------------------------------------------------
 *  Task 0: Initializes and starts other tasks
 *---------------------------------------------------------------------------*/

__task void task_init (void)  {
  os_tsk_create (task_set_CAN , 3);   /* Start          transmit task        */
  os_tsk_create (task_disp    , 2);   /* Start displaying to LCD task        */
  os_tsk_delete_self();               /* End      initialization task        */
}

/*----------------------------------------------------------------------------
 *  Task 1: Sets message with input value in data[0] periodically (every 1s)
 *---------------------------------------------------------------------------*/

__task void task_set_CAN (void)  {
  /* Initialize message  = { ID, {data[0] .. data[7]}, LEN, CHANNEL, FORMAT, TYPE } */
  CAN_msg msg_for_remote = { 33, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   
                              1, 2, STANDARD_FORMAT, DATA_FRAME };

  CAN_init (1, 500000);               /* CAN controller 1 init, 500 kbit/s   */
  CAN_start (1);                      /* Start controller 1                  */

  os_dly_wait (10);                   /* Wait for AD to get first data       */

  for (;;)  {
    msg_for_remote.data[0] = In_Get (); /* Data[0] field = analog value from 
                                           potentiometer                     */

    CAN_set (1, &msg_for_remote, 0x00FF); /* Set the message that will 
                                             automatically be sent upon 
                                             reception of REMOTE FRAME       */
    Tx_val = msg_for_remote.data[0];
    os_dly_wait (100);                /* Wait 1 second                       */
  }
}

/*----------------------------------------------------------------------------
 *  Task 2: Activate visual outputs
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

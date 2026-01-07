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
#include <73x_lib.h>                  /* STR73x library definitions          */
#include <RTX_CAN.h>                  /* CAN Generic functions & defines     */ 

__task void task_init     (void);
__task void task_CAN      (void);
__task void task_disp_mux (void);

U32 Tx_val = 0, Rx_val = 0;           /* Global variables used for display   */

                                      /* LED segments for numbers 0 .. 9     */
const unsigned char LED7SEG[] = { 0xC0, 0xF9, 0xA4, 0xB0, 
                                  0x99, 0x92, 0x82, 0xF8,
                                  0x80, 0x90, 0x88, 0x83,
                                  0xC6, 0xA1, 0x86, 0x8E
                                } ;


/*----------------------------------------------------------------------------
 *  Functions for init and getting input value
 *---------------------------------------------------------------------------*/

void In_Init (void) {
  GPIO_InitTypeDef  GPIO_InitStruct;  /* Declare GPIO  structure             */
  ADC_InitTypeDef   ADC_InitStruct;   /* Declare ADC   structure             */

  /* Setup GPIO3 - AD converter pin setup (P3.0)                             */
  CFG_PeripheralClockConfig(CFG_CLK_GPIO3, ENABLE);
  GPIO_InitStruct.GPIO_Mode             = GPIO_Mode_HI_AIN_TRI;
  GPIO_InitStruct.GPIO_Pins             = GPIO_PIN_0;
  GPIO_Init(GPIO3, &GPIO_InitStruct);

  /* Setup AD converter configuration                                        */
  CFG_PeripheralClockConfig(CFG_CLK_ADC, ENABLE);
  ADC_StructInit(&ADC_InitStruct);
  ADC_InitStruct.ADC_Calibration        = ADC_Calibration_ON;
  ADC_InitStruct.ADC_CalibAverage       = ADC_CalibAverage_Enable;
  ADC_InitStruct.ADC_AutoClockOff       = ADC_AutoClockOff_Disable;
  ADC_InitStruct.ADC_ConversionMode     = ADC_ConversionMode_OneShot;
  ADC_InitStruct.ADC_SamplingPrescaler  = 0x7;
  ADC_InitStruct.ADC_ConversionPrescaler= 0x0;
  ADC_InitStruct.ADC_FirstChannel       = ADC_CHANNEL0 ;
  ADC_InitStruct.ADC_ChannelNumber      = 1;
  ADC_Init(&ADC_InitStruct);
  ADC_Cmd(ENABLE);                     /* Enable the AD converter            */
}

unsigned char In_Get (void) {
  U16 val;

  ADC_ConversionCmd(ADC_ConversionStart);           /* Start AD conversion   */
  while (!ADC_FlagStatus(ADC_FLAG_EOC));            /* Wait end of conversion*/
  val = ADC_GetConversionValue(ADC_CHANNEL0);       /* Get conversion result */

  return (val>>2);
}

/*----------------------------------------------------------------------------
 *  Functions for init and output of value on visual element
 *---------------------------------------------------------------------------*/

void Out_Init (void) {
  GPIO_InitTypeDef  GPIO_InitStruct;  /* Declare GPIO  structure             */

  /* Setup GPIO0 - 7 segment LED displays (P0.0 .. P0.9)                     */
  CFG_PeripheralClockConfig(CFG_CLK_GPIO0, ENABLE);
  GPIO_InitStruct.GPIO_Mode             = GPIO_Mode_OUT_PP;
  GPIO_InitStruct.GPIO_Pins             = GPIO_PIN_ALL;
  GPIO_Init(GPIO0, &GPIO_InitStruct);
}

void Out_Val (void) {
  static unsigned short DISP_active = 1;
  U32 val1;
  val1 = Rx_val;

  if (DISP_active == 0)
    /* Output high 4 bits to right 7-seg                                     */
    GPIO_WordWrite(GPIO0, LED7SEG[(val1>>4) & 0x0F] | 0x0200);
  else
    /* Output  low 4 bits to left 7-seg                                      */
    GPIO_WordWrite(GPIO0, LED7SEG[(val1)    & 0x0F] | 0x0100);

  DISP_active = !DISP_active;         /* Toggle active 7-seg LED display     */
}


/*----------------------------------------------------------------------------
 *  Task 0: Initializes and starts other tasks
 *---------------------------------------------------------------------------*/

__task void task_init (void)  {
  os_tsk_create (task_CAN, 2);        /* Start CAN               task        */
  os_tsk_create (task_disp_mux, 4);   /* Start disp multiplexing task        */
  os_tsk_delete_self();               /* End      initialization task        */
}

/*----------------------------------------------------------------------------
 *  Task 1: 1. set the message to be sent on remote request receive (on CAN1)
 *          2. send the remote request                              (on CAN2)
 *          3. receive the answer on remote request                 (on CAN2)
 *---------------------------------------------------------------------------*/

__task void task_CAN (void)  {
  /* Initialize message  = { ID, {data[0] .. data[7]}, LEN, CHANNEL, FORMAT, TYPE } */
  CAN_msg msg_send       = { 33, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   
                              1, 2, STANDARD_FORMAT, REMOTE_FRAME };
  CAN_msg msg_set        = { 33, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   
                              1, 1, STANDARD_FORMAT, DATA_FRAME };
  CAN_msg msg_rece;

  CAN_init (1, 500000);               /* CAN controller 1 init, 500 kbit/s   */
  CAN_init (2, 500000);               /* CAN controller 2 init, 500 kbit/s   */
  CAN_rx_object (2, 1,  33, DATA_TYPE | STANDARD_TYPE); /* Enable reception  */
                                      /* of message on controller 2, channel */
                                      /* 1, data frame with standard id 33   */

  CAN_start (1);                      /* Start CAN controller 1              */
  CAN_start (2);                      /* Start CAN controller 2              */

  for (;;)  {
    msg_set.data[0] = In_Get ();      /* Data[0] field = analog value from   */
                                      /* potentiometer                       */
    CAN_set     (1, &msg_set , 0x0F00);  /* Set answer to remote frame       */
    CAN_request (2, &msg_send, 0x0F00);  /* Send request on controller 2     */

    /* When message arrives store received value to global variable Rx_val   */
    if (CAN_receive (2, &msg_rece, 0x00FF) == CAN_OK)  {
      Rx_val = msg_rece.data[0];
    }

    os_dly_wait (100);                /* Wait 1 second                       */
  }
}

/*----------------------------------------------------------------------------
 *  Task 3: Activate visual outputs
 *---------------------------------------------------------------------------*/

__task void task_disp_mux (void)  {
  for (;;)  {
    Out_Val ();
    os_dly_wait (1);
  }
}


/*----------------------------------------------------------------------------
 *        Main: Initialize and start RTX Kernel
 *---------------------------------------------------------------------------*/

int main (void)  {                    /* Program execution starts here       */
  CMU_InitTypeDef   CMU_InitStruct;   /* Declare CMU   structure             */
  PRCCU_InitTypeDef PRCCU_InitStruct; /* Declare PRCCU structure             */

  /* Enable Enhanced Interrupt Controller (EIC)                              */
  CFG_PeripheralClockConfig(CFG_CLK_EIC, ENABLE);

  /* Power, Reset and Clock Control Unit (PRCCU) Setup                       */
  /* Setup clock to 32 MHz                                                   */
  PRCCU_StructInit(&PRCCU_InitStruct);  
  PRCCU_InitStruct.PRCCU_MCLKSRC_SRC    = PRCCU_MCLKSRC_PLL;
  PRCCU_InitStruct.PRCCU_DIV2           = ENABLE;
  PRCCU_InitStruct.PRCCU_PLLMUL         = PRCCU_PLLMUL_16;
  PRCCU_InitStruct.PRCCU_PLLDIV         = PRCCU_PLLDIV_2;
  PRCCU_Init(&PRCCU_InitStruct);

  /* Clock Monitor Unit (CMU) Setup                                          */
  /* Setup CMU to use oscillator                                             */
  CMU_DeInit();
  CMU_StructInit(&CMU_InitStruct);
  CMU_InitStruct.CMU_CKSEL0             = CMU_CKSEL0_CKOSC;
  CMU_Init(&CMU_InitStruct);

  In_Init  ();                        /* Initialize input                    */
                                      /* - Analog voltage                    */
  Out_Init ();                        /* Initialize visual outputs           */
                                      /* - two 7-segment LED displays        */

  os_sys_init (task_init);            /* Initialize OS and start init task   */
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/

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
#include <LPC29xx.h>                  /* LPC29xx definitions                 */
#include <RTX_CAN.h>                  /* CAN Generic functions & defines     */ 
#include <stdio.h>
#include "LCD.h"

__task void task_init     (void);
__task void task_send_CAN (void);
__task void task_rece_CAN (void);
__task void task_disp     (void);

U8   Tx_val = 0, Rx_val = 0;          /* Transmit and receive values         */
U32  Tx_cnt = 0, Rx_cnt = 0;          /* Transmit and receive counters       */
U8   lcd_text[2][16+1];               /* Buffer for LCD text                 */

extern volatile U32 AD_last;          /* Last converted value                */


/*----------------------------------------------------------------------------
 *  Functions for init and getting input value
 *---------------------------------------------------------------------------*/

void In_Init (void) {
  /* Configure MSCSS clock = PLL clock / 2 = 80 MHz (max allowed 80 MHz)     */
  MSCSS_CLK_CONF   = (2UL << 24) | (1 << 11) | (1 << 2);

  MTIM0_PR   = (80000000 / 1000) - 1; /* Prescaler to drive timer with 1 ms  */
  MTIM0_MR2  = (100 - 1);             /* Match value = 100 * 1ms = 100 ms    */
  MTIM0_MCR  = (1 << 4);              /* On Match 2 event reset timer        */
  MTIM0_EMR |= (3 << 8);              /* Match 2 event generate logic 1      */
  MTIM0_TCR  = 1;                     /* Start Timer 0                       */

  /* Configure ADC clock = FDIV0 / 1 = 4 MHz (max allowed 4.5 MHz)           */
  ADC_CLK_CONF     = (5UL << 24) | (1 << 11) | (0 << 2);

  ADC2_CTRL  = (1<<1);                /* Stop  ADC conversion                */

  SFSP0_16         = 1;               /* Configure P0.16 as analog input     */

  /* Setup ADC2 interrupt generation                                         */
  INT_REQUEST_18   = (1  << 28) |     /* Enable setting of priority level    */
                     (1  << 27) |     /* Enable setting interrupt target     */
                     (1  << 26) |     /* Write enable of new settings        */
                     (1  << 16) |     /* Enable interrupt request            */
                     (1  <<  8) |     /* Interrupt target is IRQ interrupt   */
                     (15 <<  0) ;     /* Priority level 15, disable nesting  */

  /* Setup ADC2 IN0 to convert in 10-bit resolution and generate interrupt   */
  ADC2_ACC0        = 0x0000000A;      /* Set ADC2 IN0 10-bit resolution      */
  ADC2_CONFIG      = (1 << 14);       /* ADC single scan, start on pos edge  */
  ADC2_CTRL        = 4;               /* Copy the configuration              */
  ADC2_INT_SET_ENABLE = 1;            /* Enable end of scan interrupt        */
}

unsigned char In_Get (void) {
  return (AD_last >> 2);
}

/*----------------------------------------------------------------------------
 *  Functions for init and output of value on visual element
 *---------------------------------------------------------------------------*/

void Out_Init (void) {
  GPIO1_DR |= (0xFFUL << 24);         /* Configure LEDs GPIO pins as Outputs */

  LCD_init ();                        /* Initialize LCD display              */
  LCD_cls ();
}

void Out_Val (void) {
  LCD_print (0, 0, "    RL-ARM      ");
  LCD_print (0, 1, " CAN_Ex1 example");
  os_dly_wait (200);
  LCD_print (0, 1, "  www.keil.com  ");
  os_dly_wait (400);
  LCD_print (0, 0, "      KEIL      ");
  LCD_print (0, 1, " An ARM Company ");
  os_dly_wait (200);
  LCD_print (0, 0, "CAN1: Rx = 0x00 ");
  LCD_print (0, 1, "CAN2: Tx = 0x00 ");

  for (;;) {
    sprintf ((char *)lcd_text[0],"%.2X", Rx_val);
    sprintf ((char *)lcd_text[1],"%.2X", Tx_val);
    LCD_print (13, 0, (U8 *)&lcd_text[0]);
    LCD_print (13, 1, (U8 *)&lcd_text[1]);

    GPIO1_OR  = ~(0xFFUL << 24);
    GPIO1_OR |= (Tx_cnt & 0x0F) << 24;
    GPIO1_OR |= (Rx_cnt & 0x0F) << 28;
    os_dly_wait (100);
  }
}


/*----------------------------------------------------------------------------
 *  Task 0: Initializes and starts other tasks
 *---------------------------------------------------------------------------*/

__task void task_init (void)  {
  os_tsk_create (task_send_CAN, 3);   /* Start       transmit task           */
  os_tsk_create (task_rece_CAN, 4);   /* Start        receive task           */
  os_tsk_create (task_disp    , 2);   /* Start     displaying task           */
  os_tsk_delete_self();               /* End   initialization task           */
}

/*----------------------------------------------------------------------------
 *  Task 1: Sends message with input value in data[0] over CAN periodically
 *---------------------------------------------------------------------------*/

__task void task_send_CAN (void)  {
  /* Initialize message  = { ID, {data[0] .. data[7]}, LEN, CHANNEL, FORMAT, TYPE } */
  CAN_msg msg_send       = { 33, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   
                              1, 2, STANDARD_FORMAT, DATA_FRAME };

  CAN_init (1, 500000);               /* CAN controller 1 init, 500 kbit/s   */
  CAN_init (2, 500000);               /* CAN controller 2 init, 500 kbit/s   */

  /* Transmit object does not have to be enabled but channel has to be 
     reserved for transmitting, in this example channel 1 is reserved for 
     transmission                                                            */

  CAN_rx_object (1, 2,  33, DATA_TYPE | STANDARD_TYPE); /* Enable reception  */
                                      /* of message on controller 1, channel */
                                      /* is not used for LPC (can be set to  */
                                      /* whatever value), data frame with    */
                                      /* standard id 33                      */
  CAN_start (1);                      /* Start controller 1                  */
  CAN_start (2);                      /* Start controller 2                  */

  os_dly_wait (10);                   /* Wait 100 ms, to get first AD result */

  for (;;)  {
    msg_send.data[0] = In_Get ();     /* Data[0] field = analog value from   */
                                      /* potentiometer                       */
    Tx_val = msg_send.data[0];

    CAN_send (2, &msg_send, 0x0F00);  /* Send msg_send on controller 2       */
    Tx_cnt++;                         /* Increment transmit counter          */
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
      Rx_cnt++;                       /* Increment receive counter           */
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

  In_Init  ();                        /* Initialize input                    */
                                      /* - Analog voltage                    */
  Out_Init ();                        /* Initialize visual outputs           */
                                      /* - LCD display, LEDs                 */

  os_sys_init (task_init);            /* Initialize OS and start init task   */
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/

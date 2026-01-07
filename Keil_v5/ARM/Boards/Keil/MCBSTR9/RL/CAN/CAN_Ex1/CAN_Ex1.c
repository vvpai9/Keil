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
#include <91x_lib.h>                  /* STR91x library definitions          */
#include <RTX_CAN.h>                  /* CAN Generic functions & defines     */ 
#include "LCD.h"                      /* LCD functions prototypes            */

__task void task_init     (void);
__task void task_send_CAN (void);
__task void task_rece_CAN (void);
__task void task_disp     (void);

U32 Tx_val = 0, Rx_val = 0;           /* Global variables used for display   */

char hex_chars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};


/*----------------------------------------------------------------------------
 *  Function for converting 1 byte to string in hexadecimal notation
 *---------------------------------------------------------------------------*/

void Hex_Str (unsigned char hex, char *str) {
  *str++ = '0';
  *str++ = 'x';
  *str++ = hex_chars[hex >>  4];
  *str++ = hex_chars[hex & 0xF];
}

/*----------------------------------------------------------------------------
 *  Functions for init and getting input value
 *---------------------------------------------------------------------------*/

void In_Init (void) {
  int n;

  /* ADC Pin Setup                                                           */
  SCU->GPIOIN[4]  |= 0x01;            /* P4.0 input  - mode 0                */
  SCU->GPIOOUT[4] &= 0xFFFC;          /* P4.0 output - mode 0                */
  GPIO4->DDR      &= 0xFE;            /* P4.0 direction - input              */
  SCU->GPIOANA    |= 0x0001;          /* P4.0 analog mode ON                 */

  /* ADC Setup                                                               */
  ADC->CR = ADC->CR | 0x0002;         /* Set POR bit                         */
  for (n = 0; n < 100000; n ++);      /* Wait > 1 ms                         */
  ADC->CR = ADC->CR & 0xFFF7;         /* Clear STB bit                       */
  for (n = 0; n < 1500; n ++);        /* Wait > 15 us                        */
  ADC->CCR = 0x0003;                  /* AD Conversion, No WDG on Ch 0       */
}

unsigned char In_Get (void) {
  U16 val;

  ADC->CR = ADC->CR | 0x0003;           /* Set STR bit (Start Conversion)    */
                                        /* on Channel 0                      */
  while ((ADC->CR & 0x8000) != 0x8000); /* Wait for AD to finish             */

  val = ADC->DR0 & 0x03FF;              /* Get conversion result             */
  val = (val >> 2) & 0xFF;              /* Scale analog value to 8 bits      */

  return (val);
}

/*----------------------------------------------------------------------------
 *  Functions for init and output of value on visual element
 *---------------------------------------------------------------------------*/

void Out_Init (void) {
  int n;

  /* Setup P7.0..7 as outputs for LEDs                                       */
  SCU->GPIOOUT[7]  = 0x5555;          /* P7.0..7 output - mode 1             */
  GPIO7->DDR       = 0xFF;            /* P7.0..7 Outputs (LED Data)          */

  /* LCD Pins Setup                                                          */
  GPIO8->DDR       = 0xFF;            /* P8.0..7 Outputs (LCD Data)          */
  GPIO9->DDR       = 0x07;            /* P9.0..2 Outputs (LCD Control)       */

  /* Setup LCD                                                               */
  lcd_init();                         /* Initialize the LCD display          */
  lcd_clear();                        /* Clear the LCD display               */
  lcd_print ("MCBSTR9 CAN DEMO");     /* Display string on LCD display       */
  set_cursor (0, 1);                  /* Set cursor position on LCD display  */
  lcd_print ("  www.keil.com  ");
  for (n = 0; n < 2500000; n ++);     /* Wait for initial display (~5s)      */

  lcd_clear ();
  lcd_print ("CAN at 500kbit/s");
}

void Out_Val (void) {
  U32 val1, val2;
  static char disp_buf[] = "Tx:    , Rx:    ";

  val1 = Tx_val;                      /* Read values to local variable       */
  val2 = Rx_val;    

  GPIO7->DR[0x3FC] = (U8) Rx_val;     /* Activate LEDs                       */

  Hex_Str(val1, &disp_buf[ 3]);       /* Display Tx and Rx values to LCD disp*/ 
  Hex_Str(val2, &disp_buf[12]);
  set_cursor (0, 1);
  lcd_print  ((char *)disp_buf);
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
     reserved for transmitting, in this example channel 1 is reserved for 
     transmission                                                            */

  CAN_rx_object (1, 2,  33, DATA_TYPE | STANDARD_TYPE); /* Enable reception  */
                                      /* of message on controller 1, channel */
                                      /* 2, data frame with standard id 33   */

  CAN_start (1);                      /* Start CAN controller 1              */

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

  In_Init  ();                        /* Initialize input                    */
                                      /* - Analog voltage                    */
  Out_Init ();                        /* Initialize visual outputs           */
                                      /* - LEDs, LCD display (2x16 chars)    */

  os_sys_init (task_init);            /* Initialize OS and start init task   */
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/

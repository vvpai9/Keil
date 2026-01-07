/*------------------------------------------------------------------------------
 *      RL-ARM - USB
 *------------------------------------------------------------------------------
 *      Name:    USBD_Demo.c
 *      Purpose: USB Device Demonstration
 *      Rev.:    V4.70
 *------------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <RTL.h>
#include <rl_usb.h>
#include "LCD.h"
#include "UART.h"
#include <stdio.h>


__task void init (void) {
  int32_t usb_rx_ch = -1;
  int32_t usb_tx_ch = -1;

  lcd_init  ();
  lcd_clear ();
  lcd_print ("USB CDC ACM RTX ");
  set_cursor(0, 1);
  lcd_print ("  www.keil.com  ");

  usbd_init();                          /* USB Device Initialization          */
  usbd_connect(__TRUE);                 /* USB Device Connect                 */
  while (!usbd_configured ());          /* Wait for device to configure       */

  while (1) {                           /* Loop forever                       */
                                        /* USB -> UART                        */
    if (usb_rx_ch == -1) {
      usb_rx_ch = USBD_CDC_ACM_GetChar ();
    }
    if (usb_rx_ch != -1) {
      if (UART_PutChar (usb_rx_ch) == usb_rx_ch) {
        usb_rx_ch = -1;
      }
    }

                                        /* UART -> USB                        */
    if (usb_tx_ch == -1) {
      usb_tx_ch = UART_GetChar ();
    }
    if (usb_tx_ch != -1) {
      if (USBD_CDC_ACM_PutChar (usb_tx_ch) == usb_tx_ch) {
        usb_tx_ch = -1;
      }
    }
  }
}


int main (void) {

  os_sys_init(init);                    /* Init RTX and start 'init'          */
}

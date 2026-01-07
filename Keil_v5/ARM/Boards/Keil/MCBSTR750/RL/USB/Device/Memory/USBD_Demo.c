/*----------------------------------------------------------------------------
 *      RL-ARM - USB
 *----------------------------------------------------------------------------
 *      Name:    USBD_Demo.c
 *      Purpose: USB Device Demonstration
 *      Rev.:    V4.70
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <RTL.h>
#include <rl_usb.h>
#include "LCD.h"

int main (void) {
  lcd_init  ();
  lcd_clear ();
  lcd_print ("USB Device Demo ");
  set_cursor(0, 1);
  lcd_print ("  www.keil.com  ");

  usbd_init();                          /* USB Initialization                 */
  usbd_connect(__TRUE);                 /* USB Connect                        */

  while (1);                            /* Loop forever                       */
}

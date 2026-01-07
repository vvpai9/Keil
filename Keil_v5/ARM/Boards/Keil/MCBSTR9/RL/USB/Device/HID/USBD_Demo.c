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
#include <91x_lib.H>

/* Push Button Definitions                                                    */
#define S2      0x20                    /* P3.5 (INT5)                        */
#define S3      0x40                    /* P3.6 (INT6)                        */

int main (void) {
  static U8 but_ex;
         U8 but;
         U8 buf[1];

  lcd_init  ();
  lcd_clear ();
  lcd_print ("USB Device Demo ");
  set_cursor(0, 1);
  lcd_print ("  www.keil.com  ");

  usbd_init();                          /* USB Device Initialization          */
  usbd_connect(__TRUE);                 /* USB Device Connect                 */

  while (1) {                           /* Loop forever                       */
    but = ((((GPIO3->DR[S2*4]) ^ S2) >> 5) & 0x01) |
          ((((GPIO3->DR[S3*4]) ^ S3) >> 5) & 0x02) ;
    if (but ^ but_ex) {
      buf[0] = but;
      usbd_hid_get_report_trigger(0, buf, 1);
      but_ex = but;
    }
  };
}

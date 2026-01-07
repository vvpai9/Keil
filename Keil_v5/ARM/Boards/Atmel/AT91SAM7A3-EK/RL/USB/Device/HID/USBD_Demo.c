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
#include <AT91SAM7A3.H>

int main (void) {
  static U8 but_ex;
         U8 but;
         U8 buf[1];

  usbd_init();                          /* USB Device Initialization          */
  usbd_connect(__TRUE);                 /* USB Device Connect                 */

  while (1) {                           /* Loop forever                       */
    but = (((AT91C_BASE_PIOB->PIO_PDSR ^ (1 << 12)) >> 12) & 0x01) |
          (((AT91C_BASE_PIOB->PIO_PDSR ^ (1 << 13)) >> 12) & 0x02) |
          (((AT91C_BASE_PIOB->PIO_PDSR ^ (1 <<  8)) >>  6) & 0x04) |
          (((AT91C_BASE_PIOB->PIO_PDSR ^ (1 <<  9)) >>  6) & 0x08) |
          (((AT91C_BASE_PIOB->PIO_PDSR ^ (1 << 14)) >> 10) & 0x10) ;
    if (but ^ but_ex) {
      buf[0] = but;
      usbd_hid_get_report_trigger(0, buf, 1);
      but_ex = but;
    }
  };
}

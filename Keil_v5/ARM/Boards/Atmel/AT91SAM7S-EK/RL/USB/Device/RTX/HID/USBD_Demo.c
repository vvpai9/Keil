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
#include <AT91SAM7S256.H>

__task void init (void) {
  static U8 but_ex;
         U8 but;
         U8 buf[1];

  os_tsk_prio_self(100);
  usbd_init();                          /* USB Device Initialization          */
  usbd_connect(__TRUE);                 /* USB Device Connect                 */
  os_tsk_prio_self(1);
  while (1) {                           /* Loop forever                       */
    but = (((AT91C_BASE_PIOA->PIO_PDSR ^ (AT91C_PIO_PA19 | AT91C_PIO_PA20)) >> 19) & 0x03) |
          (((AT91C_BASE_PIOA->PIO_PDSR ^ (                 AT91C_PIO_PA15)) >> 13) & 0x04) |
          (((AT91C_BASE_PIOA->PIO_PDSR ^ (                 AT91C_PIO_PA14)) >> 11) & 0x08) ;
    if (but ^ but_ex) {
      buf[0] = but;
      usbd_hid_get_report_trigger(0, buf, 1);
      but_ex = but;
    }
  };
}

int main (void) {

  os_sys_init(init);                    /* Init RTX and start 'init'          */
}

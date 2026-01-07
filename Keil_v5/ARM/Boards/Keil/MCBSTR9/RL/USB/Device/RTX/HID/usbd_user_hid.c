/*----------------------------------------------------------------------------
 *      RL-ARM - USB
 *----------------------------------------------------------------------------
 *      Name:    usbd_user_hid.c
 *      Purpose: Human Interface Device Class User module
 *      Rev.:    V4.70
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <RTL.h>
#include <rl_usb.h>
#include <91x_lib.H>

/* Push Button Definitions                                                    */
#define S2      0x20                    /* P3.5 (INT5)                        */
#define S3      0x40                    /* P3.6 (INT6)                        */

/* LED Definitions                                                            */
#define LEDMSK  0xFF                    /* P7.0..7                            */

U8 feat;

void usbd_hid_init (void) {
  /* Push Button Setup                                                        */
  SCU->GPIOOUT[3]   = 0x0000;           /* P3.0..7 no output                  */
  GPIO3->DDR        = 0x00;             /* P3.0..7 Input (Push Buttons)       */

  /* LED Setup                                                                */
  SCU->GPIOOUT[7]   = 0x5555;           /* P7.0..7 output - mode 1            */
  GPIO7->DDR        = 0xFF;             /* P7.0..7 Outputs (LED Data)         */
  GPIO7->DR[0xFF*4] = 0x00;             /* Clear LEDs                         */
}

int usbd_hid_get_report (U8 rtype, U8 rid, U8 *buf, U8 req) {

  switch (rtype) {
    case HID_REPORT_INPUT:
      switch (rid) {
         case 0:
          switch (req) {
            case USBD_HID_REQ_EP_CTRL:
            case USBD_HID_REQ_PERIOD_UPDATE:
              *buf = ((((GPIO3->DR[S2*4]) ^ S2) >> 5) & 0x01) |
                     ((((GPIO3->DR[S3*4]) ^ S3) >> 5) & 0x02) ;
              return (1);
            case USBD_HID_REQ_EP_INT:
              break;
          }
           break;
      }
      break;
    case HID_REPORT_FEATURE:
      buf[0] = feat;
      return (1);
  }
  return (0);
}

void usbd_hid_set_report (U8 rtype, U8 rid, U8 *buf, int len, U8 req) {

  switch (rtype) {
    case HID_REPORT_OUTPUT:
      GPIO7->DR[0xFF*4] = *buf;
      break;
    case HID_REPORT_FEATURE:
      feat = buf[0];
      break;
  }
}

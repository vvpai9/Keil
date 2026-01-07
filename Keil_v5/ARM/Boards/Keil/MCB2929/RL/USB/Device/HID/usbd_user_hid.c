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
#include <LPC29xx.H>

/* Push Button Definitions                                                    */
#define PB_INT0         0x04000000      /* P2.26                              */

/* LED Definitions                                                            */
#define LED_MSK         0x00FF0000      /* P2.16..23                          */

U8 feat;

void usbd_hid_init (void) {
  /* Configure the BUTTON's GPIO pins as Inputs with internal pull-up         */
  SFSP2_26  =  (0x03   << 2);
  SFSP2_27  =  (0x03   << 2);
  GPIO2_DR &= ~(0x03UL << 26);

  /* Configure the LED's GPIO pins as Outputs: P2.16 -- P2.23                 */
  GPIO2_DR |=  (0xFF << 16);
}

int usbd_hid_get_report (U8 rtype, U8 rid, U8 *buf, U8 req) {

  switch (rtype) {
    case HID_REPORT_INPUT:
      switch (rid) {
         case 0:
          switch (req) {
            case USBD_HID_REQ_EP_CTRL:
            case USBD_HID_REQ_PERIOD_UPDATE:
             *buf = ((GPIO2_PINS & PB_INT0) == 0);
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
      GPIO2_OR &= ~LED_MSK;
      GPIO2_OR |=  (*buf << 16);
      break;
    case HID_REPORT_FEATURE:
      feat = buf[0];
      break;
  }
}

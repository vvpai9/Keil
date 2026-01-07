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
#include <71x_lib.H>

/* Push Button Definitions                                                    */
#define S2      0x00002000              /* P1.13 (Interrupt)                  */
#define S3      0x00008000              /* P0.15 (Wake-Up)                    */

/* LED Definitions                                                            */
#define LEDMSK  0x0000FF00              /* P2.8..15                           */

U8 feat;

void usbd_hid_init (void) {
  /* P2.8..15 (LED) defined as Outputs (Push-pull)                            */
  GPIO2->PC0 |=  LEDMSK;
  GPIO2->PC1 &= ~LEDMSK;
  GPIO2->PC2 |=  LEDMSK;
  GPIO2->PD  &= ~LEDMSK;
}

int usbd_hid_get_report (U8 rtype, U8 rid, U8 *buf, U8 req) {

  switch (rtype) {
    case HID_REPORT_INPUT:
      switch (rid) {
         case 0:
          switch (req) {
            case USBD_HID_REQ_EP_CTRL:
            case USBD_HID_REQ_PERIOD_UPDATE:
              *buf = (((GPIO1->PD ^ S2) >> 13) & 0x01) |
                     (((GPIO0->PD & S3) >> 14) & 0x02) ;
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
      GPIO2->PD  &= ~LEDMSK;
      GPIO2->PD  |=  *buf << 8;
      break;
    case HID_REPORT_FEATURE:
      feat = buf[0];
      break;
  }
}

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
#include <75x_lib.H>

/* Push Button Definitions                                                    */
#define S2              0x8000          /* P1.15 (S2)                         */
#define S3              0x2000          /* P1.13 (S3)                         */

/* LED Definitions                                                            */
#define LEDMSK  0x00FF                  /* P2.00..07                          */

U8 feat;

void usbd_hid_init (void) {
  /* Push Button Setup                                                        */
  GPIO1->PM  &= ~0xA000;                /* enable bit 13, 15                  */
  GPIO1->PC0 |=  0xA000;                /* P1.13,15 input                     */
  GPIO1->PC1 |=  0xA000;
  GPIO1->PC2 &= ~0xA000;

  /* LED Setup                                                                */
  GPIO2->PM  &= ~0x00FF;                /* enable bit 0..7                    */
  GPIO2->PC0 |=  0x00FF;                /* P2.00..07 output push-pull         */
  GPIO2->PC1 &= ~0x00FF;
  GPIO2->PC2 |=  0x00FF;                     
  GPIO2->PD  &= ~0x00FF;                /* clear all LEDs                     */
  GPIO2->PM  |=  0x00FF;                /* mask   bit 0..7                    */
}

int usbd_hid_get_report (U8 rtype, U8 rid, U8 *buf, U8 req) {

  switch (rtype) {
    case HID_REPORT_INPUT:
      switch (rid) {
         case 0:
          switch (req) {
            case USBD_HID_REQ_EP_CTRL:
            case USBD_HID_REQ_PERIOD_UPDATE:
              *buf = (((GPIO1->PD ^ S2) >> 15) & 0x01) |
                     (((GPIO1->PD ^ S3) >> 12) & 0x02) ;
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
      GPIO2->PM  &= ~LEDMSK;
      GPIO2->PD   =  *buf;
      GPIO2->PM  |=  LEDMSK;
      break;
    case HID_REPORT_FEATURE:
      feat = buf[0];
      break;
  }
}

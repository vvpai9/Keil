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
#include <AT91SAM7X256.H>

U8 feat;

void usbd_hid_init (void) {
  /* Enable Clock for PIO                                                     */
  AT91C_BASE_PMC->PMC_PCER  = (1 << AT91C_ID_PIOA);
  AT91C_BASE_PMC->PMC_PCER  = (1 << AT91C_ID_PIOB);
  AT91C_BASE_PIOB->PIO_PER  = 0x0F<<19; /* Enable PIO for LED1..4             */
  AT91C_BASE_PIOB->PIO_OER  = 0x0F<<19; /* LED1..4 are Outputs                */
  AT91C_BASE_PIOB->PIO_SODR = 0x0F<<19; /* Turn off LED's ("1")               */
}

int usbd_hid_get_report (U8 rtype, U8 rid, U8 *buf, U8 req) {

  switch (rtype) {
    case HID_REPORT_INPUT:
      switch (rid) {
         case 0:
          switch (req) {
            case USBD_HID_REQ_EP_CTRL:
            case USBD_HID_REQ_PERIOD_UPDATE:
              *buf = (((AT91C_BASE_PIOA->PIO_PDSR ^ (0x1F << 21)) >> 21) & 0x1F);
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
      AT91C_BASE_PIOB->PIO_CODR =  ( (*buf) & (0x0F)) << 19;
      AT91C_BASE_PIOB->PIO_SODR =  (~(*buf) & (0x0F)) << 19;
      break;
    case HID_REPORT_FEATURE:
      feat = buf[0];
      break;
  }
}

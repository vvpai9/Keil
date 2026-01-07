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
#include <AT91SAM7A3.H>

U8 feat;

void usbd_hid_init (void) {
  /* Enable Clock for PIO                                                     */
  AT91C_BASE_PMC->PMC_PCER  = (1 << AT91C_ID_PIOA) | 
                              (1 << AT91C_ID_PIOB) ;
  AT91C_BASE_PIOA->PIO_PER  = 0x33<<20; /* Enable PIO for LED1..4             */
  AT91C_BASE_PIOA->PIO_OER  = 0x33<<20; /* LED1..4 are Outputs                */
  AT91C_BASE_PIOA->PIO_SODR = 0x33<<20; /* Turn off LED's ("1")               */
}

int usbd_hid_get_report (U8 rtype, U8 rid, U8 *buf, U8 req) {

  switch (rtype) {
    case HID_REPORT_INPUT:
      switch (rid) {
         case 0:
          switch (req) {
            case USBD_HID_REQ_EP_CTRL:
            case USBD_HID_REQ_PERIOD_UPDATE:
              *buf = (((AT91C_BASE_PIOB->PIO_PDSR ^ (1 << 12)) >> 12) & 0x01) |
                     (((AT91C_BASE_PIOB->PIO_PDSR ^ (1 << 13)) >> 12) & 0x02) |
                     (((AT91C_BASE_PIOB->PIO_PDSR ^ (1 <<  8)) >>  6) & 0x04) |
                     (((AT91C_BASE_PIOB->PIO_PDSR ^ (1 <<  9)) >>  6) & 0x08) |
                     (((AT91C_BASE_PIOB->PIO_PDSR ^ (1 << 14)) >> 10) & 0x10) ;
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
      AT91C_BASE_PIOA->PIO_CODR =  ((((*buf) & (0x03)) | ((*buf << 2) & (0x30))) << 20);
      AT91C_BASE_PIOA->PIO_SODR = ~((((*buf) & (0x03)) | ((*buf << 2) & (0x30))) << 20);
      break;
    case HID_REPORT_FEATURE:
      feat = buf[0];
      break;
  }
}

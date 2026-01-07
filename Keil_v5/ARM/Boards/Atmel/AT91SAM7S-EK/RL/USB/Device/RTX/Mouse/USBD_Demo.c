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

#define LED1            (1<<0)          /* PA0                                */
#define LED2            (1<<1)          /* PA1                                */
#define LED3            (1<<2)          /* PA2                                */
#define LED4            (1<<3)          /* PA3                                */
#define LED_MASK        (LED1|LED2|LED3|LED4)
#define SW1             (1<<19)         /* PA19                               */
#define SW2             (1<<20)         /* PA20                               */
#define SW3             (1<<15)         /* PA15                               */
#define SW4             (1<<14)         /* PA14                               */
#define SW_MASK         (SW1|SW2|SW3|SW4)

AT91S_PIO *pPIO = AT91C_BASE_PIOA;      /* Global Pointer to PIO              */ 

/*
 *  Get Mouse Input Report -> MouseInReport
 *    Parameters:      report:
 *                               Byte0.0: 1st Button (Left)
 *                               Byte0.1: 2nd Button (Right)
 *                               Byte0.2: 3rd Button
 *                               Byte1:   Relative X Pos
 *                               Byte2:   Relative Y Pos
 *                               Byte3:   Relative Wheel Pos
 *                     size:     report size
 *    Return Value:    None
 */

void GetMouseInReport (S8 *report, U32 size) {
  U32 key;

  key = pPIO->PIO_PDSR;                 /* Read Pin Data                      */
  if (key & SW1) {                      /* Check if SW1 is not pressed        */
    report[0]  =  !(key&SW4);           /* Left Click (SW4)                   */
    report[1]  =    0;                  /* Default no X Movement              */
    report[1] += (!(key&SW3))*4;        /* Right Movement (SW3)               */
    report[1] -= (!(key&SW2))*4;        /* Left Movement (SW2)                */
    report[2]  =    0;                  /* No Y Movement                      */
  } else {                              /* SW1 is pressed                     */
    report[0]  = (!(key&SW4))*2;        /* Right Click (SW4)                  */
    report[1]  =    0;                  /* No X Movement                      */
    report[2]  =    0;                  /* Default no Y Movement              */
    report[2] += (!(key&SW2))*4;        /* Down Movement (SW2)                */
    report[2] -= (!(key&SW3))*4;        /* Up Movement (SW3)                  */
  }
  report[3]    = 0;                     /* Wheel not used                     */
}


__task void init (void) {
  U32 i, n = 0;
  S8 report[4] = {0, 0, 0, 0};
  
  /* Enable Clock for PIO                                                     */
  AT91C_BASE_PMC->PMC_PCER = (1 << AT91C_ID_PIOA);

  pPIO->PIO_PER  = LED_MASK;            /* Enable PIO for LED1..4             */
  pPIO->PIO_OER  = LED_MASK;            /* LED1..4 are Outputs                */
  pPIO->PIO_SODR = LED_MASK;            /* Turn off LED's ("1")               */

  os_tsk_prio_self(100);
  usbd_init();                          /* USB Device Initialization          */
  usbd_connect(__TRUE);                 /* USB Device Connect                 */
  os_tsk_prio_self(1);

  while (1) {                           /* Loop forever                       */
    GetMouseInReport(report, 4);
    for (i = 0; i < 4; i++) {
      if (report[i]) {
        usbd_hid_get_report_trigger(0, (U8 *)report, 4);
        break;
      }
    } 
  
    if (n == 10000) {
      ((pPIO->PIO_PDSR & SW1) ? (pPIO->PIO_SODR = LED1) : (pPIO->PIO_CODR = LED1));
      n = 0;
    }
    n++;    
  }
}


int main (void) {
  os_sys_init(init);                    /* Init RTX and start 'init'          */
}

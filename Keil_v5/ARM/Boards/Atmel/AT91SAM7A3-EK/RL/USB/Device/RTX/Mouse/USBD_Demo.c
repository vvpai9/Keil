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

#define LED1            (1<<20)         /* PA20                               */
#define LED2            (1<<21)         /* PA21                               */
#define LED3            (1<<24)         /* PA24                               */
#define LED4            (1<<25)         /* PA25                               */
#define LED_MASK        (LED1|LED2|LED3|LED4)
#define JS_UP           (1<< 8)         /* PB8                                */
#define JS_DOWN         (1<< 9)         /* PB9                                */
#define JS_LEFT         (1<<12)         /* PB12                               */
#define JS_RIGHT        (1<<13)         /* PB13                               */
#define JS_PUSH         (1<<14)         /* PB14                               */
#define JS_MASK         (JS_UP|JS_DOWN|JS_LEFT|JS_RIGHT|JS_PUSH)

AT91S_PIO *pPIOA = AT91C_BASE_PIOA;     /* Global Pointer to PIOA             */
AT91S_PIO *pPIOB = AT91C_BASE_PIOB;     /* Global Pointer to PIOB             */

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

  key = pPIOB->PIO_PDSR;                    /* Read Pin Data                  */
  report[0]  =  !(key&JS_PUSH);             /* Left Click                     */
  report[1]  =    0;                        /* Default no X Movement          */
  report[1] += (!(key&JS_RIGHT))*4;         /* Right Movement                 */
  report[1] -= (!(key&JS_LEFT ))*4;         /* Left Movement                  */
  report[2]  =    0;                        /* Default no Y Movement          */
  report[2] += (!(key&JS_DOWN ))*4;         /* Down Movement                  */
  report[2] -= (!(key&JS_UP   ))*4;         /* Up Movement                    */
  report[3]  =    0;                        /* Wheel not used                 */
}


__task void init (void) {
  U32 i, n = 0;
  S8 report[4] = {0, 0, 0, 0};

  /* Enable Clock for PIO                                                     */
  AT91C_BASE_PMC->PMC_PCER = (1 << AT91C_ID_PIOA) |
                             (1 << AT91C_ID_PIOB) ;

  pPIOA->PIO_PER  = LED_MASK;           /* Enable PIO for LED1..4             */
  pPIOA->PIO_OER  = LED_MASK;           /* LED1..4 are Outputs                */
  pPIOA->PIO_SODR = LED_MASK;           /* Turn off LED's ("1")               */

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
      ((pPIOB->PIO_PDSR & JS_PUSH) ? (pPIOA->PIO_SODR = LED1) : (pPIOA->PIO_CODR = LED1));
      n = 0;
    }
    n++;
  }
}


int main (void) {
  os_sys_init(init);                    /* Init RTX and start 'init'          */
}

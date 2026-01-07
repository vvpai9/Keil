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
#include <AT91SAM7X256.H>

#define LED1            (1<<19)         /* PB19                               */
#define LED2            (1<<20)         /* PB20                               */
#define LED3            (1<<21)         /* PB21                               */
#define LED4            (1<<22)         /* PB22                               */
#define LED_MASK        (LED1|LED2|LED3|LED4)
#define SW1             (1<<21)         /* PA21                               */
#define SW2             (1<<22)         /* PA22                               */
#define SW3             (1<<23)         /* PA23                               */
#define SW4             (1<<24)         /* PA24                               */
#define SW5             (1<<25)         /* PA25                               */
#define SW_MASK         (SW1|SW2|SW3|SW4)

AT91S_PIO *pPIO_LED = AT91C_BASE_PIOB;  /* Global Pointer to LED PIO          */
AT91S_PIO *pPIO_SW  = AT91C_BASE_PIOA;  /* Global Pointer to SW PIO           */

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

  key = pPIO_SW->PIO_PDSR;              /* Read Pin Data                      */
  report[0]  =  !(key&SW5);             /* Left Click (SW4)                   */
  report[1]  =    0;                    /* Default no X Movement              */
  report[1] += (!(key&SW4))*4;          /* Right Movement (SW4)               */
  report[1] -= (!(key&SW3))*4;          /* Left Movement (SW3)                */
  report[2]  =    0;                    /* Default no Y Movement              */
  report[2] += (!(key&SW2))*4;          /* Down Movement (SW2)                */
  report[2] -= (!(key&SW1))*4;          /* Up Movement (SW1)                  */
  report[3]    = 0;                     /* Wheel not used                     */
}


__task void init (void) {
  U32 i, n = 0;
  S8 report[4] = {0, 0, 0, 0};

  /* Enable Clock for PIO                                                     */
  AT91C_BASE_PMC->PMC_PCER  = (1 << AT91C_ID_PIOA);
  AT91C_BASE_PMC->PMC_PCER  = (1 << AT91C_ID_PIOB);

  pPIO_LED->PIO_PER  = LED_MASK;        /* Enable PIO for LED1..4             */
  pPIO_LED->PIO_OER  = LED_MASK;        /* LED1..4 are Outputs                */
  pPIO_LED->PIO_SODR = LED_MASK;        /* Turn off LED's ("1")               */

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
      ((pPIO_SW->PIO_PDSR & SW5) ? (pPIO_LED->PIO_SODR = LED1) : (pPIO_LED->PIO_CODR = LED1));
      n = 0;
    }
    n++;    
  }
}


int main (void) {
  os_sys_init(init);                    /* Init RTX and start 'init'          */
}

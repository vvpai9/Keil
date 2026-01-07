/*------------------------------------------------------------------------------
 *      RL-ARM - USB
 *------------------------------------------------------------------------------
 *      Name:    IRQ.c
 *      Purpose: IRQ Handlers
 *------------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <LPC325x.H>

extern void USB_IRQHandler (void);
extern void Timer_Handler  (void);


/* Common interrupt handler, handles all interrupts                           */
__irq void IRQ_Handler (void) {
  
  if (SIC1_SR & (1 << 27)) {            /* If USB_host_int active             */ 
    USB_IRQHandler ();
  }

  if (MIC_SR & (1 << 5)) {              /* If HSTIMER_INT active              */ 
    Timer_Handler ();
  }
}

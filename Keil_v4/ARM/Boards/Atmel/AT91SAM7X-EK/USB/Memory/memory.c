/*----------------------------------------------------------------------------
 *      Name:    MEMORY.C
 *      Purpose: USB Mass Storage Demo
 *      Version: V1.10
 *----------------------------------------------------------------------------
 *      This file is part of the uVision/ARM development tools.
 *      This software may only be used under the terms of a valid, current,
 *      end user licence from KEIL for a compatible version of KEIL software
 *      development tools. Nothing else gives you the right to use it.
 *
 *      Copyright (c) 2005-2007 Keil Software.
 *---------------------------------------------------------------------------*/

#include <AT91SAM7X256.H>                /* AT91SAM7X256 definitions         */

#include "../../AT91SAM7X-EK.h"

#include "type.h"

#include "usb.h"
#include "usbcfg.h"
#include "usbhw.h"
#include "usbcore.h"
#include "mscuser.h"

#include "memory.h"


AT91S_PIO * pPIO_Led = AT91D_BASE_PIO_LED;  /* Global Pointer to PIO */

extern BYTE Memory[MSC_MemorySize];         /* MSC Memory in RAM */


/* Main Program */

int main (void) {
  DWORD n;

  /* Enable Clock for PIO */
  AT91C_BASE_PMC->PMC_PCER = (1 << AT91C_ID_PIOB);         /* LEDs     */

  pPIO_Led->PIO_PER  = AT91B_LED_MASK;      /* Enable PIO for LED1..4  */
  pPIO_Led->PIO_OER  = AT91B_LED_MASK;      /* LED1..4 are Outputs     */
  pPIO_Led->PIO_SODR = AT91B_LED_MASK;      /* Turn off LED's ("1")    */

  for (n = 0; n < MSC_ImageSize; n++) {     /* Copy Initial Disk Image */
    Memory[n] = DiskImage[n];               /*   from Flash to RAM     */
  }

  USB_Init();                               /* USB Initialization */
  USB_Connect(TRUE);                        /* USB Connect */

  while (1);                                /* Loop forever */
}

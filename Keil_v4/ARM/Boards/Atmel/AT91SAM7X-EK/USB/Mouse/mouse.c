/*----------------------------------------------------------------------------
 *      Name:    MOUSE.C
 *      Purpose: USB Mouse Demo
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

#include "mouse.h"


AT91S_PIO * pPIO_Led = AT91D_BASE_PIO_LED;  /* Global Pointer to PIO */
AT91S_PIO * pPIO_Sw  = AT91D_BASE_PIO_SW;   /* Global Pointer to PIO */


BYTE MouseInReport[4];                      /* Mouse Input Report */
                                            /*   Byte0.0: 1st Button (Left)  */
                                            /*   Byte0.1: 2nd Button (Right) */
                                            /*   Byte0.2: 3rd Button         */
                                            /*   Byte1: Relative X Pos       */
                                            /*   Byte2: Relative Y Pos       */
                                            /*   Byte3: Relative Wheel Pos   */

/*
 *  Get Mouse Input Report -> MouseInReport
 *    Parameters:      None
 *    Return Value:    None
 */

void GetMouseInReport (void) {
  DWORD key;

  key = pPIO_Sw->PIO_PDSR;                  /* Read Pin Data */
  if ((key & AT91B_SW5) != 0) {             /* Check if SW5 is not pressed */
    if ((key & AT91B_SW1) == 0) {           /* Check if SW1 (up) is pressed */
      MouseInReport[2] = (BYTE)(-4);        /* -Y: Up Movement */
    }
    else if ((key & AT91B_SW2) == 0) {      /* check is SW2 (down) is pressed */
      MouseInReport[2] = +4;                /* +Y: Down Movement */
    }
    else {
      MouseInReport[2] =  0;                /* No Y Movement */
    }
    if ((key & AT91B_SW3) == 0) {           /* Check if SW3 (left) is pressed */
      MouseInReport[1] = (BYTE)(-4);        /* -X: Left Movement */
    }
    else if ((key & AT91B_SW4) == 0) {      /* check is SW4 (right) is pressed */
      MouseInReport[1] = +4;                /* +X: Right Movement */
    }
    else {
      MouseInReport[1] =  0;                /* No X Movement */
    }
                                    
  } else {                                  /* SW5 is pressed */
    if ((key & AT91B_SW4) == 0) {           /* Check if SW4 is pressed */
      MouseInReport[0] = 0x02;              /* Right Click */
    } else if ((key & AT91B_SW3) == 0) {    /* Check if SW3 is pressed */
      MouseInReport[0] = 0x01;              /* Left Click */
    } else {
      MouseInReport[0] = 0x00;              /* No Click */
    }
  }
  MouseInReport[3] = 0;                     /* Wheel not used */
}

/* Main Program */

int main (void) {
  DWORD n;

  /* Enable Clock for PIO */
  AT91C_BASE_PMC->PMC_PCER = (1 << AT91C_ID_PIOA);         /* Joystick */
  AT91C_BASE_PMC->PMC_PCER = (1 << AT91C_ID_PIOB);         /* LEDs     */

  pPIO_Led->PIO_PER  = AT91B_LED_MASK;      /* Enable PIO for LED1..4  */
  pPIO_Led->PIO_OER  = AT91B_LED_MASK;      /* LED1..4 are Outputs     */
  pPIO_Led->PIO_SODR = AT91B_LED_MASK;      /* Turn off LED's ("1")    */

  USB_Init();                               /* USB Initialization */
  USB_Connect(TRUE);                        /* USB Connect */

  while (1) {                               /* Loop forever */
    n = pPIO_Sw->PIO_PDSR;                  /* Read Pin Data */
    if ((n & AT91B_SW5) == 0) {             /* Check if SW5 is pressed */
      pPIO_Led->PIO_CODR = AT91B_LED1;      /* Turn On LED1 */
    } else {
      pPIO_Led->PIO_SODR = AT91B_LED1;      /* Turn Off LED1 */
    }
    for (n = 0; n < 10000; n++);            /* Delay */
  }
}

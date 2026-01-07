/*-----------------------------------------------------------------------------
 * Name:    JOY.c
 * Purpose: Low level joystick functions
 * Note(s):
 *-----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2004-2011 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <LPC29xx.h>                    /* LPC29xx Definitions                */
#include "JOY.h"


/*-----------------------------------------------------------------------------
 *  JOY_Init:  Initialize joystick
 *----------------------------------------------------------------------------*/
void JOY_Init (void) {

  // Configure P0.26,28..31 as inputs
  SFSP0_26  =  (0x03 << 2);
  SFSP0_28  =  (0x03 << 2);
  SFSP0_29  =  (0x03 << 2);
  SFSP0_30  =  (0x03 << 2);
  SFSP0_31  =  (0x03 << 2);
  GPIO0_DR &= ~((1UL<<26) | (1UL<<28) | (1UL<<29) | (1UL<<30) | (1UL<<31));
}


/*-----------------------------------------------------------------------------
 *  JOY_GetKeys:  Get joystick direction keys state
 *
 * Parameters: (none)
 * Return:     joystick directions bitmask
 *----------------------------------------------------------------------------*/
unsigned int JOY_GetKeys (void) {
  unsigned int p, val = 0;

  p = GPIO0_PINS;
  if ((p & (1UL << 31)) == 0) {
    val |= JOY_LEFT;
  }
  if ((p & (1UL << 29)) == 0) {
    val |= JOY_RIGHT;
  }
  if ((p & (1UL << 28)) == 0) {
    val |= JOY_UP;
  }
  if ((p & (1UL << 30)) == 0) {
    val |= JOY_DOWN;
  }
  if ((p & (1UL << 26)) == 0) {
    val |= JOY_CENTER;
  }
  return (val);
}

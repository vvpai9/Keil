/******************************************************************************/
/* IRQ.H: IRQ Definitions                                                     */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2006 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#define IRQSIZE 64                          /* Max IRQ Sources */

extern void (*IRQ_ISR[IRQSIZE])(void);      /* IRQ Interrupt Service Routines */

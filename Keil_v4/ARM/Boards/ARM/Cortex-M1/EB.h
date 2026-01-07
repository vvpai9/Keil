/******************************************************************************/
/* EB.H: Emulation Baseboard definitions                                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2007 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/


#define HWR(adr) (*((volatile unsigned long *)(adr)))


/*
 * System Control Registers
 */

#define BRD_BASE        0x10000000

#define BRD_ID          0x00
#define BRD_SW          0x04
#define BRD_LED         0x08

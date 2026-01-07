/*----------------------------------------------------------------------------
 * Name:    demo.h
 * Purpose: USB HID Demo Definitions
 * Version: V1.20
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2008 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

/* Push Button Definitions */
#define S2      0x8000    /* P1.15 (S2) */
#define S3      0x2000    /* P1.13 (S3) */

/* LED Definitions */
#define LEDMSK  0x00FF    /* P2.00..07 */

/* HID Demo Variables */
extern U8 InReport;
extern U8 OutReport;

/* HID Demo Functions */
extern void GetInReport  (void);
extern void SetOutReport (void);

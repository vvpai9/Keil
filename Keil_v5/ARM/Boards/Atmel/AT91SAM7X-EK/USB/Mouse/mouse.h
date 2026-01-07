/*----------------------------------------------------------------------------
 * Name:    mouse.h
 * Purpose: USB Mouse Demo Definitions
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


/* LED Definitions */
#define LED_MSK         0x00780000  /* PB.19..22 */
#define LED_1           0x00080000  /* PB.19 */
#define LED_2           0x00100000  /* PB.20 */
#define LED_3           0x00200000  /* PB.21 */
#define LED_4           0x00400000  /* PB.22 */

extern void LED_On  (unsigned int value);
extern void LED_Off (unsigned int value);

/* Mouse Variables */
extern U8 MouseInReport[4];

/* Mouse Functions */
extern void GetMouseInReport (void);

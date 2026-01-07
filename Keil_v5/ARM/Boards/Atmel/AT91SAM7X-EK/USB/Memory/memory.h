/*----------------------------------------------------------------------------
 * Name:    memory.h
 * Purpose: USB Memory Storage Demo Definitions
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2010 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

/* LED Definitions */
#define LED_MSK         0x00780000  /* PB.19..22 */
#define LED_RD          0x00080000  /* PB.19 */
#define LED_WR          0x00100000  /* PB.20 */
#define LED_CFG         0x00200000  /* PB.21 */
#define LED_SUSP        0x00400000  /* PB.22 */

extern void LED_On  (unsigned int value);
extern void LED_Off (unsigned int value);

/* MSC Disk Image Definitions */
#define MSC_ImageSize   0x00001000

extern const unsigned char DiskImage[MSC_ImageSize];   /* Disk Image */

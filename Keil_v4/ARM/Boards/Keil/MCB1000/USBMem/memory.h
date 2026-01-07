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
 * Copyright (c) 2009 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

/* LED Definitions */
/* LED Definitions */
#define LED_NUM     8               /* Number of user LEDs */

#define LED_MASK        0x000000FF  /* P2.0..7 */
#define LED_RD          0x00000001  /* P2.0 */
#define LED_WR          0x00000002  /* P2.1 */
#define LED_CFG         0x00000004  /* P2.2 */
#define LED_SUSP        0x00000008  /* P2.3 */

extern void LED_On  (unsigned int value);
extern void LED_Off (unsigned int value);

/* MSC Disk Image Definitions */
#define MSC_ImageSize   0x00001000

extern const unsigned char DiskImage[MSC_ImageSize];   /* Disk Image */

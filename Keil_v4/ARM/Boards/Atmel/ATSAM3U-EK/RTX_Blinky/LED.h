/*----------------------------------------------------------------------------
 * Name:    LED.h
 * Purpose: AT91SAM3U-EK low level LED definitions
 * Version: V1.00
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2009 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------
 * History:
 *          V1.00 Initial Version
 *----------------------------------------------------------------------------*/

#ifndef __LED_H
#define __LED_H

/* LED Definitions */
#define LED_NUM     2                        /* Number of user LEDs          */

#define LED_MASK        0x00000003           /* PB0..PB1 */
#define LED_0           0x00000001           /* PB0      */
#define LED_1           0x00000002           /* PB1      */

extern void LED_init(void);
extern void LED_on  (unsigned char led);
extern void LED_off (unsigned char led);
extern void LED_out (unsigned char led);


#endif

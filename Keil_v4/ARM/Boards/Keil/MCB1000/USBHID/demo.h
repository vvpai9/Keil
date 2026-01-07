/*----------------------------------------------------------------------------
 * Name:    demo.h
 * Purpose: USB HID Demo Definitions
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

/* Push Button Definitions */
#define KBD_BOOT        0x00000002
#define KBD_MASK        0x00000002  

/* LED Definitions */
#define LED_NUM     8               /* Number of user LEDs */

#define LED_MASK        0x000000FF  /* P2.0..7 */
#define LED_0           0x00000001  /* P2.0 */
#define LED_1           0x00000002  /* P2.1 */
#define LED_2           0x00000004  /* P2.2 */
#define LED_3           0x00000008  /* P2.3 */
#define LED_4           0x00000010  /* P2.4 */
#define LED_5           0x00000020  /* P2.5 */
#define LED_6           0x00000040  /* P2.6 */
#define LED_7           0x00000080  /* P2.7 */

/* HID Demo Variables */
extern U8 InReport;
extern U8 OutReport;

/* HID Demo Functions */
extern void GetInReport  (void);
extern void SetOutReport (void);

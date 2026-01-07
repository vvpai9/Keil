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
#define SW1            0x01                       /* PE0 */
#define SW2            0x02                       /* PE1 */
#define SW3            0x04                       /* PE2 */
#define SW4            0x08                       /* PE3 */
#define SW5            0x10                       /* PE4 */
#define SW6            0x20                       /* PE5 */
#define SW7            0x40                       /* PE6 */
#define SW8            0x80                       /* PE7 */

/* HID Demo Variables */
extern U8 InReport;
extern U8 OutReport;

/* HID Demo Functions */
extern void GetInReport  (void);
extern void SetOutReport (void);

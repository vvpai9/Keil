/*----------------------------------------------------------------------------
 *      RL-ARM - USB
 *----------------------------------------------------------------------------
 *      Name:    Memory.h
 *      Purpose: USB Memory Storage Demo Definitions
 *      Rev.:    V4.70
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

/* LED Definitions */
#define LED_MSK         0x000000FF  /* P2.0..7 */
#define LED_RD          0x00000001  /* P2.0 */
#define LED_WR          0x00000002  /* P2.1 */
#define LED_CFG         0x00000010  /* P2.4 */
#define LED_SUSP        0x00000020  /* P2.5 */

extern void LED_On  (unsigned int value);
extern void LED_Off (unsigned int value);

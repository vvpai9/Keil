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
#define LED_MSK         0x0000000F  /* LED0..3 */
#define LED_RD          0x00000001  /* LED0 */
#define LED_WR          0x00000002  /* LED1 */
#define LED_CFG         0x00000004  /* LED2 */
#define LED_SUSP        0x00000008  /* LED3 */

extern void LED_On  (unsigned int value);
extern void LED_Off (unsigned int value);

extern volatile BOOL WakeUp;

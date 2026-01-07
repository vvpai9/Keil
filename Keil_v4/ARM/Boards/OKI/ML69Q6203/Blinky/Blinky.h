/******************************************************************************/
/* BLINKY.H: Blinky definitions                                               */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2006 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#define REG(x) (*((volatile unsigned int *)(x)))

// 7-segment LED Symbol definitions
#define LED_0   0x3F    /* "0" */
#define LED_1   0x06    /* "1" */
#define LED_2   0x5B    /* "2" */
#define LED_3   0x4F    /* "3" */
#define LED_4   0x66    /* "4" */
#define LED_5   0x6D    /* "5" */
#define LED_6   0x7D    /* "6" */
#define LED_7   0x27    /* "7" */
#define LED_8   0x7F    /* "8" */
#define LED_9   0x6F    /* "9" */
#define LED_A   0x77    /* "A" */
#define LED_b   0x7C    /* "b" */
#define LED_C   0x39    /* "C" */
#define LED_d   0x5E    /* "d" */
#define LED_E   0x79    /* "E" */
#define LED_F   0x71    /* "F" */
#define LED_ON  0xFF    /* All LEDs On */
#define LED_OFF 0x00    /* All LEDs Off */

// 7-segment LED Port definitions
#define LED_EM  0xFF    /* LED Port E Mask */


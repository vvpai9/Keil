/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2008                                  */
/******************************************************************************/
/*                                                                            */
/*  Board.H:  AT91SAM7A3 Evaluation Board Features Definitions                */
/*                                                                            */
/******************************************************************************/

#ifndef __BOARD_H
#define __BOARD_H


/* Clock Definitions */
#define EXT_OSC         18432000        /* External Oscillator MAINCK */
#define MCK             47923200        /* MCK (PLLRC div by 2) */

/* LED's Definitions */
#define LED1            (1<<20)         /* PA20 */
#define LED2            (1<<21)         /* PA21 */
#define LED3            (1<<24)         /* PA24 */
#define LED4            (1<<25)         /* PA25 */

#define LED_CNT         4
#define LED_MASK        (LED1 | LED2 |LED3 | LED4)

/* Joystick Definition */
#define JS_UP           (1<<8)          /* PB8  */
#define JS_DOWN         (1<<9)          /* PB9  */
#define JS_LEFT         (1<<12)         /* PB12 */
#define JS_RIGHT        (1<<13)         /* PB13 */
#define JS_PUSH         (1<<14)         /* PB14 */
#define JS_MASK         (JS_UP | JS_DOWN | JS_LEFT | JS_RIGHT | JS_PUSH)


#endif /* __BOARD_H */

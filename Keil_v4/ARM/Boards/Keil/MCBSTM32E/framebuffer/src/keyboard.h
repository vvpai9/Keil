/******************************************************************************
 * @file:    joystick.h
 * @purpose: Driver for joystick
 * @version: V1.0
 * @date:    14. Aug 2009
 *----------------------------------------------------------------------------
 *
 * Copyright (C) 2009 ARM Limited. All rights reserved.
 *
 * ARM Limited (ARM) is supplying this software for use with Cortex-Mx 
 * processor based microcontrollers.  This file can be freely distributed 
 * within development tools that are supporting such ARM based processors. 
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/


#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

/* Keyboard Hardware Definitions */
#define JOYHW_UP             15                     /* PG15: Joystick up     */
#define JOYHW_LEFT           14                     /* PG14: Joystick left   */
#define JOYHW_RIGHT          13                     /* PG13: Joystick right  */
#define JOYHW_SELECT          7                     /* PG07: Joystick select */
#define JOYHW_DOWN            3                     /* PD03: Joystick down   */

#define BUTHW_USER            8                     /* user Push Button      */


/* Keyboard Software Definitions  */
#define JOY_UP      (1<<0)
#define JOY_DOWN    (1<<1)
#define JOY_LEFT    (1<<2)
#define JOY_RIGHT   (1<<3)
#define JOY_BUT     (1<<4)

#define BUT_USER    (1<<8)

/* prototypes */
int  InitKeyboard(void);
int  getKeyboardVal(void);

#endif



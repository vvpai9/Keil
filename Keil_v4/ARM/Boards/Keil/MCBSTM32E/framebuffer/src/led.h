/******************************************************************************
 * @file:    led.h
 * @purpose: Driver for LEDs
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


#ifndef __led_h__
#define __led_h__


#define LED_PORT			GPIOB->ODR
#define LED_PORT_MASK		0xFFFF00FF
#define LED_PORT_SHIFT		8
#define LED_PORT_SHIFT_MAX	15




int led_init(void);
void led_out(char out);
void running_light(void);




#endif


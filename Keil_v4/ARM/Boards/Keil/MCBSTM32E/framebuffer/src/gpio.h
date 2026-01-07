/******************************************************************************
 * @file:    gpio.h
 * @purpose: Driver for GPIO config
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



#ifndef __GPIO_H__
#define __GPIO_H__


// AF enable
#define AFIO_EN		0	// Alternate Function Enable

// GPIO enable
#define IOPA_EN		2	// GPIO A enable
#define IOPB_EN		3	// GPIO B enable
#define IOPC_EN		4	// GPIO C enable
#define IOPD_EN		5	// GPIO D enable
#define IOPE_EN		6	// GPIO E enable
#define IOPF_EN		7	// GPIO F enable
#define IOPG_EN		8	// GPIO G enable





#define GPIO_CONF_BIT(BIT)	((BIT>7? BIT-8 : BIT) << 2)		// 4Bits per port pin

// Mode and Conf Bits
#define MODE0					(unsigned int)0
#define MODE1					(unsigned int)1
#define CONF0					(unsigned int)2
#define CONF1					(unsigned int)3


// Port Mode
#define GPIO_MODE_INPUT		    (((unsigned int)0<<MODE0) | ((unsigned int)0<<MODE1))		// GPIO is input
#define GPIO_SPEED_2MHZ		    (((unsigned int)0<<MODE0) | ((unsigned int)1<<MODE1))		// Max output Speed  2MHz
#define GPIO_SPEED_10MHZ		  (((unsigned int)1<<MODE0) | ((unsigned int)0<<MODE1))		// Max output Speed 10MHz
#define GPIO_SPEED_50MHZ		  (((unsigned int)1<<MODE0) | ((unsigned int)1<<MODE1))		// Max output Speed 50MHz

// Port Conf
#define GPIO_OUT_PUSH_PULL		(((unsigned int)0<<CONF0) | ((unsigned int)0<<CONF1))		// general purpose output push-pull

#define GPIO_AF_PUSHPULL      (((unsigned int)0<<CONF0) | ((unsigned int)1<<CONF1))   // alternate function push-pull

#define GPIO_IN_FLOATING      (((unsigned int)1<<CONF0) | ((unsigned int)0<<CONF1))   // input floating
#define GPIO_IN_PULL_DOWN     (((unsigned int)0<<CONF0) | ((unsigned int)1<<CONF1))   // alternate function push-pull
#define GPIO_IN_PULL_UP       (((unsigned int)0<<CONF0) | ((unsigned int)1<<CONF1))   // alternate function push-pull


#endif


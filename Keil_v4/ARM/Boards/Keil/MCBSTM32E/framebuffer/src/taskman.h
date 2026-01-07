/******************************************************************************
 * @file:    taskman.h
 * @purpose: RTOS config and start
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

#ifndef __TASKMAN_H__
#define __TASKMAN_H__


// IDs for Tasks
extern OS_TID idTaskman;			// id from Taskman
extern OS_TID idFrameBuf_WriteDisp;
extern OS_TID idMoveBackImage;   // Moves Backg Image




// prototypes
void taskman(void);
OS_TID insertNewTask(void (*task)(void), U8 priority, char* taskName);
void BootSystem(void);
void PrintMessage(void);

#endif

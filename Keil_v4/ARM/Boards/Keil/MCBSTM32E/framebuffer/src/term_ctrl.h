/******************************************************************************
 * @file:    term_ctrl.h
 * @purpose: Driver for terminal control sequences
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
 

#ifndef __TERM_CTRL_H__
#define __TERM_CTRL_H__


#define TERM_STATE_ZERO               (   0)
#define TERM_STATE_ESC                (1<<0)
#define TERM_STATE_OPENBOXBRACKET     (1<<1)
#define TERM_STATE_WAIT_FOR_END       (1<<2)
#define TERM_STATE_HOME               (1<<3)
#define TERM_STATE_END                (1<<4)



// key translation codes
#define CODE_ZERO                     ( 0)
#define CODE_WAITING                  ( 1)

#define CODE_CTRL_C                   (10)
#define CODE_CTRL_D                   (11)
#define CODE_DOUBLE_ESC               (12)

#define CODE_CURSOR_UP                (21)
#define CODE_CURSOR_DOWN              (22)
#define CODE_CURSOR_LEFT              (23)
#define CODE_CURSOR_RIGHT             (24)

#define CODE_ENTER                    (31)
#define CODE_REPEAT                   (32)

#define CODE_DEL                      (41)
#define CODE_BACKSPACE                (42)
#define CODE_HOME                     (43)
#define CODE_END                      (44)


/**
 * Attribute codes:
 * 00=none 01=bold 04=underscore 05=blink 07=reverse 08=concealed
 * Text color codes:
 * 30=black 31=red 32=green 33=yellow 34=blue 35=magenta 36=cyan 37=white
 * Background color codes:
 * 40=black 41=red 42=green 43=yellow 44=blue 45=magenta 46=cyan 47=white
 */
#define NONE                      0
#define BOLD                      1
#define UNDERSCORE                4
#define BLINK                     5
#define REVERSE                   7
#define CONCEALED                 8

#define TEXT                     30
#define BACK                     40

#define BLACK                     0
#define RED                       1
#define GREEN                     2
#define YELLOW                    3
#define BLUE                      4
#define MAGENTA                   5
#define CYAN                      6
#define WHITE                     7

#define TEXTCOLOR               (TEXT + WHITE)


typedef struct position
{
  int x;
  int y;
}pos;


// prototypes
void ClearScreen(void);
void gotoxy(int x, int y);



#endif



/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2013  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.22 - Graphical user interface for embedded applications **
All  Intellectual Property rights  in the Software belongs to  SEGGER.
emWin is protected by  international copyright laws.  Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with the following terms:

The software has been licensed to  ARM LIMITED whose registered office
is situated at  110 Fulbourn Road,  Cambridge CB1 9NJ,  England solely
for  the  purposes  of  creating  libraries  for  ARM7, ARM9, Cortex-M
series,  and   Cortex-R4   processor-based  devices,  sublicensed  and
distributed as part of the  MDK-ARM  Professional  under the terms and
conditions  of  the   End  User  License  supplied  with  the  MDK-ARM
Professional. 
Full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : GUI_X_Joystick.c
Purpose     : Config / System dependent externals for GUI
---------------------------END-OF-HEADER------------------------------
*/

#include "GUI.h"
#include "Joystick.h"

/*********************************************************************
*
*       Joystick support
*
*/

#ifdef  JOYSTICK_ROTATE
#define JOYSTICK_LEFT   JOY_DOWN
#define JOYSTICK_RIGHT  JOY_UP
#define JOYSTICK_UP     JOY_LEFT
#define JOYSTICK_DOWN   JOY_RIGHT
#define JOYSTICK_CENTER JOY_CENTER
#else
#define JOYSTICK_LEFT   JOY_LEFT
#define JOYSTICK_RIGHT  JOY_RIGHT
#define JOYSTICK_UP     JOY_UP
#define JOYSTICK_DOWN   JOY_DOWN
#define JOYSTICK_CENTER JOY_CENTER
#endif

void GUI_JOYSTICK_Initialize (void) {
  Joystick_Initialize();
}

void GUI_JOYSTICK_Exec (void) {
  GUI_PID_STATE state;
  static  U8    hold = 0;
  static  U8    prevkeys = 0;
          U32   keys;
          I32   diff, max;

  // Read Joystick keys
  keys = Joystick_GetButtons();

  // Dynamic pointer acceleration
  if (keys == prevkeys) {
    if (hold < (40+3)) hold++;
    diff = (hold > 3) ? hold - 3 : 0; 
  } else {
    hold = 0;
    diff = 1;
  }

  // Change State if keys are pressed or have changed
  if (keys || (keys != prevkeys)) {
    GUI_PID_GetState(&state);
    if (keys & JOYSTICK_LEFT) {
      state.x -= diff;
      if (state.x < 0) state.x = 0;
    }
    if (keys & JOYSTICK_RIGHT) {
      state.x += diff;
      max = LCD_GetXSize() - 1;
      if (state.x > max) state.x = max; 
    }
    if (keys & JOYSTICK_UP) {
      state.y -= diff;
      if (state.y < 0) state.y = 0;
    }
    if (keys & JOYSTICK_DOWN) {
      state.y += diff;
      max = LCD_GetYSize() - 1;
      if (state.y > max) state.y = max; 
    } 
    state.Pressed = (keys & JOYSTICK_CENTER) ? 1 : 0;
    GUI_PID_StoreState(&state);
    prevkeys = keys;
  }
}

/*************************** End of file ****************************/

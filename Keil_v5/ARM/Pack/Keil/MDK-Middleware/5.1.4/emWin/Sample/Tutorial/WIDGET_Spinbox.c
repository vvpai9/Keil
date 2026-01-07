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
File        : WIDGET_Spinbox.c
Purpose     : Shows how to use the SPINBOX widget.
---------------------------END-OF-HEADER------------------------------
*/
#include "GUI.h"
#include "FRAMEWIN.h"
#include "SPINBOX.h"

#define ID_FRAMEWIN_0 (GUI_ID_USER + 0)

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/*********************************************************************
*
*       _cbBk
*/
static void _cbBk(WM_MESSAGE * pMsg) {
  int xSize, ySize;

  switch (pMsg->MsgId) {
  case WM_PAINT:
    xSize = LCD_GetXSize();
    ySize = LCD_GetYSize();
    GUI_DrawGradientV(0, 0, xSize, ySize, GUI_BLUE, GUI_BLACK);
    GUI_SetColor(GUI_WHITE);
    GUI_SetFont(&GUI_Font24_ASCII);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringHCenterAt("WIDGET_Spinbox - Sample", 160, 5);
    break;
  default:
    WM_DefaultProc(pMsg);
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       MainTask
*/
void MainTask(void);
void MainTask(void) {
  SPINBOX_Handle  hSpin;
  FRAMEWIN_Handle hFrame;
  WM_HWIN hClient;

  GUI_Init();
  WM_SetCallback(WM_HBKWIN, _cbBk);
  hFrame = FRAMEWIN_CreateEx(110, 60, 100, 80, WM_HBKWIN, WM_CF_SHOW, 0, ID_FRAMEWIN_0, "Spinbox", 0);
  hClient = WM_GetClientWindow(hFrame);
  FRAMEWIN_SetSkin(hFrame, FRAMEWIN_SKIN_FLEX);
  FRAMEWIN_SetFont(hFrame, GUI_FONT_16B_ASCII);
  hSpin  = SPINBOX_CreateEx(10, 10, 60, 20, hClient, WM_CF_SHOW, GUI_ID_SPINBOX0, 5, 2222);
  SPINBOX_SetSkin(hSpin, SPINBOX_SKIN_FLEX);
  while (1) {
    GUI_Delay(100);
  }
}

/*************************** End of file ****************************/

/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2017  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.46 - Graphical user interface for embedded applications **
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
Licensing information
Licensor:                 SEGGER Software GmbH
Licensed to:              ARM Ltd, 110 Fulbourn Road, CB1 9NJ Cambridge, UK
Licensed SEGGER software: emWin
License number:           GUI-00181
License model:            LES-SLA-20007, Agreement, effective since October 1st 2011 
Licensed product:         MDK-ARM Professional
Licensed platform:        ARM7/9, Cortex-M/R4
Licensed number of seats: -
----------------------------------------------------------------------
File        : JPEGConf.h
Purpose     : Configuration header file to draw JPEG with hardware
----------------------------------------------------------------------
*/

#ifndef JPEGCONF_H
#define JPEGCONF_H

#define JPEG_ARGB8888 0
#define JPEG_RGB565   1

typedef struct {
  U32                 WorkBufferSize;
  void              * (* pfMalloc)(size_t size);
  void                (* pfFree)  (void * ptr);
  int                 ColorFormat;
  U8                * pWorkBuffer;
  GUI_HMEM            hWorkBuffer;
  U8                * pOutBuffer;
  GUI_HMEM            hOutBuffer;
  U32                 OutBufferSize;
  U8                * pInBuffer;
  U32                 NumBytesInBuffer;
  int                 BitsPerPixel;
  int                 BytesPerLine;
  GUI_GET_DATA_FUNC * pfGetData;
  void              * pVoid;
  U32                 Off;
  U32                 xPos;
  U32                 yPos;
  U32                 xSize;
  U32                 ySize;
  U32                 BlockSize;
  U32                 TotalMCUs;
  U32                 IndexMCU;
  U32                 (* pfConvert)(U32 BlockIndex);
  //U8                  HFactor;
  U8                  VFactor;
  U32                 xSizeExtended;
  U8                  Error;
  U8                  IRQFlag;
#if GUI_SUPPORT_MEMDEV
  GUI_MEMDEV_Handle   hMem;
#endif
} JPEG_X_CONTEXT;

int  JPEG_X_Draw        (GUI_GET_DATA_FUNC * pfGetData, void * p, int x0, int y0);
void JPEG_X_DeInit      (void);
void JPEG_X_Init(JPEG_X_CONTEXT * pContext);
void JPEG_X_SetStayAlive(int OnOff);
void JPEG_X_IncStayAlive(void);
void JPEG_X_DecStayAlive(void);

void MOVIE_X_cbNotify    (GUI_MOVIE_HANDLE hMovie, int Notification, U32 CurrentFrame);

#endif /* LCDCONF_H */

/*************************** End of file ****************************/

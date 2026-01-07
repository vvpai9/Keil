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
* Height:      16                                                    *
*                                                                    *
**********************************************************************
*                                                                    *
* Initial font height: 16                                            *
* Range disabled: 0000 - FFFF                                        *
* Character enabled:   0x41 (65)                                     *
* Character enabled:   0x42 (66)                                     *
* Character enabled:   0x43 (67)                                     *
*                                                                    *
**********************************************************************
*/

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

/* The following line needs to be included in any file selecting the
   font. A good place would be GUIConf.H
*/
extern GUI_CONST_STORAGE GUI_FONT GUI_Font16;

/* Start of unicode area <Basic Latin> */
GUI_CONST_STORAGE unsigned char acGUI_Font16_0041[ 20] = { /* code 0041, LATIN CAPITAL LETTER A */
  ____X___,________,
  ___X_X__,________,
  ___X_X__,________,
  ___X_X__,________,
  __X___X_,________,
  __X___X_,________,
  _XXXXXXX,________,
  _X_____X,________,
  X_______,X_______,
  X_______,X_______};

GUI_CONST_STORAGE unsigned char acGUI_Font16_0042[ 10] = { /* code 0042, LATIN CAPITAL LETTER B */
  XXXXXX__,
  X_____X_,
  X_____X_,
  X_____X_,
  XXXXXX__,
  X_____X_,
  X_____X_,
  X_____X_,
  X_____X_,
  XXXXXX__};

GUI_CONST_STORAGE unsigned char acGUI_Font16_0043[ 10] = { /* code 0043, LATIN CAPITAL LETTER C */
  __XXX___,
  _X___X__,
  X_____X_,
  X_______,
  X_______,
  X_______,
  X_______,
  X_____X_,
  _X___X__,
  __XXX___};

GUI_CONST_STORAGE GUI_CHARINFO_EXT GUI_Font16_CharInfo[3] = {
   {   9,  10,   0,   3,   9, acGUI_Font16_0041 } /* code 0041, LATIN CAPITAL LETTER A */
  ,{   7,  10,   1,   3,   9, acGUI_Font16_0042 } /* code 0042, LATIN CAPITAL LETTER B */
  ,{   7,  10,   1,   3,   9, acGUI_Font16_0043 } /* code 0043, LATIN CAPITAL LETTER C */
};

GUI_CONST_STORAGE GUI_FONT_PROP_EXT GUI_Font16_Prop1 = {
   0x0041 /* first character */
  ,0x0043 /* last character  */
  ,&GUI_Font16_CharInfo[  0] /* address of first character */
  ,(GUI_CONST_STORAGE GUI_FONT_PROP_EXT *)0 /* pointer to next GUI_FONT_PROP_EXT */
};

GUI_CONST_STORAGE GUI_FONT GUI_Font16 = {
   GUI_FONTTYPE_PROP_EXT /* type of font    */
  ,16 /* height of font  */
  ,16 /* space of font y */
  ,1 /* magnification x */
  ,1 /* magnification y */
  ,{&GUI_Font16_Prop1}
  ,13 /* Baseline */
  ,7 /* Height of lowercase characters */
  ,10 /* Height of capital characters */
};


/******************************************************************************/
/* GLCD.h Graphic LCD function prototypes                                     */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2006 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/


extern void glcd_write_cmd (unsigned char c, char enable);
extern void glcd_write_data (unsigned char c, char enable);
extern void glcd_init (void);
extern void glcd_clear (void);
extern void glcd_bitmap (int x, int y, int w, int h, const unsigned char *bitmap);
extern void glcd_print (int pos_x, int  pos_y, int font, const unsigned char *string);

/******************************************************************************/


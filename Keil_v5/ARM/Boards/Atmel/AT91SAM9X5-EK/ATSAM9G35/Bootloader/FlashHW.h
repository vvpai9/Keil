/******************************************************************************/
/*  FlashHW.H:   Include file for Hardware Layer Flash Programming functions  */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2010 Keil Software. All rights reserved.                     */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

/* Functions defined in module DFlashHW.c                                     */
int InitFlashController_HW (unsigned char bus_width, unsigned char adr_cycles, unsigned char page_type, unsigned long clk);
int UnInit_HW              (void);
int GetPageSize_HW         (void);
int ErasePage_HW           (unsigned long adr);
int EraseBlock_HW          (unsigned long adr);
int EraseChip_HW           (void);
int CheckBlock_HW          (unsigned long adr);
int MarkBlockBad_HW        (unsigned long adr);
int ReadPage_HW            (unsigned long adr, unsigned long sz, unsigned char *buf);
int ProgramPage_HW         (unsigned long adr, unsigned long sz, unsigned char *buf);
int WaitOperation_HW       (void);


/******************************************************************************/

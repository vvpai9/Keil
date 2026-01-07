/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  SRAM.H:  Header file for Internal SRAM                                    */
/*           Sharp LH754xx                                                    */
/*                                                                            */
/******************************************************************************/

#ifndef __SRAM_H
#define __SRAM_H


/* Internal SRAM Memory (for Processor, DMA, LCD) */
#define ISRAM_BASE  0x60000000  /* Internal SRAM (can also be mapped to 0) */
#define ISRAM_SIZE  (16*1024)   /* 16kB Internal SRAM */

/* Local SRAM Memory (for Processor Only) */
#define LSRAM_BASE  0x80000000  /* Local SRAM (can also be mapped to 0) */
#define LSRAM_SIZE  (16*1024)   /* 16kB Local SRAM */


#endif /* __SRAM_H */

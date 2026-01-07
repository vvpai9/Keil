/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  DMA.H:  Header file for DMA Controllers                                   */
/*          Samsung S3C44B0X                                                  */
/*                                                                            */
/******************************************************************************/

#ifndef __DMA_H
#define __DMA_H


#define ZDMA_BASE   0x01E80000  // ZDMA Controller Base Address
#define BDMA_BASE   0x01F80000  // BDMA Controller Base Address


// ZDMA & BDMA Controller Registers
typedef struct {
  reg32 DCON0;      // DMA 0 Control
  reg32 DISRC0;     // DMA 0 Initial Source Address
  reg32 DIDES0;     // DMA 0 Initial Destination Address
  reg32 DICNT0;     // DMA 0 Initial Transfer Count
  reg32 DCSRC0;     // DMA 0 Current Source Address
  reg32 DCDES0;     // DMA 0 Current Destination Address
  reg32 DCCNT0;     // DMA 0 Current Transfer Count
  reg32 Rsrvd0;
  reg32 DCON1;      // DMA 1 Control
  reg32 DISRC1;     // DMA 1 Initial Source Address
  reg32 DIDES1;     // DMA 1 Initial Destination Address
  reg32 DICNT1;     // DMA 1 Initial Transfer Count
  reg32 DCSRC1;     // DMA 1 Current Source Address
  reg32 DCDES1;     // DMA 1 Current Destination Address
  reg32 DCCNT1;     // DMA 1 Current Transfer Count
  reg32 Rsrvd1;
} regDMA;

#define pZDMA ((regDMA *)ZDMA_BASE)
#define pBDMA ((regDMA *)BDMA_BASE)


#endif /* __DMA_H */

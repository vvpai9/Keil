/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  DMA.H:  Header file for Direct Memory Access Controller (DMA)             */
/*          Sharp LH754xx                                                     */
/*                                                                            */
/******************************************************************************/

#ifndef __DMA_H
#define __DMA_H


#define DMA_BASE    0xFFFE1000  /* DMA Base Address */

#define DMA_STREAM0 0x00        /* DMA Stream 0 Offset */
#define DMA_STREAM1 0x40        /* DMA Stream 1 Offset */
#define DMA_STREAM2 0x80        /* DMA Stream 2 Offset */
#define DMA_STREAM3 0xC0        /* DMA Stream 3 Offset */

/* DMA Register Offsets */
#define DMASourceLo 0x00        /* DMA Source Base Address, lower 16 bits */
#define DMASourceHi 0x04        /* DMA Source Base Address, higher 16 bits */
#define DMADestLo   0x08        /* DMA Dest. Base Address, lower 16 bits */
#define DMADestHi   0x0C        /* DMA Dest. Base Address, higher 16 bits */
#define DMAMax      0x10        /* DMA Maximum Count Register */
#define DMACtrl     0x14        /* DMA Control Register */
#define DMASoCurrHi 0x18        /* DMA Current Source Address, higher 16 bits */
#define DMASoCurrLo 0x1C        /* DMA Current Source Address, lower 16 bits */
#define DMADeCurrHi 0x20        /* DMA Current Dest. Address, higher 16 bits */
#define DMADeCurrLo 0x24        /* DMA Current Dest. Address, lower 16 bits */
#define DMATCnt     0x28        /* DMA Terminal Counter */

#define DMAMask     REG16(DMA_BASE + 0xF0)  /* DMA Interrupt Mask */
#define DMAClr      REG16(DMA_BASE + 0xF4)  /* DMA Interrupt Clear */
#define DMAStatus   REG16(DMA_BASE + 0xF8)  /* DMA Status */

typedef struct {
  reg16 SourceLo;   /* Source Base Address, lower 16 bits */
  reg16 pad0;
  reg16 SourceHi;   /* Source Base Address, higher 16 bits */
  reg16 pad1;
  reg16 DestLo;     /* Destination Base Address, lower 16 bits */
  reg16 pad2;
  reg16 DestHi;     /* Destination Base Address, higher 16 bits */
  reg16 pad3;
  reg16 Max;        /* Maximum Count Register */
  reg16 pad4;
  reg16 Ctrl;       /* Control Register */
  reg16 pad5;
  reg16 SoCurrHi;   /* Current Source Address, higher 16 bits */
  reg16 pad6;
  reg16 SoCurrLo;   /* Current Source Address, lower 16 bits */
  reg16 pad7;
  reg16 DeCurrHi;   /* Current Destination Address, higher 16 bits */
  reg16 pad8;
  reg16 DeCurrLo;   /* Current Destination Address, lower 16 bits */
  reg16 pad9;
  reg16 TCnt;       /* Terminal Counter */
  reg16 padA;
} DMAStream;

#define DMAStream0 ((DMAStream *)(DMA_BASE + DMA_STREAM0))
#define DMAStream1 ((DMAStream *)(DMA_BASE + DMA_STREAM1))
#define DMAStream2 ((DMAStream *)(DMA_BASE + DMA_STREAM2))
#define DMAStream3 ((DMAStream *)(DMA_BASE + DMA_STREAM3))


#endif /* __DMA_H */

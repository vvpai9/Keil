/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  UART01.H:  Header file for UART0 and UART1                                */
/*             Sharp LH754xx                                                  */
/*                                                                            */
/******************************************************************************/

#ifndef __UART01_H
#define __UART01_H


#define UART0_BASE  0xFFFC0000  /* UART0 Base Address */
#define UART1_BASE  0xFFFC1000  /* UART1 Base Address */

/* UART Register Offsets */
#define UARTDR      0x00        /* UART Data Register */
#define UARTRSR     0x04        /* UART Receive Status Register */
#define UARTECR     0x04        /* UART Error Clear Register */
#define UARTFR      0x18        /* UART Flag Register */
#define UARTIBRD    0x24        /* UART Integer Baud Rate Divisor Register */
#define UARTFBRD    0x28        /* UART Fractional Baud Rate Divisor Register */
#define UARTLCR_H   0x2C        /* UART Line Control Register, High Byte */
#define UARTCR      0x30        /* UART Control Register */
#define UARTIFLS    0x34        /* UART Interrupt FIFO Level Select */
#define UARTIMSC    0x38        /* UART Interrupt Mask Set/Clear */
#define UARTRIS     0x3C        /* UART Raw Interrupt Status */
#define UARTMIS     0x40        /* UART Masked Interrupt Status */
#define UARTICR     0x44        /* UART Interrupt Clear Register */
#define UARTDMACR   0x48        /* UART DMA Control Register */

typedef struct {
  reg16 dr;         /* Data Register */
  reg16 pad0;
  reg8  rsr_ecr;    /* Receive Status Reg. (Read) / Error Clear Reg. (Write) */
  reg8  pad1[3];
  reg32 rsrvd1[4];
  reg16 fr;         /* Flag Register */
  reg16 pad2;
  reg32 rsrvd2[2];
  reg16 ibrd;       /* Integer Baud Rate Divisor Register */
  reg16 pad3;
  reg16 fbrd;       /* Fractional Baud Rate Divisor Register */
  reg16 pad4;
  reg16 lcr_h;      /* Line Control Register, High Byte */
  reg16 pad5;
  reg16 cr;         /* Control Register */
  reg16 pad6;
  reg16 ifls;       /* Interrupt FIFO Level Select */
  reg16 pad7;
  reg16 imsc;       /* Interrupt Mask Set/Clear */
  reg16 pad8;
  reg16 ris;        /* Raw Interrupt Status */
  reg16 pad9;
  reg16 mis;        /* Masked Interrupt Status */
  reg16 padA;
  reg16 icr;        /* Interrupt Clear Register */
  reg16 padB;
  reg16 dmacr;      /* DMA Control Register */
  reg16 padC;
} UART;

#define UART0 ((UART *)(UART0_BASE))
#define UART1 ((UART *)(UART1_BASE))


#endif /* __UART01_H */

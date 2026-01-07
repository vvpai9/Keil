/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  IOCON.H:  Header file for I/O Configuration                               */
/*            Sharp LH754xx                                                   */
/*                                                                            */
/******************************************************************************/

#ifndef __IOCON_H
#define __IOCON_H


#define IOCON_BASE  0xFFFE5000                  /* IOCON Base Address */

#define EBI_MUX     REG32(IOCON_BASE + 0x00)    /* EBI Interface Mux */
#define PD_MUX      REG32(IOCON_BASE + 0x04)    /* Pins PDx Mux */
#define PE_MUX      REG32(IOCON_BASE + 0x08)    /* Pins PEx Mux */
#define TIMER_MUX   REG32(IOCON_BASE + 0x0C)    /* Timer Mux */
#define LCD_MUX     REG32(IOCON_BASE + 0x10)    /* LCD Mode Mux */
#define PA_RES_MUX  REG32(IOCON_BASE + 0x14)    /* Pins PAx Resisor Mux */
#define PB_RES_MUX  REG32(IOCON_BASE + 0x18)    /* Pins PBx Resisor Mux */
#define PC_RES_MUX  REG32(IOCON_BASE + 0x1C)    /* Pins PCx Resisor Mux */
#define PD_RES_MUX  REG32(IOCON_BASE + 0x20)    /* Pins PDx Resisor Mux */
#define PE_RES_MUX  REG32(IOCON_BASE + 0x24)    /* Pins PEx Resisor Mux */
#define ADC_MUX     REG32(IOCON_BASE + 0x28)    /* Pins ANx/PJx Mux */


#endif /* __IOCON_H */

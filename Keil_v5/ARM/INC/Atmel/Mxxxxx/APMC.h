/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  APMC.H:  Header file for Advanced Power Management Controller      */
/*                                                                     */
/***********************************************************************/

#ifndef __APMC_H
#define __APMC_H


/*----------------*/
/* APMC Registers */
/*----------------*/
#define APMC_SCER  REG(APMC_BASE + 0x00)   /* System Clock Enable  Register */
#define APMC_SCDR  REG(APMC_BASE + 0x04)   /* System Clock Disable Register */
#define APMC_SCSR  REG(APMC_BASE + 0x08)   /* System Clock Status  Register */
#define APMC_PCER  REG(APMC_BASE + 0x10)   /* Peripheral Clock Enable  Register */
#define APMC_PCDR  REG(APMC_BASE + 0x14)   /* Peripheral Clock Disable Register */
#define APMC_PCSR  REG(APMC_BASE + 0x18)   /* Peripheral Clock Status  Register */
#define APMC_CGMR  REG(APMC_BASE + 0x20)   /* Clock Generator Mode Register */
#define APMC_PCR   REG(APMC_BASE + 0x28)   /* Power Control Register */
#define APMC_PMR   REG(APMC_BASE + 0x2C)   /* Power Mode Register */
#define APMC_SR    REG(APMC_BASE + 0x30)   /* Status Register */
#define APMC_IER   REG(APMC_BASE + 0x34)   /* Interrupt Enable Register */
#define APMC_IDR   REG(APMC_BASE + 0x38)   /* Interrupt Disable Register */
#define APMC_IMR   REG(APMC_BASE + 0x3C)   /* Interrupt Mask Register */


/*------------------------------------------*/
/* APMC_SCER: System Clock Enable  Register */
/* APMC_SCDR: System Clock Disable Register */
/* APMC_SCSR: System Clock Status  Register */
/*------------------------------------------*/
#define APMC_CPU           (1<<0)

/*------------------------------------------*/
/* APMC_CGMR: Clock Generator Mode Register */
/*------------------------------------------*/

#define APMC_MOSC_BYP      (1<<0)      /* Main Oscillator Bypass */
#define APMC_MOSC_EN       (1<<1)      /* Main Oscillator Enable */
#define APMC_MCKO_DIS      (1<<2)      /* Disable Master clock output */

#define APMC_PRES          (7<<4)      /* Prescaler Selection */
#define APMC_PRES_NONE     (0<<4)      /* No prescaler */
#define APMC_PRES_DIV2     (1<<4)      /* Selected Clock Divided by 2 */
#define APMC_PRES_DIV4     (2<<4)      /* Selected Clock Divided by 4 */
#define APMC_PRES_DIV8     (3<<4)      /* Selected Clock Divided by 8 */
#define APMC_PRES_DIV16    (4<<4)      /* Selected Clock Divided by 16 */
#define APMC_PRES_DIV32    (5<<4)      /* Selected Clock Divided by 32 */
#define APMC_PRES_DIV64    (6<<4)      /* Selected Clock Divided by 64 */

#define APMC_CSS           (3<<14)     /* Clock Source Selection */
#define APMC_CSS_LF        (0<<14)     /* Low-Frequency Clock */
#define APMC_CSS_MOSC      (1<<14)     /* Main Oscillator or External Clock */
#define APMC_CSS_PLL       (2<<14)     /* Phase Lock Loop Output */

#define APMC_MUL           (0x3F<<8)
#define APMC_B_MUL         8

#define APMC_OSCOUNT       (0xFF<<16)
#define APMC_B_OSCOUNT     16

#define APMC_PLLCOUNT      (0x3F<<24)
#define APMC_B_PLLCOUNT    24

/*----------------------------------*/
/* APMC_PCR: Power Control Register */
/*----------------------------------*/
#define APMC_SHDALC        (1<<0)      /* Shut-down or Alarm Command */
#define APMC_WKACKC        (1<<1)      /* Wake-up or Alarm Ack Command */

/*-------------------------------*/
/* APMC_PMR: Power Mode Register */
/*-------------------------------*/

#define APMC_SHDALS_OUT          (3<<0)    /* Shut-down or Alarm Output */
#define APMC_SHDALS_OUT_TRIS     (0<<0)    /* SHDALS Pin is Tri-Stated */
#define APMC_SHDALS_OUT_LEVEL_0  (1<<0)    /* SHDALS Pin is Level 0 */
#define APMC_SHDALS_OUT_LEVEL_1  (2<<0)    /* SHDALS Pin is Level 1 */

#define APMC_WKACKS_OUT          (3<<2)    /* Wake-up or Alarm Ack Output */
#define APMC_WKACKS_OUT_TRIS     (0<<2)    /* WKACKS Pin is Tri-Stated */
#define APMC_WKACKS_OUT_LEVEL_0  (1<<2)    /* WKACKS Pin is Level 0 */
#define APMC_WKACKS_OUT_LEVEL_1  (2<<2)    /* WKACKS Pin is Level 1 */

#define APMC_WKEN                (1<<4)    /* Alarm Wake-up Enable */
#define APMC_ALSHEN              (1<<5)    /* Alarm Shut-Down Enable */

#define APMC_WKEDG               (3<<6)    /* Wake-up Input Edge */
#define APMC_WKEDG_NONE          (0<<6)    /* None */
#define APMC_WKEDG_POS_EDG       (1<<6)    /* Positive Edge */
#define APMC_WKEDG_NEG_EDG       (2<<6)    /* Negative Edge */
#define APMC_WKEDG_BOTH_EDG      (3<<6)    /* Both Edges */

/*--------------------------------------*/
/* APMC_SR:  Status Register            */
/* APMC_IER: Interrupt Enable  Register */
/* APMC_IDR: Interrupt Disable Register */
/* APMC_IMR: Interrupt Mask    Register */
/*--------------------------------------*/
#define APMC_MOSCS         (1<<0)      /* Main Osillator Status */
#define APMC_PLL_LOCK      (1<<1)      /* PLL Lock Status */


#endif /* __APMC_H */

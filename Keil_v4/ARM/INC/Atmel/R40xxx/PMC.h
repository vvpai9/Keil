/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  PMC.H:  Header file for Power Management Controller                */
/*                                                                     */
/***********************************************************************/

#ifndef __PMC_H
#define __PMC_H


/*---------------*/
/* PMC Registers */
/*---------------*/
#define PMC_SCER   REG(PMC_BASE + 0x00)    /* System Clock Enable  Register */
#define PMC_SCDR   REG(PMC_BASE + 0x04)    /* System Clock Disable Register */
#define PMC_SCSR   REG(PMC_BASE + 0x08)    /* System Clock Status  Register */
#define PMC_PCER   REG(PMC_BASE + 0x10)    /* Peripheral Clock Enable  Register */
#define PMC_PCDR   REG(PMC_BASE + 0x14)    /* Peripheral Clock Disable Register */
#define PMC_PCSR   REG(PMC_BASE + 0x18)    /* Peripheral Clock Status  Register */
#ifdef AT91M42800
#define PMC_CGMR   REG(PMC_BASE + 0x20)    /* Clock Generator Mode Register */
#define PMC_SR     REG(PMC_BASE + 0x30)    /* Status Register */
#define PMC_IER    REG(PMC_BASE + 0x34)    /* Interrupt Enable Register */
#define PMC_IDR    REG(PMC_BASE + 0x38)    /* Interrupt Disable Register */
#define PMC_IMR    REG(PMC_BASE + 0x3C)    /* Interrupt Mask Register */
#endif


/*-----------------------------------------*/
/* PMC_SCER: System Clock Enable  Register */
/* PMC_SCDR: System Clock Disable Register */
/* PMC_SCSR: System Clock Status  Register */
/*-----------------------------------------*/
#define PMC_CPU              (1<<0)


#ifdef AT91M42800

/*-----------------------------------------*/
/* PMC_CGMR: Clock Generator Mode Register */
/*-----------------------------------------*/

#define PMC_PRES             (7<<0)    /* Prescaler Selection */
#define PMC_PRES_NONE        (0<<0)    /* No prescaler */
#define PMC_PRES_DIV2        (1<<0)    /* Selected Clock Divided by 2 */
#define PMC_PRES_DIV4        (2<<0)    /* Selected Clock Divided by 4 */
#define PMC_PRES_DIV8        (3<<0)    /* Selected Clock Divided by 8 */
#define PMC_PRES_DIV16       (4<<0)    /* Selected Clock Divided by 16 */
#define PMC_PRES_DIV32       (5<<0)    /* Selected Clock Divided by 32 */
#define PMC_PRES_DIV64       (6<<0)    /* Selected Clock Divided by 64 */

#define	PMC_PLL              (1<<3)    /* PLL Selection */
#define	PMC_PLL_A            (0<<3)    /* 5-20 MHz PLL */
#define	PMC_PLL_B            (1<<3)    /* 20-80 MHz PLL */

#define PMC_MCKOSS           (3<<4)    /* Master Clock Output Source Selection */
#define	PMC_MCKOSS_SLCK      (0<<4)    /* Slow Clock */
#define	PMC_MCKOSS_MCK       (1<<4)    /* Master Clock */
#define	PMC_MCKOSS_MCKINV    (2<<4)    /* Master Clock Inverted */
#define	PMC_MCKOSS_MCK_DIV2  (3<<4)    /* Master Clock Divided by 2 */

#define PMC_MCKO             (1<<6)    /* Master Clock Output Disable */
#define	PMC_MCKO_DIS         (1<<6)    /* MCKO is tri-stated */

#define PMC_CSS              (1<<7)    /* Clock Source Selection */
#define	PMC_CSS_LF           (0<<7)    /* Low-Frequency Clock */
#define	PMC_CSS_PLL          (1<<7)    /* Phase Lock Loop Output */

#define PMC_MUL           (0x7FF<<8)
#define PMC_B_MUL         8

#define PMC_PLLCOUNT      (0xFF<<24)
#define PMC_B_PLLCOUNT    24

/*-------------------------------------*/
/* PMC_SR:  Status Register            */
/* PMC_IER: Interrupt Enable  Register */
/* PMC_IDR: Interrupt Disable Register */
/* PMC_IMR: Interrupt Mask    Register */
/*-------------------------------------*/
#define PMC_PLL_LOCK       (1<<0)      /* PLL Lock Status */

#endif /* AT91M42800 */


#endif /* __PMC_H */

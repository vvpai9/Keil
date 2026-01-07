/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  TC.H:  Header file for Timer Counter                               */
/*                                                                     */
/***********************************************************************/

#ifndef __TC_H
#define __TC_H


/*---------------*/
/* TC0 Registers */
/*---------------*/
#define TC0_CCR    REG(TCB0_BASE + 0x00 + 0x00) /* Channel Control Register */
#define TC0_CMR    REG(TCB0_BASE + 0x00 + 0x04) /* Channel Mode Register */
#define TC0_CV     REG(TCB0_BASE + 0x00 + 0x10) /* Counter Value */
#define TC0_RA     REG(TCB0_BASE + 0x00 + 0x14) /* Register A */
#define TC0_RB     REG(TCB0_BASE + 0x00 + 0x18) /* Register B */
#define TC0_RC     REG(TCB0_BASE + 0x00 + 0x1C) /* Register C */
#define TC0_SR     REG(TCB0_BASE + 0x00 + 0x20) /* Status Register */
#define TC0_IER    REG(TCB0_BASE + 0x00 + 0x24) /* Interrupt Enable Register */
#define TC0_IDR    REG(TCB0_BASE + 0x00 + 0x28) /* Interrupt Disable Register */
#define TC0_IMR    REG(TCB0_BASE + 0x00 + 0x2C) /* Interrupt Mask Register */

/*---------------*/
/* TC1 Registers */
/*---------------*/
#define TC1_CCR    REG(TCB0_BASE + 0x40 + 0x00) /* Channel Control Register */
#define TC1_CMR    REG(TCB0_BASE + 0x40 + 0x04) /* Channel Mode Register */
#define TC1_CV     REG(TCB0_BASE + 0x40 + 0x10) /* Counter Value */
#define TC1_RA     REG(TCB0_BASE + 0x40 + 0x14) /* Register A */
#define TC1_RB     REG(TCB0_BASE + 0x40 + 0x18) /* Register B */
#define TC1_RC     REG(TCB0_BASE + 0x40 + 0x1C) /* Register C */
#define TC1_SR     REG(TCB0_BASE + 0x40 + 0x20) /* Status Register */
#define TC1_IER    REG(TCB0_BASE + 0x40 + 0x24) /* Interrupt Enable Register */
#define TC1_IDR    REG(TCB0_BASE + 0x40 + 0x28) /* Interrupt Disable Register */
#define TC1_IMR    REG(TCB0_BASE + 0x40 + 0x2C) /* Interrupt Mask Register */

/*---------------*/
/* TC2 Registers */
/*---------------*/
#define TC2_CCR    REG(TCB0_BASE + 0x80 + 0x00) /* Channel Control Register */
#define TC2_CMR    REG(TCB0_BASE + 0x80 + 0x04) /* Channel Mode Register */
#define TC2_CV     REG(TCB0_BASE + 0x80 + 0x10) /* Counter Value */
#define TC2_RA     REG(TCB0_BASE + 0x80 + 0x14) /* Register A */
#define TC2_RB     REG(TCB0_BASE + 0x80 + 0x18) /* Register B */
#define TC2_RC     REG(TCB0_BASE + 0x80 + 0x1C) /* Register C */
#define TC2_SR     REG(TCB0_BASE + 0x80 + 0x20) /* Status Register */
#define TC2_IER    REG(TCB0_BASE + 0x80 + 0x24) /* Interrupt Enable Register */
#define TC2_IDR    REG(TCB0_BASE + 0x80 + 0x28) /* Interrupt Disable Register */
#define TC2_IMR    REG(TCB0_BASE + 0x80 + 0x2C) /* Interrupt Mask Register */

/*----------------------*/
/* TC Block 0 Registers */
/*----------------------*/
#define TCB0_BCR   REG(TCB0_BASE + 0xC0 + 0x00) /* Block Control Register */
#define TCB0_BMR   REG(TCB0_BASE + 0xC0 + 0x04) /* Block Mode Register */
#define TC_BCR     TCB0_BCR
#define TC_BMR     TCB0_BMR

/*---------------*/
/* TC3 Registers */
/*---------------*/
#define TC3_CCR    REG(TCB1_BASE + 0x00 + 0x00) /* Channel Control Register */
#define TC3_CMR    REG(TCB1_BASE + 0x00 + 0x04) /* Channel Mode Register */
#define TC3_CV     REG(TCB1_BASE + 0x00 + 0x10) /* Counter Value */
#define TC3_RA     REG(TCB1_BASE + 0x00 + 0x14) /* Register A */
#define TC3_RB     REG(TCB1_BASE + 0x00 + 0x18) /* Register B */
#define TC3_RC     REG(TCB1_BASE + 0x00 + 0x1C) /* Register C */
#define TC3_SR     REG(TCB1_BASE + 0x00 + 0x20) /* Status Register */
#define TC3_IER    REG(TCB1_BASE + 0x00 + 0x24) /* Interrupt Enable Register */
#define TC3_IDR    REG(TCB1_BASE + 0x00 + 0x28) /* Interrupt Disable Register */
#define TC3_IMR    REG(TCB1_BASE + 0x00 + 0x2C) /* Interrupt Mask Register */

/*---------------*/
/* TC4 Registers */
/*---------------*/
#define TC4_CCR    REG(TCB1_BASE + 0x40 + 0x00) /* Channel Control Register */
#define TC4_CMR    REG(TCB1_BASE + 0x40 + 0x04) /* Channel Mode Register */
#define TC4_CV     REG(TCB1_BASE + 0x40 + 0x10) /* Counter Value */
#define TC4_RA     REG(TCB1_BASE + 0x40 + 0x14) /* Register A */
#define TC4_RB     REG(TCB1_BASE + 0x40 + 0x18) /* Register B */
#define TC4_RC     REG(TCB1_BASE + 0x40 + 0x1C) /* Register C */
#define TC4_SR     REG(TCB1_BASE + 0x40 + 0x20) /* Status Register */
#define TC4_IER    REG(TCB1_BASE + 0x40 + 0x24) /* Interrupt Enable Register */
#define TC4_IDR    REG(TCB1_BASE + 0x40 + 0x28) /* Interrupt Disable Register */
#define TC4_IMR    REG(TCB1_BASE + 0x40 + 0x2C) /* Interrupt Mask Register */

/*---------------*/
/* TC5 Registers */
/*---------------*/
#define TC5_CCR    REG(TCB1_BASE + 0x80 + 0x00) /* Channel Control Register */
#define TC5_CMR    REG(TCB1_BASE + 0x80 + 0x04) /* Channel Mode Register */
#define TC5_CV     REG(TCB1_BASE + 0x80 + 0x10) /* Counter Value */
#define TC5_RA     REG(TCB1_BASE + 0x80 + 0x14) /* Register A */
#define TC5_RB     REG(TCB1_BASE + 0x80 + 0x18) /* Register B */
#define TC5_RC     REG(TCB1_BASE + 0x80 + 0x1C) /* Register C */
#define TC5_SR     REG(TCB1_BASE + 0x80 + 0x20) /* Status Register */
#define TC5_IER    REG(TCB1_BASE + 0x80 + 0x24) /* Interrupt Enable Register */
#define TC5_IDR    REG(TCB1_BASE + 0x80 + 0x28) /* Interrupt Disable Register */
#define TC5_IMR    REG(TCB1_BASE + 0x80 + 0x2C) /* Interrupt Mask Register */

/*----------------------*/
/* TC Block 1 Registers */
/*----------------------*/
#define TCB1_BCR   REG(TCB1_BASE + 0xC0 + 0x00) /* Block Control Register */
#define TCB1_BMR   REG(TCB1_BASE + 0xC0 + 0x04) /* Block Mode Register */


/*----------------------------------*/
/* TC_CCR: Channel Control Register */
/*----------------------------------*/
#define TC_CLKEN           (1<<0)      /* Clock Enable */
#define TC_CLKDIS          (1<<1)      /* Clock Disable */
#define TC_SWTRG           (1<<2)      /* Software Trigger */

/*-------------------------------*/
/* TC_CMR: Channel Mode Register */
/*-------------------------------*/

/* Clock Selection */
#define TC_CLKS                    7
#define TC_CLKS_MCK2               0
#define TC_CLKS_MCK8               1
#define TC_CLKS_MCK32              2
#define TC_CLKS_MCK128             3
#define TC_CLKS_MCK1024            4
#define TC_CLKS_SLCK               4
#define TC_CLKS_XC0                5
#define TC_CLKS_XC1                6
#define TC_CLKS_XC2                7

/* Clock Invert */
#define TC_CLKI                    (1<<3)

/* Burst Signal Selection */
#define TC_BURST                   (3<<4)
#define TC_BURST_NONE              (0<<4)
#define TC_BUSRT_XC0               (1<<4)
#define TC_BURST_XC1               (2<<4)
#define TC_BURST_XC2               (3<<4)

/* Capture Mode: Counter Clock Stopped with RB Loading */
#define TC_LDBSTOP                 (1<<6)

/* Waveform Mode: Counter Clock Stopped with RC Compare */
#define TC_CPCSTOP                 (1<<6)

/* Capture Mode: Counter Clock Disabled with RB Loading */
#define TC_LDBDIS                  (1<<7)

/* Waveform Mode: Counter Clock Disabled with RC Compare */
#define TC_CPCDIS                  (1<<7)

/* Capture Mode: External Trigger Edge Selection */
#define TC_ETRGEDG                 (3<<8)
#define TC_ETRGEDG_EDGE_NONE       (0<<8)
#define TC_ETRGEDG_RISING_EDGE     (1<<8)
#define TC_ETRGEDG_FALLING_EDGE    (2<<8)
#define TC_ETRGEDG_BOTH_EDGE       (3<<8)

/* Waveform Mode: External Event Edge Selection */
#define TC_EEVTEDG                 (3<<8)
#define TC_EEVTEDG_EDGE_NONE       (0<<8)
#define TC_EEVTEDG_RISING_EDGE     (1<<8)
#define TC_EEVTEDG_FALLING_EDGE    (2<<8)
#define TC_EEVTEDG_BOTH_EDGE       (3<<8)

/* Capture Mode: TIOA or TIOB External Trigger Selection */
#define TC_ABETRG                  (1<<10)
#define TC_ABETRG_TIOB             (0<<10)
#define TC_ABETRG_TIOA             (1<<10)

/* Waveform Mode: External Event Selection */
#define TC_EEVT                    (3<<10)
#define TC_EEVT_TIOB               (0<<10)
#define TC_EEVT_XC0                (1<<10)
#define TC_EEVT_XC1                (2<<10)
#define TC_EEVT_XC2                (3<<10)

/* Waveform Mode: Enable Trigger on External Event */
#define TC_ENETRG                  (1<<12)

/* RC Compare Enable Trigger Enable */
#define TC_CPCTRG                  (1<<14)

/* Mode Selection */
#define TC_WAVE                    (1<<15)
#define TC_CAPT                    (0<<15)

/* Capture Mode: RA Loading Selection */
#define TC_LDRA                    (3<<16)
#define TC_LDRA_EDGE_NONE          (0<<16)
#define TC_LDRA_RISING_EDGE        (1<<16)
#define TC_LDRA_FALLING_EDGE       (2<<16)
#define TC_LDRA_BOTH_EDGE          (3<<16)

/* Waveform Mode: RA Compare Effect on TIOA */
#define TC_ACPA                    (3<<16)
#define TC_ACPA_OUTPUT_NONE        (0<<16)
#define TC_ACPA_SET_OUTPUT         (1<<16)
#define TC_ACPA_CLEAR_OUTPUT       (2<<16)
#define TC_ACPA_TOGGLE_OUTPUT      (3<<16)

/* Capture Mode: RB Loading Selection */
#define TC_LDRB                    (3<<18)
#define TC_LDRB_EDGE_NONE          (0<<18)
#define TC_LDRB_RISING_EDGE        (1<<18)
#define TC_LDRB_FALLING_EDGE       (2<<18)
#define TC_LDRB_BOTH_EDGE          (3<<18)

/* Waveform Mode: RC Compare Effect on TIOA */
#define TC_ACPC                    (3<<18)
#define TC_ACPC_OUTPUT_NONE        (0<<18)
#define TC_ACPC_SET_OUTPUT         (1<<18)
#define TC_ACPC_CLEAR_OUTPUT       (2<<18)
#define TC_ACPC_TOGGLE_OUTPUT      (3<<18)

/* Waveform Mode: External Event Effect on TIOA */
#define TC_AEEVT                   (3<<20)
#define TC_AEEVT_OUTPUT_NONE       (0<<20)
#define TC_AEEVT_SET_OUTPUT        (1<<20)
#define TC_AEEVT_CLEAR_OUTPUT      (2<<20)
#define TC_AEEVT_TOGGLE_OUTPUT     (3<<20)

/* Waveform Mode: Software Trigger Effect on TIOA */
#define TC_ASWTRG                  (3<<22)
#define TC_ASWTRG_OUTPUT_NONE      (0<<22)
#define TC_ASWTRG_SET_OUTPUT       (1<<22)
#define TC_ASWTRG_CLEAR_OUTPUT     (2<<22)
#define TC_ASWTRG_TOGGLE_OUTPUT    (3<<22)

/* Waveform Mode: RB Compare Effect on TIOB */
#define TC_BCPB                    (3<<24)
#define TC_BCPB_OUTPUT_NONE        (0<<24)
#define TC_BCPB_SET_OUTPUT         (1<<24)
#define TC_BCPB_CLEAR_OUTPUT       (2<<24)
#define TC_BCPB_TOGGLE_OUTPUT      (3<<24)

/* Waveform Mode: RC Compare Effect on TIOB */
#define TC_BCPC                    (3<<26)
#define TC_BCPC_OUTPUT_NONE        (0<<26)
#define TC_BCPC_SET_OUTPUT         (1<<26)
#define TC_BCPC_CLEAR_OUTPUT       (2<<26)
#define TC_BCPC_TOGGLE_OUTPUT      (3<<26)

/* Waveform Mode: External Event Effect on TIOB */
#define TC_BEEVT                   (3<<28)
#define TC_BEEVT_OUTPUT_NONE       (0<<28)
#define TC_BEEVT_SET_OUTPUT        (1<<28)
#define TC_BEEVT_CLEAR_OUTPUT      (2<<28)
#define TC_BEEVT_TOGGLE_OUTPUT     (3<<28)

/* Waveform Mode: Software Trigger Effect on TIOB */
#define TC_BSWTRG                  (3<<30)
#define TC_BSWTRG_OUTPUT_NONE      (0<<30)
#define TC_BSWTRG_SET_OUTPUT       (1<<30)
#define TC_BSWTRG_CLEAR_OUTPUT     (2<<30)
#define TC_BSWTRG_TOGGLE_OUTPUT    (3<<30)

/*------------------------*/
/* TC_SR: Status Register */
/*------------------------*/
#define TC_COVFS           (1<<0)      /* Counter Overflow Status */
#define TC_LOVRS           (1<<1)      /* Load Overrun Status */
#define TC_CPAS            (1<<2)      /* RA Compare Status */
#define TC_CPBS            (1<<3)      /* RB Compare Status */
#define TC_CPCS            (1<<4)      /* RC Compare Status */
#define TC_LDRAS           (1<<5)      /* RA Loading Status */
#define TC_LDRBS           (1<<6)      /* RB Loading Status */
#define TC_ETRGS           (1<<7)      /* External Trigger Status */
#define TC_CLKSTA          (1<<16)     /* Clock Status */
#define TC_MTIOA           (1<<17)     /* TIOA Mirror */
#define TC_MTIOB           (1<<18)     /* TIOB Status */

/*--------------------------------*/
/* TC_BCR: Block Control Register */
/*--------------------------------*/
#define TC_SYNC            (1<<0)      /* Synchronisation Trigger */

/*-----------------------------*/
/* TC_BMR: Block Mode Register */
/*-----------------------------*/

/* External Clock Signal 0 Selection */
#define TC_TC0XC0S         (3<<0)
#define TC_TCLK0XC0        (0<<0)
#define TC_NONEXC0         (1<<0)
#define TC_TIOA1XC0        (2<<0)
#define TC_TIOA2XC0        (3<<0)

/* External Clock Signal 1 Selection */
#define TC_TC1XC1S         (3<<2)
#define TC_TCLK1XC1        (0<<2)
#define TC_NONEXC1         (1<<2)
#define TC_TIOA0XC1        (2<<2)
#define TC_TIOA2XC1        (3<<2)

/* External Clock Signal 2 Selection */
#define TC_TC2XC2S         (3<<4)
#define TC_TCLK2XC2        (0<<4)
#define TC_NONEXC2         (1<<4)
#define TC_TIOA0XC2        (2<<4)
#define TC_TIOA1XC2        (3<<4)


#endif /* __TC_H */

/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  ADC.H:  Header file for Analog to Digital Converter                */
/*                                                                     */
/***********************************************************************/

#ifndef __ADC_H
#define __ADC_H


/*----------------*/
/* ADC0 Registers */
/*----------------*/
#define ADC0_CR    REG(ADC0_BASE + 0x00)   /* Control Register */
#define ADC0_MR    REG(ADC0_BASE + 0x04)   /* Mode Register */
#define ADC0_CHER  REG(ADC0_BASE + 0x10)   /* Channel Enable Register */
#define ADC0_CHDR  REG(ADC0_BASE + 0x14)   /* Channel Disable Register */
#define ADC0_CHSR  REG(ADC0_BASE + 0x18)   /* Channel Status Register */
#define ADC0_SR    REG(ADC0_BASE + 0x20)   /* Status Register */
#define ADC0_IER   REG(ADC0_BASE + 0x24)   /* Interrupt Enable Register */
#define ADC0_IDR   REG(ADC0_BASE + 0x28)   /* Interrupt Disable Register */
#define ADC0_IMR   REG(ADC0_BASE + 0x2C)   /* Interrupt Mask Register */
#define ADC0_CDR0  REG(ADC0_BASE + 0x30)   /* Convert Data Registers 0 */
#define ADC0_CDR1  REG(ADC0_BASE + 0x34)   /* Convert Data Registers 1 */
#define ADC0_CDR2  REG(ADC0_BASE + 0x38)   /* Convert Data Registers 2 */
#define ADC0_CDR3  REG(ADC0_BASE + 0x3C)   /* Convert Data Registers 3 */

/*----------------*/
/* ADC1 Registers */
/*----------------*/
#define ADC1_CR    REG(ADC1_BASE + 0x00)   /* Control Register */
#define ADC1_MR    REG(ADC1_BASE + 0x04)   /* Mode Register */
#define ADC1_CHER  REG(ADC1_BASE + 0x10)   /* Channel Enable Register */
#define ADC1_CHDR  REG(ADC1_BASE + 0x14)   /* Channel Disable Register */
#define ADC1_CHSR  REG(ADC1_BASE + 0x18)   /* Channel Status Register */
#define ADC1_SR    REG(ADC1_BASE + 0x20)   /* Status Register */
#define ADC1_IER   REG(ADC1_BASE + 0x24)   /* Interrupt Enable Register */
#define ADC1_IDR   REG(ADC1_BASE + 0x28)   /* Interrupt Disable Register */
#define ADC1_IMR   REG(ADC1_BASE + 0x2C)   /* Interrupt Mask Register */
#define ADC1_CDR0  REG(ADC1_BASE + 0x30)   /* Convert Data Registers 0 */
#define ADC1_CDR1  REG(ADC1_BASE + 0x34)   /* Convert Data Registers 1 */
#define ADC1_CDR2  REG(ADC1_BASE + 0x38)   /* Convert Data Registers 2 */
#define ADC1_CDR3  REG(ADC1_BASE + 0x3C)   /* Convert Data Registers 3 */


/*--------------------------*/
/* ADC_CR: Control Register */
/*--------------------------*/
#define ADC_SWRST          (1<<0)      /* Software Reset */
#define ADC_START          (1<<1)      /* Start Conversion */

/*-----------------------*/
/* ADC_MR: Mode Register */
/*-----------------------*/

/* Trigger Enable */
#define ADC_TRGEN          (1<<0)
#define ADC_TRGEN_DIS      (0<<0)      /* Trigger Disable */
#define ADC_TRGEN_EN       (1<<0)      /* Trigger Enable */

/* Trigger Selection */
#define ADC_TRG            (7<<1)
#define ADC_TRG_TIOA0      (0<<1)      /* TIOA0 Trigger */
#define ADC_TRG_TIOA1      (1<<1)      /* TIOA1 Trigger */
#define ADC_TRG_TIOA2      (2<<1)      /* TIOA2 Trigger */
#define ADC_TRG_TIOA3      (3<<1)      /* TIOA3 Trigger */
#define ADC_TRG_TIOA4      (4<<1)      /* TIOA4 Trigger */
#define ADC_TRG_TIOA5      (5<<1)      /* TIOA5 Trigger */
#define ADC_TRG_EXT        (6<<1)      /* External Trigger */

/* Resolution */
#define ADC_10_BIT_RES     (0<<4)      /* 10-bit Resolution */
#define ADC_8_BIT_RES      (1<<4)      /*  8-bit Resolution */

/* Sleep Mode */
#define ADC_NORMAL_MODE    (0<<5)      /* Normal Mode */
#define ADC_SLEEP_MODE     (1<<5)      /* Sleep Mode */

/* Prescaler */
#define ADC_PRESCAL        (0x3F<<8)   /* Max Prescaler Value */
#define ADC_B_PRESCAL      8           /* Prescaler Bit Shift */

/*------------------------------------*/
/* ADC_CHER: Channel Enable  Register */
/* ADC_CHDR: Channel Disable Register */
/* ADC_CHSR: Channel Status  Register */
/*------------------------------------*/
#define ADC_CH0            (1<<0)      /* Channel 0 */
#define ADC_CH1            (1<<1)      /* Channel 1 */
#define ADC_CH2            (1<<2)      /* Channel 2 */
#define ADC_CH3            (1<<3)      /* Channel 3 */

/*-------------------------------------*/
/* ADC_SR:  Status Register            */
/* ADC_IER: Interrupt Enable  Register */
/* ADC_IDR: Interrupt Disable Register */
/* ADC_IMR: Interrupt Mask    Register */
/*-------------------------------------*/
#define ADC_EOC0           (1<<0)      /* End of Conversion Channel 0 */
#define ADC_EOC1           (1<<1)      /* End of Conversion Channel 1 */
#define ADC_EOC2           (1<<2)      /* End of Conversion Channel 2 */
#define ADC_EOC3           (1<<3)      /* End of Conversion Channel 3 */

#define ADC_OVRE0          (1<<8)      /* Overrun Error Channel 0 */
#define ADC_OVRE1          (1<<9)      /* Overrun Error Channel 1 */
#define ADC_OVRE2          (1<<10)     /* Overrun Error Channel 2 */
#define ADC_OVRE3          (1<<11)     /* Overrun Error Channel 3 */

/*-------------------------------------*/
/* ADC_CDR0..3: Convert Data Registers */
/*-------------------------------------*/
#define ADC_DATA_10BITS    0x03FF      /* 10-bits Data Mask */
#define ADC_DATA_8BITS     0x00FF      /*  8-bits Data Mask */


#endif /* __ADC_H */

/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  DAC.H:  Header file for Digital to Analog Converter                */
/*                                                                     */
/***********************************************************************/

#ifndef __DAC_H
#define __DAC_H


/*----------------*/
/* DAC0 Registers */
/*----------------*/
#define DAC0_CR    REG(DAC0_BASE + 0x00)   /* Control Register */
#define DAC0_MR    REG(DAC0_BASE + 0x04)   /* Mode Register */
#define DAC0_DHR   REG(DAC0_BASE + 0x08)   /* Data Holding Register */
#define DAC0_DOR   REG(DAC0_BASE + 0x0C)   /* Data Output Register */
#define DAC0_SR    REG(DAC0_BASE + 0x10)   /* Status Register */
#define DAC0_IER   REG(DAC0_BASE + 0x14)   /* Interrupt Enable Register */
#define DAC0_IDR   REG(DAC0_BASE + 0x18)   /* Interrupt Disable Register */
#define DAC0_IMR   REG(DAC0_BASE + 0x1C)   /* Interrupt Mask Register */

/*----------------*/
/* DAC1 Registers */
/*----------------*/
#define DAC1_CR    REG(DAC1_BASE + 0x00)   /* Control Register */
#define DAC1_MR    REG(DAC1_BASE + 0x04)   /* Mode Register */
#define DAC1_DHR   REG(DAC1_BASE + 0x08)   /* Data Holding Register */
#define DAC1_DOR   REG(DAC1_BASE + 0x0C)   /* Data Output Register */
#define DAC1_SR    REG(DAC1_BASE + 0x10)   /* Status Register */
#define DAC1_IER   REG(DAC1_BASE + 0x14)   /* Interrupt Enable Register */
#define DAC1_IDR   REG(DAC1_BASE + 0x18)   /* Interrupt Disable Register */
#define DAC1_IMR   REG(DAC1_BASE + 0x1C)   /* Interrupt Mask Register */


/*--------------------------*/
/* DAC_CR: Control Register */
/*--------------------------*/
#define DAC_SWRST          (1<<0)      /* Sowtware Reset */

/*-----------------------*/
/* DAC_MR: Mode Register */
/*-----------------------*/

/* Timer Trigger Enable */
#define DAC_TTRGEN         (1<<0)
#define DAC_TTRGEN_DIS     (0<<0)      /* Timer Trigger Disable */
#define DAC_TTRGEN_EN      (1<<0)      /* Timer Trigger Enable */

/* Timer Trigger Selection */
#define DAC_TRG            (7<<1)
#define DAC_TRG_TIOA0      (0<<1)      /* TIOA0 Trigger */
#define DAC_TRG_TIOA1      (1<<1)      /* TIOA1 Trigger */
#define DAC_TRG_TIOA2      (2<<1)      /* TIOA2 Trigger */
#define DAC_TRG_TIOA3      (3<<1)      /* TIOA3 Trigger */
#define DAC_TRG_TIOA4      (4<<1)      /* TIOA4 Trigger */
#define DAC_TRG_TIOA5      (5<<1)      /* TIOA5 Trigger */

/* Resolution */
#define DAC_10_BIT_RES     (0<<4)      /* 10-bit Resolution */
#define DAC_8_BIT_RES      (1<<4)      /*  8-bit Resolution */

/*--------------------------------*/
/* DAC_DHR: Data Holding Register */
/* DAC_DOR: Data Output  Register */
/*--------------------------------*/
#define DAC_DATA_10BITS    0x03FF      /* 10-bits Data Mask */
#define DAC_DATA_8BITS     0x00FF      /*  8-bits Data Mask */

/*-------------------------------------*/
/* DAC_SR:  Status Register            */
/* DAC_IER: Interrupt Enable  Register */
/* DAC_IDR: Interrupt Disable Register */
/* DAC_IMR: Interrupt Mask    Register */
/*-------------------------------------*/
#define DAC_DATRDY         (1<<0)      /* Data Ready */


#endif /* __DAC_H */

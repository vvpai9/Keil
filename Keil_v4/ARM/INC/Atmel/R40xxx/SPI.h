/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  SPI.H:  Header file for Serial Peripheral Interface                */
/*                                                                     */
/***********************************************************************/

#ifndef __SPI_H
#define __SPI_H


/*---------------*/
/* SPI Registers */
/*---------------*/
#define SP_CR      REG(SPI_BASE + 0x00)    /* Control Register */
#define SP_MR      REG(SPI_BASE + 0x04)    /* Mode Register */
#define SP_RDR     REG(SPI_BASE + 0x08)    /* Receive Data Register */
#define SP_TDR     REG(SPI_BASE + 0x0C)    /* Transmit Data Register */
#define SP_SR      REG(SPI_BASE + 0x10)    /* Status Register */
#define SP_IER     REG(SPI_BASE + 0x14)    /* Interrupt Enable Register */
#define SP_IDR     REG(SPI_BASE + 0x18)    /* Interrupt Disable Register */
#define SP_IMR     REG(SPI_BASE + 0x1C)    /* Interrupt Mask Register */
#define SP_RPR     REG(SPI_BASE + 0x20)    /* Receive Pointer_Register */
#define SP_RCR     REG(SPI_BASE + 0x24)    /* Receive Counter Register */
#define SP_TPR     REG(SPI_BASE + 0x28)    /* Transmit Pointer_Register */
#define SP_TCR     REG(SPI_BASE + 0x2C)    /* Transmit Counter Register */
#define SP_CSR0    REG(SPI_BASE + 0x30)    /* Chip Select Register 0 */
#define SP_CSR1    REG(SPI_BASE + 0x34)    /* Chip Select Register 1 */
#define SP_CSR2    REG(SPI_BASE + 0x38)    /* Chip Select Register 2 */
#define SP_CSR3    REG(SPI_BASE + 0x3C)    /* Chip Select Register 3 */

/*----------------*/
/* SPIA Registers */
/*----------------*/
#define SPA_CR     REG(SPIA_BASE + 0x00)   /* Control Register */
#define SPA_MR     REG(SPIA_BASE + 0x04)   /* Mode Register */
#define SPA_RDR    REG(SPIA_BASE + 0x08)   /* Receive Data Register */
#define SPA_TDR    REG(SPIA_BASE + 0x0C)   /* Transmit Data Register */
#define SPA_SR     REG(SPIA_BASE + 0x10)   /* Status Register */
#define SPA_IER    REG(SPIA_BASE + 0x14)   /* Interrupt Enable Register */
#define SPA_IDR    REG(SPIA_BASE + 0x18)   /* Interrupt Disable Register */
#define SPA_IMR    REG(SPIA_BASE + 0x1C)   /* Interrupt Mask Register */
#define SPA_RPR    REG(SPIA_BASE + 0x20)   /* Receive Pointer_Register */
#define SPA_RCR    REG(SPIA_BASE + 0x24)   /* Receive Counter Register */
#define SPA_TPR    REG(SPIA_BASE + 0x28)   /* Transmit Pointer_Register */
#define SPA_TCR    REG(SPIA_BASE + 0x2C)   /* Transmit Counter Register */
#define SPA_CSR0   REG(SPIA_BASE + 0x30)   /* Chip Select Register 0 */
#define SPA_CSR1   REG(SPIA_BASE + 0x34)   /* Chip Select Register 1 */
#define SPA_CSR2   REG(SPIA_BASE + 0x38)   /* Chip Select Register 2 */
#define SPA_CSR3   REG(SPIA_BASE + 0x3C)   /* Chip Select Register 3 */

/*----------------*/
/* SPIB Registers */
/*----------------*/
#define SPB_CR     REG(SPIB_BASE + 0x00)   /* Control Register */
#define SPB_MR     REG(SPIB_BASE + 0x04)   /* Mode Register */
#define SPB_RDR    REG(SPIB_BASE + 0x08)   /* Receive Data Register */
#define SPB_TDR    REG(SPIB_BASE + 0x0C)   /* Transmit Data Register */
#define SPB_SR     REG(SPIB_BASE + 0x10)   /* Status Register */
#define SPB_IER    REG(SPIB_BASE + 0x14)   /* Interrupt Enable Register */
#define SPB_IDR    REG(SPIB_BASE + 0x18)   /* Interrupt Disable Register */
#define SPB_IMR    REG(SPIB_BASE + 0x1C)   /* Interrupt Mask Register */
#define SPB_RPR    REG(SPIB_BASE + 0x20)   /* Receive Pointer_Register */
#define SPB_RCR    REG(SPIB_BASE + 0x24)   /* Receive Counter Register */
#define SPB_TPR    REG(SPIB_BASE + 0x28)   /* Transmit Pointer_Register */
#define SPB_TCR    REG(SPIB_BASE + 0x2C)   /* Transmit Counter Register */
#define SPB_CSR0   REG(SPIB_BASE + 0x30)   /* Chip Select Register 0 */
#define SPB_CSR1   REG(SPIB_BASE + 0x34)   /* Chip Select Register 1 */
#define SPB_CSR2   REG(SPIB_BASE + 0x38)   /* Chip Select Register 2 */
#define SPB_CSR3   REG(SPIB_BASE + 0x3C)   /* Chip Select Register 3 */


/*-------------------------*/
/* SP_CR: Control Register */
/*-------------------------*/
#define SP_SPIEN           (1<<0)      /* SPI Enable */
#define SP_SPIDIS          (1<<1)      /* SPI Disable */
#define SP_SWRST           (1<<7)      /* SPI Software Reset */

/*----------------------*/
/* SP_MR: Mode Register */
/*----------------------*/

#define SP_MSTR            (1<<0)      /* Master Mode Select */

#define SP_PS              (1<<1)      /* Peripheral Select */
#define SP_PS_FIXED        (0<<1)      /* Fixed Peripheral Select */
#define SP_PS_VARIABLE     (1<<1)      /* Variable Peripheral Select */

#define SP_PCSDEC          (1<<2)      /* Chip Select Decode */
#define SP_DIV32           (1<<4)      /* Clock Selection */
#define SP_LLB             (1<<7)      /* Local Loopback */

#define SP_PCS             (0x0F<<16)  /* Peripheral Chip Select */
#define SP_PCS0            (0x0E<<16)  /* Chip Select 0 */
#define SP_PCS1            (0x0D<<16)  /* Chip Select 1 */
#define SP_PCS2            (0x0B<<16)  /* Chip Select 2 */
#define SP_PCS3            (0x07<<16)  /* Chip Select 3 */

#define SP_DLYBCS          (0xFF<<24)  /* Delay Before Chip Selects */

/*--------------------------------*/
/* SP_RDR: Receive Data Register  */
/* SP_TDR: Transmit Data Register */
/*--------------------------------*/
#define SP_RD              0xFFFF      /* Receive Data */
#define SP_TD              0xFFFF      /* Transmit Data */

/*------------------------*/
/* SP_SR: Status Register */
/*------------------------*/
#define SP_RDRF            (1<<0)      /* Receive Data Register Full */
#define SP_TDRE            (1<<1)      /* Transmitte Data Register Empty */
#define SP_MODF            (1<<2)      /* Mode Fault */
#define SP_OVRES           (1<<3)      /* Overrun Error Status */
#define SP_ENDRX           (1<<4)      /* End of Receiver Transfer */
#define SP_ENDTX           (1<<5)      /* End of Transmitter Transfer */
#define SP_SPIENS          (1<<16)     /* SPI Enable Status */

/*-------------------------------*/
/* SP_CSR: Chip Select Registers */
/*-------------------------------*/

#define SP_CPOL            (1<<0)      /* Clock Polarity */
#define SP_NCPHA           (1<<1)      /* Clock Phase */

#define SP_BITS            (0x0F<<4)   /* Bits Per Transfer */
#define SP_BITS_8          (0x00<<4)   /* 8 Bits Per Transfer */
#define SP_BITS_9          (0x01<<4)   /* 9 Bits Per Transfer */
#define SP_BITS_10         (0x02<<4)   /* 10 Bits Per Transfer */
#define SP_BITS_11         (0x03<<4)   /* 11 Bits Per Transfer */
#define SP_BITS_12         (0x04<<4)   /* 12 Bits Per Transfer */
#define SP_BITS_13         (0x05<<4)   /* 13 Bits Per Transfer */
#define SP_BITS_14         (0x06<<4)   /* 14 Bits Per Transfer */
#define SP_BITS_15         (0x07<<4)   /* 15 Bits Per Transfer */
#define SP_BITS_16         (0x08<<4)   /* 16 Bits Per Transfer */

#define SP_SCBR            (0xFF<<8)   /* Serial Clock Baud Rate */
#define SP_DLYBS           (0xFF<<16)  /* Delay Before SPCK */
#define SP_DLYBCT          (0xFF<<24)  /* Delay Between Consecutive Transfer */


#endif /* __SPI_H */

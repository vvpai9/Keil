/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2005                           */
/***********************************************************************/
/*                                                                     */
/*  91C140.H:  Header file for AT91C140                                */
/*  27-09-2005: preleminary release                                    */
/***********************************************************************/

#ifndef __91C140_H
#define __91C140_H

#define REG(x) (*((volatile unsigned int *)(x)))

/*-----------------------*/
/* Peripheral Memory Map */
/*-----------------------*/

#define SYSC_BASE    0xFF000000    /* System Controller                */
#define SMC_BASE     0xFF004000    /* Static Memory Controller         */
#define SDRAMC_BASE  0xFF008000    /* SDRAM Controller                 */
#define PIOA_BASE    0xFF00C000    /* Parallel I/O Controller A        */
#define PIOB_BASE    0xFF010000    /* Parallel I/O Controller B        */
#define UART0_BASE   0xFF018000    /* Parallel I/O Controller A        */
#define UART1_BASE   0xFF01C000    /* Parallel I/O Controller B        */
#define SPI_BASE     0xFF020000    /* Serial Peripheral Interface      */
#define AIC_BASE     0xFFFFF000    /* Advanced Interrupt Controller    */
#define MAC0_BASE    0xFF034000    /* Ethernet MAC0                    */
#define MAC1_BASE    0xFF038000    /* Ethernet MAC1                    */



/*----------------------------------------------------------------------*/
/* SYSC Registers                                                       */
/*----------------------------------------------------------------------*/
#define SYS_MD      REG(SYSC_BASE + 0x00)    /* System Mode Register    */
#define SYS_ID      REG(SYSC_BASE + 0x04)    /* System ID Register      */
#define SYS_CLKF    REG(SYSC_BASE + 0x0C)    /* System Clock Status     */

/*-------------------------------*/
/* SYS_MD: System Mode Register  */
/*-------------------------------*/
#define SYS_MD_RM           (1<<0)           /* Remap                  */
#define SYS_MD_LP           (1<<6)           /* Low Power Mode         */
#define SYS_MD_SA           (1<<7)           /* Slow ARM               */
#define SYS_MD_LPCS         (3<<8)           /* Low Power Clock Select */

/*-----------------------------------------*/
/* SYS_CLKF: System Clock Status Register  */
/*-----------------------------------------*/
#define SYS_CLKF_ACLKST           (1<<0)     /* ARM Clock Status       */



/*-----------------------------------------------------------------------*/
/* SMC Registers                                                         */
/*-----------------------------------------------------------------------*/

#define SMC_CSR0      REG(SMC_BASE + 0x00)    /* Chip Select Register    */
#define SMC_CSR1      REG(SMC_BASE + 0x04)    /* Chip Select Register    */
#define SMC_CSR2      REG(SMC_BASE + 0x08)    /* Chip Select Register    */
#define SMC_CSR3      REG(SMC_BASE + 0x0C)    /* Chip Select Register    */
#define SMC_MCR       REG(SMC_BASE + 0x24)    /* Memory Control Register */

/*----------------------------------*/
/* SMC_CSR0: Chip Select Register   */
/*----------------------------------*/
#define SMC_CSR0_DBW           (3<<0)         /* Data Bus Width          */
#define SMC_CSR0_NWS           (7<<2)         /* Number of Wait States   */
#define SMC_CSR0_WSE           (1<<5)         /* Wait State Enable       */
#define SMC_CSR0_MWS           (1<<6)         /* Multiply Wait States    */
#define SMC_CSR0_PAGES         (3<<7)         /* Page Size               */
#define SMC_CSR0_TDF           (7<<9)         /* Data Float Output Time  */
#define SMC_CSR0_BAT           (1<<12)        /* Byte Access Mode        */
#define SMC_CSR0_CSEN          (1<<13)        /* Chip Select Enable      */
#define SMC_CSR0_BA            (15<<20)       /* Base Address            */									  
/*----------------------------------*/
/* SMC_CSR1: Chip Select Register   */
/*----------------------------------*/
#define SMC_CSR1_DBW           (3<<0)         /* Data Bus Width          */
#define SMC_CSR1_NWS           (7<<2)         /* Number of Wait States   */
#define SMC_CSR1_WSE           (1<<5)         /* Wait State Enable       */
#define SMC_CSR1_MWS           (1<<6)         /* Multiply Wait States    */
#define SMC_CSR1_PAGES         (3<<7)         /* Page Size               */
#define SMC_CSR1_TDF           (7<<9)         /* Data Float Output Time  */
#define SMC_CSR1_BAT           (1<<12)        /* Byte Access Mode        */
#define SMC_CSR1_CSEN          (1<<13)        /* Chip Select Enable      */
#define SMC_CSR1_BA            (15<<20)       /* Base Address            */	

/*----------------------------------*/
/* SMC_CSR2: Chip Select Register   */
/*----------------------------------*/
#define SMC_CSR2_DBW           (3<<0)         /* Data Bus Width          */
#define SMC_CSR2_NWS           (7<<2)         /* Number of Wait States   */
#define SMC_CSR2_WSE           (1<<5)         /* Wait State Enable       */
#define SMC_CSR2_MWS           (1<<6)         /* Multiply Wait States    */
#define SMC_CSR2_PAGES         (3<<7)         /* Page Size               */
#define SMC_CSR2_TDF           (7<<9)         /* Data Float Output Time  */
#define SMC_CSR2_BAT           (1<<12)        /* Byte Access Mode        */
#define SMC_CSR2_CSEN          (1<<13)        /* Chip Select Enable      */
#define SMC_CSR2_BA            (15<<20)       /* Base Address            */	

/*----------------------------------*/
/* SMC_CSR3: Chip Select Register   */
/*----------------------------------*/
#define SMC_CSR3_DBW           (3<<0)         /* Data Bus Width          */
#define SMC_CSR3_NWS           (7<<2)         /* Number of Wait States   */
#define SMC_CSR3_WSE           (1<<5)         /* Wait State Enable       */
#define SMC_CSR3_MWS           (1<<6)         /* Multiply Wait States    */
#define SMC_CSR3_PAGES         (3<<7)         /* Page Size               */
#define SMC_CSR3_TDF           (7<<9)         /* Data Float Output Time  */
#define SMC_CSR3_BAT           (1<<12)        /* Byte Access Mode        */
#define SMC_CSR3_CSEN          (1<<13)        /* Chip Select Enable      */
#define SMC_CSR3_BA            (15<<20)       /* Base Address            */	

/*----------------------------------*/
/* SMC_MCR: Memory Control Register */
/*----------------------------------*/
#define SMC_MCR_DRP            (1<<4)         /* Data Read Protocol      */



/*-----------------------------------------------------------------------------*/
/* SDRAMC Registers                                                            */
/*-----------------------------------------------------------------------------*/

#define SDRAMC_MR     REG(SDRAMC_BASE + 0x00) /* SDRAMC Mode Register          */
#define SDRAMC_TR     REG(SDRAMC_BASE + 0x04) /* SDRAMC Refresh Timer Register */
#define SDRAMC_CR     REG(SDRAMC_BASE + 0x08) /* SDRAMC Configuration Register */
#define SDRAMC_16BIT  REG(SDRAMC_BASE + 0x0C) /* SDRAMC 16-bit Configuration   */
#define SDRAMC_ADDR   REG(SDRAMC_BASE + 0x10) /* Base Address for SDCS         */

/*------------------------------------------*/
/* SDRAMC_MR: SDRAMC Mode Register          */
/*------------------------------------------*/
#define SDRAMC_MR_MODE         (7<<6)         /* SDRAMC Command Mode           */

/*------------------------------------------*/
/* SDRAMC_TR: SDRAMC Refresh Timer Register */
/*------------------------------------------*/
#define SDRAMC_TR_COUNT        (4095<<0)      /* SDRAMC Refresh Timer Count    */

/*------------------------------------------*/
/* SDRAMC_CR: SDRAMC Configuration Register */
/*------------------------------------------*/
#define SDRAMC_CR_NC           (3<<0)         /* Number of Column Bits         */
#define SDRAMC_CR_NR           (3<<2)         /* Number of Row Bits            */
#define SDRAMC_CR_NB           (1<<4)         /* Number of Banks               */
#define SDRAMC_CR_TWR          (7<<7)         /* Write Recovery Delay          */
#define SDRAMC_CR_TRC          (7<<11)        /* Row Cycle Delay               */
#define SDRAMC_CR_TRP          (7<<15)        /* Row Precharge Delay           */
#define SDRAMC_CR_TRCD         (7<<19)        /* Row to Column Delay           */
#define SDRAMC_CR_TRAS         (7<<23)        /* Active to Precharge Delay     */

/*------------------------------------------*/
/* SDRAMC_ADDR: Base Address for SDCS       */
/*------------------------------------------*/
#define SDRAMC_ADDR_SDCS_ADDR  (255<<0)       /* 8MSB of Base Address of SDRAMC*/



/*-----------------------------------------------------------------------------*/
/* PIOA Registers                                                              */
/*-----------------------------------------------------------------------------*/

#define PIOA_PER      REG(PIOA_BASE + 0x00)    /* PIO Enable Register          */
#define PIOA_PDR      REG(PIOA_BASE + 0x04)    /* PIO Disable Register         */
#define PIOA_PSR      REG(PIOA_BASE + 0x08)    /* PIO Status Register          */
#define PIOA_OER      REG(PIOA_BASE + 0x10)    /* Output Enable Register       */
#define PIOA_ODR      REG(PIOA_BASE + 0x14)    /* Output Disable Register      */
#define PIOA_OSR      REG(PIOA_BASE + 0x18)    /* Output Status Register       */
#define PIOA_SODR     REG(PIOA_BASE + 0x30)    /* Set Output Data Register     */
#define PIOA_CODR     REG(PIOA_BASE + 0x34)    /* Clear Output Data Register   */
#define PIOA_ODSR     REG(PIOA_BASE + 0x38)    /* Output Data Status Register  */
#define PIOA_PDSR     REG(PIOA_BASE + 0x3C)    /* Pin Data Status Register     */
#define PIOA_IER      REG(PIOA_BASE + 0x40)    /* Interrupt Enable Register    */
#define PIOA_IDR      REG(PIOA_BASE + 0x44)    /* Interrupt Disable Register   */
#define PIOA_IMR      REG(PIOA_BASE + 0x48)    /* Interrupt Mask Register      */
#define PIOA_ISR      REG(PIOA_BASE + 0x4C)    /* Interrupt Status Register    */
					  
/*-----------------------------------------------------------------------------*/
/* PIOA Registers                                                              */
/*-----------------------------------------------------------------------------*/

#define PIOB_PER      REG(PIOA_BASE + 0x00)    /* PIO Enable Register          */
#define PIOB_PDR      REG(PIOA_BASE + 0x04)    /* PIO Disable Register         */
#define PIOB_PSR      REG(PIOA_BASE + 0x08)    /* PIO Status Register          */
#define PIOB_OER      REG(PIOA_BASE + 0x10)    /* Output Enable Register       */
#define PIOB_ODR      REG(PIOA_BASE + 0x14)    /* Output Disable Register      */
#define PIOB_OSR      REG(PIOA_BASE + 0x18)    /* Output Status Register       */
#define PIOB_SODR     REG(PIOA_BASE + 0x30)    /* Set Output Data Register     */
#define PIOB_CODR     REG(PIOA_BASE + 0x34)    /* Clear Output Data Register   */
#define PIOB_ODSR     REG(PIOA_BASE + 0x38)    /* Output Data Status Register  */
#define PIOB_PDSR     REG(PIOA_BASE + 0x3C)    /* Pin Data Status Register     */
#define PIOB_IER      REG(PIOA_BASE + 0x40)    /* Interrupt Enable Register    */
#define PIOB_IDR      REG(PIOA_BASE + 0x44)    /* Interrupt Disable Register   */
#define PIOB_IMR      REG(PIOA_BASE + 0x48)    /* Interrupt Mask Register      */
#define PIOB_ISR      REG(PIOA_BASE + 0x4C)    /* Interrupt Status Register    */

/*-----------*/
/* Port Pins */
/*-----------*/

#define P0         (1<<0)
#define P1         (1<<1)
#define P2         (1<<2)
#define P3         (1<<3)
#define P4         (1<<4)
#define P5         (1<<5)
#define P6         (1<<6)
#define P7         (1<<7)
#define P8         (1<<8)
#define P9         (1<<9)
#define P10        (1<<10)
#define P11        (1<<11)
#define P12        (1<<12)
#define P13        (1<<13)
#define P14        (1<<14)
#define P15        (1<<15)
#define P16        (1<<16)
#define P17        (1<<17)
#define P18        (1<<18)
#define P19        (1<<19)
#define P20        (1<<20)
#define P21        (1<<21)
#define P22        (1<<22)
#define P23        (1<<23)
#define P24        (1<<24)
#define P25        (1<<25)
#define P26        (1<<26)
#define P27        (1<<27)
#define P28        (1<<28)
#define P29        (1<<29)
#define P30        (1<<30)
#define P31        (1<<31)



/*------------------------------------------------------------------------------*/
/* UART0 Registers                                                              */
/*------------------------------------------------------------------------------*/
#define US0_CR         REG(UART0_BASE + 0x00)   /* Control Register             */
#define US0_MR         REG(UART0_BASE + 0x04)   /* Mode Register                */
#define US0_IER        REG(UART0_BASE + 0x08)   /* Interrupt Enable Register    */
#define US0_IDR        REG(UART0_BASE + 0x0C)   /* Interrupt Disable Register   */
#define US0_IMR        REG(UART0_BASE + 0x10)   /* Interrupt Mask Register      */
#define US0_CSR        REG(UART0_BASE + 0x14)   /* Channel Status Register      */
#define US0_RHR        REG(UART0_BASE + 0x18)   /* Receiver Holding Register    */
#define US0_THR        REG(UART0_BASE + 0x1C)   /* Transmitter Holding Register */
#define US0_BRGR       REG(UART0_BASE + 0x20)   /* Baud Rate Generator Register */
#define US0_RTOR       REG(UART0_BASE + 0x24)   /* Receiver Time-out Register   */
#define US0_TTGR       REG(UART0_BASE + 0x28)   /* Transmitter Time-guard Reg.  */
#define US0_RPR        REG(UART0_BASE + 0x30)   /* Receive Pointer Register     */
#define US0_RCR        REG(UART0_BASE + 0x34)   /* Receive Counter Register     */
#define US0_TPR        REG(UART0_BASE + 0x38)   /* Transmit Pointer Register    */
#define US0_TCR        REG(UART0_BASE + 0x3C)   /* Transmit Counter Register    */
#define US0_MC         REG(UART0_BASE + 0x40)   /* Modem Control Register       */
#define US0_MS         REG(UART0_BASE + 0x44)   /* Modem Status Register        */

/*------------------------------------------*/
/* US_CR: UART Control Register             */
/*------------------------------------------*/
#define US0_CR_RSTRX            (1<<2)          /* Reset Receiver               */
#define US0_CR_RSTTX            (1<<3)          /* Reset Transmitter            */
#define US0_CR_RXEN             (1<<4)          /* Receiver Enable              */
#define US0_CR_RXDIS            (1<<5)          /* Receiver Disable             */
#define US0_CR_TXEN             (1<<6)          /* Transmitter Enable           */
#define US0_CR_TXDIS            (1<<7)          /* Transmitter Disable          */
#define US0_CR_RSTSTA           (1<<8)          /* Reset Status Bits            */

/*------------------------------------------*/
/* US_MR: UART Control Register             */
/*------------------------------------------*/
#define US0_MR_USCLKS           (3<<4)          /* Clock Selection              */
#define US0_MR_CHRL             (3<<6)          /* Character Lengh              */
#define US0_MR_PAR              (7<<9)          /* Parity Type                  */
#define US0_MR_NBSTOP           (3<<12)         /* Number of Stop Bits          */
#define US0_MR_CHMODE           (3<<14)         /* Channel Mode                 */

/*------------------------------------------*/
/* US_IER: UART Control Register            */
/*------------------------------------------*/
#define US0_IER_RXRDY           (1<<0)          /* Enable RXRDY Interrupt       */
#define US0_IER_TXRDY           (1<<1)          /* Enable TXRDY Interrupt       */
#define US0_IER_ENDRX           (1<<3)          /* Enable End of Receive Transfer Interrupt  */
#define US0_IER_ENDTX           (1<<4)          /* Enable End of Transmit Transfer Interrupt */
#define US0_IER_OVRE            (1<<5)          /* Enable Overrun Error Interrupt            */
#define US0_IER_FRAME           (1<<6)          /* Enable Framing Error Interrupt            */
#define US0_IER_PARE            (1<<7)          /* Enable Parity Error Interrupt             */
#define US0_IER_TXEMPTY         (1<<9)          /* Enable TXEMPTY Interrupt     */
#define US0_IER_DMSI            (1<<10)         /* Delta Modem Interrupt        */

/*------------------------------------------*/
/* US_IDR: UART Control Register            */
/*------------------------------------------*/
#define US0_IDR_RXRDY           (1<<0)          /* Disable RXRDY Interrupt       */
#define US0_IDR_TXRDY           (1<<1)          /* Disable TXRDY Interrupt       */
#define US0_IDR_ENDRX           (1<<3)          /* Disable End of Receive Transfer Interrupt  */
#define US0_IDR_ENDTX           (1<<4)          /* Disable End of Transmit Transfer Interrupt */
#define US0_IDR_OVRE            (1<<5)          /* Disable Overrun Error Interrupt            */
#define US0_IDR_FRAME           (1<<6)          /* Disable Framing Error Interrupt            */
#define US0_IDR_PARE            (1<<7)          /* Disable Parity Error Interrupt             */
#define US0_IDR_TXEMPTY         (1<<9)          /* Disable TXEMPTY Interrupt     */
#define US0_IDR_DMSI            (1<<10)         /* Disable Delta Modem Interrupt */

/*------------------------------------------*/
/* US_IMR: UART Control Register            */
/*------------------------------------------*/
#define US0_IMR_RXRDY           (1<<0)          /* RXRDY Interrupt Mask          */
#define US0_IMR_TXRDY           (1<<2)          /* TXRDY Interrupt Mask          */
#define US0_IMR_ENDRX           (1<<3)          /* End of Receive Transfer Interrupt Mask */
#define US0_IMR_ENDTX           (1<<4)          /* End of Transmit Transfer Interrupt Mask*/
#define US0_IMR_OVRE            (1<<5)          /* Overrun Error Interrupt Mask  */
#define US0_IMR_FRAME           (1<<6)          /* Framing Error Interrupt Mask  */
#define US0_IMR_PARE            (1<<7)          /* Parity Error Interrupt Mask   */
#define US0_IMR_TXEMPTY         (1<<9)          /* TXEMPTY Interrupt Mask        */
#define US0_IMR_DMSI            (1<<10)         /* Delta Modem Interrupt Mask    */

/*------------------------------------------*/
/* US_CSR: UART Channel Status Register     */
/*------------------------------------------*/
#define US0_CSR_RXRDY           (1<<0)          /* Receiver Ready                */
#define US0_CSR_TXRDY           (1<<1)          /* Transmitter Ready             */
#define US0_CSR_ENDRX           (1<<3)          /* End of Receive Transfer       */
#define US0_CSR_ENDTX           (1<<4)          /* End of Transmit Transfer      */
#define US0_CSR_OVRE            (1<<5)          /* Overrun Error                 */
#define US0_CSR_FRAME           (1<<6)          /* Framing Error                 */
#define US0_CSR_PARE            (1<<7)          /* Parity Error                  */
#define US0_CSR_TXEMPTY         (1<<9)          /* Transmitter Empty             */
#define US0_CSR_DMSI            (1<<10)         /* Delta Modem Status Indication Interrupt */

/*------------------------------------------*/
/* US_RHR: UART Receiver Holding Register   */
/*------------------------------------------*/
#define US0_RHR_RXCHR           (255<<0)        /* Received Character            */

/*------------------------------------------*/
/* US_THR: UART Transmitter Holding Register*/
/*------------------------------------------*/
#define US0_THR_TXCHR           (255<<0)        /* Character to be Transmitted   */

/*-------------------------------------------*/
/* US_BRGR: UART Baud Rate Generator Register*/
/*-------------------------------------------*/
#define US0_BRGR_CD             (65535<<0)      /* Clock Divisor                 */

/*------------------------------------------*/
/* US_RCR: UART Receive Counter Register    */
/*------------------------------------------*/
#define US0_RCR_RXCTR           (65535<<0)      /* Receive Counter               */

/*------------------------------------------*/
/* US_TCR: UART Receive Counter Register    */
/*------------------------------------------*/
#define US0_TCR_TXCTR           (65535<<0)      /* Transmit Counter              */

/*------------------------------------------*/
/* US_MC: Modem Control Register            */
/*------------------------------------------*/
#define US0_MC_DTR              (1<<0)          /* Data Terminal Ready           */
#define US0_MC_RTS              (1<<1)          /* Request to Send               */

/*------------------------------------------*/
/* US_MS: Modem Status Register             */
/*------------------------------------------*/
#define US0_MS_DCTS             (1<<0)          /* Delta Clear to Send           */
#define US0_MS_DDSR             (1<<1)          /* Delta Data Set Ready          */
#define US0_MS_TERI             (1<<2)          /* Trailing Edge Ring Indicator  */
#define US0_MS_DDCD             (1<<3)          /* Delta Data Carrier Detect     */
#define US0_MS_CTS              (1<<4)          /* Clear to Send                 */
#define US0_MS_DSR              (1<<5)          /* Delta Set Ready               */
#define US0_MS_RI               (1<<6)          /* Ring Indicator                */
#define US0_MS_DCD              (1<<7)          /* Data Carrier Detect           */



/*------------------------------------------------------------------------------*/
/* UART1 Registers                                                              */
/*------------------------------------------------------------------------------*/
#define US1_CR         REG(UART1_BASE + 0x00)   /* Control Register             */
#define US1_MR         REG(UART1_BASE + 0x04)   /* Mode Register                */
#define US1_IER        REG(UART1_BASE + 0x08)   /* Interrupt Enable Register    */
#define US1_IDR        REG(UART1_BASE + 0x0C)   /* Interrupt Disable Register   */
#define US1_IMR        REG(UART1_BASE + 0x10)   /* Interrupt Mask Register      */
#define US1_CSR        REG(UART1_BASE + 0x14)   /* Channel Status Register      */
#define US1_RHR        REG(UART1_BASE + 0x18)   /* Receiver Holding Register    */
#define US1_THR        REG(UART1_BASE + 0x1C)   /* Transmitter Holding Register */
#define US1_BRGR       REG(UART1_BASE + 0x20)   /* Baud Rate Generator Register */
#define US1_RTOR       REG(UART1_BASE + 0x24)   /* Receiver Time-out Register   */
#define US1_TTGR       REG(UART1_BASE + 0x28)   /* Transmitter Time-guard Register */
#define US1_RPR        REG(UART1_BASE + 0x30)   /* Receive Pointer Register     */
#define US1_RCR        REG(UART1_BASE + 0x34)   /* Receive Counter Register     */
#define US1_TPR        REG(UART1_BASE + 0x38)   /* Transmit Pointer Register    */
#define US1_TCR        REG(UART1_BASE + 0x3C)   /* Transmit Counter Register    */
#define US1_MC         REG(UART1_BASE + 0x40)   /* Modem Control Register       */
#define US1_MS         REG(UART1_BASE + 0x44)   /* Modem Status Register        */

/*------------------------------------------*/
/* US_CR: UART Control Register             */
/*------------------------------------------*/
#define US1_CR_RSTRX            (1<<2)          /* Reset Receiver               */
#define US1_CR_RSTTX            (1<<3)          /* Reset Transmitter            */
#define US1_CR_RXEN             (1<<4)          /* Receiver Enable              */
#define US1_CR_RXDIS            (1<<5)          /* Receiver Disable             */
#define US1_CR_TXEN             (1<<6)          /* Transmitter Enable           */
#define US1_CR_TXDIS            (1<<7)          /* Transmitter Disable          */
#define US1_CR_RSTSTA           (1<<8)          /* Reset Status Bits            */

/*------------------------------------------*/
/* US_MR: UART Control Register             */
/*------------------------------------------*/
#define US1_MR_USCLKS           (3<<4)          /* Clock Selection              */
#define US1_MR_CHRL             (3<<6)          /* Character Lengh              */
#define US1_MR_PAR              (7<<9)          /* Parity Type                  */
#define US1_MR_NBSTOP           (3<<12)         /* Number of Stop Bits          */
#define US1_MR_CHMODE           (3<<14)         /* Channel Mode                 */

/*------------------------------------------*/
/* US_IER: UART Control Register            */
/*------------------------------------------*/
#define US1_IER_RXRDY           (1<<0)          /* Enable RXRDY Interrupt       */
#define US1_IER_TXRDY           (1<<1)          /* Enable TXRDY Interrupt       */
#define US1_IER_ENDRX           (1<<3)          /* Enable End of Receive Transfer Interrupt  */
#define US1_IER_ENDTX           (1<<4)          /* Enable End of Transmit Transfer Interrupt */
#define US1_IER_OVRE            (1<<5)          /* Enable Overrun Error Interrupt            */
#define US1_IER_FRAME           (1<<6)          /* Enable Framing Error Interrupt            */
#define US1_IER_PARE            (1<<7)          /* Enable Parity Error Interrupt             */
#define US1_IER_TXEMPTY         (1<<9)          /* Enable TXEMPTY Interrupt     */
#define US1_IER_DMSI            (1<<10)         /* Delta Modem Interrupt        */

/*------------------------------------------*/
/* US_IDR: UART Control Register            */
/*------------------------------------------*/
#define US1_IDR_RXRDY           (1<<0)          /* Disable RXRDY Interrupt       */
#define US1_IDR_TXRDY           (1<<1)          /* Disable TXRDY Interrupt       */
#define US1_IDR_ENDRX           (1<<3)          /* Disable End of Receive Transfer Interrupt  */
#define US1_IDR_ENDTX           (1<<4)          /* Disable End of Transmit Transfer Interrupt */
#define US1_IDR_OVRE            (1<<5)          /* Disable Overrun Error Interrupt            */
#define US1_IDR_FRAME           (1<<6)          /* Disable Framing Error Interrupt            */
#define US1_IDR_PARE            (1<<7)          /* Disable Parity Error Interrupt             */
#define US1_IDR_TXEMPTY         (1<<9)          /* Disable TXEMPTY Interrupt     */
#define US1_IDR_DMSI            (1<<10)         /* Disable Delta Modem Interrupt */

/*------------------------------------------*/
/* US_IMR: UART Control Register            */
/*------------------------------------------*/
#define US1_IMR_RXRDY           (1<<0)          /* RXRDY Interrupt Mask          */
#define US1_IMR_TXRDY           (1<<2)          /* TXRDY Interrupt Mask          */
#define US1_IMR_ENDRX           (1<<3)          /* End of Receive Transfer Interrupt Mask */
#define US1_IMR_ENDTX           (1<<4)          /* End of Transmit Transfer Interrupt Mask*/
#define US1_IMR_OVRE            (1<<5)          /* Overrun Error Interrupt Mask  */
#define US1_IMR_FRAME           (1<<6)          /* Framing Error Interrupt Mask  */
#define US1_IMR_PARE            (1<<7)          /* Parity Error Interrupt Mask   */
#define US1_IMR_TXEMPTY         (1<<9)          /* TXEMPTY Interrupt Mask        */
#define US1_IMR_DMSI            (1<<10)         /* Delta Modem Interrupt Mask    */

/*------------------------------------------*/
/* US_CSR: UART Channel Status Register     */
/*------------------------------------------*/
#define US1_CSR_RXRDY           (1<<0)          /* Receiver Ready                */
#define US1_CSR_TXRDY           (1<<1)          /* Transmitter Ready             */
#define US1_CSR_ENDRX           (1<<3)          /* End of Receive Transfer       */
#define US1_CSR_ENDTX           (1<<4)          /* End of Transmit Transfer      */
#define US1_CSR_OVRE            (1<<5)          /* Overrun Error                 */
#define US1_CSR_FRAME           (1<<6)          /* Framing Error                 */
#define US1_CSR_PARE            (1<<7)          /* Parity Error                  */
#define US1_CSR_TXEMPTY         (1<<9)          /* Transmitter Empty             */
#define US1_CSR_DMSI            (1<<10)         /* Delta Modem Status Indication Interrupt */

/*------------------------------------------*/
/* US_RHR: UART Receiver Holding Register   */
/*------------------------------------------*/
#define US1_RHR_RXCHR           (255<<0)        /* Received Character            */

/*------------------------------------------*/
/* US_THR: UART Transmitter Holding Register*/
/*------------------------------------------*/
#define US1_THR_TXCHR           (255<<0)        /* Character to be Transmitted   */

/*-------------------------------------------*/
/* US_BRGR: UART Baud Rate Generator Register*/
/*-------------------------------------------*/
#define US1_BRGR_CD             (65535<<0)      /* Clock Divisor                 */

/*------------------------------------------*/
/* US_RCR: UART Receive Counter Register    */
/*------------------------------------------*/
#define US1_RCR_RXCTR           (65535<<0)      /* Receive Counter               */

/*------------------------------------------*/
/* US_TCR: UART Receive Counter Register    */
/*------------------------------------------*/
#define US1_TCR_TXCTR           (65535<<0)      /* Transmit Counter              */

/*------------------------------------------*/
/* US_MC: Modem Control Register            */
/*------------------------------------------*/
#define US1_MC_DTR              (1<<0)          /* Data Terminal Ready           */
#define US1_MC_RTS              (1<<1)          /* Request to Send               */

/*------------------------------------------*/
/* US_MS: Modem Status Register             */
/*------------------------------------------*/
#define US1_MS_DCTS             (1<<0)          /* Delta Clear to Send           */
#define US1_MS_DDSR             (1<<1)          /* Delta Data Set Ready          */
#define US1_MS_TERI             (1<<2)          /* Trailing Edge Ring Indicator  */
#define US1_MS_DDCD             (1<<3)          /* Delta Data Carrier Detect     */
#define US1_MS_CTS              (1<<4)          /* Clear to Send                 */
#define US1_MS_DSR              (1<<5)          /* Delta Set Ready               */
#define US1_MS_RI               (1<<6)          /* Ring Indicator                */
#define US1_MS_DCD              (1<<7)          /* Data Carrier Detect           */



/*-------------------------------------------------------*/
/* SPI Registers                                         */
/*-------------------------------------------------------*/
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



/*-----------------------------------------------------------------------------------*/
/* AIC Registers                                                                     */
/*-----------------------------------------------------------------------------------*/
#define AIC_SMR0      REG(AIC_BASE + 0x000)    /* Source Mode Register 0             */
#define AIC_SMR1      REG(AIC_BASE + 0x004)    /* Source Mode Register 1             */
#define AIC_SMR31     REG(AIC_BASE + 0x07C)    /* Source Mode Register 31            */
#define AIC_SVR0      REG(AIC_BASE + 0x080)    /* Source Vector Register 0           */
#define AIC_SVR1      REG(AIC_BASE + 0x084)    /* Source Vector Register 1           */
#define AIC_SVR31     REG(AIC_BASE + 0xFC0)    /* Source Vector Register 31          */
#define AIC_IVR       REG(AIC_BASE + 0x100)    /* IRQ Vector Register                */
#define AIC_FVR       REG(AIC_BASE + 0x104)    /* FIQ Vector Register                */
#define AIC_ISR       REG(AIC_BASE + 0x108)    /* Interrupt Status Register          */
#define AIC_IPR       REG(AIC_BASE + 0x10C)    /* Interrupt Pending Register         */
#define AIC_IMR       REG(AIC_BASE + 0x110)    /* Interrupt Mask Register            */
#define AIC_CISR      REG(AIC_BASE + 0x114)    /* Core Interrupt Status Register     */
#define AIC_IECR      REG(AIC_BASE + 0x120)    /* Interrupt Enable Command Register  */
#define AIC_IDCR      REG(AIC_BASE + 0x124)    /* Interrupt Disable Command Register */
#define AIC_ICCR      REG(AIC_BASE + 0x128)    /* Interrupt Clear Command Register   */
#define AIC_ISCR      REG(AIC_BASE + 0x12C)    /* Interrupt Set Command Register     */
#define AIC_EOICR     REG(AIC_BASE + 0x130)    /* End-of-interrupt Command Register  */
#define AIC_SPU       REG(AIC_BASE + 0x134)    /* Spurious Interrupt Vector Register */
				   
/*-------------------------------------*/
/* AIC_SMR0: AIC Source Mode Register  */
/*-------------------------------------*/
#define AIC_SMR0_PRIOR     (7<<0)              /* Priority Level                     */
#define AIC_SMR0_SRCTYPE   (3<<0)              /* Interrupt Source Type              */

/*-------------------------------------*/
/* AIC_SMR1: AIC Source Mode Register  */
/*-------------------------------------*/
#define AIC_SMR1_PRIOR     (7<<0)              /* Priority Level                     */
#define AIC_SMR1_SRCTYPE   (3<<0)              /* Interrupt Source Type              */

/*-------------------------------------*/
/* AIC_SMR31: AIC Source Mode Register */
/*-------------------------------------*/
#define AIC_SMR31_PRIOR    (7<<0)              /* Priority Level                     */
#define AIC_SMR31_SRCTYPE  (3<<0)              /* Interrupt Source Type              */

/*----------------------------------------*/
/* AIC_ISR: AIC Interrupt Status Register */
/*----------------------------------------*/
#define AIC_ISR_IRQID      (31<<0)              /* Returns the current interrupt source register */

/*-----------------------------------------*/
/* AIC_IPR: AIC Interrupt Pending Register */
/*-----------------------------------------*/
#define AIC_IPR_IRQID      (31<<0)              /* Returns the current interrupt source register */


/*----------------------------------------------*/
/* AIC_CISR: AIC Core Interrupt Status Register */
/*----------------------------------------------*/
#define AIC_CISR_nFIQ      (1<<0)               /* nFIQ Status                       */
#define AIC_CISR_NIRQ      (1<<1)               /* nIRQ Status                       */



/*------------------------------------------------------------------------------------------*/
/* MAC0 Registers                                                                           */
/*------------------------------------------------------------------------------------------*/
#define MAC0_ETH_CTL      REG(MAC0_BASE + 0x00)    /* Network Control Register              */
#define MAC0_ETH_CFG      REG(MAC0_BASE + 0x04)    /* Network Configuration Register        */
#define MAC0_ETH_SR       REG(MAC0_BASE + 0x08)    /* Network Status Register               */
#define MAC0_ETH_TAR      REG(MAC0_BASE + 0x0C)    /* Transmit Address Register             */
#define MAC0_ETH_TCR      REG(MAC0_BASE + 0x10)    /* Transmit Control Register             */
#define MAC0_ETH_TSR      REG(MAC0_BASE + 0x14)    /* Transmit Status Register              */
#define MAC0_ETH_RBQP     REG(MAC0_BASE + 0x18)    /* Receive Buffer Queue Pointer          */
#define MAC0_ETH_RSR      REG(MAC0_BASE + 0x20)    /* Receive Status Register               */
#define MAC0_ETH_ISR      REG(MAC0_BASE + 0x24)    /* Interrupt Status Register             */ 
#define MAC0_ETH_IER      REG(MAC0_BASE + 0x28)    /* Interrupt Enable Register             */
#define MAC0_ETH_IDR      REG(MAC0_BASE + 0x2C)    /* Interrupt Disable Register            */
#define MAC0_ETH_IMR      REG(MAC0_BASE + 0x30)    /* Interrupt Mask Register               */
#define MAC0_ETH_MAN      REG(MAC0_BASE + 0x34)    /* PHY Maintenance Register              */
#define MAC0_ETH_FRA      REG(MAC0_BASE + 0x40)    /* Frames Transmitted OK Register        */
#define MAC0_ETH_SCOL     REG(MAC0_BASE + 0x44)    /* Single Collision Frame Register       */
#define MAC0_ETH_MCOL     REG(MAC0_BASE + 0x48)    /* Multiple Collision Frame Register     */
#define MAC0_ETH_OK       REG(MAC0_BASE + 0x4C)    /* Frames Received OK Register           */
#define MAC0_ETH_SEQE     REG(MAC0_BASE + 0x50)    /* Frame Check Sequence Error Register   */
#define MAC0_ETH_ALE      REG(MAC0_BASE + 0x54)    /* Alignment Error Register              */
#define MAC0_ETH_DTE      REG(MAC0_BASE + 0x58)    /* Deferred Transmission Frame Register  */
#define MAC0_ETH_LCOL     REG(MAC0_BASE + 0x5C)    /* Late Collision Register               */
#define MAC0_ETH_ECOL     REG(MAC0_BASE + 0x60)    /* Excessive Collision Register          */
#define MAC0_ETH_CSE      REG(MAC0_BASE + 0x64)    /* Carrier Sense Error Register          */
#define MAC0_ETH_TUE      REG(MAC0_BASE + 0x68)    /* Transmit Underrun Error Register      */
#define MAC0_ETH_CDE      REG(MAC0_BASE + 0x6C)    /* Code Error Register                   */
#define MAC0_ETH_ELR      REG(MAC0_BASE + 0x70)    /* Excessive Lengh Error Register        */
#define MAC0_ETH_RJB      REG(MAC0_BASE + 0x74)    /* Receive Jabber Register               */
#define MAC0_ETH_USF      REG(MAC0_BASE + 0x78)    /* Undersize Frame Register              */
#define MAC0_ETH_SQEE     REG(MAC0_BASE + 0x7C)    /* SQE Test Error Register               */
#define MAC0_ETH_DRFC     REG(MAC0_BASE + 0x80)    /* Discarded RX Frame Register           */
#define MAC0_ETH_HSH      REG(MAC0_BASE + 0x90)    /* Hash Address High [63:32]             */
#define MAC0_ETH_HSL      REG(MAC0_BASE + 0x94)    /* Hash Address Low [31:0]               */
#define MAC0_ETH_SA1L     REG(MAC0_BASE + 0x98)    /* Specific Address 1 Low, First 4 Bytes */
#define MAC0_ETH_SA1H     REG(MAC0_BASE + 0x9C)    /* Specific Address 1 High, Last 2 Bytes */
#define MAC0_ETH_SA2L     REG(MAC0_BASE + 0xA0)    /* Specific Address 2 Low, First 4 Bytes */
#define MAC0_ETH_SA2H     REG(MAC0_BASE + 0xA4)    /* Specific Address 2 High, Last 2 Bytes */	
#define MAC0_ETH_SA3L     REG(MAC0_BASE + 0xA8)    /* Specific Address 3 Low, First 4 Bytes */
#define MAC0_ETH_SA3H     REG(MAC0_BASE + 0xAC)    /* Specific Address 3 High, Last 2 Bytes */
#define MAC0_ETH_SA4L     REG(MAC0_BASE + 0xB0)    /* Specific Address 4 Low, First 4 Bytes */
#define MAC0_ETH_SA4H     REG(MAC0_BASE + 0xB4)    /* Specific Address 4 High, Last 2 Bytes */
							   
/*-------------------------------------*/
/* MAC0_ETH_CTL: EMAC Control Register */
/*-------------------------------------*/
#define MAC0_ETH_CTL_LB     (1<<0)                 /* Loopback                              */
#define MAC0_ETH_CTL_LBL    (1<<1)                 /* Loopback Local                        */
#define MAC0_ETH_CTL_RE     (1<<2)                 /* Receive Enable                        */
#define MAC0_ETH_CTL_TE     (1<<3)                 /* Transmit Enable                       */
#define MAC0_ETH_CTL_MPE    (1<<4)                 /* Management Port Enable                */
#define MAC0_ETH_CTL_CSR    (1<<5)                 /* Clear Statistics Registers            */
#define MAC0_ETH_CTL_ISR    (1<<6)                 /* Increment Statistics Registers        */
#define MAC0_ETH_CTL_WES    (1<<7)                 /* Write Enable for Statistics Registers */
#define MAC0_ETH_CTL_BP     (1<<8)                 /* Back Pressure                         */

/*-------------------------------------*/
/* MAC0_ETH_CFG: EMAC Mode Register    */
/*-------------------------------------*/
#define MAC0_ETH_CFG_SPD    (1<<0)                 /* Speed                                 */
#define MAC0_ETH_CFG_FD     (1<<1)                 /* Full Duplex                           */
#define MAC0_ETH_CFG_BR     (1<<2)                 /* Bit Rate                              */
#define MAC0_ETH_CFG_CAF    (1<<4)                 /* Copy All Frames                       */
#define MAC0_ETH_CFG_NBC    (1<<5)                 /* No Broadcast                          */
#define MAC0_ETH_CFG_MTI    (1<<6)                 /* Multicast Hash Enable                 */
#define MAC0_ETH_CFG_UNI    (1<<7)                 /* Unicast Hash Enable                   */
#define MAC0_ETH_CFG_BIG    (1<<8)                 /* Receive 1522 Bytes                    */
#define MAC0_ETH_CFG_EAE    (1<<9)                 /* External Address Match Enable         */
#define MAC0_ETH_CFG_CLK    (3<<10)                /* Clock                                 */
#define MAC0_ETH_CFG_RTY    (1<<12)                /* Retry Test                            */

/*-------------------------------------*/
/* MAC0_ETH_SR: EMAC Status Register   */
/*-------------------------------------*/
#define MAC0_ETH_SR_LINK    (1<<0)                 
#define MAC0_ETH_SR_MDIO    (1<<1)                 
#define MAC0_ETH_SR_IDLE    (1<<2)                 

/*-----------------------------------------*/
/* MAC0_ETH_TCR: Transmit Control Register */
/*-----------------------------------------*/
#define MAC0_ETH_TCR_LEN    (0xFFF<<0)             /* Transmit Frame Lengh                  */
#define MAC0_ETH_TCR_NCRC   (1<<15)                /* No CRC                                */

/*---------------------------------------------*/
/* MAC0_ETH_TSR: EMAC Transmit Status Register */
/*---------------------------------------------*/
#define MAC0_ETH_TSR_OVR    (1<<0)                 /* Ethernet Transmit Buffer Underrun     */
#define MAC0_ETH_TSR_COL    (1<<1)                 /* Collision Occured                     */
#define MAC0_ETH_TSR_RLE    (1<<2)                 /* Retry Limit Exceeded                  */
#define MAC0_ETH_TSR_IDLE   (1<<3)                 /* Transmitter Idle                      */
#define MAC0_ETH_TSR_BNQ    (1<<4)                 /* Ethernet Transmit Buffer not Queued   */
#define MAC0_ETH_TSR_COMP   (1<<5)                 /* Transmit Complete                     */
#define MAC0_ETH_TSR_UND    (1<<6)                 /* Transmit Underrun                     */

/*---------------------------------------------*/
/* MAC0_ETH_RSR: EMAC Receive Status Register  */
/*---------------------------------------------*/
#define MAC0_ETH_RSR_BNA    (1<<0)                 /* Buffer Not Available                  */
#define MAC0_ETH_RSR_REC    (1<<1)                 /* Frame Received                        */
#define MAC0_ETH_RSR_OVR    (1<<2)                 /* RX Overrun                            */

/*----------------------------------------------*/
/* MAC0_ETH_ISR: EMAC Interrupt Status Register */
/*----------------------------------------------*/
#define MAC0_ETH_ISR_DONE   (1<<0)                 /* Management Done                       */
#define MAC0_ETH_ISR_RCOM   (1<<1)                 /* Receive Complete                      */
#define MAC0_ETH_ISR_RBNA   (1<<2)                 /* Receive Buffer Not Available          */
#define MAC0_ETH_ISR_TOVR   (1<<3)                 /* Transmit Buffer Overrun               */
#define MAC0_ETH_ISR_TUND   (1<<4)                 /* Transmit Buffer Underrun              */
#define MAC0_ETH_ISR_RTRY   (1<<5)                 /* Retry Limit                           */
#define MAC0_ETH_ISR_TBRE   (1<<6)                 /* Transmit Buffer Register Empty        */
#define MAC0_ETH_ISR_TCOM   (1<<7)                 /* Transmit Complete                     */
#define MAC0_ETH_ISR_TIDLE  (1<<8)                 /* Transmit Idle                         */
#define MAC0_ETH_ISR_LINK   (1<<9)                 /* Set when LINK pin changes value       */
#define MAC0_ETH_ISR_ROVR   (1<<10)                /* RX Overrun                            */
#define MAC0_ETH_ISR_ABT    (1<<11)                /* Abort                                 */

/*----------------------------------------------*/
/* MAC0_ETH_IER: EMAC Interrupt Enable Register */
/*----------------------------------------------*/
#define MAC0_ETH_IER_DONE   (1<<0)                 /* Management Done Interrupt Enable      */
#define MAC0_ETH_IER_RCOM   (1<<1)                 /* Receive Complete Interrupt Enable     */
#define MAC0_ETH_IER_RBNA   (1<<2)                 /* Receive Buffer Not Available Interrupt Enable   */
#define MAC0_ETH_IER_TOVR   (1<<3)                 /* Transmit Buffer Overrun Interrupt Enable        */
#define MAC0_ETH_IER_TUND   (1<<4)                 /* Transmit Buffer Underrun Interrupt Enable       */
#define MAC0_ETH_IER_RTRY   (1<<5)                 /* Retry Limit Interrupt Enable                    */
#define MAC0_ETH_IER_TBRE   (1<<6)                 /* Transmit Buffer Register Empty Interrupt Enable */
#define MAC0_ETH_IER_TCOM   (1<<7)                 /* Transmit Complete Interrupt Enable    */
#define MAC0_ETH_IER_TIDLE  (1<<8)                 /* Transmit Idle Interrupt Enable        */
#define MAC0_ETH_IER_LINK   (1<<9)                 /* LINK Interrupt Enable                 */
#define MAC0_ETH_IER_ROVR   (1<<10)                /* RX Overrun Interrupt Enable           */
#define MAC0_ETH_IER_ABT    (1<<11)                /* Abort Interrupt Enable                */

/*-----------------------------------------------*/
/* MAC0_ETH_IDR: EMAC Interrupt Disable Register */
/*-----------------------------------------------*/
#define MAC0_ETH_IDR_DONE   (1<<0)                 /* Management Done Interrupt Disable     */
#define MAC0_ETH_IDR_RCOM   (1<<1)                 /* Receive Complete Interrupt Disable    */
#define MAC0_ETH_IDR_RBNA   (1<<2)                 /* Receive Buffer Not Available Interrupt Disable   */
#define MAC0_ETH_IDR_TOVR   (1<<3)                 /* Transmit Buffer Overrun Interrupt Disable        */
#define MAC0_ETH_IDR_TUND   (1<<4)                 /* Transmit Buffer Underrun Interrupt Disable       */
#define MAC0_ETH_IDR_RTRY   (1<<5)                 /* Retry Limit Interrupt Disable                    */
#define MAC0_ETH_IDR_TBRE   (1<<6)                 /* Transmit Buffer Register Empty Interrupt Disable */
#define MAC0_ETH_IDR_TCOM   (1<<7)                 /* Transmit Complete Interrupt Disable   */
#define MAC0_ETH_IDR_TIDLE  (1<<8)                 /* Transmit Idle Interrupt Disable       */
#define MAC0_ETH_IDR_LINK   (1<<9)                 /* LINK Interrupt Disable                */
#define MAC0_ETH_IDR_ROVR   (1<<10)                /* RX Overrun Interrupt Disable          */
#define MAC0_ETH_IDR_ABT    (1<<11)                /* Abort Interrupt Disable               */

/*-----------------------------------------------*/
/* MAC0_ETH_IMR: EMAC Interrupt Mask Register    */
/*-----------------------------------------------*/
#define MAC0_ETH_IMR_DONE   (1<<0)                 /* Management Done Interrupt Mask        */
#define MAC0_ETH_IMR_RCOM   (1<<1)                 /* Receive Complete Interrupt Mask       */
#define MAC0_ETH_IMR_RBNA   (1<<2)                 /* Receive Buffer Not Available Interrupt Mask   */
#define MAC0_ETH_IMR_TOVR   (1<<3)                 /* Transmit Buffer Overrun Interrupt Mask        */
#define MAC0_ETH_IMR_TUND   (1<<4)                 /* Transmit Buffer Underrun Interrupt Mask       */
#define MAC0_ETH_IMR_RTRY   (1<<5)                 /* Retry Limit Interrupt Mask                    */
#define MAC0_ETH_IMR_TBRE   (1<<6)                 /* Transmit Buffer Register Empty Interrupt Mask */
#define MAC0_ETH_IMR_TCOM   (1<<7)                 /* Transmit Complete Interrupt Mask      */
#define MAC0_ETH_IMR_TIDLE  (1<<8)                 /* Transmit Idle Interrupt Mask          */
#define MAC0_ETH_IMR_LINK   (1<<9)                 /* LINK Interrupt Mask                   */
#define MAC0_ETH_IMR_ROVR   (1<<10)                /* RX Overrun Interrupt Mask             */
#define MAC0_ETH_IMR_ABT    (1<<11)                /* Abort Interrupt Mask                  */

/*-----------------------------------------------*/
/* MAC0_ETH_MAN: EMAC PHY Maintenance Register   */
/*-----------------------------------------------*/
#define MAC0_ETH_MAN_DATA   (0xFFFF<<0)                 
#define MAC0_ETH_MAN_CODE   (3<<16)                 
#define MAC0_ETH_MAN_REGA   (0x1F<<18)                 
#define MAC0_ETH_MAN_PHYA   (0x1F<<23)              
#define MAC0_ETH_MAN_RW     (3<<28)             
#define MAC0_ETH_MAN_HIGH   (1<<30)              
#define MAC0_ETH_MAN_LOW    (1<<31)                 

/*----------------------------------------------------*/
/* MAC0_ETH_SA1H: EMAC Specific Address High Register */
/*----------------------------------------------------*/
#define MAC0_ETH_SA1H_ADDR   (0xFFFF<<0)            /* Unicast Addresses, Bits [47:32]       */           

/*----------------------------------------------------*/
/* MAC0_ETH_SA2H: EMAC Specific Address High Register */
/*----------------------------------------------------*/
#define MAC0_ETH_SA2H_ADDR   (0xFFFF<<0)            /* Unicast Addresses, Bits [47:32]       */

/*----------------------------------------------------*/
/* MAC0_ETH_SA3H: EMAC Specific Address High Register */
/*----------------------------------------------------*/
#define MAC0_ETH_SA3H_ADDR   (0xFFFF<<0)            /* Unicast Addresses, Bits [47:32]       */

/*----------------------------------------------------*/
/* MAC0_ETH_SA4H: EMAC Specific Address High Register */
/*----------------------------------------------------*/
#define MAC0_ETH_SA4H_ADDR   (0xFFFF<<0)            /* Unicast Addresses, Bits [47:32]       */



/*------------------------------------------------------------------------------------------*/
/* MAC1 Registers                                                                           */
/*------------------------------------------------------------------------------------------*/
#define MAC1_ETH_CTL      REG(MAC1_BASE + 0x00)    /* Network Control Register              */
#define MAC1_ETH_CFG      REG(MAC1_BASE + 0x04)    /* Network Configuration Register        */
#define MAC1_ETH_SR       REG(MAC1_BASE + 0x08)    /* Network Status Register               */
#define MAC1_ETH_TAR      REG(MAC1_BASE + 0x0C)    /* Transmit Address Register             */
#define MAC1_ETH_TCR      REG(MAC1_BASE + 0x10)    /* Transmit Control Register             */
#define MAC1_ETH_TSR      REG(MAC1_BASE + 0x14)    /* Transmit Status Register              */
#define MAC1_ETH_RBQP     REG(MAC1_BASE + 0x18)    /* Receive Buffer Queue Pointer          */
#define MAC1_ETH_RSR      REG(MAC1_BASE + 0x20)    /* Receive Status Register               */
#define MAC1_ETH_ISR      REG(MAC1_BASE + 0x24)    /* Interrupt Status Register             */ 
#define MAC1_ETH_IER      REG(MAC1_BASE + 0x28)    /* Interrupt Enable Register             */
#define MAC1_ETH_IDR      REG(MAC1_BASE + 0x2C)    /* Interrupt Disable Register            */
#define MAC1_ETH_IMR      REG(MAC1_BASE + 0x30)    /* Interrupt Mask Register               */
#define MAC1_ETH_MAN      REG(MAC1_BASE + 0x34)    /* PHY Maintenance Register              */
#define MAC1_ETH_FRA      REG(MAC1_BASE + 0x40)    /* Frames Transmitted OK Register        */
#define MAC1_ETH_SCOL     REG(MAC1_BASE + 0x44)    /* Single Collision Frame Register       */
#define MAC1_ETH_MCOL     REG(MAC1_BASE + 0x48)    /* Multiple Collision Frame Register     */
#define MAC1_ETH_OK       REG(MAC1_BASE + 0x4C)    /* Frames Received OK Register           */
#define MAC1_ETH_SEQE     REG(MAC1_BASE + 0x50)    /* Frame Check Sequence Error Register   */
#define MAC1_ETH_ALE      REG(MAC1_BASE + 0x54)    /* Alignment Error Register              */
#define MAC1_ETH_DTE      REG(MAC1_BASE + 0x58)    /* Deferred Transmission Frame Register  */
#define MAC1_ETH_LCOL     REG(MAC1_BASE + 0x5C)    /* Late Collision Register               */
#define MAC1_ETH_ECOL     REG(MAC1_BASE + 0x60)    /* Excessive Collision Register          */
#define MAC1_ETH_CSE      REG(MAC1_BASE + 0x64)    /* Carrier Sense Error Register          */
#define MAC1_ETH_TUE      REG(MAC1_BASE + 0x68)    /* Transmit Underrun Error Register      */
#define MAC1_ETH_CDE      REG(MAC1_BASE + 0x6C)    /* Code Error Register                   */
#define MAC1_ETH_ELR      REG(MAC1_BASE + 0x70)    /* Excessive Lengh Error Register        */
#define MAC1_ETH_RJB      REG(MAC1_BASE + 0x74)    /* Receive Jabber Register               */
#define MAC1_ETH_USF      REG(MAC1_BASE + 0x78)    /* Undersize Frame Register              */
#define MAC1_ETH_SQEE     REG(MAC1_BASE + 0x7C)    /* SQE Test Error Register               */
#define MAC1_ETH_DRFC     REG(MAC1_BASE + 0x80)    /* Discarded RX Frame Register           */
#define MAC1_ETH_HSH      REG(MAC1_BASE + 0x90)    /* Hash Address High [63:32]             */
#define MAC1_ETH_HSL      REG(MAC1_BASE + 0x94)    /* Hash Address Low [31:0]               */
#define MAC1_ETH_SA1L     REG(MAC1_BASE + 0x98)    /* Specific Address 1 Low, First 4 Bytes */
#define MAC1_ETH_SA1H     REG(MAC1_BASE + 0x9C)    /* Specific Address 1 High, Last 2 Bytes */
#define MAC1_ETH_SA2L     REG(MAC1_BASE + 0xA0)    /* Specific Address 2 Low, First 4 Bytes */
#define MAC1_ETH_SA2H     REG(MAC1_BASE + 0xA4)    /* Specific Address 2 High, Last 2 Bytes */	
#define MAC1_ETH_SA3L     REG(MAC1_BASE + 0xA8)    /* Specific Address 3 Low, First 4 Bytes */
#define MAC1_ETH_SA3H     REG(MAC1_BASE + 0xAC)    /* Specific Address 3 High, Last 2 Bytes */
#define MAC1_ETH_SA4L     REG(MAC1_BASE + 0xB0)    /* Specific Address 4 Low, First 4 Bytes */
#define MAC1_ETH_SA4H     REG(MAC1_BASE + 0xB4)    /* Specific Address 4 High, Last 2 Bytes */
							   
/*-------------------------------------*/
/* MAC1_ETH_CTL: EMAC Control Register */
/*-------------------------------------*/
#define MAC1_ETH_CTL_LB     (1<<0)                 /* Loopback                              */
#define MAC1_ETH_CTL_LBL    (1<<1)                 /* Loopback Local                        */
#define MAC1_ETH_CTL_RE     (1<<2)                 /* Receive Enable                        */
#define MAC1_ETH_CTL_TE     (1<<3)                 /* Transmit Enable                       */
#define MAC1_ETH_CTL_MPE    (1<<4)                 /* Management Port Enable                */
#define MAC1_ETH_CTL_CSR    (1<<5)                 /* Clear Statistics Registers            */
#define MAC1_ETH_CTL_ISR    (1<<6)                 /* Increment Statistics Registers        */
#define MAC1_ETH_CTL_WES    (1<<7)                 /* Write Enable for Statistics Registers */
#define MAC1_ETH_CTL_BP     (1<<8)                 /* Back Pressure                         */

/*-------------------------------------*/
/* MAC1_ETH_CFG: EMAC Mode Register    */
/*-------------------------------------*/
#define MAC1_ETH_CFG_SPD    (1<<0)                 /* Speed                                 */
#define MAC1_ETH_CFG_FD     (1<<1)                 /* Full Duplex                           */
#define MAC1_ETH_CFG_BR     (1<<2)                 /* Bit Rate                              */
#define MAC1_ETH_CFG_CAF    (1<<4)                 /* Copy All Frames                       */
#define MAC1_ETH_CFG_NBC    (1<<5)                 /* No Broadcast                          */
#define MAC1_ETH_CFG_MTI    (1<<6)                 /* Multicast Hash Enable                 */
#define MAC1_ETH_CFG_UNI    (1<<7)                 /* Unicast Hash Enable                   */
#define MAC1_ETH_CFG_BIG    (1<<8)                 /* Receive 1522 Bytes                    */
#define MAC1_ETH_CFG_EAE    (1<<9)                 /* External Address Match Enable         */
#define MAC1_ETH_CFG_CLK    (3<<10)                /* Clock                                 */
#define MAC1_ETH_CFG_RTY    (1<<12)                /* Retry Test                            */

/*-------------------------------------*/
/* MAC1_ETH_SR: EMAC Status Register   */
/*-------------------------------------*/
#define MAC1_ETH_SR_LINK    (1<<0)                 
#define MAC1_ETH_SR_MDIO    (1<<1)                 
#define MAC1_ETH_SR_IDLE    (1<<2)                 

/*-----------------------------------------*/
/* MAC1_ETH_TCR: Transmit Control Register */
/*-----------------------------------------*/
#define MAC1_ETH_TCR_LEN    (0xFFF<<0)             /* Transmit Frame Lengh                  */
#define MAC1_ETH_TCR_NCRC   (1<<15)                /* No CRC                                */

/*---------------------------------------------*/
/* MAC1_ETH_TSR: EMAC Transmit Status Register */
/*---------------------------------------------*/
#define MAC1_ETH_TSR_OVR    (1<<0)                 /* Ethernet Transmit Buffer Underrun     */
#define MAC1_ETH_TSR_COL    (1<<1)                 /* Collision Occured                     */
#define MAC1_ETH_TSR_RLE    (1<<2)                 /* Retry Limit Exceeded                  */
#define MAC1_ETH_TSR_IDLE   (1<<3)                 /* Transmitter Idle                      */
#define MAC1_ETH_TSR_BNQ    (1<<4)                 /* Ethernet Transmit Buffer not Queued   */
#define MAC1_ETH_TSR_COMP   (1<<5)                 /* Transmit Complete                     */
#define MAC1_ETH_TSR_UND    (1<<6)                 /* Transmit Underrun                     */

/*---------------------------------------------*/
/* MAC1_ETH_RSR: EMAC Receive Status Register  */
/*---------------------------------------------*/
#define MAC1_ETH_RSR_BNA    (1<<0)                 /* Buffer Not Available                  */
#define MAC1_ETH_RSR_REC    (1<<1)                 /* Frame Received                        */
#define MAC1_ETH_RSR_OVR    (1<<2)                 /* RX Overrun                            */

/*----------------------------------------------*/
/* MAC1_ETH_ISR: EMAC Interrupt Status Register */
/*----------------------------------------------*/
#define MAC1_ETH_ISR_DONE   (1<<0)                 /* Management Done                       */
#define MAC1_ETH_ISR_RCOM   (1<<1)                 /* Receive Complete                      */
#define MAC1_ETH_ISR_RBNA   (1<<2)                 /* Receive Buffer Not Available          */
#define MAC1_ETH_ISR_TOVR   (1<<3)                 /* Transmit Buffer Overrun               */
#define MAC1_ETH_ISR_TUND   (1<<4)                 /* Transmit Buffer Underrun              */
#define MAC1_ETH_ISR_RTRY   (1<<5)                 /* Retry Limit                           */
#define MAC1_ETH_ISR_TBRE   (1<<6)                 /* Transmit Buffer Register Empty        */
#define MAC1_ETH_ISR_TCOM   (1<<7)                 /* Transmit Complete                     */
#define MAC1_ETH_ISR_TIDLE  (1<<8)                 /* Transmit Idle                         */
#define MAC1_ETH_ISR_LINK   (1<<9)                 /* Set when LINK pin changes value       */
#define MAC1_ETH_ISR_ROVR   (1<<10)                /* RX Overrun                            */
#define MAC1_ETH_ISR_ABT    (1<<11)                /* Abort                                 */

/*----------------------------------------------*/
/* MAC1_ETH_IER: EMAC Interrupt Enable Register */
/*----------------------------------------------*/
#define MAC1_ETH_IER_DONE   (1<<0)                 /* Management Done Interrupt Enable      */
#define MAC1_ETH_IER_RCOM   (1<<1)                 /* Receive Complete Interrupt Enable     */
#define MAC1_ETH_IER_RBNA   (1<<2)                 /* Receive Buffer Not Available Interrupt Enable   */
#define MAC1_ETH_IER_TOVR   (1<<3)                 /* Transmit Buffer Overrun Interrupt Enable        */
#define MAC1_ETH_IER_TUND   (1<<4)                 /* Transmit Buffer Underrun Interrupt Enable       */
#define MAC1_ETH_IER_RTRY   (1<<5)                 /* Retry Limit Interrupt Enable                    */
#define MAC1_ETH_IER_TBRE   (1<<6)                 /* Transmit Buffer Register Empty Interrupt Enable */
#define MAC1_ETH_IER_TCOM   (1<<7)                 /* Transmit Complete Interrupt Enable    */
#define MAC1_ETH_IER_TIDLE  (1<<8)                 /* Transmit Idle Interrupt Enable        */
#define MAC1_ETH_IER_LINK   (1<<9)                 /* LINK Interrupt Enable                 */
#define MAC1_ETH_IER_ROVR   (1<<10)                /* RX Overrun Interrupt Enable           */
#define MAC1_ETH_IER_ABT    (1<<11)                /* Abort Interrupt Enable                */

/*-----------------------------------------------*/
/* MAC1_ETH_IDR: EMAC Interrupt Disable Register */
/*-----------------------------------------------*/
#define MAC1_ETH_IDR_DONE   (1<<0)                 /* Management Done Interrupt Disable     */
#define MAC1_ETH_IDR_RCOM   (1<<1)                 /* Receive Complete Interrupt Disable    */
#define MAC1_ETH_IDR_RBNA   (1<<2)                 /* Receive Buffer Not Available Interrupt Disable   */
#define MAC1_ETH_IDR_TOVR   (1<<3)                 /* Transmit Buffer Overrun Interrupt Disable        */
#define MAC1_ETH_IDR_TUND   (1<<4)                 /* Transmit Buffer Underrun Interrupt Disable       */
#define MAC1_ETH_IDR_RTRY   (1<<5)                 /* Retry Limit Interrupt Disable                    */
#define MAC1_ETH_IDR_TBRE   (1<<6)                 /* Transmit Buffer Register Empty Interrupt Disable */
#define MAC1_ETH_IDR_TCOM   (1<<7)                 /* Transmit Complete Interrupt Disable   */
#define MAC1_ETH_IDR_TIDLE  (1<<8)                 /* Transmit Idle Interrupt Disable       */
#define MAC1_ETH_IDR_LINK   (1<<9)                 /* LINK Interrupt Disable                */
#define MAC1_ETH_IDR_ROVR   (1<<10)                /* RX Overrun Interrupt Disable          */
#define MAC1_ETH_IDR_ABT    (1<<11)                /* Abort Interrupt Disable               */

/*-----------------------------------------------*/
/* MAC1_ETH_IMR: EMAC Interrupt Mask Register    */
/*-----------------------------------------------*/
#define MAC1_ETH_IMR_DONE   (1<<0)                 /* Management Done Interrupt Mask        */
#define MAC1_ETH_IMR_RCOM   (1<<1)                 /* Receive Complete Interrupt Mask       */
#define MAC1_ETH_IMR_RBNA   (1<<2)                 /* Receive Buffer Not Available Interrupt Mask   */
#define MAC1_ETH_IMR_TOVR   (1<<3)                 /* Transmit Buffer Overrun Interrupt Mask        */
#define MAC1_ETH_IMR_TUND   (1<<4)                 /* Transmit Buffer Underrun Interrupt Mask       */
#define MAC1_ETH_IMR_RTRY   (1<<5)                 /* Retry Limit Interrupt Mask                    */
#define MAC1_ETH_IMR_TBRE   (1<<6)                 /* Transmit Buffer Register Empty Interrupt Mask */
#define MAC1_ETH_IMR_TCOM   (1<<7)                 /* Transmit Complete Interrupt Mask      */
#define MAC1_ETH_IMR_TIDLE  (1<<8)                 /* Transmit Idle Interrupt Mask          */
#define MAC1_ETH_IMR_LINK   (1<<9)                 /* LINK Interrupt Mask                   */
#define MAC1_ETH_IMR_ROVR   (1<<10)                /* RX Overrun Interrupt Mask             */
#define MAC1_ETH_IMR_ABT    (1<<11)                /* Abort Interrupt Mask                  */

/*-----------------------------------------------*/
/* MAC1_ETH_MAN: EMAC PHY Maintenance Register   */
/*-----------------------------------------------*/
#define MAC1_ETH_MAN_DATA   (0xFFFF<<0)            
#define MAC1_ETH_MAN_CODE   (3<<16)                
#define MAC1_ETH_MAN_REGA   (0x1F<<18)             
#define MAC1_ETH_MAN_PHYA   (0x1F<<23)             
#define MAC1_ETH_MAN_RW     (3<<28)                
#define MAC1_ETH_MAN_HIGH   (1<<30)                
#define MAC1_ETH_MAN_LOW    (1<<31)                

/*----------------------------------------------------*/
/* MAC1_ETH_SA1H: EMAC Specific Address High Register */
/*----------------------------------------------------*/
#define MAC1_ETH_SA1H_ADDR   (0xFFFF<<0)            /* Unicast Addresses, Bits [47:32]       */           

/*----------------------------------------------------*/
/* MAC1_ETH_SA2H: EMAC Specific Address High Register */
/*----------------------------------------------------*/
#define MAC1_ETH_SA2H_ADDR   (0xFFFF<<0)            /* Unicast Addresses, Bits [47:32]       */

/*----------------------------------------------------*/
/* MAC1_ETH_SA3H: EMAC Specific Address High Register */
/*----------------------------------------------------*/
#define MAC1_ETH_SA3H_ADDR   (0xFFFF<<0)            /* Unicast Addresses, Bits [47:32]       */

/*----------------------------------------------------*/
/* MAC1_ETH_SA4H: EMAC Specific Address High Register */
/*----------------------------------------------------*/
#define MAC1_ETH_SA4H_ADDR   (0xFFFF<<0)            /* Unicast Addresses, Bits [47:32]       */



#endif 
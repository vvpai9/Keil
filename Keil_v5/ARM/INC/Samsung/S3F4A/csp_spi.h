/*
* Automotive Body/DashBoard Application MCU,S3F4A0K,
* Developed by Microcontroller Design Team
* 
* Copyright 2005 by MCU System Team, Samsung Electronics CO.,LTD.
* San #24 Nongseo-Dong,Giheung-Gu,
* 449-711 Youngin-City, Gyeongi-Do, Korea.
* All rights reserved.
*
* This software is the confidential and proprietary information of Samsung
* Electronics CO.,LTD. ("Confidential Information"). 
* You shall not disclose such Confidential Inforamtion and shall use it only
* in accordance with the terms of the license agreement you entered into
* with Samsung.
* 
* The software is delivered "AS IS" without warranty or condition of any 
* kind, either express, implied or statutory. This includes without limitation
* any warranty or condition with respect to merchantability or fitness for
* any particular purpose, or against the infringements of intellectual property
* rights of others. 
*/

/**
* @file name	csp_spi.h
* @description	Definitions, Macros and function declarations 
*            	for SPI module
*                
* @author	Juil Kim(82-31-209-2379, prodakim@samsung.com)   
*			Younghee Jin(82-31-209-4956, como.jin@samsung.com)
*			Minseok Jeong(82-31-209-3865, ms3525.jeong@samsung.com)		
*
* @version	Preliminary 0.0  
* @history	History type - NEW/MODify/ADD/DELete  
*  			 -------------------------------------------------------------------
*			|ver type when       who                       what             
*			|---+---+----------+-------------------------+----------------------
*			|0.0 NEW 01/07/2005  Samsung MCU System Team   Creation			
*	 		 -------------------------------------------------------------------
*
* @see	ADS Compiler Tool
*		Module/Drivers/Processor/Board -
*		SPI/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 


#ifndef CSP_SPI_H
#define CSP_SPI_H


/******************************************************************************
************************** SPI Structure Definition ***************************
******************************************************************************/

/** Number of SPI Chips Select                                               */
 #define NB_SPI_CS 4u

/* Chip Select                                                               */
 #define CS0       0u                   /**< Chip select 0                   */
 #define CS1       1u                   /**< Chip select 1                   */
 #define CS2       2u                   /**< Chip select 2                   */
 #define CS3       3u                   /**< Chip select 3                   */

/**
*******************************************************************************
@brief SPI Chip Select Structure
*******************************************************************************
*/
 typedef struct
 { 
    CSP_REGISTER_T  SSR;                /* Chips Select Registers            */
 } CSP_SPI_CS_T, *CSP_SPI_CS_PTR;


/**
*******************************************************************************
@brief SPI Structure
*******************************************************************************
*/
 typedef struct 
 {
    CSP_REGISTER_T  ReservedA[20];     
    CSP_REGISTER_T  ECR;                /**< Enable Clock Register           */
    CSP_REGISTER_T  DCR;                /**< Disable Clock Register          */
    CSP_REGISTER_T  PMSR;               /**< Power management Status Register*/
    CSP_REGISTER_T  ReservedD;       
    CSP_REGISTER_T  CR;                 /**< Control Register                */
    CSP_REGISTER_T  MR;                 /**< Mode Register                   */
    CSP_REGISTER_T  ReservedE;
    CSP_REGISTER_T  CSR;                /**< Clear Status Register           */
    CSP_REGISTER_T  SR;                 /**< Status Register                 */
    CSP_REGISTER_T  IER;                /**< Interrupt Enable Register       */
    CSP_REGISTER_T  IDR;                /**< Interrupt Disable Register      */
    CSP_REGISTER_T  IMR;                /**< Interrupt Mask Register         */
    CSP_REGISTER_T  RDR;                /**< Receive Data Register           */
    CSP_REGISTER_T  TDR;                /**< Transmit Data Register          */
    CSP_REGISTER_T  ReservedF[2];
    CSP_SPI_CS_T    CS[NB_SPI_CS];      /**< Chips Select Registers          */
 } CSP_SPI_T, *CSP_SPI_PTR;


/******************************************************************************
************************** SPI Registers Definition ***************************
******************************************************************************/


/******************************************************************************
* ECR, DCR, PMSR : SPI Power Management Registers
******************************************************************************/ 
 #define SPI_SPI          (0x01ul << 1)     /**< SPI Clock                   */
 #define SPI_IPIDCODE     (0x01ul << 4)     /**< SPI IPIDCODE                */
 #define SPI_DBGEN        (0x01ul << 31)    /**< Debug Mode Enable           */

/******************************************************************************
* CR : SPI Control Register
******************************************************************************/
 #define SPI_SWRST        (0x01ul << 0)     /**< SPI Software Reset          */
 #define SPI_SPIEN        (0x01ul << 1)     /**< SPI Enable Command          */
 #define SPI_SPIDIS       (0x01ul << 2)     /**< SPI Disable Command         */

/******************************************************************************
* MR : SPI Mode Register
******************************************************************************/
/* MSTR : Master / Slave Mode                                                */
 #define SPI_MSTR         (0x01ul << 0)     /**< MSTR Mask                   */
 #define SPI_SLAVE        (0x00ul << 0)     /**< Slave Mode                  */
 #define SPI_MASTER       (0x01ul << 0)     /**< Master Mode                 */
                           
/* PS : Peripheral Select                                                    */
 #define SPI_PS           (0x01ul << 1)     /**< PS Mask                     */
 #define SPI_PSFIX        (0x00ul << 1)     /**< Fix Peripheral Select       */
 #define SPI_PSVAR        (0x01ul << 1)     /**< Variable Peripheral Select  */
                                       
 #define SPI_PCSDEC       (0x01ul << 2)     /**< Chip Select Decode          */
 #define SPI_DIV32        (0x01ul << 3)     /**< Clock Selection             */
 #define SPI_MODFEN       (0x01ul << 4)     /**< Mode Fault                  */
 #define SPI_LLB          (0x01ul << 7)     /**< Local Loop Back             */

/* PCS : Peripheral Chip Select                                              */
 #define SPI_PCS_MASK     (0x0Ful << 16)    /**< PCS Mask                    */
/* PCSDEX = 0 : The 4 Chip select directly connected to a peripheral device  */
 #define SPI_PCS0         (0x0Eul << 16)    /**< Peripheral Chip Select 0    */
 #define SPI_PCS1         (0x01ul << 16)    /**< Peripheral Chip Select 1    */
 #define SPI_PCS2         (0x03ul << 16)    /**< Peripheral Chip Select 2    */
 #define SPI_PCS3         (0x07ul << 16)    /**< Peripheral Chip Select 3    */

/* PCSDEX = 1 : The 4 Chip select lines connected to a decoder               */
 #define SPI_PCS0_OUTPUT  (0x00ul << 16)    /**< Output lines = PCS 0        */
 #define SPI_PCS1_OUTPUT  (0x01ul << 16)    /**< Output lines = PCS 1        */
 #define SPI_PCS2_OUTPUT  (0x02ul << 16)    /**< Output lines = PCS 2        */
 #define SPI_PCS3_OUTPUT  (0x03ul << 16)    /**< Output lines = PCS 3        */
 #define SPI_PCS4_OUTPUT  (0x04ul << 16)    /**< Output lines = PCS 4        */
 #define SPI_PCS5_OUTPUT  (0x05ul << 16)    /**< Output lines = PCS 5        */
 #define SPI_PCS6_OUTPUT  (0x06ul << 16)    /**< Output lines = PCS 6        */
 #define SPI_PCS7_OUTPUT  (0x07ul << 16)    /**< Output lines = PCS 7        */
 #define SPI_PCS8_OUTPUT  (0x08ul << 16)    /**< Output lines = PCS 8        */
 #define SPI_PCS9_OUTPUT  (0x09ul << 16)    /**< Output lines = PCS 9        */
 #define SPI_PCS10_OUTPUT (0x0Aul << 16)    /**< Output lines = PCS 10       */
 #define SPI_PCS11_OUTPUT (0x0Bul << 16)    /**< Output lines = PCS 11       */
 #define SPI_PCS12_OUTPUT (0x0Cul << 16)    /**< Output lines = PCS 12       */
 #define SPI_PCS13_OUTPUT (0x0Dul << 16)    /**< Output lines = PCS 13       */
 #define SPI_PCS14_OUTPUT (0x0Eul << 16)    /**< Output lines = PCS 14       */
 #define SPI_PCS15_OUTPUT (0x0Ful << 16)    /**< Output lines = PCS 15       */

 #define SPI_DLYBCS_MASK  (0xFFul << 24)    /**< Delay Between Chip Select   */
 #define SPI_DLYBCS(val)  ((val & 0xFFul) << 24) /**< Writing macro          */

/******************************************************************************
* CSR, SR, IER, IDR, IMR : SPI Status and Interrupt Registers
******************************************************************************/
 #define SPI_MODF         (0x01ul << 2)     /**< Mode Fault Error            */
 #define SPI_OVRE         (0x01ul << 3)     /**< Overrun Error               */
 #define SPI_ENDTRANS     (0x01ul << 6)     /**< End Transfer 
                                                (Chip Select Inactive)       */

/* SR Register Only                                                          */
 #define SPI_RDRF         (0x01ul << 0)     /**< Receive Data Register Full  */
 #define SPI_TDRE         (0x01ul << 1)     /**< Transmit Data Register Empty*/
 #define SPI_ENS          (0x01ul << 8)     /**< SPI Enable                  */
 #define SPI_BUSY         (0x01ul << 9)     /**< SPI Busy                    */

/******************************************************************************
* RDR : SPI Received Data Register 
******************************************************************************/
 #define SPI_RD_MASK      (0xFFFFFul << 0)   /**< Receive Data               */
/* PCS : Peripheral Chip Select - Same as MR Register                        */

/******************************************************************************
* TDR : SPI Transmit Data Register
******************************************************************************/
 #define SPI_TD_MASK      (0xFFFFFul << 0)           /**< Transmit Data mask */
 #define SPI_TD(val)      ((val & 0xFFFFFul) << 0)   /**< Transmit Data      */
/* PCS : Peripheral Chip Select - Same as MR Register                        */

/******************************************************************************
* CSR : SPI Chip Select Register 
******************************************************************************/
 #define SPI_CPOL         (0x01ul << 0)     /**< Clock Polarity              */
 #define SPI_NCPHA        (0x01ul << 1)     /**< Clock Phase                 */

/* BITS : Number of Bits Per Transfer                                        */
 #define SPI_BITS_MASK    (0x0Ful << 4)     /**< BITS Mask                   */
 #define SPI_BITS_1       (0x01ul << 4)     /**< 1 Bits Per Transfer         */
 #define SPI_BITS_2       (0x02ul << 4)     /**< 2 Bits Per Transfer         */
 #define SPI_BITS_3       (0x03ul << 4)     /**< 3 Bits Per Transfer         */
 #define SPI_BITS_4       (0x04ul << 4)     /**< 4 Bits Per Transfer         */
 #define SPI_BITS_5       (0x05ul << 4)     /**< 5 Bits Per Transfer         */
 #define SPI_BITS_6       (0x06ul << 4)     /**< 6 Bits Per Transfer         */
 #define SPI_BITS_7       (0x07ul << 4)     /**< 7 Bits Per Transfer         */
 #define SPI_BITS_8       (0x00ul << 4)     /**< 8  Bits Per Transfer        */
 #define SPI_BITS_9       (0x01ul << 4)     /**< 9  Bits Per Transfer        */
 #define SPI_BITS_10      (0x02ul << 4)     /**< 10 Bits Per Transfer        */
 #define SPI_BITS_11      (0x03ul << 4)     /**< 11 Bits Per Transfer        */
 #define SPI_BITS_12      (0x04ul << 4)     /**< 12 Bits Per Transfer        */
 #define SPI_BITS_13      (0x05ul << 4)     /**< 13 Bits Per Transfer        */
 #define SPI_BITS_14      (0x06ul << 4)     /**< 14 Bits Per Transfer        */
 #define SPI_BITS_15      (0x07ul << 4)     /**< 15 Bits Per Transfer        */
 #define SPI_BITS_16      (0x08ul << 4)     /**< 16 Bits Per Transfer        */

/* SCBR : Serial Clock Baud Rate                                             */
 #define SPI_SCBR_MASK    (0xFFul << 8)              /**< Mask               */    
 #define SPI_SCBR(val)    (((val) & 0xFFul) << 8)    /**< Writing Macro      */    

/* DLYBS : Delay Before SCK                                                  */
 #define SPI_DLYBS_MASK   (0xFFul << 16)             /**< Mask               */
 #define SPI_DLYBS(val)   (((val) & 0xFFul) << 16)   /**< Writing Macro      */

/* DLYBCT : Delay Between Consecutive Transfers                              */
 #define SPI_DLYBCT_MASK  (0xFFul << 24)             /**< Mask               */
 #define SPI_DLYBCT(val)  (((val) & 0xFFul) << 24)   /**< Writing Macro      */

/******************************************************************************
***************************** SPI Registers mask ******************************
******************************************************************************/
 #define SPI_ECR_MASK          (0x80000002ul)    /**< ECR mask               */
 #define SPI_DCR_MASK          (0x80000002ul)    /**< DCR mask               */
 #define SPI_PMSR_MASK         (0xBFFFFFF2ul)    /**< PMSR mask              */
 #define SPI_CR_MASK           (0x00000007ul)    /**< CR mask                */
 #define SPI_MR_MASK           (0xFF0F009Ful)    /**< MR mask                */
 #define SPI_CSR_MASK          (0x0000007Cul)    /**< CSR mask               */
 #define SPI_SR_MASK           (0x0000037Ful)    /**< SR mask                */
 #define SPI_IER_MASK          (0x0000007Ful)    /**< IER mask               */
 #define SPI_IDR_MASK          (0x0000007Ful)    /**< IDR mask               */
 #define SPI_IMR_MASK          (0x0000007Ful)    /**< IMR mask               */
 #define SPI_RDR_MASK          (0x80000FFFul)    /**< RDR mask               */
 #define SPI_TDR_MASK          (0x80000FFFul)    /**< TDR mask               */
 #define SPI_SSR_MASK          (0xFFFFFFF3ul)    /**< SSR mask               */


/******************************************************************************
************************* SPI Registers reset value ***************************
******************************************************************************/
 #define SPI_ECR_RST           (0x00000000ul)    /**< ECR reset value         */
 #define SPI_DCR_RST           (0x00000000ul)    /**< DCR reset value         */
 #define SPI_PMSR_RST          (IPIDCODE_SPI_0)  /**< PMSR reset value        */
 #define SPI8_PMSR_RST         (IPIDCODE_SPI8_0) /**< PMSR reset value        */
 #define SPI_CR_RST            (0x00000000ul)    /**< CR reset value          */
 #define SPI_MR_RST            (0x00000000ul)    /**< MR reset value          */
 #define SPI_CSR_RST           (0x00000000ul)    /**< CSR reset value         */
 #define SPI_SR_RST            (0x00000000ul)    /**< SR reset value          */
 #define SPI_IER_RST           (0x00000000ul)    /**< IER reset value         */
 #define SPI_IDR_RST           (0x00000000ul)    /**< IDR reset value         */
 #define SPI_IMR_RST           (0x00000000ul)    /**< IMR reset value         */
 #define SPI_RDR_RST           (0x00000000ul)    /**< RDR reset value         */
 #define SPI_TDR_RST           (0x00000000ul)    /**< TDR reset value         */
 #define SPI_SSR_RST           (0x00000000ul)    /**< SSR reset value         */


/******************************************************************************
*************************** SPI Macros Definition *****************************
******************************************************************************/

/* ECR, DCR, PMSR : SPI Power Management Registers                           */
/** Set ECR register (Enable)                                                */
 #define CSP_SPI_SET_ECR(spi, val)      ((spi)->ECR = (val))
/** Set DCR register (Disable)                                               */
 #define CSP_SPI_SET_DCR(spi, val)      ((spi)->DCR = (val))
/** Get PMSR register (Status)                                               */
 #define CSP_SPI_GET_PMSR(spi)          ((spi)->PMSR)

/* CR : SPI Control Register                                                 */
/** Set CR register                                                          */
 #define CSP_SPI_SET_CR(spi, val)       ((spi)->CR = (val))

/* MR : SPI Mode Register                                                    */
/** Get MR register                                                          */
 #define CSP_SPI_GET_MR(spi)            ((spi)->MR)
/** Set MR register                                                          */
 #define CSP_SPI_SET_MR(spi, mode)      ((spi)->MR = (mode))

/* CSR, SR : SPI Status Registers                                            */
/** Set CSR register (Clear)                                                 */
 #define CSP_SPI_SET_CSR(spi, val)      ((spi)->CSR = (val))
/** Get SR register (Status)                                                 */
 #define CSP_SPI_GET_SR(spi)            ((spi)->SR)

/* IER, IDR, IMR : SPI Interrupt Registers                                   */
/** Set IER register (Enable)                                                */
 #define CSP_SPI_SET_IER(spi, val)      ((spi)->IER = (val))
/** Set IDR register (Disable)                                               */
 #define CSP_SPI_SET_IDR(spi, val)      ((spi)->IDR = (val))
/** Get IMR register (Status)                                                */
 #define CSP_SPI_GET_IMR(spi)           ((spi)->IMR)

/* RDR : SPI Receive Data Register                                           */
/** Get RDR register                                                         */
 #define CSP_SPI_GET_RDR(spi)           ((spi)->RDR)

/* TDR : SPI Transmit Data Register                                          */
/** Set TDR register                                                         */
 #define CSP_SPI_SET_TDR(spi, val)      ((spi)->TDR = (val))

/* CSR : SPI Chip Select Register                                            */
/** Get SSR register                                                         */
 #define CSP_SPI_CS_GET_SSR(spi, cs)       ((spi)->CS[(cs)].SSR)
/** Set SSR register                                                         */
 #define CSP_SPI_CS_SET_SSR(spi, cs, val)  ((spi)->CS[(cs)].SSR = (val))


/******************************************************************************
********************* SPI External Functions Declaration **********************
******************************************************************************/
extern void CSP_SPIInit(CSP_SPI_T *const spi, U32_T mode_u32);
extern void CSP_SPIClose(CSP_SPI_T *const spi);
extern void CSP_SPIConfigureCS(CSP_SPI_T *const spi,
                               U8_T cs_u8, 
                               U32_T mode_u32);
extern void CSP_SPIConfigInterrupt(CSP_SPI_T *const spi, 
                                   U32_T intMode_u32, 
                                   U32_T intMask_u32, 
                                   U32_T callback_u32);
extern void CSP_SPIEnable(CSP_SPI_T *const spi);
extern void CSP_SPIDisable(CSP_SPI_T *const spi);
extern void CSP_SPIReceive(CSP_SPI_T *const spi, 
                    U8_T cs_u8, 
                    U8_T channel_u8, 
                    U32_T destAddress_u32, 
                    U16_T length_u16);
extern void CSP_SPITransmit(CSP_SPI_T *const spi, 
                     U8_T cs_u8, 
                     U8_T channel_u8, 
                     U32_T sourceAddress_u32, 
                     U16_T length_u16);


#endif   /* CSP_SPI_H */

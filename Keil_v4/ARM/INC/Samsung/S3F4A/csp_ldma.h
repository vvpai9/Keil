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
* @file name	csp_ldma.h
* @description	Definitions, Macros and function declarations 
*            	for LDMA module
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
*		LDMA/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 




#ifndef CSP_LDMA_H
#define CSP_LDMA_H

/**
*******************************************************************************
* LDMA Channel Structure
*******************************************************************************
*/
typedef struct
{
   CSP_REGISTER_T CR;           /**< Channel Control Register                */
   CSP_REGISTER_T MR;           /**< Channel Mode Register                   */
   CSP_REGISTER_T CSR;          /**< Channel Clear Status Register           */
   CSP_REGISTER_T SR;           /**< Channel Status Register                 */
   CSP_REGISTER_T IER;          /**< Channel Interrupt Enable Register       */
   CSP_REGISTER_T IDR;          /**< Channel Interrupt Disable Register      */
   CSP_REGISTER_T IMR;          /**< Channel Interrupt Mode Register         */
   CSP_REGISTER_T ASRCR;        /**< Channel Source Address Register         */
   CSP_REGISTER_T ADSTR;        /**< Channel Destination Address Register    */
   CSP_REGISTER_T CNTR;         /**< Channel Transfert Counter Register      */
   CSP_REGISTER_T Reserved[22];
}CSP_LDMA_CHANNEL_T;

/**
*******************************************************************************
* LDMA Structure
*******************************************************************************
*/
typedef struct
{
   CSP_REGISTER_T Reserved[20];
   CSP_REGISTER_T ECR;          /**< LDMA Enable Clock Register             */
   CSP_REGISTER_T DCR;          /**< LDMA Disable Clock Register            */
   CSP_REGISTER_T PMSR;         /**< LDMA Power Management Status Register  */
   CSP_REGISTER_T ReservedA;
   CSP_REGISTER_T CR;           /**< LDMA Control Register                  */
   CSP_REGISTER_T ReservedB[3];
   CSP_REGISTER_T SR;           /**< LDMA Status Register                   */
   CSP_REGISTER_T IER;          /**< LDMA Interrupt Enable Register         */
   CSP_REGISTER_T IDR;          /**< LDMA Interrupt Disable Register        */
   CSP_REGISTER_T IMR;          /**< LDMA Interrupt Mode Register           */
   CSP_REGISTER_T ReservedC[32];
   CSP_LDMA_CHANNEL_T CHANNEL[NB_LDMA_CHANNEL];
}CSP_LDMA_T, *CSP_LDMA_PTR;


/**
*******************************************************************************
************************** LDMA Registers Definition *************************
*******************************************************************************
*/

/**
*******************************************************************************
*  ECR, DCR, PMSR
*******************************************************************************
*/
#define   LDMA_DBGEN   (0x01ul << 31)           /**< Debug Enable            */

/**
*******************************************************************************
*  CR
*******************************************************************************
*/
#define   LDMA_SWRST   (0x01 << 0)          /**< Software Reset              */

/**
*******************************************************************************
*  SR, IER, IDR, IMR
*******************************************************************************
*/
#define LDMA_CH0_IT    (0x01ul << 0)       /**< Channel 0 interrupt         */
#define LDMA_CH1_IT    (0x01ul << 1)       /**< Channel 1 interrupt         */
#define LDMA_CH2_IT    (0x01ul << 2)       /**< Channel 2 interrupt         */
#define LDMA_CH3_IT    (0x01ul << 3)       /**< Channel 3 interrupt         */
#define LDMA_CH4_IT    (0x01ul << 4)       /**< Channel 4 interrupt         */
#define LDMA_CH5_IT    (0x01ul << 5)       /**< Channel 5 interrupt         */
#define LDMA_CH6_IT    (0x01ul << 6)       /**< Channel 6 interrupt         */
#define LDMA_CH7_IT    (0x01ul << 7)       /**< Channel 7 interrupt         */
#define LDMA_CH8_IT    (0x01ul << 8)       /**< Channel 8 interrupt         */
#define LDMA_CH9_IT    (0x01ul << 9)       /**< Channel 9 interrupt         */
#define LDMA_CH10_IT   (0x01ul << 10)      /**< Channel 10 interrupt        */
#define LDMA_CH11_IT   (0x01ul << 11)      /**< Channel 11 interrupt        */
#define LDMA_CH12_IT   (0x01ul << 12)      /**< Channel 12 interrupt        */
#define LDMA_CH13_IT   (0x01ul << 13)      /**< Channel 13 interrupt        */
#define LDMA_CH14_IT   (0x01ul << 14)      /**< Channel 14 interrupt        */
#define LDMA_CH15_IT   (0x01ul << 15)      /**< Channel 15 interrupt        */
#define LDMA_CH16_IT   (0x01ul << 16)      /**< Channel 16 interrupt        */
#define LDMA_CH17_IT   (0x01ul << 17)      /**< Channel 17 interrupt        */
#define LDMA_CH18_IT   (0x01ul << 18)      /**< Channel 18 interrupt        */
#define LDMA_CH19_IT   (0x01ul << 19)      /**< Channel 19 interrupt        */
#define LDMA_CH20_IT   (0x01ul << 20)      /**< Channel 20 interrupt        */
#define LDMA_CH21_IT   (0x01ul << 21)      /**< Channel 21 interrupt        */
#define LDMA_CH22_IT   (0x01ul << 22)      /**< Channel 22 interrupt        */
#define LDMA_CH23_IT   (0x01ul << 23)      /**< Channel 23 interrupt        */
#define LDMA_CH24_IT   (0x01ul << 24)      /**< Channel 24 interrupt        */
#define LDMA_CH25_IT   (0x01ul << 25)      /**< Channel 25 interrupt        */
#define LDMA_CH26_IT   (0x01ul << 26)      /**< Channel 26 interrupt        */
#define LDMA_CH27_IT   (0x01ul << 27)      /**< Channel 27 interrupt        */
#define LDMA_CH28_IT   (0x01ul << 28)      /**< Channel 28 interrupt        */
#define LDMA_CH29_IT   (0x01ul << 29)      /**< Channel 29 interrupt        */
#define LDMA_CH30_IT   (0x01ul << 30)      /**< Channel 30 interrupt        */
#define LDMA_CH31_IT   (0x01ul << 31)      /**< Channel 31 interrupt        */

/**
*******************************************************************************
*  CRx
*******************************************************************************
*/
#define   LDMA_LCHEN   (0x01ul << 1)          /**< LDMA Enable Channel       */
#define   LDMA_LCHDIS  (0x01ul << 2)          /**< LDMA Disable Channel      */

/**
*******************************************************************************
*  MRx
*******************************************************************************
*/
#define    LDMA_SRC            (0x01ul << 0)  /**< Source bus transfert      */
#define    LDMA_DEST           (0x01ul << 1)  /**< Destination bus transfert */
#define    LDMA_SRC_INCR       (0x01ul << 2)  /**< Increment source address  */
#define    LDMA_DEST_INCR      (0x01ul << 3)  /**< Increment destination                                                        address                   */
#define    LDMA_TRIG           (0x01ul << 4)  /**< Trigger type              */
#define    LDMA_SIZE_MASK      (0x03ul << 5)  /**< LDMA transfert size mask  */
#define    LDMA_SIZE(val)      ((val & 0x03ul) << 5) /**< Writing macro      */
#define    LDMA_BYTE_SIZE      (0x00)         /**< Byte size                 */
#define    LDMA_HALF_WORD_SIZE (0x01)         /**< Half word size            */
#define    LDMA_WORD_SIZE      (0x02)         /**< Word size                 */
#define    LDMA_CHREADY_MASK   (0x1Ful << 8)  /**< Channel Ready mask        */
#define    LDMA_CHREADY(val)   ((val & 0x1Ful) << 8)  /**< Writing Macro     */

/**
*******************************************************************************
*  CSRx, SRx, IERx, IDRx, IMRx
*******************************************************************************
*/
#define    LDMA_END           (0x01ul << 0)   /**< LDMA End of Transfer      */
                                              /**< interrupt                 */
#define    LDMA_SRC_ERROR     (0x01ul << 1)   /**< Source Error interrup     */
#define    LDMA_DEST_ERROR    (0x01ul << 2)   /**< Destination Error         */
                                              /**< interrupt                 */
/* SRx register only */
#define    LDMA_CHEN          (0x01ul << 8)   /**< Channel Enable Status     */

/**
*******************************************************************************
*  ASRCx
*******************************************************************************
*/
#define    LDMA_SRC_ADD_MASK(val)  (0xFFFFFFFF << 0)
#define    LDMA_SRC_ADD(val)       ((val) & 0xFFFFFFFF << 0)

/**
*******************************************************************************
*  LDMA Register: ADSTx
*******************************************************************************
*/
#define    LDMA_DEST_ADD_MASK(val)  (0xFFFFFFFF << 0)
#define    LDMA_DEST_ADD(val)       ((val) & 0xFFFFFFFF << 0)

/**
*******************************************************************************
*  LDMA Register: CNTx
*******************************************************************************
*/
#define    LDMA_DATA_CNT_MASK       (0xFFFFul << 0)
#define    LDMA_DATA_CNT(val)       ((val & 0xFFFFul) << 0)

/**
*******************************************************************************
***************************** LDMA Registers mask ****************************
*******************************************************************************
*/
#define LDMA_ECR_MASK     (0x80000000ul)      /**< ECR mask                 */
#define LDMA_DCR_MASK     (0x80000000ul)      /**< DCR mask                 */
#define LDMA_PMSR_MASK    (0x80000000ul)      /**< PMSR mask                */
#define LDMA_CR_MASK      (0x00000001ul)      /**< CR mask                  */
#define LDMA_SR_MASK      (0xFFFFFFFFul)      /**< SR mask                  */
#define LDMA_IER_MASK     (0x000000FFul)      /**< IER mask                 */
#define LDMA_IDR_MASK     (0x000000FFul)      /**< IDR mask                 */
#define LDMA_IMR_MASK     (0x000000FFul)      /**< IMR mask                 */
#define LDMA_CRX_MASK     (0x00000006ul)      /**< CRX mask                 */
#define LDMA_MRX_MASK     (0x00001F7Ful)      /**< MRX mask                 */
#define LDMA_CSRX_MASK    (0x00000007ul)      /**< CSRX mask                */
#define LDMA_SRX_MASK     (0x00000107ul)      /**< SRX mask                 */
#define LDMA_IERX_MASK    (0x00000007ul)      /**< IERX mask                */
#define LDMA_IDRX_MASK    (0x00000007ul)      /**< IDRX mask                */
#define LDMA_IMRX_MASK    (0x00000007ul)      /**< IMRX mask                */
#define LDMA_ASRCRX_MASK  (0xFFFFFFFFul)      /**< ASRCRX mask               */
#define LDMA_ADSTRX_MASK  (0xFFFFFFFFul)      /**< ADSTRX mask               */
#define LDMA_CNTRX_MASK   (0x0000FFFFul)      /**< CNTRX mask                */

/**
*******************************************************************************
************************* LDMA Registers reset value *************************
*******************************************************************************
*/
#define LDMA_ECR_RST     (0x00000000ul)       /**< ECR reset value          */
#define LDMA_DCR_RST     (0x00000000ul)       /**< DCR reset value          */
#define LDMA_PMSR_RST    (0x00000000ul)       /**< PMSR reset value         */
#define LDMA_CR_RST      (0x00000000ul)       /**< CR reset value           */
#define LDMA_SR_RST      (0x00000000ul)       /**< SR reset value           */
#define LDMA_IER_RST     (0x00000000ul)       /**< IER reset value          */
#define LDMA_IDR_RST     (0x00000000ul)       /**< IDR reset value          */
#define LDMA_IMR_RST     (0x00000000ul)       /**< IMR reset value          */
#define LDMA_CRX_RST     (0x00000000ul)       /**< CRX reset value          */
#define LDMA_MRX_RST     (0x00000000ul)       /**< MRX reset value          */
#define LDMA_CSRX_RST    (0x00000000ul)       /**< CSRX reset value         */
#define LDMA_SRX_RST     (0x00000000ul)       /**< SRX reset value          */
#define LDMA_IERX_RST    (0x00000000ul)       /**< IERX reset value         */
#define LDMA_IDRX_RST    (0x00000000ul)       /**< IDRX reset value         */
#define LDMA_IMRX_RST    (0x00000000ul)       /**< IMRX reset value         */
#define LDMA_ASRCRX_RST  (0x00000000ul)       /**< ASRCRX reset value        */
#define LDMA_ADSTRX_RST  (0x00000000ul)       /**< ADSTRX reset value        */
#define LDMA_CNTRX_RST   (0x00000000ul)       /**< CNTRX reset value         */


/**
*******************************************************************************
*************************** LDMA Macros Definition ***************************
*******************************************************************************
*/
/* ECR, DCR, PMSR : CAN Power Management Registers                           */
/** Set ECR register (Enable)                                                */
#define CSP_LDMA_SET_ECR(ldma, val)     (ldma->ECR = val)
/** Set DCR register (Disable)                                               */
#define CSP_LDMA_SET_DCR(ldma, val)     (ldma->DCR = val)
/** Get PMSR register (Enable)                                               */
#define CSP_LDMA_GET_PMSR(ldma)         (ldma->PMSR)

/** Set CR register                                                          */
#define CSP_LDMA_SET_CR(ldma, val)      (ldma->CR = val)
/** Get SR register                                                          */
#define CSP_LDMA_GET_SR(ldma)           (ldma->SR)

/** Set IER register (Enable)                                                */
#define CSP_LDMA_SET_IER(ldma, val)     (ldma->IER = val)
/** Set IDR register (Disable)                                               */
#define CSP_LDMA_SET_IDR(ldma, val)     (ldma->IDR = val)
/** Get IMR register (Status)                                                */
#define CSP_LDMA_GET_IMR(ldma)          (ldma->IMR)

/** Set CRX register                                                         */
#define CSP_LDMA_SET_CRX(ldma, channel, val)                                \
                                         (ldma->CHANNEL[channel].CR = val)

/** Get MRX register                                                         */
#define CSP_LDMA_GET_MRX(ldma, channel) (ldma->CHANNEL[channel].MR)
/** Set MRX register                                                         */
#define CSP_LDMA_SET_MRX(ldma, channel, val)                                \
                                         (ldma->CHANNEL[channel].MR = val)

/** Set CSRX register                                                        */
#define CSP_LDMA_SET_CSRX(ldma, channel, val)                               \
                                         (ldma->CHANNEL[channel].CSR = val)
/** Get SRX register                                                         */
#define CSP_LDMA_GET_SRX(ldma, channel)    (ldma->CHANNEL[channel].SR)

/** Set IERX register (Enable)                                               */
#define CSP_LDMA_SET_IERX(ldma, channel, val)                               \
                                         (ldma->CHANNEL[channel].IER = val)
/** Set IDRX register (Disable)                                              */
#define CSP_LDMA_SET_IDRX(ldma, channel, val)                               \
                                         (ldma->CHANNEL[channel].IDR = val)
/** Get IMRX register (Status)                                               */
#define CSP_LDMA_GET_IMRX(ldma, channel)   (ldma->CHANNEL[channel].IMR)

/** Get ASRCX register                                                       */
#define CSP_LDMA_GET_ASRCRX(ldma, channel)  (ldma->CHANNEL[channel].ASRCR)
/** Set ASRCX register                                                       */
#define CSP_LDMA_SET_ASRCRX(ldma, channel, val)                              \
                                          (ldma->CHANNEL[channel].ASRCR = val)

/** Get ADSTX register                                                       */
#define CSP_LDMA_GET_ADSTRX(ldma, channel) (ldma->CHANNEL[channel].ADSTR)
/** Set ADSTX register                                                       */
#define CSP_LDMA_SET_ADSTRX(ldma, channel, val)                              \
                                          (ldma->CHANNEL[channel].ADSTR = val)

/** Get CNTX register                                                        */
#define CSP_LDMA_GET_CNTRX(ldma, channel)  (ldma->CHANNEL[channel].CNTR)
/** Set CNTX register                                                        */
#define CSP_LDMA_SET_CNTRX(ldma, channel, val)                               \
                                          (ldma->CHANNEL[channel].CNTR = val)


/******************************************************************************
********************* LDMA External Functions Declaration ********************
******************************************************************************/

extern void CSP_LDMAInit(CSP_LDMA_T *const ldma);
extern void CSP_LDMARxInitChannel(CSP_LDMA_T *const ldma, 
                                  U32_T periph_address, 
                                  U8_T channel_u8, 
                                  U32_T mode_u32);
extern void CSP_LDMATxInitChannel(CSP_LDMA_T *const ldma, 
                                  U32_T periph_address, 
                                  U8_T channel_u8, 
                                  U32_T mode_u32);
extern void CSP_LDMAConfigInterrupt(CSP_LDMA_T *const ldma, 
                                    U32_T intMode_u32, 
                                    U32_T intMask_u32, 
                                    U32_T callback_u32);                                     
extern void CSP_LDMAConfigChannelInterrupt(CSP_LDMA_T *const ldma,
                                           U8_T channel_u8,
                                           U32_T intChannelMask_u32);
extern void CSP_LDMAEnableChannel(CSP_LDMA_T *const ldma, U8_T channel_u8);
extern void CSP_LDMADisableChannel(CSP_LDMA_T *const ldma, U8_T channel_u8);
extern void CSP_LDMAStartTransfer(CSP_LDMA_T *const ldma, U8_T channel_u8,
                                   U32_T srcAddress_u32, 
                                   U32_T destAddress_u32, 
                                   U16_T nbData_u16);

#endif   /* CSP_LDMA_H */

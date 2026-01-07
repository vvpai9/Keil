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
* @file name	csp_lcdc.h
* @description	Definitions, Macros and function declarations 
*            	for LCDC module
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
*		LCDC/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 


#ifndef CSP_LCDC_H
#define CSP_LCDC_H


/**
*******************************************************************************
@brief LCDC Structure
*******************************************************************************
*/
typedef struct
{ 
   CSP_REGISTER_T     ReservedA[20]; 
   CSP_REGISTER_T     ECR;           /**< Enable Clock Register              */
   CSP_REGISTER_T     DCR;           /**< Disable Clock Register             */
   CSP_REGISTER_T     PMSR;          /**< Power ManagementStatus Register    */
   CSP_REGISTER_T     ReservedB; 
   CSP_REGISTER_T     CR;            /**< Control Register                   */
   CSP_REGISTER_T     MR;            /**< Mode Register                      */
   CSP_REGISTER_T     ReservedC[2];
   CSP_REGISTER_T     SR;            /**< Status Register                    */
   CSP_REGISTER_T     ReservedD[3];
   CSP_REGISTER_T     CLKDIVR;       /**< Scalling Clock Register            */
   CSP_REGISTER_T     ReservedE[3];
   CSP_REGISTER_T     DMR[5];        /**< LCD Display Memory Register        */
   CSP_REGISTER_T     ReservedF[3];
   CSP_REGISTER_T     TSTR;          /**< Test Register                      */
} CSP_LCDC_T, *CSP_LCDC_PTR;


/**
*******************************************************************************
************************** LCDC Registers Definition ***************************
*******************************************************************************
*/
/**
*******************************************************************************
* ECR, DCR, PMSR Register
*******************************************************************************
*/
#define LCDC_LCD        (0x01ul << 1)         /**< LCD Clock                 */
#define LCDC_DBGEN      (0x01ul <<31)         /**< Debug mode enable         */

/**
*******************************************************************************
* CR, SR Register
*******************************************************************************
*/
#define LCDC_VLC0       (0x01ul << 7)        /**< VLC0 Level Select          */
#define LCDC_EXTVDD     (0x00ul << 7)        /**< External VDD as VLCD       */
#define LCDC_INTVDD     (0x01ul << 7)        /**< Internal VDD as VLCD       */

#define LCDC_VLCD       (0x01ul << 15)       /**< VLCD Select                */
#define LCDC_VLCDSEL    (0x01ul << 15)       /**< VLC0 = VLCD                */
#define LCDC_BIASSEL    (0x00ul << 15)       /**< VLC0 = Internal Bias 
                                                  dividing circuit           */  
#define LCDC_BIASCLK    (0x01ul << 23)       /**< BIAS Circuit Select        */
#define LCDC_EXTBIAS    (0x01ul << 23)       /**< External Bias circuit      */
#define LCDC_INTBIAS    (0x00ul << 23)       /**< External Bias circuit      */

#define LCDC_LCDEN      (0x01ul << 31)       /**< LCD Enable                 */
#define LCDC_LCDENABLE  (0x01ul << 31)       /**< LCD Enable                 */
#define LCDC_LCDDISABLE (0x00ul << 31)       /**< LCD Disable                */

/**
*******************************************************************************
* MR Register
*******************************************************************************
*/
#define LCDC_OP_MODE_MASK (0x07ul << 0)         /**< Operating bias and Duty 
                                                     mode                    */
#define LCDC_OP_MODE(val) ((0x07ul & val) << 0) /**< Writing macro           */
#define LCDC_OP_4D3B      (0x00ul)              /**< 1/4 Duty, 1/3 Bias mode */
#define LCDC_OP_3D3B      (0x01ul)              /**< 1/3 Duty, 1/3 Bias mode */
#define LCDC_OP_3D2B      (0x02ul)              /**< 1/3 Duty, 1/2 Bias mode */
#define LCDC_OP_2D2B      (0x03ul)              /**< 1/2 Duty, 1/2 Bias mode */
#define LCDC_OP_STATIC    (0x04ul)              /**< Static Mode             */

#define LCDC_FR_FREQ_MASK  (0x03ul << 4)        /**< Frame Frequency         */
#define LCDC_FR_FREQ(val)  ((0x03ul & val) << 4)/**< Writing macro           */
#define LCDC_FR_FREQ_62_5  (0x00ul << 4)        /**< Frame Freq = 62.5 Hz    */
#define LCDC_FR_FREQ_125   (0x01ul << 4)        /**< Frame Freq = 125 Hz     */
#define LCDC_FR_FREQ_250   (0x02ul << 4)        /**< Frame Freq = 250 Hz     */
#define LCDC_FR_FREQ_500   (0x03ul << 4)        /**< Frame Freq = 500 Hz     */

/**
*******************************************************************************
* CLKDIVR Register
*******************************************************************************
*/
#define LCDC_DIVVAL_MASK  (0xFFFFul << 0)       /**< LCD Clock Scaling value */
#define LCDC_DIVVAL(val)  ((0xFFFFul & val) << 0)   /**< Writing macro       */

/**
*******************************************************************************
* DMRX Registers
*******************************************************************************
*/
#define LCDC_COM_MASK  (0xFul)      /**< COM mask in DMx registers   */
#define LCDC_COM0      (0x1ul)      /**< COM 0 mask in DMx registers */
#define LCDC_COM1      (0x2ul)      /**< COM 1 mask in DMx registers */
#define LCDC_COM2      (0x4ul)      /**< COM 2 mask in DMx registers */
#define LCDC_COM3      (0x8ul)      /**< COM 3 mask in DMx registers */
#define LCDC_SEG0_COM_MASK  (0xFul << 0)          /**< LCD segment           */
#define LCDC_SEG0_COM_(val) ((0xFul & val) << 0)  /**< Writing macro         */
#define LCDC_SEG1_COM_MASK  (0xFul << 4)          /**< LCD segment           */
#define LCDC_SEG1_COM_(val) ((0xFul & val) << 4)  /**< Writing macro         */
#define LCDC_SEG2_COM_MASK  (0xFul << 8)          /**< LCD segment           */
#define LCDC_SEG2_COM_(val) ((0xFul & val) << 8)  /**< Writing macro         */
#define LCDC_SEG3_COM_MASK  (0xFul << 12)         /**< LCD segment           */
#define LCDC_SEG3_COM_(val) ((0xFul & val) << 12) /**< Writing macro         */
#define LCDC_SEG4_COM_MASK  (0xFul << 16)         /**< LCD segment           */
#define LCDC_SEG4_COM_(val) ((0xFul & val) << 16) /**< Writing macro         */
#define LCDC_SEG5_COM_MASK  (0xFul << 20)         /**< LCD segment           */
#define LCDC_SEG5_COM_(val) ((0xFul & val) << 20) /**< Writing macro         */
#define LCDC_SEG6_COM_MASK  (0xFul << 24)         /**< LCD segment           */
#define LCDC_SEG6_COM_(val) ((0xFul & val) << 24) /**< Writing macro         */
#define LCDC_SEG7_COM_MASK  (0xFul << 28)         /**< LCD segment           */
#define LCDC_SEG7_COM_(val) ((0xFul & val) << 28) /**< Writing macro         */

#define LCDC_SEG8_COM_MASK  (0xFul << 0)          /**< LCD segment           */
#define LCDC_SEG8_COM_(val) ((0xFul & val) << 0)  /**< Writing macro         */
#define LCDC_SEG9_COM_MASK  (0xFul << 0)          /**< LCD segment           */
#define LCDC_SEG9_COM_(val) ((0xFul & val) << 4)  /**< Writing macro         */
#define LCDC_SEG10_COM_MASK  (0xFul << 0)         /**< LCD segment           */
#define LCDC_SEG10_COM_(val) ((0xFul & val) << 8) /**< Writing macro         */
#define LCDC_SEG11_COM_MASK  (0xFul << 0)         /**< LCD segment           */
#define LCDC_SEG11_COM_(val) ((0xFul & val) << 12) /**< Writing macro         */
#define LCDC_SEG12_COM_MASK  (0xFul << 0)         /**< LCD segment           */
#define LCDC_SEG12_COM_(val) ((0xFul & val) << 16) /**< Writing macro         */
#define LCDC_SEG13_COM_MASK  (0xFul << 0)         /**< LCD segment           */
#define LCDC_SEG13_COM_(val) ((0xFul & val) << 20) /**< Writing macro         */
#define LCDC_SEG14_COM_MASK  (0xFul << 0)         /**< LCD segment           */
#define LCDC_SEG14_COM_(val) ((0xFul & val) << 24) /**< Writing macro         */
#define LCDC_SEG15_COM_MASK  (0xFul << 0)         /**< LCD segment           */
#define LCDC_SEG15_COM_(val) ((0xFul & val) << 28) /**< Writing macro         */

#define LCDC_SEG16_COM_MASK  (0xFul << 0)         /**< LCD segment           */
#define LCDC_SEG16_COM_(val) ((0xFul & val) << 0) /**< Writing macro         */
#define LCDC_SEG17_COM_MASK  (0xFul << 4)         /**< LCD segment           */
#define LCDC_SEG17_COM_(val) ((0xFul & val) << 4) /**< Writing macro         */
#define LCDC_SEG18_COM_MASK  (0xFul << 8)         /**< LCD segment           */
#define LCDC_SEG18_COM_(val) ((0xFul & val) << 8) /**< Writing macro         */
#define LCDC_SEG19_COM_MASK  (0xFul << 12)        /**< LCD segment           */
#define LCDC_SEG19_COM_(val) ((0xFul & val) << 12)/**< Writing macro         */
#define LCDC_SEG20_COM_MASK  (0xFul << 16)        /**< LCD segment           */
#define LCDC_SEG20_COM_(val) ((0xFul & val) << 16)/**< Writing macro         */
#define LCDC_SEG21_COM_MASK  (0xFul << 20)        /**< LCD segment           */
#define LCDC_SEG21_COM_(val) ((0xFul & val) << 20)/**< Writing macro         */
#define LCDC_SEG22_COM_MASK  (0xFul << 24)        /**< LCD segment           */
#define LCDC_SEG22_COM_(val) ((0xFul & val) << 24)/**< Writing macro         */
#define LCDC_SEG23_COM_MASK  (0xFul << 28)        /**< LCD segment           */
#define LCDC_SEG23_COM_(val) ((0xFul & val) << 28)/**< Writing macro         */

#define LCDC_SEG24_COM_MASK  (0xFul << 0)         /**< LCD segment           */
#define LCDC_SEG24_COM_(val) ((0xFul & val) << 0) /**< Writing macro         */
#define LCDC_SEG25_COM_MASK  (0xFul << 4)         /**< LCD segment           */
#define LCDC_SEG25_COM_(val) ((0xFul & val) << 4) /**< Writing macro         */
#define LCDC_SEG26_COM_MASK  (0xFul << 8)         /**< LCD segment           */
#define LCDC_SEG26_COM_(val) ((0xFul & val) << 8) /**< Writing macro         */
#define LCDC_SEG27_COM_MASK  (0xFul << 12)        /**< LCD segment           */
#define LCDC_SEG27_COM_(val) ((0xFul & val) << 12)/**< Writing macro         */
#define LCDC_SEG28_COM_MASK  (0xFul << 16)        /**< LCD segment           */
#define LCDC_SEG28_COM_(val) ((0xFul & val) << 16)/**< Writing macro         */
#define LCDC_SEG29_COM_MASK  (0xFul << 20)        /**< LCD segment           */
#define LCDC_SEG29_COM_(val) ((0xFul & val) << 20)/**< Writing macro         */
#define LCDC_SEG30_COM_MASK  (0xFul << 24)        /**< LCD segment           */
#define LCDC_SEG30_COM_(val) ((0xFul & val) << 24)/**< Writing macro         */
#define LCDC_SEG31_COM_MASK  (0xFul << 28)        /**< LCD segment           */
#define LCDC_SEG31_COM_(val) ((0xFul & val) << 28)/**< Writing macro         */

#define LCDC_SEG32_COM_MASK  (0xFul << 0)         /**< LCD segment           */
#define LCDC_SEG32_COM_(val) ((0xFul & val) << 0) /**< Writing macro         */
#define LCDC_SEG33_COM_MASK  (0xFul << 4)         /**< LCD segment           */
#define LCDC_SEG33_COM_(val) ((0xFul & val) << 4) /**< Writing macro         */
#define LCDC_SEG34_COM_MASK  (0xFul << 8)         /**< LCD segment           */
#define LCDC_SEG34_COM_(val) ((0xFul & val) << 8) /**< Writing macro         */
#define LCDC_SEG35_COM_MASK  (0xFul << 12)        /**< LCD segment           */
#define LCDC_SEG35_COM_(val) ((0xFul & val) << 12)/**< Writing macro         */
#define LCDC_SEG36_COM_MASK  (0xFul << 16)        /**< LCD segment           */
#define LCDC_SEG36_COM_(val) ((0xFul & val) << 16)/**< Writing macro         */
#define LCDC_SEG37_COM_MASK  (0xFul << 20)        /**< LCD segment           */
#define LCDC_SEG37_COM_(val) ((0xFul & val) << 20)/**< Writing macro         */
#define LCDC_SEG38_COM_MASK  (0xFul << 24)        /**< LCD segment           */
#define LCDC_SEG38_COM_(val) ((0xFul & val) << 24)/**< Writing macro         */
#define LCDC_SEG39_COM_MASK  (0xFul << 28)        /**< LCD segment           */
#define LCDC_SEG39_COM_(val) ((0xFul & val) << 28)/**< Writing macro         */

/**
*******************************************************************************
* TSTR Register
*******************************************************************************
*/
#define LCDC_TESTEN       (0x01ul << 0)         /**< Test Enable             */

/**
*******************************************************************************
***************************** LCDC Registers mask *****************************
*******************************************************************************
*/
#define LCDC_ECR_MASK     (0x00000002ul)        /**< ECR mask                */
#define LCDC_DRC_MASK     (0x00000002ul)        /**< DCR mask                */
#define LCDC_PMSR_MASK    (0x3FFFFFF2ul)        /**< PMSR mask               */
#define LCDC_CR_MASK      (0x80808080ul)        /**< CR mask                 */
#define LCDC_MR_MASK      (0x00000037ul)        /**< MR mask                 */
#define LCDC_SR_MASK      (0x80808080ul)        /**< SR mask                 */
#define LCDC_CLKDIVR_MASK (0x0000FFFFul)        /**< CLKDIVR mask            */
#define LCDC_DMX_MASK     (0xFFFFFFFFul)        /**< DMX mask                */
#define LCDC_TESTR_MASK   (0x00000001ul)        /**< TESTR mask              */

/**
*******************************************************************************
************************* LCDC Registers reset value **************************
*******************************************************************************
*/
#define LCDC_ECR_RST      (0x00000000ul)        /**< ECR reset               */
#define LCDC_DRC_RST      (0x00000000ul)        /**< DCR reset               */
#define LCDC_PMSR_RST     (0x00000000ul)        /**< PMSR reset              */
#define LCDC_CR_RST       (0x00000000ul)        /**< CR reset                */
#define LCDC_MR_RST       (0x00000000ul)        /**< MR reset                */
#define LCDC_SR_RST       (0x00000000ul)        /**< SR reset                */
#define LCDC_CLKDIVR_RST  (0x00009C3Ful)        /**< SCR reset               */
#define LCDC_DMX_RST      (0x00000000ul)        /**< DMX reset               */
#define LCDC_TESTR_RST    (0x00000001ul)        /**< TESTR reset             */

/**
*******************************************************************************
*************************** LCDC Macros Definition ****************************
*******************************************************************************
*/
/* ECR, DCR, PMSR :                                                          */
/** Set ECR register (Enable)                                                */
#define CSP_LCDC_SET_ECR(lcdc, val)       ((lcdc)->ECR = (val))
/** Set DCR register (Disable)                                               */
#define CSP_LCDC_SET_DCR(lcdc, val)       ((lcdc)->DCR = (val))
/** Get PMSR register (Statust)                                              */
#define CSP_LCDC_GET_PMSR(lcdc)           ((lcdc)->PMSR)

/* CR : LCDC Control Register                                                */
/** Set CR register                                                          */
#define CSP_LCDC_SET_CR(lcdc,val)         ((lcdc)->CR = (val))

/* MR : LCDC Mode Register                                                   */
/** Get MR register (Mode Register)                                          */
#define CSP_LCDC_GET_MR                   ((lcdc)->MR)
/** Set MR register (Mode Register)                                          */
#define CSP_LCDC_SET_MR(lcdc,mode)        ((lcdc)->MR = (mode))

/* SR : LCDC Status Register                                                 */
/** Get SR register (Status Register)                                        */
#define CSP_LCDC_GET_SR(lcdc)             ((lcdc)->SR)

/* CLKDIVR : LCDC Clock Dividing Register                                    */
/** Set SCR register (Status Register)                                       */
#define CSP_LCDC_SET_CLKDIVR(lcdc,val)    ((lcdc)->CLKDIVR = (val))
/** Get SCR register (Status Register)                                       */
#define CSP_LCDC_GET_CLKDIVR(lcdc)        ((lcdc)->CLKDIVR)

/* DMRX : LCDC Display Memory Register                                       */
/** Set DMX register (Status Register)                                       */
#define CSP_LCDC_SET_DMR(lcdc,val, mem)   ((lcdc)->DMR[mem] = (val))
/** Get DMX register (Status Register)                                       */
#define CSP_LCDC_GET_DMR(lcdc,mem)        ((lcdc)->DMR[mem])

/**
*******************************************************************************
********************* LCDC External Functions Declaration *********************
*******************************************************************************
*/

#endif   /* CSP_LCDC_H */

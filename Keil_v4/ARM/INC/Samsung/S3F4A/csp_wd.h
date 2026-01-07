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
* @file name	csp_wd.h
* @description	Definitions, Macros and function declarations 
*            	for Watchdog module
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
*		WD/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 

#ifndef CSP_WD_H
#define CSP_WD_H


/******************************************************************************
************************** WD Structure Definition ****************************
******************************************************************************/
/**
*******************************************************************************
@brief WD Structure
*******************************************************************************
*/
 typedef struct
 { 
    CSP_REGISTER_T  ReservedA[20];
    CSP_REGISTER_T  ECR;             /**< Enable Clock Register              */
    CSP_REGISTER_T  DCR;             /**< Disable Clock Register             */
    CSP_REGISTER_T  PMSR;            /**< Power Management Status Register   */
    CSP_REGISTER_T  ReservedB;
    CSP_REGISTER_T  CR;              /**< Control Register                   */
    CSP_REGISTER_T  MR;              /**< Mode Register                      */
    CSP_REGISTER_T  OMR;             /**< Overflow Mode Register             */
    CSP_REGISTER_T  CSR;             /**< Clear Status Register              */
    CSP_REGISTER_T  SR;              /**< Status Register                    */
    CSP_REGISTER_T  IER;             /**< Interrupt Enable Register          */
    CSP_REGISTER_T  IDR;             /**< Interrupt Disable Register         */
    CSP_REGISTER_T  IMR;             /**< Interrupt Mask Register            */
    CSP_REGISTER_T  PWR;             /**< Pending Window Register            */
    CSP_REGISTER_T  CTR;             /**< Counter Test Register              */
 } CSP_WD_T, *CSP_WD_PTR;


/******************************************************************************
************************** WD Registers Definition ****************************
******************************************************************************/

/******************************************************************************
* ECR, DCR, PMSR : WD Power Management Registers
******************************************************************************/
 #define WD_IPIDCODE     (0x3FFFFFul << 4)    /**< WD version number         */
 #define WD_DBGEN        (0x01ul << 31)       /**< Debug Mode Enable         */


/******************************************************************************
* CR : WD Control Register
******************************************************************************/
 #define WD_RSTKEY_MASK  (0xFFFFul << 0)   /**< Restart key mask             */
 #define WD_RSTKEY       (0xC071ul << 0)   /**< Restart key                  */


/******************************************************************************
* MR : WD Mode Register
******************************************************************************/
/* WDPDIV : Clock Divider                                                    */
 #define WD_WDPDIV_MASK    (0x07ul << 0)   /**< WDPDIV Mask                  */
 #define WD_WDPDIV(val)    ((0x07ul & val) << 0) /**< Writing macro          */
 #define WD_WDPDIVCLK_2    (0x00ul)        /**< WDPDIVCLK / 2                */
 #define WD_WDPDIVCLK_4    (0x01ul)        /**< WDPDIVCLK / 4                */
 #define WD_WDPDIVCLK_8    (0x02ul)        /**< WDPDIVCLK / 8                */
 #define WD_WDPDIVCLK_16   (0x03ul)        /**< WDPDIVCLK / 16               */
 #define WD_WDPDIVCLK_32   (0x04ul)        /**< WDPDIVCLK / 32               */
 #define WD_WDPDIVCLK_128  (0x05ul)        /**< WDPDIVCLK / 128              */
 #define WD_WDPDIVCLK_256  (0x06ul)        /**< WDPDIVCLK / 256              */
 #define WD_WDPDIVCLK_512 (0x07ul)        /**< WDPDIVCLK / 512             */

/* PCV : High Preload Counter Value                                          */
 #define WD_PCV_MASK       (0xFFFFul << 8) /**< Mask                         */
 #define WD_PCV(val)       (((val) & 0xFFFFul) << 8)  /**< Writing Macro     */

/* CKEY : Clock access Key                                                   */
 #define WD_CKEY_MASK      (0xFFul << 24)  /**< CKEY Mask                    */
 #define WD_CKEY           (0x37ul << 24)  /**< Write Access in MR allowed   */


/******************************************************************************
* OMR : WD Overflow Mode Register
******************************************************************************/
 #define WD_WDEN           (0x01ul << 0)   /**< Watchdog Enable              */
 #define WD_RSTEN          (0x01ul << 1)   /**< Reset Enable                 */

/* OKEY : Overflow access key                                                */
 #define WD_OKEY_MASK      (0xFFFul << 4)  /**< OKEY Mask                    */
 #define WD_OKEY           (0x234ul << 4)  /**< Write Access in OMR allowed  */


/******************************************************************************
* CSR, SR, IER, IDR, IMR : WD Status and Interrupt Registers
******************************************************************************/
 #define WD_WDPEND         (0x01ul << 0)   /**< Watchdog Pending             */
 #define WD_WDOVF          (0x01ul << 1)   /**< Watchdog Overflow            */

/* SR Register Only                                                          */
 #define WD_PENDING        (0x01ul << 8)   /**< WatchDog Pending Status      */
 #define WD_CLEAR_STATUS   (0x01ul << 9)   /**< Watchdog Clear Status        */


/******************************************************************************
* PWR : WD Pending Window Register
******************************************************************************/
 #define WD_RSTALW         (0x01ul << 0)   /**< Restart allowed              */

/* PWL : Pending Window Length                                               */
 #define WD_PWL_MASK       (0xFFFFul << 8) /**< PWL Mask                     */
 #define WD_PWL(val)       (((val) & 0xFFFFul) << 8) /**< Writing Macro      */

/* PWKEY : Clock access key                                                  */
 #define WD_PWKEY_MASK     (0xFFul << 24)  /**< PWKEY Mask                   */
 #define WD_PWKEY          (0x91ul << 24)  /**< Write Access in PWR Allowed  */


/******************************************************************************
* CTR : WD Counter Test Register
******************************************************************************/
 #define WD_COUNT_MASK     (0xFFFFul << 0) /**< Counter Mask                 */
 #define WD_RESET          (0x01ul << 16)  /**< Watchdog Counter Resetting   */


/******************************************************************************
****************************** WD Registers mask ******************************
******************************************************************************/
 #define WD_ECR_MASK         (0x80000000ul)    /**< ECR mask                 */
 #define WD_DCR_MASK         (0x80000000ul)    /**< DCR mask                 */
 #define WD_PMSR_MASK        (0xBFFFFFF0ul)    /**< PMSR mask                */
 #define WD_CR_MASK          (0x0000FFFFul)    /**< CR mask                  */
 #define WD_MR_MASK          (0xFFFFFF07ul)    /**< MR mask                  */
 #define WD_OMR_MASK         (0x0000FFF3ul)    /**< OMR mask                 */
 #define WD_CSR_MASK         (0x00000003ul)    /**< CSR mask                 */
 #define WD_SR_MASK          (0x00000303ul)    /**< SR mask                  */
 #define WD_IER_MASK         (0x00000003ul)    /**< IER mask                 */
 #define WD_IDR_MASK         (0x00000003ul)    /**< IDR mask                 */
 #define WD_IMR_MASK         (0x00000003ul)    /**< IMR mask                 */
 #define WD_PWR_MASK         (0xFFFFFF01ul)    /**< PWR mask                 */
 #define WD_CTR_MASK         (0x0000FFFFul)    /**< CTR mask                 */                   

/******************************************************************************
************************** WD Registers reset value* **************************
******************************************************************************/
 #define WD_PMSR_RST   (IPIDCODE_WATCHDOG0)    /**< PMSR reset value         */
 #define WD_MR_RST           (0x0007FF00ul)    /**< MR reset value           */
 #define WD_OMR_RST          (0x00000000ul)    /**< OMR reset value          */
 #define WD_SR_RST           (0x00000101ul)    /**< SR reset value           */
 #define WD_IMR_RST          (0x00000000ul)    /**< IMR reset value          */
 #define WD_PWR_RST          (0x0007FF00ul)    /**< PWR reset value          */
 #define WD_CTR_RST          (0x000007FFul)    /**< CTR reset value          */                   


/******************************************************************************
**************************** WD Macros Definition *****************************
******************************************************************************/
/* ECR, DCR, PMSR : WD Power Management Registers                            */
/** Set ECR register (Enable)                                                */
 #define CSP_WD_SET_ECR(wd, val)     ((wd)->ECR = (val))
/** Set DCR register (Disable)                                               */
 #define CSP_WD_SET_DCR(wd, val)     ((wd)->DCR = (val))
/** Get PMSR register (Status)                                               */
 #define CSP_WD_GET_PMSR(wd)         ((wd)->PMSR)

/* CR : WD Control Register                                                  */
/** Set CR register                                                          */
 #define CSP_WD_SET_CR(wd)           ((wd)->CR = (WD_RSTKEY))

/* MR : WD Mode Register                                                     */
/** Get MR register                                                          */
 #define CSP_WD_GET_MR(wd)           ((wd)->MR)
/** Set MR register                                                          */
 #define CSP_WD_SET_MR(wd, mode)     ((wd)->MR = (mode | WD_CKEY))

/* OMR : WD Overflow Mode Register                                           */
/** Get OMR register                                                         */
 #define CSP_WD_GET_OMR(wd)          ((wd)->OMR)
/** Set OMR register                                                         */
 #define CSP_WD_SET_OMR(wd, val)     ((wd)->OMR = (val | WD_OKEY))

/* CSR, SR : WD Status Registers                                             */
/** Set CSR register (Clear)                                                 */
 #define CSP_WD_SET_CSR(wd, val)     ((wd)->CSR = (val))
/** Get SR register (Status)                                                 */
 #define CSP_WD_GET_SR(wd)           ((wd)->SR)

/* IER, IDR, IMR : WD Interrupt Registers                                    */
/** Set IER register (Enable)                                                */
 #define CSP_WD_SET_IER(wd, val)     ((wd)->IER = (val))
/** Set IDR register (Disable)                                               */
 #define CSP_WD_SET_IDR(wd, val)     ((wd)->IDR = (val))
/** Get IMR register (Status)                                                */
 #define CSP_WD_GET_IMR(wd)          ((wd)->IMR)

/* PWR : WD Pending Window Register                                          */
/** Get PWR register                                                         */
 #define CSP_WD_GET_PWR(wd)          ((wd)->PWR)
/** Set PWR register                                                         */
 #define CSP_WD_SET_PWR(wd, mode)    ((wd)->PWR = (mode | WD_PWKEY))
/* CTR : WD Counter Test Register                                            */
/** Get CTR register                                                         */
 #define CSP_WD_GET_CTR(wd)          ((wd)->CTR)


/******************************************************************************
********************** WD External Functions Declaration **********************
******************************************************************************/
extern void CSP_WDInit(CSP_WD_T *const wd, 
                       U32_T mode_u32, 
                       U32_T overflowMode_u32, 
                       U32_T pendingMode_u32);
extern void CSP_WDConfigInterrupt(CSP_WD_T *const wd, 
                                  U32_T intMode_u32, 
                                  U32_T intMask_u32, 
                                  U32_T callback_u32);
extern void CSP_WDEnable(CSP_WD_T *const wd);
extern void CSP_WDDisable(CSP_WD_T *const wd);
extern void CSP_WDCounterRestart(CSP_WD_T *const wd);


#endif   /* CSP_WD_H */

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
* @file name	csp_stt.h
* @description	Definitions, Macros and function declarations 
*            	for STT module
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
*		STT/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 



#ifndef CSP_STT_H
#define CSP_STT_H


/******************************************************************************
************************* STT Structure Definition *****************************
******************************************************************************/
/**
*******************************************************************************
@brief STT Structure
*******************************************************************************
*/
 typedef struct
 { 
    CSP_REGISTER_T  ReservedA[20];   /**< Reserved                           */
    CSP_REGISTER_T  ECR;             /**< Enable Clock Register              */
    CSP_REGISTER_T  DCR;             /**< Disable Clock Register             */
    CSP_REGISTER_T  PMSR;            /**< Power Management Status Register   */
    CSP_REGISTER_T  ReservedB;       /**< Reserved                           */
    CSP_REGISTER_T  CR;              /**< Control Register                   */
    CSP_REGISTER_T  MR;              /**< Mode Register                      */
    CSP_REGISTER_T  ReservedC;       /**< Reserved                           */
    CSP_REGISTER_T  CSR;             /**< Clear Status Register              */
    CSP_REGISTER_T  SR;              /**< Status Register                    */
    CSP_REGISTER_T  IER;             /**< Interrupt Enable Register          */
    CSP_REGISTER_T  IDR;             /**< Interrupt Disable Register         */
    CSP_REGISTER_T  IMR;             /**< Interrupt Mask Register            */
    CSP_REGISTER_T  CNTR;            /**< Counter Register                   */
    CSP_REGISTER_T  ALR;             /**< Alarm Register                     */
 } CSP_STT_T, *CSP_STT_PTR;


/******************************************************************************
************************** STT Registers Definition ***************************
******************************************************************************/

/******************************************************************************
* ECR, DCR, PMSR : STT Power Management Registers
******************************************************************************/
 #define STT_DBGEN        (0x01ul << 31) /* Debug Mode Enable                */

/******************************************************************************
* CR, CSR, SR, IER, IDR, IMR
******************************************************************************/
 #define STT_CNTEN        (0x01ul << 1)  /**< Counter Enable                 */
 #define STT_CNTDIS       (0x01ul << 2)  /**< Counter Disable                */
 #define STT_ALARMEN      (0x01ul << 3)  /**< Alarm Enable                   */
 #define STT_ALARMDIS     (0x01ul << 4)  /**< Alarm Disable                  */

/* CR Register Only                                                          */
 #define STT_SWRST        (0x01ul << 0)  /**< Software Reset                 */

/* CSR, SR, IER, IDR, IMR Registers only                                     */
 #define STT_ALARM        (0x01ul << 0)  /**< Alarm Interrupt                */

/* SR Register Only                                                          */
 #define STT_WCNT         (0x01ul << 5)  /**< Write Counter                  */
 #define STT_CNTENS       (0x01ul << 8)  /**< Counter Enable Status          */
 #define STT_ALARMENS     (0x01ul << 9)  /**< Alarm Enable Status            */

/******************************************************************************
* MR : STT Mode Register
******************************************************************************/
 #define STT_CNTRST       (0x01ul << 0)  /**< Counter Reset Mask             */
 #define STT_CNTRST_A8B   (0x00ul << 0)  /**< Counter Reset after 0xA8BFFFFF */ 
 #define STT_CNTRST_FFF   (0x01ul << 0)  /**< Counter Reset after 0xFFFFFFFF */

/******************************************************************************
***************************** STT Registers mask ******************************
******************************************************************************/
 #define STT_ECR_MASK         (0x80000000ul)  /**< ECR mask                  */
 #define STT_DCR_MASK         (0x80000000ul)  /**< DCR mask                  */
 #define STT_PMSR_MASK        (0xBFFFFFF0ul)  /**< PMSR mask                 */
 #define STT_CR_MASK          (0x0000001Ful)  /**< CR mask                   */
 #define STT_MR_MASK          (0x00000001ul)  /**< MR mask                   */
 #define STT_CSR_MASK         (0x0000001Ful)  /**< CSR mask                  */
 #define STT_SR_MASK          (0x0000033Ful)  /**< SR mask                   */
 #define STT_IER_MASK         (0x0000001Ful)  /**< IER mask                  */
 #define STT_IDR_MASK         (0x0000001Ful)  /**< IDR mask                  */
 #define STT_IMR_MASK         (0x0000001Ful)  /**< IMR mask                  */
 #define STT_CNTR_MASK        (0xFFFFFFFFul)  /**< CTNR mask                 */
 #define STT_ALR_MASK         (0xFFFFFFFFul)  /**< ALR mask                  */

/******************************************************************************
*************************** STT Registers reset value *************************
******************************************************************************/
 #define STT_MR_RST            (0x00000000ul)  /**< MR reset value              */
 #define STT_SR_RST         (0x00000000ul)  /**< SR reset value              */
 #define STT_IMR_RST        (0x00000000ul)  /**< IMR reset value             */
 #define STT_CNTR_RST       (0x00000000ul)  /**< CNTR reset value            */
 #define STT_ALR_RST        (0x00000000ul)  /**< ALR reset value             */


/******************************************************************************
**************************** STT Macros Definition ****************************
******************************************************************************/
/* ECR, DCR, PMSR : STT Power Management Registers                           */
/** Set ECR register (Enable)                                                */
 #define CSP_STT_SET_ECR(stt, val)        ((stt)->ECR = (val)) 
/** Set DCR register (Disable)                                               */
 #define CSP_STT_SET_DCR(stt, val)        ((stt)->DCR = (val))
/** Get PMSR register (Status)                                               */
 #define CSP_STT_GET_PMSR(stt)            ((stt)->PMSR)

/** CR : STT Control Register                                                */
 #define CSP_STT_SET_CR(stt, val)         ((stt)->CR = (val))

/* MR : STT Mode Register                                                    */
/** Get MR register (Mode Register)                                          */
 #define CSP_STT_GET_MR(stt)              ((stt)->MR)          
/** Set MR register (Mode Register)                                          */
 #define CSP_STT_SET_MR(stt, mode)        ((stt)->MR = (mode))

/* CSR, SR : STT Status Registers                                            */
/** Set CSR register (Clear Status Register)                                 */
 #define CSP_STT_SET_CSR(stt, val)        ((stt)->CSR = (val))
/** Get SR register (Status Register)                                        */
 #define CSP_STT_GET_SR(stt)              ((stt)->SR)
                                       
/* IER, IDR, IMR : STT Interrupt Registers                                   */
/** Set IER register (Enable Interrupt)                                      */
 #define CSP_STT_SET_IER(stt, val)        ((stt)->IER = (val))
/** Set IDR register (Disable Interrupt)                                     */
 #define CSP_STT_SET_IDR(stt, val)        ((stt)->IDR = (val))
/** Get IMR register (Status Interrupt)                                      */
 #define CSP_STT_GET_IMR(stt)             ((stt)->IMR)

/* CNTR : STT Counter Register                                               */
 #define CSP_STT_GET_CNTR(stt)            ((stt)->CNTR)
 #define CSP_STT_SET_CNTR(stt, count)     ((stt)->CNTR = (count))

/* ALR : STT Alarm Register                                                  */
 #define CSP_STT_GET_ALR(stt)             ((stt)->ALR)
 #define CSP_STT_SET_ALR(stt, val)        ((stt)->ALR = (val))


/******************************************************************************
********************** STT External Functions Declaration **********************
******************************************************************************/
extern void  CSP_STTInit(CSP_STT_T *const stt, U32_T mode_u32);
extern void  CSP_STTConfigInterrupt(CSP_STT_T *const stt, 
                                    U32_T intMode_u32, 
                                    U32_T intMask_u32,
                                    U32_T callback_u32);
extern U32_T CSP_STTGetTime (CSP_STT_T *const stt);
extern void  CSP_STTSetTime (CSP_STT_T *const stt, U32_T time_u32);
extern U32_T CSP_STTGetAlarm(CSP_STT_T *const stt);
extern void  CSP_STTSetAlarm (CSP_STT_T *const stt, U32_T alarm_u32);
extern void  CSP_STTEnable(CSP_STT_T *const stt, U8_T enableMask_u8);
extern void  CSP_STTDisable(CSP_STT_T *const stt, U8_T disableMask_u8);


#endif   /* CSP_STT_H */

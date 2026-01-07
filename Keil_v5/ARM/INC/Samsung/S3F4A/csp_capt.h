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
* @file name	csp_capt.h
* @description	Definitions, Macros and function declarations 
*           	for Capture module
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
*		CAPT/ /S3F4A0K/AGP1 EVB Rev1.0
*/

#ifndef _CSP_CAPT_H
#define _CSP_CAPT_H

/*******************************************************************************
***********************   CAPTURE STRUCTURE DEFINITION   ***********************
*******************************************************************************/
typedef struct
{
	CSP_REGISTER_T	ReservedA[20];     
    CSP_REGISTER_T  ECR;                  /* Enable Clock Register           */
    CSP_REGISTER_T  DCR;                  /* Disable Clock Register          */
    CSP_REGISTER_T  PMSR;                 /* Power Management Status Register*/
    CSP_REGISTER_T  ReservedB;     
    CSP_REGISTER_T  CR;                   /* Control Register                */
    CSP_REGISTER_T  MR;                   /* Mode Register                   */
    CSP_REGISTER_T  ReservedC;     
    CSP_REGISTER_T  CSR;                  /* Clear Status Register           */
    CSP_REGISTER_T  SR;                   /* Status Register                 */
    CSP_REGISTER_T  IER;                  /* Interrupt enable Register       */
    CSP_REGISTER_T  IDR;                  /* Interrupt Disable Register      */
    CSP_REGISTER_T  IMR;                  /* Interrupt Mask Register         */
    CSP_REGISTER_T  DR;                   /* Capture Data Register           */
}CSP_CAPT_T, *CSP_CAPT_PTR;

/*******************************************************************************
**********************   CAPTURE REGISTERS DEFINITION   ************************
*******************************************************************************/	

/*******************************************************************************
* ECR, DCR, PMSR : CAPTURE Power Management Registers
*******************************************************************************/
#define CAPT_CAP				(0x01ul << 1)      	/**< CAPTURE Clock         */
#define CAPT_IPIDCODE_MASK   	(0x3FFFFFFul << 4)	/**< CAPTURE IPIDCODE MASK */
#define CAPT_DBGEN           	(0x01ul << 31)    	/**< Debug Mode Enable     */

/*******************************************************************************
* CR : CAPTURE Control Register 
*******************************************************************************/
#define CAPT_SWRST  			(0x01ul << 0) 	/**< CAPTURE Software Reset  */
#define CAPT_CAPEN            	(0x01ul << 1)  	/**< CAPTURE Enable          */
#define CAPT_CAPDIS           	(0x01ul << 2)  	/**< CAPTURE Disable         */
#define CAPT_STARTCAP         	(0x01ul << 3)  	/**< Start Capture           */

/*******************************************************************************
* MR : CAPTURE Mode Register
*******************************************************************************/
/* PRESCALAR : Counter Clock Prescalar                                       */
#define CAPT_PRESCALAR_MASK		(0x0Ful << 0)            /**< Mask            */
#define CAPT_PRESCALAR(val)  	(((val) & 0x0Ful) << 0)  /**< Writing Macro   */

#define CAPT_MEASMODE_MASK   	(0x03ul << 4)            /**< Measure mask    */
#define CAPT_MEASMODE(val)   	(((val) & 0x03) << 4)    /**< Writing macro   */
#define CAPT_MEASMODE_POS_NEG	((0x00ul) << 4)  /**< Measure Between Positive*/
                                                /*   and Negative Edge       */
#define CAPT_MEASMODE_POS 		((0x02ul) << 4)  /**< Meas. Between Pos. Edge */
#define CAPT_MEASMODE_NEG     ((0x03ul) << 4)  /**< Meas. Between Neg. Edge */
#define CAPT_OVERMODE        	(0x01ul << 6)    /**< Overrun Mode            */
#define CAPT_ONESHOT          	(0x01ul << 7)    /**< One Shot                */

/*******************************************************************************
* CSR, SR, IER, IDR, IMR : CAPTURE Status and Interrupt Registers 
*******************************************************************************/
#define CAPT_OVERRUN			(0x01ul << 1)  /**< Over Run                */
#define CAPT_OVERFLOW        	(0x01ul << 2)  /**< Over Flow               */

/* SR, IER, IDR, IMR Registers only                                          */
#define CAPT_DATACAPT         	(0x01ul << 3)  /**< Data Captured           */

/* SR Register Only                                                          */
#define CAPT_CAPENS           	(0x01ul << 8)  /**< Capture Enable Status   */

/******************************************************************************
* DR : CAPTURE Data Register
******************************************************************************/
/* DURATION : CAPTURE duration                                               */
#define CAPT_DURATION_MASK  	(0x7FFFul << 0)            /**< Mask         */
#define CAPT_DURATION(val)    (((val) & 0x7FFFul) << 0)  /**< Writing Macro*/

/* LEVEL : Level Measured                                                    */
#define CAPT_LEVEL          	(0x01ul << 15) /**< LEVEL Mask                 */
#define CAPT_LEVEL_HIGH      	(0x01ul << 15) /**< Duration High Level        */
#define CAPT_LEVEL_LOW       	(0x00ul << 15) /**< Duration Low Level         */

/*******************************************************************************
****************************  CAPTURE REGISTER MASK  ***************************
*******************************************************************************/
#define CAPT_ECR_MASK			(0x80000002ul)    /**< ECR mask              */
#define CAPT_DCR_MASK         	(0x80000002ul)    /**< DCR mask              */
#define CAPT_PMSR_MASK        	(0xBFFFFFF2ul)    /**< PMSR mask             */
#define CAPT_CR_MASK          	(0x0000000Ful)    /**< CR mask               */
#define CAPT_MR_MASK          	(0x000000FFul)    /**< MR mask               */
#define CAPT_CSR_MASK        	(0x00000006ul)    /**< CSR mask              */
#define CAPT_SR_MASK          	(0x0000010Eul)    /**< SR mask               */
#define CAPT_IER_MASK        	(0x0000000Eul)    /**< IER mask              */
#define CAPT_IDR_MASK         	(0x0000000Eul)    /**< IDR mask              */
#define CAPT_IMR_MASK        	(0x0000000Eul)    /**< IMR mask              */
#define CAPT_DR_MASK          	(0x0000FFFFul)    /**< DR mask               */
                   
/*******************************************************************************
*************************  CAPTURE REGISTERS RESET VALUE  **********************
*******************************************************************************/
#define CAPT_ECR_RST			(0x00000000ul)    	/**< ECR reset value     */
#define CAPT_DCR_RST          	(0x00000000ul)    	/**< DCR reset value     */
#define CAPT_PMSR_RST    		(IPIDCODE_CAPTURE0)	/**< PMSR reset value    */
#define CAPT_CR_RST           	(0x00000000ul)    	/**< CR reset value      */
#define CAPT_MR_RST           	(0x00000000ul)    	/**< MR reset value      */
#define CAPT_CSR_RST          	(0x00000000ul)    	/**< CSR reset value     */
#define CAPT_SR_RST           	(0x00000000ul)    	/**< SR reset value      */
#define CAPT_IER_RST          	(0x00000000ul)    	/**< IER reset value     */
#define CAPT_IDR_RST          	(0x00000000ul)    	/**< IDR reset value     */
#define CAPT_IMR_RST          	(0x00000000ul)    	/**< IMR reset value     */
#define CAPT_DR_RST           	(0x00000000ul)    	/**< DR reset value      */

/*******************************************************************************
**************************  CAPTURE MACROS DEFINITION  *************************
*******************************************************************************/
/* ECR, DCR, PMSR : CAPTURE Power Management Registers                       */
/** Set ECR register (Enable)                                                */
#define CSP_CAPT_SET_ECR(capt, val)			((capt)->ECR = (val))
/** Set DCR register (Disable)                                               */
#define CSP_CAPT_SET_DCR(capt, val) 		((capt)->DCR = (val))
/** Get PMSR register (status)                                               */
#define CSP_CAPT_GET_PMSR(capt)     		((capt)->PMSR)

/* CR : CAPTURE Control Register                                             */
/** Set CR register                                                          */
#define CSP_CAPT_SET_CR(capt, val)			((capt)->CR = (val))

/* MR : CAPTURE Mode Register                                                */
/** Get MR register                                                          */
#define CSP_CAPT_GET_MR(capt)            	((capt)->MR)
/** Set MR register                                                          */
#define CSP_CAPT_SET_MR(capt, mode)      ((capt)->MR = (mode))

/* CSR, SR : CAPTURE Status Registers                                        */
/** Set CSR register (Clear)                                                 */
#define CSP_CAPT_SET_CSR(capt, val)      ((capt)->CSR = (val)) 
/** Get SR register (Status)                                                 */
#define CSP_CAPT_GET_SR(capt)            	((capt)->SR)

/* IER, IDR, IMR : CAPTURE Interrupt Registers                               */
/** Set IER register (Enable)                                                */
#define CSP_CAPT_SET_IER(capt, val)      ((capt)->IER = (val))
/** Set IDR register (Disable)                                               */
#define CSP_CAPT_SET_IDR(capt, val)     	((capt)->IDR = (val))
/** Get IMR register (Mask)                                                  */
#define CSP_CAPT_GET_IMR(capt)           	((capt)->IMR)

/* DR : CAPTURE Data Register                                                */
/** Get DR register                                                          */
#define CSP_CAPT_GET_DR(capt)            	((capt)->DR)

/*******************************************************************************
***********************   CAPTURE  EXTERNAL FUNCTIONS   ************************
*******************************************************************************/
extern void CSP_CAPTInit(CSP_CAPT_T *const capt, U32_T mode);
extern void CSP_CAPTClose(CSP_CAPT_T *const capt);
extern void CSP_CAPTConfigInterrupt(CSP_CAPT_T *const capt, 
                                    	U32_T intMode_u32, 
                                    	U32_T intMask_u32, 
                                    	U32_T callback_u32);
extern void CSP_CAPTInitRxLdmaChannel(CSP_CAPT_T *const capt, 
                                          	U32_T mode_u32, 
                                            U8_T channel_u8);
extern void CSP_CAPTEnable(CSP_CAPT_T *const capt);
extern void CSP_CAPTDisable(CSP_CAPT_T *const capt);
extern void CSP_CAPTStart(CSP_CAPT_T *const capt);

#endif   /*_CSP_CAPT_H */

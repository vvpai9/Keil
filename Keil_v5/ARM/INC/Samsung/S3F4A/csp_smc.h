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
* @file name	csp_smc.h
* @description	Definitions, Macros and function declarations 
*            	for SMC module
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
*		SMC/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 




#ifndef CSP_SMC_H
#define CSP_SMC_H


/******************************************************************************
************************** SMC Structure Definition ***************************
******************************************************************************/
/** Number of SMC channel                                                    */
 #define NB_SMC_CH     2u


/**
*******************************************************************************
@brief SMC Channel Structure
*******************************************************************************
*/
 typedef struct
 {   
    CSP_REGISTER_T     DLY;        /**< Delay Register                       */
    CSP_REGISTER_T     PUL;        /**< Pulse Register                       */
 } CSP_SMC_CH_T;


/**
*******************************************************************************
@brief SMC Structure
*******************************************************************************
*/
 typedef struct
 { 
    CSP_REGISTER_T     ReservedA[20]; 
    CSP_REGISTER_T     ECR;          /**< Enable Clock Register              */
    CSP_REGISTER_T     DCR;          /**< Disable Clock Register             */
    CSP_REGISTER_T     PMSR;         /**< Power Management Status Register   */
    CSP_REGISTER_T     ReservedB;      
    CSP_REGISTER_T     CR;           /**< Control Register                   */
    CSP_REGISTER_T     MR;           /**< Mode Register                      */
    CSP_REGISTER_T     ReservedC;      
    CSP_REGISTER_T     CSR;          /**< Clear Status Register              */
    CSP_REGISTER_T     SR;           /**< Status Register                    */
    CSP_REGISTER_T     IER;          /**< Interrupt Enable Register          */
    CSP_REGISTER_T     IDR;          /**< Interrupt Disable Register         */
    CSP_REGISTER_T     IMR;          /**< Interrupt Mask Register            */
    CSP_SMC_CH_T       CH[NB_SMC_CH];/**< SMC channel                        */
    CSP_REGISTER_T     ReservedD[2];      
    CSP_REGISTER_T     TPR;          /**< Target Position Register           */
    CSP_REGISTER_T     CPR;          /**< Current Position Register          */
 } CSP_SMC_T, *CSP_SMC_PTR;



/******************************************************************************
************************** SMC Registers Definition ***************************
******************************************************************************/

/******************************************************************************
* ECR, DCR, PMSR : SMC Power Management Registers
******************************************************************************/
 #define SMC_SMC      (0x01ul << 1)            /**< SMC Clock                */
 #define SMC_DBGEN    (0x01ul << 31)           /**< Debug Mode Enable        */


/******************************************************************************
* CR : SMC Control Register
******************************************************************************/
 #define SMC_SWRST    (0x01ul << 0)          /**< SMC Software Reset         */  
 #define SMC_SMCEN    (0x01ul << 1)          /**< SMC Enable                 */ 
 #define SMC_SMCDIS   (0x01ul << 2)          /**< SMC Disable                */ 
 #define SMC_MSTT     (0x01ul << 4)          /**< Motor Start                */ 
 #define SMC_MSTP     (0x01ul << 5)          /**< Motor Stop                 */
 #define SMC_PWMSTT0  (0x01ul << 8)          /**< Start PWM channel 0        */
 #define SMC_PWMSTP0  (0x01ul << 9)          /**< Stop  PWM channel 0        */
 #define SMC_PWMSTT1  (0x01ul << 10)         /**< Start PWM channel 1        */
 #define SMC_PWMSTP1  (0x01ul << 11)         /**< Stop  PWM channel 1        */ 


/******************************************************************************
* MR : SMC Mode Register
******************************************************************************/
/** PRESCAL : Clock Prescalar                                                */
 #define SMC_PRESCAL_MASK  (0x1Ful << 0)            /**< Mask                */
 #define SMC_PRESCAL(val)  (((val) & 0x1Ful) << 0)  /**< Writing Macro       */

 #define SMC_CONT          (0x01ul << 6)            /**< Continuous Mode     */
 #define SMC_SMCFM         (0x01ul << 7)            /**< SMC Functional Mode */

/** SDIV : Sub Clock Divider                                                 */
 #define SMC_SDIV_MASK     (0xFFul << 8)            /**< Mask                */
 #define SMC_SDIV(val)     (((val) & 0xFFul) << 8)  /**< Writing Macro       */

/** NCM : Number of PWM Cycles by Microstep                                  */
 #define SMC_NCM_MASK      (0x7ul << 16)            /**< Mask                */
 #define SMC_NCM(val)      (((val) & 0x7ul) << 16)  /**< Writing Macro       */

/** NMSQ : Number of Microstep by Sinusoid Quarter                           */
 #define SMC_NMSQ_MASK     (0x3ul << 19)            /**< Mask                */
 #define SMC_NMSQ(val)     (((val) & 0x3ul) << 19)  /**< Writing Macro       */

/** DM : Driving Method                                                      */
 #define SMC_DM_MASK       (0x7ul << 21)            /**< Mask                */
 #define SMC_DM(val)       (((val) & 0x7ul) << 21)  /**< Writing Macro       */

 #define SMC_PL0           (0x1ul << 30)            /**< Pulse on channel 0  */
 #define SMC_PL1           (0x1ul << 31)            /**< Pulse on channel 1  */


/******************************************************************************
* CSR, SR, IER, IDR, IMR : SMC Status and Interrupt Registers
******************************************************************************/
 #define SMC_PSTA0        (0x01ul << 0)  /**< Pulse Start Interrupt Channel 0*/
 #define SMC_PEND0        (0x01ul << 1)  /**< Pulse End Interrupt Channel 0  */
 #define SMC_PSTA1        (0x01ul << 2)  /**< Pulse Start Interrupt Channel 1*/
 #define SMC_PEND1        (0x01ul << 3)  /**< Pulse End Interrupt Channel 1  */
 #define SMC_PR           (0x01ul << 9)  /**< Position Reached Interrupt     */
 #define SMC_CPO          (0x01ul << 10) /**< Current Position Overflow Int. */

/** SR Register Only                                                         */
 #define SMC_SMCENS       (0x01ul << 16) /**< SMC enable status              */


/******************************************************************************
* DLY : SMC Channel X Delay Register
******************************************************************************/
/** DELAY : Delay width                                                      */
 #define SMC_DELAY_MASK   (0xFFul << 0)             /**< Mask                */
 #define SMC_DELAY(val)   (((val) & 0xFFul) << 0)   /**< Writing Macro       */


/******************************************************************************
* PUL : SMC Channel X Pulse Register
******************************************************************************/
/** PULSE : Pulse width                                                      */
 #define SMC_PULSE_MASK   (0xFFul << 0)             /**< Mask                */
 #define SMC_PULSE(val)   (((val) & 0xFFul) << 0)   /**< Writing Macro       */


/******************************************************************************
* TPR : SMC Target Position Register
******************************************************************************/
/** RP : Requested Position                                                  */
 #define SMC_RP_MASK      (0x7FFFul << 0)           /**< Mask                */
 #define SMC_RP(val)      (((val) & 0x7FFFul) << 0) /**< Writing Macro       */

 #define SMC_DIR_SIGN     (0x01ul << 15)            /**< Direction or Sign   */


/******************************************************************************
* CPR : SMC Current Position Register
******************************************************************************/
/** CP : Current Position                                                    */
 #define SMC_CP_MASK      (0x7FFFul << 0)           /**< Mask                */

 #define SMC_NEG          (0x01ul << 15)            /**< Negative Position   */


/******************************************************************************
***************************** SMC Registers mask ******************************
******************************************************************************/
 #define SMC_ECR_MASK     (0x80000002ul)         /**< ECR mask               */
 #define SMC_DCR_MASK     (0x80000002ul)         /**< DCR mask               */
 #define SMC_PMSR_MASK    (0xBFFFFFF2ul)         /**< PMSR mask              */
 #define SMC_CR_MASK      (0x00000F37ul)         /**< CR mask                */
 #define SMC_MR_MASK      (0xC0FFFFDFul)         /**< MR mask                */
 #define SMC_CSR_MASK     (0x0000060Ful)         /**< CSR mask               */
 #define SMC_SR_MASK      (0x0000070Ful)         /**< SR mask                */
 #define SMC_IER_MASK     (0x0000060Ful)         /**< IER mask               */
 #define SMC_IDR_MASK     (0x0000060Ful)         /**< IDR mask               */
 #define SMC_IMR_MASK     (0x0000060Ful)         /**< IMR mask               */
 #define SMC_DLYX_MASK    (0x000000FFul)         /**< DLYX mask              */
 #define SMC_PULX_MASK    (0x000000FFul)         /**< PULX mask              */
 #define SMC_TPR_MASK     (0x0000FFFFul)         /**< TPR mask               */
 #define SMC_CPR_MASK     (0x0000FFFFul)         /**< CPR mask               */


/******************************************************************************
************************* SMC Registers reset value ***************************
******************************************************************************/
 #define SMC_ECR_RST      (0x00000000ul)        /**< ECR reset value         */
 #define SMC_DCR_RST      (0x00000000ul)        /**< DCR reset value         */
 #define SMC_PMSR_RST     (IPIDCODE_STEPPER0)   /**< PMSR reset value        */
 #define SMC_CR_RST       (0x00000000ul)        /**< CR reset value          */
 #define SMC_MR_RST       (0xC0000080ul)        /**< MR reset value          */
 #define SMC_CSR_RST      (0x00000000ul)        /**< CSR reset value         */
 #define SMC_SR_RST       (0x00000000ul)        /**< SR reset value          */
 #define SMC_IER_RST      (0x00000000ul)        /**< IER reset value         */
 #define SMC_IDR_RST      (0x00000000ul)        /**< IDR reset value         */
 #define SMC_IMR_RST      (0x00000000ul)        /**< IMR reset value         */
 #define SMC_DLYX_RST     (0x00000000ul)        /**< ISSR reset value        */
 #define SMC_PULX_RST     (0x00000000ul)        /**< SIER reset value        */
 #define SMC_TPR_RST      (0x00000000ul)        /**< SIDR reset value        */
 #define SMC_CPR_RST      (0x00000000ul)        /**< SIMR reset value        */


/******************************************************************************
*************************** SMC Macros Definition *****************************
******************************************************************************/
/* ECR, DCR, PMSR : SMC Power Management Registers                           */
/** Set ECR register (Enable)                                                */
 #define CSP_SMC_SET_ECR(SMC, val)         ((SMC)->ECR = (val))
/** Set DCR register (Disable)                                               */
 #define CSP_SMC_SET_DCR(SMC, val)         ((SMC)->DCR = (val))
/** Get PMSR register (Status)                                               */
 #define CSP_SMC_GET_PMSR(SMC)             ((SMC)->PMSR)

/** CR : SMC Control Register                                                */
 #define CSP_SMC_SET_CR(SMC, val)          ((SMC)->CR = (val))

/* MR : SMC Mode Register                                                    */
/** Get MR register (Mode Register)                                          */
 #define CSP_SMC_GET_MR(SMC)               ((SMC)->MR)
/** Set MR register (Mode Register)                                          */
 #define CSP_SMC_SET_MR(SMC, mode)         ((SMC)->MR = (mode))

/* CSR, SR : SMC Status Register                                             */
/** Set CSR register (Clear Status Register)                                 */
 #define CSP_SMC_SET_CSR(SMC, val)         ((SMC)->CSR = (val))
/** Get SR register (Status Register)                                        */
 #define CSP_SMC_GET_SR(SMC)               ((SMC)->SR)

/* IER, IDR, IMR : SMC Interrupt Registers                                   */
/** Set IER register (Enable Interrupt)                                      */
 #define CSP_SMC_SET_IER(SMC, val)         ((SMC)->IER = (val))
/** Set IDR register (Disable Interrupt)                                     */
 #define CSP_SMC_SET_IDR(SMC, val)         ((SMC)->IDR = (val))
/** Get IMR register (Status Interrupt)                                      */
 #define CSP_SMC_GET_IMR(SMC)              ((SMC)->IMR)

/* DLY : SMC Channel X Delay Register                                        */
/** Get DLY register                                                         */
 #define CSP_SMC_CH_GET_DLY(SMC, channel)  ((SMC)->CH[(channel)].DLY)
/** Set DLY register                                                         */
 #define CSP_SMC_CH_SET_DLY(SMC, channel, val)                              \
                                          ((SMC)->CH[(channel)].DLY = (val))

/* PUL : SMC Channel X Pulse Register                                        */
/** Get PUL register                                                         */
 #define CSP_SMC_CH_GET_PUL(SMC, channel)  ((SMC)->CH[(channel)].PUL)
/** Set PUL register                                                         */
 #define CSP_SMC_CH_SET_PUL(SMC, channel, val)                              \
                                          ((SMC)->CH[(channel)].PUL = (val))
 
/* TPR : SMC Target Position Register                                        */
/** Get TPR register                                                         */
 #define CSP_SMC_GET_TPR(SMC)              ((SMC)->TPR)
/** Set TPR register                                                         */
 #define CSP_SMC_SET_TPR(SMC, val)         ((SMC)->TPR = (val))

/* CPR : SMC Current Position Register                                       */
/** Get CPR register                                                         */
 #define CSP_SMC_GET_CPR(SMC)              ((SMC)->CPR)
/** Set CPR register                                                         */
 #define CSP_SMC_SET_CPR(SMC, val)         ((SMC)->CPR = (val))


/******************************************************************************
********************* SMC External Functions Declaration **********************
******************************************************************************/
extern void CSP_SMCInit(CSP_SMC_T *const SMC, U32_T mode_u32);
extern void CSP_SMCClose(CSP_SMC_T *const SMC);
extern void CSP_SMCConfigInterrupt(CSP_SMC_T *const SMC, 
                                   U32_T intMode_u32, 
                                   U32_T intMask_u32, 
                                   U32_T callback_u32);
extern void CSP_SMCEnable(CSP_SMC_T *const SMC);
extern void CSP_SMCDisable(CSP_SMC_T *const SMC);

#endif   /* CSP_SMC_H */

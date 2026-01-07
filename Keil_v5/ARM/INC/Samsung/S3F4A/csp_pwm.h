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
* @file name	csp_pwm.h
* @description	Definitions, Macros and function declarations 
*            	for Pulse Width Modulation module
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
*		PWM/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 

#ifndef CSP_PWM_H
#define CSP_PWM_H


/******************************************************************************
************************** PWM Structure Definition ***************************
******************************************************************************/

/**
*******************************************************************************
@brief PWM Channel Structure
*******************************************************************************
*/
 typedef struct
 {
    CSP_REGISTER_T  DLY;             /**< Delay Register                      */
    CSP_REGISTER_T  PUL;             /**< Pulse Register                      */
 } CSP_PWM_CHANNEL_T, *CSP_PWM_CHANNEL_PTR;


/**
*******************************************************************************
@brief PWM Structure
*******************************************************************************
*/
typedef struct                  
{
#ifdef PWM_PIO_TAG
   CSP_REGISTER_T     PER;           /**< PIO Enable Register                 */
   CSP_REGISTER_T     PDR;           /**< PIO Disable Register                */
   CSP_REGISTER_T     PSR;           /**< PIO Status Register                 */
   CSP_REGISTER_T     ReservedA;                                                
   CSP_REGISTER_T     OER;           /**< Output Enable Register              */
   CSP_REGISTER_T     ODR;           /**< Output Disable Register             */
   CSP_REGISTER_T     OSR;           /**< Output Status Register              */
   CSP_REGISTER_T     ReservedB;                                               
   CSP_REGISTER_T     SODR;          /**< Set Output Data Register            */
   CSP_REGISTER_T     CODR;          /**< Clear Output Data Register          */
   CSP_REGISTER_T     ODSR;          /**< Output Data Status Register         */
   CSP_REGISTER_T     PDSR;          /**< Pin Data Status Register            */
   CSP_REGISTER_T     MDER;          /**< Multi-Driver Enable Register        */
   CSP_REGISTER_T     MDDR;          /**< Multi-Driver Disable Register       */
   CSP_REGISTER_T     MDSR;          /**< Multi-Driver Status Register        */
   CSP_REGISTER_T     ReservedC;
#else
   CSP_REGISTER_T     ReservedA[20];
#endif   
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
    CSP_PWM_CHANNEL_T  CHANNEL[NB_PWM_CHANNEL];  /**< PWM Channels           */
 } CSP_PWM_T, *CSP_PWM_PTR;

#ifdef PWM_PIO_TAG
/******************************************************************************
* PER, PDR, PSR, OER, ODR, OSR,      :
* SODR, CODR, ODSR, PDSR, MDER, MDDR : PWM PIO Registers, Status Register and 
* MDSR, CR, SR, IER, IDR, IMR        : Interrupt Registers
******************************************************************************/
 #define PWM_PWM0 (0x01ul << 4)         /**< PWM 0 pin                      */
 #define PWM_PWM1 (0x01ul << 12)        /**< PWM 1 pin                      */
 #define PWM_PWM2 (0x01ul << 20)        /**< PWM 2 pin                      */
 #define PWM_PWM3 (0x01ul << 28)        /**< PWM 3 pin                      */
#endif
 
/******************************************************************************
* ECR, DCR, PMSR : PWM Power Management Registers
******************************************************************************/
#ifdef PWM_PIO_TAG
 #define PWM_PIO  (0x01ul << 0)         /**< PIO Clock                      */
#endif
 #define PWM_PWM            (0x01ul << 1)         /**< PWM Clock             */
#ifdef PWM_IPIDCODE_TAG
 #define PWM_IPIDCODE_MASK  (0x3FFFFFFul << 4)    /**< PWM IPIDCODE mask     */
#endif
 #define PWM_DBGEN          (0x01ul << 31)        /**< Debug Mode Enable     */
 
          
/******************************************************************************
* CR : PWM Control Register
******************************************************************************/
 #define PWM_SWRST      (0x01ul << 0)     /**< PWM Software Reset            */
 #define PWM_PWMEN      (0x01ul << 1)     /**< PWM Channel Enable 0          */
 #define PWM_PWMDIS     (0x01ul << 2)     /**< PWM Channel Disable 0         */
 #define PWM_PWMEN0     (0x01ul << 1)     /**< PWM Channel Enable 0          */
 #define PWM_PWMDIS0    (0x01ul << 2)     /**< PWM Channel Disable 0         */
 #define PWM_PWMEN1     (0x01ul << 9)     /**< PWM Channel Enable 1          */
 #define PWM_PWMDIS1    (0x01ul << 10)    /**< PWM Channel Disable 1         */
 #define PWM_PWMEN2     (0x01ul << 17)    /**< PWM Channel Enable 2          */
 #define PWM_PWMDIS2    (0x01ul << 18)    /**< PWM Channel Disable 2         */
 #define PWM_PWMEN3     (0x01ul << 25)    /**< PWM Channel Enable 3          */
 #define PWM_PWMDIS3    (0x01ul << 26)    /**< PWM Channel Disable 3         */

/******************************************************************************
* MR : PWM Mode Register
******************************************************************************/
 #define PWM_PRESCAL_MASK   (0x1Ful << 0) /**< Counter Clock Prescalar       */
 #define PWM_PL             (0x01ul << 5) /**< Pulse Level                   */

 #define PWM_PRESCAL0(val)  (((val) & 0x1Ful) << 0)  /**< Counter Clock prescalar for                                                         Channel 0         */
 #define PWM_PL0            (0x01ul << 5)            /**< Pulse Level for PWM                                                          Channel 0         */
 #define PWM_PRESCAL1(val)  (((val) & 0x1Ful) << 8)  /**< Counter Clock Prescalar for                                                           Channel 1         */
 #define PWM_PL1            (0x01ul << 13)           /**< Pulse Level for PWM         Channel 1         */                                                                                                              
 #define PWM_PRESCAL2(val)  (((val) & 0x1Ful) << 16)  /**< Counter Clock Prescalar for                                                           Channel 2         */
 #define PWM_PL2            (0x01ul << 21)           /**< Pulse Level for PWM                                                         Channel 2         */                                                                                                                    
 #define PWM_PRESCAL3(val)  (((val) & 0x1Ful) << 24)  /**< Counter Clock Prescalar for                                                           Channel 3         */
 #define PWM_PL3            (0x01ul << 29)           /**< Pulse Level for PWM  Channel 3         */                                                           


/******************************************************************************
* CSR, SR, IER, IDR, IMR : PWM Status Register and Interrupt Registers
******************************************************************************/
 #define PWM_PSTA0     (0x01ul << 0)      /**< Pulse Start Channel 0         */
 #define PWM_PEND0     (0x01ul << 1)      /**< Pulse End Channel 0           */
 #define PWM_PSTA1     (0x01ul << 8)      /**< Pulse Start Channel 1         */
 #define PWM_PEND1     (0x01ul << 9)      /**< Pulse End Channel 1           */
 #define PWM_PSTA2     (0x01ul << 16)     /**< Pulse Start Channel 2         */
 #define PWM_PEND2     (0x01ul << 17)     /**< Pulse End Channel 2           */
 #define PWM_PSTA3     (0x01ul << 24)     /**< Pulse Start Channel 3         */
 #define PWM_PEND3     (0x01ul << 25)     /**< Pulse End Channel 3           */

/* SR Register Only                                                          */
 #define PWM_PWMENS0   (0x01ul << 2)      /**< PWM Enable Status of Channel 0*/
 #define PWM_PWMENS1   (0x01ul << 10)     /**< PWM Enable Status of Channel 1*/
 #define PWM_PWMENS2   (0x01ul << 18)     /**< PWM Enable Status of Channel 2*/
 #define PWM_PWMENS3   (0x01ul << 26)     /**< PWM Enable Status of Channel 3*/


/******************************************************************************
* DLY : PWM Delay Register
******************************************************************************/
 #define PWM_DELAY_MASK   (0xFFFFul << 0)            /**< Channel Delay Mask */
 #define PWM_DELAY(val)   (((val) & 0xFFFFul) << 0)  /**< Channel Delay                                                                Writing Macro     */

/******************************************************************************
* PUL : PWM Pulse Register
******************************************************************************/
 #define PWM_PULSE_MASK   (0xFFFFul << 0)    /**< Channel Pulse Width Mask   */
 #define PWM_PULSE(val)   (((val) & 0xFFFFul) << 0)  /**< Channel Pulse                                                                Writing Macro     */
                                                      
/******************************************************************************
***************************** PWM Registers mask ******************************
******************************************************************************/
#ifdef PWM_PIO_TAG
 #define PWM_PER_MASK       	(0x10101010ul)  /**< PER mask                */
 #define PWM_PDR_MASK       	(0x10101010ul)  /**< PDR mask                */
 #define PWM_PSR_MASK       	(0x10101010ul)  /**< PSR mask                */
 #define PWM_OER_MASK       	(0x10101010ul)  /**< OER mask                */
 #define PWM_ODR_MASK       	(0x10101010ul)  /**< ODR mask                */
 #define PWM_OSR_MASK       	(0x10101010ul)  /**< OSR mask                */
 #define PWM_SODR_MASK      	(0x10101010ul)  /**< SODR mask               */
 #define PWM_CODR_MASK      	(0x10101010ul)  /**< CODR mask               */
 #define PWM_ODSR_MASK      	(0x10101010ul)  /**< ODSR mask               */
 #define PWM_PDSR_MASK      	(0x10101010ul)  /**< PDSR mask               */
 #define PWM_MDER_MASK      	(0x10101010ul)  /**< MDER mask               */
 #define PWM_MDDR_MASK      	(0x10101010ul)  /**< MDDR mask               */
 #define PWM_MDSR_MASK      	(0x10101010ul)  /**< MDSR mask               */
 #define PWM_CSR_MASK           (0x13131313ul)  /**< CSR mask                */
 #define PWM_SR_MASK            (0x17171717ul)  /**< SR mask                 */
 #define PWM_IER_MASK           (0x13131313ul)  /**< IER mask                */
 #define PWM_IDR_MASK           (0x13131313ul)  /**< IDR mask                */
 #define PWM_IMR_MASK           (0x13131313ul)  /**< IMR mask                */
#else
 #define PWM_CSR_MASK           (0x03030303ul)  /**< CSR mask                */
 #define PWM_SR_MASK            (0x07070707ul)  /**< SR mask                 */
 #define PWM_IER_MASK           (0x03030303ul)  /**< IER mask                */
 #define PWM_IDR_MASK           (0x03030303ul)  /**< IDR mask                */
 #define PWM_IMR_MASK           (0x03030303ul)  /**< IMR mask                */
#endif
 #define PWM_ECR_MASK           (0x80000002ul)  /**< ECR mask                */
 #define PWM_DCR_MASK           (0x80000002ul)  /**< DCR mask                */
 #define PWM_PMSR_MASK          (0xBFFFFFF2ul)  /**< PMSR mask               */
 #define PWM_CR_MASK            (0x06060607ul)  /**< CR mask                 */
 #define PWM_MR_MASK            (0x3F3F3F3Ful)  /**< MR mask                 */
 #define PWM_DLYX_MASK          (0x0000FFFFul)  /**< DLYx mask               */
 #define PWM_PULX_MASK          (0x0000FFFFul)  /**< PULx mask               */

/******************************************************************************
************************* PWM Registers reset value ***************************
******************************************************************************/
#ifdef PWM_PIO_TAG
 #define PWM_PER_RST            (0x00000000ul)  /**< PER reset value         */
 #define PWM_PDR_RST  		    (0x00000000ul)  /**< PDR reset value         */
 #define PWM_PSR_RST  		    (0x10101010ul)  /**< PSR reset value         */
 #define PWM_OER_RST  		    (0x00000000ul)  /**< OER reset value         */
 #define PWM_ODR_RST  		    (0x00000000ul)  /**< ODR reset value         */
 #define PWM_OSR_RST  		    (0x00000000ul)  /**< OSR reset value         */
 #define PWM_SODR_RST  		    (0x00000000ul)  /**< SODR reset value        */
 #define PWM_CODR_RST  		    (0x00000000ul)  /**< CODR reset value        */
 #define PWM_ODSR_RST  		    (0x00000000ul)  /**< ODSR reset value        */
 #define PWM_PDSR_RST  		    (0x00000000ul)  /**< PDSR reset value        */
 #define PWM_MDER_RST  		    (0x00000000ul)  /**< MDER reset value        */
 #define PWM_MDDR_RST  		    (0x00000000ul)  /**< MDDR reset value        */
 #define PWM_MDSR_RST  		    (0x00000000ul)  /**< MDSR reset value        */
#endif
 #define PWM_ECR_RST            (0x00000000ul)  /**< ECR reset value         */
 #define PWM_DCR_RST            (0x00000000ul)  /**< DCR reset value         */
 #define PWM_PMSR_RST           (IPIDCODE_PWM0) /**< PMSR reset value        */
 #define PWM_CR_RST             (0x00000000ul)  /**< CR reset value          */
 #define PWM_MR_RST             (0x20202020ul)  /**< MR reset value          */
 #define PWM_CSR_RST            (0x00000000ul)  /**< CSR reset value         */
 #define PWM_SR_RST             (0x00000000ul)  /**< SR reset value          */
 #define PWM_IER_RST            (0x00000000ul)  /**< IER reset value         */
 #define PWM_IDR_RST            (0x00000000ul)  /**< IDR reset value         */
 #define PWM_IMR_RST            (0x00000000ul)  /**< IMR reset value         */
 #define PWM_DLYX_RST           (0x00000000ul)  /**< DLYx reset value        */
 #define PWM_PULX_RST           (0x00000000ul)  /**< PULx reset value        */

/******************************************************************************
**************************** PWM Macros Definition ****************************
******************************************************************************/
#ifdef PWM_PIO_TAG
/* PER, PDR, PSR : PWM4C PIO Registers                                       */
/** Set PER register (Enable)                                                */
 #define CSP_PWM_SET_PER(pwm, val)    ((pwm)->PER = (val))
/** Set PDR register (Disable)                                               */
 #define CSP_PWM_SET_PDR(pwm, val)    ((pwm)->PDR = (val))
/** Get PSR register (Status)                                                */
 #define CSP_PWM_GET_PSR(pwm)         ((pwm)->PSR)

/* OER, ODR, OSR : PWM4C Output Registers                                    */
/** Set OER register (Enable)                                                */
 #define CSP_PWM_SET_OER(pwm, val)    ((pwm)->OER = (val))
/** Set ODR register (Disable)                                               */
 #define CSP_PWM_SET_ODR(pwm, val)    ((pwm)->ODR = (val))
/** Get OSR register (Status)                                                */
 #define CSP_PWM_GET_OSR(pwm)         ((pwm)->OSR)

/* SODR, CODR, ODSR, PDSR : PWM4C Output Data Registers                      */
/** Set SODR register (Set)                                                  */
 #define CSP_PWM_SET_SODR(pwm, val)   ((pwm)->SODR = (val))
/** Set CODR register (Clear)                                                */
 #define CSP_PWM_SET_CODR(pwm, val)   ((pwm)->CODR = (val))
/** Get ODSR register (Status)                                               */
 #define CSP_PWM_GET_ODSR(pwm)        ((pwm)->ODSR)
/** Get PDSR register (Pin Status)                                           */
 #define CSP_PWM_GET_PDSR(pwm)        ((pwm)->PDSR)

/* MDER, MDDR, MDSR : PWM4C Multi-Driver Registers                           */
/** Set MDER register (Enable)                                               */
 #define CSP_PWM_SET_MDER(pwm, val)   ((pwm)->MDER = (val))
/** Set MDDR register (Disable)                                              */
 #define CSP_PWM_SET_MDDR(pwm, val)   ((pwm)->MDDR = (val))
/** Get MDSR register (Status)                                               */
 #define CSP_PWM_GET_MDSR(pwm)        ((pwm)->MDSR)
#endif

/* ECR, DCR, PMSR : PWM Power Management registers                           */
/** Set ECR register (Enable)                                                */
 #define CSP_PWM_SET_ECR(pwm, val)    ((pwm)->ECR = (val))
/** Set DCR register (Enable)                                                */
 #define CSP_PWM_SET_DCR(pwm, val)    ((pwm)->DCR = (val))
/** Get PMSR register (Enable)                                               */
 #define CSP_PWM_GET_PMSR(pwm)        ((pwm)->PMSR)

/* CR : PWM Control Register                                                 */
/** Set CR register                                                          */
 #define CSP_PWM_SET_CR(pwm, val)     ((pwm)->CR = (val))

/* MR : PWM Mode Register                                                    */
/** Get MR register                                                          */
 #define CSP_PWM_GET_MR(pwm)          ((pwm)->MR)
/** Set MR register                                                          */
 #define CSP_PWM_SET_MR(pwm, mode)    ((pwm)->MR = (mode))

/* CSR, SR : PWM Status Registers                                            */
/** Set CSR register (Clear)                                                 */
 #define CSP_PWM_SET_CSR(pwm, val)    ((pwm)->CSR = (val))
/** Get SR register (Status)                                                 */
 #define CSP_PWM_GET_SR(pwm)          ((pwm)->SR)

/* IER, IDR, IMR : PWM Interrupt Registers                                   */
/** Set IER register (Enable)                                                */
 #define CSP_PWM_SET_IER(pwm, val)    ((pwm)->IER = (val))
/** Set IDR register (Disable)                                               */
 #define CSP_PWM_SET_IDR(pwm, val)    ((pwm)->IDR = (val))
/** Get IMR register (Status)                                                */
 #define CSP_PWM_GET_IMR(pwm)         ((pwm)->IMR)

/* DLY : PWM Delay Register                                                  */
/** Get DLY register                                                         */
 #define CSP_PWM_CHANNEL_GET_DLY(pwm, channel)                                \
                                 ((pwm)->CHANNEL[(channel)].DLY)
/** Set DLY register                                                         */
 #define CSP_PWM_CHANNEL_SET_DLY(pwm, channel, delay)                         \
                                 ((pwm)->CHANNEL[(channel)].DLY = (delay))

/* PUL : PWM Pulse Register                                                  */
/** Get PUL register                                                         */
 #define CSP_PWM_CHANNEL_GET_PUL(pwm, channel)                                \
                                 ((pwm)->CHANNEL[(channel)].PUL)
/** Set PUL register                                                         */
 #define CSP_PWM_CHANNEL_SET_PUL(pwm, channel, pulse)                         \
                                 ((pwm)->CHANNEL[(channel)].PUL = (pulse))


/******************************************************************************
********************** PWM External Functions Declaration *********************
******************************************************************************/
extern void CSP_PWMInit(CSP_PWM_T *const pwm);
extern void CSP_PWMClose(CSP_PWM_T *const pwm);
extern void CSP_PWMConfigureChannel(CSP_PWM_T *const pwm, 
                                    U8_T channel_u8, 
                                    U32_T mode_u32, 
                                    U16_T delay_u16, 
                                    U16_T pulse_u16);
extern void CSP_PWMConfigInterrupt(CSP_PWM_T *const pwm, 
                                   U32_T intMode_u32, 
                                   U32_T intMask_u32, 
                                   U32_T callback_u32);
extern void CSP_PWMEnable(CSP_PWM_T *const pwm, U8_T channel_u8);
extern void CSP_PWMDisable(CSP_PWM_T *const pwm, U8_T channel_u8);
extern void CSP_PWMSetOffstate(CSP_PWM_T *const pwm, 
                               U8_T channel_u8, 
                               U8_T offstate_u8);
#ifdef PWM_PIO_TAG
extern void CSP_PWMPioInit(CSP_PWM_T *const pwm, U32_T pioMask_u32, U32_T outputPio_u32);
extern void CSP_PWMPioClear(CSP_PWM_T *const pwm, U32_T pioMask_u32);
extern void CSP_PWMPioSet(CSP_PWM_T *const pwm, U32_T pioMask_u32);
extern void CSP_PWMPioDisable(CSP_PWM_T *const pwm, U32_T pioMask_u32);
#endif

#endif   /* CSP_PWM_H */

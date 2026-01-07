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
* @file name	csp_st16.h
* @description	Definitions, Macros and function declarations 
*            	for Simple Timer module
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
*		ST/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 



#ifndef CSP_ST16_H
#define CSP_ST16_H


/******************************************************************************
************************* ST Structure Definition *****************************
******************************************************************************/

/* Number of ST Channels                                                     */
 #define NB_MAX_ST16_CHANNEL   8u          /**< Max number of channel        */
 #define NB_ST16_CHANNEL       2u          /**< Number of channel            */

 #define RSVD_D_SZ             (80+((NB_MAX_ST16_CHANNEL-NB_ST16_CHANNEL)*2))
/**
*******************************************************************************
@brief ST 16 bits Channel Structure
*******************************************************************************
*/
 typedef struct
 { 
    CSP_REGISTER_T  PR;                    /**< Channel Prescalar Register   */
    CSP_REGISTER_T  CT;                    /**< Channel Counter Register     */
 } CSP_ST16_CHANNEL_T, *CSP_ST16_CHANNEL_PTR;


/**
*******************************************************************************
@brief ST 16 bits Structure
*******************************************************************************
*/
 typedef struct 
 { 
    CSP_REGISTER_T     ReservedA[20]; 
    CSP_REGISTER_T     ECR;            /**< Enable Clock Register            */
    CSP_REGISTER_T     DCR;            /**< Disable Clock Register           */
    CSP_REGISTER_T     PMSR;           /**< Power Management Status Register */
    CSP_REGISTER_T     ReservedB;       
    CSP_REGISTER_T     CR;             /**< Control Register                 */
    CSP_REGISTER_T     ReservedC[2];  
    CSP_REGISTER_T     CSR;            /**< Clear Status Register            */
    CSP_REGISTER_T     SR;             /**< Status Register                  */
    CSP_REGISTER_T     IER;            /**< Interrupt Enable Register        */
    CSP_REGISTER_T     IDR;            /**< Interrupt Disable Register       */
    CSP_REGISTER_T     IMR;            /**< Interrupt Mask Register          */
    CSP_ST16_CHANNEL_T CHANNEL[NB_ST16_CHANNEL]; /**< ST Channels            */
    CSP_REGISTER_T     ReservedD[RSVD_D_SZ]; 
    CSP_REGISTER_T     CCV[NB_ST16_CHANNEL];     /**< Current Counter Value 
                                                      Registers              */
 } CSP_ST16_T, *CSP_ST16_PTR;


/******************************************************************************
************************** ST Registers Definition ****************************
******************************************************************************/

/******************************************************************************
* ECR, DCR, PMSR : ST Power Management Registers
******************************************************************************/
 #define ST16_ST            (0x01ul << 1)      /**< ST Clock                 */
 #define ST16_IPIDCODE_MASK (0x3FFFFFFul << 4) /**< ST IPIDCODE MASK         */
 #define ST16_DBGEN         (0x01ul << 31)     /**< Debug Mode Enable        */


/******************************************************************************
* CR : ST Control Register
******************************************************************************/
 #define ST16_SWRST      (0x01ul << 0)       /**< Software Reset             */
 #define ST16_CHEN       (0x01ul << 8)       /**< Channel Enable             */ 
 #define ST16_CHEN0      (0x01ul << 8)       /**< Channel 0 Enable           */
 #define ST16_CHEN1      (0x02ul << 9)       /**< Channel 1 Enable           */
 #define ST16_CHEN2      (0x01ul << 10)      /**< Channel 2 Enable           */
 #define ST16_CHEN3      (0x02ul << 11)      /**< Channel 3 Enable           */
 #define ST16_CHEN4      (0x01ul << 12)      /**< Channel 4 Enable           */
 #define ST16_CHEN5      (0x02ul << 13)      /**< Channel 5 Enable           */
 #define ST16_CHEN6      (0x01ul << 14)      /**< Channel 6 Enable           */
 #define ST16_CHEN7      (0x02ul << 15)      /**< Channel 7 Enable           */

 #define ST16_CHDIS      (0x01ul << 16)      /**< Channel Disable            */
 #define ST16_CHDIS0     (0x01ul << 16)      /**< Channel 0 Disable          */
 #define ST16_CHDIS1     (0x01ul << 17)      /**< Channel 1 Disable          */
 #define ST16_CHDIS2     (0x01ul << 18)      /**< Channel 2 Disable          */
 #define ST16_CHDIS3     (0x01ul << 19)      /**< Channel 3 Disable          */
 #define ST16_CHDIS4     (0x01ul << 20)      /**< Channel 4 Disable          */
 #define ST16_CHDIS5     (0x01ul << 21)      /**< Channel 5 Disable          */
 #define ST16_CHDIS6     (0x01ul << 22)      /**< Channel 6 Disable          */
 #define ST16_CHDIS7     (0x01ul << 23)      /**< Channel 7 Disable          */


/******************************************************************************
* CSR, SR, IER, IDR, IMR : ST Status and Interrupt Registers
******************************************************************************/
/* CHEND : Channel X End Status - Same as CR Register                        */
 #define ST16_CHEND      (0x01ul << 0)       /**< Channel X End              */
 #define ST16_CHEND0     (0x01ul << 0)       /**< Channel 0 End              */
 #define ST16_CHEND1     (0x01ul << 1)       /**< Channel 1 End              */
 #define ST16_CHEND2     (0x01ul << 2)       /**< Channel 2 End              */
 #define ST16_CHEND3     (0x01ul << 3)       /**< Channel 3 End              */
 #define ST16_CHEND4     (0x01ul << 4)       /**< Channel 4 End              */
 #define ST16_CHEND5     (0x01ul << 5)       /**< Channel 5 End              */
 #define ST16_CHEND6     (0x01ul << 6)       /**< Channel 6 End              */
 #define ST16_CHEND7     (0x01ul << 7)       /**< Channel 7 End              */

/* CHDIS : Channel X Disable - Same as CR Register                           */
 #define ST16_CHDIS      (0x01ul << 16)      /**< Channel X Disable          */
 #define ST16_CHDIS0     (0x01ul << 16)      /**< Channel 0 Disable          */
 #define ST16_CHDIS1     (0x01ul << 17)      /**< Channel 1 Disable          */
 #define ST16_CHDIS2     (0x01ul << 18)      /**< Channel 2 Disable          */
 #define ST16_CHDIS3     (0x01ul << 19)      /**< Channel 3 Disable          */
 #define ST16_CHDIS4     (0x01ul << 20)      /**< Channel 4 Disable          */
 #define ST16_CHDIS5     (0x01ul << 21)      /**< Channel 5 Disable          */
 #define ST16_CHDIS6     (0x01ul << 22)      /**< Channel 6 Disable          */
 #define ST16_CHDIS7     (0x01ul << 23)      /**< Channel 7 Disable          */

/* CHLD : Channel X Load - Same as CR Register                               */
 #define ST16_CHLD       (0x01ul << 24)      /**< Channel X Load             */
 #define ST16_CHLD0      (0x01ul << 24)      /**< Channel 0 Load             */
 #define ST16_CHLD1      (0x01ul << 25)      /**< Channel 1 Load             */
 #define ST16_CHLD2      (0x01ul << 26)      /**< Channel 2 Load             */
 #define ST16_CHLD3      (0x01ul << 27)      /**< Channel 3 Load             */
 #define ST16_CHLD4      (0x01ul << 28)      /**< Channel 4 Load             */
 #define ST16_CHLD5      (0x01ul << 29)      /**< Channel 5 Load             */
 #define ST16_CHLD6      (0x01ul << 30)      /**< Channel 6 Load             */
 #define ST16_CHLD7      (0x01ul << 31)      /**< Channel 7 Load             */

/* SR Register Only                                                          */
 #define ST16_CHENS      (0x01ul << 8)       /**< Channel X Enable Status    */
 #define ST16_CHENS0     (0x01ul << 8)       /**< Channel 0 Enable Status    */
 #define ST16_CHENS1     (0x01ul << 9)       /**< Channel 1 Enable Status    */
 #define ST16_CHENS2     (0x01ul << 10)      /**< Channel 2 Enable Status    */
 #define ST16_CHENS3     (0x01ul << 11)      /**< Channel 3 Enable Status    */
 #define ST16_CHENS4     (0x01ul << 12)      /**< Channel 4 Enable Status    */
 #define ST16_CHENS5     (0x01ul << 13)      /**< Channel 5 Enable Status    */
 #define ST16_CHENS6     (0x01ul << 14)      /**< Channel 6 Enable Status    */
 #define ST16_CHENS7     (0x01ul << 15)      /**< Channel 7 Enable Status    */
 

/******************************************************************************
* PRx : ST Channel Prescalar Register
******************************************************************************/
/* PRESCALAR : Channel Prescalar                                             */
 #define ST16_PRESCAL_MASK  (0x0Ful << 0)            /**< Mask               */
 #define ST16_PRESCAL(val)  (((val) & 0x0Ful) << 0)  /**< Writing Macro      */

 #define ST16_AUTOREL       (0x01ul << 4)            /**< Autoreload         */

/* SYSCAL : System Clock Prescalar                                           */
 #define ST16_SYSCAL_MASK   (0x7FFul << 8)           /**< Mask               */ 
 #define ST16_SYSCAL(val)   (((val) & 0x7FFul) << 8) /**< Writing Macro      */


/******************************************************************************
* CTx : ST Channel Counter Register
******************************************************************************/
 #define ST16_LOAD_MASK  (0xFFFFul << 0)             /**< Counter Value Mask */
 #define ST16_LOAD(val)  (((val) & 0xFFFFul) << 0)   /**< Writing Macro      */

             
/******************************************************************************
* CCVx : ST Current Counter Value Registers
******************************************************************************/
 #define ST16_COUNT_MASK (0xFFFFul << 0)     /**< Current Counter Value Mask */
 #define ST16_COUNT(val) (((val) & 0xFFFFul) << 0)   /**< Writing Macro      */


/******************************************************************************
***************************** ST16 Registers mask *****************************
******************************************************************************/
 #define ST16_ECR_MASK               (0x80000002ul)    /**< ECR mask         */
 #define ST16_DCR_MASK               (0x80000002ul)    /**< DCR mask         */
 #define ST16_PMSR_MASK              (0xBFFFFFF2ul)    /**< PMSR mask        */
 #define ST16_CR_MASK                (0x00030301ul)    /**< CR mask          */
 #define ST16_CSR_MASK               (0x03030003ul)    /**< CSR mask         */
 #define ST16_SR_MASK                (0x03030303ul)    /**< SR mask          */
 #define ST16_IER_MASK               (0x03030003ul)    /**< IER mask         */
 #define ST16_IDR_MASK               (0x03030003ul)    /**< IDR mask         */
 #define ST16_IMR_MASK               (0x03030003ul)    /**< IMR mask         */
 #define ST16_PRX_MASK               (0x0007FF1Ful)    /**< PRx mask         */
 #define ST16_CTX_MASK               (0x0000FFFFul)    /**< CTx mask         */ 
 #define ST16_CCVX_MASK              (0x0000FFFFul)    /**< CCVx mask        */
                         

/******************************************************************************
***************************** ST16 Registers mask *****************************
******************************************************************************/
 #define ST16_ECR_RST              	 (0x00000000ul)    /**< ECR reset value  */
 #define ST16_DCR_RST              	 (0x00000000ul)    /**< DCR reset value  */
 #define ST16_PMSR_RST    (IPIDCODE_SIMPLETIMER16_0)   /**< PMSR reset value */
 #define ST16_SY_PMSR_RST (IPIDCODE_SIMPLETIMER16_SY0) /**< PMSR reset value */
 #define ST16_CR_RST                 (0x00000000ul)    /**< CR reset value   */
 #define ST16_CSR_RST                (0x00000000ul)    /**< CSR reset value  */
 #define ST16_SR_RST                 (0x00000000ul)    /**< SR reset value   */
 #define ST16_IER_RST                (0x00000000ul)    /**< IER reset value  */
 #define ST16_IDR_RST                (0x00000000ul)    /**< IDR reset value  */
 #define ST16_IMR_RST                (0x00000000ul)    /**< IMR reset value  */
 #define ST16_PRX_RST                (0x00000000ul)    /**< PRx reset value  */
 #define ST16_CTX_RST                (0x00000000ul)    /**< CTx reset value  */ 
 #define ST16_CCVX_RST               (0x00000000ul)    /**< CCVx reset value */
                      

/******************************************************************************
**************************** ST Macros Definition *****************************
******************************************************************************/
/* ECR, DCR, PMSR : ST Power Management Registers                            */
/** Set ECR register (Enable)                                                */
 #define CSP_ST16_SET_ECR(st, val)            ((st)->ECR = (val))
/** Set DCR register (Disable)                                               */
 #define CSP_ST16_SET_DCR(st, val)            ((st)->DCR = (val))
/** Get PMSR register (Status)                                               */
 #define CSP_ST16_GET_PMSR(st)                ((st)->PMSR)

/* CR : ST Control Register                                                  */
/** Set CR register                                                          */
 #define CSP_ST16_SET_CR(st, val)             ((st)->CR = (val))

/* CSR, SR : ST Status Registers                                             */
/** Set CSR register (Clear)                                                 */
 #define CSP_ST16_SET_CSR(st, val)            ((st)->CSR = (val))
/** Get SR register (Status)                                                 */
 #define CSP_ST16_GET_SR(st)                  ((st)->SR)

/* IER, IDR, IMR : ST Interrupt Registers                                    */
/** Set IER register (Enable)                                                */
 #define CSP_ST16_SET_IER(st, val)            ((st)->IER = (val))
/** Set IDR register (Disable)                                               */
 #define CSP_ST16_SET_IDR(st, val)            ((st)->IDR = (val))
/** Get IMR register  (Status)                                               */
 #define CSP_ST16_GET_IMR(st)                 ((st)->IMR)

/* PR : ST Channel Prescalar Register                                        */
/** Get PR register                                                          */
 #define CSP_ST16_CHANNEL_GET_PR(st, channel)                                 \
                               ((st)->CHANNEL[(channel)].PR)
/** Set PR register                                                          */
 #define CSP_ST16_CHANNEL_SET_PR(st, channel, prescal)                        \
                               ((st)->CHANNEL[(channel)].PR = (prescal))

/* CT : ST Channel Counter Register                                          */
/** Get CT register                                                          */
 #define CSP_ST16_CHANNEL_GET_CT(st, channel)                                 \
                               ((st)->CHANNEL[(channel)].CT)
/** Set CT register                                                          */
 #define CSP_ST16_CHANNEL_SET_CT(st, channel, counter)                        \
                               ((st)->CHANNEL[(channel)].CT = (counter))

/* CCV : ST Current Counter Value Register                                   */
/** Get CCV register                                                         */
 #define CSP_ST16_CHANNEL_GET_CCV(st, channel)          ((st)->CCV[(channel)])


/******************************************************************************
********************** ST External Functions Declaration **********************
******************************************************************************/
extern void CSP_ST16Init(CSP_ST16_T *const st);
extern void CSP_ST16Close(CSP_ST16_T *const st);
extern void CSP_ST16ConfigureChannel(CSP_ST16_T *const st, 
                                     U8_T channel_u8, 
                                     U32_T prescalMode_u32, 
                                     U32_T loadCounter_u32);
extern void CSP_ST16ConfigInterrupt(CSP_ST16_T *const st, 
                                    U32_T intMode_u32, 
                                    U32_T intMask_u32, 
                                    U32_T callback_u32);
extern void CSP_ST16Enable(CSP_ST16_T *const st, U8_T channel_u8);
extern void CSP_ST16Disable(CSP_ST16_T *const st, U8_T channel_u8);


#endif   /* CSP_ST16_H */

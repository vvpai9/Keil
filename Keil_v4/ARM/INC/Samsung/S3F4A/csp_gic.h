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
* @file name	csp_gic.h
* @description	Definitions, Macros and function declarations 
*            	for Generic Interrupt Controller module
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
*		GIC/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 

#ifndef _CSP_GIC_H
#define _CSP_GIC_H

/*******************************************************************************
************************   GIC STRUCTURE DEFINITION   **************************
*******************************************************************************/
/** Number of Interrupt Vectors                                              */
#define NB_INTERRUPT			64u
/** Number of register for Interrupt                                         */
#define NB_INT_REG         		2u
/** Number of Priority Level                                                 */
#define NB_INTERRUPT_LEVEL  	8u


/*******************************************************************************
* GIC Structure
********************************************************************************/
typedef struct
{ 
	CSP_REGISTER_T	ReservedA[960];
   	CSP_REGISTER_T  SMR[NB_INTERRUPT]; /**< Source Mode Registers             */
   	CSP_REGISTER_T  SVR[NB_INTERRUPT]; /**< Source Vector Registers           */
   	CSP_REGISTER_T  IVR;               /**< IRQ Vector Register               */ 
   	CSP_REGISTER_T  FVR;               /**< FIQ Vector Register               */ 
   	CSP_REGISTER_T  ISR;               /**< Interrupt Status Register         */
   	CSP_REGISTER_T  IPR[NB_INT_REG];   /**< Interrupt Pending Register        */  
   	CSP_REGISTER_T  IMR[NB_INT_REG];   /**< Interrupt Mask Register           */
   	CSP_REGISTER_T  CISR;              /**< Core Interrupt Status Register    */          
   	CSP_REGISTER_T  IECR[NB_INT_REG];  /**< Interrupt Enable Command Register */ 
   	CSP_REGISTER_T  IDCR[NB_INT_REG];  /**< Interrupt Disable Command Register*/ 
   	CSP_REGISTER_T  ICCR[NB_INT_REG];  /**< Interrupt Clear Command Register  */
   	CSP_REGISTER_T  ISCR[NB_INT_REG];  /**< Interrupt Set Command Register    */
   	CSP_REGISTER_T  EOICR;             /**< End of Interrupt Command Register */
   	CSP_REGISTER_T  SPU;               /**< Spurious Vector Register          */
}CSP_GIC_T, *CSP_GIC_PTR;


/*******************************************************************************
************************  GIC  REGISTERS DEFINITION   **************************
*******************************************************************************/	

/*******************************************************************************
* SMR : GIC Source Mode Register
*******************************************************************************/
/* PRIOR : Priority Level                                                    */
#define GIC_PRIOR_MASK	(0x07ul << 0)       /**< Priority Mask                */
#define GIC_PRIOR_0   	(0x00ul <<0)        /**< Priority Level 0             */
#define GIC_PRIOR_1   	(0x01ul <<0)        /**< Priority Level 1             */
#define GIC_PRIOR_2   	(0x02ul <<0)        /**< Priority Level 2             */
#define GIC_PRIOR_3   	(0x03ul <<0)        /**< Priority Level 3             */
#define GIC_PRIOR_4   	(0x04ul <<0)        /**< Priority Level 4             */
#define GIC_PRIOR_5   	(0x05ul <<0)        /**< Priority Level 5             */
#define GIC_PRIOR_6   	(0x06ul <<0)        /**< Priority Level 6             */
#define GIC_PRIOR_7   	(0x07ul <<0)        /**< Priority Level 7             */

/* SDI : Select Destination Interrupt NFIQ or NIRQ                           */
#define GIC_SDI      	(0x01ul << 3)       /**< SDI Mask                     */
#define GIC_SDI_IRQ   	(0x00ul << 3)       /**< IRQ line                     */
#define GIC_SDI_FIQ   	(0x01ul << 3)       /**< FIQ line                     */

/* SRCTYP : Interrupt Source Type                                            */
#define GIC_SRCTYP_MASK					(0x03ul << 4) /**< SRCTYP Mask           */
#define GIC_LOW_LEVEL_SENSITIVE     	(0x00ul << 4) /**< Low Level Sensitive   */
#define GIC_NEGATIVE_EDGE_TRIGGERED 	(0x01ul << 4) /**< Negative Edge Triggered */
#define GIC_HIGH_LEVEL_SENSITIVE    	(0x02ul << 4) /**< High Level Sensitive  */
#define GIC_POSITIVE_EDGE_TRIGGERED 	(0x03ul << 4) /**< Positive Edge Triggered */

/*******************************************************************************
* SVR : GIC Source Vector Register
*******************************************************************************/
#define GIC_VECT_MASK	(0xFFFFFFFFul << 0) /**< Interrupt Handler Address Mas */

/*******************************************************************************
* IVR : GIC Interrupt Vector Register
*******************************************************************************/
#define GIC_IRQV_MASK	(0xFFFFFFFFul << 0) /**< Interrupt Vector Address Mask */

/*******************************************************************************
* FVR : GIC FIQ Vector Register
*******************************************************************************/
#define GIC_FIQV_MASK	(0xFFFFFFFFul << 0) /**< FIQ Vector Address Mask       */

/*******************************************************************************
* ISR : GIC Interrupt Status Register
*******************************************************************************/
#define GIC_IRQID_MASK (0x3Ful << 0)      /**< Current IRQ Identifier Mask   */

/*******************************************************************************
* IPR, IMR, IECR, IDCR, ICCR, ISCR : GIC Interrupt Registers
*******************************************************************************/
#define GIC_INT0		(0x01ul << 0)       /**< Peripheral Interrupt 0        */
#define GIC_INT1      	(0x01ul << 1)       /**< Peripheral Interrupt 1        */
#define GIC_INT2      	(0x01ul << 2)       /**< Peripheral Interrupt 2        */
#define GIC_INT3      	(0x01ul << 3)       /**< Peripheral Interrupt 3        */
#define GIC_INT4      	(0x01ul << 4)       /**< Peripheral Interrupt 4        */
#define GIC_INT5      	(0x01ul << 5)       /**< Peripheral Interrupt 5        */
#define GIC_INT6      	(0x01ul << 6)       /**< Peripheral Interrupt 6        */
#define GIC_INT7      	(0x01ul << 7)       /**< Peripheral Interrupt 7        */
#define GIC_INT8      	(0x01ul << 8)       /**< Peripheral Interrupt 8        */
#define GIC_INT9      	(0x01ul << 9)       /**< Peripheral Interrupt 9        */
#define GIC_INT10     	(0x01ul << 10)      /**< Peripheral Interrupt 10       */
#define GIC_INT11     	(0x01ul << 11)      /**< Peripheral Interrupt 11       */
#define GIC_INT12     	(0x01ul << 12)      /**< Peripheral Interrupt 12       */
#define GIC_INT13     	(0x01ul << 13)      /**< Peripheral Interrupt 13       */
#define GIC_INT14     	(0x01ul << 14)      /**< Peripheral Interrupt 14       */
#define GIC_INT15     	(0x01ul << 15)      /**< Peripheral Interrupt 15       */
#define GIC_INT16     	(0x01ul << 16)      /**< Peripheral Interrupt 16       */
#define GIC_INT17     	(0x01ul << 17)      /**< Peripheral Interrupt 17       */
#define GIC_INT18     	(0x01ul << 18)      /**< Peripheral Interrupt 18       */
#define GIC_INT19     	(0x01ul << 19)      /**< Peripheral Interrupt 19       */
#define GIC_INT20     	(0x01ul << 20)      /**< Peripheral Interrupt 20       */
#define GIC_INT21     	(0x01ul << 21)      /**< Peripheral Interrupt 21       */
#define GIC_INT22     	(0x01ul << 22)      /**< Peripheral Interrupt 22       */
#define GIC_INT23     	(0x01ul << 23)      /**< Peripheral Interrupt 23       */
#define GIC_INT24     	(0x01ul << 24)      /**< Peripheral Interrupt 24       */
#define GIC_INT25     	(0x01ul << 25)      /**< Peripheral Interrupt 25       */
#define GIC_INT26     	(0x01ul << 26)      /**< Peripheral Interrupt 26       */
#define GIC_INT27     	(0x01ul << 27)      /**< Peripheral Interrupt 27       */
#define GIC_INT28     	(0x01ul << 28)      /**< Peripheral Interrupt 28       */
#define GIC_INT29     	(0x01ul << 29)      /**< Peripheral Interrupt 29       */
#define GIC_INT30     	(0x01ul << 30)      /**< Peripheral Interrupt 30       */
#define GIC_INT31     	(0x01ul << 31)      /**< Peripheral Interrupt 31       */	

/*******************************************************************************
* CISR : GIC Core Interrupt Status Register
*******************************************************************************/
#define GIC_NFIQ		(0x01ul << 0)       /**< NFIQ Status                   */
#define GIC_NIRQ      	(0x01ul << 1)       /**< NIRQ Status                   */

/*******************************************************************************
* SPU : GIC Spurious Vector Register
*******************************************************************************/
#define GIC_SPUVECT_MASK	(0xFFFFul)/**< Spurious Vector Handler Address Mask*/

/*******************************************************************************
*****************************  GIC REGISTER MASK  ******************************
*******************************************************************************/
#define GIC_SMRX_MASK		(0x0000003Ful)     /**< SMRx mask                   */
#define GIC_SVRX_MASK  		(0xFFFFFFFFul)     /**< SVRx mask                   */
#define GIC_IVR_MASK   		(0xFFFFFFFFul)     /**< IVR mask                    */
#define GIC_FVR_MASK   		(0xFFFFFFFFul)     /**< FVR mask                    */
#define GIC_ISR_MASK   		(0x0000003Ful)     /**< ISR mask                    */
#define GIC_IPRX_MASK  		(0xFFFFFFFFul)     /**< IPR mask                    */
#define GIC_IMRX_MASK  		(0xFFFFFFFFul)     /**< IMR mask                    */
#define GIC_CISR_MASK  		(0x00000003ul)     /**< CISR mask                   */
#define GIC_IECRX_MASK 		(0xFFFFFFFFul)     /**< IECR mask                   */
#define GIC_IDCRX_MASK 		(0xFFFFFFFFul)     /**< IDCR mask                   */
#define GIC_ICCRX_MASK 		(0xFFFFFFFFul)     /**< ICCR mask                   */
#define GIC_ISCRX_MASK 		(0xFFFFFFFFul)     /**< ISCR mask                   */
#define GIC_EOICR_MASK 		(0xFFFFFFFFul)     /**< EOICR mask                  */
#define GIC_SPU_MASK   		(0xFFFFFFFFul)     /**< SPU mask                    */

/*******************************************************************************
************************  GIC REGISTERS RESET VALUE  ***************************
*******************************************************************************/
#define GIC_SMRX_RST		(0x00000000ul)     /**< SMRX reset value            */
#define GIC_SVRX_RST   		(0x00000000ul)     /**< SVRX reset value            */
#define GIC_IVR_RST    		(0x00000000ul)     /**< IVRX reset value            */
#define GIC_FVR_RST    		(0x00000000ul)     /**< FVR reset value             */
#define GIC_ISR_RST    		(0x00000000ul)     /**< ISR reset value             */
#define GIC_IPRX_RST   		(0xFFFFFFFFul)     /**< IPRX reset value            */
#define GIC_IMRX_RST   		(0x00000000ul)     /**< IMRX reset value            */
#define GIC_CISR_RST   		(0x00000000ul)     /**< CISR reset value            */
#define GIC_IECRX_RST  		(0x00000000ul)     /**< IECRX reset value           */
#define GIC_IDCRX_RST  		(0x00000000ul)     /**< IDCRX reset value           */
#define GIC_ICCRX_RST  		(0x00000000ul)     /**< ICCR reset value            */
#define GIC_ISCRX_RST  		(0x00000000ul)     /**< ISCR reset value            */
#define GIC_EOICR_RST  		(0x00000000ul)     /**< EOICR reset value           */
#define GIC_SPU_RST    		(0x00000000ul)     /**< SPU reset value             */

/*******************************************************************************
**************************  GIC MACROS DEFINITION  *****************************
*******************************************************************************/
/* SMR : GIC Source Mode Register                                            */
/** Get SMR register                                                         */
#define CSP_GIC_GET_SMR(gic, interrupt)		((gic)->SMR[(interrupt)])
/** Set SMR register                                                         */
#define CSP_GIC_SET_SMR(gic, interrupt, val)                               \
                                         	((gic)->SMR[(interrupt)] = (val))

/* SVR : GIC Source Vertor Register                                          */
/** Get SVR register                                                         */
#define CSP_GIC_GET_SVR(gic, interrupt)	((gic)->SVR[(interrupt)])
/** Set SVR register                                                         */
#define CSP_GIC_SET_SVR(gic, interrupt, vector)                            \
                                     	((gic)->SVR[(interrupt)] = (vector))

/* IVR : GIC IRQ Vector Register                                             */
/** Get IVR register                                                         */
#define CSP_GIC_GET_IVR(gic)				((gic)->IVR)

/* FVR : GIC FIQ Vector Register                                             */
/** Get FVR register                                                         */
#define CSP_GIC_GET_FVR(gic)             	((gic)->FVR)

/* ISR, IPR, IMR : GIC Interrupt Registers                                   */
/** Get ISR register (Status)                                                */
#define CSP_GIC_GET_ISR(gic)             	((gic)->ISR)
/** Get IPR register (Pending)                                               */
#define CSP_GIC_GET_IPR(gic, regNum)		((gic)->IPR[regNum])
/** Get IMR register (Mask)                                                  */
#define CSP_GIC_GET_IMR(gic, regNum)		((gic)->IMR[regNum])

/* CISR : GIC Core Interrupt Status Register                                 */
/** Get CISR register  (Status)                                              */
#define CSP_GIC_GET_CISR(gic)            	((gic)->CISR)
 
/* IECR, IDCR, ICCR, ISCR : GIC Interrupt Command Registers                  */
/** Set IECR register (Enable)                                               */
#define CSP_GIC_SET_IECR(gic, regNum, val)	((gic)->IECR[regNum] = (val))
/** Set IDCR register (Disable)                                              */
#define CSP_GIC_SET_IDCR(gic, regNum, val)	((gic)->IDCR[regNum] = (val))
/** Set ICCR register (Clear)                                                */
#define CSP_GIC_SET_ICCR(gic, regNum, val)	((gic)->ICCR[regNum] = (val))
/** Set ISCR register (Set)                                                  */
#define CSP_GIC_SET_ISCR(gic, regNum, val)	((gic)->ISCR[regNum] = (val))

/* EOICR : GIC End of Interrupt Command Register                             */
/** Set EOICR register (                                                     */
#define CSP_GIC_SET_EOICR(gic, val)				((gic)->EOICR = (val))

/* SPU : GIC Spurious Vector Register                                        */
/** Get SPU register                                                         */
#define CSP_GIC_GET_SPU(gic)              		((gic)->SPU)
/** Set SPU register                                                         */
#define CSP_GIC_SET_SPU(gic, vector)     		((gic)->SPU = (vector))
         
/*******************************************************************************
***********************   GIC EXTERNAL FUNCTIONS   *****************************
*******************************************************************************/
extern void CSP_GICInit(void);
extern void CSP_GICConfigInterrupt(U8_T intNum_u8, 
                                   	U32_T intMode_u32, 
                                   	U32_T callback_u32);
extern void CSP_GICUndefinedIntHandler(void);
extern void CSP_ASM_GICSpuriousIntHandler(void);

#endif	/* _CSP_GIC_H */

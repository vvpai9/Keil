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
* @file name	csp_cm.h
* @description	Definitions, Macros and function declarations 
*            	for Clock Manager module
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
*		CM/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 

#ifndef _CSP_CM_H
#define _CSP_CM_H

/*******************************************************************************
*************************   CM STRUCTURE DEFINITION   **************************
*******************************************************************************/
typedef struct
{
	CSP_REGISTER_T		STR;       	/**< Master clock status                  */
  	CSP_REGISTER_T      ReservedA;
  	CSP_REGISTER_T      WFIR;     	/**< Wait For Interrupt                   */
  	CSP_REGISTER_T      PSTR;    	/**< Clock Manager Pll Stabilisation Time */
  	CSP_REGISTER_T      PDPR;   	/**< PLL Divider Parameters           	  */
  	CSP_REGISTER_T      OSTR;    	/**< Master Oscillator Stabilisation Time */
  	CSP_REGISTER_T      ReservedB;
  	CSP_REGISTER_T      DIVBR;     		/**< Master Clock Divider             */
  	CSP_REGISTER_T      SELR;    		/**< Clock manager mode select        */ 
  	CSP_REGISTER_T      RSR;        	/**< Reset status                     */
  	CSP_REGISTER_T      MDIVR;      	/**< Master clock divider             */
  	CSP_REGISTER_T      LFOSCR;    		/**< Low Frequency Oscillator         */
  	CSP_REGISTER_T      CR;        		/**< Control Register                 */
  	CSP_REGISTER_T      ReservedC[12]; /**< Reserved                         */
  	CSP_REGISTER_T      MR;            	/**< Mode Register                    */
  	CSP_REGISTER_T      ReservedD;  	
  	CSP_REGISTER_T      CSR;            	/**< Mode Register                    */
  	CSP_REGISTER_T      SR;            	/**< Mode Register                    */
  	CSP_REGISTER_T      IER;            	/**< Mode Register                    */
  	CSP_REGISTER_T      IDR;            	/**< Mode Register                    */
  	CSP_REGISTER_T      IMR;            	/**< Mode Register                    */  	  	
}CSP_CM_T, *CSP_CM_PTR;

/*******************************************************************************
************************  CM REGISTERS DEFINITION   ****************************
*******************************************************************************/	

/*******************************************************************************
* STR : Clock Manager Status register
*******************************************************************************/
#define CM_PLLST			(0x01ul     <<  0) /**< PLL stabilization status  */
#define CM_OSCST           (0x01ul     <<  1) /**< Oscillator counter 
                                                   stabilization status      */
#define CM_LFOST           (0x01ul     <<  2) /**< Low Frequency oscillator stabilization status */
#define CM_LFUSED          (0x01ul     <<  3) /**< Low Frequency oscillator use status */                                                
                                                   
/******************************************************************************
* WFIR : Wait For Interrupt register
******************************************************************************/
#define CM_WFIKEY_MASK    	(0xFFFFul << 16)   /**< WFIKEY mask               */
#define CM_WFIKEY			(0x80A4ul << 16)   /**< Key for write access      */   
#define CM_PCLK1           (0x01ul   <<  5)   /**< Peripheral Clock domain   */

/******************************************************************************
* PSTR : PLL Stabilization Time
******************************************************************************/
#define CM_PLLKEY_MASK   	(0xFFFFul << 16) /**< PLLKEY mask                 */
#define CM_PLLKEY         	(0x59C1ul << 16) /**< Key for write access        */
#define CM_PST_MASK   		((0x7FFul) << 0) /**< PLL stabilization time mask */
#define CM_PST(val)   		((val & 0x7FF) << 0) /**< PLL stabilization time */
												 /* writing macro */
/******************************************************************************
* PDPR : PLL Divider Parameters
******************************************************************************/
#define CM_PDPKEY_MASK   	(0xFFFFul << 16)     	  /* PDPKEY mask          */
#define CM_PDPKEY         	(0x7AB2ul << 16)     	  /* Key for write access */

#define CM_PMUL_MASK      	((0xFFul) << 0)      	  /* PLL Multiplier mask  */
#define CM_PMUL(val)      	((val & 0xFFul) << 0)	  /* PLL Multiplier macro */

#define CM_PLLPOST_MASK  	((0x03ul)<< 8)         /*Post scalar parameter mask*/
#define CM_PLLPOST(val)  	((val & 0x03ul) << 8) /*Post scalar parameter macro*/

#define CM_PLLPRE_MASK   	((0x3Ful)<< 10)         /*Predivider parameter mask*/
#define CM_PLLPRE(val)    	((val & 0x3Ful) << 10) /*Predivider parameter macro*/

/******************************************************************************
* OSTR : Oscillator Stabilization Time
******************************************************************************/
/*** CM_OST Register ***/
#define CM_OSTKEY_MASK		(0xFFFFul << 16)     /* OSTKEY mask              */
#define CM_OSTKEY         	(0xFA4Bul << 16)     /* Key for write access*/
/* into CM_OST register 	  */
#define CM_OST_MASK       	(0xFFFFul << 0)      /**< oscillator              */
#define CM_OST(val)       	((val & 0xFFFFul) << 0)	/*< oscillator stabilization */                                               
													/*  time macro            */

/******************************************************************************
* DIVBR : Clock divider
******************************************************************************/
/*** CM_OST Register ***/
#define CM_PCLK1DIV_MASK	(0x7ul << 0)           /**< PCLK1 mask            */
#define CM_PCLK1DIV(val)  ((val & 0x7ul) << 0)   /**< PCLK1 macro           */

/******************************************************************************
* SELR : System Clock Selection register
******************************************************************************/
#define CM_SELKEY_MASK			(0xFFFFul << 16)      /**< SELKEY mask          */
#define CM_SELKEY         		(0xD0C9ul << 16)      /**< Key for write access */
													 /** into CM_SEL register  */
#define CM_CLKSEL_MASK    		(0x03ul << 0)         /**< Clock select mask    */
#define CM_CLKSEL(val)    		((val & 0x3ul) << 0) /**< Clock select macro   */
#define CM_CLKSELNORMAL  		(0x00ul)     /**< Clock select Normal mode 	   */
#define CM_CLKSELHIGHSPEED		(0x01ul)   	/**< Clock select High Speed mode  */
#define CM_CLKSELSLOW     		(0x02ul)  	/**< Clock select Slow Speed mode  */
#define CM_CLKSELLOWPOWER  		(0x03ul)  	/**< Clock select Low Power mode   */

/******************************************************************************
* RSR : Reset Status register
******************************************************************************/
#define CM_WD				(0x01ul << 0)        /**< Watchdog reset          */
#define CM_CM             	(0x01ul << 1)        /**< Clock Monitor reset     */
#define CM_LVD             	(0x01ul << 2)        /**< LVD reset               */
#define CM_POR             	(0x01ul << 3)        /**< POR reset               */

/******************************************************************************
* MDIVR : Master Oscillator Clock Divider regsiter
******************************************************************************/
#define CM_MDIVKEY_MASK   	(0xFFFFul << 16)       /**< MDIVKEY mask          */
#define CM_MDIVKEY        	(0xACDCul << 16)       /**< Key for write access                                                        CM_MDIV into  register*/
#define CM_MDIV_MASK      	(0x1FFul << 0)         /**< oscillator stabilization time                                                        mask                  */
#define CM_MDIV(val)      	((val & 0x1FFul) << 0) /**< oscillator stabilization time    macro                 */
#define CM_CDIV_MASK       (0x07ul << 10)         /**< Core clock divider mask */
#define CM_CDIV(val)       (((val) & 0x07ul) << 10) /**< Core clock divider macro */
#define CM_LDIV_MASK       (0x07ul << 13)         /**< Low Frequency clock divider mask */
#define CM_LDIV(val)       (((val) & 0x07ul) << 13) /**< Low Frequency clock divider macro */

/******************************************************************************
* LFOSCR : Low Frequency oscillator control
******************************************************************************/
#define CM_LFOSCKEY_MASK  	(0xFFFFul << 16)      /**< LFOSCKEY mask          */
#define CM_LFOSCKEY       	(0xA34Cul << 16)      /**< Key for write access   */
#define CM_LFOSCEN        	(0x01ul << 0)         /**< Low Frequency oscillator                                                  Enable                 */
#define CM_LFSEL          	(0x01ul << 1)         /**< Low Frequency clock    */
#define CM_LFST_MASK       (0xFFul << 8)         /**< Low Frequency stabilization time mask*/
#define CM_LFST(val)       (((val) & 0xFFul) << 8) /**< Low Frequency stabilization time macro */

/******************************************************************************
* CR : Control register
******************************************************************************/
#define CM_CRKEY_MASK     	(0xFFFFul << 16)      /**< CRKEY mask             */
#define CM_CRKEY           (0x678Ful << 16)      /**< Key for write access   */
#define CM_HALTMODE   		(0x01ul << 0)        /**< Halt Mode              */
#define CM_STOPMODE       	(0x01ul << 4)         /**< Stop mode              */
#define CM_IDLEMODE       	(0x01ul << 5)         /**< Idle mode              */

/******************************************************************************
* MR : Control register
******************************************************************************/
#define CM_MRKEY_MASK    	(0xFFFFul << 16)     /**< MRKEY mask              */
#define CM_MRKEY          	(0x1505ul << 16)     /**< Key for write access    */
#define CM_CMEN           	(0x01ul << 0)        /**< Clock Monitor Enable    */

/******************************************************************************
* CSR,SR,IER,IDR,IMR : Status/Interrupt-mask register
******************************************************************************/
#define CM_STABLE           (0x01ul << 0)       /**< STABLE transition flag  */
  
/*******************************************************************************
***************************** CM REGISTER MASK  ********************************
*******************************************************************************/
#define CM_STR_MASK     	(0x00000003ul)         /**< STR mask                */
#define CM_PMCR_MASK    	(0xFFFF0008ul)         /**< PMCR mask               */
#define CM_WFIR_MASK    	(0xFFFF0030ul)         /**< WFIR mask               */
#define CM_PSTR_MASK    	(0xFFFF07FFul)         /**< PSTR mask               */
#define CM_PDPR_MASK    	(0xFFFFFFFFul)         /**< PDPR mask               */
#define CM_OSTR_MASK    	(0xFFFFFFFFul)         /**< OSTR mask               */
#define CM_DIVBR_MASK   	(0x00000007ul)         /**< DIVBR mask              */
#define CM_SELR_MASK    	(0xFFFF0003ul)         /**< SELR mask               */
#define CM_RSR_MASK     	(0x0000000Ful)         /**< RSR mask                */
#define CM_MDIVR_MASK   	(0xFFFF01FFul)         /**< MDIVR mask              */
#define CM_LFOSCR_MASK  	(0xFFFF0003ul)         /**< LFOSCR mask             */
#define CM_CR_MASK      	(0xFFFF0011ul)         /**< CR mask                 */
#define CM_MR_MASK      	(0xFFFF0001ul)         /**< MR mask                 */
#define CM_CSR_MASK     (0x00000001ul)         /**< CSR mask                 */
#define CM_SR_MASK      (0x00000001ul)         /**< SR mask                  */
#define CM_IER_MASK     (0x00000001ul)         /**< IER mask                 */
#define CM_IDR_MASK     (0x00000001ul)         /**< IDR mask                 */
#define CM_IMR_MASK     (0x00000001ul)         /**< IMR mask    		*/

/*******************************************************************************
************************   CM REGISTERS RESET VALUE  ***************************
*******************************************************************************/
#define CM_STR_RST     		(0x00000002ul)        /**< STR reset                */
#define CM_PMCR_RST     	(0x00000000ul)        /**< PMCR reset               */
#define CM_WFIR_RST     	(0x00000000ul)        /**< WFIR reset               */
#define CM_PSTR_RST     	(0x00000154ul)        /**< PSTR reset               */
#define CM_PDPR_RST     	(0x0000FFFFul)        /**< PDPR reset               */
#define CM_OSTR_RST     	(0x00000834ul)        /**< OSTR reset               */
#define CM_DIVBR_RST    	(0x00077777ul)        /**< DIVBR reset              */
#define CM_SELR_RST     	(0x00000000ul)        /**< SELR reset               */
#define CM_RSR_RST      	(0x00000000ul)        /**< RSR reset                */
#define CM_MDIVR_RST    	(0x00000000ul)        /**< MDIVR reset              */
#define CM_LFOSCR_RST   	(0x00000001ul)        /**< LFOSCR reset             */
#define CM_CR_RST       	(0x00000000ul)        /**< CR reset                 */
#define CM_MR_RST       	(0x00000000ul)        /**< MR reset                 */
#define CM_CSR_RST      (0x00000000ul)        /**< CSR reset                 */
#define CM_SR_RST       (0x00000000ul)        /**< SR reset                  */
#define CM_IER_RST      (0x00000000ul)        /**< IER reset                 */
#define CM_IDR_RST      (0x00000000ul)        /**< IDR reset                 */
#define CM_IMR_RST      (0x00000000ul)        /**< IMR reset                 */

/*******************************************************************************
***************************  CM MACROS DEFINITION  *****************************
*******************************************************************************/
/* STR : CM Status Clock Register                                            */
/** Get STR register (Status)                                                */
#define CSP_CM_GET_STR(cm)				(cm->STR)

/* WFIR : CM Wait For Interrupt                                              */
/** Set WFIR register                                                        */
#define CSP_CM_SET_WFIR(cm, val)   		(cm->WFIR = (val | CM_WFIKEY))
/** Get WFIR register                                                        */
#define CSP_CM_GET_WFIR(cm)         	(cm->WFIR)

/* PSTR : CM PLL Stabilisation Timer                                         */
/** Set PSTR register                                                        */
#define CSP_CM_SET_PSTR(cm, val)    	(cm->PSTR = (val | CM_PLLKEY))
/** Get PSTR register                                                        */
#define CSP_CM_GET_PSTR(cm)         	(cm->PSTR)

/* PDPR : CM PLL Divider Parameters                                          */
/** Set PDPR register                                                        */
#define CSP_CM_SET_PDPR(cm, val)    	(cm->PDPR = (val | CM_PDPKEY))
/** Get PDPR register                                                        */
#define CSP_CM_GET_PDPR(cm)          	(cm->PDPR)

/* OSTR : CM Oscillator Stabilization Timer                                  */
/** Set OSTR register                                                        */
#define CSP_CM_SET_OSTR(cm, val)    	(cm->OSTR = (val | CM_OSTKEY))
/** Get OSTR register                                                        */
#define CSP_CM_GET_OSTR(cm)         	(cm->OSTR)

/* DIVBR :  CM Master Clock divider                                          */
/** Set DIVBR register                                                       */
#define CSP_CM_SET_DIVBR(cm, val)   	(cm->DIVBR = (val))
/** Get DIVBR register                                                       */
#define CSP_CM_GET_DIVBR(cm)         	(cm->DIVBR)

/* SELR : CM Select                                                          */
/** Set SELR register                                                        */
#define CSP_CM_SET_SELR(cm, val)    	(cm->SELR = (val | CM_SELKEY))
/** Get SELR register                                                        */
#define CSP_CM_GET_SELR(cm)          	(cm->SELR)

/* RSR : CM Reset status                                                     */
/** Get RSR register (Status)                                                */
#define CSP_CM_GET_RSR(cm)           	(cm->RSR)

/* MDIVR : CM Master Clock Divider                                           */
/** Set MDIVR register                                                       */
#define CSP_CM_SET_MDIVR(cm, val)   	(cm->MDIVR = (val | CM_MDIVKEY))
/** Get MDIVR register                                                       */
#define CSP_CM_GET_MDIVR(cm)         	(cm->MDIVR)

/* LFOSCR : CM Low Frequency oscillator control                              */
/** Set LFOSCR register                                                      */
#define CSP_CM_SET_LFOSCR(cm, val)  	(cm->LFOSCR = (val | CM_LFOSCKEY))
/** Get LFOSCR register                                                      */
#define CSP_CM_GET_LFOSCR(cm)        	(cm->LFOSCR)

/* CR :  CM Control register                                                 */
/** Set CR register                         ;                                */
#define CSP_CM_SET_CR(cm, val)       	(cm->CR = (val | CM_CRKEY))

/* MR : CM Mode register                                                     */
/** Set MR register                                                          */
#define CSP_CM_SET_MR(cm, val)       	(cm->MR = (val | CM_MRKEY))
/** Get MR register                                                          */
#define CSP_CM_GET_MR(cm)            	(cm->MR)


/* CSR :  CM Clear status register                                                 */
/** Set CSR register                         ;                                */
#define CSP_CM_SET_CSR(cm, val)       	(cm->CSR = val )

/* SR : CM status register                                                     */
/** Get SR register (status)                                                */
#define CSP_CM_GET_SR(cm)           	(cm->SR)

/* IER :  CM Interrupt enable register                                                 */
/** Set IER register                         ;                                */
#define CSP_CM_SET_IER(cm, val)       	(cm->IER = val )

/* IDR :  CM Interrupt disable register                                                 */
/** Set IDR register                         ;                                */
#define CSP_CM_SET_IDR(cm, val)       	(cm->IDR = val )

/* IMR : CM Interrupt mask register                                                     */
/** Get IMR register (status)                                                */
#define CSP_CM_GET_IMR(cm)           	(cm->IMR)


/******************************************************************************
****************** Clock Manager External Functions Declaration ***************
******************************************************************************/
extern void CSP_CMConfigInterrupt(CSP_CM_T *const cm,
                                    U32_T intMode_u32,
                                    U32_T intChannel_u32,
                                     U32_T intMask_u32,
                                      U32_T callback_u32);
#endif /* _CSP_CM_H */

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
* @file name	csp_dfc.h
* @description	Definitions, Macros and function declarations 
*            	for DFC module
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
*		DFC/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 

#ifndef _CSP_DFC_H
#define _CSP_DFC_H

/*******************************************************************************
***********************   DFC STRUCTURE DEFINITION   ***************************
*******************************************************************************/
typedef struct 
{ 
	CSP_REGISTER_T		ReservedA[20]; 
   	CSP_REGISTER_T      ECR;            /**< Enable Clock Register            */
   	CSP_REGISTER_T      DCR;            /**< Disable Clock Register           */
   	CSP_REGISTER_T      PMSR;           /**< Power Management Status Register */
   	CSP_REGISTER_T      ReservedB;          
   	CSP_REGISTER_T      CR;             /**< Control Register                 */
   	CSP_REGISTER_T      MR;             /**< Mode Register                    */
   	CSP_REGISTER_T      ReservedC;  
   	CSP_REGISTER_T      CSR;            /**< Clear Status Register            */
   	CSP_REGISTER_T      SR;             /**< Status Register                  */
   	CSP_REGISTER_T      IER;            /**< Interrupt Enable Register        */
   	CSP_REGISTER_T      IDR;            /**< Interrupt Disable Register       */
   	CSP_REGISTER_T      IMR;            /**< Interrupt Mask Register          */
}CSP_DFC_T, *CSP_DFC_PTR;

/*******************************************************************************
************************   DFC REGISTERS DEFINITION   **************************
*******************************************************************************/	

/*******************************************************************************
* ECR, DCR, PMSR : DFC Power Management Registers
*******************************************************************************/
#define DFC_DFC				(0x01ul << 1)        /**< DFC Clock               */
#define DFC_IPIDCODE_MASK	(0x3FFFFFFul << 4)    /**< DFC IPIDCODE mask       */

/*******************************************************************************
* CR : DFC Control Register
*******************************************************************************/
#define DFC_CRKEY_MASK		(0xFFul << 8)	/**< Control Register Key mask	  */
#define DFC_CRKEY          (0x14ul << 8)    /**< Control Register Key    	  */

#define DFC_SECTOR_MASK		(0x03ul << 30)        	/**< Sector number mask   */
#define DFC_SECTOR(val)  	(((val) & 0x03ul) << 30) /**< Writing macro        */
#define DFC_PAGE_MASK    	(0x1Ful << 25)         	/**< Page Number mask     */
#define DFC_PAGE(val)    	(((val) & 0x1Ful) << 25) /**< Writing macro        */
#define DFC_ERASE_MASK  	(0x03ul << 1)         	/**< Erase mask           */
#define DFC_ERASE(val)   	(((val) & 0x03ul) << 1)	/**< Writing macro        */
#define DFC_CHIP_ERASE   	((0x03ul) << 1)        	/**< Chip Erase           */
#define DFC_SECTOR_ERASE 	((0x02ul) << 1)        	/**< Sector Erase         */
#define DFC_PAGE_ERASE   	((0x01ul) << 1)        	/**< Page Erase           */
                     
/*******************************************************************************
* MR : DFC Mode Register
*******************************************************************************/
#define DFC_MRKEY_MASK		(0xFFul << 8)         /**< Mode Register Key mask */
#define DFC_MRKEY         	(0x78ul << 8)         /**< Mode Register Key      */

#define DFC_BA_MASK       	(0xFFul << 24)        	/**< Base address mask    */
#define DFC_BA(val)       	(((val) & 0xFFul) << 24) /**< Writing macro        */
#define DFC_WPR           	(0x01ul << 7)         	/**< Write Protection     */
#define DFC_STANDEN       	(0x01ul << 4)         	/**< Standby mode enable  */

/*******************************************************************************
* CSR, CR, IER, IDR, IMR : DFC Status and Interrupt Registers
*******************************************************************************/
#define DFC_DACCESS			(0x01ul << 2)           /**< Denied Access         */
#define DFC_ENDERASE    	(0x01ul << 1)           /**< End Erase             */
#define DFC_ENDWR       	(0x01ul << 0)           /**< End Write             */

/* SR register only */
#define DFC_BUSY 			(0x01ul << 8)           /**< Flash Busy            */

/*******************************************************************************
*****************************  DFC REGISTER MASK  ******************************
*******************************************************************************/
#define DFC_ECR_MASK 		(0x00000002ul)     	 	/**< ECR mask              */
#define DFC_DCR_MASK      	(0x00000002ul)      	/**< DCR mask              */
#define DFC_PMSR_MASK     	(0x3FFFFFF2ul)     	 	/**< PMSR mask             */
#define DFC_CR_MASK       	(0xFE00FF06ul)      	/**< CR mask               */
#define DFC_MR_MASK       	(0xFF00FF90ul)      	/**< MR mask               */
#define DFC_CSR_MASK      	(0x00000007ul)      	/**< CSR mask              */
#define DFC_SR_MASK       	(0x00000017ul)      	/**< SR mask               */
#define DFC_IER_MASK      	(0x00000007ul)      	/**< IER mask              */
#define DFC_IDR_MASK      	(0x00000007ul)      	/**< IDR mask              */
#define DFC_IMR_MASK      	(0x00000007ul)      	/**< IMR mask              */

/*******************************************************************************
***********************  DFC REGISTERS RESET VALUE  ****************************
*******************************************************************************/
#define DFC_ECR_RST			(0x00000000ul)     		/**< ECR reset value      */
#define DFC_DCR_RST       	(0x00000000ul)      	/**< DCR reset value      */
#define DFC_PMSR_RST    	(IPIDCODE_ASB_DFC0)		/**< PMSR reset value     */
#define DFC_CR_RST        	(0x00000000ul)      	/**< CR reset value       */
#define DFC_MR_RST        	(0x80000090ul)      	/**< MR reset value       */
#define DFC_CSR_RST       	(0x00000000ul)      	/**< CSR reset value      */
#define DFC_SR_RST        	(0x00000000ul)      	/**< SR reset value       */
#define DFC_IER_RST       	(0x00000000ul)      	/**< IER reset value      */
#define DFC_IDR_RST       	(0x00000000ul)     	 	/**< IDR reset value      */
#define DFC_IMR_RST       	(0x00000000ul)      	/**< IMR reset value      */

/*******************************************************************************
**************************  DFC MACROS DEFINITION  *****************************
*******************************************************************************/
/* ECR, DCR, PMSR: DFC Clock and Power Management Status Register            */
/** Set ECR register (Enable)                                                */
#define CSP_DFC_SET_ECR(dfc, val)		((dfc)->ECR = (val))
/** Set DCR register (Disable)                                               */
#define CSP_DFC_SET_DCR(dfc, val)   	((dfc)->DCR = (val))
/** Get PMSR register (Status)                                               */
#define CSP_DFC_GET_PMSR(dfc)        	((dfc)->PMSR) 

/* CR : DFC Control Register                                                 */
/** Set CR register                                                          */
#define CSP_DFC_SET_CR(dfc, val)     	((dfc)->CR = ((val) | DFC_CRKEY))

/* MR : DFC Mode Register                                                    */
/** Get MR register                                                          */
#define CSP_DFC_GET_MR(dfc)          	((dfc)->MR)
/** Set MR register                                                          */
#define CSP_DFC_SET_MR(dfc, mode)   	((dfc)->MR = ((mode) | DFC_MRKEY))

/* CSR, SR : DFC Status Registers                                            */
/** Set CSR register (Clear)                                                 */
#define CSP_DFC_SET_CSR(dfc, val)   	((dfc)->CSR = (val))
/** Get SR register (Status)                                                 */
#define CSP_DFC_GET_SR(dfc)          	((dfc)->SR)               

/* IER, IDR, IMR : DFC Interrupt Registers                                   */
/** Set IER register (Enable)                                                */
#define CSP_DFC_SET_IER(dfc, val)   	((dfc)->IER = (val))    
/** Set IDR register (Disable)                                               */
#define CSP_DFC_SET_IDR(dfc, val)    	((dfc)->IDR = (val))
/** Get IMR register (Status)                                                */
#define CSP_DFC_GET_IMR(dfc)         	((dfc)->IMR)

/*******************************************************************************
***********************    DFC EXTERNAL FUNCTIONS   ****************************
*******************************************************************************/
extern void CSP_DFC_ConfigInterrupt(CSP_DFC_T *const dfc,
										U32_T int_mode, 
                               		    U32_T int_mask,
                               		    U32_T callback);
extern void CSP_DFC_PageErase(CSP_DFC_T *const dfc, 
									U32_T sector,
									U32_T page);
extern void CSP_DFC_SectorErase(CSP_DFC_T *const dfc, U32_T sector);
extern void CSP_DFC_ChipErase(CSP_DFC_T *const dfc);

#endif	/* _CSP_DFC_H */



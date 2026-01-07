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
* @file name	csp_ifc.h
* @description	Definitions, Macros and function declarations 
*            	for IFC module
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
*			|0.1 MOD 09/12/2005  Windy 					   csp define format 	
*	 		 -------------------------------------------------------------------
*
* @see	ADS Compiler Tool
*		Module/Drivers/Processor/Board -
*		IFC/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 

#ifndef _CSP_IFC_H
#define _CSP_IFC_H


/*******************************************************************************
*********************  IFC(flahsSTRUCTURE DEFINITION   *************************
*******************************************************************************/
typedef struct
{ 
	CSP_REGISTER_T		ReservedA[22];
   	CSP_REGISTER_T     	PMSR;         /**< Power Management Status Register    */
   	CSP_REGISTER_T     	ReservedB;
   	CSP_REGISTER_T     	CR;           /**< Control Register                    */
   	CSP_REGISTER_T     	MR;           /**< Mode Register                       */
   	CSP_REGISTER_T     	ReservedC;
   	CSP_REGISTER_T     	CSR;          /**< Clear Status Register               */
   	CSP_REGISTER_T     	SR;           /**< Status Register                     */
   	CSP_REGISTER_T     	IER;          /**< Interrupt Enable Register           */
   	CSP_REGISTER_T     	IDR;          /**< Interrupt Disable Register          */
   	CSP_REGISTER_T     	IMR;          /**< Interrupt Mask Register             */
}CSP_IFC_T, *CSP_IFC_PTR;


/*******************************************************************************
************************   IFC REGISTERS DEFINITION   **************************
*******************************************************************************/	

/*******************************************************************************
 CR Register
*******************************************************************************/
#define IFC_SE 				(0x01ul << 1)         /**< Sector Erase              */
#define IFC_CE          	(0x01ul << 2)         /**< Chip Erase                */
#define IFC_CRKEY_MASK 		(0xFFul << 8)         /**< Control Register Key mask */
#define IFC_CRKEY       	(0x37ul << 8)         /**< Control Register Key      */
#define IFC_SECTOR_MASK		(0x3Ful << 26)        /**< Sector to Erase           */
#define IFC_SECTOR(nb) 		((0x3Ful & nb) << 26) /**< Writing macro             */

/*******************************************************************************
* MR Register
*******************************************************************************/
#define IFC_SPEEDMODE  		(0x01ul << 2)        /**< Speed mode                 */
#define IFC_WPR         	(0x01ul << 7)        /**< Write and Erase protection */
#define IFC_MRKEY_MASK 		(0xFFul << 8)        /**< Mode Register Key mask     */
#define IFC_MRKEY       	(0xACul << 8)        /**< mode Register Key          */
#define IFC_BA_MASK     	(0xFFul << 24)       /**< Sector to Erase            */
#define IFC_BA(val)     	((0xFFul & val) << 24) /**< Writing macro            */

/*******************************************************************************
* CSR, SR, IER, IDR, IMR Registers
*******************************************************************************/
#define IFC_ENDWR      		(0x01ul << 0)          /**< End of Write cycle       */
#define IFC_ENDERASE    	(0x01ul << 1)          /**< End of Erase cycle       */
#define IFC_DACCESS     	(0x01ul << 2)          /**< Denied Access            */

/* SR regsiter only */
#define IFC_BUSY        	(0x01ul << 8)          /**< Flash busy               */

/*******************************************************************************
*****************************  IFC REGISTER MASK  ******************************
*******************************************************************************/
 #define IFC_IPIDCODE_MASK		(0x03FFFFFul << 4) /**< IFC IPIDCODE            */
#define IFC_CR_MASK    			(0xFC00FF06ul)         /**< CR mask                 */
#define IFC_MR_MASK     		(0xFF00FF84ul)         /**< MR mask                 */
#define IFC_CSR_MASK     		(0x00000007ul)         /**< CSR mask                */
#define IFC_SR_MASK      		(0x00000107ul)         /**< SR mask                 */
#define IFC_IER_MASK     		(0x00000007ul)         /**< IER mask                */
#define IFC_IDR_MASK     		(0x00000007ul)         /**< IDR mask                */
#define IFC_IMR_MASK			(0x00000007ul)         /**< IMR mask                */

/*******************************************************************************
************************  IFC REGISTERS RESET VALUE  ***************************
*******************************************************************************/
#define IFC_PMSR_RST	(IPIDCODE_ASB_IFC0)	/**< PMSR reset value         */
#define IFC_CR_RST		(0x00000000ul)        /**< CR reset value           */
#define IFC_MR_RST		(0x00000080ul)        /**< MR reset value           */
#define IFC_CSR_RST		(0x00000000ul)        /**< CSR reset value          */
#define IFC_SR_RST    	(0x00000000ul)        /**< SR reset value           */
#define IFC_IER_RST   	(0x00000000ul)        /**< IER reset value          */
#define IFC_IDR_RST   	(0x00000000ul)        /**< IDR reset value          */
#define IFC_IMR_RST   	(0x00000000ul)        /**< IMR reset value          */


/*******************************************************************************
**************************  IFC MACROS DEFINITION   ****************************
*******************************************************************************/
/** CR : IFC Control Register                                                */
#define CSP_IFC_SET_CR(ifc,val)				((ifc)->CR = ((val) | IFC_CRKEY))

/* MR : IFC Mode Register                                                    */
/** Get MR register (Mode Register)                                          */
#define CSP_IFC_GET_MR(ifc)               ((ifc)->MR)
/** Set MR register (Mode Register)                                          */
#define CSP_IFC_SET_MR(ifc,mode)        	((ifc)->MR = ((mode) | IFC_MRKEY))

/* CSR, SR : IFC Status Register                                             */
/** Set CSR register (Clear Status Register)                                 */
#define CSP_IFC_SET_CSR(ifc,val)  			((ifc)->CSR = (val))
/** Get SR register (Status Register)                                        */
#define CSP_IFC_GET_SR(ifc)            		((ifc)->SR)

/* IER, IDR, IMR : IFC Interrupt Registers                                   */
/** Set IER register (Enable Interrupt)                                      */
#define CSP_IFC_SET_IER(ifc,val)   			((ifc)->IER = (val))
/** Set IDR register (Disable Interrupt)                                     */
#define CSP_IFC_SET_IDR(ifc,val)     		((ifc)->IDR = (val))
/** Get IMR register (Status Interrupt)                                      */
#define CSP_IFC_GET_IMR(ifc)           		((ifc)->IMR)

/*******************************************************************************
* IFC CSP Driver Enum Declaration
*******************************************************************************/
typedef enum
{
	CSP_IFC_OK = 0,
   	CSP_IFC_BUSY,
   	CSP_IFC_WRITE_ERROR,    
   	CSP_IFC_INVALID_PARAMETER    
}CSP_IFC_ERROR_E;


/*******************************************************************************
* IFC CSP Driver Enum Declaration
*******************************************************************************/
typedef enum
{
	CSP_IFC_POLLING_ON_BUSY = 0,
   	CSP_IFC_POLLING,
   	CSP_IFC_INTERRUPT   
}CSP_IFC_MODE_E;

/*******************************************************************************
* IFC CSP Driver Enum Declaration
*******************************************************************************/
typedef enum
{
	CSP_IFC_ERASING_SECTOR = 0,
   	CSP_IFC_ERASING_CHIP,
   	CSP_IFC_ERASING,
   	CSP_IFC_WRITING,
   	CSP_IFC_TIMEOUT,
   	CSP_IFC_NOT_BUSY   
}CSP_IFC_STATUS_E;

/******************************************************************************
** IFC CSP Driver Declaration
*******************************************************************************/
typedef struct
{
   U32_T             *source_ptr_u32;
   U32_T             *destination_ptr_u32;
   U32_T             nb_data_u32;
   CSP_IFC_STATUS_E  status_e;
}CSP_IFC_STATUS_T, CSP_IFC_STATUS_PTR;


/*******************************************************************************
* IFC CSP Driver
*******************************************************************************/
extern CSP_IFC_STATUS_T CSP_IFCStatus_t;

/*******************************************************************************
***********************   IFC EXTERNAL FUNCTIONS   *****************************
*******************************************************************************/
extern void CSP_IFCInit(CSP_IFC_T *const ifc,U32_T mode_u32);
extern void CSP_IFCConfigInterrupt(CSP_IFC_T *const ifc,
									U32_T Mode_u32, 						    			
                                  	U32_T Mask_u32, 						   
                                  	U32_T callback_u32);
extern CSP_IFC_ERROR_E CSP_IFCChipErase(CSP_IFC_T *const ifc,CSP_IFC_MODE_E mode_e);
extern CSP_IFC_ERROR_E CSP_IFCSectorErase(CSP_IFC_T *const ifc,CSP_IFC_MODE_E mode_e, 
                                    		U8_T sector_u8);
extern CSP_IFC_ERROR_E CSP_IFCWrite(CSP_IFC_T *const ifc,
										CSP_IFC_MODE_E mode_e, 
                                    	U32_T *dest_ptr_u32, 
                                    	U32_T *src_ptr_u32,
                                    	U32_T nb_data_u32);

#endif   /* _CSP_IFC_H */

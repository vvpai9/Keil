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
* @file name	csp_sfm.h
* @description	Definitions, Macros and function declarations 
*            	for Special Function module
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
*		SFM/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 

#ifndef CSP_SFM_H
#define CSP_SFM_H


/******************************************************************************
************************* SFM Structure Definition ****************************
******************************************************************************/
/**
*******************************************************************************
@brief CAN Interface Structure
*******************************************************************************
*/
typedef struct
{
   CSP_REGISTER_T CIDR;              /**< CHIP ID Register                   */
   CSP_REGISTER_T ARCR;              /**< Architecture Register              */
   CSP_REGISTER_T MSR;               /**< Memory Size Register               */
} CSP_SFM_T, *CSP_SFM_PTR;


/******************************************************************************
************************** SFM Registers Definition ***************************
******************************************************************************/

/******************************************************************************
* CIDR : SFM Chip ID Register
******************************************************************************/
/* VER : Version                                                             */
#define SFM_VER_MASK    (0x000Ful << 28)               /**< VER Mask         */

/* PN  : Part Number  (Europe Technologies project code)                     */
#define SFM_MET         (0x0000ul << 12)               /**< Metering         */
#define SFM_AUT         (0x1000ul << 12)               /**< Automotive       */
#define SFM_IND         (0x2000ul << 12)               /**< Industry         */
#define SFM_TXT         (0x3000ul << 12)               /**< Teletext         */
#define SFM_MUL         (0x4000ul << 12)               /**< Multimedia       */
#define SFM_PNTYPE_MASK (0xF000ul << 12)               /**< PN Type Mask     */
#define SFM_PNCODE_MASK (0x0FFFul << 12)               /**< PN Code Mask     */
#define SFM_PN_MASK     (PNTYPE_MASK | PNCODE_MASK)    /**< PN Mask          */

/* MC : Manufacturor Code                                                    */
#define SFM_MC_MASK     (0x07FFul << 1)                /**< MC Mask          */


/******************************************************************************
* ARCR : SFM Chip Architecture Register
******************************************************************************/
/* IRAME : Internal RAM Exists                                               */
#define SFM_IRAME       (0x01ul << 17)                 /**< PRAME Mask       */

/* BOOT : Boot on ROM                                                        */
#define SFM_BOOT        (0x01ul << 16)                 /**< BOOT Mask        */

/* NVDE : Non Volatile Data Memory Exists                                    */
#define SFM_NVDE        (0x01ul << 15)                 /**< NVDE Mask        */

/* Memory Types  for NVDT and NVPT                                           */
#define SFM_TYPE_ROM    (0x00ul << 0)                  /**< Type ROM         */
#define SFM_TYPE_EEPROM (0x01ul << 0)                  /**< Type EEPROM      */
#define SFM_TYPE_FLASH  (0x02ul << 0)                  /**< Type FLASH       */
#define SFM_TYPE_FRAM   (0x03ul << 0)                  /**< Type FRAM        */
#define SFM_TYPE_MASK   (0x07ul << 0)                  /**< Type MASK        */

/* NVDT : Non Volatile Data Memory Type                                      */
#define SFM_NVDT_ROM    (SFM_TYPE_ROM << 12)           /**< NVDT ROM         */
#define SFM_NVDT_EEPROM (SFM_TYPE_EEPROM << 12)        /**< NVDT EEPROM      */
#define SFM_NVDT_FLASH  (SFM_TYPE_FLASH << 12)         /**< NVDT FLASH       */
#define SFM_NVDT_FRAM   (SFM_TYPE_FRAM << 12)          /**< NVDT FRAM        */
#define SFM_NVDT_MASK   (SFM_TYPE_MASK << 12)          /**< NVDT Mask        */

/* NVPE : Non Volatile Program Memory Exists                                 */
#define SFM_NVPE        (0x01ul << 11)                 /**< NVPE Mask        */

/* NVPT : Non Volatile Program Memory Type                                   */
#define SFM_NVPT_ROM    (SFM_TYPE_ROM << 8)            /**< NVPT ROM         */
#define SFM_NVPT_EEPROM (SFM_TYPE_EEPROM << 8)         /**< NVPT EEPROM      */
#define SFM_NVPT_FLASH  (SFM_TYPE_FLASH << 8)          /**< NVPT FLASH       */
#define SFM_NVPT_FRAM   (SFM_TYPE_FRAM << 8)           /**< NVPT FRAM        */
#define SFM_NVPT_MASK   (SFM_TYPE_MASK << 8)           /**< NVPT Mask        */

/* ARC : Core Architecture                                                   */
#define SFM_AR7TDMI     (0x00ul << 0)                  /**< AR7TDMI          */
#define SFM_ARM926EJS   (0x01ul << 0)                  /**< ARM926EJS        */
#define SFM_ARM946ES    (0x02ul << 0)                  /**< ARM946ES         */
#define SFM_ARC_MASK    (0x03ul << 0)                  /**< ARC Mask         */



/******************************************************************************
* MSR : SFM Memory Size Register
******************************************************************************/
/* IRAMS : internal RAM Size               (Multiple of 1kb: 1 to  16 kbytes)*/
#define SFM_IRAMS_MASK  (0xFFul << 16)                 /**< IRAMS Mask       */

/* NVDMS  Non Volatile Data Memory Size    (Multiple of 8kb: 8 to 128 kbytes)*/
#define SFM_NVDMS_MASK  (0xFFul << 8)                  /**< NVDMS Mask       */

/* NVPMS : Non Volatile Program Memory Size(Multiple of 8kb: 8 to 128 kbytes)*/
#define SFM_NVPMS_MASK  (0xFFul << 0)                  /**< NVPMS Mask       */


/******************************************************************************
***************************** SFM Registers mask ******************************
******************************************************************************/
#define SFM_CIDR_MASK          (0xFFFFFFFEul)    /**< CIDR mask                 */
#define SFM_ARCR_MASK          (0x0003FF03ul)      /**< ARCR mask                 */
#define SFM_MSR_MASK         (0x00FFFFFFul)    /**< MSR mask                  */


/******************************************************************************
************************* SFM Registers reset value ***************************
******************************************************************************/
#define SFM_CIDR_RST          (0x01040271ul)    /**< CIDR reset value          */
#define SFM_ARCR_RST          (0x0003AA00ul)    /**< ARCR reset value          */
#define SFM_MSR_RST         (0x001F03FFul)    /**< MSR reset value           */


/******************************************************************************
*************************** SFM Macros Definition *****************************
******************************************************************************/
/* CIDR : SFM Chip ID Register                                               */
/** Get CIDR register                                                        */
#define CSP_SFM_GET_CIDR(sfm)       ((sfm)->CIDR)

/* ARCR : SFM Chip Architecture Register                                     */
/** Get ARCR register                                                        */
#define CSP_SFM_GET_ARCR(sfm)       ((sfm)->ARCR)

/* MSR : SFM Memory Size Register                                            */
/** Get MSR register                                                         */
#define CSP_SFM_GET_MSR(sfm)        ((sfm)->MSR)


/******************************************************************************
********************* SFM External Functions Declaration **********************
******************************************************************************/
/* NONE                                                                      */

#endif   /* CSP_SFM_H */

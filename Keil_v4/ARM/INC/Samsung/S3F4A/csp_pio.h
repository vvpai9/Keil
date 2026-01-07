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
* @file name	csp_pio.h
* @description	Definitions, Macros and function declarations 
*            	for Peripheral Input Output module
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
*		PIO/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 

#ifndef CSP_PIO_H
#define CSP_PIO_H


/******************************************************************************
************************ CAPTURE Structure Definition *************************
******************************************************************************/
 typedef struct
 {
    CSP_REGISTER_T  PER;                   /**< PIO Enable Register          */
    CSP_REGISTER_T  PDR;                   /**< PIO Disable Register         */
    CSP_REGISTER_T  PSR;                   /**< PIO Status Register          */              
    CSP_REGISTER_T  ReservedA;
    CSP_REGISTER_T  OER;                   /**< Output Enable Register       */
    CSP_REGISTER_T  ODR;                   /**< Output Disable Register      */
    CSP_REGISTER_T  OSR;                   /**< Output Status Register       */              
    CSP_REGISTER_T  ReservedB[4];         
    CSP_REGISTER_T  WODR;                  /**< Output Enable Register       */
    CSP_REGISTER_T  SODR;                  /**< Output Disable Register      */
    CSP_REGISTER_T  CODR;                  /**< Output Status Register       */  
    CSP_REGISTER_T  ODSR;                  /**< Output Enable Register       */
    CSP_REGISTER_T  PDSR;                  /**< Output Disable Register      */
    CSP_REGISTER_T  MDER;                  /**< Output Status Register       */  
    CSP_REGISTER_T  MDDR;                  /**< Output Enable Register       */
    CSP_REGISTER_T  MDSR;                  /**< Output Disable Register      */
    CSP_REGISTER_T  ReservedC;         
    CSP_REGISTER_T  ECR;                   /**< Enable Clock Register        */
    CSP_REGISTER_T  DCR;                   /**< Disable Clock Register       */
    CSP_REGISTER_T  PMSR;                  /**< Power Management Status 
                                              Register                       */
    CSP_REGISTER_T  ReservedD;      
    CSP_REGISTER_T  CR;                    /**< Control Register             */
    CSP_REGISTER_T  ReservedE[2];          
    CSP_REGISTER_T  CSR;                   /**< Clear Status Register        */
    CSP_REGISTER_T  SR;                    /**< Status Register              */
    CSP_REGISTER_T  IER;                   /**< Interrupt enable Register    */
    CSP_REGISTER_T  IDR;                   /**< Interrupt Disable Register   */
    CSP_REGISTER_T  IMR;                   /**< Interrupt Mask Register      */
 } CSP_PIO_T, *CSP_PIO_PTR; 


/******************************************************************************
************************** PIO Registers Definition ***************************
******************************************************************************/
/******************************************************************************
* OER, ODR, OSR : 
* WODR, SODR, CODR, ODSR, PDSR, MDER, MDDR : PIO Registers, Status Register and 
* MDSR, CSR, SR, IER, IDR, IMR             : Interrupt Registers
******************************************************************************/
 #define PIO_PIO0  (0x01ul << 0)          /**< PIO 0 pin                     */
 #define PIO_PIO1  (0x01ul << 1)          /**< PIO 1 pin                     */
 #define PIO_PIO2  (0x01ul << 2)          /**< PIO 2 pin                     */
 #define PIO_PIO3  (0x01ul << 3)          /**< PIO 3 pin                     */
 #define PIO_PIO4  (0x01ul << 4)          /**< PIO 4 pin                     */
 #define PIO_PIO5  (0x01ul << 5)          /**< PIO 5 pin                     */
 #define PIO_PIO6  (0x01ul << 6)          /**< PIO 6 pin                     */
 #define PIO_PIO7  (0x01ul << 7)          /**< PIO 7 pin                     */
 #define PIO_PIO8  (0x01ul << 8)          /**< PIO 8 pin                     */
 #define PIO_PIO9  (0x01ul << 9)          /**< PIO 9 pin                     */
 #define PIO_PIO10 (0x01ul << 10)         /**< PIO 10 pin                    */
 #define PIO_PIO11 (0x01ul << 11)         /**< PIO 11 pin                    */
 #define PIO_PIO12 (0x01ul << 12)         /**< PIO 12 pin                    */
 #define PIO_PIO13 (0x01ul << 13)         /**< PIO 13 pin                    */
 #define PIO_PIO14 (0x01ul << 14)         /**< PIO 14 pin                    */
 #define PIO_PIO15 (0x01ul << 15)         /**< PIO 15 pin                    */
 #define PIO_PIO16 (0x01ul << 16)         /**< PIO 16 pin                    */
 #define PIO_PIO17 (0x01ul << 17)         /**< PIO 17 pin                    */
 #define PIO_PIO18 (0x01ul << 18)         /**< PIO 18 pin                    */
 #define PIO_PIO19 (0x01ul << 19)         /**< PIO 19 pin                    */
 #define PIO_PIO20 (0x01ul << 20)         /**< PIO 20 pin                    */
 #define PIO_PIO21 (0x01ul << 21)         /**< PIO 21 pin                    */
 #define PIO_PIO22 (0x01ul << 22)         /**< PIO 22 pin                    */
 #define PIO_PIO23 (0x01ul << 23)         /**< PIO 23 pin                    */
 #define PIO_PIO24 (0x01ul << 24)         /**< PIO 24 pin                    */
 #define PIO_PIO25 (0x01ul << 25)         /**< PIO 25 pin                    */
 #define PIO_PIO26 (0x01ul << 26)         /**< PIO 26 pin                    */
 #define PIO_PIO27 (0x01ul << 27)         /**< PIO 27 pin                    */
 #define PIO_PIO28 (0x01ul << 28)         /**< PIO 28 pin                    */
 #define PIO_PIO29 (0x01ul << 29)         /**< PIO 29 pin                    */
 #define PIO_PIO30 (0x01ul << 30)         /**< PIO 30 pin                    */
 #define PIO_PIO31 (0x01ul << 31)         /**< PIO 31 pin                    */ 

/******************************************************************************
* ECR, DCR, PMSR : PIO Power Management Registers
******************************************************************************/
 #define PIO_PIO                (0x01ul << 0)  /**< PIO Clock                */
 
 #define PIO_IPIDCODE_MASK  (0x3FFFFFFul << 4) /**< PIO IPIDCODE mask        */

/******************************************************************************
* CR : PIO Control Register 
******************************************************************************/
 #define PIO_SWRST              (0x01ul << 0)  /**< PIO Software Reset       */

/******************************************************************************
***************************** PIO Registers mask ******************************
******************************************************************************/
 #define PIO_PER_MASK          (0xFFFFFFFFul)    /**< PER mask               */
 #define PIO_PDR_MASK          (0xFFFFFFFFul)    /**< PDR mask               */
 #define PIO_PSR_MASK          (0xFFFFFFFFul)    /**< PSR mask               */
 #define PIO_OER_MASK          (0xFFFFFFFFul)    /**< OER mask               */
 #define PIO_ODR_MASK          (0xFFFFFFFFul)    /**< ODR mask               */
 #define PIO_OSR_MASK          (0xFFFFFFFFul)    /**< OSR mask               */
 #define PIO_WODR_MASK         (0xFFFFFFFFul)    /**< WODR mask              */
 #define PIO_SODR_MASK         (0xFFFFFFFFul)    /**< SODR mask              */
 #define PIO_CODR_MASK         (0xFFFFFFFFul)    /**< CODR mask              */
 #define PIO_ODSR_MASK         (0xFFFFFFFFul)    /**< ODSR mask              */
 #define PIO_PDSR_MASK         (0xFFFFFFFFul)    /**< PDSR mask              */
 #define PIO_MDER_MASK         (0xFFFFFFFFul)    /**< MDER mask              */
 #define PIO_MDDR_MASK         (0xFFFFFFFFul)    /**< MDDR mask              */
 #define PIO_MDSR_MASK         (0xFFFFFFFFul)    /**< MDSR mask              */
 #define PIO_ECR_MASK          (0xFFFFFFFFul)    /**< ECR mask               */
 #define PIO_DCR_MASK          (0xFFFFFFFFul)    /**< DCR mask               */
 #define PIO_PMSR_MASK         (0xFFFFFFFFul)    /**< PMSR mask              */
 #define PIO_CR_MASK           (0xFFFFFFFFul)    /**< CR mask                */
 #define PIO_MR_MASK           (0xFFFFFFFFul)    /**< MR mask                */
 #define PIO_CSR_MASK          (0xFFFFFFFFul)    /**< CSR mask               */
 #define PIO_SR_MASK           (0xFFFFFFFFul)    /**< SR mask                */
 #define PIO_IER_MASK          (0xFFFFFFFFul)    /**< IER mask               */
 #define PIO_IDR_MASK          (0xFFFFFFFFul)    /**< IDR mask               */
 #define PIO_IMR_MASK          (0xFFFFFFFFul)    /**< IMR mask               */
              
/******************************************************************************
************************* PIO Registers reset value ***************************
******************************************************************************/
 #define PIO_PER_RST          (0x00000000ul)    /**< PER reset value         */
 #define PIO_PDR_RST          (0x00000000ul)    /**< PDR reset value         */
 #define PIO_PSR_RST          (0xFFFFFFFFul)    /**< PSR reset value         */
 #define PIO_OER_RST          (0x00000000ul)    /**< OER reset value         */
 #define PIO_ODR_RST          (0x00000000ul)    /**< ODR reset value         */
 #define PIO_OSR_RST          (0x00000000ul)    /**< OSR reset value         */
 #define PIO_WODR_RST         (0x00000000ul)    /**< WODR reset value        */
 #define PIO_SODR_RST         (0x00000000ul)    /**< SODR reset value        */
 #define PIO_CODR_RST         (0x00000000ul)    /**< CODR reset value        */
 #define PIO_ODSR_RST         (0x00000000ul)    /**< ODSR reset value        */
 #define PIO_MDER_RST         (0x00000000ul)    /**< MDER reset value        */
 #define PIO_MDDR_RST         (0x00000000ul)    /**< MDDR reset value        */
 #define PIO_MDSR_RST         (0x00000000ul)    /**< MDSR reset value        */
 #define PIO_ECR_RST          (0x00000000ul)    /**< ECR reset value         */
 #define PIO_DCR_RST          (0x00000000ul)    /**< DCR reset value         */
 #define PIO_PMSR_RST         (IPIDCODE_PIO0)   /**< PMSR reset value        */
 #define PIO_CR_RST           (0x00000000ul)    /**< CR reset value          */
 #define PIO_MR_RST           (0x00000000ul)    /**< MR reset value          */
 #define PIO_CSR_RST          (0x00000000ul)    /**< CSR reset value         */
 #define PIO_SR_RST           (0x00000000ul)    /**< SR reset value          */
 #define PIO_IER_RST          (0x00000000ul)    /**< IER reset value         */
 #define PIO_IDR_RST          (0x00000000ul)    /**< IDR reset value         */
 #define PIO_IMR_RST          (0x00000000ul)    /**< IMR reset value         */


/******************************************************************************
*************************** PIO Macros Definition *****************************
******************************************************************************/
/* PER, PDR, PSR : PIO Enable Registers                                      */
/** Set ECR register (Enable)                                                */
 #define CSP_PIO_SET_PER(pio, val)       ((pio)->PER = (val))
/** Set DCR register (Disable)                                               */
 #define CSP_PIO_SET_PDR(pio, val)       ((pio)->PDR = (val))
/** Get PMSR register (Status)                                               */
 #define CSP_PIO_GET_PSR(pio)            ((pio)->PSR)

/* OER, ODR, OSR : PIO Output Registers                                      */
/** Set OER register (Enable)                                                */
 #define CSP_PIO_SET_OER(pio, val)       ((pio)->OER = (val))
/** Set ODR register (Disable)                                               */
 #define CSP_PIO_SET_ODR(pio, val)       ((pio)->ODR = (val))
/** Get OSR register (Status)                                                */ 
 #define CSP_PIO_GET_OSR(pio)            ((pio)->OSR)

/* WODR, SODR, CODR, ODSR : PIO Control level Registers                      */
/** Set WODR register (Write)                                                */
 #define CSP_PIO_SET_WODR(pio, val)       ((pio)->WODR = (val))
/** Set SODR register (Set)                                                  */
 #define CSP_PIO_SET_SODR(pio, val)       ((pio)->SODR = (val))
/** Set CODR register (Clear)                                                */ 
 #define CSP_PIO_SET_CODR(pio, val)       ((pio)->CODR = (val))
/** Get ODSR register (Status)                                               */ 
 #define CSP_PIO_GET_ODSR(pio)            ((pio)->ODSR)

/* PDSR : PIO Status Registers                                               */
/** Get PDSR register (Pin Status)                                           */
 #define CSP_PIO_GET_PDSR(pio)            ((pio)->PDSR)

/* MDER, MDDR, MDSR : PIO Multi Driver Control Registers   */  
/** Set MDER register (Enable)                                               */
 #define CSP_PIO_SET_MDER(pio, val)       ((pio)->MDER = (val))
/** Set MDDR register (Disable)                                              */
 #define CSP_PIO_SET_MDDR(pio, val)       ((pio)->MDDR = (val))
/** Get MDST register (Status)                                               */
 #define CSP_PIO_GET_MDSR(pio)            ((pio)->MDSR)

/* ECR, DCR, PMSR : PIO Power Management Registers                           */
/** Set ECR register (Enable)                                                */
 #define CSP_PIO_SET_ECR(pio, val)       ((pio)->ECR = (val))
/** Set DCR register (Disable)                                               */
 #define CSP_PIO_SET_DCR(pio, val)       ((pio)->DCR = (val))
/** Set PMSR register (Status)                                               */
 #define CSP_PIO_GET_PMSR(pio)           ((pio)->PMSR)

/* CR : PIO Control Register                                                 */
 #define CSP_PIO_SET_CR(pio, val)        ((pio)->CR = (val))

/* CSR, SR : PIO Status Registers                                            */
/** Set CSR register (Clear Status Register)                                 */
 #define CSP_PIO_SET_CSR(pio, val)       ((pio)->CSR = (val))
/** Get SR register (Status Register)                                        */
 #define CSP_PIO_GET_SR(pio)             ((pio)->SR)

/* IER, IDR, IMR : PIO Interrupt Registers                                   */
/** Set IER register (Enable Interrupt)                                      */
 #define CSP_PIO_SET_IER(pio, val)       ((pio)->IER = (val))
/** Set IDR register (Disable Interrupt)                                     */
 #define CSP_PIO_SET_IDR(pio, val)       ((pio)->IDR = (val))
/** Get IMR register (Status Interrupt)                                      */
 #define CSP_PIO_GET_IMR(pio)            ((pio)->IMR)


/******************************************************************************
********************* PIO External Functions Declaration **********************
******************************************************************************/
extern void CSP_PIOInit(CSP_PIO_T *const pio, U32_T pioOutput_u32, U32_T pioMultidriver_u32);
extern void CSP_PIOClose(CSP_PIO_T *const pio);
extern void CSP_PIOConfigInterrupt(CSP_PIO_T *const pio, 
                                   U32_T intMode_u32, 
                                   U32_T intMask_u32, 
                                   U32_T callback_u32);
extern U32_T CSP_PIOGetStatus(CSP_PIO_T *const pio);
extern void CSP_PIOClear(CSP_PIO_T *const pio, U32_T pioMask_u32);
extern void CSP_PIOSet(CSP_PIO_T *const pio, U32_T pioMask_u32);
extern CSP_REGISTER_T CSP_PIOGetBlockMask(CSP_PIO_T *const pio);
extern U8_T CSP_PIOGetBlockNumber(CSP_PIO_T *const pio);


#endif   /**< CSP_PIO_H */

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
* @file name	csp_i2c.h
* @description	Definitions, Macros and function declarations 
*            	for I2C module
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
*		I2C/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 

#ifndef _CSP_I2C_H
#define _CSP_I2C_H

/******************************************************************************
************************* I2C STRUCTURE DEFINITION  ***************************
******************************************************************************/
typedef struct
{
	CSP_REGISTER_T	ReservedA[20];
    CSP_REGISTER_T  ECR;           /* Enable Clock Register                  */
    CSP_REGISTER_T  DCR;           /* Disable Clock Register                 */
    CSP_REGISTER_T  PMSR;          /* Power Management Status Register       */
    CSP_REGISTER_T  ReservedD;     
    CSP_REGISTER_T  CR;            /* Control Register                       */
    CSP_REGISTER_T  MR;            /* Mode Register                          */
    CSP_REGISTER_T  ReservedE;
    CSP_REGISTER_T  CSR;           /* Clear Status Register                  */
    CSP_REGISTER_T  SR;            /* Status Register                        */
    CSP_REGISTER_T  IER;           /* Interrupt Enable Register              */
    CSP_REGISTER_T  IDR;           /* Interrupt Enable Register              */
    CSP_REGISTER_T  IMR;           /* Interrupt Enable Register              */
    CSP_REGISTER_T  DAT;           /* Serial Data Register                   */
    CSP_REGISTER_T  ADR;           /* Serial Slave Address Register          */
    CSP_REGISTER_T  THOLD;         /* Hold/Setup Delay Register              */
}CSP_I2C_T, *CSP_I2C_PTR;


/*******************************************************************************
***********************    I2C REGISTERS DEFINITION   **************************
*******************************************************************************/	

/*******************************************************************************
* ECR, DCR, PMSR : I2C Power Management Registers
*******************************************************************************/
#define I2C_I2C     		(0x01ul << 1)    /**< I2C Clock                 */
#define I2C_IPIDCODE      	(0x01ul << 4)    /**< I2C version number        */
#define I2C_DBGEN         	(0x01ul << 31)   /**< Debug Mode Enable         */

/*******************************************************************************
* CR : I2C Control Register 
*******************************************************************************/
#define I2C_SWRST       	(0x01ul << 0)   /**< I2C Software Reset          */
#define I2C_AA            	(0x01ul << 1)   /**< I2C Acknowledge Mask        */ 
#define I2C_AA_NO         	(0x00ul << 1)   /**< I2C No Acknowledge          */ 
#define I2C_AA_RET        	(0x01ul << 1)   /**< I2C Acknowledge Returned    */ 
#define I2C_STO           	(0x01ul << 2)   /**< I2C Stop                    */
#define I2C_STA           	(0x01ul << 3)   /**< I2C Start Mask              */             
#define I2C_STA_MASTER   	(0x01ul << 3)   /**< I2C Start Master            */
#define I2C_STA_SLAVE    	(0x00ul << 3)   /**< I2C Start Slave             */
#define I2C_SI            	(0x01ul << 4)   /**< I2C Interrupt Mask          */
#define I2C_SI_SET        	(0x01ul << 4)   /**< I2C Interrupt Mask          */
#define I2C_SI_CLR        	(0x00ul << 4)   /**< I2C Interrupt Mask          */
#define I2C_ENA            	(0x01ul << 8)   /**< I2C Enable Mask             */
#define I2C_ENABLE        	(0x01ul << 8)   /**< I2C Enable                  */
#define I2C_DISABLE       	(0x00ul << 8)   /**< I2C Disable                 */  
    
/*******************************************************************************
* MR : I2C Mode Register
*******************************************************************************/
/** PRV : Prescaler Value                                                    */
#define I2C_PRV_MASK		(0xFFFul << 0)           /**< Prescaler Value Mask */
#define I2C_PRV(val)  		(((val) & 0xFFFul) << 0) /**< Prescaler Value 
														Writing Macro    	 */
#define I2C_FAST      		(0x01ul  << 12)          /**< En/Disable Fast Mode*/

/*******************************************************************************
* SR : I2C Status Register
*******************************************************************************/                     
#define I2C_SC_MASK 		(0xFFul << 0)              /* Status Code Mask    */

/*******************************************************************************
* Master Transmitter mode status codes
*******************************************************************************/
#define I2C_MTX_START   		0x08u  /* START condition has been transmitted*/
#define I2C_MTX_RSTART    		0x10u  /* REPEAT START condition has been*/ 
									  /* transmitted */
#define I2C_MTX_SADDR_ACK 		0x18u  /* Slave address and 				  */
									  /* WRITE has been sent,ACK received    */
#define I2C_MTX_SADDR_NACK 	 	0x20u  /* Slave address and WRITE 		  */
									   /* has been sent, No ACK received 	  */
#define I2C_MTX_DATATX_ACK   	0x28u  /* Data byte transmitted,ACK received*/
#define I2C_MTX_DATATX_NACK  	0x30u  /* Data byte transmitted,                                                        No ACK received            */
#define I2C_MTX_AL            	0x38u  /* Arbitration lost           `	  */

/*******************************************************************************
* Master Receiver mode status codes
*******************************************************************************/
#define I2C_MRX_START  			0x08u  /* START condition has been transmitted */
#define I2C_MRX_RSTART       	0x10u  /* REPEAT START condition has */
									  /* been transmitted           */
#define I2C_MRX_AL            	0x38u  /* Arbitration lost           */
#define I2C_MRX_SADDR_ACK    	0x40u  /* Slave address and Read has                                                    been sent, ACK received    */
#define I2C_MRX_SADDR_NACK   	0x48u  /* Slave address and Read has                                                    been sent, No ACK received */ 
#define I2C_MRX_DATARX_ACK   	0x50u  /* Data byte received,                                                           ACK returned               */
#define I2C_MRX_DATARX_NACK  	0x58u  /* Data byte received,                                                           No ACK returned            */

/******************************************************************************
* Slave Receiver mode status codes
******************************************************************************/
#define I2C_SRX_OADDR_WRI_ACK			0x60u   /* Own Slave address + WRITE */
                                     	       /* received, ACK returned     */
#define I2C_SRX_AL_OADDR_ACK        	0x68u  /* Arbitration lost, own slave                                    address received,                                                             ACK returned               */                                               
#define I2C_SRX_GCA_ACK              	0x70u  /* General Call Address has                                                     been received, ACK returned*/
#define I2C_SRX_AL_GCADDR_ACK       	0x78u  /* Arbitration lost, general                                 call address received,                                                        ACK returned               */
#define I2C_SRX_OADDR_DATARX_ACK     0x80u  /* Addressed with own address                                   and W, data byte received,                                                    ACK returned               */
#define I2C_SRX_OADDR_DATARX_NACK    0x88u  /* Addressed with own address,                                                   data byte received,                                                           no ACK returned            */
#define I2C_SRX_GCADDR_DATARX_ACK    0x90u  /* Addressed by general call                                 address, data byte received,                                                  ACK returned               */
#define I2C_SRX_GCADDR_DATARX_NACK   0x98u  /* Addressed by general call        address, data byte received,                                                no ACK returned            */
#define I2C_SRX_STOP_START           	0xA0u  /* A stop or repeated start         has been received while                                                       still addressed as slave   */

/*****************************************************************************
* Slave Transmitter mode status codes
******************************************************************************/
#define I2C_STX_OADDR_READ_ACK		0xA8u  /**< Own Slave address +        */
                                            /**< R received, ACK returned   */ 
#define I2C_STX_AL_OADDR_ACK 		0xB0u  /**< Arbitration lost, own slave*/
                                             /**< address has been received, */
                                             /**< ACK returned               */
#define I2C_STX_DATATX_ACK    0xB8u  /**< Data has been transmitted, */
                                	             /**< ACK has been received      */
#define I2C_STX_DATATX_NACK   0xC0u  /**< Data has been transmitted, */
                                             /**< No ACK has been received   */
#define I2C_STX_LDATATX_ACK   0xC8u  /**< Last data has been                                                   transmitted, ACK received  */

/*****************************************************************************
* Miscellaneous status codes
******************************************************************************/
#define I2C_NO_INFORMATION	0xF8u 	/**< No revelant state information */
#define I2C_BUS_ERROR     	 0x00u  /**< Bus error due to an illegal*/
                                   /**< START or STOP condition    */

/******************************************************************************
*  IER, IDR, IMR : I2C Interrupt Registers
******************************************************************************/
/* I2C_SI  : I2C Interrupt - Same as CR Register                             */

/*******************************************************************************
*  DAT : I2C Serial Data Registers
*******************************************************************************/
#define I2C_DATA_MASK   	(0xFFul << 0)            /**< Data Mask            */
#define I2C_DATA(val)    	(((val) & 0xFFul) << 0)  /**< Data Writing Macro   */

/*******************************************************************************
*  ADR : I2C Serial Slave Address Registers
*******************************************************************************/
#define I2C_GC         		(0x01ul << 0)            /**< General call           */  
#define I2C_ADDR_MASK   	(0x7Ful << 1)           /**< Address Mask           */
#define I2C_ADDR(val)   	(((val) & 0x7Ful) << 1) /**< Writing Macro          */

/*******************************************************************************
*  ADR : I2C Hold/Setup Delay Registers
*******************************************************************************/
#define I2C_DL_MASK    (0xFFul << 0)             /**< Hold/Setup Delay Mask */
#define I2C_DL(val)    (((val) & 0xFFul) << 0)   /**< Hold/Setup Delay      */

/*******************************************************************************
***************************** I2C REGISTER MASK  *******************************
********************************************************************************/
#define I2C_ECR_MASK 		(0x80000002ul)    /**< ECR mask               */
#define I2C_DCR_MASK      	(0x80000002ul)    /**< DCR mask               */
#define I2C_PMSR_MASK     	(0x00000002ul)    /**< PMSR mask              */
#define I2C_CR_MASK       	(0x0000000Ful)    /**< CR mask                */
#define I2C_MR_MASK       	(0x00001FFFul)    /**< MR mask                */
#define I2C_CSR_MASK      	(0x0000007Cul)    /**< CSR mask               */
#define I2C_SR_MASK       	(0x000000F8ul)    /**< SR mask                */
#define I2C_IER_MASK      	(0x00000010ul)    /**< IER mask               */
#define I2C_IDR_MASK      	(0x00000010ul)    /**< IDR mask               */
#define I2C_IMR_MASK      	(0x00000010ul)    /**< IMR mask               */
#define I2C_DAT_MASK      	(0x0000000Ful)    /**< DAT mask               */
#define I2C_ADR_MASK      	(0x0000000Ful)    /**< ADR mask               */
#define I2C_THOLD_MASK   	(0x0000000Ful)    /**< THOLD mask             */                    


/*******************************************************************************
************************  I2C REGISTERS RESET VALUE ****************************
*******************************************************************************/
#define I2C_ECR_RST			(0x00000000ul)     /**< ECR reset value         */
#define I2C_DCR_RST       	(0x00000000ul)     /**< DCR reset value         */
#define I2C_PMSR_RST      	(IPIDCODE_I2C0)    /**< PMSR reset value        */
#define I2C_CR_RST        	(0x00000000ul)     /**< CR reset value          */
#define I2C_MR_RST        	(0x000001F4ul)     /**< MR reset value          */
#define I2C_CSR_RST       	(0x00000000ul)     /**< CSR reset value         */
#define I2C_SR_RST        	(0x000000F8ul)     /**< SR reset value          */
#define I2C_IER_RST       	(0x00000000ul)     /**< IER reset value         */
#define I2C_IDR_RST       	(0x00000000ul)     /**< IDR reset value         */
#define I2C_IMR_RST       	(0x00000000ul)     /**< IMR reset value         */
#define I2C_DAT_RST       	(0x00000000ul)     /**< DAT reset value         */
#define I2C_ADR_RST       	(0x00000000ul)     /**< ADR reset value         */
#define I2C_THOLD_RST    	(0x00000001ul)     /**< THOLD reset value       */                  

/*******************************************************************************
**************************  I2C  MACROS DEFINITION  ****************************
*******************************************************************************/
/* ECR, DCR, PMSR : I2C Power Management Registers                           */
/** Set ECR register (Enable)                                                */
 #define CSP_I2C_SET_ECR(i2c, val)      ((i2c)->ECR = (val))
/** Set DCR register (Disable)                                               */
 #define CSP_I2C_SET_DCR(i2c, val)      ((i2c)->DCR = (val))
/** Get PMSR register (Status)                                               */
 #define CSP_I2C_GET_PMSR(i2c)          ((i2c)->PMSR)

/* CR : I2C Control Register                                                 */
/** Get CR register                                                          */
 #define CSP_I2C_GET_CR(i2c)            ((i2c)->CR)
/** Set CR register                                                          */
 #define CSP_I2C_SET_CR(i2c, val)       ((i2c)->CR = (val))

/* MR : I2C Mode Register                                                    */
/** Get MR register                                                          */
 #define CSP_I2C_GET_MR(i2c)            ((i2c)->MR)
/** Set MR register                                                          */
 #define CSP_I2C_SET_MR(i2c, mode)      ((i2c)->MR = (mode))

/* CSR, SR : I2C Status Register                                             */
/** Set CSR register (Clear)                                                 */
 #define CSP_I2C_SET_CSR(i2c, val)      ((i2c)->CSR = (val))
/** Get SR register (Status)                                                 */
 #define CSP_I2C_GET_SR(i2c)            ((i2c)->SR)         

/* IER, IDR, IMR : I2C Interrupt Registers                                   */
/** Set IER register (Enable)                                                */
 #define CSP_I2C_SET_IER(i2c, val)      ((i2c)->IER = (val))
/** Set IDR register (Disable)                                               */
 #define CSP_I2C_SET_IDR(i2c, val)      ((i2c)->IDR = (val))
/** Get IMR register (Mask)                                                  */
 #define CSP_I2C_GET_IMR(i2c)           ((i2c)->IMR)

/* DAT : I2C Serial Data Register                                            */
/** Get DAT register                                                         */
 #define CSP_I2C_GET_DAT(i2c)          ((i2c)->DAT)
/** Set DAT register                                                         */
 #define CSP_I2C_SET_DAT(i2c, val)      ((i2c)->DAT = (val))

/* ADR : I2C Serial Slave Address Register                                   */
/** Get ADR register                                                         */
 #define CSP_I2C_GET_ADR(i2c)           ((i2c)->ADR)
/** Set ADR register                                                         */
 #define CSP_I2C_SET_ADR(i2c, val)      ((i2c)->ADR = (val))

/* THOLD : I2C Hold/Setup Delay Register                                     */
/** Get THOLD register                                                       */
 #define CSP_I2C_GET_THOLD(i2c)         ((i2c)->THOLD)
/** Set THOLD register                                                       */
 #define CSP_I2C_SET_THOLD(i2c, val)    ((i2c)->THOLD = (val))


/*******************************************************************************
*************************   I2C EXTERNAL FUNCTIONS   ***************************
*******************************************************************************/
extern void CSP_I2CInit(CSP_I2C_T *const i2c, 
                        	U32_T mode_u32, 
                        	U32_T thold_u32);
extern void CSP_I2CClose(CSP_I2C_T *const i2c);
extern void CSP_I2CConfigInterrupt(CSP_I2C_T *const i2c, 
                            	       U32_T intMode_u32, 
                                	   U32_T intMask_u32, 
                                   	   U32_T callback_u32);
extern void CSP_I2CModeConfig(CSP_I2C_T *const i2c, 
                              U16_T cr_u16, 
                              U8_T add_u8);
#endif /* _CSP_I2C_H */


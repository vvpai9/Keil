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
* @file name	csp_epc.h
* @description	Definitions, Macros and function declarations 
*            	for External Protocol Controller module
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
*		EPC/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 

#ifndef _CSP_EPC_H
#define _CSP_EPC_H

/*******************************************************************************
************************    EPC STRUCTURE DEFINITION   *************************
*******************************************************************************/

/** Number of Chip Select in the EPC Module                                  */
#define NB_XCS			4u
 
/** Number of Line in an EPC Table                                           */
#define NB_LINE			8u

/*******************************************************************************
* EPC PIO Event Structure
*******************************************************************************/
typedef struct
{
	CSP_REGISTER_T		CSR;         /**< Clear Status Register               */
    CSP_REGISTER_T     	SR;          /**< Status Register                     */
    CSP_REGISTER_T     	IER;         /**< Interrupt Enable Register           */
    CSP_REGISTER_T     	IDR;         /**< Interrupt Disable Register          */
    CSP_REGISTER_T     	IMR;         /**< Interrupt Mask Register             */
}CSP_EPC_PIOEVENT_T, *CSP_EPC_PIOEVENT_PTR;


/*******************************************************************************
* EPC Device Structure
*******************************************************************************/
typedef struct
{
	CSP_REGISTER_T		DSR;         /**< Device Select Register              */  
}CSP_EPC_DEVICE_T, *CSP_EPC_DEVICE_PTR;


/*******************************************************************************
* EPC Read Table, Write Table Structure
*******************************************************************************/
typedef struct
{
	CSP_REGISTER_T		TBLR[NB_LINE];      /**< Table Read                   */
    CSP_REGISTER_T     	TBLW[NB_LINE];      /**< Table Write                  */
}CSP_EPC_TABLE_T, *CSP_EPC_TABLE_PTR;



/*******************************************************************************
* EPC Structure
*******************************************************************************/
typedef struct 
{
	CSP_REGISTER_T		ReservedA[20];
    CSP_REGISTER_T     	ECR;          /**< Enable Clock Register              */
    CSP_REGISTER_T     	DCR;          /**< Disable Clock Register             */
    CSP_REGISTER_T     	PMSR;         /**< Power Management Status Register   */
    CSP_REGISTER_T     	ReservedB;
    CSP_REGISTER_T     	CR;           /**< Control Register                   */
    CSP_REGISTER_T     	ReservedC[2];      
    CSP_EPC_PIOEVENT_T 	PIOEVENT0;    /**< PIO block Event 0                  */
    CSP_REGISTER_T     	PR;           /**< Prescalar Register                 */
    CSP_EPC_DEVICE_T   	DEVICE[NB_XCS];  
    CSP_REGISTER_T     	ReservedD[54];

    CSP_EPC_PIOEVENT_T	PIOEVENT1;    /**< PIO block Event 1                  */
    CSP_REGISTER_T     	WER;          /**< Write Enable Register              */
    CSP_REGISTER_T     	WDR;          /**< Write Disable Register             */
    CSP_REGISTER_T     	WSR;          /**< Write Status Register              */
    CSP_REGISTER_T     	ReservedF[29];
    CSP_EPC_TABLE_T    	TABLE[NB_XCS];/**< Table RAM                          */  
}CSP_EPC_T, *CSP_EPC_PTR;


/*******************************************************************************
* CSR0, SR0, IER0, IDR0, IMR0   : EPC PIO Registers, Status Register and 
* CSR1, SR1, IER1, IDR1, IMR1   : Interrupt Registers
*******************************************************************************/
/* CSR0, SR0, IER0, IDR0 & IMR0 Registers Only                               */
#define EPC_ADDR0		(0x01ul << 0)         /**< ADDR0 pin                */
#define EPC_ADDR1     	(0x01ul << 1)         /**< ADDR1 pin                */
#define EPC_ADDR2     	(0x01ul << 2)         /**< ADDR2 pin                */
#define EPC_ADDR3     	(0x01ul << 3)         /**< ADDR3 pin                */
#define EPC_ADDR4     	(0x01ul << 4)         /**< ADDR4 pin                */
#define EPC_ADDR5     	(0x01ul << 5)         /**< ADDR5 pin                */
#define EPC_ADDR6      (0x01ul << 6)         /**< ADDR6 pin                */
#define EPC_ADDR7     	(0x01ul << 7)         /**< ADDR7 pin                */
#define EPC_ADDR8     	(0x01ul << 8)         /**< ADDR8 pin                */
#define EPC_ADDR9     	(0x01ul << 9)         /**< ADDR9 pin                */
#define EPC_ADDR10    	(0x01ul << 10)        /**< ADDR10 pin               */
#define EPC_ADDR11    	(0x01ul << 11)        /**< ADDR11 pin               */
#define EPC_ADDR12    	(0x01ul << 12)        /**< ADDR12 pin               */
#define EPC_ADDR13    	(0x01ul << 13)        /**< ADDR13 pin               */
#define EPC_ADDR14    	(0x01ul << 14)        /**< ADDR14 pin               */
#define EPC_ADDR15    	(0x01ul << 15)        /**< ADDR15 pin               */
#define EPC_XCS0      	(0x01ul << 16)        /**< XCS0 pin                 */
#define EPC_XCS1      	(0x01ul << 17)        /**< XCS1 pin                 */
#define EPC_XCS2       	(0x01ul << 18)        /**< XCS2 pin                 */
#define EPC_XCS3       	(0x01ul << 19)        /**< XCS3 pin                 */
#define EPC_CTRL0      (0x01ul << 20)        /**< CTRL0 pin                */
#define EPC_CTRL1     	(0x01ul << 21)        /**< CTRL1 pin                */
#define EPC_CTRL2     	(0x01ul << 22)        /**< CTRL2 pin                */
#define EPC_CTRL3     	(0x01ul << 23)        /**< CTRL3 pin                */
#define EPC_DATA0      (0x01ul << 24)        /**< DATA0 pin                */
#define EPC_DATA1     	(0x01ul << 25)        /**< DATA1 pin                */
#define EPC_DATA2      (0x01ul << 26)        /**< DATA2 pin                */
#define EPC_DATA3     	(0x01ul << 27)        /**< DATA3 pin                */
#define EPC_DATA4     	(0x01ul << 28)        /**< DATA4 pin                */
#define EPC_DATA5     	(0x01ul << 29)        /**< DATA5 pin                */
#define EPC_DATA6     	(0x01ul << 30)        /**< DATA6 pin                */
#define EPC_DATA7		(0x01ul << 31)        /**< DATA7 pin                */

/* CSR1, SR1, IER1, IDR1 & IMR1 Registers Only                               */
#define EPC_ADDR16    	(0x01ul << 0)         /**< ADDR16 pin               */
#define EPC_ADDR17    	(0x01ul << 1)         /**< ADDR17 pin               */
#define EPC_ADDR18    	(0x01ul << 2)         /**< ADDR18 pin               */
#define EPC_ADDR19    	(0x01ul << 3)         /**< ADDR19 pin               */
#define EPC_ADDR20    	(0x01ul << 4)         /**< ADDR20 pin               */
#define EPC_ADDR21    	(0x01ul << 5)         /**< ADDR21 pin               */
#define EPC_ADDR22    	(0x01ul << 6)         /**< ADDR22 pin               */
#define EPC_ADDR23    	(0x01ul << 7)         /**< ADDR23 pin               */
#define EPC_DATA8     	(0x01ul << 8)         /**< DATA8 pin                */
#define EPC_DATA9     	(0x01ul << 9)         /**< DATA9 pin                */
#define EPC_DATA10    	(0x01ul << 10)        /**< DATA10 pin               */
#define EPC_DATA11    	(0x01ul << 11)        /**< DATA11 pin               */
#define EPC_DATA12    	(0x01ul << 12)        /**< DATA12 pin               */
#define EPC_DATA13    	(0x01ul << 13)        /**< DATA13 pin               */
#define EPC_DATA14    	(0x01ul << 14)        /**< DATA14 pin               */
#define EPC_DATA15    	(0x01ul << 15)        /**< DATA15 pin               */
#define EPC_CTRL4     	(0x01ul << 16)        /**< CTRL4 pin                */
#define EPC_CLK        	(0x01ul << 17)        /**< CLK pin                  */
#define EPC_NWAITEXT  	(0x01ul << 18)        /**< NWAITEXT pin             */

/* SR1 Register Only                                                         */
#define EPC_BUSY  		(0x01ul << 24)        /**< BUSY signal              */
#define EPC_FLAGSR0   	(0x01ul << 25)        /**< FLAGSR0 signal           */

/*******************************************************************************
* ECR, DCR, PMSR : EPC Power Management Registers
*******************************************************************************/
#define EPC_IPIDCODE_MASK		(0x3FFFFFFul << 4) /**< EPC IPIDCODE mask        */ 
#define EPC_EPC         		(0x01ul << 1)     /**< EPC Clock                */
/* ECR Register Only                                                         */
#define EPC_CLOCKENKEY_MASK 	(0xFFFFul << 16)  /**< Clock Enable Key mask */
#define EPC_CLOCKENKEY  		(0x1903ul << 16)  /**< Clock Enable Key      */
/* DCR Register Only                                                         */
#define EPC_CLOCKDISKEY_MASK	(0xFFFFul << 16) /**< Clock Disable Key mask   */
#define EPC_CLOCKDISKEY 		(0x2808ul << 16) /**< Clock Disable Key        */
    
/*******************************************************************************
* CR : EPC Control Register
*******************************************************************************/
#define EPC_SWRSTEPC			(0x01ul << 1)         /**< EPC Software Reset       */

/*******************************************************************************
* PR : EPC Prescalar Register
*******************************************************************************/
#define EPC_PRESCALAR_MASK  	(0x07ul << 0)         /**< Clock Prescalar      */
#define EPC_PRESCALAR(val)		((val & 0x07ul) << 0) /**< Writing macro        */
#define EPC_CORECLK         	0x00ul    		/**< 16Mbytes External memory */
#define EPC_CORECLK_2       	0x01ul   		/**< 8Mbytes External memory  */
#define EPC_CORECLK_4       	0x02ul           /**< 4Mbytes External memory */
#define EPC_CORECLK_6       	0x03ul           /**< 2Mbytes External memory */
#define EPC_CORECLK_8       	0x04ul           /**< 1Mbytes External memory */
#define EPC_CORECLK_10      	0x05ul           /**< 512Kbytes External memory*/
#define EPC_CORECLK_12      	0x06ul           /**< 1Mbytes External memory  */
#define EPC_CORECLK_14     		0x07ul           /**< 512Kbytes External memory*/

#define EPC_POL             	(0x01ul << 3)         /**< Clock Out Polarity   */

#define EPC_PHASE_MASK   		(0x07ul << 4)         	/**< Phase            */
#define EPC_PHASE(val)      	((val & 0x07ul) << 4)	/**< Writing Macro    */
#define EPC_NO_DELAY          	(0x00ul <<4)     	/**< No Delay             */
#define EPC_1_CORECLK_PERIOD 	(0x01ul <<4)    	 /**< 1 Core Clock Period  */
#define EPC_2_CORECLK_PERIOD 	(0x02ul <<4)     	/**< 2 Core Clock Periods */
#define EPC_3_CORECLK_PERIOD 	(0x03ul <<4)     	/**< 3 Core Clock Periods */
#define EPC_4_CORECLK_PERIOD 	(0x04ul <<4)     	/**< 4 Core Clock Periods */
#define EPC_5_CORECLK_PERIOD 	(0x05ul <<4)     	/**< 5 Core Clock Periods */
#define EPC_6_CORECLK_PERIOD 	(0x06ul <<4)     	/**< 6 Core Clock Periods */
#define EPC_7_CORECLK_PERIOD 	(0x07ul <<4)     	/**< 7 Core Clock Periods */

/*******************************************************************************
* DSR0, DSR1, DSR2, DSR3 : EPC Device Select Registers
*******************************************************************************/
#define EPC_DBW          		(0x01ul << 0)     /**< Data Bus Width          */
#define EPC_DBW_8_BIT        	(0x00ul << 0)     /**< 8 bit Data Bus Width    */
#define EPC_DBW_16_BIT       	(0x01ul << 0)     /**< 16 bit Data Bus Width   */
#define EPC_CSEN             	(0x01ul << 3)     /**< Chip Select Enable      */

#define EPC_MEMSIZE_MASK     	(0x0Ful << 8)     /**< External Memory Size    */
#define EPC_MEMSIZE(val)     	((val & 0x0Ful) << 8) /**< External Memory Size*/
#define EPC_MEMSIZE_16MB     	(0x00ul << 8)     /**< 16Mbytes External memory*/
#define EPC_MEMSIZE_8MB      	(0x01ul << 8)     /**< 8Mbytes External memory */
#define EPC_MEMSIZE_4MB      	(0x02ul << 8)     /**< 4Mbytes External memory */
#define EPC_MEMSIZE_2MB      	(0x03ul << 8)     /**< 2Mbytes External memory */
#define EPC_MEMSIZE_1MB      	(0x04ul << 8)     /**< 1Mbytes External memory */
#define EPC_MEMSIZE_512KB    	(0x05ul << 8)   /**< 512Kbytes External memory */
#define EPC_MEMSIZE_256KB    	(0x06ul << 8)   /**< 256Kbytes External memory */
#define EPC_MEMSIZE_128KB    	(0x07ul << 8)   /**< 128Kbytes External memory */
#define EPC_MEMSIZE_64KB     	(0x08ul << 8)   /**< 64Kbytes External memory  */
#define EPC_MEMSIZE_32KB     	(0x09ul << 8)     /**< 32Kbytes External memory*/
#define EPC_MEMSIZE_16KB     	(0x0Aul << 8)     /**< 16Kbytes External memory*/
#define EPC_MEMSIZE_8KB      	(0x0Bul << 8)     /**< 8Kbytes External memory */
#define EPC_MEMSIZE_4KB      	(0x0Cul << 8)     /**< 4Kbytes External memory */
#define EPC_MEMSIZE_2KB      	(0x0Dul << 8)     /**< 2Kbytes External memory */
#define EPC_MEMSIZE_1KB      	(0x0Eul << 8)     /**< 1Kbytes External memory */
#define EPC_HIGH_SPEED       	(0x01ul << 12)    /**< high speed mode         */
#define EPC_EPC_BA_MASK  		(0xFFFul << 20)   /**< Base Address mask       */
#define EPC_BA(val)     		((val & 0xFFFul) << 20)/**< Base Address       */

/* DSR0 Register Only                           	                          */
#define EPC_CS0RTSEL 			(0x01ul << 4) /* Chip Select0 Read Table Select*/

/*******************************************************************************
* WER, WDR, WSR : EPC RAM Access Registers
*******************************************************************************/
#define EPC_WRITERAM			(0x01ul << 0)  	/**< Write in RAM            */

/* WER Register Only                                                         */
#define EPC_WRITEENKEY_MASK  	(0xFFFFul << 16) /**< Write Enable Key mask   */
#define EPC_WRITEENKEY   		(0x1110ul << 16) /**< Write Enable Key        */


/*******************************************************************************
* TBL0, TBL1, TBL2, TBL3, TBL4, TBL5, TBL6, TBL7 : EPC Table Registers
*******************************************************************************/
#define EPC_CYCLECOUNTER_MASK	(0x3Ful << 0)           /**< Cycle counter    */
#define EPC_CYCLECOUNTER(val)	((val & 0x3Ful) << 0)   /**< Cycle counter    */
#define EPC_EOT               	(0x01ul << 6)           /**< End of Table     */
#define EPC_VALIDDATA        	(0x01ul << 7)           /**< Valid Data       */
#define EPC_XCS               	(0x01ul << 8)           /**< Chip Select Line */
#define EPC_CTRL0_LINE_MASK  	(0x07ul << 9)           /**< Control 0 Line   */
#define EPC_CTRL0_LINE(val)  	((val & 0x07ul) << 9)   /**< Control 0 Line   */
#define EPC_CTRL1_LINE_MASK  	(0x07ul << 12)          /**< Control 1 Line   */
#define EPC_CTRL1_LINE(val)  	((val & 0x07ul) << 12)  /**< Control 1 Line   */
#define EPC_CTRL2_LINE_MASK  	(0x07ul << 15)          /**< Control 2 Line   */
#define EPC_CTRL2_LINE(val)  	((val & 0x07ul) << 15)  /**< Control 2 Line   */
#define EPC_CTRL3_LINE_MASK  	(0x07ul << 18)          /**< Control 3 Line   */
#define EPC_CTRL3_LINE(val)   ((val & 0x07ul) << 18)  /**< Control 3 Line   */
#define EPC_CTRL4_LINE_MASK  	(0x07ul << 21)          /**< Control 4 Line   */
#define EPC_CTRL4_LINE(val)  	((val & 0x07ul) << 21)  /**< Control 4 Line   */
#define EPC_CTRL_16           	(0x4ul << 0)        /**< EPC type of transfert*/
#define EPC_CTRL_8H           	(0x2ul << 0)        /**< EPC type of transfert*/
#define EPC_CTRL_8L           	(0x1ul << 0)        /**< EPC type of transfert*/

/*******************************************************************************
*****************************  EPC REGISTER MASK  ******************************
*******************************************************************************/
#define EPC_ECR_MASK			(0xFF000002ul)  /**< ECR mask                  */
#define EPC_DCR_MASK      		(0xFF000002ul)  /**< DCR mask                  */
#define EPC_PMSR_MASK     		(0x3FFFFFF3ul)  /**< PMSR mask                 */
#define EPC_CR_MASK       		(0x00000002ul)  /**< CR mask                   */
#define EPC_CSR0_MASK     		(0xFFFFFFFFul)  /**< CSR mask                  */
#define EPC_SR0_MASK      		(0xFFFFFFFFul)  /**< SR mask                   */
#define EPC_IER0_MASK     		(0xFFFFFFFFul)  /**< IER mask                  */
#define EPC_IDR0_MASK     		(0xFFFFFFFFul)  /**< IDR mask                  */
#define EPC_IMR0_MASK     		(0xFFFFFFFFul)  /**< IMR mask                  */
#define EPC_PR_MASK       		(0x0000007Ful)  /**< PR mask                   */
#define EPC_DSRX_MASK     		(0xFFF00F19ul)  /**< DSR mask                  */
#define EPC_CSR1_MASK     		(0x0007FFFFul)  /**< CSR1 mask                 */
#define EPC_SR1_MASK      		(0x0007FFFFul)  /**< SR1 mask                  */
#define EPC_IER1_MASK     		(0x0007FFFFul)  /**< IER1 mask                 */
#define EPC_IDR1_MASK     		(0x0007FFFFul)  /**< IDR1 mask                 */
#define EPC_IMR1_MASK     		(0x0007FFFFul)  /**< IMR1 mask                 */
#define EPC_WER_MASK      		(0xFFFF0001ul)  /**< WER mask                  */
#define EPC_WDR_MASK      		(0x00000001ul)  /**< WDR mask                  */
#define EPC_WSR_MASK      		(0x00000001ul)  /**< WSR mask                  */
#define EPC_TBLX_MASK     		(0x00FFFFFFul)  /**< TBL mask                  */

/*******************************************************************************
************************   EPC REGISTERS RESET VALUE ***************************
*******************************************************************************/
#define EPC_ECR_RST    			(0x00000000ul)  /**< ECR reset value           */
#define EPC_DCR_RST       		(0x00000000ul)  /**< DCR reset value           */
#define EPC_PMSR_RST      		(IPIDCODE_EPC0)/**< PMSR reset value          */
#define EPC_CR_RST        		(0x00000000ul)  /**< CR reset value            */
#define EPC_CSR0_RST      		(0x00000000ul)  /**< CSR reset value           */
#define EPC_SR0_RST       		(0x00000000ul)  /**< SR reset value            */
#define EPC_IER0_RST      		(0x00000000ul)  /**< IER reset value           */
#define EPC_IDR0_RST      		(0x00000000ul)  /**< IDR reset value           */
#define EPC_IMR0_RST      		(0x00000000ul)  /**< IMR reset value           */
#define EPC_PR_RST        		(0x00000007ul)  /**< PR reset value            */
#define EPC_DSRX_RST      		(0x00000000ul)  /**< DSR reset value           */
#define EPC_CSR1_RST      		(0x00000000ul)  /**< CSR reset value           */
#define EPC_SR1_RST       		(0x00000000ul)  /**< SR reset value            */
#define EPC_IER1_RST      		(0x00000000ul)  /**< IER reset value           */
#define EPC_IDR1_RST      		(0x00000000ul)  /**< IDR reset value           */
#define EPC_IMR1_RST      		(0x00000000ul)  /**< IMR reset value           */
#define EPC_WER_RST       		(0x00000000ul)  /**< WER reset value           */
#define EPC_WDR_RST       		(0x00000000ul)  /**< WDR reset value           */
#define EPC_WSR_RST       		(0x00000000ul)  /**< WSR reset value           */
#define EPC_TBLX_RST      		(0x00FFFFFFul)  /**< TBL reset value           */

/*******************************************************************************
**************************  EPC MACROS DEFINITION  *****************************
*******************************************************************************/

/* ECR, DCR, PMSR : EPC Power Management registers                           */
/** Set ECR register (Enable)                                                */
#define CSP_EPC_SET_ECR(epc,val)	((epc)->ECR = (val | EPC_CLOCKENKEY ))
/** Set DCR register (Disable)                                               */
#define CSP_EPC_SET_DCR(epc,val)	((epc)->DCR = (val | EPC_CLOCKDISKEY ))
/** Set PMSR register (Status)                                               */
#define CSP_EPC_GET_PMSR(epc)    	((epc)->PMSR)

/* CR : EPC Control Register                                                 */
/** Set CR register                                                          */
#define CSP_EPC_SET_CR(epc,val)		((epc)->CR = (val))

/* CSR, SR : EPC Status Registers                                            */
/** Set CSR register (Clear)                                                 */
#define CSP_EPC_SET_CSR(epc,pioevent,val)                                  \
                  		((pioevent == 0) ? (((epc)->PIOEVENT0).CSR = (val)) :\
                       	(((epc)->PIOEVENT1).CSR = (val)))
/** Get SR register (Status)                                                 */
#define CSP_EPC_GET_SR(epc,pioevent)                                        \
                      	((pioevent == 0) ? (((epc)->PIOEVENT0).SR) :          \
                      	(((epc)->PIOEVENT1).SR))

/* IER, IDR, IMR : EPC Interrupt Registers                                   */
/** Set IER register (Enable)                                                */
#define CSP_EPC_SET_IER(epc,pioevent,val)                                  \
                       	((pioevent == 0) ? (((epc)->PIOEVENT0).IER = (val)) :\
                       	(((epc)->PIOEVENT1).IER = (val)))
/** Set IDR register (Disable)                                               */
#define CSP_EPC_SET_IDR(epc,pioevent,val)                                  \
                       	((pioevent == 0) ? (((epc)->PIOEVENT0).IDR = (val)) :\
                       	(((epc)->PIOEVENT1).IDR = (val)))
/** Get IMR register (Status)                                                */
#define CSP_EPC_GET_IMR(epc,pioevent)                                      \
                       	((pioevent == 0) ? (((epc)->PIOEVENT0).IMR) :        \
                       	(((epc)->PIOEVENT1).IMR))

/* PR : EPC Prescalar Register                                               */
/** Set PR register                                                          */
#define CSP_EPC_SET_PR(epc,val)			((epc)->PR = (val))
/** Get PR register                                                          */
#define CSP_EPC_GET_PR(epc)          	((epc)->PR)

/* DSR0, DSR1, DSR2, DSR3 : EPC Device Select Registers                      */
/** Set DSR register                                                         */
#define CSP_EPC_SET_DSR(epc,xcs,val)	((epc)->DEVICE[xcs].DSR = (val)) 
/** Get DSR register                                                         */
#define CSP_EPC_GET_DSR(epc,xcs)     	((epc)->DEVICE[xcs].DSR)

/* WER, WDR, WSR : EPC RAM Registers                                         */
/** Set WER register (Enable)                                                */
#define CSP_EPC_SET_WER(epc,val)		((epc)->WER = (val | EPC_WRITEENKEY ))
/** Set WDR register (Disable)                                               */
#define CSP_EPC_SET_WDR(epc,val)    	((epc)->WDR = (val))
/** Get WSR register (Status)                                                */
#define CSP_EPC_GET_WSR(epc)         	((epc)->WSR)

/* RAM_TBL0, RAM_TBL1, RAM_TBL2, RAM_TBL3, RAM_TBL4,                         */
/* RAM_TBL5, RAM_TBL6, RAM_TBL7 : EPC Table Registers                        */
/** Set READ RAM TABLE                                                       */ 
#define CSP_EPC_SET_RAM_TBLR(epc,table,line,val)                          \
                            	((epc)->TABLE[(table)].TBLR[line] = (val))
/** Set WRITE RAM TABLE                                                      */ 
#define CSP_EPC_SET_RAM_TBLW(epc,table,line,val)                          \
                          		((epc)->TABLE[(table)].TBLW[line] = (val))
/** Get READ RAM TABLE                                                       */ 
#define CSP_EPC_GET_RAM_TBLR(epc,table,line)                         	     \
                            	((epc)->TABLE[(table)].TBLR[line])
/** Get WRITE RAM TABLE                                                      */ 
#define CSP_EPC_GET_RAM_TBLW(epc,table,line)                               \
                            	((epc)->TABLE[(table)].TBLW[line])


/*******************************************************************************
**************************  EPC EXTERNAL FUNCTIONS   ***************************
*******************************************************************************/
extern void CSP_EPCInit(CSP_EPC_T *const epc);
extern void CSP_EPCClose(CSP_EPC_T *const epc);
extern U32_T CSP_EPCPowerManagementGetStatus(CSP_EPC_T *const epc);
extern void CSP_EPCSetPrescalar(CSP_EPC_T *const epc, U32_T prMask_u32);
extern U32_T CSP_EPCGetPrescalar(CSP_EPC_T *const epc);
extern void CSP_EPCSetDeviceSelect(CSP_EPC_T *const epc, 
                                  	  U32_T dsrMask_u32, 
                                   	  U8_T xcsMask_u8);
extern U32_T CSP_EPCGetDeviceSelect(CSP_EPC_T *const epc, U8_T xcsMask_u8);
extern void CSP_EPCWriteEnable(CSP_EPC_T *const epc);
extern void CSP_EPCWriteDisable(CSP_EPC_T *const epc);
extern U32_T CSP_EPCWriteGetStatus(CSP_EPC_T *const epc);
extern void CSP_EPCSetReadTable(CSP_EPC_T *const epc, 
                                	U32_T tableMask_u32, 
                                	U32_T lineMask_u32, 
                                	U32_T valMask_u32);
extern U32_T CSP_EPCGetReadTable(CSP_EPC_T *const epc, 
                                 	U32_T tableMask_u32, 
                                 	U32_T lineMask_u32);
extern void CSP_EPCSetWriteTable(CSP_EPC_T *const epc, 
                                 	U32_T tableMask_u32, 
                                 	U32_T lineMask_u32, 
                                 	U32_T valMask_u32);
extern U32_T CSP_EPCGetWriteTable(CSP_EPC_T *const epc, 
                                  	U32_T tableMask_u32, 
                                  	U32_T lineMask_u32);                                  
extern void CSP_EPCClearStatus(CSP_EPC_T *const epc, 
                               	  U8_T pioEvent_u8, 
                                  U32_T pioMask_u32);
extern void CSP_EPCInitReadTable(CSP_EPC_T *const epc, 
									U32_T tableMask_u32);
extern void CSP_EPCInitWriteTable(CSP_EPC_T *const epc,
									U32_T tableMask_u32);
extern void CSP_EPCClearReadTable(CSP_EPC_T *const epc,
									  U32_T tableMask_u32);
extern void CSP_EPCClearWriteTable(CSP_EPC_T *const epc,
									  U32_T tableMask_u32);
extern U32_T CSP_EPCInterruptGetStatus(CSP_EPC_T *const epc, 
										  U8_T pioEvent_u8);
extern void CSP_EPCConfigInterrupt(CSP_EPC_T *const epc, 
                                   	  U32_T intMode_u32, 
                                   	  U32_T intMask_u32, 
                                   	  U8_T pioEvent_u8, 
                                   	  U32_T callback_u32);
extern U32_T CSP_EPCInterruptMaskGetStatus(CSP_EPC_T *const epc, 
                                          	   U8_T pioEvent_u8);

#endif	/*_CSP_EPC_H */


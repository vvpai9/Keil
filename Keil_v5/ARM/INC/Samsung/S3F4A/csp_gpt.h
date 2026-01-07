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
* @file name	csp_gpt.h
* @description	Definitions, Macros and function declarations 
*            	for General Purpose Timer module
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
*		GPT/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 

#ifndef _CSP_GPT_H
#define _CSP_GPT_H

/*******************************************************************************
***********************   GPT STRUCTURE DEFINITION   ***************************
*******************************************************************************/
/* Physical Timer Definition                                                 */
/** GPT one channel                                                          */
#define GPT_ONE_CHANNEL			1u
/** GPT three channel                                                        */
#define GPT_THREE_CHANNEL  		3u


/*******************************************************************************
* GPT Channel Structure
*******************************************************************************/
typedef struct
{
	CSP_REGISTER_T	ReservedA[20];
    CSP_REGISTER_T  ECR;               /**< Enable Clock Register            */
    CSP_REGISTER_T  DCR;               /**< Disable Clock Register           */
    CSP_REGISTER_T  PMSR;              /**< Power Management Status Register */
    CSP_REGISTER_T  ReservedD;
    CSP_REGISTER_T  CR;                /**< Control Register                 */
    CSP_REGISTER_T  MR;                /**< Mode Register                    */
    CSP_REGISTER_T  ReservedE;
    CSP_REGISTER_T  CSR;               /**< Clear Status Register            */
    CSP_REGISTER_T  SR;                /**< Status Register                  */
    CSP_REGISTER_T  IER;               /**< Interrupt Enable Register        */
    CSP_REGISTER_T  IDR;               /**< Interrupt Disable Register       */
    CSP_REGISTER_T  IMR;               /**< Interrupt Mask Register          */
    CSP_REGISTER_T  CV;                /**< Counter value Register           */
    CSP_REGISTER_T  RA;                /**< Register A                       */
    CSP_REGISTER_T  RB;                /**< Register B                       */
    CSP_REGISTER_T  RC;                /**< Register C                       */
    CSP_REGISTER_T  ReservedF[28];
}CSP_GPT_T, *CSP_GPT_PTR;

/*******************************************************************************
* GPT 1 Channel Structure
*******************************************************************************/
typedef struct
{
	CSP_GPT_T		CHANNEL[GPT_ONE_CHANNEL]; 	/**< GPT Channel             */
	
}CSP_GPT1C_T, *CSP_GPT1C_PTR;

/*******************************************************************************
* GPT 3 Channel Structure
*******************************************************************************/
typedef struct
{
	CSP_GPT_T     	CHANNEL[GPT_THREE_CHANNEL];   /**< GPT Channel           */
    CSP_REGISTER_T	BCR;                          /**< Block Control Register */
    CSP_REGISTER_T	BMR;                          /**< Clock Mode Register    */
 }CSP_GPT3C_T, *CSP_GPT3C_PTR;

/*******************************************************************************
***********************   GPT REGISTERS DEFINITION   ***************************
*******************************************************************************/	

/*******************************************************************************
* ECR, DCR, PMSR : GPT Power Management Registers
*******************************************************************************/
#define GPT_GPT           	(0x01ul << 1)   		/**< GPT Clock         */
#define GPT_IPIDCODE_MASK	(0x03FFFFFul << 4)		/**< GPT IPIDCODE      */
#define GPT_DBGEN         	(0x01ul << 31)           /**< Debug Mode Enable */

/*******************************************************************************
* CR : GPT Control Register
*******************************************************************************/
#define GPT_SWRST         	(0x01ul << 0)  /**< GPT Software Reset          */
#define GPT_CLKEN         	(0x01ul << 1)  /**< Counter Clock Enable        */
#define GPT_CLKDIS        	(0x01ul << 2)  /**< Counter Clock Disable       */
#define GPT_SWTRG        	(0x01ul << 3)  /**< Software Trigger            */

/*******************************************************************************
* MR : GPT Mode Register (Capture mode)
*******************************************************************************/
/* WAVE = CAPT_ENA : Capture Mode is enabled                                 */
#define GPT_WAVE 			(0x01ul << 15)	/**< WAVE Mask                   */
#define GPT_CAPT_ENA      	(0x00ul << 15) 	/**< Capture Mode                */
#define GPT_WAVE_ENA      	(0x01ul << 15) 	/**< Waveform Mode               */

/* CLKS : Clock Source                                                       */
#define GPT_CLKS_MASK		(0x07ul << 0)  			/**< CLKS Mask           */
#define GPT_CLKS(val)     	(((val) & 0x07ul) << 0)	/**< Writing Macro 		 */
#define GPT_CLKS_MCK2     	(0x00ul)       			/**< MCK/2               */
#define GPT_CLKS_MCK8    	(0x01ul)      			/**< MCK/8               */
#define GPT_CLKS_MCK32   	(0x02ul)       			/**< MCK/32              */
#define GPT_CLKS_MCK128  	(0x03ul)       			/**< MCK/128             */
#define GPT_CLKS_MCK1024 	(0x04ul)       			/**< MCK/1024            */
#define GPT_CLKS_XC0      	(0x05ul)         		/**< XC0                 */
#define GPT_CLKS_XC1      	(0x06ul)         		/**< XC1                 */
#define GPT_CLKS_XC2      	(0x07ul)         		/**< XC2                 */

/* CLKI : Clock Inverter                                                    */
#define GPT_CLKI			(0x01ul << 3)

/* BURST : Burst Signal                                                      */
#define GPT_BURST_MASK		(0x03ul << 4)  			 /**< BURST Mask         */
#define GPT_BURST(val)    	(((val) & 0x03ul) << 4)	 /**< Writing Macro      */
#define GPT_BURST_NONE   	((0x00ul) << 4)	/**< No signal selected for burst*/
#define GPT_BURST_XC0     	((0x01ul) << 4)           /**< XC0                */
#define GPT_BURST_XC1    	((0x02ul) << 4)           /**< XC1                */
#define GPT_BURST_XC2     	((0x03ul) << 4)           /**< XC2                */

/* LDBSTOP : Counter clock stopped with RB Loading                            */
#define GPT_LDBSTOP			(0x01ul << 6)

/* LDBDIS : Counter clock disable with RB Loading                             */
#define GPT_LDBDIS         (0x01ul << 7)

/* ETRGEDG : External Trigger Edge                                            */
#define GPT_ETRGEDG_MASK  		(0x03ul << 8)  		/**< ETRGEDG Mask         */
#define GPT_ETRGEDG(val)  		((val & 0x03ul) << 8)/**< Writing macro  	  */
#define GPT_ETRGEDG_NONE  		((0x00ul) << 8)		/**< No external trigger  */
#define GPT_ETRGEDG_RISING  	((0x01ul) << 8)  	/**< Rising edge trigger  */
#define GPT_ETRGEDG_FALLING 	((0x02ul) << 8)  	/**< Falling edge trigger */
#define GPT_ETRGEDG_EACH    	((0x03ul) << 8)  	/**< Each edge trigger    */

/* ABETRG : TIOA or TIOB External Trigger                                      */
#define GPT_ABETRG       	(0x01ul << 10)/*< ABETRG Mask                	   */
#define GPT_ABETRG_TIOA   	(0x01ul << 10)/*< TIOA selected for external trigger*/
#define GPT_ABETRG_TIOB   	(0x00ul << 10)/*< TIOB selected for external trigger*/ 
                              
/* CPCTRG : RC Compare Trigger Enable                                          */
#define GPT_CPCTRG			(0x01ul << 14)/*< Equal condition on RC causes trigger */                                         

/* LDRA : Load RA                                                             */
#define GPT_LDRA_MASK		(0x03ul << 16) 			/**< LDRA Mask            */
#define GPT_LDRA(val) 		((val & 0x03ul) << 16)	/**< Writing macro        */
#define GPT_LDRA_NONE 		((0x00ul) << 16)/**< No external trigger selected  */
                                            
#define GPT_LDRA_RISING   ((0x01ul) << 16)  	/**< Rising edge on TIOA      */
#define GPT_LDRA_FALLING  	((0x02ul) << 16)  	/**< Falling edge on TIOA     */
#define GPT_LDRA_EACH    	((0x03ul) << 16)  	/**< Each edge on TIOA        */

/* LDRB : Load RB                                                             */
#define GPT_LDRB_MASK     	(0x03ul << 18) 			/**< LRRB Mask            */
#define GPT_LDRB(val) 		((val & 0x03) << 18) 	/**< Writing Macro        */
#define GPT_LDRB_NONE     	((0x00ul) << 18) /**< No external trigger selected */                                                       
#define GPT_LDRB_RISING   ((0x01ul) << 18)  		/**< Rising edge on TIOB  */
#define GPT_LDRB_FALLING  ((0x02ul) << 18)  		/**< Falling edge on TIOB */
#define GPT_LDRB_EACH    	((0x03ul) << 18)  		/**< Each edge on TIOB    */

/*******************************************************************************
* MR : Mode Register (Waveform mode)
*******************************************************************************/
/* CLKS  : Clock source   - Same as Capture Mode                             */
/* CLKI  : Clock inverter - Same as Capture Mode                             */
/* BURST : Burst signal   - Same as Capture Mode                             */

/* CPCSTOP : Compare RC Stops the counter                                    */
#define GPT_CPCSTOP			(0x01ul << 6)	/*< CPCSTOP Mask                  */
#define GPT_CPCSTOP_DIS  	(0x00ul << 6)  	/*< Counter is not stopped 		  */
										  	/*  when equal condition on RC     */	   
#define GPT_CPCSTOP_ENA  	(0x01ul << 6)  /**< Counter is stopped when equal*/
                                          /**  condition on RC   	         */

/* CPCDIS : Compare RC Disables Clock                                        */
#define GPT_CPCDIS     		(0x01ul << 7)  	/**< CPCSDIS Mask                */
#define GPT_CPCDIS_DIS    	(0x00ul << 7)  	/**< Counter clock is disables 	 */
                                            /**  when equal condition on RC   */
#define GPT_CPCDIS_ENA    	(0x01ul << 7)  /**< Counter clock disables when    */
                                              /**  equal condition on RC      */

/* EEVTEDG : External Event Edge                                              */
#define GPT_EEVTEDG_MASK 		(0x03ul << 8)  /**< EEVTEDG Mask               */
#define GPT_EEVTEDG(val)    	((val & 0x03) << 8) /**< Writing macro        */
#define GPT_EEVTEDG_NONE    	((0x00ul) << 8)  /**< No external event edge   */
#define GPT_EEVTEDG_RISING  	((0x01ul) << 8)  /**< Rising event edge        */
#define GPT_EEVTEDG_FALLING 	((0x02ul) << 8)  /**< Falling event edge       */ 
#define GPT_EEVTEDG_EACH    	((0x03ul) << 8)  /**< Each event edge          */

/* EEVT : External Event                                                      */
#define GPT_EEVT_MASK  		(0x03ul << 10) 		 /**< EEVT Mask               */
#define GPT_EEVT(val)     	((val & 0x03) << 10) /**< Writing macro 		  */
#define GPT_EEVT_TIOB    	((0x00ul) << 10)  	/**< TIOB External Trigger    */
#define GPT_EEVT_XC0      	((0x01ul) << 10)  	/**< XC0 External Trigger     */   
#define GPT_EEVT_XC1      	((0x02ul) << 10)  	/**< XC1 External Trigger     */
#define GPT_EEVT_XC2      	((0x03ul) << 10)  	/**< XC2 External Trigger     */

/* ENETRG : Enable External Trigger                                          */
#define GPT_ENETRG			(0x01ul << 12)	/**< Enable External trigger     */

/* CPCTRG : RC compare trigger enable - Same as Capture Mode                 */
/* WAVE = WAVE_ENA : Waveform mode is enable                                 */

/* ACPA : RA Compare Effect on TIOA                                           */
#define GPT_ACPA_MASK		(0x03ul << 16) 		  /**< ACPA Mask              */
#define GPT_ACPA(val)     	((val & 0x03ul) << 16) /**< Writing macro          */ 
#define GPT_ACPA_NONE    	((0x00ul) << 16) 	  /**< Noeffect on TIOA output*/
#define GPT_ACPA_SET      	((0x01ul) << 16) 	  /**< SET TIOA output        */
#define GPT_ACPA_CLEAR   	((0x02ul) << 16) 	  /**< Clear TIOA output      */
#define GPT_ACPA_TOGGLE  	((0x03ul) << 16)	  /**< Toggle TIOA output     */

/* ACPC : RC Compare Effect on TIOA                                          */
#define GPT_ACPC_MASK 		(0x03ul << 18) /**< ACPC Mask                   */
#define GPT_ACPC(val)     	((val & 0x03ul) << 18) /**< Writing macro       */ 
#define GPT_ACPC_NONE    	((0x00ul) << 18)  /**< No effect on TIOA output */
#define GPT_ACPC_SET      	((0x01ul) << 18)  /**< SET TIOA output          */
#define GPT_ACPC_CLEAR   	((0x02ul) << 18)  /**< Clear TIOA output        */
#define GPT_ACPC_TOGGLE  	((0x03ul) << 18)  /**< Toggle TIOA output       */
/* AEEVT : External Event Effect on TIOA                                     */
#define GPT_AEEVT_MASK    	(0x03ul << 20) /**< AEEVT Mask                  */
#define GPT_AEEVT(val)    	((0x03ul & val) << 20) /**< Writing macro       */
#define GPT_AEEVT_NONE   	((0x00ul) << 20) /**< No effect on TIOA output  */
#define GPT_AEEVT_SET    	((0x01ul) << 20) /**< SET TIOA output           */
#define GPT_AEEVT_CLEAR  	((0x02ul) << 20) /**< Clear TIOA output         */
#define GPT_AEEVT_TOGGLE  ((0x03ul) << 20) /**< Toggle TIOA output        */

/* ASWTRG : Software Trigger Effect on TIOA                                  */
#define GPT_ASWTRG_MASK   	(0x03ul << 22) /**< ASWTRG Mask                 */
#define GPT_ASWTRG(val)   	((0x03ul & val) << 22) /**< ASWTRG Mask         */
#define GPT_ASWTRG_NONE   	((0x00ul) << 22)  /**< No effect on TIOA output */
#define GPT_ASWTRG_SET   	((0x01ul) << 22)  /**< SET TIOA output          */
#define GPT_ASWTRG_CLEAR 	((0x02ul) << 22)  /**< Clear TIOA output        */
#define GPT_ASWTRG_TOGGLE ((0x03ul) << 22)  /**< Toggle TIOA output       */

/* BCPB : RB Compare Effect on TIOB                                          */
#define GPT_BCPB_MASK		(0x03ul << 24) /**< BCPB Mask                   */
#define GPT_BCPB(val)     	((0x03ul & val) << 24) /**< Writing macro       */
#define GPT_BCPB_NONE     	(0x00ul << 24)   /**< No effect on TIOB output  */ 
#define GPT_BCPB_SET      	(0x01ul << 24)   /**< SET TIOB output           */
#define GPT_BCPB_CLEAR   	(0x02ul << 24)   /**< Clear TIOB output         */
#define GPT_BCPB_TOGGLE  	(0x03ul << 24)   /**< Toggle TIOB output        */

/* BCPC : RC Compare Effect on TIOB                                          */
#define GPT_BCPC_MASK   	(0x03ul << 26) /**< BCPC Mask                   */
#define GPT_BCPC(val)     	((0x03ul & val) << 26) /**< Writing macro       */ 
#define GPT_BCPC_NONE    	(0x00ul << 26)   /**< No effect on TIOB output  */
#define GPT_BCPC_SET      	(0x01ul << 26)   /**< SET TIOB output           */
#define GPT_BCPC_CLEAR   	(0x02ul << 26)   /**< Clear TIOB output         */
#define GPT_BCPC_TOGGLE  	(0x03ul << 26)   /**< Toggle TIOB output        */

/* BEEVT : External Event Effect on TIOB                                     */
#define GPT_BEEVT_MASK		(0x03ul << 28) /**< BEEVT Mask                  */
#define GPT_BEEVT(val)    	((0x03ul & val) << 28) /**< Writing macro       */
#define GPT_BEEVT_NONE   	(0x00ul << 28)  /**< No effect on TIOB output   */
#define GPT_BEEVT_SET    	(0x01ul << 28)  /**< SET TIOB output            */
#define GPT_BEEVT_CLEAR  	(0x02ul << 28)  /**< Clear TIOB output          */
#define GPT_BEEVT_TOGGLE 	(0x03ul << 28)  /**< Toggle TIOB output         */

/* BSWTRG : Software Trigger Effect on TIOB                                  */
#define GPT_BSWTRG_MASK		(0x03ul << 30) /**< BSWTRG Mask                 */
#define GPT_BSWTRG(val)  	((0x03ul & val) << 30) /**< BSWTRG Mask         */
#define GPT_BSWTRG_NONE   (0x00ul << 30) /**< No effect on TIOB output    */
#define GPT_BSWTRG_SET   	(0x01ul << 30) /**< SET TIOB output             */
#define GPT_BSWTRG_CLEAR  (0x02ul << 30) /**< Clear TIOB output           */
#define GPT_BSWTRG_TOGGLE	(0x03ul << 30) /**< Toggle TIOB output          */

/*******************************************************************************
* CSR, SR, IER, IDR, IMR : GPT Status and Interrupt Registers                        
*                           (capture & Waveform mode)                                
*******************************************************************************/
#define GPT_COVFS			(0x01ul << 0)  /**< Counter overflow            */
#define GPT_LOVRS         	(0x01ul << 1)  /**< Load overrun                */
#define GPT_CPAS           	(0x01ul << 2)  /**< Compare Register A          */
#define GPT_CPBS           (0x01ul << 3)  /**< Compare Register B          */
#define GPT_CPCS           	(0x01ul << 4)  /**< Compare Register C          */
#define GPT_LDRAS         	(0x01ul << 5)  /**< Load Register A             */
#define GPT_LDRBS         	(0x01ul << 6)  /**< Load Register B             */
#define GPT_ETRGS         	(0x01ul << 7)  /**< External Trigger            */

/* SR register Only                                                          */
#define GPT_CLKSTA        	(0x01ul << 8)  /**< Clock Status                */
#define GPT_MTIOA         	(0x01ul << 9)  /**< TIOA Mirror                 */
#define GPT_MTIOB         	(0x01ul << 10) /**< TIOB Mirror                 */
#define GPT_TIOBS         	(0x01ul << 16) /**< TIOB                        */
#define GPT_TIOAS         	(0x01ul << 17) /**< TIOA                        */
#define GPT_TCLKS         	(0x01ul << 18) /**< TCLK                        */	

/*******************************************************************************
* CV : GPT Counter Value Register
*******************************************************************************/
#define GPT_CV_MASK			(0xFFFFul << 0)   /**< Counter Value Mask       */
      
/*******************************************************************************
* RA : GPT Register A Value
*******************************************************************************/
#define GPT_RA_MASK     	(0xFFFFul << 0)   /**< RA Mask                  */

/*******************************************************************************
* RB : GPT Register B Value
*******************************************************************************/
#define GPT_RB_MASK       	(0xFFFFul << 0)   /**< RB Mask                  */

/*******************************************************************************
* RC : GPT Register C Value
*******************************************************************************/
#define GPT_RC_MASK      	(0xFFFFul << 0)   /**< RC Mask                  */

/*******************************************************************************
* BCR : GPT Block Control Register - 3 Channels Only
*******************************************************************************/
/* SWRST : GPT Software Block Reset - Same as CR                             */
#define GPT_TCSYNC       	(0x01ul << 1)     /**< Synchronization Bit      */

/*******************************************************************************
* BMR : GPT Block Mode Register - 3 Channels Only
*******************************************************************************/
/* TC0XC0S : External Clock XC0 Selection                                    */
#define GPT_TC0XC0S_MASK	(0x03ul << 0)  /**< TC0XC0S Mask                */
#define GPT_TC0XC0S(val) 	((0x03ul & val) << 0)  /**< Writing macro       */
#define GPT_TCLK0_XC0     	(0x00ul)       /**< XC0 signal select           */
#define GPT_NONE_XC0      	(0x01ul)       /**< None signal select          */
#define GPT_TIOA1_XC0     	(0x02ul)       /**< TIOA1 signal select         */
#define GPT_TIOA2_XC0    	(0x03ul)       /**< TIOA2 signal select         */
/* TC1XC1S : External Clock XC1 Selection                                    */
#define GPT_TC1XC1S_MASK	(0x03ul << 2)  /**< TC1XC1S Mask                */
#define GPT_TC1XC1S(val) 	((0x03ul & val) << 2)  /**< Writing macro       */
#define GPT_TCLK1_XC1    	(0x00ul << 2)  /**< XC1 signal select           */
#define GPT_NONE_XC1      	(0x01ul << 2)  /**< None signal select          */
#define GPT_TIOA0_XC1    	(0x02ul << 2)  /**< TIOA0 signal select         */
#define GPT_TIOA2_XC1     	(0x03ul << 2)  /**< TIOA2 signal select         */

/* TC2XC2S : External Clock XC2 Selection                                    */
#define GPT_TC2XC2S_MASK	(0x03ul << 4)  /**< TC2XC2S Mask                */
#define GPT_TC2XC2S(val) 	((0x03ul & val) << 4)  /**< TC2XC2S Mask        */
#define GPT_TCLK2_XC2    	(0x00ul << 4)   /**< XC2 signal select          */
#define GPT_NONE_XC2      	(0x01ul << 4)   /**< None signal select         */
#define GPT_TIOA0_XC2    	(0x02ul << 4)   /**< TIOA0 signal select        */
#define GPT_TIOA1_XC2    	(0x03ul << 4)   /**< TIOA1 signal select        */

/*******************************************************************************
***************************** GPT REGISTER MASK  *******************************
*******************************************************************************/
#define GPT_ECR_MASK		(0x80000002ul)    /**< ECR mask                    */
#define GPT_DCR_MASK     	(0x80000002ul)    /**< DCR mask                    */
#define GPT_PMSR_MASK   	(0xBFFFFFF2ul)    /**< PMSR mask                   */
#define GPT_CR_MASK      	(0x0000000Ful)    /**< CR mask                     */
#define GPT_MR_MASK      	(0xFFFFDFFFul)    /**< MR mask                     */
#define GPT_CSR_MASK     	(0x000000FFul)    /**< CSR mask                    */
#define GPT_SR_MASK      	(0x000707FFul)    /**< SR mask                     */
#define GPT_IER_MASK     	(0x000700FFul)    /**< IER mask                    */
#define GPT_IDR_MASK     	(0x000700FFul)    /**< IDR mask                    */
#define GPT_IMR_MASK     	(0x000700FFul)    /**< IMR mask                    */
#define GPT_BCR_MASK 		(0x00000001ul)    /**< BCR mask                    */
#define GPT_BMR_MASK     	(0x0000003Ful)    /**< BMR mask                    */

/*******************************************************************************
************************   GPT REGISTERS RESET VALUE  **************************
*******************************************************************************/
#define GPT_ECR_RST			(0x00000000ul)     /**< ECR reset value             */
#define GPT_DCR_RST     	(0x00000000ul)     /**< DCR reset value             */
#define GPT_PMSR_RST    	(IPIDCODE_GPT0)   /**< PMSR reset value            */
#define GPT_CR_RST      	(0x00000000ul)     /**< CR reset value              */
#define GPT_MR_RST      	(0x00000000ul)     /**< MR reset value              */
#define GPT_CSR_RST     	(0x00000000ul)     /**< CSR reset value             */
#define GPT_SR_RST      	(0x00000700ul)     /**< SR reset value              */
#define GPT_IER_RST     	(0x00000000ul)     /**< IER reset value             */
#define GPT_IDR_RST     	(0x00000000ul)     /**< IDR reset value             */
#define GPT_IMR_RST     	(0x00000000ul)     /**< IMR reset value             */
#define GPT_CV_RST      	(0x00000000ul)     /**< CV reset value              */
#define GPT_RA_RST      	(0x00000000ul)     /**< RA reset value              */
#define GPT_RB_RST      	(0x00000000ul)     /**< RB reset value              */
#define GPT_RC_RST      	(0x00000000ul)     /**< RC reset value              */
#define GPT_BCR_RST     	(0x00000000ul)     /**< BCR reset value             */
#define GPT_BMR_RST     	(0x00000000ul)     /**< BMR reset value             */

/*******************************************************************************
**************************  GPT MACROS DEFINITION  *****************************
*******************************************************************************/
/* ECR, DCR, PMSR : GPT Power Management Registers                           */
/** Set ECR register (Enable)                                                */
#define CSP_GPT_SET_ECR(gpt, val)		((gpt)->ECR = (val))
/** Set DCR register (Disable)                                               */
#define CSP_GPT_SET_DCR(gpt, val)   	((gpt)->DCR = (val))
/** Get PMSR register (Status)                                               */
#define CSP_GPT_GET_PMSR(gpt)        	((gpt)->PMSR)

/* CR : GPT Control Register                                                 */
/** Set CR register                                                          */
#define CSP_GPT_SET_CR(gpt, val)     	((gpt)->CR = (val))

/* MR : GPT Mode Register                                                    */
/** Get MR register                                                          */
#define CSP_GPT_GET_MR(gpt)          	((gpt)->MR)
/** Set MR register                                                          */
#define CSP_GPT_SET_MR(gpt, mode)    	((gpt)->MR = (mode))

/* CSR, SR : GPT Status Registers                                            */
/** Set CSR register (Clear)                                                 */
#define CSP_GPT_SET_CSR(gpt, val)  		((gpt)->CSR = (val))
/** Get SR register (Status)                                                 */
#define CSP_GPT_GET_SR(gpt)           ((gpt)->SR)

/* IER, IDR, IMR : GPT Interrupt Registers                                   */
/** Set IER register (Enable)                                                */
#define CSP_GPT_SET_IER(gpt, val)    	((gpt)->IER = (val))
/** Set IDR register (Disable)                                               */
#define CSP_GPT_SET_IDR(gpt, val)    	((gpt)->IDR = (val))
/** Get IMR register (Mask)                                                  */
#define CSP_GPT_GET_IMR(gpt)          ((gpt)->IMR)

/* CV : GPT Counter Value Register                                           */
/** Get CV register                                                          */
#define CSP_GPT_GET_CV(gpt)           ((gpt)->CV)

/* RA : GPT Capture - Compare Register A                                     */
/** Get RA register                                                          */
#define CSP_GPT_GET_RA(gpt)          	((gpt)->RA)
/** Set RA register                                                          */
#define CSP_GPT_SET_RA(gpt, val)     	((gpt)->RA = (val))

/* RB : GPT Capture - Compare Register B                                     */
/** Get RB register                                                          */
#define CSP_GPT_GET_RB(gpt)           ((gpt)->RB)
/** Set RB register                                                          */
#define CSP_GPT_SET_RB(gpt, val)     	((gpt)->RB = (val))

/* RC : GPT Compare Register C                                               */
/** Get RC register                                                          */
#define CSP_GPT_GET_RC(gpt)          	((gpt)->RC)
/** Set RC register                                                          */
#define CSP_GPT_SET_RC(gpt, val)     	((gpt)->RC = (val))

/* BCR : GPT Block Control Register - 3 Channels Only                        */
/** Set BCR register                                                         */
#define CSP_GPT_SET_BCR(gpt, val)    ((gpt)->BCR = (val))

/* BMR : GPT Block Mode Register - 3 Channels Only                           */
/** Get BMR register                                                         */
#define CSP_GPT_GET_BMR(gpt)          ((gpt)->BMR)
/** Set BCR register                                                         */
#define CSP_GPT_SET_BMR(gpt, val)    	((gpt)->BMR = (val))

/*******************************************************************************
*************************   GPT EXTERNAL FUNCTIONS   ***************************
*******************************************************************************/
extern void CSP_GPTInit(CSP_GPT_T *const gpt, 
                       	  U32_T mode_u32, 
                          U16_T *regValue_p_u16);
extern void CSP_GPTClose(CSP_GPT_T *const gpt);
extern void CSP_GPTConfigInterrupt(CSP_GPT_T *const gpt, 
                            	      U32_T intMode_u32, 
                                	  U32_T intMask_u32, 
                                  	  U32_T callback_u32);
extern void CSP_GPTEnable(CSP_GPT_T *const gpt);
extern void CSP_GPTDisable(CSP_GPT_T *const gpt);

#endif   /* _CSP_GPT_H */

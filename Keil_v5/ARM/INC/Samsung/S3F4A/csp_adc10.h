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
* @file name	csp_adc10.h
* @description	Definitions, Macros and function declarations 
*            	for ADC10 module
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
*		ADC10/ /S3F4A0K/AGP1 EVB Rev1.0
*/

#ifndef _CSP_ADC10_H
#define _CSP_ADC10_H

/*******************************************************************************
***********************   ADC10 STRUCTURE DEFINITION   *************************
*******************************************************************************/

/*CSP_ADC10_T and CSP_ADC10_PTR												   */
typedef struct
{
	CSP_REGISTER_T	ReservedA[20];
    CSP_REGISTER_T  ECR; 				/**< Clock Enable Register            */
    CSP_REGISTER_T  DCR;              	/**< Clock Disable Register           */
    CSP_REGISTER_T  PMSR;             	/**< Power Management Status Register */
    CSP_REGISTER_T  ReservedB;
    CSP_REGISTER_T  CR;               	/**< Control Register                 */
    CSP_REGISTER_T  MR;               	/**< Mode Register                    */
    CSP_REGISTER_T  ReservedC;   
    CSP_REGISTER_T  CSR;              	/**< Clear Status Register            */  
    CSP_REGISTER_T  SR;               	/**< Status Register                  */  
    CSP_REGISTER_T  IER;              	/**< Interrupt Enable Register        */
    CSP_REGISTER_T  IDR;              	/**< Interrupt Disable Register       */ 
    CSP_REGISTER_T  IMR;              	/**< Interrupt Mask Register          */
    CSP_REGISTER_T  CMR0;             	/**< Conversion Mode Register 0       */ 
    CSP_REGISTER_T  CMR1;             	/**< Conversion Mode Register 1       */ 
    CSP_REGISTER_T  DR;               	/**< Convert Data Register            */ 
 }CSP_ADC10_T, *CSP_ADC10_PTR;

/*******************************************************************************
**********************   ADC10 REGISTERS DEFINITION   **************************
*******************************************************************************/	

/*******************************************************************************
* ECR, DCR, PMSR : ADC10 Power Management Registers
*******************************************************************************/
#define	ADC10_ADC				(0x01ul 	<< 1)  	/**< ADC Clock            */
#define ADC10_IPIDCODE_MASK  	(0x3FFFFFFul << 4)	/**< ADC IPIDCODE mask    */
#define ADC10_DBGEN          	(0x01ul 	<<31)  	/**< Debug Mode Enable    */

/*******************************************************************************
* CR : ADC10 Control Register
*******************************************************************************/
#define	ADC10_SWRST			(0x01ul << 0) 			/**< Software Reset       */
#define	ADC10_ADCEN			(0x01ul << 1)      		/**< ADC Enable           */
#define ADC10_ADCDIS		(0x01ul << 2)      	   	/**< ADC Disable          */
#define ADC10_START			(0x01ul << 3)      	   	/**< Start Conversion     */
#define ADC10_STOP			(0x01ul << 4)      	   	/**< Stop Conversion      */

/*******************************************************************************
* MR : ADC10 Mode Register
*******************************************************************************/

/* PRVAL : Preload Value                                					 */
#define ADC10_PRLVAL_MASK (0x1Ful << 0)				/**< Mask 				 */
#define ADC10_PRLVAL(val)	(((val) & 0x1Ful) << 0)	/**< Writing Macro		 */ 
#define ADC10_IES      	   (0x01ul << 5)     		/**<Int or External Start*/

/* NBRCH : Number of conversions                       	                	 */
#define ADC10_NBRCH_MASK	(0x0Ful << 16)           /**< Mask                */
#define ADC10_NBRCH(val) 	(((val) & 0xFul) << 16) /**< Writing Macro		 */ 
#define ADC10_NBRCH1      	(0x00ul << 16)          /**< 1 conversion         */
#define ADC10_NBRCH2      	(0x01ul << 16)          /**< 2 conversions        */
#define ADC10_NBRCH3      	(0x02ul << 16)          /**< 3 conversions        */
#define ADC10_NBRCH4      	(0x03ul << 16)          /**< 4 conversions        */
#define ADC10_NBRCH5      	(0x04ul << 16)          /**< 5 conversions        */
#define ADC10_NBRCH6      	(0x05ul << 16)          /**< 6 conversions        */
#define ADC10_NBRCH7      	(0x06ul << 16)          /**< 7 conversions        */
#define ADC10_NBRCH8      	(0x07ul << 16)          /**< 8 conversions        */
#define ADC10_NBRCH9      	(0x08ul << 16)          /**< 9 conversions        */
#define ADC10_NBRCH10    	(0x09ul << 16)          /**< 10 conversions       */
#define ADC10_NBRCH11    	(0x0Aul << 16)          /**< 11 conversions       */
#define ADC10_NBRCH12    	(0x0Bul << 16)          /**< 12 conversions       */
#define ADC10_NBRCH13    	(0x0Cul << 16)          /**< 13 conversions       */
#define ADC10_NBRCH14     	(0x0Dul << 16)          /**< 14 conversions       */
#define ADC10_NBRCH15    	(0x0Eul << 16)          /**< 15 conversions       */
#define ADC10_NBRCH16     	(0x0Ful << 16)          /**< 16 conversions       */
#define ADC10_CONTCV      	(0x01ul << 20)          /**< Continuous Conversion*/

/*******************************************************************************
* CSR, SR, IER, IDR, IMR : ADC10 Status Registers and Interrupt Registers
*******************************************************************************/
#define	ADC10_OVR			(0x01ul << 2)	/**< Over Run 		 			  */

/* SR, IER, IDR, IMR Registers only 										  */
#define ADC10_EOC			(0x01ul << 0)	/**< End Of Conversion		 	  */
#define ADC10_READY      	(0x01ul << 1)	/**< Ready to Start       		  */
 
/* SR Register Only                                                           */
#define ADC10_ADCENS		(0x01ul << 8)	/**< ADC Enable Status            */
#define ADC10_CTCVS      	(0x01ul << 9)	/**< Continuous Conversion Status */

/*******************************************************************************
* CMR0, CMR1  : ADC10 Conversion Mode Register
*******************************************************************************/

/* CV : Input Selection                                                       */
#define	ADC10_CV1_MASK		(0x0Ful << 0)          	/**< CV1 Mask            */
#define ADC10_CV1(val)    	(((val) & 0x0Ful) << 0)	/**< CV1 Writing Macro   */
#define ADC10_CV2_MASK   	(0x0Ful << 4)            /**< CV2 Mask            */
#define ADC10_CV2(val)    	(((val) & 0x0Ful) << 4)	/**< CV2 Writing Macro   */
#define ADC10_CV3_MASK    	(0x0Ful << 8)         	/**< CV3 Mask            */
#define ADC10_CV3(val)    	(((val) & 0x0Ful) << 8)	/**< CV3 Writing Macro   */
#define ADC10_CV4_MASK    	(0x0Ful << 12)         	/**< CV4 Mask            */
#define ADC10_CV4(val)    	(((val) & 0x0Ful) << 12) /**< CV4 Writing Macro   */
#define ADC10_CV5_MASK    	(0x0Ful << 16)       	/**< CV5 Mask            */
#define ADC10_CV5(val)    	(((val) & 0x0Ful) << 16) /**< CV5 Writing Macro   */
#define ADC10_CV6_MASK    	(0x0Ful << 20)         	/**< CV6 Mask            */
#define ADC10_CV6(val) 		(((val) & 0x0Ful) << 20) /**< CV6 Writing Macro   */
#define ADC10_CV7_MASK    	(0x0Ful << 24)           /**< CV7 Mask            */
#define ADC10_CV7(val) 		(((val) & 0x0Ful) << 24) /**< CV7 Writing Macro   */
#define ADC10_CV8_MASK    	(0x0Ful << 28)           /**< CV8 Mask            */
#define ADC10_CV8(val)    	(((val) & 0x0Ful) << 28) /**< CV8 Writing Macro   */
#define ADC10_CV9_MASK    	(0x0Ful << 0)            /**< CV9 Mask            */
#define ADC10_CV9(val)    	(((val) & 0x0Ful) << 0)	/**< CV9 Writing Macro   */
#define ADC10_CV10_MASK		(0x0Ful << 4)         	/**< CV10 Mask           */
#define ADC10_CV10(val)		(((val) & 0x0Ful) << 4)	/**< CV10 Writing Macro  */
#define ADC10_CV11_MASK		(0x0Ful << 8)   		/**< CV11 Mask           */
#define ADC10_CV11(val)  	(((val) & 0x0Ful) << 8)	/**< CV11 Writing Macro  */
#define ADC10_CV12_MASK   (0x0Ful << 12)          	/**< CV12 Mask           */
#define ADC10_CV12(val)		(((val) & 0x0Ful) << 12) /**< CV12 Writing Macro  */
#define ADC10_CV13_MASK		(0x0Ful << 16)       	/**< CV13 Mask           */
#define ADC10_CV13(val)		(((val) & 0x0Ful) << 16) /**< CV13 Writing Macro  */
#define ADC10_CV14_MASK   (0x0Ful << 20)           /**< CV14 Mask           */
#define ADC10_CV14(val)   (((val) & 0x0Ful) << 20)	/**< CV14 Writing Macro  */
#define ADC10_CV15_MASK		(0x0Ful << 24)       	/**< CV15 Mask           */
#define ADC10_CV15(val)		(((val) & 0x0Ful) << 24) /**< CV15 Writing Macro  */
#define ADC10_CV16_MASK		(0x0Ful << 28)        	/**< CV16 Mask           */
#define ADC10_CV16(val)		(((val) & 0x0Ful) << 28) /**< CV16 Writing Macro  */

/* CV1 Input Selection                                                        */
#define ADC10_CV1IN0		(0x00ul << 0)            /**< Input 0             */
#define ADC10_CV1IN1      	(0x01ul << 0)            /**< Input 1             */
#define ADC10_CV1IN2      	(0x02ul << 0)            /**< Input 2             */
#define ADC10_CV1IN3      	(0x03ul << 0)            /**< Input 3             */
#define ADC10_CV1IN4      	(0x04ul << 0)            /**< Input 4             */
#define ADC10_CV1IN5      	(0x05ul << 0)            /**< Input 5             */
#define ADC10_CV1IN6      	(0x06ul << 0)            /**< Input 6             */
#define ADC10_CV1IN7      	(0x07ul << 0)            /**< Input 7             */
#define ADC10_CV1IN8      	(0x08ul << 0)            /**< Input 8             */
#define ADC10_CV1IN9      	(0x09ul << 0)            /**< Input 9             */
#define ADC10_CV1IN10    	(0x0Aul << 0)            /**< Input 10            */
#define ADC10_CV1IN11    	(0x0Bul << 0)            /**< Input 11            */
#define ADC10_CV1IN12     	(0x0Cul << 0)            /**< Input 12            */
#define ADC10_CV1IN13     	(0x0Dul << 0)            /**< Input 13            */
#define ADC10_CV1IN14     	(0x0Eul << 0)            /**< Input 14            */
#define ADC10_CV1IN15     	(0x0Ful << 0)            /**< Input 15            */

/*  CV2 Input Selection                                                       */
#define ADC10_CV2IN0		(0x00ul << 4)            /**< Input 0             */
#define ADC10_CV2IN1      	(0x01ul << 4)            /**< Input 1             */
#define ADC10_CV2IN2      	(0x02ul << 4)            /**< Input 2             */
#define ADC10_CV2IN3      	(0x03ul << 4)            /**< Input 3             */
#define ADC10_CV2IN4      	(0x04ul << 4)            /**< Input 4             */
#define ADC10_CV2IN5      	(0x05ul << 4)            /**< Input 5             */
#define ADC10_CV2IN6      	(0x06ul << 4)            /**< Input 6             */
#define ADC10_CV2IN7      	(0x07ul << 4)            /**< Input 7             */
#define ADC10_CV2IN8      	(0x08ul << 4)            /**< Input 8             */
#define ADC10_CV2IN9      	(0x09ul << 4)            /**< Input 9             */
#define ADC10_CV2IN10    	(0x0Aul << 4)            /**< Input 10            */
#define ADC10_CV2IN11     	(0x0Bul << 4)            /**< Input 11            */
#define ADC10_CV2IN12     	(0x0Cul << 4)            /**< Input 12            */
#define ADC10_CV2IN13     	(0x0Dul << 4)            /**< Input 13            */
#define ADC10_CV2IN14     	(0x0Eul << 4)            /**< Input 14            */
#define ADC10_CV2IN15     	(0x0Ful << 4)            /**< Input 15            */

/* CV3 Input Selection                                                        */
#define ADC10_CV3IN0		(0x00ul << 8)            /**< Input 0             */
#define ADC10_CV3IN1      	(0x01ul << 8)            /**< Input 1             */ 
#define ADC10_CV3IN2      	(0x02ul << 8)            /**< Input 2             */
#define ADC10_CV3IN3      	(0x03ul << 8)            /**< Input 3             */
#define ADC10_CV3IN4      	(0x04ul << 8)            /**< Input 4             */
#define ADC10_CV3IN5      	(0x05ul << 8)            /**< Input 5             */
#define ADC10_CV3IN6      	(0x06ul << 8)            /**< Input 6             */
#define ADC10_CV3IN7      	(0x07ul << 8)            /**< Input 7             */
#define ADC10_CV3IN8      	(0x08ul << 8)            /**< Input 8             */
#define ADC10_CV3IN9      	(0x09ul << 8)            /**< Input 9             */
#define ADC10_CV3IN10    	(0x0Aul << 8)            /**< Input 10            */
#define ADC10_CV3IN11    	(0x0Bul << 8)            /**< Input 11            */
#define ADC10_CV3IN12     	(0x0Cul << 8)            /**< Input 12            */
#define ADC10_CV3IN13     	(0x0Dul << 8)            /**< Input 13            */
#define ADC10_CV3IN14     	(0x0Eul << 8)            /**< Input 14            */
#define ADC10_CV3IN15     	(0x0Ful << 8)            /**< Input 15            */

/* CV4 Input Selection                                                       */
#define ADC10_CV4IN0		(0x00ul << 12)           /**< Input 0             */
#define ADC10_CV4IN1      	(0x01ul << 12)           /**< Input 1             */
#define ADC10_CV4IN2      	(0x02ul << 12)           /**< Input 2             */
#define ADC10_CV4IN3      	(0x03ul << 12)           /**< Input 3             */
#define ADC10_CV4IN4      	(0x04ul << 12)           /**< Input 4             */
#define ADC10_CV4IN5      	(0x05ul << 12)           /**< Input 5             */
#define ADC10_CV4IN6      	(0x06ul << 12)           /**< Input 6             */
#define ADC10_CV4IN7      	(0x07ul << 12)           /**< Input 7             */
#define ADC10_CV4IN8      	(0x08ul << 12)           /**< Input 8             */
#define ADC10_CV4IN9      	(0x09ul << 12)           /**< Input 9             */
#define ADC10_CV4IN10    	(0x0Aul << 12)           /**< Input 10            */
#define ADC10_CV4IN11     	(0x0Bul << 12)           /**< Input 11            */
#define ADC10_CV4IN12     	(0x0Cul << 12)           /**< Input 12            */
#define ADC10_CV4IN13     	(0x0Dul << 12)           /**< Input 13            */
#define ADC10_CV4IN14     	(0x0Eul << 12)           /**< Input 14            */
#define ADC10_CV4IN15     	(0x0Ful << 12)           /**< Input 15            */

/* CV5 Input Selection                                                       */
#define ADC10_CV5IN0		(0x00ul << 16)           /**< Input 0             */
#define ADC10_CV5IN1      	(0x01ul << 16)           /**< Input 1             */
#define ADC10_CV5IN2      	(0x02ul << 16)           /**< Input 2             */
#define ADC10_CV5IN3      	(0x03ul << 16)           /**< Input 3             */
#define ADC10_CV5IN4      	(0x04ul << 16)           /**< Input 4             */
#define ADC10_CV5IN5      	(0x05ul << 16)           /**< Input 5             */ 
#define ADC10_CV5IN6      	(0x06ul << 16)           /**< Input 6             */
#define ADC10_CV5IN7      	(0x07ul << 16)           /**< Input 7             */
#define ADC10_CV5IN8      	(0x08ul << 16)           /**< Input 8             */
#define ADC10_CV5IN9      	(0x09ul << 16)           /**< Input 9             */
#define ADC10_CV5IN10    	(0x0Aul << 16)           /**< Input 10            */
#define ADC10_CV5IN11    	(0x0Bul << 16)           /**< Input 11            */
#define ADC10_CV5IN12    	(0x0Cul << 16)           /**< Input 12            */
#define ADC10_CV5IN13     	(0x0Dul << 16)           /**< Input 13            */
#define ADC10_CV5IN14     	(0x0Eul << 16)           /**< Input 14            */
#define ADC10_CV5IN15     	(0x0Ful << 16)           /**< Input 15            */

/* CV6 Input Selection                                                       */
#define ADC10_CV6IN0		(0x00ul << 20)           /**< Input 0             */
#define ADC10_CV6IN1      	(0x01ul << 20)           /**< Input 1             */
#define ADC10_CV6IN2      	(0x02ul << 20)           /**< Input 2             */
#define ADC10_CV6IN3      	(0x03ul << 20)           /**< Input 3             */
#define ADC10_CV6IN4      	(0x04ul << 20)           /**< Input 4             */
#define ADC10_CV6IN5      	(0x05ul << 20)           /**< Input 5             */
#define ADC10_CV6IN6      	(0x06ul << 20)           /**< Input 6             */
#define ADC10_CV6IN7      	(0x07ul << 20)           /**< Input 7             */
#define ADC10_CV6IN8      	(0x08ul << 20)           /**< Input 8             */
#define ADC10_CV6IN9      	(0x09ul << 20)           /**< Input 9             */
#define ADC10_CV6IN10     	(0x0Aul << 20)           /**< Input 10            */
#define ADC10_CV6IN11     	(0x0Bul << 20)           /**< Input 11            */
#define ADC10_CV6IN12     	(0x0Cul << 20)           /**< Input 12            */
#define ADC10_CV6IN13     	(0x0Dul << 20)           /**< Input 13            */
#define ADC10_CV6IN14     	(0x0Eul << 20)           /**< Input 14            */
#define ADC10_CV6IN15     	(0x0Ful << 20)           /**< Input 15            */

/* CV7 Input Selection                                                        */
#define ADC10_CV7IN0		(0x00ul << 24)           /**< Input 0             */
#define ADC10_CV7IN1      	(0x01ul << 24)           /**< Input 1             */
#define ADC10_CV7IN2      	(0x02ul << 24)           /**< Input 2             */
#define ADC10_CV7IN3      	(0x03ul << 24)           /**< Input 3             */
#define ADC10_CV7IN4      	(0x04ul << 24)           /**< Input 4             */
#define ADC10_CV7IN5      	(0x05ul << 24)           /**< Input 5             */
#define ADC10_CV7IN6      	(0x06ul << 24)           /**< Input 6             */
#define ADC10_CV7IN7      	(0x07ul << 24)           /**< Input 7             */
#define ADC10_CV7IN8      	(0x08ul << 24)           /**< Input 8             */
#define ADC10_CV7IN9      	(0x09ul << 24)           /**< Input 9             */
#define ADC10_CV7IN10    	(0x0Aul << 24)           /**< Input 10            */
#define ADC10_CV7IN11     	(0x0Bul << 24)           /**< Input 11            */
#define ADC10_CV7IN12     	(0x0Cul << 24)           /**< Input 12            */
#define ADC10_CV7IN13     	(0x0Dul << 24)           /**< Input 13            */
#define ADC10_CV7IN14     	(0x0Eul << 24)           /**< Input 14            */
#define ADC10_CV7IN15     	(0x0Ful << 24)           /**< Input 15            */

/* CV8 Input Selection                                                       */
#define ADC10_CV8IN0		(0x00ul << 28)           /**< Input 0             */
#define ADC10_CV8IN1      	(0x01ul << 28)           /**< Input 1             */
#define ADC10_CV8IN2      	(0x02ul << 28)           /**< Input 2             */
#define ADC10_CV8IN3      	(0x03ul << 28)           /**< Input 3             */
#define ADC10_CV8IN4      	(0x04ul << 28)           /**< Input 4             */
#define ADC10_CV8IN5      	(0x05ul << 28)           /**< Input 5             */
#define ADC10_CV8IN6      	(0x06ul << 28)           /**< Input 6             */
#define ADC10_CV8IN7      	(0x07ul << 28)           /**< Input 7             */
#define ADC10_CV8IN8      	(0x08ul << 28)           /**< Input 8             */
#define ADC10_CV8IN9      	(0x09ul << 28)           /**< Input 9             */
#define ADC10_CV8IN10    	(0x0Aul << 28)           /**< Input 10            */
#define ADC10_CV8IN11     	(0x0Bul << 28)           /**< Input 11            */
#define ADC10_CV8IN12    	(0x0Cul << 28)           /**< Input 12            */
#define ADC10_CV8IN13     	(0x0Dul << 28)           /**< Input 13            */
#define ADC10_CV8IN14     	(0x0Eul << 28)           /**< Input 14            */
#define ADC10_CV8IN15     	(0x0Ful << 28)           /**< Input 15            */

/* CV9 Input Selection                                                       */
#define ADC10_CV9IN0		(0x00ul << 0)           /**< Input 0              */
#define ADC10_CV9IN1      	(0x01ul << 0)           /**< Input 1              */
#define ADC10_CV9IN2      	(0x02ul << 0)           /**< Input 2              */
#define ADC10_CV9IN3      	(0x03ul << 0)           /**< Input 3              */
#define ADC10_CV9IN4		(0x04ul << 0)           /**< Input 4              */
#define ADC10_CV9IN5      	(0x05ul << 0)           /**< Input 5              */
#define ADC10_CV9IN6      	(0x06ul << 0)           /**< Input 6              */
#define ADC10_CV9IN7      	(0x07ul << 0)           /**< Input 7              */
#define ADC10_CV9IN8      	(0x08ul << 0)           /**< Input 8              */
#define ADC10_CV9IN9      	(0x09ul << 0)           /**< Input 9              */
#define ADC10_CV9IN10     	(0x0Aul << 0)           /**< Input 10             */
#define ADC10_CV9IN11     	(0x0Bul << 0)           /**< Input 11             */
#define ADC10_CV9IN12     	(0x0Cul << 0)           /**< Input 12             */
#define ADC10_CV9IN13     	(0x0Dul << 0)           /**< Input 13             */
#define ADC10_CV9IN14     	(0x0Eul << 0)           /**< Input 14             */
#define ADC10_CV9IN15     	(0x0Ful << 0)           /**< Input 15             */

/* CV10 Input Selection                                                      */
#define ADC10_CV10IN0		(0x00ul << 4)           /**< Input 0             */
#define ADC10_CV10IN1     	(0x01ul << 4)           /**< Input 1             */
#define ADC10_CV10IN2     	(0x02ul << 4)           /**< Input 2             */
#define ADC10_CV10IN3		(0x03ul << 4)           /**< Input 3             */
#define ADC10_CV10IN4     	(0x04ul << 4)           /**< Input 4             */
#define ADC10_CV10IN5     	(0x05ul << 4)           /**< Input 5             */
#define ADC10_CV10IN6     	(0x06ul << 4)           /**< Input 6             */
#define ADC10_CV10IN7     	(0x07ul << 4)           /**< Input 7             */
#define ADC10_CV10IN8     	(0x08ul << 4)           /**< Input 8             */
#define ADC10_CV10IN9     	(0x09ul << 4)           /**< Input 9             */
#define ADC10_CV10IN10    	(0x0Aul << 4)           /**< Input 10            */
#define ADC10_CV10IN11    	(0x0Bul << 4)           /**< Input 11            */
#define ADC10_CV10IN12    	(0x0Cul << 4)           /**< Input 12            */
#define ADC10_CV10IN13    	(0x0Dul << 4)           /**< Input 13            */
#define ADC10_CV10IN14    	(0x0Eul << 4)           /**< Input 14            */
#define ADC10_CV10IN15    	(0x0Ful << 4)           /**< Input 15            */

/* CV11 Input Selection                                                      */
#define ADC10_CV11IN0		(0x00ul << 8)           /**< Input 0             */
#define ADC10_CV11IN1     	(0x01ul << 8)           /**< Input 1             */
#define ADC10_CV11IN2     	(0x02ul << 8)           /**< Input 2             */
#define ADC10_CV11IN3     	(0x03ul << 8)           /**< Input 3             */
#define ADC10_CV11IN4     	(0x04ul << 8)           /**< Input 4             */
#define ADC10_CV11IN5     	(0x05ul << 8)           /**< Input 5             */
#define ADC10_CV11IN6     	(0x06ul << 8)           /**< Input 6             */
#define ADC10_CV11IN7     	(0x07ul << 8)           /**< Input 7             */
#define ADC10_CV11IN8     	(0x08ul << 8)           /**< Input 8             */
#define ADC10_CV11IN9     	(0x09ul << 8)           /**< Input 9             */
#define ADC10_CV11IN10    	(0x0Aul << 8)           /**< Input 10            */
#define ADC10_CV11IN11    	(0x0Bul << 8)           /**< Input 11            */
#define ADC10_CV11IN12    	(0x0Cul << 8)           /**< Input 12            */
#define ADC10_CV11IN13    	(0x0Dul << 8)           /**< Input 13            */
#define ADC10_CV11IN14    	(0x0Eul << 8)           /**< Input 14            */
#define ADC10_CV11IN15    	(0x0Ful << 8)           /**< Input 15            */

/* CV12 Input Selection                                                      */
#define ADC10_CV12IN0		(0x00ul << 12)           /**< Input 0            */
#define ADC10_CV12IN1     	(0x01ul << 12)           /**< Input 1            */
#define ADC10_CV12IN2     	(0x02ul << 12)           /**< Input 2            */
#define ADC10_CV12IN3     	(0x03ul << 12)           /**< Input 3            */
#define ADC10_CV12IN4     	(0x04ul << 12)           /**< Input 4            */ 
#define ADC10_CV12IN5     	(0x05ul << 12)           /**< Input 5            */
#define ADC10_CV12IN6     	(0x06ul << 12)           /**< Input 6            */
#define ADC10_CV12IN7     	(0x07ul << 12)           /**< Input 7            */
#define ADC10_CV12IN8     	(0x08ul << 12)           /**< Input 8            */
#define ADC10_CV12IN9     	(0x09ul << 12)           /**< Input 9            */
#define ADC10_CV12IN10    	(0x0Aul << 12)           /**< Input 10           */
#define ADC10_CV12IN11    	(0x0Bul << 12)           /**< Input 11           */
#define ADC10_CV12IN12    	(0x0Cul << 12)           /**< Input 12           */
#define ADC10_CV12IN13    	(0x0Dul << 12)           /**< Input 13           */
#define ADC10_CV12IN14    	(0x0Eul << 12)           /**< Input 14           */
#define ADC10_CV12IN15    	(0x0Ful << 12)           /**< Input 15           */

/* CV13 Input Selection                                                      */
#define ADC10_CV13IN0		(0x00ul << 16)           /**< Input 0            */
#define ADC10_CV13IN1     	(0x01ul << 16)           /**< Input 1            */
#define ADC10_CV13IN2     	(0x02ul << 16)           /**< Input 2            */
#define ADC10_CV13IN3     	(0x03ul << 16)           /**< Input 3            */
#define ADC10_CV13IN4     	(0x04ul << 16)           /**< Input 4            */
#define ADC10_CV13IN5     	(0x05ul << 16)           /**< Input 5            */
#define ADC10_CV13IN6     	(0x06ul << 16)           /**< Input 6            */
#define ADC10_CV13IN7     	(0x07ul << 16)           /**< Input 7            */
#define ADC10_CV13IN8     	(0x08ul << 16)           /**< Input 8            */
#define ADC10_CV13IN9     	(0x09ul << 16)           /**< Input 9            */
#define ADC10_CV13IN10    	(0x0Aul << 16)           /**< Input 10           */
#define ADC10_CV13IN11    	(0x0Bul << 16)           /**< Input 11           */ 
#define ADC10_CV13IN12    	(0x0Cul << 16)           /**< Input 12           */
#define ADC10_CV13IN13    	(0x0Dul << 16)           /**< Input 13           */
#define ADC10_CV13IN14    	(0x0Eul << 16)           /**< Input 14           */
#define ADC10_CV13IN15    	(0x0Ful << 16)           /**< Input 15           */


/* CV14 Input Selection                                                      */
#define ADC10_CV14IN0		(0x00ul << 20)           /**< Input 0            */
#define ADC10_CV14IN1     	(0x01ul << 20)           /**< Input 1            */
#define ADC10_CV14IN2     	(0x02ul << 20)           /**< Input 2            */
#define ADC10_CV14IN3     	(0x03ul << 20)           /**< Input 3            */
#define ADC10_CV14IN4     	(0x04ul << 20)           /**< Input 4            */
#define ADC10_CV14IN5     	(0x05ul << 20)           /**< Input 5            */
#define ADC10_CV14IN6     	(0x06ul << 20)           /**< Input 6            */
#define ADC10_CV14IN7     	(0x07ul << 20)           /**< Input 7            */
#define ADC10_CV14IN8     	(0x08ul << 20)           /**< Input 8            */
#define ADC10_CV14IN9     	(0x09ul << 20)           /**< Input 9            */
#define ADC10_CV14IN10    	(0x0Aul << 20)           /**< Input 10           */
#define ADC10_CV14IN11    	(0x0Bul << 20)           /**< Input 11           */
#define ADC10_CV14IN12    	(0x0Cul << 20)           /**< Input 12           */
#define ADC10_CV14IN13    	(0x0Dul << 20)           /**< Input 13           */
#define ADC10_CV14IN14    	(0x0Eul << 20)           /**< Input 14           */
#define ADC10_CV14IN15    	(0x0Ful << 20)           /**< Input 15           */


/* CV15 Input Selection                                                      */
#define ADC10_CV15IN0		(0x00ul << 24)           /**< Input 0            */
#define ADC10_CV15IN1     	(0x01ul << 24)           /**< Input 1            */
#define ADC10_CV15IN2     	(0x02ul << 24)           /**< Input 2            */
#define ADC10_CV15IN3     	(0x03ul << 24)           /**< Input 3            */
#define ADC10_CV15IN4     	(0x04ul << 24)           /**< Input 4            */
#define ADC10_CV15IN5     	(0x05ul << 24)           /**< Input 5            */
#define ADC10_CV15IN6     	(0x06ul << 24)           /**< Input 6            */
#define ADC10_CV15IN7     	(0x07ul << 24)           /**< Input 7            */
#define ADC10_CV15IN8     	(0x08ul << 24)           /**< Input 8            */
#define ADC10_CV15IN9     	(0x09ul << 24)           /**< Input 9            */
#define ADC10_CV15IN10    	(0x0Aul << 24)           /**< Input 10           */
#define ADC10_CV15IN11    	(0x0Bul << 24)           /**< Input 11           */
#define ADC10_CV15IN12    	(0x0Cul << 24)           /**< Input 12           */
#define ADC10_CV15IN13    	(0x0Dul << 24)           /**< Input 13           */
#define ADC10_CV15IN14    	(0x0Eul << 24)           /**< Input 14           */
#define ADC10_CV15IN15    	(0x0Ful << 24)           /**< Input 15           */


/* CV16 Input Selection                                                      */
#define ADC10_CV16IN0		(0x00ul << 28)           /**< Input 0            */
#define ADC10_CV16IN1     	(0x01ul << 28)           /**< Input 1            */
#define ADC10_CV16IN2     	(0x02ul << 28)           /**< Input 2            */
#define ADC10_CV16IN3     	(0x03ul << 28)           /**< Input 3            */
#define ADC10_CV16IN4     	(0x04ul << 28)           /**< Input 4            */
#define ADC10_CV16IN5     	(0x05ul << 28)           /**< Input 5            */
#define ADC10_CV16IN6     	(0x06ul << 28)           /**< Input 6            */
#define ADC10_CV16IN7     	(0x07ul << 28)           /**< Input 7            */
#define ADC10_CV16IN8     	(0x08ul << 28)           /**< Input 8            */
#define ADC10_CV16IN9     	(0x09ul << 28)           /**< Input 9            */
#define ADC10_CV16IN10    	(0x0Aul << 28)           /**< Input 10           */
#define ADC10_CV16IN11    	(0x0Bul << 28)           /**< Input 11           */
#define ADC10_CV16IN12    	(0x0Cul << 28)           /**< Input 12           */
#define ADC10_CV16IN13    	(0x0Dul << 28)           /**< Input 13           */
#define ADC10_CV16IN14    	(0x0Eul << 28)           /**< Input 14           */
#define ADC10_CV16IN15    	(0x0Ful << 28)           /**< Input 15           */
#define ADC10_ADCIN0      	0x0ul                    /**< ADC Analog Input 0 */
#define ADC10_ADCIN1      	0x1ul                    /**< ADC Analog Input 1 */
#define ADC10_ADCIN2      	0x2ul                    /**< ADC Analog Input 2 */
#define ADC10_ADCIN3      	0x3ul                    /**< ADC Analog Input 3 */
#define ADC10_ADCIN4      	0x4ul                    /**< ADC Analog Input 4 */
#define ADC10_ADCIN5      	0x5ul                    /**< ADC Analog Input 5 */
#define ADC10_ADCIN6      	0x6ul                    /**< ADC Analog Input 6 */
#define ADC10_ADCIN7      	0x7ul                    /**< ADC Analog Input 7 */
#define ADC10_ADCIN8      	0x8ul                    /**< ADC Analog Input 8 */
#define ADC10_ADCIN9      	0x9ul                    /**< ADC Analog Input 9 */
#define ADC10_ADCIN10    	0xAul                    /**< ADC Analog Input 10*/
#define ADC10_ADCIN11     	0xBul                    /**< ADC Analog Input 11*/
#define ADC10_ADCIN12     	0xCul                    /**< ADC Analog Input 12*/
#define ADC10_ADCIN13     	0xDul                    /**< ADC Analog Input 13*/
#define ADC10_ADCIN14     	0xEul                    /**< ADC Analog Input 14*/
#define ADC10_ADCIN15     	0xFul                    /**< ADC Analog Input 15*/ 


/*******************************************************************************
* DR : ADC10 Convert Data Register  
*******************************************************************************/
 #define DATA				(0x3FFul << 0)		/**< ADC10 Converted Data Mask*/

/*******************************************************************************
***************************** ADC10 REGISTER MASK  *****************************
*******************************************************************************/
#define ADC_ECR_MASK		(0x80000002ul)       	/**< ECR  mask        */
#define ADC_DCR_MASK      	(0x80000002ul)       	/**< DCR  mask        */
#define ADC_PMSR_MASK     	(0x80000002ul)         	/**< PMSR mask        */
#define ADC_CR_MASK       	(0x0000001Ful)        	/**< CR   mask        */
#define ADC_MR_MASK       	(0x001FFF7Ful)        	/**< MR   mask        */
#define ADC_CSR_MASK      	(0x0000000Cul)         	/**< CSR  mask        */
#define ADC_SR_MASK       	(0x0000030Ful)         	/**< SR   mask        */
#define ADC_IER_MASK      	(0x0000000Ful)         	/**< IER  mask        */
#define ADC_IDR_MASK      	(0x0000000Ful)         	/**< IDR  mask        */
#define ADC_IMR_MASK      	(0x0000000Ful)         	/**< IMR  mask        */
#define ADC_CMR0_MASK    	(0xFFFFFFFFul)         	/**< CMR0  mask  	  */
#define ADC_CMR1_MASK   	(0xFFFFFFFFul)         	/**< CMR1  mask    	  */
#define ADC_DR_MASK      	(0x000003FFul)         	/**< DR   mask     	  */

/*******************************************************************************
************************  ADC10 REGISTERS RESET VALUE **************************
*******************************************************************************/
#define ADC_ECR_RST 		(0x00000000ul)          /**< ECR  reset value  */
#define ADC_DCR_RST       	(0x00000000ul)          /**< DCR  reset value  */
#define ADC_PMSR_RST      	(ADC10_IPIDCODE_MASK) /**< PMSR reset value  */
#define ADC_CR_RST        	(0x00000000ul)          /**< CR   reset value  */
#define ADC_MR_RST        	(0x00000000ul)          /**< MR   reset value  */
#define ADC_CSR_RST       	(0x00000000ul)          /**< CSR  reset value  */
#define ADC_SR_RST        	(0x00000000ul)          /**< SR   reset value  */
#define ADC_IER_RST      	(0x00000000ul)          /**< IER  reset value  */
#define ADC_IDR_RST       	(0x00000000ul)          /**< IDR  reset value  */
#define ADC_IMR_RST       	(0x00000000ul)          /**< IMR  reset value  */
#define ADC_CMR0_RST      	(0x00000000ul)          /**< CMR0  reset value */
#define ADC_CMR1_RST      	(0x00000000ul)          /**< CMR1  reset value */
#define ADC_DR_RST        	(0x00000000ul)          /**< DR   reset value  */

/*******************************************************************************
************************** ADC10 MACROS DEFINITION  ****************************
*******************************************************************************/
/** ECR, DCR, PMSR : ADC10 Power Management Registers                          */

/* Set ECR register (Enable) 	                                               */
#define CSP_ADC10_SET_ECR(adc, val)		((adc)->ECR = (val))
 
/* Set DCR register (Disable)                                                  */
#define CSP_ADC10_SET_DCR(adc, val)		((adc)->DCR = (val))
 
/* Get PMSR register (Status)                                                  */
#define CSP_ADC10_GET_PMSR(adc)			((adc)->PMsSR)

/* CR : ADC10 Control Register                                                 */
/* Set CR register (Control Register)                                          */
#define CSP_ADC10_SET_CR(adc, val)		((adc)->CR = (val))

/* MR : ADC10 Mode Register                                                    */
/* Get MR register (Mode Register)                                             */
#define CSP_ADC10_GET_MR(adc)			((adc)->MR)

/* Set MR register (Mode Register)                                             */
#define CSP_ADC10_SET_MR(adc, mode)		((adc)->MR = (mode))

/* CSR, SR : ADC10 Status Registers                                            */
/* Set CSR register (Clear Status Register)                                    */
#define CSP_ADC10_SET_CSR(adc, val)		((adc)->CSR = (val))

/* Get SR register (Status Register)                                           */
#define CSP_ADC10_GET_SR(adc) 			((adc)->SR)

/* IER, IDR, IMR : ADC10 Interrupt Registers                                   */
/* Set IER register (Enable Interrupt)                                         */
#define CSP_ADC10_SET_IER(adc, val)		((adc)->IER = (val))

/* Set IDR register (Disable Interrupt)                                        */
#define CSP_ADC10_SET_IDR(adc, val)		((adc)->IDR = (val))

/* Get IMR register (Status Interrupt)                                         */
#define CSP_ADC10_GET_IMR(adc)  		((adc)->IMR)

/* CMR0 : ADC10 Conversion Mode Register 0                                     */
/* Get CMR0 register (Conversion Mode register 0)                              */
#define CSP_ADC10_GET_CMR0(adc)			((adc)->CMR0)

/* Set CMR register (Conversion Mode register)                                 */
#define CSP_ADC10_SET_CMR0(adc, val)	((adc)->CMR0 = (val))
					
/* CMR1 : ADC10 Conversion Mode Register 1                                     */
/* Get CMR0 register (Conversion Mode register 1)                              */
#define CSP_ADC10_GET_CMR1(adc)			((adc)->CMR1)

/* Set CMR register (Conversion Mode register)                                 */
#define CSP_ADC10_SET_CMR1(adc, val) ((adc)->CMR1 = (val))

/* DR : ADC10 Convert Data Register                                            */
/* Get DR register                                                             */
#define CSP_ADC10_GET_DR(adc)         ((adc)->DR)


/*******************************************************************************
***********************   ADC10 EXTERNAL FUNCTIONS   ***************************
*******************************************************************************/
extern void CSP_ADC10Init(CSP_ADC10_T *const adc, U32_T mode_u32);
extern void CSP_ADC10Close(CSP_ADC10_T *const adc);
extern void CSP_ADC10ConfigInterrupt(CSP_ADC10_T *const adc, 
                                     U32_T intMode_u32, 
                                     U32_T intMask_u32, 
                                     U32_T callback_u32);
extern void CSP_ADC10StartConversion(CSP_ADC10_T *const adc, 
                                     U16_T *data_p_u16, 
                                     U32_T orderConversion0_u32,
                                     U32_T orderConversion1_u32,  
                                     U8_T nbConversion_u8);
extern void CSP_ADC10StopConversion(CSP_ADC10_T *const adc);
extern void CSP_ADC10Enable(CSP_ADC10_T *const adc);
extern void CSP_ADC10Disable(CSP_ADC10_T *const adc);

#endif   /*_CSP_ADC10_H */



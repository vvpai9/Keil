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
* @file name	csp_ipidcodes.h
* @description	Definitions, Macros and function declarations 
*            	for IPIDCODES module
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
*		IPIDCODE/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 

#ifndef _CSP_IPIDCODE_H
#define _CSP_IPIDCODE_H

/*******************************************************************************
***********************   IPIDCODE STRUCTURE DEFINITION   ************************
*******************************************************************************/

#define IPIDCODE_ADC_16CH_0 	(507852ul << 4)
#define IPIDCODE_ASB_DFC0 		(500410ul << 4)
#define IPIDCODE_ASB_IFC0 		(513038ul << 4)
#define IPIDCODE_CAPTURE0 		(507860ul << 4)
#define IPIDCODE_CAPTURE1 		(507860ul << 4)
#define IPIDCODE_EPC0 			(509461ul << 4)
#define IPIDCODE_GPT0 			(509477ul << 4)
#define IPIDCODE_I2C0 			(507870ul << 4)
#define IPIDCODE_I2C1 			(507870ul << 4)
#define IPIDCODE_PIO0 			(506657ul << 4)
#define IPIDCODE_PIO1 			(506657ul << 4)
#define IPIDCODE_PIO2 			(506657ul << 4)
#define IPIDCODE_PIO3 			(506657ul << 4)
#define IPIDCODE_PWM0 			(507880ul << 4)
#define IPIDCODE_SIMPLETIMER16_0 		(515048ul << 4)
#define IPIDCODE_SIMPLETIMER16_SY0 		(515106ul << 4)
#define IPIDCODE_SIMPLETIMER16_SY1 		(515106ul << 4)
#define IPIDCODE_SPI8_0 		(507901ul << 4)
#define IPIDCODE_SPI_0 			(508852ul << 4)
#define IPIDCODE_STEPPER0 		(507553ul << 4)
#define IPIDCODE_STEPPER1 		(507553ul << 4)
#define IPIDCODE_STEPPER2 		(507553ul << 4)
#define IPIDCODE_STEPPER3 		(507553ul << 4)
#define IPIDCODE_STEPPER4 		(507553ul << 4)
#define IPIDCODE_STEPPER5 		(507553ul << 4)
#define IPIDCODE_UART0 			(507906ul << 4)
#define IPIDCODE_UART1 			(507906ul << 4)
#define IPIDCODE_USART0 		(507906ul << 4)
#define IPIDCODE_WATCHDOG0 		(509488ul << 4)

#endif   /** CSP_IPIDCODE_H */

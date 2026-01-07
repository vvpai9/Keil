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
* @file name	csp_irc.h
* @description	Definitions, Macros and function declarations 
*            	for Internal RAM Controller module
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
*		IRC/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 


#ifndef _CSP_IRC_H
#define _CSP_IRC_H

/*******************************************************************************
***********************    IRC STRUCTURE DEFINITION   **************************
*******************************************************************************/
typedef struct
{
	CSP_REGISTER_T    MR;                           /**< Mode Register       */
}CSP_IRC_T, *CSP_IRC_PTR;

/******************************************************************************
* MR : IRC Control Register
******************************************************************************/
#define IRC_BA_MASK      (0xFFFul << 20)           /**< Base address mask    */
#define IRC_BA(val)      (((val) & 0xFFFul) << 20) /**< Base address macro   */

/*******************************************************************************
*****************************  IRC REGISTER MASK  ******************************
*******************************************************************************/
#define IRC_MR_MASK          (0xFFF00000ul)         /**< MR mask              */

/*******************************************************************************
************************   IRC REGISTERS RESET VALUE  **************************
*******************************************************************************/
#define IRC_MR_RST          (0x00300000ul)         /**< MR reset value       */

/*******************************************************************************
**************************  IRC MACROS DEFINITION  *****************************
*******************************************************************************/
/* MR : IRC Control Register                                                 */
/** Set MR register                                                          */
#define CSP_IRC_SET_MR(irc, val)             ((irc)->MR = (val))
/** Get MR register                                                          */
#define CSP_IRC_GET_MR(irc)                  ((irc)->MR )


#endif /* _CSP_IRC_H */

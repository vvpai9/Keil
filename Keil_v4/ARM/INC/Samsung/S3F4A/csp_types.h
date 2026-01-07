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
* @file name	csp_types.h
* @description	Definitions and Structures
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
*/ 




#ifndef CSP_TYPES_H
#define CSP_TYPES_H

/******************************************************************************
*********************************** TYPES *************************************
******************************************************************************/

/******************************************************************************
* Data Types
******************************************************************************/
/* Signed Types                                                              */
typedef signed char     S8_T;
typedef short           S16_T;
typedef long            S32_T;

/* Unsigned Types                                                            */
typedef unsigned char   U8_T;
typedef unsigned short  U16_T;
typedef unsigned long   U32_T;
typedef unsigned long long U64_T;

/* Float Types                                                               */
typedef float           F32_T;
typedef double          F64_T;

/* Boolean types declared as U8_T, as enums are generated as 16 bit          */
typedef U8_T            B_T;

/* Definitions for the two members of the Boolean type                       */
#ifndef FALSE
#define FALSE ((B_T) 0)
#endif

#ifndef TRUE
#define TRUE  ((B_T) 1)
#endif

/* UNUSED Definition for unused Interrupt numbers * and unused PDC channels  */
/* in the CHIP structure. (cf. CSP.C file)                                   */
#ifndef UNUSED
#define UNUSED ((U8_T) 0xFF)
#endif

/* NULL definition */
#ifndef NULL
#define NULL  0
#endif

/******************************************************************************
* Peripherals Type
******************************************************************************/
typedef volatile U32_T CSP_REGISTER_T; 


#endif   /* CSP_TYPE_H */

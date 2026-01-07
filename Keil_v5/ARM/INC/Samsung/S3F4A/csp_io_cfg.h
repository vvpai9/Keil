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
* @file name	csp_io_cfg.h
* @description	Definitions, Macros and function declarations 
*            	for IO_CFG module
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
*		IOCONG/ /S3F4A0K/AGP1 EVB Rev1.0
*/ 

#ifndef _CSP_IOCFG_H
#define _CSP_IOCFG_H

/*******************************************************************************
***********************   IO_CFG STRUCTURE DEFINITION   ************************
*******************************************************************************/
	
/** Number of PIO Block                                                      */
#define PIO_BLOCK_NUMBER		4u

#define UNUSED_ADDRESS			0xDEADDEADul    /**< Unused address            */


/*******************************************************************************
* Description CSP_IO_CFG_T and CSP_IO_CFG_PTR
*******************************************************************************/
typedef struct 
{ 
    CSP_REGISTER_T	MR0;
    CSP_REGISTER_T 	MR1;
    CSP_REGISTER_T 	MR2;
    CSP_REGISTER_T 	MR3;
    CSP_REGISTER_T 	MR4;
    CSP_REGISTER_T 	MR5;
    CSP_REGISTER_T 	MR6;
    CSP_REGISTER_T 	MR7;
    CSP_REGISTER_T 	MR8;
    CSP_REGISTER_T 	MR9;
    CSP_REGISTER_T 	MR10;
    CSP_REGISTER_T 	MR11;
    CSP_REGISTER_T 	MR12;
    CSP_REGISTER_T 	MR13;
    CSP_REGISTER_T 	MR14;
    CSP_REGISTER_T 	MR15;
    CSP_REGISTER_T 	MR16;
}CSP_IO_CFG_T, *CSP_IO_CFG_PTR;
/*******************************************************************************
**********************   IO_CFG OREGISTERS DEFINITION   ************************
*******************************************************************************/	

/*******************************************************************************
* MR0 : IO_CFG Mode Register
******************************************************************************/
#define IO_CFG_PIO0_0_PUENB	(0x01ul << 0)		/* Enable/Disable Pull up     */
#define IO_CFG_PIO0_1_PUENB (0x01ul << 4)		/* Enable/Disable Pull up     */
#define IO_CFG_PIO0_2_PUENB (0x01ul << 8)		/* Enable/Disable Pull up     */
#define IO_CFG_PIO0_2_F3EN  (0x01ul << 11)		/* Enable/Disable 3rd function*/
#define IO_CFG_PIO0_3_PUENB (0x01ul << 12)		/* Enable/Disable Pull up	  */        
#define IO_CFG_PIO0_3_F3EN  (0x01ul << 15) 		/* Enable/Disable 3rd function*/
#define IO_CFG_PIO0_4_PUENB (0x01ul << 16) 		/* Enable/Disable Pull up     */          
#define IO_CFG_PIO0_5_PUENB (0x01ul << 20) 		/* Enable/Disable Pull up     */         
#define IO_CFG_PIO0_6_PUENB (0x01ul << 24) 		/* Enable/Disable Pull up     */        
#define IO_CFG_PIO0_7_PUENB (0x01ul << 28) 		/* Enable/Disable Pull up     */
/******************************************************************************
* MR1 : IO_CFG Mode Register
******************************************************************************/
#define IO_CFG_PIO0_8_PUENB  	(0x01ul << 0)	/* Enable/Disable Pull up     */
#define IO_CFG_PIO0_8_F3EN   	(0x01ul << 3)    /* Enable/Disable 3rd function*/                                                      
#define IO_CFG_PIO0_9_PUENB  	(0x01ul << 4)    /* Enable/Disable Pull up     */                                                
#define IO_CFG_PIO0_9_F3EN   	(0x01ul << 7)    /* Enable/Disable 3rd function*/                                             
#define IO_CFG_PIO0_10_PUENB	(0x01ul << 8)    /* Enable/Disable Pull up     */                                                    
#define IO_CFG_PIO0_10_F3EN  	(0x01ul << 11)   /* Enable/Disable 3rd function*/                                             
#define IO_CFG_PIO0_11_PUENB    (0x01ul << 12)   /* Enable/Disable Pull up     */                        
#define IO_CFG_PIO0_11_F3EN     (0x01ul << 15)   /* Enable/Disable 3rd function*/  
#define IO_CFG_PIO0_12_PUENB 	(0x01ul << 16)   /* Enable/Disable Pull up     */                                                   
#define IO_CFG_PIO0_12_F3EN  	(0x01ul << 19)   /* Enable/Disable 3rd function*/                                          
#define IO_CFG_PIO0_13_PUENB 	(0x01ul << 20)   /* Enable/Disable Pull up     */                                                      
#define IO_CFG_PIO0_13_F3EN  	(0x01ul << 23)   /* Enable/Disable T3rd function*/                                           
#define IO_CFG_PIO0_14_PUENB 	(0x01ul << 24)   /* Enable/Disable Pull up     */                                                    
#define IO_CFG_PIO0_14_F3EN  	(0x01ul << 27)   /* Enable/Disable T3rd function*/  
#define IO_CFG_PIO0_15_PUENB 	(0x01ul << 28)   /* Enable/Disable Pull up     */                                                   
#define IO_CFG_PIO0_15_F3EN  	(0x01ul << 31)   /* Enable/Disable 3rd function*/                                                                                                 

/*******************************************************************************
* MR2 : IO_CFG Mode Register
*******************************************************************************/
#define IO_CFG_PIO0_16_PUENB  (0x01ul << 0)	/**< Enable/Disable Pull up  */	                                                      
#define IO_CFG_PIO0_16_F3EN   (0x01ul << 3)	/**< Enable/Disable Third    */                                                                                                   
#define IO_CFG_PIO0_17_PUENB  (0x01ul << 4)  	/**< Enable/Disable Pull up  */                                                          
#define IO_CFG_PIO0_17_F3EN   (0x01ul << 7)	/**< Enable/Disable Third    */                                                   
#define IO_CFG_PIO0_18_PUENB  (0x01ul << 8)  	/**< Enable/Disable Pull up  */                                                    
#define IO_CFG_PIO0_18_F3EN   (0x01ul << 11)	/**< Enable/Disable Third    */                                                 
#define IO_CFG_PIO0_19_PUENB  (0x01ul << 12)	/**< Enable/Disable Pull up  */                                                    
#define IO_CFG_PIO0_19_F3EN   (0x01ul << 15)	/**< Enable/Disable Third    */                                                  
#define IO_CFG_PIO0_20_PUENB  (0x01ul << 16)	/**< Enable/Disable Pull up  */                                                    
#define IO_CFG_PIO0_20_F3EN   (0x01ul << 19)	/**< Enable/Disable Third    */                                                  
#define IO_CFG_PIO0_21_PUENB  (0x01ul << 20)	/**< Enable/Disable Pull up  */                                                   
#define IO_CFG_PIO0_21_F3EN   (0x01ul << 23)	/**< Enable/Disable Third    */                                                 
#define IO_CFG_PIO0_22_PUENB  (0x01ul << 24)	/**< Enable/Disable Pull up  */                                                  
#define IO_CFG_PIO0_22_F3EN   (0x01ul << 27)	/**< Enable/Disable Third    */                                                 
 
/*******************************************************************************
* MR3 : IO_CFG Mode Register
*******************************************************************************/
#define IO_CFG_PIO1_0_PUENB   (0x01ul << 0)     /**< Enable/Disable Pull up                                                       on pin PIO1_0          */
#define IO_CFG_PIO1_0_F3EN    (0x01ul << 3)     /**< Enable/Disable Third                                                       function on pin PIO1_0 */                                                      
#define IO_CFG_PIO1_1_PUENB   (0x01ul << 4)     /**< Enable/Disable Pull up                                                       on pin PIO1_1          */
#define IO_CFG_PIO1_1_F3EN    (0x01ul << 7)     /**< Enable/Disable Third                                                       function on pin PIO1_1 */
#define IO_CFG_PIO1_2_PUENB   (0x01ul << 8)     /**< Enable/Disable Pull up                                                       on pin PIO1_2          */
#define IO_CFG_PIO1_2_F3EN    (0x01ul << 11)    /**< Enable/Disable Third                                                       function on pin PIO1_2 */
#define IO_CFG_PIO1_3_PUENB   (0x01ul << 12)    /**< Enable/Disable Pull up                                                       on pin PIO1_3          */
#define IO_CFG_PIO1_3_F3EN    (0x01ul << 15)    /**< Enable/Disable Third                                                       function on pin PIO1_3 */
#define IO_CFG_PIO1_4_PUENB   (0x01ul << 16)    /**< Enable/Disable Pull up                                                       on pin PIO1_4          */
#define IO_CFG_PIO1_4_F3EN    (0x01ul << 19)    /**< Enable/Disable Third                                                       function on pin PIO1_4 */
#define IO_CFG_PIO1_5_PUENB   (0x01ul << 20)    /**< Enable/Disable Pull up                                                        on pin PIO1_5         */
#define IO_CFG_PIO1_5_F3EN    (0x01ul << 23)    /**< Enable/Disable Third                                                       function on pin PIO1_5 */
#define IO_CFG_PIO1_6_PUENB   (0x01ul << 24)    /**< Enable/Disable Pull up                                                       on pin PIO1_6          */
#define IO_CFG_PIO1_7_PUENB   (0x01ul << 28)    /**< Enable/Disable Pull up                                                       on pin PIO1_7          */

/*******************************************************************************
* MR4 : IO_CFG Mode Register
*******************************************************************************/
#define IO_CFG_PIO1_8_PUENB   (0x01ul << 0)     /**< Enable/Disable Pull up                                                       on pin PIO1_8          */
#define IO_CFG_PIO1_8_F3EN    (0x01ul << 3)     /**< Enable/Disable Third                                                       function on pin PIO1_8 */
#define IO_CFG_PIO1_9_PUENB   (0x01ul << 4)     /**< Enable/Disable Pull up                                                       on pin PIO1_9          */
#define IO_CFG_PIO1_10_PUENB  (0x01ul << 8)     /**< Enable/Disable Pull up                                                       on pin PIO1_10         */
#define IO_CFG_PIO1_10_F3EN   (0x01ul << 11)    /**< Enable/Disable Third                                                       function on pin PIO1_10*/
#define IO_CFG_PIO1_11_PUENB  (0x01ul << 12)    /**< Enable/Disable Pull up                                                       on pin PIO1_11         */
#define IO_CFG_PIO1_11_F3EN   (0x01ul << 15)    /**< Enable/Disable Third                                                       function on pin PIO1_11*/
/*******************************************************************************
 MR5 : IO_CFG Mode Register
*******************************************************************************/
 #define IO_CFG_PIO1_12_F3EN   (0x01ul << 3)     /**< Enable/Disable Third                                                       function on pin PIO1_12*/
 #define IO_CFG_PIO1_13_F3EN   (0x01ul << 7)     /**< Enable/Disable Third                                                       function on pin PIO1_13*/
 #define IO_CFG_PIO1_14_F3EN   (0x01ul << 11)    /**< Enable/Disable Third                                                       function on pin PIO1_14*/
 #define IO_CFG_PIO1_15_F3EN   (0x01ul << 15)    /**< Enable/Disable Third                                                       function on pin PIO1_15*/
 #define IO_CFG_PIO1_16_F3EN   (0x01ul << 19)    /**< Enable/Disable Third                                                       function on pin PIO1_16*/
 #define IO_CFG_PIO1_17_F3EN   (0x01ul << 23)    /**< Enable/Disable Third                                                       function on pin PIO1_17*/
 #define IO_CFG_PIO1_18_F3EN   (0x01ul << 27)    /**< Enable/Disable Third                                                      function on pin PIO1_18*/
 #define IO_CFG_PIO1_19_F3EN   (0x01ul << 31)    /**< Enable/Disable Third                                                       function on pin PIO1_19*/
                                                      
/*******************************************************************************
* MR6 : IO_CFG Mode Register
*******************************************************************************/
#define IO_CFG_PIO1_20_F3EN   (0x01ul << 3)     /**< Enable/Disable Third                                                       function on pin PIO1_20*/
#define IO_CFG_PIO1_21_F3EN   (0x01ul << 7)     /**< Enable/Disable Third                                                       function on pin PIO1_21*/
#define IO_CFG_PIO1_22_F3EN   (0x01ul << 11)    /**< Enable/Disable Third                                                       function on pin PIO1_22*/
#define IO_CFG_PIO1_23_F3EN   (0x01ul << 15)    /**< Enable/Disable Third                                                       function on pin PIO1_23*/
#define IO_CFG_PIO1_24_F3EN   (0x01ul << 19)    /**< Enable/Disable Third                                                       function on pin PIO1_24*/
#define IO_CFG_PIO1_25_F3EN   (0x01ul << 23)    /**< Enable/Disable Third                                                       function on pin PIO1_25*/
#define IO_CFG_PIO1_26_F3EN   (0x01ul << 27)    /**< Enable/Disable Third                                                       function on pin PIO1_26*/
#define IO_CFG_PIO1_27_F3EN   (0x01ul << 31)    /**< Enable/Disable Third                                                       function on pin PIO1_27*/
/*******************************************************************************
* MR7 : IO_CFG Mode Register
*******************************************************************************/
#define IO_CFG_PIO1_28_F3EN   (0x01ul << 3)     /**< Enable/Disable Third                                                       function on pin PIO1_28*/
#define IO_CFG_PIO1_29_F3EN   (0x01ul << 7)     /**< Enable/Disable Third                                                       function on pin PIO1_29*/
#define IO_CFG_PIO1_30_F3EN   (0x01ul << 11)    /**< Enable/Disable Third                                                       function on pin PIO1_30*/
#define IO_CFG_PIO1_31_F3EN   (0x01ul << 15)    /**< Enable/Disable Third                                                       function on pin PIO1_31*/
                                                      
/*******************************************************************************
* MR8 : IO_CFG Mode Register
*******************************************************************************/
#define IO_CFG_PIO2_0_F3EN    (0x01ul << 3)     /**< Enable/Disable Third                                                       function on pin PIO2_0 */
#define IO_CFG_PIO2_1_F3EN    (0x01ul << 7)     /**< Enable/Disable Third                                                       function on pin PIO2_1 */
#define IO_CFG_PIO2_2_F3EN    (0x01ul << 11)    /**< Enable/Disable Third                                                       function on pin PIO2_2 */
#define IO_CFG_PIO2_3_F3EN    (0x01ul << 15)    /**< Enable/Disable Third                                                       function on pin PIO2_3 */
#define IO_CFG_PIO2_4_F3EN    (0x01ul << 19)    /**< Enable/Disable Third                                                       function on pin PIO2_4 */
#define IO_CFG_PIO2_5_F3EN    (0x01ul << 23)    /**< Enable/Disable Third                                                       function on pin PIO2_5 */
#define IO_CFG_PIO2_6_F3EN    (0x01ul << 27)    /**< Enable/Disable Third                                                       function on pin PIO2_6 */
#define IO_CFG_PIO2_7_F3EN    (0x01ul << 31)    /**< Enable/Disable Third                                                       function on pin PIO2_7 */
                                                     
/*******************************************************************************
* MR9 : IO_CFG Mode Register
*******************************************************************************/
#define IO_CFG_PIO2_8_F3EN    (0x01ul << 3)     /**< Enable/Disable Third                                                     function on pin PIO2_8 */
#define IO_CFG_PIO2_9_F3EN    (0x01ul << 7)     /**< Enable/Disable Third                                                       function on pin PIO2_9 */
#define IO_CFG_PIO2_10_F3EN   (0x01ul << 11)    /**< Enable/Disable Third                                                       function on pin PIO2_10*/
#define IO_CFG_PIO2_11_F3EN   (0x01ul << 15)    /**< Enable/Disable Third                                                       function on pin PIO2_11*/
#define IO_CFG_PIO2_12_F3EN   (0x01ul << 19)    /**< Enable/Disable Third                                                       function on pin PIO2_12*/
#define IO_CFG_PIO2_13_F3EN   (0x01ul << 23)    /**< Enable/Disable Third                                                       function on pin PIO2_13*/
#define IO_CFG_PIO2_14_F3EN   (0x01ul << 27)    /**< Enable/Disable Third                                                       function on pin PIO2_14*/
#define IO_CFG_PIO2_15_F3EN   (0x01ul << 31)    /**< Enable/Disable Third                                                       function on pin PIO2_15*/
                                                     
/*******************************************************************************
* MR10 : IO_CFG Mode Register
*******************************************************************************/
#define IO_CFG_PIO2_16_F3EN   (0x01ul << 3)     /**< Enable/Disable Third                                                       function on pin PIO2_16*/
#define IO_CFG_PIO2_17_F3EN   (0x01ul << 7)     /**< Enable/Disable Third                                                       function on pin PIO2_17*/
#define IO_CFG_PIO2_18_F3EN   (0x01ul << 11)    /**< Enable/Disable Third                                                       function on pin PIO2_18*/
#define IO_CFG_PIO2_19_F3EN   (0x01ul << 15)    /**< Enable/Disable Third                                                       function on pin PIO2_19*/
#define IO_CFG_PIO2_20_F3EN   (0x01ul << 19)    /**< Enable/Disable Third                                                       function on pin PIO2_20*/
#define IO_CFG_PIO2_21_F3EN   (0x01ul << 23)    /**< Enable/Disable Third                                                       function on pin PIO2_21*/
#define IO_CFG_PIO2_22_F3EN   (0x01ul << 27)    /**< Enable/Disable Third                                                       function on pin PIO2_22*/
#define IO_CFG_PIO2_23_F3EN   (0x01ul << 31)    /**< Enable/Disable Third                                                       function on pin PIO2_23*/

/*******************************************************************************
* MR11 : IO_CFG Mode Register
******************************************************************************/
 #define IO_CFG_PIO3_0_F3EN    (0x01ul << 3)     /**< Enable/Disable Third                                                       function on pin PIO3_0 */
 #define IO_CFG_PIO3_1_F3EN    (0x01ul << 7)     /**< Enable/Disable Third                                                       function on pin PIO3_1 */
 #define IO_CFG_PIO3_2_F3EN    (0x01ul << 11)    /**< Enable/Disable Third                                                       function on pin PIO3_2 */
 #define IO_CFG_PIO3_3_F3EN    (0x01ul << 15)    /**< Enable/Disable Third                                                       function on pin PIO3_3 */
 #define IO_CFG_PIO3_4_F3EN    (0x01ul << 19)    /**< Enable/Disable Third                                                       function on pin PIO3_4 */
 #define IO_CFG_PIO3_5_F3EN    (0x01ul << 23)    /**< Enable/Disable Third                                                       function on pin PIO3_5 */
 #define IO_CFG_PIO3_6_F3EN    (0x01ul << 27)    /**< Enable/Disable Third                                                       function on pin PIO3_6 */
 #define IO_CFG_PIO3_7_F3EN    (0x01ul << 31)    /**< Enable/Disable Third                                                       function on pin PIO3_7 */

/******************************************************************************
* MR12 : IO_CFG Mode Register
*******************************************************************************/
#define IO_CFG_PIO3_8_F3EN    (0x01ul << 3)     /**< Enable/Disable Third                                                       function on pin PIO3_8 */
#define IO_CFG_PIO3_9_F3EN    (0x01ul << 7)     /**< Enable/Disable Third                                                       function on pin PIO3_9 */
#define IO_CFG_PIO3_10_F3EN   (0x01ul << 11)    /**< Enable/Disable Third                                                       function on pin PIO3_10*/
#define IO_CFG_PIO3_11_F3EN   (0x01ul << 15)    /**< Enable/Disable Third                                                       function on pin PIO3_11*/
#define IO_CFG_PIO3_12_F3EN   (0x01ul << 19)    /**< Enable/Disable Third                                                       function on pin PIO3_12*/
#define IO_CFG_PIO3_13_F3EN   (0x01ul << 23)    /**< Enable/Disable Third                                                       function on pin PIO3_13*/
#define IO_CFG_PIO3_14_F3EN   (0x01ul << 27)    /**< Enable/Disable Third                                                       function on pin PIO3_14*/
#define IO_CFG_PIO3_15_F3EN   (0x01ul << 31)    /**< Enable/Disable Third                                                       function on pin PIO3_15*/
                                                     
/*******************************************************************************
* MR13 : IO_CFG Mode Register
*******************************************************************************/
#define IO_CFG_PIO3_16_PUENB  (0x01ul << 0)     /**< Enable/Disable Pull-Up                                                      on pin PIO3_16         */
#define IO_CFG_PIO3_16_DH     (0x01ul << 2)     /**< Drive Selection                                                       on pin PIO3_16         */
#define IO_CFG_PIO3_16_F3EN   (0x01ul << 3)     /**< Enable/Disable Third                                                       function on pin PIO3_16*/
#define IO_CFG_PIO3_17_PUENB  (0x01ul << 4)     /**< Enable/Disable Pull-Up                                                       on pin PIO3_17         */
#define IO_CFG_PIO3_17_DH     (0x01ul << 6)     /**< Drive Selection                                                       on pin PIO3_17         */
#define IO_CFG_PIO3_17_F3EN   (0x01ul << 7)     /**< Enable/Disable Third                                                       function on pin PIO3_17*/

#define IO_CFG_PIO3_18_PUENB  (0x01ul << 8)     /**< Enable/Disable Pull-Up                                                       on pin PIO3_18         */
#define IO_CFG_PIO3_18_DH     (0x01ul << 10)    /**< Drive Selection                                                       on pin PIO3_18         */
#define IO_CFG_PIO3_18_F3EN   (0x01ul << 11)    /**< Enable/Disable Third                                                      function on pin PIO3_18*/
#define IO_CFG_PIO3_19_PUENB  (0x01ul << 12)    /**< Enable/Disable Pull-Up                                                       on pin PIO3_19         */
#define IO_CFG_PIO3_19_DH     (0x01ul << 14)    /**< Drive Selection                                                      on pin PIO3_19         */
#define IO_CFG_PIO3_19_F3EN   (0x01ul << 15)    /**< Enable/Disable Third                                                       function on pin PIO3_19*/
#define IO_CFG_PIO3_20_PUENB  (0x01ul << 16)    /**< Enable/Disable Pull-Up                                                       on pin PIO3_20         */
#define IO_CFG_PIO3_20_DH     (0x01ul << 18)    /**< Drive Selection                                                       on pin PIO3_20         */
#define IO_CFG_PIO3_20_F3EN   (0x01ul << 19)    /**< Enable/Disable Third                                                       function on pin PIO3_20*/
#define IO_CFG_PIO3_21_PUENB  (0x01ul << 20)    /**< Enable/Disable Pull-Up*/
#define IO_CFG_PIO3_21_DH     (0x01ul << 22)    /**< Drive Selection                                                       on pin PIO3_21         */
#define IO_CFG_PIO3_21_F3EN   (0x01ul << 23)    /**< Enable/Disable Third                                                       function on pin PIO3_21*/

#define IO_CFG_PIO3_22_PUENB  (0x01ul << 24)    /**< Enable/Disable Pull-Up                                                      on pin PIO3_22         */
#define IO_CFG_PIO3_22_DH     (0x01ul << 26)    /**< Drive Selection                                                       on pin PIO3_22         */
#define IO_CFG_PIO3_22_F3EN   (0x01ul << 27)    /**< Enable/Disable Third                                                       function on pin PIO3_22*/

#define IO_CFG_PIO3_23_PUENB  (0x01ul << 28)    /**< Enable/Disable Pull-Up                                                       on pin PIO3_23         */
#define IO_CFG_PIO3_23_DH     (0x01ul << 30)    /**< Drive Selection                                                       on pin PIO3_23         */
#define IO_CFG_PIO3_23_F3EN   (0x01ul << 31)    /**< Enable/Disable Third                                                      function on pin PIO3_23*/

/*******************************************************************************
* MR14 : IO_CFG Mode Register
*******************************************************************************/
 #define IO_CFG_PIO3_24_PUENB  (0x01ul << 0)     /**< Enable/Disable Pull-Up                                                       on pin PIO3_24         */
 #define IO_CFG_PIO3_24_DH     (0x01ul << 2)     /**< Drive Selection                                                       on pin PIO3_24         */
 #define IO_CFG_PIO3_24_F3EN   (0x01ul << 3)     /**< Enable/Disable Third                                                       function on pin PIO3_24*/

 #define IO_CFG_PIO3_25_PUENB  (0x01ul << 4)     /**< Enable/Disable Pull-Up                                                       on pin PIO3_25         */
 #define IO_CFG_PIO3_25_DH     (0x01ul << 6)     /**< Drive Selection                                                       on pin PIO3_25         */
 #define IO_CFG_PIO3_25_F3EN   (0x01ul << 7)     /**< Enable/Disable Third                                                       function on pin PIO3_25*/

 #define IO_CFG_PIO3_26_PUENB  (0x01ul << 8)     /**< Enable/Disable Pull-Up                                                      on pin PIO3_26         */
 #define IO_CFG_PIO3_26_DH     (0x01ul << 10)    /**< Drive Selection                                                       on pin PIO3_26         */
 #define IO_CFG_PIO3_26_F3EN   (0x01ul << 11)    /**< Enable/Disable Third                                                       function on pin PIO3_26*/

 #define IO_CFG_PIO3_27_PUENB  (0x01ul << 12)    /**< Enable/Disable Pull-Up                                                       on pin PIO3_27         */
 #define IO_CFG_PIO3_27_DH     (0x01ul << 14)    /**< Drive Selection                                                       on pin PIO3_27         */
 #define IO_CFG_PIO3_27_F3EN   (0x01ul << 15)    /**< Enable/Disable Third                                                       function on pin PIO3_27*/

 #define IO_CFG_PIO3_28_PUENB  (0x01ul << 16)    /**< Enable/Disable Pull-Up                                                       on pin PIO3_28         */
 #define IO_CFG_PIO3_28_DH     (0x01ul << 18)    /**< Drive Selection                                                       on pin PIO3_28         */
 #define IO_CFG_PIO3_28_F3EN   (0x01ul << 19)    /**< Enable/Disable Third                                                       function on pin PIO3_28*/

 #define IO_CFG_PIO3_29_PUENB  (0x01ul << 20)    /**< Enable/Disable Pull-Up                                                       on pin PIO3_29         */
 #define IO_CFG_PIO3_29_DH     (0x01ul << 22)    /**< Drive Selection                                                       on pin PIO3_29         */
 #define IO_CFG_PIO3_29_F3EN   (0x01ul << 23)    /**< Enable/Disable Third                                                       function on pin PIO3_29*/

 #define IO_CFG_PIO3_30_PUENB  (0x01ul << 24)    /**< Enable/Disable Pull-Up                                                       on pin PIO3_30         */
 #define IO_CFG_PIO3_30_DH     (0x01ul << 26)    /**< Drive Selection                                                       on pin PIO3_30         */
 #define IO_CFG_PIO3_30_F3EN   (0x01ul << 27)    /**< Enable/Disable Third                                                       function on pin PIO3_30*/


 #define IO_CFG_PIO3_31_PUENB  (0x01ul << 28)    /**< Enable/Disable Pull-Up                                                       on pin PIO3_31         */
 #define IO_CFG_PIO3_31_DH     (0x01ul << 30)    /**< Drive Selection                                                       on pin PIO3_31         */
 #define IO_CFG_PIO3_31_F3EN   (0x01ul << 31)    /**< Enable/Disable Third                                                      function on pin PIO3_31*/

/******************************************************************************
* MR15 : IO_CFG Mode Register
******************************************************************************/
 #define IO_CFG_STOP_WU0_MASK  (0x1Ful << 0)     /**<  */
 #define IO_CFG_STOP_WU0(val)  ((0x1Ful & val) << 0)     /**< Writing macro  */
 #define IO_CFG_STOP_WU1_MASK  (0x1Ful << 8)     /**<  */
 #define IO_CFG_STOP_WU1(val)  ((0x1Ful & val) << 8)     /**< Writing macro  */
 #define IO_CFG_STOP_WU2_MASK  (0x1Ful << 16)    /**<  */
 #define IO_CFG_STOP_WU2(val)  ((0x1Ful & val) << 16)    /**< Writing macro  */
 #define IO_CFG_STOP_WU3_MASK  (0x1Ful << 24)    /**<  */
 #define IO_CFG_STOP_WU3(val)  ((0x1Ful & val) << 24)    /**< Writing macro  */

/******************************************************************************
* MR16 : IO_CFG Mode Register
******************************************************************************/
 #define IO_CFG_LVD_RST_EN     (0x01ul << 0)     /**< Low Voltage Detector                                                       reset                  */
 #define IO_CFG_LVD_INT_EN     (0x01ul << 1)     /**< Low Voltage Detector                                                    interrupt              */
/******************************************************************************
***************************** IOCONG Registers mask ***************************
******************************************************************************/
 #define IO_CFG_MR0_MASK       (0x11119911ul)    /**< MR0 mask               */
 #define IO_CFG_MR1_MASK       (0x99999999ul)    /**< MR1 mask               */
 #define IO_CFG_MR2_MASK       (0x09999999ul)    /**< MR2 mask               */
 #define IO_CFG_MR3_MASK       (0x11999999ul)    /**< MR3 mask               */
 #define IO_CFG_MR4_MASK       (0x00009911ul)    /**< MR4 mask               */
 #define IO_CFG_MR5_MASK       (0x88888888ul)    /**< MR5 mask               */
 #define IO_CFG_MR6_MASK       (0x88888888ul)    /**< MR6 mask               */
 #define IO_CFG_MR7_MASK       (0x00008888ul)    /**< MR7 mask               */
 #define IO_CFG_MR8_MASK       (0x88888888ul)    /**< MR8 mask               */   
 #define IO_CFG_MR9_MASK       (0x88888888ul)    /**< MR9 mask               */
 #define IO_CFG_MR10_MASK      (0x88888888ul)    /**< MR10 mask              */
 #define IO_CFG_MR11_MASK      (0x88888888ul)    /**< MR11 mask              */
 #define IO_CFG_MR12_MASK      (0x88888888ul)    /**< MR12 mask              */
 #define IO_CFG_MR13_MASK      (0xFFFFFFFFul)    /**< MR13 mask              */
 #define IO_CFG_MR14_MASK      (0xFFFFFFFFul)    /**< MR14 mask              */
 #define IO_CFG_MR15_MASK      (0x1F1F1F1Ful)    /**< MR15 mask              */
 #define IO_CFG_MR16_MASK      (0x00000003ul)    /**< MR16 mask              */  


/******************************************************************************
************************* IOCONG Registers reset value ************************
******************************************************************************/
 #define IO_CFG_MR0_RST        (0x11110000ul)    /**< MR0 reset value        */
 #define IO_CFG_MR1_RST        (0x11111111ul)    /**< MR1 reset value        */
 #define IO_CFG_MR2_RST        (0x01111111ul)    /**< MR2 reset value        */
 #define IO_CFG_MR3_RST        (0x11110011ul)    /**< MR3 reset value        */
 #define IO_CFG_MR4_RST        (0x00001111ul)    /**< MR4 reset value        */
 #define IO_CFG_MR5_RST        (0x00000000ul)    /**< MR5 reset value        */
 #define IO_CFG_MR6_RST        (0x00000000ul)    /**< MR6 reset value        */
 #define IO_CFG_MR7_RST        (0x00000000ul)    /**< MR7 reset value        */
 #define IO_CFG_MR8_RST        (0x00000000ul)    /**< MR8 reset value        */   
 #define IO_CFG_MR9_RST        (0x00000000ul)    /**< MR9 reset value        */
 #define IO_CFG_MR10_RST       (0x00000000ul)    /**< MR10 reset value       */
 #define IO_CFG_MR11_RST       (0x00000000ul)    /**< MR11 reset value       */
 #define IO_CFG_MR12_RST       (0x00000000ul)    /**< MR12 reset value       */
 #define IO_CFG_MR13_RST       (0x11111111ul)    /**< MR13 reset value       */
 #define IO_CFG_MR14_RST       (0x11111111ul)    /**< MR14 reset value       */
 #define IO_CFG_MR15_RST       (0x00000000ul)    /**< MR15 reset value       */
 #define IO_CFG_MR16_RST       (0x00000000ul)    /**< MR16 reset value       */  





/******************************************************************************
* IO CONF Register Definition
******************************************************************************/
/* MR0 : IO CONF Mode Register                                                */
/** Get MR0 register (Mode Register)                                          */
 #define CSP_IO_CFG_GET_MR0(io_cfg)            ((io_cfg)->MR0)
/** Set MR0 register (Mode Register)                                          */
 #define CSP_IO_CFG_SET_MR0(io_cfg, mode)      ((io_cfg)->MR0 = (mode))

/* MR1 : IO CONF Mode Register                                                */
/** Get MR1 register (Mode Register)                                          */
 #define CSP_IO_CFG_GET_MR1(io_cfg)            ((io_cfg)->MR1)
/** Set MR1 register (Mode Register)                                          */
 #define CSP_IO_CFG_SET_MR1(io_cfg, mode)      ((io_cfg)->MR1 = (mode))

/* MR2 : IO CONF Mode Register                                                */
/** Get MR2 register (Mode Register)                                          */
 #define CSP_IO_CFG_GET_MR2(io_cfg)            ((io_cfg)->MR2)
/** Set MR2 register (Mode Register)                                          */
 #define CSP_IO_CFG_SET_MR2(io_cfg, mode)      ((io_cfg)->MR2 = (mode))

/* MR3 : IO CONF Mode Register                                                */
/** Get MR3 register (Mode Register)                                          */
 #define CSP_IO_CFG_GET_MR3(io_cfg)            ((io_cfg)->MR3)
/** Set MR3 register (Mode Register)                                          */
 #define CSP_IO_CFG_SET_MR3(io_cfg, mode)      ((io_cfg)->MR3 = (mode))

/* MR4 : IO CONF Mode Register                                                */
/** Get MR4 register (Mode Register)                                          */
 #define CSP_IO_CFG_GET_MR4(io_cfg)            ((io_cfg)->MR4)
/** Set MR4 register (Mode Register)                                          */
 #define CSP_IO_CFG_SET_MR4(io_cfg, mode)      ((io_cfg)->MR4 = (mode))

/* MR5 : IO CONF Mode Register                                                */
/** Get MR5 register (Mode Register)                                          */
 #define CSP_IO_CFG_GET_MR5(io_cfg)            ((io_cfg)->MR5)
/** Set MR5 register (Mode Register)                                          */
 #define CSP_IO_CFG_SET_MR5(io_cfg, mode)      ((io_cfg)->MR5 = (mode))

/* MR6 : IO CONF Mode Register                                                */
/** Get MR6 register (Mode Register)                                          */
 #define CSP_IO_CFG_GET_MR6(io_cfg)            ((io_cfg)->MR6)
/** Set MR6 register (Mode Register)                                          */
 #define CSP_IO_CFG_SET_MR6(io_cfg, mode)      ((io_cfg)->MR6 = (mode))

/* MR7 : IO CONF Mode Register                                                */
/** Get MR7 register (Mode Register)                                          */
 #define CSP_IO_CFG_GET_MR7(io_cfg)            ((io_cfg)->MR7)
/** Set MR7 register (Mode Register)                                          */
 #define CSP_IO_CFG_SET_MR7(io_cfg, mode)      ((io_cfg)->MR7 = (mode))

/* MR8 : IO CONF Mode Register                                                */
/** Get MR8 register (Mode Register)                                          */
 #define CSP_IO_CFG_GET_MR8(io_cfg)            ((io_cfg)->MR8)
/** Set MR8 register (Mode Register)                                          */
 #define CSP_IO_CFG_SET_MR8(io_cfg, mode)      ((io_cfg)->MR8 = (mode))

/* MR9 : IO CONF Mode Register                                                */
/** Get MR9 register (Mode Register)                                          */
 #define CSP_IO_CFG_GET_MR9(io_cfg)            ((io_cfg)->MR9)
/** Set MR9 register (Mode Register)                                          */
 #define CSP_IO_CFG_SET_MR9(io_cfg, mode)      ((io_cfg)->MR9 = (mode))

/* MR10 : IO CONF Mode Register                                               */
/** Get MR10 register (Mode Register)                                         */
 #define CSP_IO_CFG_GET_MR10(io_cfg)            ((io_cfg)->MR10)
/** Set MR10 register (Mode Register)                                         */
 #define CSP_IO_CFG_SET_MR10(io_cfg, mode)      ((io_cfg)->MR10 = (mode))

/* MR11 : IO CONF Mode Register                                               */
/** Get MR11 register (Mode Register)                                         */
 #define CSP_IO_CFG_GET_MR11(io_cfg)            ((io_cfg)->MR11)
/** Set MR11 register (Mode Register)                                         */
 #define CSP_IO_CFG_SET_MR11(io_cfg, mode)      ((io_cfg)->MR11 = (mode))

/* MR12 : IO CONF Mode Register                                               */
/** Get MR12 register (Mode Register)                                         */
 #define CSP_IO_CFG_GET_MR12(io_cfg)            ((io_cfg)->MR12)
/** Set MR12 register (Mode Register)                                         */
 #define CSP_IO_CFG_SET_MR12(io_cfg, mode)      ((io_cfg)->MR12 = (mode))

/* MR13 : IO CONF Mode Register                                               */
/** Get MR13 register (Mode Register)                                         */
 #define CSP_IO_CFG_GET_MR13(io_cfg)            ((io_cfg)->MR13)
/** Set MR13 register (Mode Register)                                         */
 #define CSP_IO_CFG_SET_MR13(io_cfg, mode)      ((io_cfg)->MR13 = (mode))

/* MR14 : IO CONF Mode Register                                               */
/** Get MR14 register (Mode Register)                                         */
 #define CSP_IO_CFG_GET_MR14(io_cfg)            ((io_cfg)->MR14)
/** Set MR14 register (Mode Register)                                         */
 #define CSP_IO_CFG_SET_MR14(io_cfg, mode)      ((io_cfg)->MR14 = (mode))

/* MR15 : IO CONF Mode Register                                               */
/** Get MR15 register (Mode Register)                                         */
 #define CSP_IO_CFG_GET_MR15(io_cfg)            ((io_cfg)->MR15)
/** Set MR15 register (Mode Register)                                         */
 #define CSP_IO_CFG_SET_MR15(io_cfg, mode)      ((io_cfg)->MR15 = (mode))

/* MR16 : IO CONF Mode Register                                               */
/** Get MR16 register (Mode Register)                                         */
 #define CSP_IO_CFG_GET_MR16(io_cfg)            ((io_cfg)->MR16)
/** Set MR16 register (Mode Register)                                         */
 #define CSP_IO_CFG_SET_MR16(io_cfg, mode)      ((io_cfg)->MR16 = (mode))

/******************************************************************************
********************* PIO BLOCK External Functions Declaration ****************
******************************************************************************/
extern CSP_REGISTER_T CSP_PIOGetBlockMask(CSP_PIO_T *const pio);
extern U8_T CSP_PIOGetBlockNumber(CSP_PIO_T *const pio);

#endif   /** CSP_IOCFG_H */

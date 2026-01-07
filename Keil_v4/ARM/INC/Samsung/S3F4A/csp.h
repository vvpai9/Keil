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
* @file name	csp.h
* @description	Structure for S3F4A0K Chip.
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
*		S3F4A0K AGP1
*/ 

#ifndef _CSP_H
#define _CSP_H

/*******************************************************************************
*********************  C H I P  D E C L A R A T I O N  *************************
*******************************************************************************/

/** Number of Peripherals                                                    */
#define PERIPH_NUMBER		35ul

/** Number of system peripheral                                              */
#define SYSIRQ_NUMBER		6u

/** Number of external interrupts                                            */
#define EXTIRQ_NUMBER		20u

/** Number of Software Interrupts                                            */
#define SWIRQ_NUMBER		6u

/** Number of LDMA Channels (used in csp_ldma.h)                             */
#define NB_LDMA_CHANNEL		8u

/** Number of Channel Interrupt                                              */
#define NB_INT_CHANNEL		3u

/** Number of PWM Channels                                                   */
#define NB_PWM_CHANNEL		2u

/*******************************************************************************
***************************  I N C L U D E S  **********************************
*******************************************************************************/
/**< Include AGP1 IPIDCODES  only if */ 
/**<ipname>_IPIDCODE_TAG are defined */
#include "csp_ipidcodes.h"           
                                      
#include "csp_types.h"
#include "csp_adc10.h"
#include "csp_capt.h"
#include "csp_cm.h"
#include "csp_can.h"
#include "csp_dfc.h"
#include "csp_epc.h"
#include "csp_pio.h"
#include "csp_gpt.h"
#include "csp_gic.h"
#include "csp_io_cfg.h"
#include "csp_i2c.h"
#include "csp_ifc.h"
#include "csp_irc.h"
#include "csp_lcdc.h"
#include "csp_ldma.h"
#include "csp_pwm.h"
#include "csp_spi.h"
#include "csp_st16.h"
#include "csp_sfm.h"
#include "csp_stt.h"
#include "csp_smc.h"
#include "csp_usart.h"
#include "csp_wd.h"

/*******************************************************************************
*******************   PERIPHERAL BASE ADDRESSES   ******************************
*******************************************************************************/
#define	PERIPH_SIZE 				0x4000ul     /**< Peripheral size           */
#define PSEL0_BASE_ADDRESS      	0xFFE00000ul /**< PSEL0 base address        */
#define PSEL_SYS_BASE_ADDRESS   	0xFFFE0000ul /**< System Peripheral baseaddr*/                    
#define DFC0_BASE_ADDRESS      		0xFFE00000ul /**< DFC0 base address         */
#define IFC0_BASE_ADDRESS       	0xFFE04000ul /**< IFC0 base address         */
#define PWM0_BASE_ADDRESS       	0xFFE08000ul /**< PWM0 base address         */
#define ADC0_BASE_ADDRESS       	0xFFE0C000ul /**< ADC0 base address         */
#define SPI0_BASE_ADDRESS       	0xFFE10000ul /**< SPI0 base address         */
#define WD0_BASE_ADDRESS        	0xFFE14000ul /**< WD0 base address          */
#define CAN0_BASE_ADDRESS       	0xFFE18000ul /**< CAN0 base address         */
#define GPT0_BASE_ADDRESS       	0xFFE1C000ul /**< GPT0 base address         */
#define GPT0CH0_BASE_ADDRESS    	0xFFE1C000ul /**< GPT channel 0 base address*/
#define GPT0CH1_BASE_ADDRESS    	0xFFE1C100ul /**< GPT channel 1 base address*/
#define GPT0CH2_BASE_ADDRESS    	0xFFE1C200ul /**< GPT channel 2 base address*/
#define ST0_BASE_ADDRESS        	0xFFE20000ul /**< ST0 base address          */
#define ST1_BASE_ADDRESS        	0xFFE24000ul /**< ST1 base address          */
#define UART0_BASE_ADDRESS      	0xFFE28000ul /**< UART0 base address        */
#define IOCFG0_BASE_ADDRESS     	0xFFE2C000ul /**< IO_CFG0 base address      */
#define STT0_BASE_ADDRESS       	0xFFE30000ul /**< STT0                      */
#define UART1_BASE_ADDRESS      	0xFFE34000ul /**< UART1 base address        */
#define USART0_BASE_ADDRESS     	0xFFE38000ul /**< USART0 base address       */
#define CAN1_BASE_ADDRESS       	0xFFE3C000ul /**< CAN1 base address         */
#define CAN2_BASE_ADDRESS       	0xFFE40000ul /**< CAN2 base address         */
#define CAN3_BASE_ADDRESS       	0xFFE44000ul /**< CAN3 base address         */
#define CAPT0_BASE_ADDRESS      	0xFFE48000ul /**< CAPT0 base address        */
#define CAPT1_BASE_ADDRESS      	0xFFE4C000ul /**< CAPT1 base address        */
#define I2C0_BASE_ADDRESS       	0xFFE50000ul /**< I2C0 base address         */
#define I2C1_BASE_ADDRESS       	0xFFE54000ul /**< I2C1 base address         */
#define LCDC0_BASE_ADDRESS      	0xFFE58000ul /**< LCDC0 base address        */
#define ST2_BASE_ADDRESS        	0xFFE5C000ul /**< ST2 base address          */
#define SPI1_BASE_ADDRESS       	0xFFE60000ul /**< SPI1 base address         */
#define PIO0_BASE_ADDRESS       	0xFFE64000ul /**< PIO0 base address         */
#define PIO1_BASE_ADDRESS       	0xFFE68000ul /**< PIO1 base address         */
#define PIO2_BASE_ADDRESS       	0xFFE6C000ul /**< PIO2 base address         */
#define PIO3_BASE_ADDRESS       	0xFFE70000ul /**< PIO3 base address         */
#define SMC0_BASE_ADDRESS       	0xFFE74000ul /**< SMC0 base address         */
#define SMC1_BASE_ADDRESS       	0xFFE78000ul /**< SMC1 base address         */
#define SMC2_BASE_ADDRESS       	0xFFE7C000ul /**< SMC2 base address         */
#define SMC3_BASE_ADDRESS       	0xFFE80000ul /**< SMC3 base address         */
#define SMC4_BASE_ADDRESS       	0xFFE84000ul /**< SMC4 base address         */
#define SMC5_BASE_ADDRESS       	0xFFE88000ul /**< SMC5 base address         */
#define EPC0_BASE_ADDRESS       	0xFFFE0000ul /**< EPC0 base address         */
#define SFM0_BASE_ADDRESS       	0xFFFE4000ul /**< SFM0 base address         */
#define CM0_BASE_ADDRESS        	0xFFFE8000ul /**< CM0 base address          */
#define IRC_BASE_ADDRESS        	0xFFFF0000ul /**< IRC base address          */
#define LDMA_BASE_ADDRESS       	0xFFFF8000ul /**< LDMA base address         */
#define GIC_BASE_ADDRESS        	0xFFFFE000ul /**< GIC base address          */

/*******************************************************************************
**********************   PERIPHERAL TYPE DEFINITION   **************************
*******************************************************************************/

/*******************************************************************************
*************************   PERIPHERAL TYPE ENUM   *****************************
*******************************************************************************/
typedef enum  
{
	UNUSED_PERIPHERAL_TYPE_E = -1,
	WATCHDOG_E,
	ST16_E,
	CAN32C_E,
	PWM_E, 
    ADC16C_10_E,
    IFC_E,
    SPI_E, 
    GPT3C_E, 
    USART_E,
    CAPTURE_E,
    STT_E,
    I2C_E, 
    LCDC_E,
    PIO_E, 
    SMC_E, 
    IOCONF_E,
    DFC_E
}CSP_PERIPHERAL_TYPE_E;

/*******************************************************************************
**********************  SYSTEM PERIPHERAL TYPE ENUM   **************************
*******************************************************************************/
typedef enum  
{
	UNUSED_SYS_PERIPH_TYPE_E = -1,
	CM_E, 
	EPC_E,
	SFM_E,
	IRC_E,
	LDMAC_E
}CSP_SYS_PERIPH_TYPE_E;

/*******************************************************************************
************************   PERIPHERAL TYPE STRUCTURE   *************************
*******************************************************************************/
typedef struct 
{ 
	CSP_PERIPHERAL_TYPE_E  Type;               		/* Type Of Peripheral    */
   	U8_T     InterruptNumber[NB_INT_CHANNEL];		/* Interruption Number   */
   	U8_T     LdmaRx;                            	/* LDMA Channel Rx       */
   	U8_T     LdmaTx;                            	/* LDMA Channel Tx       */
}PERIPHERAL_TYPE_T; 

/*******************************************************************************
*********************   SYSTEM PERIPHERAL TYPE STRUCTURE   *********************
*******************************************************************************/
typedef struct 
{ 
	CSP_SYS_PERIPH_TYPE_E	Type;          		/* Type Of System Peripheral */
   	U8_T	InterruptNumber[NB_INT_CHANNEL];	/* Interruption Number       */
   	U8_T    LdmaRx;                           	/* LDMA Channel Rx           */
   	U8_T    LdmaTx;                            /* LDMA Channel Tx           */
}SYS_PERIPH_TYPE_T; 

/*******************************************************************************
*************************   INTERRUPT TYPE ENUM   ******************************
*******************************************************************************/
typedef enum  
{
	UNUSED_IRQ_TYPE_E = -1,
	SWIRQ1_E,
	SWIRQ2_E,
	SWIRQ3_E,	
	SWIRQ4_E,
	SWIRQ5_E,
	SWIRQ6_E,
   	IRQ0_E,
   	IRQ1_E,
   	IRQ2_E,
   	IRQ3_E,
   	IRQ4_E,
   	IRQ5_E,
	IRQ6_E,
	IRQ7_E,
	IRQ8_E,
	IRQ9_E,
	IRQ10_E,
	IRQ11_E,
	IRQ12_E, 
	IRQ13_E,
	IRQ14_E,
	IRQ15_E,
	IRQ16_E,
	IRQ17_E,
	IRQ18_E,
	IRQ19_E
} CSP_IRQ_TYPE_E;

/*******************************************************************************
*****************   EXTERNAL INTERRUPT TYPE STRUCTRE   *************************
*******************************************************************************/
typedef struct 
{ 
	CSP_IRQ_TYPE_E		Type;              		/* Type Of external Interrupt*/
   	U8_T                InterruptNumber;     	/* Interrupt Number          */
}EXTIRQ_TYPE_T; 

/*******************************************************************************
******************  SOFTWARE INTERRUPT TYPE STRUCTURE  *************************
*******************************************************************************/
typedef struct 
{ 
	CSP_IRQ_TYPE_E		Type;              		/* Type Of Software Interrupt*/
   	U8_T                InterruptNumber;     	/* Interrupt Number          */
}SWIRQ_TYPE_T; 

/*******************************************************************************
*********************   PIO BLOCK TYPE STRUCTURE   *****************************
*******************************************************************************/
typedef struct 
{ 
	CSP_PIO_PTR			Pio_Block_Base_Address;		/* Pio_Block_Base_Address*/
   	CSP_REGISTER_T    	Pio_Block_Mask;				/* Pio_Block_Mask        */
}PIO_BLOCK_TYPE_T; 

/*******************************************************************************
********************   PERIPHERALS MACROS DEFINITION   *************************
*******************************************************************************/

/** Get Peripheral Psel Number (See CHIP Tab in .C file)                      */
#define CSP_GET_PSEL_NUMBER(periph)											  \
							(((U32_T)periph - PSEL0_BASE_ADDRESS) / PERIPH_SIZE) 

/** Get Peripheral Interrupt Number from given peripheral channnel            */ 
/* (See CHIP Tab in .C file) */
#define CSP_GET_INT_NUMBER_CHANNEL(periph,channel)                            \
			(CHIP[CSP_GET_PSEL_NUMBER(periph)].InterruptNumber[channel])

/** Get Peripheral Interrupt Number (See CHIP Tab in .C file)                 */ 
#define CSP_GET_INT_NUMBER(periph)	(CSP_GET_INT_NUMBER_CHANNEL(periph,0))

/** Get Peripheral LDMA RX Number (See CHIP Tab in .C file)                   */
#define CSP_GET_LDMA_RX_NUMBER(periph)                                         \
           						(CHIP[CSP_GET_PSEL_NUMBER(periph)].LdmaRx)           						
#define CSP_GET_LDMA_TX_NUMBER(periph)                                         \
                        		(CHIP[CSP_GET_PSEL_NUMBER(periph)].LdmaTx)

/** Get Peripheral Type (See CHIP Tab in .C file)                             */
#define CSP_GET_PERIPHERAL_TYPE(periph)                                       \
            					(CHIP[CSP_GET_PSEL_NUMBER(periph)].Type)

/*******************************************************************************
****************  SYSTEM PERIPHERAL MACROS DEFINITION   ************************
*******************************************************************************/

/** Get Peripheral Psel Number (See CHIP Tab in .C file)                      */
#define CSP_GET_SYS_PSEL_NUMBER(periph)                                       \
            		(((U32_T)periph - PSEL_SYS_BASE_ADDRESS) / PERIPH_SIZE) 

/** Get Peripheral Interrupt Number from given peripheral channnel            */ 
/* (See CHIP Tab in .C file) */
#define CSP_GET_SYS_INT_NUMBER_CHANNEL(periph,channel)                        \
		(SYSIRQ[CSP_GET_SYS_PSEL_NUMBER(periph)].InterruptNumber[channel])

/** Get Peripheral Interrupt Number (See CHIP Tab in .C file)                 */ 
#define CSP_GET_SYS_INT_NUMBER(periph)                                        \
             					(CSP_GET_SYS_INT_NUMBER_CHANNEL(periph,0))

/** Get Peripheral LDMA RX Number (See CHIP Tab in .C file)                   */
#define CSP_GET_SYS_LDMAC_RX_NUMBER(periph)                                   \
             			(SYSIRQ[CSP_GET_SYS_PSEL_NUMBER(periph)].LdmaRx)
#define CSP_GET_SYS_LDMAC_TX_NUMBER(periph)                                   \
             			(SYSIRQ[CSP_GET_SYS_PSEL_NUMBER(periph)].LdmaTx)

/** Get Peripheral Type (See CHIP Tab in .C file)                             */
#define CSP_GET_SYS_PERIPHERAL_TYPE(periph)                                   \
             			(SYSIRQ[CSP_GET_SYS_PSEL_NUMBER(periph)].Type)


/*******************************************************************************
****************  EXTERNAL INTERRUPT MACROS DEFINITION  ************************
*******************************************************************************/

/** Get External IRQ Interrupt Number (See EXTIRQ Tab in .C file)             */ 
#define CSP_GET_EXTIRQ_INTERRUPT_NUMBER(extirq)                               \
            								(EXTIRQ[extirq].InterruptNumber)

/** Get External IRQ  Type (See EXTIRQ Tab in .C file)                        */
#define CSP_GET_EXTIRQ_TYPE(extirq)			(EXTIRQ[extirq].Type)

/*******************************************************************************
****************   SOFTWARE INTERRUPT MACROS DEFINITION  ***********************
*******************************************************************************/

/** Get Software IRQ Interrupt Number (See SWIRQ Tab in .C file)              */ 
#define CSP_GET_SWIRQ_INTERRUPT_NUMBER(swirq)  							      \
											(SWIRQ[swirq].InterruptNumber)

/** Get Software IRQ  Type (See SWIRQ Tab in .C file)                         */
#define CSP_GET_SWIRQ_TYPE(swirq)			(SWIRQ[swirq].Type)


/*******************************************************************************
*******************   EXTERNAL PERIPHERAL DECLARATION   ************************
*******************************************************************************/
/** Peripherals                                                               */
extern CSP_LDMA_T		*const LDMA0;
extern CSP_IRC_T      	*const IRC;
extern CSP_GIC_T      	*const GIC;
extern CSP_DFC_T      	*const DFC0;
extern CSP_IFC_T      	*const IFC0;
extern CSP_PWM_T      	*const PWM0;
extern CSP_ADC10_T    	*const ADC0;
extern CSP_SPI_T      	*const SPI0;
extern CSP_WD_T       	*const WD0;
extern CSP_CAN_T      	*const CAN0;
extern CSP_GPT3C_T    	*const GPT0;
extern CSP_GPT_T      	*const GPT0CH0;
extern CSP_GPT_T      	*const GPT0CH1;
extern CSP_GPT_T      	*const GPT0CH2;
extern CSP_ST16_T     	*const ST0;
extern CSP_ST16_T     	*const ST1;
extern CSP_USART_T    	*const UART0;
extern CSP_IO_CFG_T		*const IO_CFG0;
extern CSP_STT_T      	*const STT0;
extern CSP_USART_T    	*const UART1;
extern CSP_USART_T    	*const USART0;
extern CSP_CAN_T      	*const CAN1;
extern CSP_CAN_T      	*const CAN2;
extern CSP_CAN_T      	*const CAN3;
extern CSP_CAPT_T     	*const CAPT0;
extern CSP_CAPT_T     	*const CAPT1;
extern CSP_I2C_T      	*const I2C0;
extern CSP_I2C_T      	*const I2C1;
extern CSP_LCDC_T     	*const LCDC0;
extern CSP_ST16_T     	*const ST2;
extern CSP_SPI_T      	*const SPI1;
extern CSP_PIO_T      	*const PIO0;
extern CSP_PIO_T      	*const PIO1;
extern CSP_PIO_T      	*const PIO2;
extern CSP_PIO_T      	*const PIO3;
extern CSP_SMC_T      	*const SMC0;
extern CSP_SMC_T      	*const SMC1;
extern CSP_SMC_T      	*const SMC2;
extern CSP_SMC_T      	*const SMC3;
extern CSP_SMC_T      	*const SMC4;
extern CSP_SMC_T      	*const SMC5;
extern CSP_EPC_T      	*const EPC0;
extern CSP_SFM_T      	*const SFM0;
extern CSP_CM_T       	*const CM0;

/** Ghost Peripherals                                                         */
extern CSP_GIC_T      	*const GIC_GHOST;
extern CSP_PWM_T      	*const PWM0_GHOST;
extern CSP_ADC10_T   	*const ADC0_GHOST;
extern CSP_SPI_T      	*const SPI0_GHOST;
extern CSP_GPT3C_T    	*const GPT0_GHOST;
extern CSP_GPT_T      	*const GPT0CH0_GHOST;
extern CSP_GPT_T      	*const GPT0CH1_GHOST;
extern CSP_GPT_T      	*const GPT0CH2_GHOST;
extern CSP_USART_T    	*const UART0_GHOST;
extern CSP_STT_T      	*const STT0_GHOST;
extern CSP_USART_T    	*const UART1_GHOST;
extern CSP_USART_T    	*const USART0_GHOST;
extern CSP_CAPT_T     	*const CAPT0_GHOST;
extern CSP_CAPT_T     	*const CAPT1_GHOST;
extern CSP_SPI_T      	*const SPI1_GHOST;


/** Chip                                                                      */
extern const PERIPHERAL_TYPE_T	CHIP[PERIPH_NUMBER+1];

/** System Peripheral                                                         */
extern const SYS_PERIPH_TYPE_T	SYSIRQ[SYSIRQ_NUMBER+1];

/** External Interrupt                                                        */
extern const EXTIRQ_TYPE_T		EXTIRQ[EXTIRQ_NUMBER+1];

/** Software Interrupt                                                        */
extern const SWIRQ_TYPE_T		SWIRQ[SWIRQ_NUMBER+1];

/** Pio block mask description                                                */
extern const PIO_BLOCK_TYPE_T	PIO_BLOCK_MASK[PIO_BLOCK_NUMBER+1];

#endif	/* _CSP_H */

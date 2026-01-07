/*******************************************************************************
 * (c) Copyright 2009 Actel Corporation.  All rights reserved.
 * 
 *  SmartFusion A2FM3Fxx CMSIS system initialization.
 *
 * SVN $Revision: 1197 $
 * SVN $Date: 2009-07-30 16:14:22 +0100 (Thu, 30 Jul 2009) $
 */

#ifndef __SYSTEM_A2FM3FXXX_H__
#define __SYSTEM_A2FM3FXXX_H__

#ifdef __cplusplus
 extern "C" {
#endif 

/* Standard CMSIS global variables. */
extern uint32_t SystemFrequency;    /*!< System Clock Frequency (Core Clock) */

/* SmartFusion specific clocks. */
extern uint32_t g_FrequencyPCLK0;   /*!< Clock frequency of APB bus 0. */  
extern uint32_t g_FrequencyPCLK1;   /*!< Clock frequency of APB bus 1. */
extern uint32_t g_FrequencyACE;     /*!< Clock frequency of Analog Compute Engine. */

/***************************************************************************//**
 * The SystemInit() is a standard CMSIS function that should be called by the
 * application at system init time before configuring peripherals.
 * It is meant to perform low level hardware setup such as configuring PLLs. In
 * the case of SmartFusion these hardware setup operations are performed by the
 * chip boot which executed before the application started. Therefore this
 * function does not need to perform any hardware setup.
 */
extern void SystemInit (void);

#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_A2FM3FXXX_H__ */

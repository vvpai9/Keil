/*******************************************************************************
 * (c) Copyright 2009 Actel Corporation.  All rights reserved.
 * 
 *  SmartFusion A2FM3Fxx CMSIS system initialization.
 *
 * SVN $Revision: 1197 $
 * SVN $Date: 2009-07-30 16:14:22 +0100 (Thu, 30 Jul 2009) $
 */
#include <a2fm3fxxx.h>

/* System frequency (FCLK) coming out of reset is 100MHz. */
#define RESET_SYSCLCK_FREQ      100000000

/*
 * MSS FLCK frequency.
 * SMARTFUSION_FCLK_FREQ should be defined in the projects settings to reflect
 * the FCLK frequency selected in the Libero MSS configurator.
 * This should eventually be read from eNVM where the MSS clock configurator will
 * store the selected value. 
 */
#ifndef SMARTFUSION_FCLK_FREQ
#define SMARTFUSION_FCLK_FREQ	RESET_SYSCLCK_FREQ
#endif

/* Divider values for APB0, APB1 and ACE clocks. */
#define RESET_PCLK0_DIV         4
#define RESET_PCLK1_DIV         4
#define RESET_ACE_DIV           4

/* System register clcok control mask and shift for PCLK dividers. */
#define PCLK_DIV_MASK		0x00000003
#define PCLK0_DIV_SHIFT		2
#define PCLK1_DIV_SHIFT		4

/* Standard CMSIS global variables. */
uint32_t SystemFrequency = SMARTFUSION_FCLK_FREQ;          /*!< System Clock Frequency (Core Clock) */

/* SmartFusion specific clocks. */
uint32_t g_FrequencyPCLK0 = (SMARTFUSION_FCLK_FREQ / RESET_PCLK0_DIV);     /*!< Clock frequency of APB bus 0. */  
uint32_t g_FrequencyPCLK1 = (SMARTFUSION_FCLK_FREQ / RESET_PCLK1_DIV);     /*!< Clock frequency of APB bus 1. */
uint32_t g_FrequencyACE = (SMARTFUSION_FCLK_FREQ / RESET_ACE_DIV);     /*!< Clock frequency of Analog Compute Engine. */

/***************************************************************************//**
 * See system_a2fm3fxxx.h for details.
 */
void SystemInit(void)
{
    uint32_t PclkDiv0;
    uint32_t PclkDiv1;

    const uint32_t pclk_div_lut[4] = { 1, 2, 4, 1 };

    /* Read PCLK dividers from system registers. Multiply the value read from
     * system register by two to get actual divider value. */
    PclkDiv0 = pclk_div_lut[((SYSREG->CLK_CTRL >> PCLK0_DIV_SHIFT) & PCLK_DIV_MASK)];
    PclkDiv1 = pclk_div_lut[((SYSREG->CLK_CTRL >> PCLK1_DIV_SHIFT) & PCLK_DIV_MASK)];
    
    /* Should eventually read system clock from eNVM spare pages. */
    SystemFrequency = SMARTFUSION_FCLK_FREQ;
    g_FrequencyPCLK0 = SystemFrequency / PclkDiv0;
    g_FrequencyPCLK1 = SystemFrequency / PclkDiv1;
}

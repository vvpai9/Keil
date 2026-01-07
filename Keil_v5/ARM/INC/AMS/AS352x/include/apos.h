/*
 * Copyright: 
 * ----------------------------------------------------------------
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from ARM Limited
 *   (C) COPYRIGHT 2000,2001 ARM Limited
 *       ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from ARM Limited.
 * ----------------------------------------------------------------
 * File:     apos.h,v
 * Revision: 1.73
 * ----------------------------------------------------------------
 * 
 *  ----------------------------------------
 *  Version and Release Control Information:
 * 
 *  File Name              : apos.h.rca
 *  File Revision          : 1.3
 * 
 *  Release Information    : PrimeCell(TM)-GLOBAL-REL7v0
 *  ----------------------------------------
 *
 * This file contains the definitions for functions which will require specific
 * implementations according to OS used.  The functions themselves are implemented
 * in file os.c.
 * This file will not normally need modification
 */


#ifndef APOS_H
#define APOS_H

#ifdef    __cplusplus
extern "C" {    /* allow C++ to use these headers */
#endif    /* __cplusplus */

#include "aptypes.h"
#include "cmacros.h"
#include "sdk_interrupts.h"
#include "sdk_platform.h"

/*
 * Description:
 * Macro to generate a warning for the 'object' code release
 * ***USED INTERNALLY ONLY***
 */
#ifdef apREL_OBJ
    #include "aptest.h"
    #include <stdio.h>
    #define apREL_OBJ_WARN {printf("\n**DEMO CODE - NOT FOR DISTRIBUTION**\n");apOS_TIMER_Wait(100000);}
#else
    #define apREL_OBJ_WARN
#endif

#ifndef IRQ
/*
 * Description:
 * defines a routine to be an ISR (Interrupt Service Routine)
 * 
 * Note:
 * This is ignored if compiling in Thumb state (__thumb defined)
 */
/* __irq not required for SYSTEM as there is a dispatcher available
 */
   #define IRQ
#endif

/*
 * Description:
 * Macro to bind all interrupts.
 * A typical invocation is apBIND_ALL_INTERRUPTS(Handler,RawHandler);
 *
 * Implementation:
 * ***USED INTERNALLY ONLY***
 *
 * This assumes that the standard naming is used:
 * + Interrupts: Number of interrupts
 * + pSources: Pointer to array of interrupt sources
 * + oId: Identifier for the peripheral
 * + parameter _h - handler routine
 * + parameter _r - raw ISR routine (not used for AS3525)
 */
#define apBIND_ALL_INTERRUPTS(_h,_r) {UWORD32 c=Interrupts; apREL_OBJ_WARN; if (c) {while (c--) \
                                     {apVIC_HandlerSet(*(pSources+c),_h,(UWORD32)oId); \
                                      apVIC_InterruptEnable(*(pSources+c));}}}

#if defined(apOS_NO_STATIC_STATE) && (apOS_NO_STATIC_STATE)
/*
 * Description:
 * Data access macro for accessing the state structure for the desired peripheral 
 *
 * Implementation:
 * ***USED INTERNALLY ONLY***
 *
 * The data access macro is used to allow the code to be switched between static and
 * heap-based memory. 
 *
 * The first parameter is the module name, and the second is an array index (for static
 * memory) or a pointer (for heap-based memory). 
 */
    #define apSTATE_GET(_mod,_ptr) ((_mod ## _sStateStruct *)(_ptr)) 
#else
    #define apSTATE_GET(_mod,_ptr) (& _mod ## _sState[_ptr])
#endif

/*
 * Description:
 * Version access macro used for run-time identification of the Primecell version 
 *
 * Implementation:
 * ***USED INTERNALLY ONLY***
 *
 * This macro loads the identifier from the Primecell registers into the Version
 * element of the passed structure.  If these are absent, the version is set to zero.
 *
 * The parameter is a pointer to the state data for the driver, and it is assumed that
 * this has the elements below: 
 * +pBase - The register base address
 * +Version - an element to store the version identifier
 */
#define apVERSION_GET(_ptr) {UWORD32 * pReg = (UWORD32 *) _ptr->pBase; \
        if ((*(pReg+0x3FC)&0xFF)|((*(pReg+0x3FD)&0xFF)<<8)|((*(pReg+0x3FE)&0xFF)<<16)|((*(pReg+0x3FF)&0xFF)<<24)==0xB105F00D) \
        {_ptr->Version=(*(pReg+0x3F8) & 0xF) + ((*(pReg+0x3F8) & 0xF0)>>4) * 10 + (*(pReg+0x3F9) & 0xF)*100;} \
        else {_ptr->Version=0;}}

/*
 * Description:
 * Checking macro.  This is placed at the start of routines to check that the 'oId' parameter is within
 * the allowed range.  This will only apply if apOS_NO_STATIC_STATE is not defined, and so there is a
 * defined range of allowed instance values.  Otherwise, we merely assert that the pointer is not NULL.
 *
 * Implementation:
 * ***USED INTERNALLY ONLY***
 */
#if !apOS_NO_STATIC_STATE
#define apINSTANCE_CHECK(_module) apASSERT(oId<apOS_ ## _module ## _MAXIMUM)
#else
#define apINSTANCE_CHECK(_module) apASSERT(oId)
#endif

/*
 * Description:
 * Error codes - each module is assigned space for error codes from apERR_XXXX_START to apERR_XXXX_START+255.
 *
 * Implementation:
 * We define an enumerated type apError.  By using this we avoid the need to
 * specify individual values for the error constants, but can simply append
 * new constants to the list below.
 *
 * Code numbers with the top bit clear are generic errors.
 * Those with the top bit set (negative) are module-specific errors
 */
typedef enum {
/*---------------Generic errors---------------*/
apERR_NONE          =0,

apERR_BAD_PARAMETER =1,    /* Call failed due to a parameter out of range. */
apERR_UNSUPPORTED   =2,    /* Call failed due to a parameter which was in range, 
                              but unsupported for this variant of the hardware. */
apERR_BUSY          =3,    /* Resource is already in use */

/*--------------Specific errors---------------*/
apERR_GPIO_START            =  apERR_NONE              - 0x100,    /*Module apGPIO*/
AS353xERR_I2C_START         =  apERR_GPIO_START        - 0x100,    /*Module I2c*/
AS353xERR_I2SIN_START       =  AS353xERR_I2C_START     - 0x100,    /*Module I2SIN*/
AS353xERR_I2SOUT_START      =  AS353xERR_I2SIN_START   - 0x100,    /*Module I2SOUT*/
AS353xERR_AUD_START         =  AS353xERR_I2SOUT_START  - 0x100,    /*Module AUDIO*/
AS353xERR_MEMSTICK_START    =  AS353xERR_AUD_START     - 0x100,    /*Module MEMSTICK*/
apERR_SMC_START             =  AS353xERR_MEMSTICK_START- 0x100,    /*Module apSMC*/
apERR_UART_START            =  apERR_SMC_START         - 0x100,    /*Module apUART*/
apERR_RTC_START             =  apERR_UART_START        - 0x100,    /*Module apRTC*/
apERR_PPI_START             =  apERR_RTC_START         - 0x100,    /*Module apPPI*/
apERR_SCI_START             =  apERR_PPI_START         - 0x100,    /*Module apSCI*/
apERR_KMI_START             =  apERR_SCI_START         - 0x100,    /*Module apKMI*/
apERR_SSP_START             =  apERR_KMI_START         - 0x100,    /*Module apSSP*/
apERR_MCI_START             =  apERR_SSP_START         - 0x100,    /*Module apMCI*/
apERR_AACI_START            =  apERR_MCI_START         - 0x100,    /*Module apAACI*/          
apERR_DMA_START             =  apERR_AACI_START        - 0x100,    /*Module apDMA*/
apERR_VIC_START             =  apERR_DMA_START         - 0x100,    /*Module apVIC*/
apERR_CLCD_START            =  apERR_VIC_START         - 0x100,    /*Module apCLCD*/
apERR_DCDC_START            =  apERR_CLCD_START        - 0x100,    /*Module apDCDC*/
apERR_TIMER_START           =  apERR_DCDC_START        - 0x100,    /*Module apTIMER*/
apERR_ACI_START             =  apERR_TIMER_START       - 0x100,    /*Module apACI*/
apERR_SSMC_START            =  apERR_ACI_START         - 0x100,    /*Module apSSMC*/
apERR_PL172_START           =  apERR_SSMC_START        - 0x100,    /*Module apPL172*/
apERR_PL175_START           =  apERR_PL172_START       - 0x100,    /*Module apPL175*/
apERR_PL093_START           =  apERR_PL175_START       - 0x100,    /*Module apPL093*/
apERR_NAF_START             =  apERR_PL093_START       - 0x100,    /*Module Nand Flash*/
apERR_IDE_START             =  apERR_NAF_START         - 0x100,    /*Module IDE controller*/
apERR_MMC_START             =  apERR_IDE_START         - 0x100,    /*Module MMC */
apERR_RLD_START             =  apERR_MMC_START         - 0x100,    /*Module Reloader*/
apERR_AFE_START             =  apERR_RLD_START         - 0x100,    /*Module A. FRONTEND*/
apERR_AUD_START             =  apERR_AFE_START         - 0x100,    /*Module Audio driver*/

/*============================================*/
/*To add a new block of module errors, insert before this comment the line:
 * apERR_[thismodule]_START=apERR_[lastmodule]_START - 0x100,
 * If more than 256 error messages are needed, increase the 0x100 constant 
 * as required.
*/

apERR_END                  /*dummy terminator*/
} apError;



/*========================================================================
 * INTERRUPT CONTROLLER FUNCTIONS
 */

/*
 * Description:
 * This is a generic type for interrupt service routines, called when an interrupt occurs for a particular interrupt source.
 *
 * Remarks:
 * + the first parameter is the ID of the interrupt source that caused the
 *   interrupt.
 * + the second parameter is a UWORD32 of data registered with the interrupt 
 *   handling function. It is used to store the identifier for the peripheral
 *   which is handling the interrupt.
 */
typedef void (*apOS_INT_rServiceRoutine)(CONST apOS_INT_oInterruptSource oSource,
                                      UWORD32 Parameter);

/*
 * Description:
 * This is an alternative format of interrupt service routine, used with a minimal dispatcher
 * and called directly from the interrupt vector.
 *
 */
typedef IRQ void (*apOS_INT_rRawISR)(void);

/*
 * Description:
 * Registers an interrupt handling function for a specified interrupt
 * source. Also registers an ID number which will be passed to the 
 * interrupt handler when the interrupt occurs.
 *
 * Implementation:
 * This routine supplies both an interrupt handling function (rHandler) and a 'raw' ISR
 * (rRawHandler) which can be called directly from the interrupt vector.  The interrupt
 * controller may be passed either of these as desired.
 * 
 * Inputs:
 * eSource         - the interrupt source to attach the handler to.
 * rHandler        - the standard interrupt handling function.
 * Id              - ID number to be passed to the handler function
 * rRawHandler     - alternative interrupt service routine entry point, called directly from the interrupt vector
 */
PUBLIC void apOS_INT_HandlerSet(CONST apOS_INT_oInterruptSource oSource, 
                           apOS_INT_rServiceRoutine rHandler,
                           UWORD32 Id,
                           apOS_INT_rRawISR rRawHandler);

/*
 * Description:
 * Removes an interrupt handling function for a specified interrupt
 * source.
 * 
 * Inputs:
 * eSource         - the interrupt source to remove the handler from.
 */
PUBLIC void apOS_INT_HandlerClear(CONST apOS_INT_oInterruptSource oSource);

/*
 * Description:
 * Returns the interrupt source of the currently active interrupt
 *
 * Implementation:
 * This routine is called from within the driver raw ISR to obtain a source to be
 * passed to the interrupt controller routines.
 * 
 * Inputs:
 * none
 *
 * Return Value:
 * the interrupt source of the current interrupt.
 */
PUBLIC apOS_INT_oInterruptSource apOS_INT_SourceGet(void);

/*
 * Description:
 * Returns the instance of the peripheral of the currently active interrupt
 *
 * Implementation:
 * This routine is called from within the driver raw ISR to obtain the instance of
 * the peripheral requesting service.
 * 
 * Inputs:
 * none
 *
 * Return Value:
 * the peripheral instance relating to the current interrupt.
 */
PUBLIC UWORD32 apOS_INT_InstanceGet(void);


/*
 * Description:
 * Returns the state of IRQs
 *
 * Return Value:
 * TRUE if IRQs are enabled (core bit not set)
 */
PUBLIC BOOL apOS_CoreIRQGet(void);
 
/*
 * Description:
 * Enables IRQs to the processor by modifying the processor's
 * mode register. 
 *
 * Implementation:
 * This function is not implemented by the interrupt module, 
 * but must be defined in "oss.s", as it requires the function 
 * to temporarily enter a priviledged mode (if in user mode).
 */
PUBLIC void apOS_CoreIRQEnable(void);
 
/*
 * Description:
 * Disables IRQs to the processor by modifying the processor's
 * mode register. 
 *
 * Implementation:
 * This function is not implemented by the interrupt module, 
 * but must be defined in "oss.s", as it requires the function 
 * to temporarily enter a priviledged mode (if in user mode).
 */
PUBLIC void apOS_CoreIRQDisable(void);

/*
 * Description:
 * Enables FIQs to the processor by modifying the processor's
 * mode register. 
 *
 * Implementation:
 * This function is not implemented by the interrupt module, 
 * but must be defined in "oss.s", as it requires the function 
 * to temporarily enter a priviledged mode (if in user mode).
 */
PUBLIC void apOS_CoreFIQEnable(void);
 
/*
 * Description:
 * Disables FIQs to the processor by modifying the processor's
 * mode register. 
 *
 * Implementation:
 * This function is not implemented by the interrupt module, 
 * but must be defined in "oss.s", as it requires the function 
 * to temporarily enter a priviledged mode (if in user mode).
 */
PUBLIC void apOS_CoreFIQDisable(void);
 
/*========================================================================
 * TIMER FUNCTIONS
 */
 
/*
 * Description:
 * Uses a timer to wait for a specified length of time (in microseconds). 
 * Does not return to the caller until this time span has expired. 
 * 
 * Inputs:
 * Microseconds - the length of time to wait in microseconds
 *
 * Implementation:
 * The implementation of this function uses apOS_TIMER_TimeoutEnable with
 * timer parameter 0.  The timer used must have been initialised before 
 * it is used by this function.
 *
 * If apOS_TIMER_Enable is not implemented (returns an error), this function
 * will be implemented using the semi-hosted
 * clock() function or, if apOS_CONFIG_USE_NO_CLIB is defined, a delay loop.
 * This should not be relied upon to generate specific delays.
 */
PUBLIC void apOS_TIMER_Wait(UWORD32 Microseconds);

/*
 * Description:
 * Uses the specified timer to call back after a specified delay
 * 
 * Inputs:
 * TimerNumber - a specification of which timer is required.
 *      How this is interpreted may depend on the implementation.
 * Microseconds - the length of time to wait in microseconds
 * rCallback - a callback function called when the timer elapses.
 * CallbackParam - Parameter to be passed to the user callback routine
 *      Usually the identifier for the calling device.
 *
 * Implementation:
 * The standard implementation maps the TimerNumber parameter to the timer
 * identifier specified in apOS_TIMER_oId in module applatfm.h
 *
 * Note that the first and last parameters will need typecasting to support
 * the apOS_NO_STATIC_STATE build.
 *
 * Note:
 * The timer used must have been initialised before it is used by this function.
 *
 * Return Value:
 * + apERR_NONE - timer set successfully
 * + apERR_UNSUPPORTED - no timers in build (apOS_PLATFORM_HAS_TIMERS defined as zero)
 * + apERR_BAD_PARAMETER - timers 
 */
PUBLIC apError apOS_TIMER_TimeoutEnable(UWORD32 TimerNumber,
                                     UWORD32 Microseconds,
                                     void rCallback(UWORD32),
                                     UWORD32 CallbackParam);
 
/*
 * Description:
 * Cancels the timing set up by apOS_TIMER_TimeoutEnable so that the callback
 * will not be called.  Has no effect if the callback has already occurred.
 * 
 * Inputs:
 * TimerNumber - a specification of which timer is required.
 *      How this is interpreted may depend on the implementation.
 *
 * Implementation:
 * The standard implementation maps the TimerNumber parameter to the timer
 * identifier specified in apOS_TIMER_oId in module applatfm.h
 *
 * Note:
 * The timer used must have been initialised before it is used by this function.
 *
 * Return Value:
 * none
 */
PUBLIC void apOS_TIMER_TimeoutDisable(UWORD32 TimerNumber);

#ifdef __cplusplus
} /* allow C++ to use these headers */
#endif    /* __cplusplus */

#endif // APOS_H



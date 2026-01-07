;/*****************************************************************************/
;/* IRQ.S: IRQ Handler                                                        */
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2005-2006 Keil Software. All rights reserved.               */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


; Enhanced Interrupt Controller (EIC) definitions
EIC_BASE        EQU     0xFFFFFC00      ; EIC Base Address
CICR_OFS        EQU     0x04            ; Curr. Int. Channel R. Offset
IVR_OFS         EQU     0x18            ; Interrupt Vector Reg. Offset
IPR0_OFS        EQU     0x40            ; Interrupt Pending Reg. 0 Offset
IPR1_OFS        EQU     0x44            ; Interrupt Pending Reg. 1 Offset


        AREA IRQ, CODE, READONLY 
        ARM

        PRESERVE8
        ALIGN
        EXPORT  IRQHandler

IRQHandler
        SUB     LR, LR, #4              ; Update Link Register
        STMFD   SP!, {R0-R12, LR}       ; Save Workspace & LR to Stack
        MRS     R0, SPSR                ; Copy SPSR to R0
        STMFD   SP!, {R0, R1}           ; Save SPSR to Stack (8-byte)
        LDR     LR, =ReturnAddress      ; Read Return Address
        LDR     R0, =EIC_BASE
        LDR     R1, =IVR_OFS
        ADD     PC, R0, R1              ; Branch to IRQ Handler
ReturnAddress
        ; Clear pending bit in EIC (using the proper IPRx)
        LDR     R0, =EIC_BASE
        LDR     R2, [R0, #CICR_OFS]     ; Get the IRQ Channel Number
        CMP     R2, #31
        SUBHI   R2, R2, #32
        MOV     R3, #1
        MOV     R3, R3, LSL R2
        STRLS   R3, [R0, #IPR0_OFS]     ; Clear corresponding IPR0 bit
        STRHI   R3, [R0, #IPR1_OFS]     ; Clear corresponding IPR1 bit
        LDMFD   SP!, {R0, R1}           ; Restore SPSR to R0
        MSR     SPSR_cxsf, R0           ; Restore SPSR
        LDMFD   SP!, {R0-R12, PC}^      ; Return to program
         

;*******************************************************************************
;                   Import IRQ handlers from 73x_it.c
;*******************************************************************************

        IMPORT PRCCUCMU_IRQHandler
        IMPORT EXTIT01_IRQHandler
        IMPORT EXTIT02_IRQHandler
        IMPORT EXTIT03_IRQHandler
        IMPORT EXTIT04_IRQHandler
        IMPORT EXTIT05_IRQHandler
        IMPORT EXTIT06_IRQHandler
        IMPORT EXTIT07_IRQHandler
        IMPORT EXTIT08_IRQHandler
        IMPORT EXTIT09_IRQHandler
        IMPORT EXTIT10_IRQHandler
        IMPORT EXTIT11_IRQHandler
        IMPORT EXTIT12_IRQHandler
        IMPORT EXTIT13_IRQHandler
        IMPORT EXTIT14_IRQHandler
        IMPORT EXTIT15_IRQHandler
        IMPORT DMATRERR_IRQHandler
        IMPORT TIM1_IRQHandler
        IMPORT TIM2_IRQHandler
        IMPORT TIM3_IRQHandler
        IMPORT TIM4_IRQHandler
        IMPORT TB0_IRQHandler
        IMPORT TB1_IRQHandler
        IMPORT TB2_IRQHandler
        IMPORT TIM5_IRQHandler
        IMPORT TIM6_IRQHandler
        IMPORT TIM7_IRQHandler
        IMPORT TIM8_IRQHandler
        IMPORT TIM9_IRQHandler
        IMPORT UART2_IRQHandler
        IMPORT UART3_IRQHandler
        IMPORT FLASHEOP_IRQHandler
        IMPORT PWM0_IRQHandler
        IMPORT PWM1_IRQHandler
        IMPORT PWM2_IRQHandler
        IMPORT PWM3_IRQHandler
        IMPORT PWM4_IRQHandler
        IMPORT PWM5_IRQHandler
        IMPORT WIU_IRQHandler
        IMPORT WDGWUT_IRQHandler
        IMPORT BSPI0_IRQHandler
        IMPORT BSPI1_IRQHandler
        IMPORT BSPI2_IRQHandler
        IMPORT UART0_IRQHandler
        IMPORT UART1_IRQHandler
        IMPORT I2C0ITERR_IRQHandler
        IMPORT I2C1ITERR_IRQHandler
        IMPORT I2C0ITDDC_IRQHandler
        IMPORT I2C1ITDDC_IRQHandler
        IMPORT CAN0_IRQHandler
        IMPORT CAN1_IRQHandler
        IMPORT CAN2_IRQHandler
        IMPORT DMA0_IRQHandler
        IMPORT DMA1_IRQHandler
        IMPORT DMA2_IRQHandler
        IMPORT DMA3_IRQHandler
        IMPORT ADC_IRQHandler
        IMPORT RTC_IRQHandler


;*******************************************************************************
;* Macro Name     : IRQ_to_SYS
;* Description    : This macro used to switch form IRQ mode to SYS mode
;* Input          : none.
;* Output         : none
;*******************************************************************************
        MACRO
                IRQ_to_SYS
                MSR     CPSR_c, #0x1F   ; Switch to SYS Mode
                STMFD   SP!, {R0,LR}    ; Save Link Register (8-byte Stack)
        MEND
;*******************************************************************************
;* Macro Name     : SYS_to_IRQ
;* Description    : This macro used to switch from SYS mode to IRQ mode
;                   then to return to IRQHnadler routine.
;* Input          : none.
;* Output         : none.
;*******************************************************************************
        MACRO
                SYS_to_IRQ
                LDMFD   SP!, {R0,LR}    ; Restore Link Register (8-byte Stack)
                MSR     CPSR_c, #0xD2   ; Switch to IRQ Mode
                BX      LR              ; Return to IRQHandler routine to
                                        ; clear the pending bit
        MEND
;*******************************************************************************


;*******************************************************************************
;* Function Name  : PRCCUCMUIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the PRCCUCMUIRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   PRCCUCMUIRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT PRCCUCMUIRQHandler 
PRCCUCMUIRQHandler
        IRQ_to_SYS
        BL     PRCCUCMU_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : EXTIT01IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the EXTIT01IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   EXTIT01IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT EXTIT01IRQHandler 
EXTIT01IRQHandler
        IRQ_to_SYS
        BL     EXTIT01_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : EXTIT02IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the EXTIT02IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   EXTIT02IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT EXTIT02IRQHandler 
EXTIT02IRQHandler
        IRQ_to_SYS
        BL     EXTIT02_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : EXTIT03IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the EXTIT03IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   EXTIT03IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT EXTIT03IRQHandler 
EXTIT03IRQHandler
        IRQ_to_SYS
        BL     EXTIT03_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : EXTIT04IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the EXTIT04IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   EXTIT04IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT EXTIT04IRQHandler 
EXTIT04IRQHandler
        IRQ_to_SYS
        BL     EXTIT04_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : EXTIT05IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the EXTIT05IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   EXTIT05IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT EXTIT05IRQHandler 
EXTIT05IRQHandler
        IRQ_to_SYS
        BL     EXTIT05_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : EXTIT06IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the EXTIT06IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   EXTIT06IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT EXTIT06IRQHandler 
EXTIT06IRQHandler
        IRQ_to_SYS
        BL     EXTIT06_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : EXTIT07IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the EXTIT07IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   EXTIT07IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT EXTIT07IRQHandler 
EXTIT07IRQHandler
        IRQ_to_SYS
        BL     EXTIT07_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : EXTIT08IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the EXTIT08IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   EXTIT08IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT EXTIT08IRQHandler 
EXTIT08IRQHandler
        IRQ_to_SYS
        BL     EXTIT08_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : EXTIT09IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the EXTIT09IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   EXTIT09IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT EXTIT09IRQHandler 
EXTIT09IRQHandler
        IRQ_to_SYS
        BL     EXTIT09_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : EXTIT10IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the EXTIT10IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   EXTIT10IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT EXTIT10IRQHandler 
EXTIT10IRQHandler
        IRQ_to_SYS
        BL     EXTIT10_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : EXTIT11IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the EXTIT11IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   EXTIT11IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT EXTIT11IRQHandler 
EXTIT11IRQHandler
        IRQ_to_SYS
        BL     EXTIT11_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : EXTIT12IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the EXTIT12IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   EXTIT12IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT EXTIT12IRQHandler 
EXTIT12IRQHandler
        IRQ_to_SYS
        BL     EXTIT12_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : EXTIT13IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the EXTIT13IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   EXTIT13IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT EXTIT13IRQHandler 
EXTIT13IRQHandler
        IRQ_to_SYS
        BL     EXTIT13_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : EXTIT14IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the EXTIT14IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   EXTIT14IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT EXTIT14IRQHandler 
EXTIT14IRQHandler
        IRQ_to_SYS
        BL     EXTIT14_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : EXTIT15IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the EXTIT15IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   EXTIT15IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT EXTIT15IRQHandler 
EXTIT15IRQHandler
        IRQ_to_SYS
        BL     EXTIT15_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : DMATRERRIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the DMATRERRIRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   DMATRERRIRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT DMATRERRIRQHandler 
DMATRERRIRQHandler
        IRQ_to_SYS
        BL     DMATRERR_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM1IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the TIM1IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   TIM1IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM1IRQHandler 
TIM1IRQHandler
        IRQ_to_SYS
        BL     TIM1_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM2IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the TIM2IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   TIM2IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM2IRQHandler 
TIM2IRQHandler
        IRQ_to_SYS
        BL     TIM2_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM3IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the TIM3IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   TIM3IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM3IRQHandler 
TIM3IRQHandler
        IRQ_to_SYS
        BL     TIM3_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM4IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the TIM4IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   TIM4IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM4IRQHandler 
TIM4IRQHandler
        IRQ_to_SYS
        BL     TIM4_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TB0IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the TB0IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   TB0IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TB0IRQHandler 
TB0IRQHandler
        IRQ_to_SYS
        BL     TB0_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TB1IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the TB1IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   TB1IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TB1IRQHandler 
TB1IRQHandler
        IRQ_to_SYS
        BL     TB1_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TB2IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the TB2IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   TB2IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TB2IRQHandler 
TB2IRQHandler
        IRQ_to_SYS
        BL     TB2_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM5IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the TIM5IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   TIM5IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM5IRQHandler 
TIM5IRQHandler
        IRQ_to_SYS
        BL     TIM5_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM6IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the TIM6IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   TIM6IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM6IRQHandler 
TIM6IRQHandler
        IRQ_to_SYS
        BL     TIM6_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM7IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the TIM7IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   TIM7IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM7IRQHandler 
TIM7IRQHandler
        IRQ_to_SYS
        BL     TIM7_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM8IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the TIM8IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   TIM8IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM8IRQHandler 
TIM8IRQHandler
        IRQ_to_SYS
        BL     TIM8_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM9IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the TIM9IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   TIM9IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM9IRQHandler 
TIM9IRQHandler
        IRQ_to_SYS
        BL     TIM9_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : UART2IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the UART2IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   UART2IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT UART2IRQHandler 
UART2IRQHandler
        IRQ_to_SYS
        BL     UART2_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : UART3IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the UART3IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   UART3IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT UART3IRQHandler 
UART3IRQHandler
        IRQ_to_SYS
        BL     UART3_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : FLASHEOPIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the FLASHEOPIRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   FLASHEOPIRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT FLASHEOPIRQHandler 
FLASHEOPIRQHandler
        IRQ_to_SYS
        BL     FLASHEOP_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : PWM0IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the PWM0IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   PWM0IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT PWM0IRQHandler 
PWM0IRQHandler
        IRQ_to_SYS
        BL     PWM0_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : PWM1IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the PWM1IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   PWM1IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT PWM1IRQHandler 
PWM1IRQHandler
        IRQ_to_SYS
        BL     PWM1_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : PWM2IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the PWM2IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   PWM2IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT PWM2IRQHandler 
PWM2IRQHandler
        IRQ_to_SYS
        BL     PWM2_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : PWM3IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the PWM3IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   PWM3IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT PWM3IRQHandler 
PWM3IRQHandler
        IRQ_to_SYS
        BL     PWM3_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : PWM4IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the PWM4IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   PWM4IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT PWM4IRQHandler 
PWM4IRQHandler
        IRQ_to_SYS
        BL     PWM4_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : PWM5IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the PWM5IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   PWM5IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT PWM5IRQHandler 
PWM5IRQHandler
        IRQ_to_SYS
        BL     PWM5_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : WIUIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the WIUIRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   WIUIRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT WIUIRQHandler 
WIUIRQHandler
        IRQ_to_SYS
        BL     WIU_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : WDGWUTIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the WDGWUTIRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   WDGWUTIRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT WDGWUTIRQHandler 
WDGWUTIRQHandler
        IRQ_to_SYS
        BL     WDGWUT_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : BSPI0IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the BSPI0IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   BSPI0IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT BSPI0IRQHandler 
BSPI0IRQHandler
        IRQ_to_SYS
        BL     BSPI0_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : BSPI1IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the BSPI1IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   BSPI1IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT BSPI1IRQHandler 
BSPI1IRQHandler
        IRQ_to_SYS
        BL     BSPI1_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : BSPI2IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the BSPI2IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   BSPI2IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT BSPI2IRQHandler 
BSPI2IRQHandler
        IRQ_to_SYS
        BL     BSPI2_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : UART0IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the UART0IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   UART0IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT UART0IRQHandler 
UART0IRQHandler
        IRQ_to_SYS
        BL     UART0_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : UART1IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the UART1IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   UART1IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT UART1IRQHandler 
UART1IRQHandler
        IRQ_to_SYS
        BL     UART1_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : I2C0ITERRIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the I2C0ITERRIRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   I2C0ITERRIRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT I2C0ITERRIRQHandler 
I2C0ITERRIRQHandler
        IRQ_to_SYS
        BL     I2C0ITERR_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : I2C1ITERRIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the I2C1ITERRIRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   I2C1ITERRIRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT I2C1ITERRIRQHandler 
I2C1ITERRIRQHandler
        IRQ_to_SYS
        BL     I2C1ITERR_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : I2C0ITDDCIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the I2C0ITDDCIRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   I2C0ITDDCIRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT I2C0ITDDCIRQHandler 
I2C0ITDDCIRQHandler
        IRQ_to_SYS
        BL     I2C0ITDDC_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : I2C1ITDDCIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the I2C1ITDDCIRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   I2C1ITDDCIRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT I2C1ITDDCIRQHandler 
I2C1ITDDCIRQHandler
        IRQ_to_SYS
        BL     I2C1ITDDC_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : CAN0IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the CAN0IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   CAN0IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT CAN0IRQHandler 
CAN0IRQHandler
        IRQ_to_SYS
        BL     CAN0_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : CAN1IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the CAN1IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   CAN1IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT CAN1IRQHandler 
CAN1IRQHandler
        IRQ_to_SYS
        BL     CAN1_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : CAN2IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the CAN2IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   CAN2IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT CAN2IRQHandler 
CAN2IRQHandler
        IRQ_to_SYS
        BL     CAN2_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : DMA0IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the DMA0IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   DMA0IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT DMA0IRQHandler 
DMA0IRQHandler
        IRQ_to_SYS
        BL     DMA0_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : DMA1IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the DMA1IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   DMA1IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT DMA1IRQHandler 
DMA1IRQHandler
        IRQ_to_SYS
        BL     DMA1_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : DMA2IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the DMA2IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   DMA2IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT DMA2IRQHandler 
DMA2IRQHandler
        IRQ_to_SYS
        BL     DMA2_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : DMA3IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the DMA3IRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   DMA3IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT DMA3IRQHandler 
DMA3IRQHandler
        IRQ_to_SYS
        BL     DMA3_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : ADCIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the ADCIRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   ADCIRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT ADCIRQHandler 
ADCIRQHandler
        IRQ_to_SYS
        BL     ADC_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : RTCIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the RTCIRQHandler function located in 73x_it.c.
;                   Then to return to IRQ mode after the
;                   RTCIRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT RTCIRQHandler 
RTCIRQHandler
        IRQ_to_SYS
        BL     RTC_IRQHandler
        SYS_to_IRQ

;*******************************************************************************


                    END

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
EIC_BASE        EQU     0xFFFFF800      ; EIC Base Address
CICR_OFS        EQU     0x04            ; Curr. Int. Channel Register Offset
IVR_OFS         EQU     0x18            ; Interrupt Vector Register Offset
IPR_OFS         EQU     0x40            ; Interrupt Pending Register Offset


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
        MOV     R3, #1
        MOV     R3, R3, LSL R2
        STR     R3, [R0, #IPR_OFS]      ; Clear corresponding IPR bit        
        LDMFD   SP!, {R0, R1}           ; Restore SPSR to R0
        MSR     SPSR_cxsf, R0           ; Restore SPSR
        LDMFD   SP!, {R0-R12, PC}^      ; Return to program
         

;*******************************************************************************
;                   Import IRQ handlers from 75x_it.c
;*******************************************************************************

        IMPORT WAKUP_IRQHandler
        IMPORT TIM2_OC2_IRQHandler
        IMPORT TIM2_OC1_IRQHandler
        IMPORT TIM2_IC12_IRQHandler
        IMPORT TIM2_UP_IRQHandler
        IMPORT TIM1_OC2_IRQHandler
        IMPORT TIM1_OC1_IRQHandler
        IMPORT TIM1_IC12_IRQHandler
        IMPORT TIM1_UP_IRQHandler
        IMPORT TIM0_OC2_IRQHandler
        IMPORT TIM0_OC1_IRQHandler
        IMPORT TIM0_IC12_IRQHandler
        IMPORT TIM0_UP_IRQHandler
        IMPORT PWM_OC123_IRQHandler
        IMPORT PWM_EM_IRQHandler
        IMPORT PWM_UP_IRQHandler
        IMPORT I2C_IRQHandler
        IMPORT SSP1_IRQHandler
        IMPORT SSP0_IRQHandler
        IMPORT UART2_IRQHandler
        IMPORT UART1_IRQHandler
        IMPORT UART0_IRQHandler
        IMPORT CAN_IRQHandler
        IMPORT USB_LP_IRQHandler
        IMPORT USB_HP_IRQHandler
        IMPORT ADC_IRQHandler
        IMPORT DMA_IRQHandler
        IMPORT EXTIT_IRQHandler
        IMPORT MRCC_IRQHandler
        IMPORT FLASHSMI_IRQHandler
        IMPORT RTC_IRQHandler
        IMPORT TB_IRQHandler


;*******************************************************************************
;* Macro Name     : IRQ_to_SYS
;* Description    : This macro used to switch form IRQ mode to SYS mode.
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
;* Description    : This macro used to switch from SYS mode to IRQ mode.
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
;* Function Name  : WAKUPIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the WAKUP_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the WAKUP_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT WAKUPIRQHandler
WAKUPIRQHandler
        IRQ_to_SYS
        BL     WAKUP_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM2_OC2IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the TIM3_OC2_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the TIM2_OC2_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM2_OC2IRQHandler
TIM2_OC2IRQHandler
        IRQ_to_SYS
        BL     TIM2_OC2_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM2_OC1IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the TIM2_OC1_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the TIM2_OC1_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM2_OC1IRQHandler
TIM2_OC1IRQHandler
        IRQ_to_SYS
        BL     TIM2_OC1_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM2_IC12IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the TIM2_IC12_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the TIM2_IC12_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM2_IC12IRQHandler
TIM2_IC12IRQHandler
        IRQ_to_SYS
        BL     TIM2_IC12_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM2_UPIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the TIM2_UP_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the TIM3_UP_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM2_UPIRQHandler
TIM2_UPIRQHandler
        IRQ_to_SYS
        BL     TIM2_UP_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM1_OC2IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the TIM1_OC2_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the TIM1_OC2_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM1_OC2IRQHandler
TIM1_OC2IRQHandler
        IRQ_to_SYS
        BL     TIM1_OC2_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM1_OC1IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the TIM1_OC1_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the TIM1_OC1_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM1_OC1IRQHandler
TIM1_OC1IRQHandler
        IRQ_to_SYS
        BL     TIM1_OC1_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM1_IC12IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the TIM1_IC12_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the TIM1_IC12_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM1_IC12IRQHandler
TIM1_IC12IRQHandler
        IRQ_to_SYS
        BL     TIM1_IC12_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM1_UPIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the TIM1_UP_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the TIM1_UP_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM1_UPIRQHandler
TIM1_UPIRQHandler
        IRQ_to_SYS
        BL     TIM1_UP_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM0_OC2IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the TIM0_OC2_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the TIM0_OC2_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM0_OC2IRQHandler
TIM0_OC2IRQHandler
        IRQ_to_SYS
        BL     TIM0_OC2_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM0_OC1IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the TIM0_OC1_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the TIM0_OC1_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM0_OC1IRQHandler
TIM0_OC1IRQHandler
        IRQ_to_SYS
        BL     TIM0_OC1_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM0_IC12IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the TIM0_IC12_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the TIM0_IC12_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM0_IC12IRQHandler
TIM0_IC12IRQHandler
        IRQ_to_SYS
        BL     TIM0_IC12_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TIM0_UPIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the TIM0_UP_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the TIM0_UP_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TIM0_UPIRQHandler
TIM0_UPIRQHandler
        IRQ_to_SYS
        BL     TIM0_UP_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : PWM_OC123IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the PWM_OC123_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the PWM_OC123_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT PWM_OC123IRQHandler
PWM_OC123IRQHandler
        IRQ_to_SYS
        BL     PWM_OC123_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : PWM_EMIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the PWM_EM_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the PWM_EM_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT PWM_EMIRQHandler
PWM_EMIRQHandler
        IRQ_to_SYS
        BL     PWM_EM_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : PWM_UPIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the PWM_UP_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the PWM_UP_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT PWM_UPIRQHandler
PWM_UPIRQHandler
        IRQ_to_SYS
        BL     PWM_UP_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : I2CIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the I2C_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the I2C_IRQHandler function
;*                  termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT I2CIRQHandler
I2CIRQHandler
        IRQ_to_SYS
        BL     I2C_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : SSP1IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the SSP1_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the SSP1_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT SSP1IRQHandler
SSP1IRQHandler
        IRQ_to_SYS
        BL     SSP1_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : SSP0IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the SSP0_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the SSP0_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT SSP0IRQHandler
SSP0IRQHandler
        IRQ_to_SYS
        BL     SSP0_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : UART2IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the UART2_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the UART2_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT UART2IRQHandler
UART2IRQHandler
        IRQ_to_SYS
        BL     UART2_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : UART1IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the UART1_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the UART1_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT UART1IRQHandler
UART1IRQHandler
        IRQ_to_SYS
        BL     UART1_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : UART0IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the UART0_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the UART0_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT UART0IRQHandler
UART0IRQHandler
        IRQ_to_SYS
        BL     UART0_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : CANIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the CAN_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the CAN_IRQHandler function
;*                  termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT CANIRQHandler
CANIRQHandler
        IRQ_to_SYS
        BL     CAN_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : USB_LPIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the USB_LP_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the USB_LP_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT USB_LPIRQHandler
USB_LPIRQHandler
        IRQ_to_SYS
        BL     USB_LP_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : USB_HPIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the USB_HP_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the USB_HP_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT USB_HPIRQHandler
USB_HPIRQHandler
        IRQ_to_SYS
        BL     USB_HP_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : ADCIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the ADC_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the ADC_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT ADCIRQHandler
ADCIRQHandler
        IRQ_to_SYS
        BL     ADC_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : DMAIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the DMA_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the DMA_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT DMAIRQHandler
DMAIRQHandler
        IRQ_to_SYS
        BL     DMA_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : EXTITIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the EXTIT_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the EXTIT_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
        EXPORT TBIRQHandler
;*******************************************************************************
        EXPORT EXTITIRQHandler
EXTITIRQHandler
        IRQ_to_SYS
        BL     EXTIT_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : MRCCIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the MRCC_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the MRCC_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT MRCCIRQHandler
MRCCIRQHandler
        IRQ_to_SYS
        BL     MRCC_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : FLASHSMIIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the FLASHSMI_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the FLASHSMI_IRQHandler
;*                  function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT FLASHSMIIRQHandler
FLASHSMIIRQHandler
        IRQ_to_SYS
        BL     FLASHSMI_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : RTCIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the RTC_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the RTC_IRQHandler function
;*                  termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT RTCIRQHandler
RTCIRQHandler
        IRQ_to_SYS
        BL     RTC_IRQHandler
        SYS_to_IRQ

;*******************************************************************************
;* Function Name  : TBIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;*                  the TB_IRQHandler function located in 75x_it.c.
;*                  Then to return to IRQ mode after the TB_IRQHandler function
;*                  termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT TBIRQHandler
TBIRQHandler
        IRQ_to_SYS
        BL     TB_IRQHandler
        SYS_to_IRQ

;*******************************************************************************


                    END

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
CICR_OFS        EQU     0x04            ; Curr. Int. Channel R. Offset
IVR_OFS         EQU     0x18            ; Interrupt Vector Reg. Offset
IPR_OFS         EQU     0x40            ; Interrupt Pending Reg. Offset


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
;                   Import IRQ handlers from 71x_it.c
;*******************************************************************************

        IMPORT  T0TIMI_IRQHandler
        IMPORT  FLASH_IRQHandler
        IMPORT  RCCU_IRQHandler
        IMPORT  RTC_IRQHandler
        IMPORT  WDG_IRQHandler
        IMPORT  XTI_IRQHandler
        IMPORT  USBHP_IRQHandler
        IMPORT  I2C0ITERR_IRQHandler
        IMPORT  I2C1ITERR_IRQHandler
        IMPORT  UART0_IRQHandler
        IMPORT  UART1_IRQHandler
        IMPORT  UART2_IRQHandler
        IMPORT  UART3_IRQHandler
        IMPORT  BSPI0_IRQHandler
        IMPORT  BSPI1_IRQHandler
        IMPORT  I2C0_IRQHandler
        IMPORT  I2C1_IRQHandler
        IMPORT  CAN_IRQHandler
        IMPORT  ADC12_IRQHandler
        IMPORT  T1TIMI_IRQHandler
        IMPORT  T2TIMI_IRQHandler
        IMPORT  T3TIMI_IRQHandler
        IMPORT  HDLC_IRQHandler
        IMPORT  USBLP_IRQHandler
        IMPORT  T0TOI_IRQHandler
        IMPORT  T0OC1_IRQHandler
        IMPORT  T0OC2_IRQHandler


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
;* Function Name  : T0TIMIIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the T0TIMI_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   T0TIMI_IRQHandler function termination.
;* Input          : none.
;* Output         : none.
;*******************************************************************************
        EXPORT  T0TIMIIRQHandler
T0TIMIIRQHandler
                IRQ_to_SYS
                BL  T0TIMI_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : FLASHIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the FLASH_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   FLASH_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  FLASHIRQHandler
FLASHIRQHandler
                IRQ_to_SYS
                BL  FLASH_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : RCCUIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the RCCU_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   RCCU_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  RCCUIRQHandler
RCCUIRQHandler
                IRQ_to_SYS
                BL  RCCU_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : RTCIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the RTC_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   RTC_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  RTCIRQHandler
RTCIRQHandler
                IRQ_to_SYS
                BL  RTC_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : WDGIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the WDG_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   WDG_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  WDGIRQHandler
WDGIRQHandler
                IRQ_to_SYS
                BL  WDG_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : XTIIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the XTI_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   XTI_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  XTIIRQHandler
XTIIRQHandler
                IRQ_to_SYS
                BL  XTI_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : USBHPIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the USBHP_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   USBHP_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  USBHPIRQHandler
USBHPIRQHandler
                IRQ_to_SYS
                BL  USBHP_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : I2C0ITERRIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the I2C0ITERR_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   I2C0ITERR_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  I2C0ITERRIRQHandler
I2C0ITERRIRQHandler
                IRQ_to_SYS
                BL  I2C0ITERR_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : I2C1ITERRIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the I2C1ITERR_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   I2C1ITERR_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  I2C1ITERRIRQHandler
I2C1ITERRIRQHandler
                IRQ_to_SYS
                BL  I2C1ITERR_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : UART0IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the UART0_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   UART0_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  UART0IRQHandler
UART0IRQHandler
                IRQ_to_SYS
                BL  UART0_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : UART1IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the UART1_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   UART1_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  UART1IRQHandler
UART1IRQHandler
                IRQ_to_SYS
                BL  UART1_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : UART2IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the UART2_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   UART2_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  UART2IRQHandler
UART2IRQHandler
                IRQ_to_SYS
                BL  UART2_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : UART3IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the UART3_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   UART3_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  UART3IRQHandler
UART3IRQHandler
                IRQ_to_SYS
                BL  UART3_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : BSPI0IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the BSPI0_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   BSPI0_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  BSPI0IRQHandler
BSPI0IRQHandler
                IRQ_to_SYS
                BL  BSPI0_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : BSPI1IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the BSPI1_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   BSPI1_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  BSPI1IRQHandler
BSPI1IRQHandler
                IRQ_to_SYS
                BL  BSPI1_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : I2C0IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the I2C0_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   I2C0_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  I2C0IRQHandler
I2C0IRQHandler
                IRQ_to_SYS
                BL  I2C0_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : I2C1IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the I2C1_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   I2C1_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  I2C1IRQHandler
I2C1IRQHandler
                IRQ_to_SYS
                BL  I2C1_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : CANIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the CAN_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   CAN_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  CANIRQHandler
CANIRQHandler
                IRQ_to_SYS
                BL  CAN_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : ADC12IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the ADC12_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   ADC12_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  ADC12IRQHandler
ADC12IRQHandler
                IRQ_to_SYS
                BL  ADC12_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : T1TIMIIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the T1TIMI_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   T1TIMI_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  T1TIMIIRQHandler
T1TIMIIRQHandler
                IRQ_to_SYS
                BL  T1TIMI_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : T2TIMIIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the T2TIMI_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   T2TIMI_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  T2TIMIIRQHandler
T2TIMIIRQHandler
                IRQ_to_SYS
                BL  T2TIMI_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : T3TIMIIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the T3TIMI_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   T3TIMI_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  T3TIMIIRQHandler
T3TIMIIRQHandler
                IRQ_to_SYS
                BL  T3TIMI_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : HDLCIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the HDLC_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   HDLC_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  HDLCIRQHandler
HDLCIRQHandler
                IRQ_to_SYS
                BL  HDLC_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : USBLPIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the USBLP_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   USBLP_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  USBLPIRQHandler
USBLPIRQHandler
                IRQ_to_SYS
                BL  USBLP_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : T0TOIIRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the T0TOI_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   T0TOI_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  T0TOIIRQHandler
T0TOIIRQHandler
                IRQ_to_SYS
                BL  T0TOI_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : T0OC1IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the T0OC1_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   T0OC1_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  T0OC1IRQHandler
T0OC1IRQHandler
                IRQ_to_SYS
                BL  T0OC1_IRQHandler
                SYS_to_IRQ
;*******************************************************************************
;* Function Name  : T0OC2IRQHandler
;* Description    : This function used to switch to SYS mode before entering
;                   the T0OC2_IRQHandler function located in 71x_it.c.
;                   Then to return to IRQ mode after the
;                   T0OC2_IRQHandler function termination.
;* Input          : none
;* Output         : none
;*******************************************************************************
        EXPORT  T0OC2IRQHandler
T0OC2IRQHandler
                IRQ_to_SYS
                BL  T0OC2_IRQHandler
                SYS_to_IRQ
;*******************************************************************************


                    END

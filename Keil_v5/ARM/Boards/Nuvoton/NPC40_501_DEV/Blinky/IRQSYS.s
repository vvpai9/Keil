;/*****************************************************************************/
;/* IRQ.S: IRQ Interrupt Handler                                              */
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2005-2010 Keil Software. All rights reserved.               */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


; Interrupt Controller definitions
AIC_BASE        EQU     0xB8002000             ; Interrupt Controller Base
AIC_IPER        EQU     0x10C                  ; Interrupt Priority Encoding Register 
AIC_MECR        EQU     0x120                  ; Mask Enable Command Register 
AIC_MDCR        EQU     0x124                  ; Mask Disable Command Register 
AIC_EOSCR       EQU     0x130                  ; End of Service Command Register 

                AREA    IRQ, CODE, READONLY
                ARM

                PRESERVE8
                ALIGN
                IMPORT  IRQ_ISR
                EXPORT  IRQ_Handler

IRQ_Handler     FUNCTION
                SUB     LR, LR, #4              ; Update Link Register
                STMFD   SP!, {R0-R12, LR}       ; Save Workspace & LR to Stack
                LDR     LR, =ReturnAddress      ; Read Return Address
                LDR     R1, =AIC_BASE           ; AIC Base
                LDR     R0, [R1, #AIC_IPER]     ; Read Interrupt Priority Encoding Register

                MOV     R2, R0, LSR #2          ; Calculate IRQ channel

                MOV     R3, #1
                MOV     R3, R3, LSL R2          ; prepare Interrupt mask for AIC_MECR/AIC_MDCR
                STR     R3, [R1, #AIC_MDCR]     ; Disable current Interrupt

                STR     R1, [R1, #AIC_EOSCR]    ; Acknowledge current Interrupt

                STMFD   SP!, {R3}               ; Save Interrupt mask to Stack

                LDR     R0, =IRQ_ISR            ; ISR Table
                LDR     R0, [R0, R2, LSL #2]    ; Get ISR Address
                BX      R0                      ; Branch to ISR

ReturnAddress   LDMFD   SP!, {R3}               ; Restore Interrupt mask from Stack
                LDR     R1, =AIC_BASE           ; AIC Base
                STR     R3, [R1, #AIC_MECR]     ; Enable current Interrupt

                LDMFD   SP!, {R0-R12, PC}^      ; Return to program
         
                ENDFUNC

                END

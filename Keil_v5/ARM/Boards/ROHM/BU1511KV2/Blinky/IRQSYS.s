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
ICR_BASE        EQU     0xC0007000             ; Interrupt Controller Base
ICR_FSR         EQU     0x30                   ; IRQ Final Status Register 
ICR_IRQNUM      EQU     0x10                   ; IRQ # 0..15

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
                LDR     R1, =ICR_BASE           ; ICR Base
                LDR     R0, [R1, #ICR_FSR]      ; Read IRQ Final Status Register
                                                ; Calculate IRQ number
                MOV     R1, #-1
IRQ_Next        ADD     R1, R1, #1
                LSRS    R0, R0, #1
                BCC     IRQ_Next
                CMP     R1, #ICR_IRQNUM
                BHS     ReturnAddress

                LDR     R0, =IRQ_ISR            ; ISR Table
                LDR     R0, [R0, R1, LSL #2]    ; Get ISR Address
                BX      R0                      ; Branch to ISR

ReturnAddress   LDMFD   SP!, {R0-R12, PC}^      ; Return to program
         
                ENDFUNC

                END

;/*****************************************************************************/
;/* IRQ.S: IRQ Interrupt Handler                                              */
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2005-2006 Keil Software. All rights reserved.               */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


; Interrupt Controller definitions
ICR_BASE        EQU     0x78000000             ; Interrupt Controller Base
ICR_IRN         EQU     0x14                   ; IRQ Number Register
ICR_CILCL       EQU     0x28                   ; Curr Int Level Clr Register


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
                MOV     R1, #ICR_BASE           ; ICR Base
                LDR     R0, [R1, #ICR_IRN]      ; Read IRQ Number
                LDR     R1, =IRQ_ISR            ; ISR Table
                LDR     R0, [R1, R0, LSL #2]    ; Get ISR Address
                BX      R0                      ; Branch to ISR
ReturnAddress   MOV     R1, #ICR_BASE           ; ICR Base
                MOV     R0, #0                  ; Arbitrary Value (don't care)
                STR     R0, [R1, #ICR_CILCL]    ; Clear Current Interrupt Level
                LDMFD   SP!, {R0-R12, PC}^      ; Return to program
         
                ENDFUNC

                END

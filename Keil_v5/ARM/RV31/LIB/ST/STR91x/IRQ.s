;/*****************************************************************************/
;/* IRQ.S: IRQ Handler                                                        */
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2005-2008 Keil Software. All rights reserved.               */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


; Vectored Interrupt Controller (VIC) definitions
VectorAddr      EQU    0xFFFFF030       ; VIC Vector Address Register
VectorAddrDaisy EQU    0xFC000030       ; Daisy VIC Vector Address Register


        AREA IRQ, CODE, READONLY 
        ARM

        PRESERVE8
        ALIGN
        EXPORT  IRQHandler

IRQHandler
        SUB     LR, LR, #4              ; Update Link Register
        STMFD   SP!, {R0-R12, LR}       ; Save Workspace & LR to Stack
        LDR     R0, =VectorAddr        
        LDR     R0, [R0]                ; Read the Routine Address
        BLX     R0                      ; Branch to the IRQ Handler
        LDMFD   SP!, {R0-R12, PC}^      ; Restore Workspace & PC from Stack
         

        END

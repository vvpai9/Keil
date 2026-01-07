;/*****************************************************************************/
;/* DABT.S: Data Abort Handler                                                */
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2005-2008 Keil Software. All rights reserved.               */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


        AREA DAbt, CODE, READONLY 
        ARM

        PRESERVE8
        ALIGN
        IMPORT  Abort_Handler
        EXPORT  DAbtHandler

DAbtHandler
        SUB     LR, LR, #8              ; Update Link Register
        STMFD   SP!, {R0-R12, LR}       ; Save Workspace & LR to Stack
        BL      Abort_Handler           ; Branch to Data Abort Handler
        LDMFD   SP!, {R0-R12, PC}^      ; Return to program after
                                        ; Data Abort Instruction

        END

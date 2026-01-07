;/*****************************************************************************/
;/* F_I_BIT.S: F & I Bit Masking                                              */
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2005-2006 Keil Software. All rights reserved.               */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


I_Bit           EQU     0x80            ; when I bit is set, IRQ is disabled
F_Bit           EQU     0x40            ; when F bit is set, FIQ is disabled

                AREA F_I_BIT, CODE, READONLY 
                ARM

                PRESERVE8
                ALIGN

                EXPORT  ARMFIQ_Disable
                EXPORT  ARMFIQ_Enable
                EXPORT  ARMIRQ_Disable
                EXPORT  ARMIRQ_Enable

ARMFIQ_Disable  FUNCTION                ; Disable the ARM7 core FIQ
                MRS     R0, CPSR
                ORR     R0, R0, #F_Bit	
                MSR     CPSR_c, R0
                BX      LR
                ENDFUNC

ARMFIQ_Enable   FUNCTION                ; Enable the ARM7 Core FIQ
                MRS     R0, CPSR
                BIC     R0, R0,#F_Bit	
                MSR     CPSR_c, R0
                BX      LR 
                ENDFUNC

ARMIRQ_Disable  FUNCTION                ; Disable the ARM7 core IRQ
                MRS     R0, CPSR
                ORR     R0, R0, #I_Bit	
                MSR     CPSR_c, R0
                BX      LR
                ENDFUNC

ARMIRQ_Enable   FUNCTION                ; Enable the ARM7 Core IRQ
                MRS     R0, CPSR
                BIC     R0, R0,#I_Bit	
                MSR     CPSR_c, R0
                BX      LR 
                ENDFUNC
 
                END

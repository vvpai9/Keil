;-----------------------------------------------------------------------
; $Id:: lh79524_int_vec.s 27 2007-08-31 19:35:06Z kevinw               $
; 
;  Project: LH79524
; 
;  Description: 
;   This file contains code for exception handling and in particular,
;   IRQ handling. It is left to the application to install FIQ
;   handler code and manage FIQ interrupts.
;
;   The IRQ handler is split into three parts. The first part, the
;   "prologue", and the third part, the "epilogue", are faciliate OS
;   ports. The second part handles the actual interrupt source that
;   caused the IRQ exception. The prologue can be used to signal the OS
;   that interrupt processing is occurring and to re-enable interrupts 
;   so that nested interrupts can occur. The epilogue can be used to
;   signal the OS that interrupt processing is complete, a context
;   switch can be performed, etc. If there is no OS, the prologue
;   function does nothing; the epilog function restores the context
;   that was saved prior to prologue call and then returns to 
;   the interrupted thread.
;
;   The actual interrupt handler section is sandwiched between the 
;   prologue and epilogue. It loads the pc with the VIC vector address
;   registers contents so that control is transferred directly to the
;   appropriate interrupt handler by the VIC. When the interrupt handler
;   returns, the IRQ handler clears the interrupt at the VIC.
;
;   You should be write interrupt handlers in C. If you must write
;   an assembly language interrupt handler, you may use registers r0-r3,
;   r10, r12 and r14 (lr) without preserving them in the handler. The
;   IRQ handler preserves these registers so that interrupt handler
;   functions can be standard, ARM-Thumb Procedure Call Standard 
;   (ATPCS) compliant routines. If you use any other registers, you must
;   preserve them on the IRQ stack at the beginning of your handler and
;   you must restore them at the  before the handler function returns.
;   By following ATPCS and assuming handlers also obey ATPcS, the IRQ
;   handler does not waste cycles preserving registers unnecessarily.
;   If you must use handlers that are not ATPCS compliant, pre-define
;   ATPCS_COMPLIANT {FALSE} so that the full context gets saved on
;   IRQ handler start and the full context gets restored in the default
;   epilogue.
;
;   If you code your interrupt handler functions in C, do not use the
;   __irq keyword. ARM compilers build C functions that obey the ATPCS.
;   The register preservation that the __irq keyword forces is already
;   done by the IRQ handler function.
;
;   If you rewrite the epilogue function, make sure it removes the saved
;   registers and CPSR from the IRQ stack or else IRQ stack overflow
;   will result.
;
;  Notes:
;   Use this file if all interrupt processing is done in ARM mode.
;   If your interrupt handlers operate in Thumb mode, use 
;   LH79524_int_vec_thumb.s instead.
;
;  Assembler predefines:
;   ATPCS_COMPLIANT should be predfined as {FALSE} at the assembler
;   command line if the IRQ handler prologue or any interrupt handler
;   the IRQ function calls is not ATPCS_COMPLIANT. ATPCS_COMPLIANT
;   defaults to {TRUE} if it is not defined at the assembler command
;   line.
;
;  References:
;   ARM-Thumb Procedure Call Standard 24-October-2000 ARM document
;   number SWS ESPC 0002 B-01
;
;-----------------------------------------------------------------------
;  
;   Software that is described herein is for illustrative purposes only  
;   which provides customers with programming information regarding the  
;   products. This software is supplied "AS IS" without any warranties.  
;   NXP Semiconductors assumes no responsibility or liability for the 
;   use of the software, conveys no license or title under any patent, 
;   copyright, or mask work right to the product. NXP Semiconductors 
;   reserves the right to make changes in the software without 
;   notification. NXP Semiconductors also make no representation or 
;   warranty that such application will be suitable for the specified 
;   use without further testing or modification. 
; 
;-----------------------------------------------------------------------

    AREA INTHANDLER, CODE    ;name this block of code


    IMPORT  LH79524_fiq_handler_addr
    IMPORT  LH79524_swi_handler_addr
   
    EXPORT  LH79524_irq_handler
    EXPORT  LH79524_fiq_handler
    EXPORT  LH79524_swi_handler
    EXPORT  LH79524_irq_vec
    EXPORT  LH79524_fiq_vec
    EXPORT  LH79524_swi_vec
    
LH79524_VIC_VECT_ADDR   EQU     0xfffff030

;-----------------------------------------------------------------------
;
;
; Function: irq_vec
;
; Purpose:
;  Transfers control to LH79524_irq_handler() after an IRQ
;  exception.
; 
; Processing:
;  Load the address of LH79524_irq_dispatcher() stored at reserved
;  address 0x14 into the pc register.
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes:
;  IRQ int handling routine addr is in 0x14
;
;-----------------------------------------------------------------------
LH79524_irq_vec
    LDR     pc,[pc,#-12] ; pc is 0x18 + 8. subtracting 12 yield 0x14.
    
;-----------------------------------------------------------------------
;
;
; Function: LH79524_fiq_vec
;
; Purpose:
;  Transfers control to LH79524_fiq_handler() after an FIQ
;  exception.
; 
; Processing:
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes: FIQ int handling routine addr is in 0x24
;  
;-----------------------------------------------------------------------
LH79524_fiq_vec
    LDR     pc,[pc,#0] ; pc is 0x1C + 8. subtracting 0 yield 0x24.

;-----------------------------------------------------------------------
;
;
; Function: LH79524_swi_vec
;
; Purpose:
;  Transfers control to LH79524_swi_handler() after an SWI
;  exception.
; 
; Processing:
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes: SWI int handling routine addr is in 0x20
;  
;-----------------------------------------------------------------------
LH79524_swi_vec 
    LDR     pc,[pc,#0x10] ; pc is 0x8 + 8. adding 0x10 yield 0x20.

        
;-----------------------------------------------------------------------
;
;
; Function: LH79524_irq_handler
;
; Purpose: Handle IRQ exceptions
; 
; Processing:
; 1. Branch and link to the IRQ prologue 
; 2. Load the VIC vector address into PC
; 3. Write to the VIC vector address register to signal end 
;    of interrupt
; 4. Branch to epilogue
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes:
;  It is assumed that all functions called from this IRQ handler are
;  ATPCS compliant. This functions uses that assumption to avoid the
;  unnecessary stacking of registers that get preserved anyway by 
;  ATPCS compliant functions. If any function is not ATPCS compliant,
;  please define ATPCS_COMPLIANT {FALSE} to force this function to 
;  preserve all registers. If ATPCS_COMPLIANT is defined {FALSE}, then
;  the epilogue function must also restore all registers.
;
;-----------------------------------------------------------------------
LH79524_irq_handler 

    ; save link register
    SUB     lr,lr,#4
    ; stack all registers
    STMFD   sp!,{r0-r12,lr}
    MRS     r0, SPSR ;push SPSR to allow nested interrupts
    STMFD   sp!,{r0}
    
    ; save the link register for return after the ISR has executed
LH79524_vic_jump
    LDR     r0,=LH79524_VIC_VECT_ADDR
    ;LDR		r1,[r0]
    MOV     lr,pc
    ;MOV		pc,r1
    LDR     pc,[r0]

    ; control returns here after the ISR has executed
    ; write to the VIC Vector Address register to signal 
    ; end-of-interrupt to the VIC
    LDR     r0,=LH79524_VIC_VECT_ADDR
    MOV     r1,#0
    STR     r1,[r0] 

    ; branch to epilogue code   
    B       LH79524_default_vic_epilogue
    ;LDR     r1, =LH79524_default_irq_epilogue
    ;LDR     pc, [r1, #0x0]
    
LH79524_irq_handler_end

;-----------------------------------------------------------------------
;
;
; Function: LH79524_fiq_handler
;
; Purpose: Handle FIQ exceptions
; 
; Processing:
; 1. Load the handler address into PC
; 2. Branch to epilogue
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes:
;
;-----------------------------------------------------------------------
LH79524_fiq_handler

    ; save link register
    SUB     lr,lr,#4
    ; stack all registers
    STMFD   sp!,{r0-r12,lr}
    MRS     r0, SPSR ;push SPSR to allow nested interrupts
    STMFD   sp!,{r0}
    
    ; save the link register for return after the ISR has executed
    LDR     r0,=LH79524_fiq_handler_addr
    MOV     lr,pc
    LDR     pc,[r0]

    ; branch to epilogue code    
    B       LH79524_default_vic_epilogue
    ;LDR     r1, =LH79524_default_irq_epilogue
    ;LDR     pc, r1
    
LH79524_fiq_handler_end

;-----------------------------------------------------------------------
;
;
; Function: LH79524_swi_handler
;
; Purpose: Handle SWI exceptions
; 
; Processing:
; 1. Load the handler address into PC
; 2. Branch to epilogue
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes:
;
;-----------------------------------------------------------------------
LH79524_swi_handler

    ; save link register
    SUB     lr,lr,#4
    ; stack all registers
    STMFD   sp!,{r0-r12,lr}
    MRS     r0, SPSR ;push SPSR to allow nested interrupts
    STMFD   sp!,{r0}
    
    ; save the link register for return after the ISR has executed
    LDR     r0,=LH79524_swi_handler_addr
    MOV     lr,pc
    LDR     pc,[r0]

    ; branch to epilogue code    
    B       LH79524_default_vic_epilogue
    ;LDR     r1, =LH79524_default_irq_epilogue
    ;LDR     pc, [r1, #0x0]
    
LH79524_swi_handler_end
    
;-----------------------------------------------------------------------
;
;
; Function: LH79524_default_vic_epilogue
;
; Purpose:
;   Perform post-processing after returning from an interrupt handler.
;   Meant to ease RTOS porting.
;
; Processing:
;   Restore registers and SPSR and switch out of IRQ mode
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes:
;   This is primarily a placeholder for more extensive epilogue code
;   typical of any RTOS. This does very minimal post-processing. RTOSes
;   must not rely on this and replace this code with something that 
;   satisfys their specific requirements.
;
;   This function by default assumes that the IRQ handler has stacked
;   only those registers that ATPCS compliant functions can destroy.
;   If the prologue function or any interrupt handler function the
;   IRQ handler calls is not ATPCS compliant, please define 
;   ATPCS_COMPLIANT as {FALSE} in the assembler command line
;-----------------------------------------------------------------------
LH79524_default_vic_epilogue
    LDMFD   sp!,{r0} ; recover SPSR from stack
    MSR   SPSR_cf,r0 ; restore SPSR
    ; restore all the registers
    LDMFD   sp!,{r0-r12,pc}^
 
 	END

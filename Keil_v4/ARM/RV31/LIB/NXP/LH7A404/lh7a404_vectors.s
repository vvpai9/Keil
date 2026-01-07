;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; $Id:: lh7a404_vectors.s 14 2007-08-28 16:08:18Z kevinw               $
; 
; Project: LH7A404 interrupt and exception vectors
;
; Description:
;     Interrupt and exception handler vector layout used by the
;     interrupt driver, exception functions, and startup code. This
;     block is placed at the start of the ARM memory region at address
;     0x00000000 or 0xFFFF0000 (if high vectors are enabled).
;
; Notes:
;     This version of the file is used with the ARM ADS toolset.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 ; Software that is described herein is for illustrative purposes only  
 ; which provides customers with programming information regarding the  
 ; products. This software is supplied "AS IS" without any warranties.  
 ; NXP Semiconductors assumes no responsibility or liability for the 
 ; use of the software, conveys no license or title under any patent, 
 ; copyright, or mask work right to the product. NXP Semiconductors 
 ; reserves the right to make changes in the software without 
 ; notification. NXP Semiconductors also make no representation or 
 ; warranty that such application will be suitable for the specified 
 ; use without further testing or modification. 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    AREA |.text|, CODE   ; Interrupt and exception vectors	

    export lh7a404_reset_vector
    export vec_reset_handler
    export vec_undefined_handler
    export vec_swi_handler
    export vec_prefetch_handler
    export vec_abort_handler
    export vec_irq_handler
    export vec_fiq_handler

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Function: Basic interrupt and exception jump block
;
; Purpose: Block that defines the interrupt and exception jump points
;
; Description:
;     On a bootable image that is being built, this area should be
;     linked to address 0x00000000. This area may be used with the
;     interrupt and exception drivers when installing handlers and
;     routers. For each interrupt and exception that gets routed
;     here, the indirect PC value of the handler function is loaded
;     to jump to that function.
;
; Parameters: NA
;
; Outputs; NA
;
; Returns: NA
;
; Notes: NA
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
lh7a404_reset_vector
    LDR  pc, [pc, #24]          ; Get address of Reset handler
    LDR  pc, [pc, #24]          ; Get address of Undefined handler
    LDR  pc, [pc, #24]          ; Get address of SWI handler
    LDR  pc, [pc, #24]          ; Get address of Prefetch handler
    LDR  pc, [pc, #24]          ; Get address of Abort handler
    NOP                         ; Reserved
    LDR  pc, [pc, #20]          ; Get address of IRQ handler
    LDR  pc, [pc, #20]          ; Get address of FIQ handler

vec_reset_handler
    DCD  lh7a404_reset_handler

vec_undefined_handler
    DCD  lh7a404_undefined_handler

vec_swi_handler
    DCD  lh7a404_swi_handler

vec_prefetch_handler
    DCD  lh7a404_prefetch_handler

vec_abort_handler
    DCD  lh7a404_abort_handler

vec_irq_handler
    DCD  lh7a404_irq_handler

vec_fiq_handler
    DCD  lh7a404_fiq_handler

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
; Function: lh7a404_reset_handler
;
; Purpose:
;   Default reset handler
; 
; Processing:
;   Loop forever
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes:
;     The board startup code does not use this handler! However, when
;     the interrupt and exception table is installed, the reset handler
;     will be updated to this handler.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
lh7a404_reset_handler
    B    lh7a404_reset_handler

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
; Function: lh7a404_undefined_handler
;
; Purpose:
;   Handle the undefined exception
; 
; Processing:
;   Loop forever
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes: None
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
lh7a404_undefined_handler
    B    lh7a404_undefined_handler

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
; Function: lh7a404_swi_handler
;
; Purpose:
;   Handle the software interrupt
; 
; Processing:
;   Loop forever
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes: None
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
lh7a404_swi_handler
    B    lh7a404_swi_handler

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
; Function: lh7a404_prefetch_handler
;
; Purpose:
;   Handle the prefetch abort exception
; 
; Processing:
;   Loop forever
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes: None
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
lh7a404_prefetch_handler
    B    lh7a404_prefetch_handler

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
; Function: lh7a404_abort_handler
;
; Purpose:
;   Handle the abort exception
; 
; Processing:
;   Loop forever
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes: None
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
lh7a404_abort_handler
    B    lh7a404_abort_handler

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
; Function: lh7a404_irq_handler
;
; Purpose:
;   Handle the IRQ interrupt
; 
; Processing:
;   Loop forever
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes: None
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
lh7a404_irq_handler
    B    lh7a404_irq_handler

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
; Function: lh7a404_fiq_handler
;
; Purpose:
;   Handle the FIQ interrupt
; 
; Processing:
;   Loop forever
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes: None
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
lh7a404_fiq_handler
    B    lh7a404_fiq_handler

    END

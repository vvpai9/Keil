/*----------------------------------------------------------------------------
 *      RL-ARM - TCPnet
 *----------------------------------------------------------------------------
 *      Name:    IRQ.C
 *      Purpose: Common IRQ Handler for NXP LPC3250
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <RTL.H>
#include <LPC325x.h>            /* Register definition file for LPC325x      */


extern void interrupt_ethernet (void) __irq;


/*--------------------------- IRQ_Handler -----------------------------------*/

__asm void IRQ_Handler (void) {
  /* Common IRQ Handler */
        PRESERVE8
        ARM

        STMDB   SP!,{R0}                        ; Save R0
        LDR     R0,=__cpp((U32)&MIC_SR)         ; Load MIC_SR Address
        LDR     R0,[R0]                         ; Load MIC_SR Value

        TST     R0,#(1 << 29)                   ; Check Ethernet Flag
        LDMNEIA SP!,{R0}                        ; Restore R0
        LDRNE   PC,=__cpp(interrupt_ethernet)

//      TST     R0,#mIRQx                       ; Check IRQx Flag
//      LDMNEIA SP!,{R0}                        ; Restore R0
//      LDRNE   PC,=__cpp(IRQx)                 ; IRQx Function

//      TST     R0,#mIRQy                       ; Check IRQy Flag
//      LDMNEIA SP!,{R0}                        ; Restore R0
//      LDRNE   PC,=__cpp(IRQy)                 ; IRQy Function

        LDMIA   SP!,{R0}                        ; Restore R0
        SUBS    PC,LR,#4                        ; RETI
}

/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/

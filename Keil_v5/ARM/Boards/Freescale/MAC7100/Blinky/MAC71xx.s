;/*****************************************************************************/
;/* MAC71xx.S: Startup file for Blinky Example                                */
;/*****************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                          */ 
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2005-2006 Keil Software. All rights reserved.               */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


; *  The MAC71xx.S code is executed after CPU Reset. This file may be 
; *  translated with the following SET symbols. In uVision these SET 
; *  symbols are entered under Options - ASM - Define.
; *
; *  RAM_MODE: when set the device is configured for code execution
; *  from on-chip RAM starting at address 0x40000000. It woks in a way 
; *  that it remaps RAM -> 0x00000000 and Flash -> 0x20000000 so it can be used 
; *  for running and debugging of program in RAM with using interrupt also.


; Standard definitions of Mode bits and Interrupt (I & F) flags in PSRs

Mode_USR        EQU     0x10
Mode_FIQ        EQU     0x11
Mode_IRQ        EQU     0x12
Mode_SVC        EQU     0x13
Mode_ABT        EQU     0x17
Mode_UND        EQU     0x1B
Mode_SYS        EQU     0x1F

I_Bit           EQU     0x80            ; when I bit is set, IRQ is disabled
F_Bit           EQU     0x40            ; when F bit is set, FIQ is disabled


;// <h> Stack Configuration (Stack Sizes in Bytes)
;//   <o0> Undefined Mode      <0x0-0xFFFFFFFF:8>
;//   <o1> Supervisor Mode     <0x0-0xFFFFFFFF:8>
;//   <o2> Abort Mode          <0x0-0xFFFFFFFF:8>
;//   <o3> Fast Interrupt Mode <0x0-0xFFFFFFFF:8>
;//   <o4> Interrupt Mode      <0x0-0xFFFFFFFF:8>
;//   <o5> User/System Mode    <0x0-0xFFFFFFFF:8>
;// </h>

UND_Stack_Size  EQU     0x00000000
SVC_Stack_Size  EQU     0x00000008
ABT_Stack_Size  EQU     0x00000000
FIQ_Stack_Size  EQU     0x00000000
IRQ_Stack_Size  EQU     0x00000100
USR_Stack_Size  EQU     0x00000400

Stack_Size      EQU     (UND_Stack_Size + SVC_Stack_Size + ABT_Stack_Size + \
                         FIQ_Stack_Size + IRQ_Stack_Size + USR_Stack_Size)

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size

Stack_Top       EQU     Stack_Mem + Stack_Size


;// <h> Heap Configuration
;//   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF>
;// </h>

Heap_Size       EQU     0x00000000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
Heap_Mem        SPACE   Heap_Size


; Mempory mapping control
MCM_AAMR        EQU     0xFC040020          ; Address of AXBS Address Map Register

; Constants
AAMR_MASK       EQU	    0x000000FF          ; Last byte of the AAMR Register
AAMR_REMAP      EQU     0x8B                ; Map Program Flash on slave 
                                            ; port 0 to 0x20000000
                                            ; Map SRAM to 0x00000000


; Clock definitions
; CRG = Clock and Reset Generator Module
CRG_BASE        EQU     0xFC088000      ; CRG                      Base Address
; 8 Bit registers
CRG_SYNR_OFS    EQU     0x00            ; CRG Synthesizer Register       Offset
CRG_REFDV_OFS   EQU     0x01            ; CRG Reference Divider Register Offset
CRG_CRGFLG_OFS  EQU     0x03            ; CRG Flags Register             Offset
CRG_CLKSEL_OFS  EQU     0x05            ; CRG Clock Select Register      Offset
CRG_PLLCTL_OFS  EQU     0x06            ; CRG PLL Control Register       Offset

; Bit constants
CRG_LOCK        EQU     0x08            ; CRG PLL LOCK bit value
CRG_PLLEN       EQU     0x80            ; CRG PLL SELECT bit value (Enable PLL)

;// <e> Clock Setup
;//   <i> PLLCLK = 2 * OSCCLK * (CRG_SYNR + 1) / (CRG_REFDV + 1)
;//   <h> Clock and Reset Generator (CRG) Module
;//     <o1.0..5> CRG Synthesizer Register (SYNR) <0-31>
;//     <o2.0..3> CRG Reference Divider Register (REFDV) <0-15>
;//   </h>
;// </e>
CLOCK_SETUP     EQU     1
CRG_SYNR_Val    EQU     0x04
CRG_REFDV_Val   EQU     0x01


; External Interface Module (EIM) definitions
EIM_BASE        EQU     0xFC008080      ; EIM                      Base Address
; 16 Bit registers
EIM_CSAR0_OFS   EQU     0x00            ; Chip Select Address Register 0 Offset
EIM_CSAR1_OFS   EQU     0x0C            ; Chip Select Address Register 1 Offset
EIM_CSAR2_OFS   EQU     0x18            ; Chip Select Address Register 2 Offset
; 32 Bit registers
EIM_CSMR0_OFS   EQU     0x04            ; Chip Select Mask Register 0    Offset
EIM_CSMR1_OFS   EQU     0x10            ; Chip Select Mask Register 1    Offset
EIM_CSMR2_OFS   EQU     0x1C            ; Chip Select Mask Register 2    Offset
; 16 Bit registers
EIM_CSCR0_OFS   EQU     0x0A            ; Chip Select Control Register 0 Offset
EIM_CSCR1_OFS   EQU     0x16            ; Chip Select Control Register 1 Offset
EIM_CSCR2_OFS   EQU     0x22            ; Chip Select Control Register 2 Offset

;// <e> External Memory Setup
;//   <h> External Interface Module (EIM) Setup
;//     <o1.0..15> EIM Chip Select Address Register 0 <0x0000-0xFFFF>
;//     <h> EIM Chip Select Mask Register 0 
;//       <o2.16..32> BAM: Base Address Mask <0x0000-0xFFFF>
;//       <e2.8> WP: Write Protect                                         
;//       </e>
;//       <e2.6> AM: Alternate Master                                      
;//       </e>
;//       <e2.5> C/I: CPU space and Interrupt acknowledge cycle mask       
;//       </e>
;//       <e2.4> SC: Supervisor Code addres space mask                     
;//       </e>
;//       <e2.3> SD: Supervisor Data addres space mask                     
;//       </e>
;//       <e2.2> UC: User Code address space mask                          
;//       </e>
;//       <e2.1> UD: User Data address space mask                          
;//       </e>
;//       <e2.0> V: Chip selection configuration Valid bit                 
;//       </e>
;//     </h>
;//     <h> EIM Chip Select Control Register 0
;//       <o3.10..13> WS: Wait States <0-15>
;//       <e3.8> AA: Auto-acknowledge enable                               
;//       </e>
;//       <o3.6..7> PS: Port Size 
;//         <1=> 8-bit port size  
;//         <2=> 16-bit port size
;//         <3=> 16-bit port size
;//       <e3.5> BEM: Byte Enable Mode                                     
;//       </e>
;//       <e3.4> BSTR: Burst Read enable                                   
;//       </e>
;//       <e3.3> BSTW: Burst Write enable                                  
;//       </e>
;//     </h>
;//   </h>
;//
;//   <h> External Interface Module (EIM) Setup
;//     <o4.0..15> EIM Chip Select Address Register 1 <0x0000-0xFFFF>
;//     <h> EIM Chip Select Mask Register 1 
;//       <o5.16..32> BAM: Base Address Mask <0x0000-0xFFFF>
;//       <e5.8> WP: Write Protect                                         
;//       </e>
;//       <e5.6> AM: Alternate Master                                      
;//       </e>
;//       <e5.5> C/I: CPU space and Interrupt acknowledge cycle mask       
;//       </e>
;//       <e5.4> SC: Supervisor Code addres space mask                     
;//       </e>
;//       <e5.3> SD: Supervisor Data addres space mask                     
;//       </e>
;//       <e5.2> UC: User Code address space mask                          
;//       </e>
;//       <e5.1> UD: User Data address space mask                          
;//       </e>
;//       <e5.0> V: Chip selection configuration Valid bit                 
;//       </e>
;//     </h>
;//     <h> EIM Chip Select Control Register 1
;//       <o6.10..13> WS: Wait States <0-15>
;//       <e6.8> AA: Auto-acknowledge enable                               
;//       </e>
;//       <o6.6..7> PS: Port Size 
;//         <1=> 8-bit port size  
;//         <2=> 16-bit port size
;//         <3=> 16-bit port size
;//       <e6.5> BEM: Byte Enable Mode                                     
;//       </e>
;//       <e6.4> BSTR: Burst Read enable                                   
;//       </e>
;//       <e6.3> BSTW: Burst Write enable                                  
;//       </e>
;//     </h>
;//   </h>
;//
;//   <h> External Interface Module (EIM) Setup
;//     <o7.0..15> EIM Chip Select Address Register 2 <0x0000-0xFFFF>
;//     <h> EIM Chip Select Mask Register 2 
;//       <o8.16..32> BAM: Base Address Mask <0x0000-0xFFFF>
;//       <e8.8> WP: Write Protect                                         
;//       </e>
;//       <e8.6> AM: Alternate Master                                      
;//       </e>
;//       <e8.5> C/I: CPU space and Interrupt acknowledge cycle mask       
;//       </e>
;//       <e8.4> SC: Supervisor Code addres space mask                     
;//       </e>
;//       <e8.3> SD: Supervisor Data addres space mask                     
;//       </e>
;//       <e8.2> UC: User Code address space mask                          
;//       </e>
;//       <e8.1> UD: User Data address space mask                          
;//       </e>
;//       <e8.0> V: Chip selection configuration Valid bit                 
;//       </e>
;//     </h>
;//     <h> EIM Chip Select Control Register 2
;//       <o9.10..13> WS: Wait States <0-15>
;//       <e9.8> AA: Auto-acknowledge enable                               
;//       </e>
;//       <o9.6..7> PS: Port Size 
;//         <1=> 8-bit port size  
;//         <2=> 16-bit port size
;//         <3=> 16-bit port size
;//       <e9.5> BEM: Byte Enable Mode                                     
;//       </e>
;//       <e9.4> BSTR: Burst Read enable                                   
;//       </e>
;//       <e9.3> BSTW: Burst Write enable                                  
;//       </e>
;//     </h>
;//   </h>
;// </e>
EIM_SETUP       EQU     0

EIM_CSAR0_Val   EQU     0x0000
EIM_CSMR0_Val   EQU     0x00000001
EIM_CSCR0_Val   EQU     0x3DA0

EIM_CSAR1_Val   EQU     0x2000
EIM_CSMR1_Val   EQU     0x00000001
EIM_CSCR1_Val   EQU     0x3DA0

EIM_CSAR2_Val   EQU     0x4000
EIM_CSMR2_Val   EQU     0x00000001
EIM_CSCR2_Val   EQU     0x3DA0


; AIPS Access Control Registers
AIPS_BASE       EQU     0xFC000000      ; AIPS                      Base Address
; 32 Bit registers
AIPS_MPRA_OFS   EQU     0x00            ; AIPS Master Protection Register Offset
AIPS_PACRA_OFS  EQU     0x20            ; AIPS Periph Access Ctrl A  Regs Offset
AIPS_PACRC_OFS  EQU     0x28            ; AIPS Periph Access Ctrl C  Regs Offset
AIPS_OPACRA_OFS EQU     0x40            ; AIPS Off-Platfm Per Acc Ctrl A Regs Of
AIPS_OPACRB_OFS EQU     0x44            ; AIPS Off-Platfm Per Acc Ctrl B Regs Of
AIPS_OPACRC_OFS EQU     0x48            ; AIPS Off-Platfm Per Acc Ctrl C Regs Of
AIPS_OPACRD_OFS EQU     0x4C            ; AIPS Off-Platfm Per Acc Ctrl D Regs Of
AIPS_OPACRE_OFS EQU     0x50            ; AIPS Off-Platfm Per Acc Ctrl E Regs Of


;// <e0> Access privileges
;//   <i> Access privileges for bus master, peripherals and off-platform access
;//
;//   <e1> AIPS Master Protection Registers MPROT0 .. MPROT1
;//     <h> AIPS Master Protection Register MPROT0
;//       <o2.30> MTR: Master Trusted for Reads
;//         <i> Default: Trusted for read accesses
;//         <0=> Not trusted for read accesses
;//         <1=> Trusted for read accesses
;//       <o2.29> MTW: Master Trusted for Writes
;//         <i> Default: Trusted for write accesses
;//         <0=> Not trusted for write accesses
;//         <1=> Trusted for write accesses
;//       <o2.28> MPL: Master Privilege Level
;//         <i> Default: Accesses are not forced to user-mode
;//         <0=> Accesses are forced to user-mode
;//         <1=> Accesses are not forced to user-mode
;//     </h>
;//     <h> AIPS Master Protection Register MPROT1
;//       <o2.26> MTR: Master Trusted for Reads
;//         <i> Default: Trusted for read accesses
;//         <0=> Not trusted for read accesses
;//         <1=> Trusted for read accesses
;//       <o2.25> MTW: Master Trusted for Writes
;//         <i> Default: Trusted for write accesses
;//         <0=> Not trusted for write accesses
;//         <1=> Trusted for write accesses
;//       <o2.24> MPL: Master Privilege Level
;//         <i> Default: Accesses are not forced to user-mode
;//         <0=> Accesses are forced to user-mode
;//         <1=> Accesses are not forced to user-mode
;//     </h>
;//   </e>
;//
;//   <e3> AIPS Peripheral Access Control Register PAC0 .. PAC2
;//     <h> AIPS Peripheral Access Control Register PAC0
;//       <o4.30> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o4.29> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o4.28> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Peripheral Access Control Register PAC1
;//       <o4.26> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o4.25> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o4.24> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Peripheral Access Control Register PAC2
;//       <o4.22> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o4.21> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o4.20> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//   </e>
;//
;//   <e5> AIPS Peripheral Access Control Register PAC16 .. PAC18
;//     <h> AIPS Peripheral Access Control Register PAC16
;//       <o6.30> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o6.29> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o6.28> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Peripheral Access Control Register PAC17
;//       <o6.26> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o6.25> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o6.24> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Peripheral Access Control Register PAC18
;//       <o6.22> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o6.21> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o6.20> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//   </e>
;//
;//   <e7> AIPS Off-Platform Peripheral Access Control Register OPAC0 .. OPAC7
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC0
;//       <o8.30> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o8.29> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o8.28> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC1
;//       <o8.26> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o8.25> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o8.24> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC2
;//       <o8.22> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o8.21> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o8.20> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC3
;//       <o8.18> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o8.17> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o8.16> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC4
;//       <o8.14> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o8.13> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o8.12> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC5
;//       <o8.10> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o8.9> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o8.8> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC6
;//       <o8.6> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o8.5> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o8.4> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC7
;//       <o8.2> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o8.1> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o8.0> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//   </e>
;//
;//   <e9> AIPS Off-Platform Peripheral Access Control Register OPAC8, OPAC11, OPAC13, OPAC14
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC8
;//       <o10.30> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o10.29> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o10.28> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC11
;//       <o10.18> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o10.17> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o10.16> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC13
;//       <o10.10> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o10.9> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o10.8> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC14
;//       <o10.6> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o10.5> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o10.4> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//   </e>
;//
;//   <e11> AIPS Off-Platform Peripheral Access Control Register OPAC17 .. OPAC20, OPAC23
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC17
;//       <o12.26> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o12.25> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o12.24> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC18
;//       <o12.22> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o12.21> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o12.20> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC19
;//       <o12.18> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o12.17> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o12.16> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC20
;//       <o12.14> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o12.13> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o12.12> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC23
;//       <o12.2> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o12.1> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o12.0> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//   </e>
;//
;//   <e13> AIPS Off-Platform Peripheral Access Control Register OPAC24 .. OPAC26, OPAC28
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC24
;//       <o14.30> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o14.29> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o14.28> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC25
;//       <o14.26> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o14.25> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o14.24> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC26
;//       <o14.22> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o14.21> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o14.20> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC28
;//       <o14.14> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o14.13> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o14.12> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//   </e>
;//
;//   <e15> AIPS Off-Platform Peripheral Access Control Register OPAC32 .. OPAC33
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC32
;//       <o16.30> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o16.29> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o16.28> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//     <h> AIPS Off-Platform Peripheral Access Control Register OPAC33
;//       <o16.26> SP: Supervisor Protect
;//         <i> Default: Required
;//         <0=> Not required
;//         <1=> Required
;//       <o16.25> WP: Write Protect
;//         <i> Default: Write accesses allowed
;//         <0=> Write accesses allowed
;//         <1=> Write accesses not allowed
;//       <o16.24> TP: Trusted Protect
;//         <i> Default: Accesses from an untrusted master are not allowed
;//         <0=> Accesses from an untrusted master are allowed
;//         <1=> Accesses from an untrusted master are not allowed
;//     </h>
;//   </e>
;//
;// </e>
ACS_PRIV_SETUP  EQU     1

MPRA_SETUP      EQU     0
MPRA_Val        EQU     0x77000000

PACRA_SETUP     EQU     0
PACRA_Val       EQU     0x54400000

PACRC_SETUP     EQU     1
PACRC_Val       EQU     0x44000000

OPACRA_SETUP    EQU     1
OPACRA_Val      EQU     0x44404444

OPACRB_SETUP    EQU     0
OPACRB_Val      EQU     0x40040440

OPACRC_SETUP    EQU     1
OPACRC_Val      EQU     0x04044004

OPACRD_SETUP    EQU     1
OPACRD_Val      EQU     0x04004000

OPACRE_SETUP    EQU     0
OPACRE_Val      EQU     0x44000000


; Security Fields Address in Flash           
SEC_ADDRESS     EQU     0x00000400

;// <e> Security Options Setup
;//   <h> Backdoor Comparison Key
;//     <o1.0..31> First  Word <0x00000000-0xFFFFFFFF>
;//     <o2.0..31> Second Word <0x00000000-0xFFFFFFFF>
;//   </h>
;//   <o3.0..31> Program Flash Protection Bytes <0x00000000-0xFFFFFFFF>
;//   <o4.0..31> Program Flash SUPV Access Bytes <0x00000000-0xFFFFFFFF>
;//   <o5.0..31> Program Flash DATA Access Bytes <0x00000000-0xFFFFFFFF>
;//   <o6.0..31> Flash Security Word <0x00000000-0xFFFFFFFF>
;//   <h> Data Flash
;//     <o7.24..31> Data Flash Protection Byte <0x00-0xFF>
;//     <o7.16..23> Data Flash SUPV Access Byte <0x00-0xFF>
;//     <o7.8..15> Data Flash DATA Access Byte <0x00-0xFF>
;//   </h>
;// </e>
SEC_SETUP       EQU     1

SEC_WORD0_Val   EQU     0xFFFFFFFF
SEC_WORD1_Val   EQU     0xFFFFFFFF
SEC_WORD2_Val   EQU     0xFFFFFFFF
SEC_WORD3_Val   EQU     0x00000000
SEC_WORD4_Val   EQU     0xFFFFFFFF
SEC_WORD5_Val   EQU     0x00000002
SEC_WORD6_Val   EQU     0xFFFFFF00


                PRESERVE8


                ; Import Common IRQ Handler Address
                EXTERN  IRQ_Handler[WEAK]


; Area Definition and Entry Point
;  Startup Code must be linked first at Address at which it expects to run.


                AREA    RESET, CODE, READONLY
                ARM


; Exception Vectors
;  Mapped to Address 0.
;  Absolute addressing mode must be used.
;  Dummy Handlers are implemented as infinite loops which can be modified.

Vectors         LDR     PC, Reset_Addr         
                LDR     PC, Undef_Addr
                LDR     PC, SWI_Addr
                LDR     PC, PAbt_Addr
                LDR     PC, DAbt_Addr
                NOP                            ; Reserved Vector 
                LDR     PC, IRQ_Addr
                LDR     PC, FIQ_Addr

Reset_Addr      DCD     Reset_Handler
Undef_Addr      DCD     Undef_Handler
SWI_Addr        DCD     SWI_Handler
PAbt_Addr       DCD     PAbt_Handler
DAbt_Addr       DCD     DAbt_Handler
                DCD     0                      ; Reserved Address 
IRQ_Addr        DCD     IRQ_Handler
FIQ_Addr        DCD     FIQ_Handler

Undef_Handler   B       Undef_Handler
SWI_Handler     B       SWI_Handler
PAbt_Handler    B       PAbt_Handler
DAbt_Handler    B       DAbt_Handler
FIQ_Handler     B       FIQ_Handler


; Reset Handler

                EXPORT  Reset_Handler
Reset_Handler   


; Memory Remap (Remap: Flash -> 0x20000000, SRAM -> 0x00000000)
                IF      :DEF:RAM_MODE

                LDR     R0, =MCM_AAMR
                LDR     R1, [R0]
                BIC     R1, R1, #AAMR_MASK
                ORR     R1, R1, #AAMR_REMAP
                STR     R1, [R0]

                ENDIF


; Setup Clock

                IF      CLOCK_SETUP != 0
                LDR     R0, =CRG_BASE          

                LDR     R1, =CRG_SYNR_Val         ; Setup CRG_SYNR Register
                STRB    R1, [R0, #CRG_SYNR_OFS]

                LDR     R1, =CRG_REFDV_Val        ; Setup CRG_REFDV Register
                STRB    R1, [R0, #CRG_REFDV_OFS]

PLL_LOCKING     LDRB    R1, [R0, #CRG_CRGFLG_OFS] ; Wait for PLL to lock
                ANDS    R1, R1, #CRG_LOCK
                BEQ     PLL_LOCKING

                LDRB    R1, [R0, #CRG_CLKSEL_OFS] ; Select PLL as system clock
                ORR     R1, R1, #CRG_PLLEN
                STRB    R1, [R0, #CRG_CLKSEL_OFS]
                ENDIF

; External Memory Setup
                IF      EIM_SETUP != 0
                LDR     R0, =EIM_BASE          

                ; Setup Chip Select 0 functionality
                LDR     R1, =EIM_CSAR0_Val     ; Setup EIM_CSAR0 Register
                STRH    R1, [R0, #EIM_CSAR0_OFS]
                LDR     R1, =EIM_CSCR0_Val     ; Setup EIM_CSCR0 Register
                STRH    R1, [R0, #EIM_CSCR0_OFS]
                LDR     R1, =EIM_CSMR0_Val     ; Setup EIM_CSMR0 Register
                STR     R1, [R0, #EIM_CSMR0_OFS]

                ; Setup Chip Select 1 functionality
                LDR     R1, =EIM_CSAR1_Val     ; Setup EIM_CSAR1 Register
                STRH    R1, [R0, #EIM_CSAR1_OFS]
                LDR     R1, =EIM_CSCR1_Val     ; Setup EIM_CSCR1 Register
                STRH    R1, [R0, #EIM_CSCR1_OFS]
                LDR     R1, =EIM_CSMR1_Val     ; Setup EIM_CSMR1 Register
                STR     R1, [R0, #EIM_CSMR1_OFS]

                ; Setup Chip Select 2 functionality
                LDR     R1, =EIM_CSAR2_Val     ; Setup EIM_CSAR2 Register
                STRH    R1, [R0, #EIM_CSAR2_OFS]
                LDR     R1, =EIM_CSCR2_Val     ; Setup EIM_CSCR2 Register
                STRH    R1, [R0, #EIM_CSCR2_OFS]
                LDR     R1, =EIM_CSMR2_Val     ; Setup EIM_CSMR2 Register
                STR     R1, [R0, #EIM_CSMR2_OFS]
                ENDIF


; Setup Access Control
                IF      ACS_PRIV_SETUP != 0

                LDR     R0, =AIPS_BASE

                IF      MPRA_SETUP != 0
                LDR     R1, =MPRA_Val
                STR     R1, [R0, #AIPS_MPRA_OFS]
                ENDIF

                IF      PACRA_SETUP != 0
                LDR     R1, =PACRA_Val
                STR     R1, [R0, #AIPS_PACRA_OFS]
                ENDIF

                IF      PACRC_SETUP != 0
                LDR     R1, =PACRC_Val
                STR     R1, [R0, #AIPS_PACRC_OFS]
                ENDIF

                IF      OPACRA_SETUP != 0
                LDR     R1, =OPACRA_Val
                STR     R1, [R0, #AIPS_OPACRA_OFS]
                ENDIF

                IF      OPACRB_SETUP != 0
                LDR     R1, =OPACRB_Val
                STR     R1, [R0, #AIPS_OPACRB_OFS]
                ENDIF

                IF      OPACRC_SETUP != 0
                LDR     R1, =OPACRC_Val
                STR     R1, [R0, #AIPS_OPACRC_OFS]
                ENDIF

                IF      OPACRD_SETUP != 0
                LDR     R1, =OPACRD_Val
                STR     R1, [R0, #AIPS_OPACRD_OFS]
                ENDIF

                IF      OPACRE_SETUP != 0
                LDR     R1, =OPACRE_Val
                STR     R1, [R0, #AIPS_OPACRE_OFS]
                ENDIF

                ENDIF


; Initialise Interrupt System
;  ...


; Setup Stack for each mode

                LDR     R0, =Stack_Top

;  Enter Undefined Instruction Mode and set its Stack Pointer
                MSR     CPSR_c, #Mode_UND:OR:I_Bit:OR:F_Bit
                MOV     SP, R0
                SUB     R0, R0, #UND_Stack_Size

;  Enter Abort Mode and set its Stack Pointer
                MSR     CPSR_c, #Mode_ABT:OR:I_Bit:OR:F_Bit
                MOV     SP, R0
                SUB     R0, R0, #ABT_Stack_Size

;  Enter FIQ Mode and set its Stack Pointer
                MSR     CPSR_c, #Mode_FIQ:OR:I_Bit:OR:F_Bit
                MOV     SP, R0
                SUB     R0, R0, #FIQ_Stack_Size

;  Enter IRQ Mode and set its Stack Pointer
                MSR     CPSR_c, #Mode_IRQ:OR:I_Bit:OR:F_Bit
                MOV     SP, R0
                SUB     R0, R0, #IRQ_Stack_Size

;  Enter Supervisor Mode and set its Stack Pointer
                MSR     CPSR_c, #Mode_SVC:OR:I_Bit:OR:F_Bit
                MOV     SP, R0
                SUB     R0, R0, #SVC_Stack_Size

;  Enter User Mode and set its Stack Pointer
                MSR     CPSR_c, #Mode_USR
                MOV     SP, R0
                SUB     SL, SP, #USR_Stack_Size

; Enter the C code

                IMPORT  __main
                LDR     R0, =__main
                BX      R0


; Security Configuration

                IF      SEC_SETUP != 0

                LTORG
                SPACE   (0x400-(.-Vectors))

Security        DCD     SEC_WORD0_Val   ; Backdoor Comparison Key, word 1
                DCD     SEC_WORD1_Val   ; Backdoor Comparison Key, word 2
                DCD     SEC_WORD2_Val   ; Program Flash Protection Bytes
                DCD     SEC_WORD3_Val   ; Program Flash SUPV Access Bytes
                DCD     SEC_WORD4_Val   ; Program Flash DATA Access Bytes
                DCD     SEC_WORD5_Val   ; Flash Security Word            
                DCD     SEC_WORD6_Val   ; Data Flash Options             

                ENDIF

; User Initial Stack & Heap
                AREA    |.text|, CODE, READONLY

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + USR_Stack_Size)
                LDR     R2, = (Heap_Mem +      Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR


                END

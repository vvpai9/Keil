;/*****************************************************************************/
;/* TMPM330.s: Startup file for Toshiba TMPM330 device series                 */
;/*****************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                          */
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2008 Keil Software. All rights reserved.                    */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


;// <h> Stack Configuration
;//   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
;// </h>

Stack_Size      EQU     0x00000200

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


;// <h> Heap Configuration
;//   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
;// </h>

Heap_Size       EQU     0x00000000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     MemManage_Handler         ; MPU Fault Handler
                DCD     BusFault_Handler          ; Bus Fault Handler
                DCD     UsageFault_Handler        ; Usage Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     DebugMon_Handler          ; Debug Monitor Handler
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                ; External Interrupts
                DCD     INT0_Handler              ; Interrupt Pin INT0
                DCD     INT1_Handler              ; Interrupt Pin INT1
                DCD     INT2_Handler              ; Interrupt Pin INT2
                DCD     INT3_Handler              ; Interrupt Pin INT3
                DCD     INT4_Handler              ; Interrupt Pin INT4
                DCD     INT5_Handler              ; Interrupt Pin INT5
                DCD     INTRX0_Handler            ; Serial Reception (Ch 0)
                DCD     INTTX0_Handler            ; Serial Transmit (Ch 0)
                DCD     INTRX1_Handler            ; Serial Reception (Ch 1)
                DCD     INTTX1_Handler            ; Serial Transmit (Ch 1)
                DCD     INTSBI0_Handler           ; Serial Bus Interface 0
                DCD     INTSBI1_Handler           ; Serial Bus Interface 1
                DCD     INTCECRX_Handler          ; CEC Reception
                DCD     INTCECTX_Handler          ; CEC Transmission
                DCD     INTRMCRX0_Handler         ; Remote Control Reception 0
                DCD     INTADHP_Handler           ; AD Conversion Complete High. Priority
                DCD     INTADM0_Handler           ; AD Conversion Monitor 0
                DCD     INTADM1_Handler           ; AD Conversion Monitor 1
                DCD     INTTB0_Handler            ; TMRB Match Detection 0
                DCD     INTTB1_Handler            ; TMRB Match Detection 1
                DCD     INTTB2_Handler            ; TMRB Match Detection 2
                DCD     INTTB3_Handler            ; TMRB Match Detection 3
                DCD     INTTB4_Handler            ; TMRB Match Detection 4
                DCD     INTTB5_Handler            ; TMRB Match Detection 5
                DCD     INTTB6_Handler            ; TMRB Match Detection 6
                DCD     INTRTC_Handler            ; Real Time Clock
                DCD     INTCAP00_Handler          ; TMRB Input Capture 00
                DCD     INTCAP01_Handler          ; TMRB Input Capture 01
                DCD     INTCAP10_Handler          ; TMRB Input Capture 10
                DCD     INTCAP11_Handler          ; TMRB Input Capture 11
                DCD     INTCAP50_Handler          ; TMRB Input Capture 50
                DCD     INTCAP51_Handler          ; TMRB Input Capture 51
                DCD     INTCAP60_Handler          ; TMRB Input Capture 60
                DCD     INTCAP61_Handler          ; TMRB Input Capture 61
                DCD     INT6_Handler              ; Interrupt Pin INT6
                DCD     INT7_Handler              ; Interrupt Pin INT7 
                DCD     INTRX2_Handler            ; Serial Reception (Ch 2)
                DCD     INTTX2_Handler            ; Serial Transmit (Ch 2)
                DCD     INTSBI2_Handler           ; Serial Bus Interface 2
                DCD     INTRMCRX1_Handler         ; Remote Control Reception 1
                DCD     INTTB7_Handler            ; TMRB Match Detection 7
                DCD     INTTB8_Handler            ; TMRB Match Detection 8
                DCD     INTTB9_Handler            ; TMRB Match Detection 9
                DCD     INTCAP20_Handler          ; TMRB Input Capture 20
                DCD     INTCAP21_Handler          ; TMRB Input Capture 21
                DCD     INTCAP30_Handler          ; TMRB Input Capture 30
                DCD     INTCAP31_Handler          ; TMRB Input Capture 31
                DCD     INTCAP40_Handler          ; TMRB Input Capture 40
                DCD     INTCAP41_Handler          ; TMRB Input Capture 41
                DCD     INTAD_Handler             ; AD Conversion Complete


                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  __main
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)                

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler          [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler        [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler          [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  INT0_Handler              [WEAK]
                EXPORT  INT1_Handler              [WEAK]
                EXPORT  INT2_Handler              [WEAK]
                EXPORT  INT3_Handler              [WEAK]
                EXPORT  INT4_Handler              [WEAK]
                EXPORT  INT5_Handler              [WEAK]
                EXPORT  INTRX0_Handler            [WEAK]
                EXPORT  INTTX0_Handler            [WEAK]
                EXPORT  INTRX1_Handler            [WEAK]
                EXPORT  INTTX1_Handler            [WEAK]
                EXPORT  INTSBI0_Handler           [WEAK]
                EXPORT  INTSBI1_Handler           [WEAK]
                EXPORT  INTCECRX_Handler          [WEAK]
                EXPORT  INTCECTX_Handler          [WEAK]
                EXPORT  INTRMCRX0_Handler         [WEAK]
                EXPORT  INTADHP_Handler           [WEAK]
                EXPORT  INTADM0_Handler           [WEAK]
                EXPORT  INTADM1_Handler           [WEAK]
                EXPORT  INTTB0_Handler            [WEAK]
                EXPORT  INTTB1_Handler            [WEAK]
                EXPORT  INTTB2_Handler            [WEAK]
                EXPORT  INTTB3_Handler            [WEAK]
                EXPORT  INTTB4_Handler            [WEAK]
                EXPORT  INTTB5_Handler            [WEAK]
                EXPORT  INTTB6_Handler            [WEAK]
                EXPORT  INTRTC_Handler            [WEAK]
                EXPORT  INTCAP00_Handler          [WEAK]
                EXPORT  INTCAP01_Handler          [WEAK]
                EXPORT  INTCAP10_Handler          [WEAK]
                EXPORT  INTCAP11_Handler          [WEAK]
                EXPORT  INTCAP50_Handler          [WEAK]
                EXPORT  INTCAP51_Handler          [WEAK]
                EXPORT  INTCAP60_Handler          [WEAK]
                EXPORT  INTCAP61_Handler          [WEAK]
                EXPORT  INT6_Handler              [WEAK]
                EXPORT  INT7_Handler              [WEAK]
                EXPORT  INTRX2_Handler            [WEAK]
                EXPORT  INTTX2_Handler            [WEAK]
                EXPORT  INTSBI2_Handler           [WEAK]
                EXPORT  INTRMCRX1_Handler         [WEAK]
                EXPORT  INTTB7_Handler            [WEAK]
                EXPORT  INTTB8_Handler            [WEAK]
                EXPORT  INTTB9_Handler            [WEAK]
                EXPORT  INTCAP20_Handler          [WEAK]
                EXPORT  INTCAP21_Handler          [WEAK]
                EXPORT  INTCAP30_Handler          [WEAK]
                EXPORT  INTCAP31_Handler          [WEAK]
                EXPORT  INTCAP40_Handler          [WEAK]
                EXPORT  INTCAP41_Handler          [WEAK]
                EXPORT  INTAD_Handler             [WEAK]

INT0_Handler
INT1_Handler
INT2_Handler
INT3_Handler
INT4_Handler
INT5_Handler
INTRX0_Handler
INTTX0_Handler
INTRX1_Handler
INTTX1_Handler
INTSBI0_Handler
INTSBI1_Handler
INTCECRX_Handler
INTCECTX_Handler
INTRMCRX0_Handler
INTADHP_Handler
INTADM0_Handler
INTADM1_Handler
INTTB0_Handler
INTTB1_Handler
INTTB2_Handler
INTTB3_Handler
INTTB4_Handler
INTTB5_Handler
INTTB6_Handler
INTRTC_Handler
INTCAP00_Handler
INTCAP01_Handler
INTCAP10_Handler
INTCAP11_Handler
INTCAP50_Handler
INTCAP51_Handler
INTCAP60_Handler
INTCAP61_Handler
INT6_Handler
INT7_Handler
INTRX2_Handler
INTTX2_Handler
INTSBI2_Handler
INTRMCRX1_Handler
INTTB7_Handler
INTTB8_Handler
INTTB9_Handler
INTCAP20_Handler
INTCAP21_Handler
INTCAP30_Handler
INTCAP31_Handler
INTCAP40_Handler
INTCAP41_Handler
INTAD_Handler

                B       .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB
                
                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit
                
                ELSE
                
                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF


                END

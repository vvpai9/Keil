;/*****************************************************************************
; * @file:    startup_A2FM3Fxxx.s
; * @purpose: CMSIS Cortex-M3 Core Device Startup File 
; *           for the Actel A2FM3F Device Series 
; * @version: V1.0
; * @date:    1. Sept. 2009
; *------- <<< Use Configuration Wizard in Context Menu >>> ------------------
; *
; * Copyright (C) 2009 ARM Limited. All rights reserved.
; * ARM Limited (ARM) is supplying this software for use with Cortex-M3 
; * processor based microcontrollers.  This file can be freely distributed 
; * within development tools that are supporting such ARM based processors. 
; *
; * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
; * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
; * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
; * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
; * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
; *
; *****************************************************************************/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000200

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

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

__Vectors       DCD     __initial_sp                  ; Top of Stack
                DCD     Reset_Handler                 ; Reset Handler
                DCD     NMI_Handler                   ; NMI Handler
                DCD     HardFault_Handler             ; Hard Fault Handler
                DCD     MemManage_Handler             ; MPU Fault Handler
                DCD     BusFault_Handler              ; Bus Fault Handler
                DCD     UsageFault_Handler            ; Usage Fault Handler
                DCD     0                             ; Reserved
                DCD     0                             ; Reserved
                DCD     0                             ; Reserved
                DCD     0                             ; Reserved
                DCD     SVC_Handler                   ; SVCall Handler
                DCD     DebugMon_Handler              ; Debug Monitor Handler
                DCD     0                             ; Reserved
                DCD     PendSV_Handler                ; PendSV Handler
                DCD     SysTick_Handler               ; SysTick Handler

                ; External Interrupts
                DCD     WdogWakeup_IRQHandler         ;   0: WatchDog wakeup interrupt
                DCD     BrownOut_1_5V_IRQHandler      ;   1: Supply dropped below 1.5V
                DCD     BrownOut_3_3V_IRQHandler      ;   2: Supply dropped below 1.5V
                DCD     RTC_Match_IRQHandler          ;   3: RTC match interrupt
                DCD     RTCIF_Pub_IRQHandler          ;   4: RTC interface push button interrupt
                DCD     EthernetMAC_IRQHandler        ;   5: Ethernet MAC interrupt
                DCD     IAP_IRQHandler                ;   6: In Application Programming (IAP) interrupt
                DCD     HINT0_IRQHandler              ;   7: eNVM0 operation completion interrupt
                DCD     HINT1_IRQHandler              ;   8: eNVM1 operation completion interrupt
                DCD     DMA_IRQHandler                ;   9: Peripheral DMA interrupt
                DCD     UART0_IRQHandler              ;  10: UART0 interrupt
                DCD     UART1_IRQHandler              ;  11: UART1 interrupt
                DCD     SPI0_IRQHandler               ;  12: SPI0 interrupt
                DCD     SPI1_IRQHandler               ;  13: SP1 interrupt
                DCD     I2C0_IRQHandler               ;  14: I2C0 interrupt
                DCD     I2C0_SMBAlert_IRQHandler      ;  15: I2C0 SMBus Alert interrupt
                DCD     I2C0_SMBus_IRQHandler         ;  16: I2C0 SMBus Suspend interrupt
                DCD     I2C1_IRQHandler               ;  17: I2C1 interrupt
                DCD     I2C1_SMBAlert_IRQHandler      ;  18: I2C1 SMBus Alert interrupt
                DCD     I2C1_SMBus_IRQHandler         ;  19: I2C1 SMBus Suspend interrupt
                DCD     Timer1_IRQHandler             ;  20: Timer1 interrupt
                DCD     Timer2_IRQHandler             ;  21: Timer2 interrupt
                DCD     PLL_Lock_IRQHandler           ;  22: PLL lock interrupt
                DCD     PLL_LockLost_IRQHandler       ;  23: PLL loss of lock interrupt
                DCD     CommError_IRQHandler          ;  24: Communications Matrix error interrupt
                DCD     Default_Handler               ;  25: Reserved
                DCD     Default_Handler               ;  26: Reserved
                DCD     Default_Handler               ;  27: Reserved
                DCD     Default_Handler               ;  28: Reserved
                DCD     Default_Handler               ;  29: Reserved
                DCD     Default_Handler               ;  30: Reserved
                DCD     F2H_IRQHandler                ;  31: FPGA fabric interrupt
                DCD     GPIO0_IRQHandler              ;  32: GPIO 0 interrupt
                DCD     GPIO1_IRQHandler              ;  33: GPIO 1 interrupt
                DCD     GPIO2_IRQHandler              ;  34: GPIO 2 interrupt
                DCD     GPIO3_IRQHandler              ;  35: GPIO 3 interrupt
                DCD     GPIO4_IRQHandler              ;  36: GPIO 4 interrupt
                DCD     GPIO5_IRQHandler              ;  37: GPIO 5 interrupt
                DCD     GPIO6_IRQHandler              ;  38: GPIO 6 interrupt
                DCD     GPIO7_IRQHandler              ;  39: GPIO 7 interrupt
                DCD     GPIO8_IRQHandler              ;  40: GPIO 8 interrupt
                DCD     GPIO9_IRQHandler              ;  41: GPIO 9 interrupt
                DCD     GPIO10_IRQHandler             ;  42: GPIO 10 interrupt
                DCD     GPIO11_IRQHandler             ;  43: GPIO 11 interrupt
                DCD     GPIO12_IRQHandler             ;  44: GPIO 12 interrupt
                DCD     GPIO13_IRQHandler             ;  45: GPIO 13 interrupt
                DCD     GPIO14_IRQHandler             ;  46: GPIO 14 interrupt
                DCD     GPIO15_IRQHandler             ;  47: GPIO 15 interrupt
                DCD     GPIO16_IRQHandler             ;  48: GPIO 16 interrupt
                DCD     GPIO17_IRQHandler             ;  49: GPIO 17 interrupt
                DCD     GPIO18_IRQHandler             ;  50: GPIO 18 interrupt
                DCD     GPIO19_IRQHandler             ;  51: GPIO 19 interrupt
                DCD     GPIO20_IRQHandler             ;  52: GPIO 20 interrupt
                DCD     GPIO21_IRQHandler             ;  53: GPIO 21 interrupt
                DCD     GPIO22_IRQHandler             ;  54: GPIO 22 interrupt
                DCD     GPIO23_IRQHandler             ;  55: GPIO 23 interrupt
                DCD     GPIO24_IRQHandler             ;  56: GPIO 24 interrupt
                DCD     GPIO25_IRQHandler             ;  57: GPIO 25 interrupt
                DCD     GPIO26_IRQHandler             ;  58: GPIO 26 interrupt
                DCD     GPIO27_IRQHandler             ;  59: GPIO 27 interrupt
                DCD     GPIO28_IRQHandler             ;  60: GPIO 28 interrupt
                DCD     GPIO29_IRQHandler             ;  61: GPIO 29 interrupt
                DCD     GPIO30_IRQHandler             ;  62: GPIO 30 interrupt
                DCD     GPIO31_IRQHandler             ;  63: GPIO 31 interrupt
                DCD     ACE_PC0_Flag0_IRQHandler      ;  64: ACE SSE program counter 0 flag 0 interrupt
                DCD     ACE_PC0_Flag1_IRQHandler      ;  65: ACE SSE program counter 0 flag 1 interrupt
                DCD     ACE_PC0_Flag2_IRQHandler      ;  66: ACE SSE program counter 0 flag 2 interrupt
                DCD     ACE_PC0_Flag3_IRQHandler      ;  67: ACE SSE program counter 0 flag 3 interrupt
                DCD     ACE_PC1_Flag0_IRQHandler      ;  68: ACE SSE program counter 1 flag 0 interrupt
                DCD     ACE_PC1_Flag1_IRQHandler      ;  69: ACE SSE program counter 1 flag 1 interrupt
                DCD     ACE_PC1_Flag2_IRQHandler      ;  70: ACE SSE program counter 1 flag 2 interrupt
                DCD     ACE_PC1_Flag3_IRQHandler      ;  71: ACE SSE program counter 1 flag 3 interrupt
                DCD     ACE_PC2_Flag0_IRQHandler      ;  72: ACE SSE program counter 2 flag 0 interrupt
                DCD     ACE_PC2_Flag1_IRQHandler      ;  73: ACE SSE program counter 2 flag 1 interrupt
                DCD     ACE_PC2_Flag2_IRQHandler      ;  74: ACE SSE program counter 2 flag 2 interrupt
                DCD     ACE_PC2_Flag3_IRQHandler      ;  75: ACE SSE program counter 2 flag 3 interrupt
                DCD     ACE_ADC0_DataValid_IRQHandler ;  76: ACE ADC0 data valid interrupt
                DCD     ACE_ADC1_DataValid_IRQHandler ;  77: ACE ADC1 data valid interrupt
                DCD     ACE_ADC2_DataValid_IRQHandler ;  78: ACE ADC2 data valid interrupt
                DCD     ACE_ADC0_CalDone_IRQHandler   ;  79: ACE ADC0 calibration done interrupt
                DCD     ACE_ADC1_CalDone_IRQHandler   ;  80: ACE ADC1 calibration done interrupt
                DCD     ACE_ADC2_CalDone_IRQHandler   ;  81: ACE ADC2 calibration done interrupt
                DCD     ACE_ADC0_CalStart_IRQHandler  ;  82: ACE ADC0 calibration start interrupt
                DCD     ACE_ADC1_CalStart_IRQHandler  ;  83: ACE ADC1 calibration start interrupt
                DCD     ACE_ADC2_CalStart_IRQHandler  ;  84: ACE ADC2 calibration start interrupt
                DCD     ACE_Comp0_Fall_IRQHandler     ;  85: ACE comparator 0 falling under reference interrupt
                DCD     ACE_Comp1_Fall_IRQHandler     ;  86: ACE comparator 1 falling under reference interrupt
                DCD     ACE_Comp2_Fall_IRQHandler     ;  87: ACE comparator 2 falling under reference interrupt
                DCD     ACE_Comp3_Fall_IRQHandler     ;  88: ACE comparator 3 falling under reference interrupt
                DCD     ACE_Comp4_Fall_IRQHandler     ;  89: ACE comparator 4 falling under reference interrupt
                DCD     ACE_Comp5_Fall_IRQHandler     ;  90: ACE comparator 5 falling under reference interrupt
                DCD     ACE_Comp6_Fall_IRQHandler     ;  91: ACE comparator 6 falling under reference interrupt
                DCD     ACE_Comp7_Fall_IRQHandler     ;  92: ACE comparator 7 falling under reference interrupt
                DCD     ACE_Comp8_Fall_IRQHandler     ;  93: ACE comparator 8 falling under reference interrupt
                DCD     ACE_Comp9_Fall_IRQHandler     ;  94: ACE comparator 9 falling under reference interrupt
                DCD     ACE_Comp10_Fall_IRQHandler    ;  95: ACE comparator 10 falling under reference interrupt
                DCD     ACE_Comp11_Fall_IRQHandler    ;  96: ACE comparator 11 falling under reference interrupt
                DCD     ACE_Comp0_Rise_IRQHandler     ;  97: ACE comparator 0 rising over reference interrupt
                DCD     ACE_Comp1_Rise_IRQHandler     ;  98: ACE comparator 1 rising over reference interrupt
                DCD     ACE_Comp2_Rise_IRQHandler     ;  99: ACE comparator 2 rising over reference interrupt
                DCD     ACE_Comp3_Rise_IRQHandler     ; 100: ACE comparator 3 rising over reference interrupt
                DCD     ACE_Comp4_Rise_IRQHandler     ; 101: ACE comparator 4 rising over reference interrupt
                DCD     ACE_Comp5_Rise_IRQHandler     ; 102: ACE comparator 5 rising over reference interrupt
                DCD     ACE_Comp6_Rise_IRQHandler     ; 103: ACE comparator 6 rising over reference interrupt
                DCD     ACE_Comp7_Rise_IRQHandler     ; 104: ACE comparator 7 rising over reference interrupt
                DCD     ACE_Comp8_Rise_IRQHandler     ; 105: ACE comparator 8 rising over reference interrupt
                DCD     ACE_Comp9_Rise_IRQHandler     ; 106: ACE comparator 9 rising over reference interrupt
                DCD     ACE_Comp10_Rise_IRQHandler    ; 107: ACE comparator 10 rising over reference interrupt
                DCD     ACE_Comp11_Rise_IRQHandler    ; 108: ACE comparator 11 rising over reference interrupt
                DCD     ACE_ADC0_FifoFull_IRQHandler  ; 109: ACE ADC0 FIFO full interrupt
                DCD     ACE_ADC0_FifoAFull_IRQHandler ; 110: ACE ADC0 FIFO almost full interrupt
                DCD     ACE_ADC0_FifoEmpty_IRQHandler ; 111: ACE ADC0 FIFO empty interrupt
                DCD     ACE_ADC1_FifoFull_IRQHandler  ; 112: ACE ADC1 FIFO full interrupt
                DCD     ACE_ADC1_FifoAFull_IRQHandler ; 113: ACE ADC1 FIFO almost full interrupt
                DCD     ACE_ADC1_FifoEmpty_IRQHandler ; 114: ACE ADC1 FIFO empty interrupt
                DCD     ACE_ADC2_FifoFull_IRQHandler  ; 115: ACE ADC2 FIFO full interrupt
                DCD     ACE_ADC2_FifoAFull_IRQHandler ; 116: ACE ADC2 FIFO almost full interrupt
                DCD     ACE_ADC2_FifoEmpty_IRQHandler ; 117: ACE ADC2 FIFO empty interrupt
                DCD     ACE_PPE_Flag0_IRQHandler      ; 118: ACE post processing engine flag 0 interrupt
                DCD     ACE_PPE_Flag1_IRQHandler      ; 119: ACE post processing engine flag 1 interrupt
                DCD     ACE_PPE_Flag2_IRQHandler      ; 120: ACE post processing engine flag 2 interrupt
                DCD     ACE_PPE_Flag3_IRQHandler      ; 121: ACE post processing engine flag 3 interrupt
                DCD     ACE_PPE_Flag4_IRQHandler      ; 122: ACE post processing engine flag 4 interrupt
                DCD     ACE_PPE_Flag5_IRQHandler      ; 123: ACE post processing engine flag 5 interrupt
                DCD     ACE_PPE_Flag6_IRQHandler      ; 124: ACE post processing engine flag 6 interrupt
                DCD     ACE_PPE_Flag7_IRQHandler      ; 125: ACE post processing engine flag 7 interrupt
                DCD     ACE_PPE_Flag8_IRQHandler      ; 126: ACE post processing engine flag 8 interrupt
                DCD     ACE_PPE_Flag9_IRQHandler      ; 127: ACE post processing engine flag 9 interrupt
                DCD     ACE_PPE_Flag10_IRQHandler     ; 128: ACE post processing engine flag 10 interrupt
                DCD     ACE_PPE_Flag11_IRQHandler     ; 129: ACE post processing engine flag 11 interrupt
                DCD     ACE_PPE_Flag12_IRQHandler     ; 130: ACE post processing engine flag 12 interrupt
                DCD     ACE_PPE_Flag13_IRQHandler     ; 131: ACE post processing engine flag 13 interrupt
                DCD     ACE_PPE_Flag14_IRQHandler     ; 132: ACE post processing engine flag 14 interrupt
                DCD     ACE_PPE_Flag15_IRQHandler     ; 133: ACE post processing engine flag 15 interrupt
                DCD     ACE_PPE_Flag16_IRQHandler     ; 134: ACE post processing engine flag 16 interrupt
                DCD     ACE_PPE_Flag17_IRQHandler     ; 135: ACE post processing engine flag 17 interrupt
                DCD     ACE_PPE_Flag18_IRQHandler     ; 136: ACE post processing engine flag 18 interrupt
                DCD     ACE_PPE_Flag19_IRQHandler     ; 137: ACE post processing engine flag 19 interrupt
                DCD     ACE_PPE_Flag20_IRQHandler     ; 138: ACE post processing engine flag 20 interrupt
                DCD     ACE_PPE_Flag21_IRQHandler     ; 139: ACE post processing engine flag 21 interrupt
                DCD     ACE_PPE_Flag22_IRQHandler     ; 140: ACE post processing engine flag 22 interrupt
                DCD     ACE_PPE_Flag23_IRQHandler     ; 141: ACE post processing engine flag 23 interrupt
                DCD     ACE_PPE_Flag24_IRQHandler     ; 142: ACE post processing engine flag 24 interrupt
                DCD     ACE_PPE_Flag25_IRQHandler     ; 143: ACE post processing engine flag 25 interrupt
                DCD     ACE_PPE_Flag26_IRQHandler     ; 144: ACE post processing engine flag 26 interrupt
                DCD     ACE_PPE_Flag27_IRQHandler     ; 145: ACE post processing engine flag 27 interrupt
                DCD     ACE_PPE_Flag28_IRQHandler     ; 146: ACE post processing engine flag 28 interrupt
                DCD     ACE_PPE_Flag29_IRQHandler     ; 147: ACE post processing engine flag 29 interrupt
                DCD     ACE_PPE_Flag30_IRQHandler     ; 148: ACE post processing engine flag 30 interrupt
                DCD     ACE_PPE_Flag31_IRQHandler     ; 149: ACE post processing engine flag 31 interrupt
                        
                        
                AREA    |.text|, CODE, READONLY
                        
                        
; Reset Handler         
                        
Reset_Handler   PROC    
                EXPORT  Reset_Handler                 [WEAK]
                IMPORT  __main
                LDR     R0, =__main
                BX      R0
                ENDP    
                        
                        
; Dummy Exception Handlers (infinite loops which can be modified)                
                        
NMI_Handler     PROC
                EXPORT  NMI_Handler                   [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler             [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler             [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler              [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler            [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler                   [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler              [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler                [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler               [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  WdogWakeup_IRQHandler         [WEAK]
                EXPORT  BrownOut_1_5V_IRQHandler      [WEAK]
                EXPORT  BrownOut_3_3V_IRQHandler      [WEAK]
                EXPORT  RTC_Match_IRQHandler          [WEAK]
                EXPORT  RTCIF_Pub_IRQHandler          [WEAK]
                EXPORT  EthernetMAC_IRQHandler        [WEAK]
                EXPORT  IAP_IRQHandler                [WEAK]
                EXPORT  HINT0_IRQHandler              [WEAK]
                EXPORT  HINT1_IRQHandler              [WEAK]
                EXPORT  DMA_IRQHandler                [WEAK]
                EXPORT  UART0_IRQHandler              [WEAK]
                EXPORT  UART1_IRQHandler              [WEAK]
                EXPORT  SPI0_IRQHandler               [WEAK]
                EXPORT  SPI1_IRQHandler               [WEAK]
                EXPORT  I2C0_IRQHandler               [WEAK]
                EXPORT  I2C0_SMBAlert_IRQHandler      [WEAK]
                EXPORT  I2C0_SMBus_IRQHandler         [WEAK]
                EXPORT  I2C1_IRQHandler               [WEAK]
                EXPORT  I2C1_SMBAlert_IRQHandler      [WEAK]
                EXPORT  I2C1_SMBus_IRQHandler         [WEAK]
                EXPORT  Timer1_IRQHandler             [WEAK]
                EXPORT  Timer2_IRQHandler             [WEAK]
                EXPORT  PLL_Lock_IRQHandler           [WEAK]
                EXPORT  PLL_LockLost_IRQHandler       [WEAK]
                EXPORT  CommError_IRQHandler          [WEAK]
                EXPORT  F2H_IRQHandler                [WEAK]
                EXPORT  GPIO0_IRQHandler              [WEAK]
                EXPORT  GPIO1_IRQHandler              [WEAK]
                EXPORT  GPIO2_IRQHandler              [WEAK]
                EXPORT  GPIO3_IRQHandler              [WEAK]
                EXPORT  GPIO4_IRQHandler              [WEAK]
                EXPORT  GPIO5_IRQHandler              [WEAK]
                EXPORT  GPIO6_IRQHandler              [WEAK]
                EXPORT  GPIO7_IRQHandler              [WEAK]
                EXPORT  GPIO8_IRQHandler              [WEAK]
                EXPORT  GPIO9_IRQHandler              [WEAK]
                EXPORT  GPIO10_IRQHandler             [WEAK]
                EXPORT  GPIO11_IRQHandler             [WEAK]
                EXPORT  GPIO12_IRQHandler             [WEAK]
                EXPORT  GPIO13_IRQHandler             [WEAK]
                EXPORT  GPIO14_IRQHandler             [WEAK]
                EXPORT  GPIO15_IRQHandler             [WEAK]
                EXPORT  GPIO16_IRQHandler             [WEAK]
                EXPORT  GPIO17_IRQHandler             [WEAK]
                EXPORT  GPIO18_IRQHandler             [WEAK]
                EXPORT  GPIO19_IRQHandler             [WEAK]
                EXPORT  GPIO20_IRQHandler             [WEAK]
                EXPORT  GPIO21_IRQHandler             [WEAK]
                EXPORT  GPIO22_IRQHandler             [WEAK]
                EXPORT  GPIO23_IRQHandler             [WEAK]
                EXPORT  GPIO24_IRQHandler             [WEAK]
                EXPORT  GPIO25_IRQHandler             [WEAK]
                EXPORT  GPIO26_IRQHandler             [WEAK]
                EXPORT  GPIO27_IRQHandler             [WEAK]
                EXPORT  GPIO28_IRQHandler             [WEAK]
                EXPORT  GPIO29_IRQHandler             [WEAK]
                EXPORT  GPIO30_IRQHandler             [WEAK]
                EXPORT  GPIO31_IRQHandler             [WEAK]
                EXPORT  ACE_PC0_Flag0_IRQHandler      [WEAK]
                EXPORT  ACE_PC0_Flag1_IRQHandler      [WEAK]
                EXPORT  ACE_PC0_Flag2_IRQHandler      [WEAK]
                EXPORT  ACE_PC0_Flag3_IRQHandler      [WEAK]
                EXPORT  ACE_PC1_Flag0_IRQHandler      [WEAK]
                EXPORT  ACE_PC1_Flag1_IRQHandler      [WEAK]
                EXPORT  ACE_PC1_Flag2_IRQHandler      [WEAK]
                EXPORT  ACE_PC1_Flag3_IRQHandler      [WEAK]
                EXPORT  ACE_PC2_Flag0_IRQHandler      [WEAK]
                EXPORT  ACE_PC2_Flag1_IRQHandler      [WEAK]
                EXPORT  ACE_PC2_Flag2_IRQHandler      [WEAK]
                EXPORT  ACE_PC2_Flag3_IRQHandler      [WEAK]
                EXPORT  ACE_ADC0_DataValid_IRQHandler [WEAK]
                EXPORT  ACE_ADC1_DataValid_IRQHandler [WEAK]
                EXPORT  ACE_ADC2_DataValid_IRQHandler [WEAK]
                EXPORT  ACE_ADC0_CalDone_IRQHandler   [WEAK]
                EXPORT  ACE_ADC1_CalDone_IRQHandler   [WEAK]
                EXPORT  ACE_ADC2_CalDone_IRQHandler   [WEAK]
                EXPORT  ACE_ADC0_CalStart_IRQHandler  [WEAK]
                EXPORT  ACE_ADC1_CalStart_IRQHandler  [WEAK]
                EXPORT  ACE_ADC2_CalStart_IRQHandler  [WEAK]
                EXPORT  ACE_Comp0_Fall_IRQHandler     [WEAK]
                EXPORT  ACE_Comp1_Fall_IRQHandler     [WEAK]
                EXPORT  ACE_Comp2_Fall_IRQHandler     [WEAK]
                EXPORT  ACE_Comp3_Fall_IRQHandler     [WEAK]
                EXPORT  ACE_Comp4_Fall_IRQHandler     [WEAK]
                EXPORT  ACE_Comp5_Fall_IRQHandler     [WEAK]
                EXPORT  ACE_Comp6_Fall_IRQHandler     [WEAK]
                EXPORT  ACE_Comp7_Fall_IRQHandler     [WEAK]
                EXPORT  ACE_Comp8_Fall_IRQHandler     [WEAK]
                EXPORT  ACE_Comp9_Fall_IRQHandler     [WEAK]
                EXPORT  ACE_Comp10_Fall_IRQHandler    [WEAK]
                EXPORT  ACE_Comp11_Fall_IRQHandler    [WEAK]
                EXPORT  ACE_Comp0_Rise_IRQHandler     [WEAK]
                EXPORT  ACE_Comp1_Rise_IRQHandler     [WEAK]
                EXPORT  ACE_Comp2_Rise_IRQHandler     [WEAK]
                EXPORT  ACE_Comp3_Rise_IRQHandler     [WEAK]
                EXPORT  ACE_Comp4_Rise_IRQHandler     [WEAK]
                EXPORT  ACE_Comp5_Rise_IRQHandler     [WEAK]
                EXPORT  ACE_Comp6_Rise_IRQHandler     [WEAK]
                EXPORT  ACE_Comp7_Rise_IRQHandler     [WEAK]
                EXPORT  ACE_Comp8_Rise_IRQHandler     [WEAK]
                EXPORT  ACE_Comp9_Rise_IRQHandler     [WEAK]
                EXPORT  ACE_Comp10_Rise_IRQHandler    [WEAK]
                EXPORT  ACE_Comp11_Rise_IRQHandler    [WEAK]
                EXPORT  ACE_ADC0_FifoFull_IRQHandler  [WEAK]
                EXPORT  ACE_ADC0_FifoAFull_IRQHandler [WEAK]
                EXPORT  ACE_ADC0_FifoEmpty_IRQHandler [WEAK]
                EXPORT  ACE_ADC1_FifoFull_IRQHandler  [WEAK]
                EXPORT  ACE_ADC1_FifoAFull_IRQHandler [WEAK]
                EXPORT  ACE_ADC1_FifoEmpty_IRQHandler [WEAK]
                EXPORT  ACE_ADC2_FifoFull_IRQHandler  [WEAK]
                EXPORT  ACE_ADC2_FifoAFull_IRQHandler [WEAK]
                EXPORT  ACE_ADC2_FifoEmpty_IRQHandler [WEAK]
                EXPORT  ACE_PPE_Flag0_IRQHandler      [WEAK]
                EXPORT  ACE_PPE_Flag1_IRQHandler      [WEAK]
                EXPORT  ACE_PPE_Flag2_IRQHandler      [WEAK]
                EXPORT  ACE_PPE_Flag3_IRQHandler      [WEAK]
                EXPORT  ACE_PPE_Flag4_IRQHandler      [WEAK]
                EXPORT  ACE_PPE_Flag5_IRQHandler      [WEAK]
                EXPORT  ACE_PPE_Flag6_IRQHandler      [WEAK]
                EXPORT  ACE_PPE_Flag7_IRQHandler      [WEAK]
                EXPORT  ACE_PPE_Flag8_IRQHandler      [WEAK]
                EXPORT  ACE_PPE_Flag9_IRQHandler      [WEAK]
                EXPORT  ACE_PPE_Flag10_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag11_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag12_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag13_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag14_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag15_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag16_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag17_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag18_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag19_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag20_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag21_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag22_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag23_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag24_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag25_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag26_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag27_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag28_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag29_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag30_IRQHandler     [WEAK]
                EXPORT  ACE_PPE_Flag31_IRQHandler     [WEAK]

WdogWakeup_IRQHandler
BrownOut_1_5V_IRQHandler
BrownOut_3_3V_IRQHandler
RTC_Match_IRQHandler
RTCIF_Pub_IRQHandler
EthernetMAC_IRQHandler
IAP_IRQHandler
HINT0_IRQHandler
HINT1_IRQHandler
DMA_IRQHandler
UART0_IRQHandler
UART1_IRQHandler
SPI0_IRQHandler
SPI1_IRQHandler
I2C0_IRQHandler
I2C0_SMBAlert_IRQHandler
I2C0_SMBus_IRQHandler
I2C1_IRQHandler
I2C1_SMBAlert_IRQHandler
I2C1_SMBus_IRQHandler
Timer1_IRQHandler
Timer2_IRQHandler
PLL_Lock_IRQHandler
PLL_LockLost_IRQHandler
CommError_IRQHandler
F2H_IRQHandler
GPIO0_IRQHandler
GPIO1_IRQHandler
GPIO2_IRQHandler
GPIO3_IRQHandler
GPIO4_IRQHandler
GPIO5_IRQHandler
GPIO6_IRQHandler
GPIO7_IRQHandler
GPIO8_IRQHandler
GPIO9_IRQHandler
GPIO10_IRQHandler
GPIO11_IRQHandler
GPIO12_IRQHandler
GPIO13_IRQHandler
GPIO14_IRQHandler
GPIO15_IRQHandler
GPIO16_IRQHandler
GPIO17_IRQHandler
GPIO18_IRQHandler
GPIO19_IRQHandler
GPIO20_IRQHandler
GPIO21_IRQHandler
GPIO22_IRQHandler
GPIO23_IRQHandler
GPIO24_IRQHandler
GPIO25_IRQHandler
GPIO26_IRQHandler
GPIO27_IRQHandler
GPIO28_IRQHandler
GPIO29_IRQHandler
GPIO30_IRQHandler
GPIO31_IRQHandler
ACE_PC0_Flag0_IRQHandler
ACE_PC0_Flag1_IRQHandler
ACE_PC0_Flag2_IRQHandler
ACE_PC0_Flag3_IRQHandler
ACE_PC1_Flag0_IRQHandler
ACE_PC1_Flag1_IRQHandler
ACE_PC1_Flag2_IRQHandler
ACE_PC1_Flag3_IRQHandler
ACE_PC2_Flag0_IRQHandler
ACE_PC2_Flag1_IRQHandler
ACE_PC2_Flag2_IRQHandler
ACE_PC2_Flag3_IRQHandler
ACE_ADC0_DataValid_IRQHandler
ACE_ADC1_DataValid_IRQHandler
ACE_ADC2_DataValid_IRQHandler
ACE_ADC0_CalDone_IRQHandler
ACE_ADC1_CalDone_IRQHandler
ACE_ADC2_CalDone_IRQHandler
ACE_ADC0_CalStart_IRQHandler
ACE_ADC1_CalStart_IRQHandler
ACE_ADC2_CalStart_IRQHandler
ACE_Comp0_Fall_IRQHandler
ACE_Comp1_Fall_IRQHandler
ACE_Comp2_Fall_IRQHandler
ACE_Comp3_Fall_IRQHandler
ACE_Comp4_Fall_IRQHandler
ACE_Comp5_Fall_IRQHandler
ACE_Comp6_Fall_IRQHandler
ACE_Comp7_Fall_IRQHandler
ACE_Comp8_Fall_IRQHandler
ACE_Comp9_Fall_IRQHandler
ACE_Comp10_Fall_IRQHandler
ACE_Comp11_Fall_IRQHandler
ACE_Comp0_Rise_IRQHandler
ACE_Comp1_Rise_IRQHandler
ACE_Comp2_Rise_IRQHandler
ACE_Comp3_Rise_IRQHandler
ACE_Comp4_Rise_IRQHandler
ACE_Comp5_Rise_IRQHandler
ACE_Comp6_Rise_IRQHandler
ACE_Comp7_Rise_IRQHandler
ACE_Comp8_Rise_IRQHandler
ACE_Comp9_Rise_IRQHandler
ACE_Comp10_Rise_IRQHandler
ACE_Comp11_Rise_IRQHandler
ACE_ADC0_FifoFull_IRQHandler
ACE_ADC0_FifoAFull_IRQHandler
ACE_ADC0_FifoEmpty_IRQHandler
ACE_ADC1_FifoFull_IRQHandler
ACE_ADC1_FifoAFull_IRQHandler
ACE_ADC1_FifoEmpty_IRQHandler
ACE_ADC2_FifoFull_IRQHandler
ACE_ADC2_FifoAFull_IRQHandler
ACE_ADC2_FifoEmpty_IRQHandler
ACE_PPE_Flag0_IRQHandler
ACE_PPE_Flag1_IRQHandler
ACE_PPE_Flag2_IRQHandler
ACE_PPE_Flag3_IRQHandler
ACE_PPE_Flag4_IRQHandler
ACE_PPE_Flag5_IRQHandler
ACE_PPE_Flag6_IRQHandler
ACE_PPE_Flag7_IRQHandler
ACE_PPE_Flag8_IRQHandler
ACE_PPE_Flag9_IRQHandler
ACE_PPE_Flag10_IRQHandler
ACE_PPE_Flag11_IRQHandler
ACE_PPE_Flag12_IRQHandler
ACE_PPE_Flag13_IRQHandler
ACE_PPE_Flag14_IRQHandler
ACE_PPE_Flag15_IRQHandler
ACE_PPE_Flag16_IRQHandler
ACE_PPE_Flag17_IRQHandler
ACE_PPE_Flag18_IRQHandler
ACE_PPE_Flag19_IRQHandler
ACE_PPE_Flag20_IRQHandler
ACE_PPE_Flag21_IRQHandler
ACE_PPE_Flag22_IRQHandler
ACE_PPE_Flag23_IRQHandler
ACE_PPE_Flag24_IRQHandler
ACE_PPE_Flag25_IRQHandler
ACE_PPE_Flag26_IRQHandler
ACE_PPE_Flag27_IRQHandler
ACE_PPE_Flag28_IRQHandler
ACE_PPE_Flag29_IRQHandler
ACE_PPE_Flag30_IRQHandler
ACE_PPE_Flag31_IRQHandler

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

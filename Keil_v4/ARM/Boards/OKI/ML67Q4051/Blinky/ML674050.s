;/*****************************************************************************/
;/* STARTUP.S: Startup file for OKI ML67Q4050/4051/4060/4061 devices          */
;/*****************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                          */ 
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2005-2006 Keil Software. All rights reserved.               */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


;/*
; *  The STARTUP.S code is executed after CPU Reset. This file may be 
; *  translated with the following SET symbols. In uVision these SET 
; *  symbols are entered under Options - ASM - Define.
; *
; *  No symbols (default): device is configured for code execution 
; *  from on-chip ROM starting at address IROM_BASE.
; *
; *  IRAM_MODE: when set the device is configured for code execution
; *  from on-chip RAM starting at address IRAM_BASE. The startup
; *  vectors are located to IRAM_BASE.
; *
; *  EROM_MODE: when set the device is configured for code execution
; *  from off-chip ROM starting at address EROM_BASE. The startup
; *  vectors are located to EROM_BASE.
; *
; *  REMAP_RAM: when set the startup code copies exception vectors
; *  from ROM (xROM) to on-chip RAM and remaps them to address 0.
; */


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


; Memory Base Addresses
IROM_BASE       EQU     0x08000000      ; Built-in Flash ROM
IRAM_BASE       EQU     0x10000000      ; Processor RAM
BROM_BASE       EQU     0x48000000      ; Boot ROM
EROM_BASE       EQU     0xC8000000      ; External ROM
ERAM_BASE       EQU     0xD0000000      ; External RAM
SCR_BASE        EQU     0xB8000000      ; System Control Base
SCR_BASE2       EQU     0xB7000000      ; System Control Base 2
STCR_BASE       EQU     0xB8001000      ; System Timer Base
EMCR_BASE       EQU     0x78100000      ; External Memory Control Base


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
IRQ_Stack_Size  EQU     0x00000080
USR_Stack_Size  EQU     0x00000400

ISR_Stack_Size  EQU     (UND_Stack_Size + SVC_Stack_Size + ABT_Stack_Size + \
                         FIQ_Stack_Size + IRQ_Stack_Size)

                AREA    STACK, NOINIT, READWRITE, ALIGN=3

Stack_Mem       SPACE   USR_Stack_Size
__initial_sp    SPACE   ISR_Stack_Size
Stack_Top


;// <h> Heap Configuration
;//   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF>
;// </h>

Heap_Size       EQU     0x00000000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


; System Control definitions
SCR_RMPCON      EQU     0x10            ; Remap Control Register
SCR_PECLKCNT    EQU     0x00            ; Peripheral Clock Control Reg
SCR_PERSTCNT    EQU     0x04            ; Peripheral Reset Control Reg
SCR_PLL1        EQU     0x08            ; PLL1 Control Register
SCR_PLL2        EQU     0x0C            ; PLL2 Control Register
SCR_CLKCNT      EQU     0x10            ; Clock Control Register
SCR_CLKSTPCNT   EQU     0x14            ; Clock Stop Control Register
SCR_DMARQCNT    EQU     0x1C            ; DMA Request Select Register
SCR_LSICNT      EQU     0x20            ; LSI Control Register
SCR_PORTSEL1    EQU     0x24            ; Port Control Register 1
SCR_PORTSEL2    EQU     0x28            ; Port Control Register 2
SCR_PORTSEL3    EQU     0x2C            ; Port Control Register 3
SCR_PORTSEL4    EQU     0x30            ; Port Control Register 4
SCR_PORTSEL5    EQU     0x34            ; Port Control Register 5
SCR_FTMSEL      EQU     0x40            ; FTM Control Register
SCR_CKWT        EQU     0x44            ; Clock Wait Register
SCR_FLACON      EQU     0x100           ; Flash Memory Control Register

; System Timer Control definitions
STCR_TMEN       EQU     0x04            ; System Timer Enable Register
STCR_TMRLR      EQU     0x08            ; System Timer Reload Register
STCR_TMOVF      EQU     0x10            ; System Timer Overflow Register


;// <e> Clock Setup
;//   <h> SYSCLK
;//     <i> SYSCLK Output = SYSCLK / PLLDIVA
;//       <o4.19>     SYSCLKEN: SYSCLK Oscillator Active
;//       <o3.0..7>   PLLDIVA: SYSCLK Divide Ratio <0-255>
;//                   <i> 0 -> 256
;//   </h>
;//   <h> PLLA
;//     <i> PLLA Output = SYSCLK Output * DVCOA / DREFA / PLLDIVB
;//       <o4.16>     PLLENA: PLLA Active
;//       <o2.0..7>   DVCOA: PLLA Multiplication Ratio <0-255>
;//                   <i> 0 -> 256
;//       <o2.8..11>  DREFA: PLLA Divide Ratio
;//         <1=>1  <2=>2   <3=>3   <4=>4   <5=>5   <6=>6   <7=>7   <8=>8
;//         <9=>9  <10=>10 <11=>11 <12=>12 <13=>13 <14=>14 <15=>15 <0=>16
;//       <o2.12..13> SVCOA: PLLA Mode
;//         <0=> Reserved  <1=> Reserved  <2=> 135..200MHz  <3=> 75..135MHz
;//       <o3.8..15>  PLLDIVB: PLLA Output Divide Ratio <0-255>
;//                   <i> 0 -> 256
;//   </h>
;//   <h> PLLB
;//     <i> PLLB Output = PLLA Output * DVCOB / DREFB / PLLDIVC
;//       <o4.17>     PLLENB: PLLB Active
;//       <o2.16..23> DVCOB: PLLB Multiplication Ratio <0-255>
;//                   <i> 0 -> 256
;//       <o2.24..27> DREFB: PLLB Divide Ratio
;//         <1=>1  <2=>2   <3=>3   <4=>4   <5=>5   <6=>6   <7=>7   <8=>8
;//         <9=>9  <10=>10 <11=>11 <12=>12 <13=>13 <14=>14 <15=>15 <0=>16
;//       <o2.28..29> SVCOB: PLLB Mode
;//         <0=> Reserved  <1=> Reserved  <2=> 135..200MHz  <3=> 75..135MHz
;//       <o3.16..23> PLLDIVC: PLLB Output Divide Ratio <0-255>
;//                   <i> 0 -> 256
;//   </h>
;//   <h> RINGOSC
;//     <i> Ring Oscillator
;//       <o4.18>     RINGOSCEN: Ring Oscillator Active
;//   </h>
;//   <h> RTCCLK
;//     <i> RTC Clock
;//       <o4.20>     RTCCLKEN: RTCCLK Oscillator Active
;//   </h>
;//   <h> CPU_CLK
;//     <i> CPU Clock
;//       <o4.0..1>   PLLSEL: Selects PLLSEL_CLK
;//         <0=> SYSCLK  <1=> PLLA Output  <2=> PLLB Output  <3=> Reserved
;//       <o4.2..4>   CLKDIVA: Clock Divisor A for DIVA_CLK
;//         <i> DIVA_CLK = PLLSEL_CLK * CLKDIVA 
;//         <0=> 1/1  <1=> 1/2  <2=> 1/4  <3=> 1/8  <4=> 1/16  <5=> 1/32
;//         <6=> Reserved  <7=> Reserved
;//       <o4.5..6>   CLKDIVB: Clock Divisor B for DIVB_CLK
;//         <i> DIVB_CLK = DIVA_CLK * CLKDIVB
;//         <0=> 8/8  <1=> 5/8  <2=> 6/8  <3=> 7/8
;//       <o4.8..9>   SRCSEL: Selects CPU_CLK
;//         <0=> DIVB_CLK  <1=> Ring Oscillator  <2=> RTCCLK  <3=> Reserved
;//   </h>
;//   <h> APB_CLK
;//     <i> APB Clock
;//       <o4.10..11> APBDIV: APB Clock Divisor
;//         <i> Selects APB_CLK
;//         <0=> CPU_CLK / 1  <1=> CPU_CLK / 2  <2=> CPU_CLK / 4  <3=> Reserved
;//   </h>
;//   <h> AUDIO_CLK
;//     <i> Audio Clock
;//       <o4.12..13> AUDIOSEL: Selects AUDIO_CLK
;//         <0=> SYSCLK  <1=> PLLA Output  <2=> PLLB Output  <3=> SYSCLK Output
;//   </h>
;//   <h> STOP Mode Control
;//     <i> Controls Operation in STOP Mode
;//       <o5.19>     SYSCLKEN: SYSCLK Oscillator Active
;//       <o5.16>     PLLENA: PLLA Active
;//       <o5.17>     PLLENB: PLLB Active
;//       <o5.18>     RINGOSCEN: Ring Oscillator Active
;//       <o5.20>     RTCCLKEN: RTCCLK Oscillator Active
;//   </h>
;//   <h> Clock Supply Wait Time
;//     <i> Wait Time to stable Clock after release of STOP Mode
;//       <o6.0..11>  CKWTCMP: Number of Wait Cycles <0-2047>
;//       <o6.14..15> CKWTSEL: Select Wait Cycle Clock
;//         <0=> SYSCLK / 256  <1=> Ring Osc / 256  <2=> RTCCLK  <3=> Reserved
;//   </h>
;//   <h> Peripheral Clock Control
;//     <o1.0>  ADC Clock     <0=> Disabled  <1=> Enabled
;//     <o1.1>  I2C Clock     <0=> Disabled  <1=> Enabled
;//     <o1.2>  I2S Clock     <0=> Disabled  <1=> Enabled
;//     <o1.3>  UART0 Clock   <0=> Disabled  <1=> Enabled
;//     <o1.4>  UART1 Clock   <0=> Disabled  <1=> Enabled
;//     <o1.5>  SPI0 Clock    <0=> Disabled  <1=> Enabled
;//     <o1.6>  SPI1 Clock    <0=> Disabled  <1=> Enabled
;//     <o1.8>  WDT Clock     <0=> Disabled  <1=> Enabled
;//     <o1.9>  TMR Clock     <0=> Disabled  <1=> Enabled
;//     <o1.16> GPIO0 Clock   <0=> Disabled  <1=> Enabled
;//     <o1.17> GPIO1 Clock   <0=> Disabled  <1=> Enabled
;//     <o1.18> GPIO2 Clock   <0=> Disabled  <1=> Enabled
;//     <o1.19> GPIO3 Clock   <0=> Disabled  <1=> Enabled
;//     <o1.20> GPIO4 Clock   <0=> Disabled  <1=> Enabled
;//     <o1.21> GPIO5 Clock   <0=> Disabled  <1=> Enabled
;//     <o1.22> GPIO6 Clock   <0=> Disabled  <1=> Enabled
;//     <o1.23> GPIO7 Clock   <0=> Disabled  <1=> Enabled
;//     <o1.24> GPIO8 Clock   <0=> Disabled  <1=> Enabled
;//     <o1.25> GPIO9 Clock   <0=> Disabled  <1=> Enabled
;//     <o1.26> GPIO10 Clock  <0=> Disabled  <1=> Enabled
;//     <o1.27> GPIO11 Clock  <0=> Disabled  <1=> Enabled
;//     <o1.28> GPIO12 Clock  <0=> Disabled  <1=> Enabled
;//     <o1.29> GPIO13 Clock  <0=> Disabled  <1=> Enabled
;//     <o1.30> GPIO14 Clock  <0=> Disabled  <1=> Enabled
;//   </h>
;// </e>
CLK_SETUP       EQU     1
PECLKCNT_Val    EQU     0x003F037F
PLL1_Val        EQU     0x250C3308
PLL2_Val        EQU     0x00190101
CLKCNT_Val      EQU     0x001B2000
CLKSTPCNT_Val   EQU     0x001C0000
CKWT_Val        EQU     0x00000064


;// <e> LSI Control
;//   <h> DMA Control
;//     <i> DMA Assignment of Peripherals
;//       <o1.0..3> CHSEL0: Channel 0 Request
;//         <0=> UART0 (TX)  <1=> UART0 (RX)  <2=> UART1 (TX)  <3=> UART1 (RX)
;//         <4=> SPI0 (TX)   <5=> SPI0 (RX)   <6=> SPI1 (TX)   <7=> SPI1 (RX)
;//         <8=> I2C (TX)    <9=> I2C (RX)   <10=> I2S (TX)   <11=> I2S (RX)
;//        <12=> External
;//       <o1.4..7> CHSEL1: Channel 1 Request
;//         <0=> UART0 (TX)  <1=> UART0 (RX)  <2=> UART1 (TX)  <3=> UART1 (RX)
;//         <4=> SPI0 (TX)   <5=> SPI0 (RX)   <6=> SPI1 (TX)   <7=> SPI1 (RX)
;//         <8=> I2C (TX)    <9=> I2C (RX)   <10=> I2S (TX)   <11=> I2S (RX)
;//        <12=> External
;//   </h>
;//   <h> LSI Control
;//     <i> LSI Pin Control Settings
;//       <o2.0> I2SOUT: SD Pin             <0=> Input      <1=> Output
;//       <o2.4> I2CNFON: I2C Noise Filter  <0=> Disabled   <1=> Enabled
;//       <o2.8> JTAGE: JTAG Pin            <0=> Disabled   <1=> Enabled
;//   </h>
;//   <h> Port Control 1
;//     <i> Controls switching of functions of Port A and Port B
;//     <h> Port A
;//       <o3.12..13> PA6 Pin
;//         <0=> RTSOUT_N    <1=> PA6          <2=> MCLK         <3=> Prohibited
;//     </h>
;//     <h> Port B
;//       <o3.16..17> PB0 Pin
;//         <0=> PB0         <1=> TX0 (UART0)  <2=> Prohibited   <3=> Prohibited
;//       <o3.18..19> PB1 Pin
;//         <0=> PB1         <1=> RX0 (UART0)  <2=> Prohibited   <3=> Prohibited
;//       <o3.20..21> PB2 Pin
;//         <0=> PB2         <1=> TX1 (UART1)  <2=> EXTINT0      <3=> Prohibited
;//       <o3.22..23> PB3 Pin
;//         <0=> PB3         <1=> RX1 (UART1)  <2=> EXTINT1      <3=> Prohibited
;//       <o3.24..25> PB4 Pin
;//         <0=> PB4         <1=> SCL (I2C)    <2=> TXD (SIO)    <3=> Prohibited
;//       <o3.26..27> PB5 Pin
;//         <0=> PB5         <1=> SDA (I2C)    <2=> RXD (SIO)    <3=> Prohibited
;//     </h>
;//   </h>
;//   <h> Port Control 2
;//     <i> Controls switching of functions of Port C and Port D
;//     <h> Port C
;//       <o4.0..1>   PC0 Pin
;//         <0=> PC0         <1=> SIN0 (SPI0)  <2=> DSR0 (UART0) <3=> Prohibited
;//       <o4.2..3>   PC1 Pin
;//         <0=> PC1         <1=> SOUT0 (SPI0) <2=> DTR0 (UART0) <3=> Prohibited
;//       <o4.4..5>   PC2 Pin
;//         <0=> PC2         <1=> SCLK0 (SPI0) <2=> RIO (UART0)  <3=> Prohibited
;//       <o4.6..7>   PC3 Pin
;//         <0=> PC3         <1=> ENB0 (SPI0)  <2=> DCD0 (UART0) <3=> Prohibited
;//       <o4.8..9>   PC4 Pin
;//         <0=> PC4         <1=> SIN1 (SPI1)  <2=> DSR1 (UART1) <3=> Prohibited
;//       <o4.10..11> PC5 Pin
;//         <0=> PC5         <1=> SOUT1(SPI1)  <2=> DTR1 (UART1) <3=> Prohibited
;//       <o4.12..13> PC6 Pin
;//         <0=> PC6         <1=> SCLK1 (SPI1) <2=> RI1 (UART1)  <3=> Prohibited
;//       <o4.14..15> PC7 Pin
;//         <0=> PC7         <1=> ENB1 (SPI1)  <2=> DCD1 (UART1) <3=> Prohibited
;//     </h>
;//     <h> Port D
;//       <o4.16..17> PD0 Pin
;//         <0=> PD0         <1=> AIN0         <2=> EXTINT2      <3=> Prohibited
;//       <o4.18..19> PD1 Pin
;//         <0=> PD1         <1=> AIN1         <2=> EXTINT3      <3=> Prohibited
;//       <o4.20..21> PD2 Pin
;//         <0=> PD2         <1=> AIN2         <2=> Prohibited   <3=> Prohibited
;//       <o4.22..23> PD3 Pin
;//         <0=> PD3         <1=> AIN3         <2=> Prohibited   <3=> Prohibited
;//       <o4.24..25> PD4 Pin
;//         <0=> PD4         <1=> Prohibited   <2=> Prohibited   <3=> Prohibited
;//     </h>
;//   </h>
;//   <h> Port Control 3
;//     <i> Controls switching of functions of Port E and Port F
;//     <h> Port E
;//       <o5.6..7>   PE3 Pin
;//         <0=> PE3         <1=> MCLK         <2=> Prohibited   <3=> Prohibited
;//       <o5.8..9>   PE4 Pin
;//         <0=> PE4         <1=> SD (I2S)     <2=> Prohibited   <3=> Prohibited
;//       <o5.10..11> PE5 Pin
;//         <0=> PE5         <1=> WS (I2S)     <2=> Prohibited   <3=> Prohibited
;//       <o5.12..13> PE6 Pin
;//         <0=> PE6         <1=> SCK (I2S)    <2=> Prohibited    <3=> Prohibited
;//     </h>
;//     <h> Port F
;//       <o5.16..17> PF0 Pin
;//         <0=> PF0         <1=> TIMER0       <2=> CTS0 (UART0) <3=> Prohibited
;//       <o5.18..19> PF1 Pin
;//         <0=> PF1         <1=> TIMER1       <2=> RTS0 (UART0) <3=> Prohibited
;//       <o5.20..21> PF2 Pin
;//         <0=> PF2         <1=> TIMER2       <2=> CTS1 (UART1) <3=> Prohibited
;//       <o5.22..23> PF3 Pin
;//         <0=> PF3         <1=> TIMER3       <2=> RTS1 (UART1) <3=> Prohibited
;//       <o5.24..25> PF4 Pin
;//         <0=> PF4         <1=> TIMER4       <2=> EXTINT4      <3=> Prohibited
;//       <o5.26..27> PF5 Pin
;//         <0=> PF5         <1=> TIMER5       <2=> EXTINT5      <3=> Prohibited
;//     </h>
;//   </h>
;//   <h> Port Control 4
;//     <i> Controls switching of functions of Ports G, H, I, J, K, L, M
;//       <o6.0>    XA0: Pins PI7/PG0-6/PH0-7/PI0-4
;//         <0=> XA0-20      <1=> PI7/PG0-6/PH0-7/PI0-4
;//       <o6.2..3> XA1: Pins PI5-6
;//         <0=> XA21-22     <1=> PI5-6
;//       <o6.4>    XD0: Pins PJ0-7/PK0-7
;//         <0=> XD0-15      <1=> PJ0-7/PK0-7
;//       <o6.6>    XD1: Pins PL0-7/PM0-7
;//         <0=> XD16-31     <1=> PL0-7/PM0-7
;//   </h>
;//   <h> Port Control 5
;//     <i> Controls switching of functions of Port N and Port O
;//     <h> Port N
;//       <o7.0>    PN0 Pin  <0=> ROMCS_N      <1=> PN0
;//       <o7.2>    PN1 Pin  <0=> RAMCS_N      <1=> PN1
;//       <o7.4>    PN2 Pin  <0=> IOCS0_N      <1=> PN2
;//       <o7.6>    PN3 Pin  <0=> IOCS1_N      <1=> PN3
;//       <o7.8>    PN4 Pin  <0=> BS0_N        <1=> PN4
;//       <o7.10>   PN5 Pin  <0=> BS1_N        <1=> PN5
;//       <o7.12>   PN6 Pin  <0=> BS2_N        <1=> PN6
;//       <o7.14>   PN7 Pin  <0=> BS3_N        <1=> PN7
;//     </h>
;//     <h> Port O
;//       <o7.16>   PO0 Pin  <0=> OE_N         <1=> PO0
;//       <o7.18>   PO1 Pin  <0=> WR_N         <1=> PO1
;//     </h>
;//   </h>
;//   <h> FTM Control
;//     <i> Controls the inputs of Flexible Timer
;//       <o8.0..1>   FTMCLK0 Pin
;//         <0=> TIMER0      <1=> RTCCLK       <2=> WS (I2S)     <3=> Reserved
;//       <o8.2..3>   FTMCLK1 Pin
;//         <0=> TIMER1      <1=> RTCCLK       <2=> WS (I2S)     <3=> Reserved
;//       <o8.8..9>   FTMIN0 Pin
;//         <0=> TIMER0      <1=> RTCCLK       <2=> WS (I2S)     <3=> Reserved
;//       <o8.10..11> FTMIN1 Pin
;//         <0=> TIMER1      <1=> RTCCLK       <2=> WS (I2S)     <3=> Reserved
;//       <o8.12..13> FTMIN2 Pin
;//         <0=> TIMER2      <1=> RTCCLK       <2=> WS (I2S)     <3=> Reserved
;//       <o8.14..15> FTMIN3 Pin
;//         <0=> TIMER3      <1=> RTCCLK       <2=> WS (I2S)     <3=> Reserved
;//       <o8.16..17> FTMIN4 Pin
;//         <0=> TIMER4      <1=> RTCCLK       <2=> WS (I2S)     <3=> Reserved
;//       <o8.18..19> FTMIN5 Pin
;//         <0=> TIMER5      <1=> RTCCLK       <2=> WS (I2S)     <3=> Reserved
;//   </h>
;// </e>
LSI_SETUP       EQU     1
DMARQCNT_Val    EQU     0x00000000
LSICNT_Val      EQU     0x00000100
PORTSEL1_Val    EQU     0x00800000
PORTSEL2_Val    EQU     0x00000000
PORTSEL3_Val    EQU     0x00000000
PORTSEL4_Val    EQU     0x00000000
PORTSEL5_Val    EQU     0x00000000
FTMSEL_Val      EQU     0x00000000


; External Memory Controller definitions
EMCR_BWC        EQU     0x00            ; Bus Width Control Register
EMCR_ROMAC      EQU     0x04            ; ROM Access Control Register
EMCR_RAMAC      EQU     0x08            ; SRAM Access Control Register
EMCR_IO0AC      EQU     0x0C            ; I/O 0 Access Control Register
EMCR_IO1AC      EQU     0x10            ; I/O 1 Access Control Register

;// <e.0> External Memory Controller
;//   <h> BWC: Bus Width Control
;//     <o1.2..3>  ROMBW: ROM Bus Width
;//       <0=> Not Available  <1=> Prohibited   <2=> 16-bits    <3=> 32-bits
;//     <o1.4..5>  RAMBW: SRAM Bus Width
;//       <0=> Not Available  <1=> Prohibited   <2=> 16-bits    <3=> 32-bits
;//     <o1.6..7>  IOBW0: I/O 0 Bus Width
;//       <0=> Not Available  <1=> 8-bits       <2=> 16-bits    <3=> 32-bits
;//     <o1.8..9>  IOBW1: I/O 1 Bus Width
;//       <0=> Not Available  <1=> 8-bits       <2=> 16-bits    <3=> 32-bits
;//   </h>
;//   <h> ROMAC: ROM Access Control
;//     <o2.0..2>  ROMTYPE: ROM Timming (in cycles)
;//       <0=> OE/WE = 1, Read off = 0
;//       <1=> OE/WE = 2, Read off = 0
;//       <2=> OE/WE = 3, Read off = 2
;//       <3=> OE/WE = 4, Read off = 2
;//       <4=> Prohibited
;//       <5=> Prohibited
;//       <6=> Prohibited
;//       <7=> OE/WE = 8, Read off = 4
;//   </h>
;//   <h> RAMAC: SRAM Access Control
;//     <o3.0..2>  RAMTYPE: SRAM Timming (in cycles)
;//       <0=> OE/WE = 1, Data off = 0
;//       <1=> OE/WE = 2, Data off = 0
;//       <2=> OE/WE = 3, Data off = 2
;//       <3=> OE/WE = 4, Data off = 2
;//       <4=> Prohibited
;//       <5=> Prohibited
;//       <6=> Prohibited
;//       <7=> OE/WE = 8, Data off = 4
;//   </h>
;//   <h> IO0AC: I/O 0 Access Control
;//     <o4.0..2>  IO0TYPE: I/O 0 Timming (in cycles)
;//       <0=> Address Setup = 1, OE/WE =  1, Data off = 1
;//       <1=> Address Setup = 1, OE/WE =  4, Data off = 3
;//       <2=> Reserved
;//       <3=> Address Setup = 2, OE/WE =  8, Data off = 4
;//       <4=> Address Setup = 2, OE/WE = 12, Data off = 6
;//       <5=> Address Setup = 2, OE/WE = 16, Data off = 7
;//       <6=> Reserved
;//       <7=> Address Setup = 4, OE/WE = 24, Data off = 10
;//   </h>
;//   <h> IO1AC: I/O 1 Access Control
;//     <o5.0..2>  IO1TYPE: I/O 1 Timming (in cycles)
;//       <0=> Address Setup = 1, OE/WE =  1, Data off = 1
;//       <1=> Address Setup = 1, OE/WE =  4, Data off = 3
;//       <2=> Reserved
;//       <3=> Address Setup = 2, OE/WE =  8, Data off = 4
;//       <4=> Address Setup = 2, OE/WE = 12, Data off = 6
;//       <5=> Address Setup = 2, OE/WE = 16, Data off = 7
;//       <6=> Reserved
;//       <7=> Address Setup = 4, OE/WE = 24, Data off = 10
;//   </h>
;// </e>
EMC_SETUP       EQU     1
BWC_Val         EQU     0x00000038
ROMAC_Val       EQU     0x00000003
RAMAC_Val       EQU     0x00000000
IO0AC_Val       EQU     0x00000007
IO1AC_Val       EQU     0x00000007


                PRESERVE8
                

; Area Definition and Entry Point
;  Startup Code must be linked first at Address at which it expects to run.

                AREA    RESET, CODE, READONLY
                ARM


; Exception Vectors
;  Mapped to Address 0.
;  Absolute addressing mode must be used.
;  Dummy Handlers are implemented as infinite loops which can be modified.

Vectors         LDR     PC,Reset_Addr         
                LDR     PC,Undef_Addr
                LDR     PC,SWI_Addr
                LDR     PC,PAbt_Addr
                LDR     PC,DAbt_Addr
                NOP                            ; Reserved Vector 
                LDR     PC,IRQ_Addr
                LDR     PC,FIQ_Addr

                IMPORT  IRQ_Handler

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
;IRQ_Handler    B       IRQ_Handler
FIQ_Handler     B       FIQ_Handler


                IF      CLK_SETUP <> 0
CLK_DATA        DCD     PECLKCNT_Val
                DCD     PLL1_Val
                DCD     PLL2_Val
                DCD     CLKCNT_Val
                DCD     CLKSTPCNT_Val
                DCD     CKWT_Val
                ENDIF

                IF      LSI_SETUP <> 0
LSI_DATA        DCD     DMARQCNT_Val
                DCD     LSICNT_Val
                DCD     PORTSEL1_Val
                DCD     PORTSEL2_Val
                DCD     PORTSEL3_Val
                DCD     PORTSEL4_Val
                DCD     PORTSEL5_Val
                DCD     FTMSEL_Val
                ENDIF

                IF      EMC_SETUP <> 0
EMC_DATA        DCD     BWC_Val
                DCD     ROMAC_Val
                DCD     RAMAC_Val
                DCD     IO0AC_Val
                DCD     IO1AC_Val
                ENDIF


; Reset Handler

                EXPORT  Reset_Handler
Reset_Handler   


; Setup Clock
                IF      CLK_SETUP <> 0
                ADR     R8, CLK_DATA           ; Clock Data Address
                LDR     R9, =SCR_BASE2         ; SCR Base 2 Address
                LDMIA   R8, {R0-R5}            ; Load Clock Data
                ADD     R7, R9, #SCR_PLL1
                STMIA   R7!, {R1-R2}           ; Setup PLL1, PLL2
                LDR     R6, [R7]               ; Load CLKCNT
                LDR     R10, =0x00040F00       ; Mask: SRCSEL,APBDIV,RINGOSCEN
                AND     R1, R6, R10            ; Current Masked Bits
                BIC     R2, R3, R10            ; New Bits without Masked Bits
                ORR     R1, R1, R2             ; Merge CLKCNT
                STR     R1, [R7]               ; Setup CLKCNT
                AND     R1, R6, #0x00000300    ; Mask SRCSEL Field
                CMP     R1, #0x00000100        ; Check for Ring Osc
                BNE     No_RingOsc             ; Skip if No Ring Osc
                LDR     R8, =STCR_BASE         ; System Timer Base
                LDR     R1, =(65536 - 10000)   ; 10ms @ 16MHz Ring and Div=16
                STR     R1, [R8, #STCR_TMRLR]  ; Setup Timer Reload Value
                MOV     R1, #1
                STR     R1, [R8, #STCR_TMEN]   ; Start Timer
Wait            LDR     R1, [R8, #STCR_TMOVF]  ; Read Overflow
                CMP     R1, #1                 ; Check Overflow
                BNE     Wait                   ; Wait (for Clock to stabilize)
                MOV     R2, #0
                STR     R2, [R8, #STCR_TMEN]   ; Stop Timer
                STR     R1, [R8, #STCR_TMOVF]  ; Clear Timer Overflow
No_RingOsc      ORR     R1, R3, #0x00040000    ; Desired CLKCNT & RINGOSCEN=1
                STR     R1, [R7]               ; Setup CLKCNT & RINGOSCEN=1
                STMIA   R7, {R3-R4}            ; Setup CLKCNT & CLKSTPCNT
                STR     R5, [R9, #SCR_CKWT]    ; Setup CKWT
                MVN     R1, #0
                STR     R1, [R9, #SCR_PERSTCNT]; Reset All Peripherals
                STR     R0, [R9, #SCR_PECLKCNT]; Peripheral Clocks
                MVN     R1, R0
                STR     R1, [R9, #SCR_PERSTCNT]; Release Reset (Enabled Periph.)
                ENDIF


; Setup LSI
                IF      LSI_SETUP <> 0
                ADR     R8, LSI_DATA
                LDR     R9, =(SCR_BASE2 + SCR_DMARQCNT)
                LDMIA   R8!, {R0-R7}
                STMIA   R9!, {R0-R6}
                STR     R7, [R9, #8]
                ENDIF


; Setup External Memory Controller
                IF      EMC_SETUP <> 0
                ADR     R8, EMC_DATA
                LDR     R9, =EMCR_BASE
                LDMIA   R8, {R0-R4}
                STMIA   R9, {R0-R4}
                ENDIF


; Copy and Remap Exception Vectors to Internal RAM

                IF      :DEF:REMAP_RAM
                ADR     R8, Vectors            ; Source
                LDR     R9, =IRAM_BASE         ; Destination
                LDMIA   R8!, {R0-R7}           ; Load Vectors 
                STMIA   R9!, {R0-R7}           ; Store Vectors 
                LDMIA   R8!, {R0-R7}           ; Load Handler Addresses 
                STMIA   R9!, {R0-R7}           ; Store Handler Addresses
                LDR     R0, =SCR_BASE
                MOV     R1, #0x3C              ; Protection Code
                MOV     R2, #0x0C              ; IRAM Mapping
                STR     R1, [R0, #SCR_RMPCON]
                STR     R2, [R0, #SCR_RMPCON]
                LDR     R2, [R0, #SCR_RMPCON]  ; Dummy Read
                ENDIF


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
                IF      :DEF:__MICROLIB

                EXPORT __initial_sp

                ELSE

                MOV     SP, R0
                SUB     SL, SP, #USR_Stack_Size

                ENDIF


; Enter the C code

                IMPORT  __main
                LDR     R0, =__main
                BX      R0

                IF      :DEF:__MICROLIB

                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE
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
                ENDIF


                END

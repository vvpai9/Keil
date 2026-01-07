;/******************************************************************************/
;/* startup_NUC501.s: Startup file for Nuvoton NUC501 device series            */
;/******************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                           */
;/******************************************************************************/
;/* This file is part of the uVision/ARM development tools.                    */
;/* Copyright (c) 2010 Keil Software. All rights reserved.                     */
;/* This software may only be used under the terms of a valid, current,        */
;/* end user licence from KEIL for a compatible version of KEIL software       */
;/* development tools. Nothing else gives you the right to use this software.  */
;/******************************************************************************/

;/*
; *  The startup_NUC501.s code is executed after CPU Reset. This file may be 
; *  translated with the following SET symbols. In uVision these SET 
; *  symbols are entered under Options - ASM - Define.
; *
; *  NO_DMM_SETUP: when set the startup code will not initialize  
; *  Direct Memory Mode DMM 
; *  (used mostly when DMM is already initialized from script .ini file).
; *
; *  NO_CLK_SETUP: when set the startup code will not initialize Clock 
; *  (used mostly when clock is already initialized from script .ini file).
; *
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


;----------------------- Memory Definitions ------------------------------------

; Internal Memory Base Addresses
RAM_BASE        EQU     0x20000000
EXTMEM_BASE     EQU     0x40000000


;----------------------- Stack and Heap Definitions ----------------------------

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


;----------------------- System Manager Control (GCR) Module Definitions -------

GCR_BASE        EQU     0xB1000000      ; GCR Base Address

PDID_Ofs        EQU     0x00            ; R   roduct Identification Register
SPOCR_Ofs       EQU     0x04            ; R/W System Power-On Configuration Register
CPUCR_Ofs       EQU     0x08            ; R/W CPU Control Register
MISCR_Ofs       EQU     0x0C            ; R/W Miscellaneous Control Register
IPRST_Ofs       EQU     0x14            ; R/W IP Reset Control Resister
AHB_CTRL_Ofs    EQU     0x20            ; R/W AHB Bus Control register
PAD_REG0_Ofs    EQU     0x30            ; R/W PAD function
PAD_REG1_Ofs    EQU     0x34            ; R/W PAD function
PAD_REG2_Ofs    EQU     0x38            ; R/W PAD function
GPA_DS_Ofs      EQU     0x74            ; R/W GPIOA pads driving strength control
GPB_DS_Ofs      EQU     0x78            ; R/W GPIOB pads driving strength control
GPC_DS_Ofs      EQU     0x7C            ; R/W GPIOC pads driving strength control


;----------------------- Clock Control (CLK) Module Definitions ----------------

CLK_BASE        EQU     0xB1000200      ; CLK Base Address

PWRCON_Ofs      EQU     0x00            ; R/W System Power Down Control Register
AHBCLK_Ofs      EQU     0x04            ; R/W AHB Device Clock Enable Control Register
APBCLK_Ofs      EQU     0x08            ; R/W APB Device Clock Enable Control Register
CLKSEL_Ofs      EQU     0x10            ; R/W Clock Source Select Control Register
CLKDIV0_Ofs     EQU     0x14            ; R/W Clock Divider Number Register 0
CLKDIV1_Ofs     EQU     0x18            ; R/W Clock Divider Number Register 1
MPLLCON_Ofs     EQU     0x20            ; R/W MPLL Control Register


; Constants
XTAL_EN         EQU     (1<<0)          ; Crystal Oscillation Enable
PLL_PD          EQU     (1<<16)         ; PLL Power Down


;----------------------- SPI Master Control (SPIM) Module Definitions ----------

SPIM_BASE       EQU     0xB1007000      ; SPIM Base Address

CNTRL_Ofs       EQU     0x00            ; R/W Control and Status Register
DIVIDER_Ofs     EQU     0x04            ; R/W Clock Divider Register
SSR_Ofs         EQU     0x08            ; R/W Slave Select Register



;// <e> Direct Memory Mode Setup
;//   <h> Control and Status Register (SPIM.CNTL)
;//     <o1.24..31> SPIM_MODE: SPI Read Mode Select
;//                     <0x03=> Standard Read Mode
;//                     <0x0B=> Fast Read Mode
;//                     <0x3B=> Fast Read Dual Output Mode
;//     <o1.23>     OEN: Direction Control of spi_so_o
;//          <i> In most case, spi_so_o is output. 
;//          <i> But in flash fast dual read mode, spi_so_o is bi-direction pin.
;//                     <0=>    Output
;//                     <1=>    Input
;//     <o1.22>     COMMAND: For cipher IP (current transfer is: )
;//                     <0=>    Data Phase
;//                     <1=>    Command Phase
;//     <o1.21>     DIS_M: AHB master in boot mode Disable
;//     <o1.20>     BOOT_SPIM: SPI ROM Boot /Page Write Enable
;//     <o1.19>     F_DRD: Flash Data Read Enable
;//     <o1.18>     F_TYPE: Flash Type
;//                     <0=>    SST 16Mbit SPI Serial Flash (ST25VF016B)
;//                     <1=>    PMC 512Kbit Serial Flash with SPI interface
;//     <o1.17>     IE: SPI Interrupt Enable
;//     <o1.12..15> SLEEP: Suspend Interval <0-15>
;//          <i>Suspend Interval = (SLEEP + 2) * period of SCLK
;//     <o1.11>     Insert_Dummy: insert dummy phase in SPI flash fast dual read/fast read Enable
;//          <i>This bit is used to insert a dummy phase in
;//          <i>SPI flash fast dual read/fast read mode when in DMA mode
;//     <o1.10>     LSB: Send First
;//                     <0=>    MSB
;//                     <1=>    LSB
;//     <o1.8..9>   Tx_NUM: Transmit/Receive Numbers
;//                     <0=>    1 transmit/receive per transfer
;//                     <1=>    2 transmit/receive per transfer
;//                     <2=>    3 transmit/receive per transfer
;//                     <3=>    4 transmit/receive per transfer
;//     <o1.3..7>   Tx_BIT_LEN: Transmit Bit Length <0-31>
;//          <i>This field specifies how many bits are transmitted in one transmit/receive.
;//          <i>Up to 32 bits can be transmitted
;//   </h>
;//   <h> Clock Divider Register (SPIM.DIVIDER)
;//     <o2.20..22> SCLK_IN_DLY: Serial CLK Input Delay <1-8><#-1>
;//     <o2.16..19> IDLE_CNT: idle interval of slave select <0-15>
;//     <o2.0..15>  DIVIDER: Clock Divider <0-65535>
;//          <i>f_SCLK = f_PCLK / (DIVIDER * 2)
;//          <i>NOTE: When set DIVIDER to zero, SPI clock will be equal to engine clock
;//          <i>NOTE: when set DIVIER to zero, sleep(CNTRL[SLEEP]) can.t set to zero.
;//   </h>
;//   <h> Slave Select Register (SPIM.SSR)
;//     <o3.3>      ASS: Automatic Slave Select Enable
;//     <o3.2>      SS_LVL: Slave Select Active Level
;//                     <0=>    active Low.
;//                     <1=>    active High.
;//     <o3.0>      SSR: Slave Select Register
;//   </h>
;// </e>
DMM_SETUP     EQU     1
CNTRL_Val     EQU     0x0B321344
DIVIDER_Val   EQU     0x007F0000
SSR_Val       EQU     0x00000009
;PAD_REG1_Val  EQU     0x00000040



;// <e> Clock Setup
;//   <h> System Power Down Control Register (CLK.PWRCON)
;//     <o1.8..23>  Pre-Scale: Pre-Scale counter <0-65535>
;//          <i>Assume the crystal is stable after the Pre-Scale * 256 crystal cycle
;//     <o1.1>      XIN_CTL: Crystal Pre-Divide Control for Wake-Up Enable
;//     <o1.0>      XTAL_EN: Crystal Oscillator Enable
;//   </h>
;//   <h> AHB Devices Clock Enable Control Register Å(CLK.AHBCLKÅ)
;//     <o2.8>      APU_CK_EN: APU Clock Enable
;//     <o2.7>      SPIM_CK_EN: SPI FLASH/ROM Controller Clock Enable
;//     <o2.6>      USBD_CK_EN: USB Device Clock Enable
;//     <o2.1>      APB_CK_EN: APB Clock Enable
;//     <o2.0>      CPU_CK_EN: CPU Clock Enable
;//   </h>
;//   <h> APB Devices Clock Enable Control Register Å(CLK.APBCLKÅ)
;//     <o3.9>      ADC_CK_EN: Analog-Digital-Converter Clock Enable
;//     <o3.8>      SPIMS_CK_EN: SPI (master & slave) Clock Enable
;//     <o3.6>      I2C_CK_EN: I2C Clock Enable
;//     <o3.5>      PWM_CK_EN: PWM_0 (channel 3-0) Clock Enable
;//     <o3.4>      UART1_CK_EN: UART1 Clock Enable
;//     <o3.3>      UART0_CK_EN: UART0 Clock Enable Control
;//     <o3.2>      RTC_CK_EN: Real-Time-Clock Clock Enable
;//     <o3.1>      WD_CK_EN: Watch Dog Clock Enable
;//     <o3.0>      TIMER_CK_EN: Timer Clock Enable
;//   </h>
;//   <h> Clock Source Select Control Register Å(CLK.CLKSEL)
;//     <o4.14..15> ADC_S: ADC clock source
;//                     <0=>    crystal clock
;//                     <1=>    MPLL clock
;//                     <2=>    MPLL clock / 2
;//                     <3=>    MPLL clock / 2
;//     <o4.6..7>   UART_S: UART clock source
;//                     <0=>    crystal clock
;//                     <1=>    MPLL clock
;//                     <2=>    MPLL clock / 2
;//                     <3=>    MPLL clock / 2
;//     <o4.4..5>   APU_S: APU clock source
;//                     <0=>    crystal clock
;//                     <1=>    MPLL clock
;//                     <2=>    MPLL clock / 2
;//                     <3=>    MPLL clock / 2
;//     <o4.2..3>   USB_S: USB clock source
;//                     <0=>    crystal clock
;//                     <1=>    MPLL clock
;//                     <2=>    MPLL clock / 2
;//                     <3=>    MPLL clock / 2
;//     <o4.0..1>   HCLK_S: HCLK clock source
;//                     <0=>    crystal clock
;//                     <1=>    MPLL clock
;//                     <2=>    MPLL clock / 2
;//                     <3=>    crystal 32k
;//   </h>
;//   <h> Clock Divider Register 0 Å(CLK.CLKDIV0)
;//     <o5.20..23> USB_N: USB clock divider   <0-15>
;//          <i> USB clock frequency = (USB clock source frequency ) / (USB_N + 1)
;//     <o5.16..19> UART_N: UART clock divider <0-15>
;//          <i> UART clock frequency = (UART clock source frequency ) / (UART_N + 1)
;//     <o5.8..15>  APU_N: APU clock divider   <0-255>
;//          <i> APU clock frequency = (APU clock source frequency ) / (APU_N + 1)
;//     <o5.6..7>   APB_N: APB clock divider   <0-3>
;//          <i> APB clock frequency = (CPU clock frequency ) / (APB_N + 1)
;//     <o5.0..3>   HCLK_N: HCLK clock divider <0-15>
;//          <i> HCLK clock frequency = (HCLK clock source frequency / 2) / (HCLK_N + 1))
;//   </h>
;//   <h> Clock Divider Register 1 Å(CLK.CLKDIV1)
;//     <o6.16..23> ADC_N: ADC engine clock divider   <1-256><#-1>
;//   </h>
;//   <h> MPLL Control Register Å(CLK.MPLLCON)
;//          <i> FOUT = FIN * (NF/NR) * (1/NO)
;//          <i> 3.2MHz < FIN < 150MHz
;//          <i> 800KHz < (FIN/NR) <8MHz
;//          <i> 200MHz < FCO = FIN * (NF/NR) < 500MHz
;//          <i> 250MHz < FCO is preferred
;//     <o7.18>     OE: PLL OE (FOUT pin) Disable
;//     <o7.17>     BP: PLL Bypass Enable
;//     <o7.16>     PD: PLL Disable
;//     <o7.14..15> OUT_DV: PLL Output Divider
;//                     <0=>  NO = 1
;//                     <1=>  NO = 2
;//                     <2=>  NO = 2
;//                     <3=>  NO = 4
;//     <o7.9..13>  IN_DV: PLL Input Divider    <0-16>
;//          <i> NR = (2 x (IN_DV + 2))
;//     <o7.0..8 >  FB_DV: PLL Feedback Divider <0-511>
;//          <i> NF = (2 x (FB_DV + 2))
;//   </h>
;// </e>
CLK_SETUP     EQU     1
PWRCON_Val    EQU     0x00FFFF03
AHBCLK_Val    EQU     0x00000083
APBCLK_Val    EQU     0x00000000
CLKSEL_Val    EQU     0x0000008A
CLKDIV0_Val   EQU     0x00250040
CLKDIV1_Val   EQU     0x00000000
MPLLCON_Val   EQU     0x0000002E


                PRESERVE8

; Area Definition and Entry Point
;  Startup Code must be linked first at Address at which it expects to run.

                AREA    RESET, CODE, READONLY
                ARM

; Exception Vectors

Vectors         B       Reset_Handler       
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


; Dummy Exception Handlers (infinite loops which can be modified)                

Undef_Handler   PROC
                EXPORT  Undef_Handler             [WEAK]
                B       .
                ENDP
SWI_Handler     PROC
                EXPORT  SWI_Handler               [WEAK]
                B       .
                ENDP
PAbt_Handler    PROC
                EXPORT  PAbt_Handler              [WEAK]
                B       .
                ENDP
DAbt_Handler    PROC
                EXPORT  DAbt_Handler              [WEAK]
                B       .
                ENDP
IRQ_Handler     PROC
                EXPORT  IRQ_Handler               [WEAK]
                B       .
                ENDP
FIQ_Handler     PROC
                EXPORT  FIQ_Handler               [WEAK]
                B       .
                ENDP


; Reset Handler

                EXPORT  Reset_Handler
Reset_Handler   

; Direct Memory Mode -----------------------------------------------------------

                IF      (:LNOT:(:DEF:NO_DMM_SETUP)):LAND:(DMM_SETUP != 0)
                LDR     R0, =GCR_BASE
                LDR     R1, =SPIM_BASE

;  Configure Autochip select
                LDR     R2, =SSR_Val
                STR     R2, [R1, #SSR_Ofs]

;  Configure Autochip select
                LDR     R2, =DIVIDER_Val 
                STR     R2, [R1, #DIVIDER_Ofs]

;  Configure SSel Pin
                LDR     R2, =0x40 
                STR     R2, [R0, #PAD_REG1_Ofs]

;  Configure DMM mode
                LDR     R2, =CNTRL_Val 
                STR     R2, [r1, #CNTRL_Ofs]

                ENDIF   ; DMM_SETUP


; Clock Setup ------------------------------------------------------------------

                IF      (:LNOT:(:DEF:NO_CLK_SETUP)):LAND:(CLK_SETUP != 0)
                LDR     R0, =CLK_BASE

;  Enable XTAL
                LDR     R1, =PWRCON_Val          ; Enable main oscillator
                STR     R1, [R0, #PWRCON_Ofs] 

                IF      (PWRCON_Val:AND:XTAL_EN) != 0  
                MOV     R3, #(200/4)
XTAL_Loop       SUBS    R3, R3, #1              ; wait until XTAL stable
                BNE     XTAL_Loop
                ENDIF

;  Configure and Enable PLL
                MOV     R1, #0
                STR     R1, [R0, #CLKSEL_Ofs]   ; set clock source to XTAL
                STR     R1, [R0, #CLKDIV0_Ofs]  ; reset clock divider
                STR     R1, [R0, #CLKDIV1_Ofs]  ; reset clock divider

                LDR     R1, =MPLLCON_Val        ; Enable main oscillator
                STR     R1, [R0, #MPLLCON_Ofs] 

                IF      (MPLLCON_Val:AND:PLL_PD) == 0  
                MOV     R3, #(200  )
PLL_Loop        SUBS    R3, R3, #1              ; wait until PLL stable
                BNE     PLL_Loop
                ENDIF

;  Enable Clock to AHB Devices
                LDR     R1, =AHBCLK_Val         ; AHB Device Clock Enable
                STR     R1, [R0, #AHBCLK_Ofs] 

;  Enable Clock to APB Devices
                LDR     R1, =APBCLK_Val         ; APB Device Clock Enable
                STR     R1, [R0, #APBCLK_Ofs] 

;  Set Clock Divider
                LDR     R1, =CLKDIV0_Val        ; Clock Divider Register 0
                STR     R1, [R0, #CLKDIV0_Ofs] 

;  Set Clock Divider
                LDR     R1, =CLKDIV1_Val        ; Clock Divider Register 1
                STR     R1, [R0, #CLKDIV1_Ofs] 

;  Switch to selected Clock
                LDR     R1, =CLKSEL_Val         ; Clock Source Select
                STR     R1, [R0, #CLKSEL_Ofs] 

                ENDIF   ; CLK_SETUP



; Setup Stack for each mode ----------------------------------------------------

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


; Enter the C code -------------------------------------------------------------

                IMPORT  __main
                LDR     R0, =__main
                BX      R0



; User Initial Stack & Heap
                IF      :DEF:__MICROLIB

                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

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

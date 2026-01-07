// ===============================================															
// ADuC7033 HEADER FILE REV 1.4																		
// ===============================================															

// Interrupt Controller

#define          INTBASE                                    (*(volatile unsigned long      *) 0xFFFF0000)
#define          IRQSTA                                     (*(volatile unsigned long      *) 0xFFFF0000)
#define          IRQSIG                                     (*(volatile unsigned long      *) 0xFFFF0004)
#define          IRQEN                                      (*(volatile unsigned long      *) 0xFFFF0008)
#define          IRQCLR                                     (*(volatile unsigned long      *) 0xFFFF000C)
#define          SWICFG                                     (*(volatile unsigned long      *) 0xFFFF0010)
#define          FIQSTA                                     (*(volatile unsigned long      *) 0xFFFF0100)
#define          FIQSIG                                     (*(volatile unsigned long      *) 0xFFFF0104)
#define          FIQEN                                      (*(volatile unsigned long      *) 0xFFFF0108)
#define          FIQCLR                                     (*(volatile unsigned long      *) 0xFFFF010C)

// Remap and System Control

#define          REMAPBASE                                  (*(volatile unsigned long      *) 0xFFFF0200)
#define          SYSMAP0                                    (*(volatile unsigned long      *) 0xFFFF0220)
#define          RSTSTA                                     (*(volatile unsigned long      *) 0xFFFF0230)
#define          RSTCLR                                     (*(volatile unsigned long      *) 0xFFFF0234)
#define          SYSSER0                                    (*(volatile unsigned long      *) 0xFFFF0238)
#define          SYSSER1                                    (*(volatile unsigned long      *) 0xFFFF023C)
#define          SYSCHK                                     (*(volatile unsigned long      *) 0xFFFF0240)

// 48bit General Purpose Timer 0

#define          TIMER0BASE                                 (*(volatile unsigned long      *) 0xFFFF0300)
#define          T0LD                                       (*(volatile unsigned long      *) 0xFFFF0300)
#define          T0VAL0                                     (*(volatile unsigned long      *) 0xFFFF0304)
#define          T0VAL1                                     (*(volatile unsigned long      *) 0xFFFF0308)
#define          T0CON                                      (*(volatile unsigned long      *) 0xFFFF030C)
#define          T0CLRI                                     (*(volatile unsigned long      *) 0xFFFF0310)
#define          T0CAP                                      (*(volatile unsigned long      *) 0xFFFF0314)

// General Purpose Timer 1

#define          TIMER1BASE                                 (*(volatile unsigned long      *) 0xFFFF0320)
#define          T1LD                                       (*(volatile unsigned long      *) 0xFFFF0320)
#define          T1VAL                                      (*(volatile unsigned long      *) 0xFFFF0324)
#define          T1CON                                      (*(volatile unsigned long      *) 0xFFFF0328)
#define          T1CLRI                                     (*(volatile unsigned long      *) 0xFFFF032C)
#define          T1CAP                                      (*(volatile unsigned long      *) 0xFFFF0330)

// Wake Up Timer

#define          TIMER2BASE                                 (*(volatile unsigned long      *) 0xFFFF0340)
#define          T2LD                                       (*(volatile unsigned long      *) 0xFFFF0340)
#define          T2VAL                                      (*(volatile unsigned long      *) 0xFFFF0344)
#define          T2CON                                      (*(volatile unsigned long      *) 0xFFFF0348)
#define          T2CLRI                                     (*(volatile unsigned long      *) 0xFFFF034C)

// Watchdog Timer

#define          TIMER3BASE                                 (*(volatile unsigned long      *) 0xFFFF0360)
#define          T3LD                                       (*(volatile unsigned long      *) 0xFFFF0360)
#define          T3VAL                                      (*(volatile unsigned long      *) 0xFFFF0364)
#define          T3CON                                      (*(volatile unsigned long      *) 0xFFFF0368)
#define          T3CLRI                                     (*(volatile unsigned long      *) 0xFFFF036C)

// STI TIMER

#define          TIMER4BASE                                 (*(volatile unsigned long      *) 0xFFFF0380)
#define          T4LD                                       (*(volatile unsigned long      *) 0xFFFF0380)
#define          T4VAL                                      (*(volatile unsigned long      *) 0xFFFF0384)
#define          T4CON                                      (*(volatile unsigned long      *) 0xFFFF0388)
#define          T4CLRI                                     (*(volatile unsigned long      *) 0xFFFF038C)
#define          T4CAP                                      (*(volatile unsigned long      *) 0xFFFF0390)

// PLL and Oscillator Control

#define          PLLBASE                                    (*(volatile unsigned long      *) 0xFFFF0400)
#define          PLLSTA                                     (*(volatile unsigned long      *) 0xFFFF0400)
#define          POWKEY0                                    (*(volatile unsigned long      *) 0xFFFF0404)
#define          POWCON                                     (*(volatile unsigned long      *) 0xFFFF0408)
#define          POWKEY1                                    (*(volatile unsigned long      *) 0xFFFF040C)
#define          PLLKEY0                                    (*(volatile unsigned long      *) 0xFFFF0410)
#define          PLLCON                                     (*(volatile unsigned long      *) 0xFFFF0414)
#define          PLLKEY1                                    (*(volatile unsigned long      *) 0xFFFF0418)
#define          OSC0TRM                                    (*(volatile unsigned long      *) 0xFFFF042C)
#define          OSC0CON                                    (*(volatile unsigned long      *) 0xFFFF0440)
#define          OSC0STA                                    (*(volatile unsigned long      *) 0xFFFF0444)
#define          OSC0VAL0                                   (*(volatile unsigned long      *) 0xFFFF0448)
#define          OSC0VAL1                                   (*(volatile unsigned long      *) 0xFFFF044C)

// ADC interface registers

#define          ADCBASE                                    (*(volatile unsigned long      *) 0xFFFF0500)
#define          ADCSTA                                     (*(volatile unsigned long      *) 0xFFFF0500)
#define          ADCMSKI                                    (*(volatile unsigned long      *) 0xFFFF0504)
#define          ADCMDE                                     (*(volatile unsigned long      *) 0xFFFF0508)
#define          ADC0CON                                    (*(volatile unsigned long      *) 0xFFFF050C)
#define          ADC1CON                                    (*(volatile unsigned long      *) 0xFFFF0510)
#define          ADCFLT                                     (*(volatile unsigned long      *) 0xFFFF0518)
#define          ADCCFG                                     (*(volatile unsigned long      *) 0xFFFF051C)
#define          ADC0DAT                                    (*(volatile unsigned long      *) 0xFFFF0520)
#define          ADC1DAT                                    (*(volatile unsigned long      *) 0xFFFF0524)
#define          ADC2DAT                                    (*(volatile unsigned long      *) 0xFFFF0528)
#define          ADC0OF                                     (*(volatile unsigned long      *) 0xFFFF0530)
#define          ADC1OF                                     (*(volatile unsigned long      *) 0xFFFF0534)
#define          ADC2OF                                     (*(volatile unsigned long      *) 0xFFFF0538)
#define          ADC0GN                                     (*(volatile unsigned long      *) 0xFFFF053C)
#define          ADC1GN                                     (*(volatile unsigned long      *) 0xFFFF0540)
#define          ADC2GN                                     (*(volatile unsigned long      *) 0xFFFF0544)
#define          ADC0RCL                                    (*(volatile unsigned long      *) 0xFFFF0548)
#define          ADC0RCV                                    (*(volatile unsigned long      *) 0xFFFF054C)
#define          ADC0TH                                     (*(volatile unsigned long      *) 0xFFFF0550)
#define          ADC0TCL                                    (*(volatile unsigned long      *) 0xFFFF0554)
#define          ADC0THV                                    (*(volatile unsigned long      *) 0xFFFF0558)
#define          ADC0ACC                                    (*(volatile unsigned long      *) 0xFFFF055C)
#define          ADCREF                                     (*(volatile unsigned long      *) 0xFFFF057C)

// 450 Compatible UART core registers

#define          UARTBASE                                   (*(volatile unsigned long      *) 0xFFFF0700)
#define          COMTX                                      (*(volatile unsigned long      *) 0xFFFF0700)
#define          COMRX                                      (*(volatile unsigned long      *) 0xFFFF0700)
#define          COMDIV0                                    (*(volatile unsigned long      *) 0xFFFF0700)
#define          COMIEN0                                    (*(volatile unsigned long      *) 0xFFFF0704)
#define          COMDIV1                                    (*(volatile unsigned long      *) 0xFFFF0704)
#define          COMIID0                                    (*(volatile unsigned long      *) 0xFFFF0708)
#define          COMCON0                                    (*(volatile unsigned long      *) 0xFFFF070C)
#define          COMCON1                                    (*(volatile unsigned long      *) 0xFFFF0710)
#define          COMSTA0                                    (*(volatile unsigned long      *) 0xFFFF0714)
#define          COMDIV2                                    (*(volatile unsigned long      *) 0xFFFF072C)

// LIN Hardware SYNC Registers.

#define          LSBASE                                     (*(volatile unsigned long      *) 0xFFFF0780)
#define          LHSSTA                                     (*(volatile unsigned long      *) 0xFFFF0780)
#define          LHSCON0                                    (*(volatile unsigned long      *) 0xFFFF0784)
#define          LHSVAL0                                    (*(volatile unsigned long      *) 0xFFFF0788)
#define          LHSCON1                                    (*(volatile unsigned long      *) 0xFFFF078C)
#define          LHSVAL1                                    (*(volatile unsigned long      *) 0xFFFF0790)
#define          LHSCAP                                     (*(volatile unsigned long      *) 0xFFFF0794)
#define          LHSCMP                                     (*(volatile unsigned long      *) 0xFFFF0798)

// 2-Wire Interface registers to HV die.

#define          HVBASE                                     (*(volatile unsigned long      *) 0xFFFF0800)
#define          HVCON                                      (*(volatile unsigned long      *) 0xFFFF0804)
#define          HVDAT                                      (*(volatile unsigned long      *) 0xFFFF080C)

// System Test Interface Registers

#define          STIBASE                                    (*(volatile unsigned long      *) 0xFFFF0880)
#define          STIKEY0                                    (*(volatile unsigned long      *) 0xFFFF0880)
#define          STICON                                     (*(volatile unsigned long      *) 0xFFFF0884)
#define          STIKEY1                                    (*(volatile unsigned long      *) 0xFFFF0888)
#define          STIDAT0                                    (*(volatile unsigned long      *) 0xFFFF088C)
#define          STIDAT1                                    (*(volatile unsigned long      *) 0xFFFF0890)
#define          STIDAT2                                    (*(volatile unsigned long      *) 0xFFFF0894)

// Serial Port Interface Peripheral

#define          SPIBASE                                    (*(volatile unsigned long      *) 0xFFFF0A00)
#define          SPISTA                                     (*(volatile unsigned long      *) 0xFFFF0A00)
#define          SPIRX                                      (*(volatile unsigned long      *) 0xFFFF0A04)
#define          SPITX                                      (*(volatile unsigned long      *) 0xFFFF0A08)
#define          SPIDIV                                     (*(volatile unsigned long      *) 0xFFFF0A0C)
#define          SPICON                                     (*(volatile unsigned long      *) 0xFFFF0A10)

// GPIO + Serial Port Mux (AHB bus)

#define          GPIOBASE                                   (*(volatile unsigned long      *) 0xFFFF0D00)
#define          GP0CON                                     (*(volatile unsigned long      *) 0xFFFF0D00)
#define          GP1CON                                     (*(volatile unsigned long      *) 0xFFFF0D04)
#define          GP2CON                                     (*(volatile unsigned long      *) 0xFFFF0D08)
#define          GP0DAT                                     (*(volatile unsigned long      *) 0xFFFF0D20)
#define          GP0SET                                     (*(volatile unsigned long      *) 0xFFFF0D24)
#define          GP0CLR                                     (*(volatile unsigned long      *) 0xFFFF0D28)
#define          GP1DAT                                     (*(volatile unsigned long      *) 0xFFFF0D30)
#define          GP1SET                                     (*(volatile unsigned long      *) 0xFFFF0D34)
#define          GP1CLR                                     (*(volatile unsigned long      *) 0xFFFF0D38)
#define          GP2DAT                                     (*(volatile unsigned long      *) 0xFFFF0D40)
#define          GP2SET                                     (*(volatile unsigned long      *) 0xFFFF0D44)
#define          GP2CLR                                     (*(volatile unsigned long      *) 0xFFFF0D48)

// Flash Control Interface 32Kbytes (AHB bus)

#define          FLASH0BASE                                 (*(volatile unsigned long      *) 0xFFFF0E00)
#define          FEE0STA                                    (*(volatile unsigned long      *) 0xFFFF0E00)
#define          FEE0MOD                                    (*(volatile unsigned long      *) 0xFFFF0E04)
#define          FEE0CON                                    (*(volatile unsigned long      *) 0xFFFF0E08)
#define          FEE0DAT                                    (*(volatile unsigned long      *) 0xFFFF0E0C)
#define          FEE0ADR                                    (*(volatile unsigned long      *) 0xFFFF0E10)
#define          FEE0SIG                                    (*(volatile unsigned long      *) 0xFFFF0E18)
#define          FEE0PRO                                    (*(volatile unsigned long      *) 0xFFFF0E1C)
#define          FEE0HID                                    (*(volatile unsigned long      *) 0xFFFF0E20)

// Flash Control Interface 64Kbytes(AHB bus)

#define          FLASH1BASE                                 (*(volatile unsigned long      *) 0xFFFF0E80)
#define          FEE1STA                                    (*(volatile unsigned long      *) 0xFFFF0E80)
#define          FEE1MOD                                    (*(volatile unsigned long      *) 0xFFFF0E84)
#define          FEE1CON                                    (*(volatile unsigned long      *) 0xFFFF0E88)
#define          FEE1DAT                                    (*(volatile unsigned long      *) 0xFFFF0E8C)
#define          FEE1ADR                                    (*(volatile unsigned long      *) 0xFFFF0E90)
#define          FEE1SIG                                    (*(volatile unsigned long      *) 0xFFFF0E98)
#define          FEE1PRO                                    (*(volatile unsigned long      *) 0xFFFF0E9C)
#define          FEE1HID                                    (*(volatile unsigned long      *) 0xFFFF0EA0)
/*    Function Pointers for Interrupts  */
typedef void (* tyVctHndlr) (void);

extern tyVctHndlr    IRQ;
extern tyVctHndlr    SWI;
extern tyVctHndlr    FIQ;
extern tyVctHndlr    UNDEF;
extern tyVctHndlr    PABORT;
extern tyVctHndlr    DABORT;

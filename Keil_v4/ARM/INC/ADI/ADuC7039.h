// ===============================================															
// ADuC7039 HEADER FILE REV 1.4															
// ===============================================															

// INTERRUPT CONTROLLER

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
#if           ALLOW_DEPRECATED_NAMES        
// "SYSMAP" has been deprecated. Use "SYSMAP0" instead.
#define          SYSMAP                                     (*(volatile unsigned long      *) 0xFFFF0220)
#endif
#define          RSTSTA                                     (*(volatile unsigned long      *) 0xFFFF0230)
#define          RSTCLR                                     (*(volatile unsigned long      *) 0xFFFF0234)
#define          SYSCHK                                     (*(volatile unsigned long      *) 0xFFFF0244)

// 16 bit General Purpose Timer 0

#define          TIMER0BASE                                 (*(volatile unsigned long      *) 0xFFFF0300)
#define          T0LD                                       (*(volatile unsigned long      *) 0xFFFF0300)
#define          T0VAL                                      (*(volatile unsigned long      *) 0xFFFF0304)
#define          T0CON                                      (*(volatile unsigned long      *) 0xFFFF0308)
#define          T0CLRI                                     (*(volatile unsigned long      *) 0xFFFF030C)

// Wake Up Timer

#define          TIMER1BASE                                 (*(volatile unsigned long      *) 0xFFFF0320)
#define          T1LD                                       (*(volatile unsigned long      *) 0xFFFF0320)
#define          T1VAL                                      (*(volatile unsigned long      *) 0xFFFF0324)
#define          T1CON                                      (*(volatile unsigned long      *) 0xFFFF0328)
#define          T1CLRI                                     (*(volatile unsigned long      *) 0xFFFF032C)
#define          T1CAP                                      (*(volatile unsigned long      *) 0xFFFF0330)

// Watchdog

#define          TIMER2BASE                                 (*(volatile unsigned long      *) 0xFFFF0340)
#define          T2LD                                       (*(volatile unsigned long      *) 0xFFFF0340)
#define          T2VAL                                      (*(volatile unsigned long      *) 0xFFFF0344)
#define          T2CON                                      (*(volatile unsigned long      *) 0xFFFF0348)
#define          T2CLRI                                     (*(volatile unsigned long      *) 0xFFFF034C)

// PLL and Oscillator Control

#define          PLLBASE                                    (*(volatile unsigned long      *) 0xFFFF0400)
#define          PLLSTA                                     (*(volatile unsigned long      *) 0xFFFF0400)
#define          POWKEY0                                    (*(volatile unsigned long      *) 0xFFFF0404)
#define          POWCON                                     (*(volatile unsigned long      *) 0xFFFF0408)
#define          POWKEY1                                    (*(volatile unsigned long      *) 0xFFFF040C)
#define          PLLKEY0                                    (*(volatile unsigned long      *) 0xFFFF0410)
#define          PLLCON                                     (*(volatile unsigned long      *) 0xFFFF0414)
#define          PLLKEY1                                    (*(volatile unsigned long      *) 0xFFFF0418)
#define          OSC0CON                                    (*(volatile unsigned long      *) 0xFFFF0440)
#if           ALLOW_DEPRECATED_NAMES        
// "OSCCON" has been deprecated. Use "OSC0CON" instead.
#define          OSCCON                                     (*(volatile unsigned long      *) 0xFFFF0440)
#endif
#define          OSC0STA                                    (*(volatile unsigned long      *) 0xFFFF0444)
#if           ALLOW_DEPRECATED_NAMES        
// "OSCSTA" has been deprecated. Use "OSC0STA" instead.
#define          OSCSTA                                     (*(volatile unsigned long      *) 0xFFFF0444)
#endif
#define          OSC0VAL0                                   (*(volatile unsigned long      *) 0xFFFF0448)
#if           ALLOW_DEPRECATED_NAMES        
// "OSCVAL0" has been deprecated. Use "OSC0VAL0" instead.
#define          OSCVAL0                                    (*(volatile unsigned long      *) 0xFFFF0448)
#endif
#define          OSC0VAL1                                   (*(volatile unsigned long      *) 0xFFFF044C)
#if           ALLOW_DEPRECATED_NAMES        
// "OSCVAL1" has been deprecated. Use "OSC0VAL1" instead.
#define          OSCVAL1                                    (*(volatile unsigned long      *) 0xFFFF044C)
#endif
#define          LOCCON                                     (*(volatile unsigned long      *) 0xFFFF0480)
#define          LOCUSR0                                    (*(volatile unsigned long      *) 0xFFFF0484)
#define          LOCUSR1                                    (*(volatile unsigned long      *) 0xFFFF0488)
#define          LOCMAX                                     (*(volatile unsigned long      *) 0xFFFF048C)
#define          LOCMIN                                     (*(volatile unsigned long      *) 0xFFFF0490)
#define          LOCSTA                                     (*(volatile unsigned long      *) 0xFFFF0494)
#define          LOCVAL0                                    (*(volatile unsigned long      *) 0xFFFF0498)
#define          LOCVAL1                                    (*(volatile unsigned long      *) 0xFFFF049C)
#define          LOCKEY                                     (*(volatile unsigned long      *) 0xFFFF04A0)

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
#define          ADC0OF                                     (*(volatile unsigned long      *) 0xFFFF0530)
#define          ADC1OF                                     (*(volatile unsigned long      *) 0xFFFF0534)
#define          ADC2OF                                     (*(volatile unsigned long      *) 0xFFFF0538)
#define          ADC0GN                                     (*(volatile unsigned long      *) 0xFFFF053C)
#define          ADC1GN                                     (*(volatile unsigned long      *) 0xFFFF0540)
#define          ADC2GN                                     (*(volatile unsigned long      *) 0xFFFF0544)
#define          ADC0RCL                                    (*(volatile unsigned long      *) 0xFFFF0548)
#define          ADC0RCV                                    (*(volatile unsigned long      *) 0xFFFF054C)
#define          ADC0TH                                     (*(volatile unsigned long      *) 0xFFFF0550)
#define          ADC0ACC                                    (*(volatile unsigned long      *) 0xFFFF055C)

// LIN Hardware SYNC Registers.

#define          LINBASE                                    (*(volatile unsigned long      *) 0xFFFF0700)
#define          LINCON                                     (*(volatile unsigned long      *) 0xFFFF0700)
#define          LINCS                                      (*(volatile unsigned long      *) 0xFFFF0704)
#define          LINBR                                      (*(volatile unsigned long      *) 0xFFFF0708)
#define          LINBK                                      (*(volatile unsigned long      *) 0xFFFF070C)
#define          LINSTA                                     (*(volatile unsigned long      *) 0xFFFF0710)
#define          LINDAT                                     (*(volatile unsigned long      *) 0xFFFF0714)
#define          LINLOW                                     (*(volatile unsigned long      *) 0xFFFF0718)
#define          LINWU                                      (*(volatile unsigned long      *) 0xFFFF071C)

// High Voltage Interface.

#define          HVBASE                                     (*(volatile unsigned long      *) 0xFFFF0800)
#define          HVCON                                      (*(volatile unsigned long      *) 0xFFFF0804)
#define          HVDAT                                      (*(volatile unsigned long      *) 0xFFFF080C)

// Serial Port Interface Peripheral

#define          SPIBASE                                    (*(volatile unsigned long      *) 0xFFFF0A00)
#define          SPISTA                                     (*(volatile unsigned long      *) 0xFFFF0A00)
#define          SPIRX                                      (*(volatile unsigned long      *) 0xFFFF0A04)
#define          SPITX                                      (*(volatile unsigned long      *) 0xFFFF0A08)
#define          SPIDIV                                     (*(volatile unsigned long      *) 0xFFFF0A0C)
#define          SPICON                                     (*(volatile unsigned long      *) 0xFFFF0A10)

// GPIO + Serial Port Mux (AHB bus)

#define          GPIOBASE                                   (*(volatile unsigned long      *) 0xFFFF0D00)
#define          GPCON                                      (*(volatile unsigned long      *) 0xFFFF0D00)
#define          GPDAT                                      (*(volatile unsigned long      *) 0xFFFF0D10)
#define          GPSET                                      (*(volatile unsigned long      *) 0xFFFF0D14)
#define          GPCLR                                      (*(volatile unsigned long      *) 0xFFFF0D18)

// Flash Control Interface 64Kbytes (AHB bus)

#define          FLASHBASE                                  (*(volatile unsigned long      *) 0xFFFF0E00)
#define          FEESTA                                     (*(volatile unsigned long      *) 0xFFFF0E00)
#define          FEEMOD                                     (*(volatile unsigned long      *) 0xFFFF0E04)
#define          FEECON                                     (*(volatile unsigned long      *) 0xFFFF0E08)
#define          FEEDAT                                     (*(volatile unsigned long      *) 0xFFFF0E0C)
#define          FEEADR                                     (*(volatile unsigned long      *) 0xFFFF0E10)
#define          FEESIG                                     (*(volatile unsigned long      *) 0xFFFF0E18)
#define          FEEPRO                                     (*(volatile unsigned long      *) 0xFFFF0E1C)
#define          FEEHID                                     (*(volatile unsigned long      *) 0xFFFF0E20)
/*    Function Pointers for Interrupts  */
typedef void (* tyVctHndlr) (void);

extern tyVctHndlr    IRQ;
extern tyVctHndlr    SWI;
extern tyVctHndlr    FIQ;
extern tyVctHndlr    UNDEF;
extern tyVctHndlr    PABORT;
extern tyVctHndlr    DABORT;

// ===============================================															
// ADuC7061 HEADER FILE REV 1.6															
// ===============================================															

// INTERRUPT CONTROLLER

#define          INTBASE                                    (*(volatile unsigned long      *) 0xFFFF0000)
#define          IRQSTA                                     (*(volatile unsigned long      *) 0xFFFF0000)
#define          IRQSIG                                     (*(volatile unsigned long      *) 0xFFFF0004)
#define          IRQEN                                      (*(volatile unsigned long      *) 0xFFFF0008)
#define          IRQCLR                                     (*(volatile unsigned long      *) 0xFFFF000C)
#define          SWICFG                                     (*(volatile unsigned long      *) 0xFFFF0010)
#define          IRQBASE                                    (*(volatile unsigned long      *) 0xFFFF0014)
#define          IRQVEC                                     (*(volatile unsigned long      *) 0xFFFF001C)
#define          IRQP0                                      (*(volatile unsigned long      *) 0xFFFF0020)
#define          IRQP1                                      (*(volatile unsigned long      *) 0xFFFF0024)
#define          IRQP2                                      (*(volatile unsigned long      *) 0xFFFF0028)
#define          IRQCONN                                    (*(volatile unsigned long      *) 0xFFFF0030)
#define          IRQCONE                                    (*(volatile unsigned long      *) 0xFFFF0034)
#define          IRQCLRE                                    (*(volatile unsigned long      *) 0xFFFF0038)
#define          IRQSTAN                                    (*(volatile unsigned long      *) 0xFFFF003C)
#define          FIQSTA                                     (*(volatile unsigned long      *) 0xFFFF0100)
#define          FIQSIG                                     (*(volatile unsigned long      *) 0xFFFF0104)
#define          FIQEN                                      (*(volatile unsigned long      *) 0xFFFF0108)
#define          FIQCLR                                     (*(volatile unsigned long      *) 0xFFFF010C)
#define          FIQVEC                                     (*(volatile unsigned long      *) 0xFFFF011C)
#define          FIQSTAN                                    (*(volatile unsigned long      *) 0xFFFF013C)

// REMAP AND SYSTEM CONTROL

#define          REMAPBASE                                  (*(volatile unsigned long      *) 0xFFFF0200)
#define          REMAP                                      (*(volatile unsigned long      *) 0xFFFF0220)
#define          RSTSTA                                     (*(volatile unsigned long      *) 0xFFFF0230)
#define          RSTCLR                                     (*(volatile unsigned long      *) 0xFFFF0234)

// TIMER 0

#define          T0BASE                                     (*(volatile unsigned long      *) 0xFFFF0320)
#define          T0LD                                       (*(volatile unsigned long      *) 0xFFFF0320)
#define          T0VAL                                      (*(volatile unsigned long      *) 0xFFFF0324)
#define          T0CON                                      (*(volatile unsigned long      *) 0xFFFF0328)
#define          T0CLRI                                     (*(volatile unsigned long      *) 0xFFFF032C)
#define          T0CAP                                      (*(volatile unsigned long      *) 0xFFFF0330)

// WAKE UP TIMER

#define          T1BASE                                     (*(volatile unsigned long      *) 0xFFFF0340)
#define          T1LD                                       (*(volatile unsigned long      *) 0xFFFF0340)
#define          T1VAL                                      (*(volatile unsigned long      *) 0xFFFF0344)
#define          T1CON                                      (*(volatile unsigned long      *) 0xFFFF0348)
#define          T1CLRI                                     (*(volatile unsigned long      *) 0xFFFF034C)

// WATCHDOG TIMER

#define          T2BASE                                     (*(volatile unsigned long      *) 0xFFFF0360)
#define          T2LD                                       (*(volatile unsigned long      *) 0xFFFF0360)
#define          T2VAL                                      (*(volatile unsigned long      *) 0xFFFF0364)
#define          T2CON                                      (*(volatile unsigned long      *) 0xFFFF0368)
#define          T2CLRI                                     (*(volatile unsigned long      *) 0xFFFF036C)
#define          T2RCFG                                     (*(volatile unsigned long      *) 0xFFFF0370)

// TIMER 3

#define          T3BASE                                     (*(volatile unsigned long      *) 0xFFFF0380)
#define          T3LD                                       (*(volatile unsigned long      *) 0xFFFF0380)
#define          T3VAL                                      (*(volatile unsigned long      *) 0xFFFF0384)
#define          T3CON                                      (*(volatile unsigned long      *) 0xFFFF0388)
#define          T3CLRI                                     (*(volatile unsigned long      *) 0xFFFF038C)
#define          T3CAP                                      (*(volatile unsigned long      *) 0xFFFF0390)

// PLL AND OSCILLATOR CONTROL

#define          PLLBASE                                    (*(volatile unsigned long      *) 0xFFFF0400)
#define          POWKEY1                                    (*(volatile unsigned long      *) 0xFFFF0404)
#define          POWCON0                                    (*(volatile unsigned long      *) 0xFFFF0408)
#define          POWKEY2                                    (*(volatile unsigned long      *) 0xFFFF040C)
#define          PLLKEY1                                    (*(volatile unsigned long      *) 0xFFFF0410)
#define          PLLCON                                     (*(volatile unsigned long      *) 0xFFFF0414)
#define          PLLKEY2                                    (*(volatile unsigned long      *) 0xFFFF0418)
#define          GP0KEY1                                    (*(volatile unsigned long      *) 0xFFFF0464)
#define          GP0CON1                                    (*(volatile unsigned long      *) 0xFFFF0468)
#define          GP0KEY2                                    (*(volatile unsigned long      *) 0xFFFF046C)

// ADC INTERFACE REGISTERS

#define          ADCBASE                                    (*(volatile unsigned long      *) 0xFFFF0500)
#define          ADCSTA                                     (*(volatile unsigned long      *) 0xFFFF0500)
#define          ADCMSKI                                    (*(volatile unsigned long      *) 0xFFFF0504)
#define          ADCMDE                                     (*(volatile unsigned long      *) 0xFFFF0508)
#define          ADC0CON                                    (*(volatile unsigned long      *) 0xFFFF050C)
#define          ADC1CON                                    (*(volatile unsigned long      *) 0xFFFF0510)
#define          ADCFLT                                     (*(volatile unsigned long      *) 0xFFFF0514)
#define          ADCCFG                                     (*(volatile unsigned long      *) 0xFFFF0518)
#define          ADC0DAT                                    (*(volatile unsigned long      *) 0xFFFF051C)
#define          ADC1DAT                                    (*(volatile unsigned long      *) 0xFFFF0520)
#define          ADC0OF                                     (*(volatile unsigned long      *) 0xFFFF0524)
#define          ADC1OF                                     (*(volatile unsigned long      *) 0xFFFF0528)
#define          ADC0GN                                     (*(volatile unsigned long      *) 0xFFFF052C)
#define          ADC1GN                                     (*(volatile unsigned long      *) 0xFFFF0530)
#define          ADCORCR                                    (*(volatile unsigned long      *) 0xFFFF0534)
#define          ADCORCV                                    (*(volatile unsigned long      *) 0xFFFF0538)
#define          ADCOTH                                     (*(volatile unsigned long      *) 0xFFFF053C)
#define          ADCOTHC                                    (*(volatile unsigned long      *) 0xFFFF0540)
#define          ADCOTHV                                    (*(volatile unsigned long      *) 0xFFFF0544)
#define          ADCOACC                                    (*(volatile unsigned long      *) 0xFFFF0548)
#define          ADCOATH                                    (*(volatile unsigned long      *) 0xFFFF054C)
#define          IEXCON                                     (*(volatile unsigned long      *) 0xFFFF0570)

// DAC INTERFACE REGISTERS

#define          DACBASE                                    (*(volatile unsigned long      *) 0xFFFF0600)
#define          DACCON                                     (*(volatile unsigned long      *) 0xFFFF0600)
#define          DACDAT                                     (*(volatile unsigned long      *) 0xFFFF0604)

// 450 COMPATIABLE UART CORE REGISTERS

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
#define          COMSTA1                                    (*(volatile unsigned long      *) 0xFFFF0718)
#define          COMSCR                                     (*(volatile unsigned long      *) 0xFFFF071C)
#define          COMDIV2                                    (*(volatile unsigned long      *) 0xFFFF072C)

// I2C BUS PERIPHERAL DEVICE 

#define          I2CBASE                                    (*(volatile unsigned long      *) 0xFFFF0900)
#define          I2CMCON                                    (*(volatile unsigned long      *) 0xFFFF0900)
#define          I2CMSTA                                    (*(volatile unsigned long      *) 0xFFFF0904)
#define          I2CMRX                                     (*(volatile unsigned long      *) 0xFFFF0908)
#define          I2CMTX                                     (*(volatile unsigned long      *) 0xFFFF090C)
#define          I2CMCNT0                                   (*(volatile unsigned long      *) 0xFFFF0910)
#define          I2CMCNT1                                   (*(volatile unsigned long      *) 0xFFFF0914)
#define          I2CADR0                                    (*(volatile unsigned long      *) 0xFFFF0918)
#define          I2CADR1                                    (*(volatile unsigned long      *) 0xFFFF091C)
#define          I2CDIV                                     (*(volatile unsigned long      *) 0xFFFF0924)
#define          I2CSCON                                    (*(volatile unsigned long      *) 0xFFFF0928)
#define          I2CSSTA                                    (*(volatile unsigned long      *) 0xFFFF092C)
#define          I2CSRX                                     (*(volatile unsigned long      *) 0xFFFF0930)
#define          I2CSTX                                     (*(volatile unsigned long      *) 0xFFFF0934)
#define          I2CALT                                     (*(volatile unsigned long      *) 0xFFFF0938)
#define          I2CID0                                     (*(volatile unsigned long      *) 0xFFFF093C)
#define          I2CID1                                     (*(volatile unsigned long      *) 0xFFFF0940)
#define          I2CID2                                     (*(volatile unsigned long      *) 0xFFFF0944)
#define          I2CID3                                     (*(volatile unsigned long      *) 0xFFFF0948)
#define          I2CFSTA                                    (*(volatile unsigned long      *) 0xFFFF094C)

// SERIAL PORT INTERFACE PERIPHERAL

#define          SPIBASE                                    (*(volatile unsigned long      *) 0xFFFF0A00)
#define          SPISTA                                     (*(volatile unsigned long      *) 0xFFFF0A00)
#define          SPIRX                                      (*(volatile unsigned long      *) 0xFFFF0A04)
#define          SPITX                                      (*(volatile unsigned long      *) 0xFFFF0A08)
#define          SPIDIV                                     (*(volatile unsigned long      *) 0xFFFF0A0C)
#define          SPICON                                     (*(volatile unsigned long      *) 0xFFFF0A10)

// GPIO AND SERIAL PORT MUX

#define          GPIOBASE                                   (*(volatile unsigned long      *) 0xFFFF0D00)
#define          GP0CON0                                    (*(volatile unsigned long      *) 0xFFFF0D00)
#define          GP1CON                                     (*(volatile unsigned long      *) 0xFFFF0D04)
#define          GP2CON                                     (*(volatile unsigned long      *) 0xFFFF0D08)
#define          GP0DAT                                     (*(volatile unsigned long      *) 0xFFFF0D20)
#define          GP0SET                                     (*(volatile unsigned long      *) 0xFFFF0D24)
#define          GP0CLR                                     (*(volatile unsigned long      *) 0xFFFF0D28)
#define          GP0PAR                                     (*(volatile unsigned long      *) 0xFFFF0D2C)
#define          GP1DAT                                     (*(volatile unsigned long      *) 0xFFFF0D30)
#define          GP1SET                                     (*(volatile unsigned long      *) 0xFFFF0D34)
#define          GP1CLR                                     (*(volatile unsigned long      *) 0xFFFF0D38)
#define          GP1PAR                                     (*(volatile unsigned long      *) 0xFFFF0D3C)
#define          GP2DAT                                     (*(volatile unsigned long      *) 0xFFFF0D40)
#define          GP2SET                                     (*(volatile unsigned long      *) 0xFFFF0D44)
#define          GP2CLR                                     (*(volatile unsigned long      *) 0xFFFF0D48)
#define          GP2PAR                                     (*(volatile unsigned long      *) 0xFFFF0D4C)

// FLASH CONTROL INTERFACE

#define          FLASHBASE                                  (*(volatile unsigned long      *) 0xFFFF0E00)
#define          FEESTA                                     (*(volatile unsigned long      *) 0xFFFF0E00)
#define          FEEMOD                                     (*(volatile unsigned long      *) 0xFFFF0E04)
#define          FEECON                                     (*(volatile unsigned long      *) 0xFFFF0E08)
#define          FEEDAT                                     (*(volatile unsigned long      *) 0xFFFF0E0C)
#define          FEEADR                                     (*(volatile unsigned long      *) 0xFFFF0E10)
#define          FEESIG                                     (*(volatile unsigned long      *) 0xFFFF0E18)
#if           ALLOW_DEPRECATED_NAMES        
// "FEESIGN" has been deprecated. Use "FEESIG" instead.
#define          FEESIGN                                    (*(volatile unsigned long      *) 0xFFFF0E18)
#endif
#define          FEEPRO                                     (*(volatile unsigned long      *) 0xFFFF0E1C)
#define          FEEHID                                     (*(volatile unsigned long      *) 0xFFFF0E20)
#if           ALLOW_DEPRECATED_NAMES        
// "FEEHIDE" has been deprecated. Use "FEEHID" instead.
#define          FEEHIDE                                    (*(volatile unsigned long      *) 0xFFFF0E20)
#endif

// PWM

#define          PWMBASE                                    (*(volatile unsigned long      *) 0xFFFF0F80)
#define          PWMCON                                     (*(volatile unsigned long      *) 0xFFFF0F80)
#define          PWM0COM0                                   (*(volatile unsigned long      *) 0xFFFF0F84)
#define          PWM0COM1                                   (*(volatile unsigned long      *) 0xFFFF0F88)
#define          PWM0COM2                                   (*(volatile unsigned long      *) 0xFFFF0F8C)
#define          PWM0LEN                                    (*(volatile unsigned long      *) 0xFFFF0F90)
#define          PWM1COM0                                   (*(volatile unsigned long      *) 0xFFFF0F94)
#define          PWM1COM1                                   (*(volatile unsigned long      *) 0xFFFF0F98)
#define          PWM1COM2                                   (*(volatile unsigned long      *) 0xFFFF0F9C)
#define          PWM1LEN                                    (*(volatile unsigned long      *) 0xFFFF0FA0)
#define          PWM2COM0                                   (*(volatile unsigned long      *) 0xFFFF0FA4)
#define          PWM2COM1                                   (*(volatile unsigned long      *) 0xFFFF0FA8)
#define          PWM2COM2                                   (*(volatile unsigned long      *) 0xFFFF0FAC)
#define          PWM2LEN                                    (*(volatile unsigned long      *) 0xFFFF0FB0)
#define          PWMCLRI                                    (*(volatile unsigned long      *) 0xFFFF0FB8)
/*    Function Pointers for Interrupts  */
typedef void (* tyVctHndlr) (void);

extern tyVctHndlr    IRQ;
extern tyVctHndlr    SWI;
extern tyVctHndlr    FIQ;
extern tyVctHndlr    UNDEF;
extern tyVctHndlr    PABORT;
extern tyVctHndlr    DABORT;

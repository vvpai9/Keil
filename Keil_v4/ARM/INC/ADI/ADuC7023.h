// ===============================================														
// ADuC7023 HEADER FILE REV 1.4 11th September 2009														
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
#define          RSTKEY0                                    (*(volatile unsigned long      *) 0xFFFF0248)
#define          RSTCFG                                     (*(volatile unsigned long      *) 0xFFFF024C)
#define          RSTKEY1                                    (*(volatile unsigned long      *) 0xFFFF0250)

// TIMER 0

#define          T0BASE                                     (*(volatile unsigned long      *) 0xFFFF0300)
#define          T0LD                                       (*(volatile unsigned long      *) 0xFFFF0300)
#define          T0VAL                                      (*(volatile unsigned long      *) 0xFFFF0304)
#define          T0CON                                      (*(volatile unsigned long      *) 0xFFFF0308)
#define          T0CLRI                                     (*(volatile unsigned long      *) 0xFFFF030C)

// GENERAL PURPOSE TIMER

#define          T1BASE                                     (*(volatile unsigned long      *) 0xFFFF0320)
#define          T1LD                                       (*(volatile unsigned long      *) 0xFFFF0320)
#define          T1VAL                                      (*(volatile unsigned long      *) 0xFFFF0324)
#define          T1CON                                      (*(volatile unsigned long      *) 0xFFFF0328)
#define          T1CLRI                                     (*(volatile unsigned long      *) 0xFFFF032C)
#define          T1CAP                                      (*(volatile unsigned long      *) 0xFFFF0330)

// WATCHDOG TIMER

#define          T2BASE                                     (*(volatile unsigned long      *) 0xFFFF0360)
#define          T2LD                                       (*(volatile unsigned long      *) 0xFFFF0360)
#define          T2VAL                                      (*(volatile unsigned long      *) 0xFFFF0364)
#define          T2CON                                      (*(volatile unsigned long      *) 0xFFFF0368)
#define          T2CLRI                                     (*(volatile unsigned long      *) 0xFFFF036C)

// PLL AND OSCILLATOR CONTROL

#define          PLLBASE                                    (*(volatile unsigned long      *) 0xFFFF0400)
#define          PLLSTA                                     (*(volatile unsigned long      *) 0xFFFF0400)
#define          POWKEY1                                    (*(volatile unsigned long      *) 0xFFFF0404)
#define          POWCON                                     (*(volatile unsigned long      *) 0xFFFF0408)
#define          POWKEY2                                    (*(volatile unsigned long      *) 0xFFFF040C)
#define          PLLKEY1                                    (*(volatile unsigned long      *) 0xFFFF0410)
#define          PLLCON                                     (*(volatile unsigned long      *) 0xFFFF0414)
#define          PLLKEY2                                    (*(volatile unsigned long      *) 0xFFFF0418)

// GLOBAL PERIPHERAL CONTROL

#define          ALLBASE                                    (*(volatile unsigned long      *) 0xFFFF0434)
#define          POWKEY3                                    (*(volatile unsigned long      *) 0xFFFF0434)
#define          POWCON1                                    (*(volatile unsigned long      *) 0xFFFF0438)
#define          POWKEY4                                    (*(volatile unsigned long      *) 0xFFFF043C)

// POWER SUPPLY MONITOR

#define          PSMBASE                                    (*(volatile unsigned long      *) 0xFFFF0440)
#define          PSMCON                                     (*(volatile unsigned long      *) 0xFFFF0440)
#define          CMPCON                                     (*(volatile unsigned long      *) 0xFFFF0444)

// Band Gap Reference

#define          REFBASE                                    (*(volatile unsigned long      *) 0xFFFF0480)
#define          REFCON                                     (*(volatile unsigned long      *) 0xFFFF048C)

// ADC INTERFACE REGISTERS

#define          ADCBASE                                    (*(volatile unsigned long      *) 0xFFFF0500)
#define          ADCCON                                     (*(volatile unsigned long      *) 0xFFFF0500)
#define          ADCCP                                      (*(volatile unsigned long      *) 0xFFFF0504)
#define          ADCCN                                      (*(volatile unsigned long      *) 0xFFFF0508)
#define          ADCSTA                                     (*(volatile unsigned long      *) 0xFFFF050C)
#define          ADCDAT                                     (*(volatile unsigned long      *) 0xFFFF0510)
#define          ADCRST                                     (*(volatile unsigned long      *) 0xFFFF0514)
#define          ADCGN                                      (*(volatile unsigned long      *) 0xFFFF0530)
#define          ADCOF                                      (*(volatile unsigned long      *) 0xFFFF0534)
#define          TSCON                                      (*(volatile unsigned long      *) 0xFFFF0544)
#define          TEMPREF                                    (*(volatile unsigned long      *) 0xFFFF0548)

// DAC INTERFACE REGISTERS

#define          DACBASE                                    (*(volatile unsigned long      *) 0xFFFF0600)
#define          DAC0CON                                    (*(volatile unsigned long      *) 0xFFFF0600)
#define          DAC0DAT                                    (*(volatile unsigned long      *) 0xFFFF0604)
#define          DAC1CON                                    (*(volatile unsigned long      *) 0xFFFF0608)
#define          DAC1DAT                                    (*(volatile unsigned long      *) 0xFFFF060C)
#define          DAC2CON                                    (*(volatile unsigned long      *) 0xFFFF0610)
#define          DAC2DAT                                    (*(volatile unsigned long      *) 0xFFFF0614)
#define          DAC3CON                                    (*(volatile unsigned long      *) 0xFFFF0618)
#define          DAC3DAT                                    (*(volatile unsigned long      *) 0xFFFF061C)

// I2C0 BUS PERIPHERAL DEVICE 0

#define          I2C0BASE                                   (*(volatile unsigned long      *) 0xFFFF0800)
#define          I2C0MCON                                   (*(volatile unsigned long      *) 0xFFFF0800)
#define          I2C0MSTA                                   (*(volatile unsigned long      *) 0xFFFF0804)
#define          I2C0MRX                                    (*(volatile unsigned long      *) 0xFFFF0808)
#define          I2C0MTX                                    (*(volatile unsigned long      *) 0xFFFF080C)
#define          I2C0MCNT0                                  (*(volatile unsigned long      *) 0xFFFF0810)
#define          I2C0MCNT1                                  (*(volatile unsigned long      *) 0xFFFF0814)
#define          I2C0ADR0                                   (*(volatile unsigned long      *) 0xFFFF0818)
#define          I2C0ADR1                                   (*(volatile unsigned long      *) 0xFFFF081C)
#define          I2C0DIV                                    (*(volatile unsigned long      *) 0xFFFF0824)
#define          I2C0SCON                                   (*(volatile unsigned long      *) 0xFFFF0828)
#define          I2C0SSTA                                   (*(volatile unsigned long      *) 0xFFFF082C)
#define          I2C0SRX                                    (*(volatile unsigned long      *) 0xFFFF0830)
#define          I2C0STX                                    (*(volatile unsigned long      *) 0xFFFF0834)
#define          I2C0ALT                                    (*(volatile unsigned long      *) 0xFFFF0838)
#define          I2C0ID0                                    (*(volatile unsigned long      *) 0xFFFF083C)
#define          I2C0ID1                                    (*(volatile unsigned long      *) 0xFFFF0840)
#define          I2C0ID2                                    (*(volatile unsigned long      *) 0xFFFF0844)
#define          I2C0ID3                                    (*(volatile unsigned long      *) 0xFFFF0848)
#define          I2C0FSTA                                   (*(volatile unsigned long      *) 0xFFFF084C)

// I2C1 BUS PERIPHERAL DEVICE 0

#define          I2C1BASE                                   (*(volatile unsigned long      *) 0xFFFF0900)
#define          I2C1MCON                                   (*(volatile unsigned long      *) 0xFFFF0900)
#define          I2C1MSTA                                   (*(volatile unsigned long      *) 0xFFFF0904)
#define          I2C1MRX                                    (*(volatile unsigned long      *) 0xFFFF0908)
#define          I2C1MTX                                    (*(volatile unsigned long      *) 0xFFFF090C)
#define          I2C1MCNT0                                  (*(volatile unsigned long      *) 0xFFFF0910)
#define          I2C1MCNT1                                  (*(volatile unsigned long      *) 0xFFFF0914)
#define          I2C1ADR0                                   (*(volatile unsigned long      *) 0xFFFF0918)
#define          I2C1ADR1                                   (*(volatile unsigned long      *) 0xFFFF091C)
#define          I2C1DIV                                    (*(volatile unsigned long      *) 0xFFFF0924)
#define          I2C1SCON                                   (*(volatile unsigned long      *) 0xFFFF0828)
#define          I2C1SSTA                                   (*(volatile unsigned long      *) 0xFFFF092C)
#define          I2C1SRX                                    (*(volatile unsigned long      *) 0xFFFF0930)
#define          I2C1STX                                    (*(volatile unsigned long      *) 0xFFFF0934)
#define          I2C1ALT                                    (*(volatile unsigned long      *) 0xFFFF0938)
#define          I2C1ID0                                    (*(volatile unsigned long      *) 0xFFFF093C)
#define          I2C1ID1                                    (*(volatile unsigned long      *) 0xFFFF0940)
#define          I2C1ID2                                    (*(volatile unsigned long      *) 0xFFFF0944)
#define          I2C1ID3                                    (*(volatile unsigned long      *) 0xFFFF0948)
#define          I2C1FSTA                                   (*(volatile unsigned long      *) 0xFFFF094C)

// SERIAL PORT INTERFACE PERIPHERAL

#define          SPIBASE                                    (*(volatile unsigned long      *) 0xFFFF0A00)
#define          SPISTA                                     (*(volatile unsigned long      *) 0xFFFF0A00)
#define          SPIRX                                      (*(volatile unsigned long      *) 0xFFFF0A04)
#define          SPITX                                      (*(volatile unsigned long      *) 0xFFFF0A08)
#define          SPIDIV                                     (*(volatile unsigned long      *) 0xFFFF0A0C)
#define          SPICON                                     (*(volatile unsigned long      *) 0xFFFF0A10)

// PROGRAMABLE LOGIC ARRAY

#define          PLABASE                                    (*(volatile unsigned long      *) 0xFFFF0B00)
#define          PLAELM0                                    (*(volatile unsigned long      *) 0xFFFF0B00)
#define          PLAELM1                                    (*(volatile unsigned long      *) 0xFFFF0B04)
#define          PLAELM2                                    (*(volatile unsigned long      *) 0xFFFF0B08)
#define          PLAELM3                                    (*(volatile unsigned long      *) 0xFFFF0B0C)
#define          PLAELM4                                    (*(volatile unsigned long      *) 0xFFFF0B10)
#define          PLAELM5                                    (*(volatile unsigned long      *) 0xFFFF0B14)
#define          PLAELM6                                    (*(volatile unsigned long      *) 0xFFFF0B18)
#define          PLAELM7                                    (*(volatile unsigned long      *) 0xFFFF0B1C)
#define          PLAELM8                                    (*(volatile unsigned long      *) 0xFFFF0B20)
#define          PLAELM9                                    (*(volatile unsigned long      *) 0xFFFF0B24)
#define          PLAELM10                                   (*(volatile unsigned long      *) 0xFFFF0B28)
#define          PLAELM11                                   (*(volatile unsigned long      *) 0xFFFF0B2C)
#define          PLAELM12                                   (*(volatile unsigned long      *) 0xFFFF0B30)
#define          PLAELM13                                   (*(volatile unsigned long      *) 0xFFFF0B34)
#define          PLAELM14                                   (*(volatile unsigned long      *) 0xFFFF0B38)
#define          PLAELM15                                   (*(volatile unsigned long      *) 0xFFFF0B3C)
#define          PLACLK                                     (*(volatile unsigned long      *) 0xFFFF0B40)
#define          PLAIRQ                                     (*(volatile unsigned long      *) 0xFFFF0B44)
#define          PLAADC                                     (*(volatile unsigned long      *) 0xFFFF0B48)
#define          PLADIN                                     (*(volatile unsigned long      *) 0xFFFF0B4C)
#define          PLADOUT                                    (*(volatile unsigned long      *) 0xFFFF0B50)
#define          PLALCK                                     (*(volatile unsigned long      *) 0xFFFF0B54)

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

// GPIO AND SERIAL PORT MUX

#define          GPIOBASE                                   (*(volatile unsigned long      *) 0xFFFFF400)
#define          GP0CON                                     (*(volatile unsigned long      *) 0xFFFFF400)
#define          GP1CON                                     (*(volatile unsigned long      *) 0xFFFFF404)
#define          GP2CON                                     (*(volatile unsigned long      *) 0xFFFFF408)
#define          GP0DAT                                     (*(volatile unsigned long      *) 0xFFFFF420)
#define          GP0SET                                     (*(volatile unsigned long      *) 0xFFFFF424)
#define          GP0CLR                                     (*(volatile unsigned long      *) 0xFFFFF428)
#define          GP0PAR                                     (*(volatile unsigned long      *) 0xFFFFF42C)
#define          GP1DAT                                     (*(volatile unsigned long      *) 0xFFFFF430)
#define          GP1SET                                     (*(volatile unsigned long      *) 0xFFFFF434)
#define          GP1CLR                                     (*(volatile unsigned long      *) 0xFFFFF438)
#define          GP1PAR                                     (*(volatile unsigned long      *) 0xFFFFF43C)
#define          GP2DAT                                     (*(volatile unsigned long      *) 0xFFFFF440)
#define          GP2SET                                     (*(volatile unsigned long      *) 0xFFFFF444)
#define          GP2CLR                                     (*(volatile unsigned long      *) 0xFFFFF448)
#define          GP2PAR                                     (*(volatile unsigned long      *) 0xFFFFF44C)

// FLASH CONTROL INTERFACE

#define          FLASHBASE                                  (*(volatile unsigned long      *) 0xFFFFF800)
#define          FEESTA                                     (*(volatile unsigned long      *) 0xFFFFF800)
#define          FEEMOD                                     (*(volatile unsigned long      *) 0xFFFFF804)
#define          FEECON                                     (*(volatile unsigned long      *) 0xFFFFF808)
#define          FEEDAT                                     (*(volatile unsigned long      *) 0xFFFFF80C)
#define          FEEADR                                     (*(volatile unsigned long      *) 0xFFFFF810)
#define          FEESIGN                                    (*(volatile unsigned long      *) 0xFFFFF818)
#define          FEEPRO                                     (*(volatile unsigned long      *) 0xFFFFF81C)
#define          FEEHIDE                                    (*(volatile unsigned long      *) 0xFFFFF820)
/*    Function Pointers for Interrupts  */
typedef void (* tyVctHndlr) (void);

extern tyVctHndlr    IRQ;
extern tyVctHndlr    SWI;
extern tyVctHndlr    FIQ;
extern tyVctHndlr    UNDEF;
extern tyVctHndlr    PABORT;
extern tyVctHndlr    DABORT;

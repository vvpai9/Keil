// ===============================================                    											
//   ADuC7129 HEADER FILE REV 1.2                            														
//   REV 1.1- Updated DAC Registers														
//   REV 0.7- Removed ID register        											
//               -  Renamed REF0CON to REFCON											
//               -  Renamed ADCCHNP to ADCCP											
//               -  Renamed ADCCHNN to ADCCN											
//               -  Renamed UART0 and UART1 registers
//               -  Added I2C0ADR2 and I2C1ADR2 
//               -  Removed I2C0DIVL I2C0DIVH I2C1DIVL I2C1DIVH
//               -  Removed FEE0PAR FEE1PAR
//               -  Corrected QENCLR and QENSET addresses
//   REV 0.6- Comment removals        
//   REV 0.5- Fixed  COM0DIVL COM0DIVH COM1DIVL COM1DIVH I2C0DIVL I2C0DIVH I2C1DIVL & I2C1DIVH        
//   REV 0.4 - Added FEExPAR and corrected FEExSIGN registers         
//   REV 0.3 - General update based on Rev 1.2                        
//             Corrected REF0CON name                                 
//             Removed GP2PAR                                         
//             Added GP4CLR GP4PAR I2C0CCNT I2C0FSTA I2C1CCNT I2C1FSTA
//             Corrected ADCCHNP ADCCHNN names            
//             Add interrupt definitions - IAR
//   REV 0.2 - Fixed typos                                            
//   REV 0.1 - Initial                                                
// ===============================================                    											

// INTERRUPT CONTROLLER

#define          IRQBASE                                    (*(volatile unsigned long      *) 0xFFFF0000)
#define          IRQSTA                                     (*(volatile unsigned long      *) 0xFFFF0000)
#define          IRQSIG                                     (*(volatile unsigned long      *) 0xFFFF0004)
#define          IRQEN                                      (*(volatile unsigned long      *) 0xFFFF0008)
#define          IRQCLR                                     (*(volatile unsigned long      *) 0xFFFF000C)
#define          SWICFG                                     (*(volatile unsigned long      *) 0xFFFF0010)
#define          FIQSTA                                     (*(volatile unsigned long      *) 0xFFFF0100)
#define          FIQSIG                                     (*(volatile unsigned long      *) 0xFFFF0104)
#define          FIQEN                                      (*(volatile unsigned long      *) 0xFFFF0108)
#define          FIQCLR                                     (*(volatile unsigned long      *) 0xFFFF010C)

// REMAP AND SYSTEM CONTROL

#define          REMAPBASE                                  (*(volatile unsigned long      *) 0xFFFF0200)
#define          REMAP                                      (*(volatile unsigned long      *) 0xFFFF0220)
#define          RSTSET                                     (*(volatile unsigned long      *) 0xFFFF0230)
#define          RSTSTA                                     (*(volatile unsigned long      *) 0xFFFF0230)
#define          RSTCLR                                     (*(volatile unsigned long      *) 0xFFFF0234)

// TIMER 0

#define          T0BASE                                     (*(volatile unsigned long      *) 0xFFFF0300)
#define          T0LD                                       (*(volatile unsigned long      *) 0xFFFF0300)
#define          T0VAL0                                     (*(volatile unsigned long      *) 0xFFFF0304)
#define          T0VAL1                                     (*(volatile unsigned long      *) 0xFFFF0308)
#define          T0CON                                      (*(volatile unsigned long      *) 0xFFFF030C)
#define          T0ICLR                                     (*(volatile unsigned long      *) 0xFFFF0310)
#define          T0CAP                                      (*(volatile unsigned long      *) 0xFFFF0314)

// GENERAL PURPOSE TIMER

#define          T1BASE                                     (*(volatile unsigned long      *) 0xFFFF0320)
#define          T1LD                                       (*(volatile unsigned long      *) 0xFFFF0320)
#define          T1VAL                                      (*(volatile unsigned long      *) 0xFFFF0324)
#define          T1CON                                      (*(volatile unsigned long      *) 0xFFFF0328)
#define          T1ICLR                                     (*(volatile unsigned long      *) 0xFFFF032C)
#define          T1CAP                                      (*(volatile unsigned long      *) 0xFFFF0330)

// WAKE UP TIMER

#define          T2BASE                                     (*(volatile unsigned long      *) 0xFFFF0340)
#define          T2LD                                       (*(volatile unsigned long      *) 0xFFFF0340)
#define          T2VAL                                      (*(volatile unsigned long      *) 0xFFFF0344)
#define          T2CON                                      (*(volatile unsigned long      *) 0xFFFF0348)
#define          T2ICLR                                     (*(volatile unsigned long      *) 0xFFFF034C)

// WATCHDOG TIMER

#define          T3BASE                                     (*(volatile unsigned long      *) 0xFFFF0360)
#define          T3LD                                       (*(volatile unsigned long      *) 0xFFFF0360)
#define          T3VAL                                      (*(volatile unsigned long      *) 0xFFFF0364)
#define          T3CON                                      (*(volatile unsigned long      *) 0xFFFF0368)
#define          T3ICLR                                     (*(volatile unsigned long      *) 0xFFFF036C)

// GENERAL PURPOSE TIMER 4

#define          T4BASE                                     (*(volatile unsigned long      *) 0xFFFF0380)
#define          T4LD                                       (*(volatile unsigned long      *) 0xFFFF0380)
#define          T4VAL                                      (*(volatile unsigned long      *) 0xFFFF0384)
#define          T4CON                                      (*(volatile unsigned long      *) 0xFFFF0388)
#define          T4ICLR                                     (*(volatile unsigned long      *) 0xFFFF038C)
#define          T4CAP                                      (*(volatile unsigned long      *) 0xFFFF0390)

// PLL AND OSCILLATOR CONTROL

#define          PLLBASE                                    (*(volatile unsigned long      *) 0xFFFF0400)
#define          POWKEY1                                    (*(volatile unsigned long      *) 0xFFFF0404)
#define          POWCON                                     (*(volatile unsigned long      *) 0xFFFF0408)
#define          POWKEY2                                    (*(volatile unsigned long      *) 0xFFFF040C)
#define          PLLKEY1                                    (*(volatile unsigned long      *) 0xFFFF0410)
#define          PLLCON                                     (*(volatile unsigned long      *) 0xFFFF0414)
#define          PLLKEY2                                    (*(volatile unsigned long      *) 0xFFFF0418)

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

// DAC INTERFACE REGISTERS

#define          DACBASE                                    (*(volatile unsigned long      *) 0xFFFF0670)
#define          DACCON                                     (*(volatile unsigned long      *) 0xFFFF0670)
#define          DACDAT                                     (*(volatile unsigned long      *) 0xFFFF06B4)

// DDS INTERFACE REGISTERS

#define          DDSBASE                                    (*(volatile unsigned long      *) 0xFFFF0690)
#define          DDSCON                                     (*(volatile unsigned long      *) 0xFFFF0690)
#define          DDSFRQ                                     (*(volatile unsigned long      *) 0xFFFF0694)
#define          DDSPHS                                     (*(volatile unsigned long      *) 0xFFFF0698)
#define          DACKEY0                                    (*(volatile unsigned long      *) 0xFFFF06A4)
#define          DACEN                                      (*(volatile unsigned long      *) 0xFFFF06B8)
#define          DACKEY1                                    (*(volatile unsigned long      *) 0xFFFF06BC)

// 450 COMPATIABLE UART 0 CORE REGISTERS

#define          UART0BASE                                  (*(volatile unsigned long      *) 0xFFFF0700)
#define          COM0TX                                     (*(volatile unsigned long      *) 0xFFFF0700)
#define          COM0RX                                     (*(volatile unsigned long      *) 0xFFFF0700)
#define          COM0DIV0                                   (*(volatile unsigned long      *) 0xFFFF0700)
#define          COM0IEN0                                   (*(volatile unsigned long      *) 0xFFFF0704)
#define          COM0DIV1                                   (*(volatile unsigned long      *) 0xFFFF0704)
#define          COM0IID0                                   (*(volatile unsigned long      *) 0xFFFF0708)
#define          COM0CON0                                   (*(volatile unsigned long      *) 0xFFFF070C)
#define          COM0CON1                                   (*(volatile unsigned long      *) 0xFFFF0710)
#define          COM0STA0                                   (*(volatile unsigned long      *) 0xFFFF0714)
#define          COM0STA1                                   (*(volatile unsigned long      *) 0xFFFF0718)
#define          COM0SCR                                    (*(volatile unsigned long      *) 0xFFFF071C)
#define          COM0IEN1                                   (*(volatile unsigned long      *) 0xFFFF0720)
#define          COM0IID1                                   (*(volatile unsigned long      *) 0xFFFF0724)
#define          COM0ADR                                    (*(volatile unsigned long      *) 0xFFFF0728)
#define          COM0DIV2                                   (*(volatile unsigned long      *) 0xFFFF072C)

// 450 COMPATIABLE UART 1 CORE REGISTERS

#define          UART1BASE                                  (*(volatile unsigned long      *) 0xFFFF0740)
#define          COM1TX                                     (*(volatile unsigned long      *) 0xFFFF0740)
#define          COM1RX                                     (*(volatile unsigned long      *) 0xFFFF0740)
#define          COM1DIV0                                   (*(volatile unsigned long      *) 0xFFFF0740)
#define          COM1IEN0                                   (*(volatile unsigned long      *) 0xFFFF0744)
#define          COM1DIV1                                   (*(volatile unsigned long      *) 0xFFFF0744)
#define          COM1IID0                                   (*(volatile unsigned long      *) 0xFFFF0748)
#define          COM1CON0                                   (*(volatile unsigned long      *) 0xFFFF074C)
#define          COM1CON1                                   (*(volatile unsigned long      *) 0xFFFF0750)
#define          COM1STA0                                   (*(volatile unsigned long      *) 0xFFFF0754)
#define          COM1STA1                                   (*(volatile unsigned long      *) 0xFFFF0758)
#define          COM1SCR                                    (*(volatile unsigned long      *) 0xFFFF075C)
#define          COM1IEN1                                   (*(volatile unsigned long      *) 0xFFFF0760)
#define          COM1IID1                                   (*(volatile unsigned long      *) 0xFFFF0764)
#define          COM1ADR                                    (*(volatile unsigned long      *) 0xFFFF0768)
#define          COM1DIV2                                   (*(volatile unsigned long      *) 0xFFFF076C)

// I2C BUS PERIPHERAL DEVICE 0

#define          I2C0BASE                                   (*(volatile unsigned long      *) 0xFFFF0800)
#define          I2C0MSTA                                   (*(volatile unsigned long      *) 0xFFFF0800)
#define          I2C0SSTA                                   (*(volatile unsigned long      *) 0xFFFF0804)
#define          I2C0SRX                                    (*(volatile unsigned long      *) 0xFFFF0808)
#define          I2C0STX                                    (*(volatile unsigned long      *) 0xFFFF080C)
#define          I2C0MRX                                    (*(volatile unsigned long      *) 0xFFFF0810)
#define          I2C0MTX                                    (*(volatile unsigned long      *) 0xFFFF0814)
#define          I2C0CNT                                    (*(volatile unsigned long      *) 0xFFFF0818)
#define          I2C0ADR                                    (*(volatile unsigned long      *) 0xFFFF081C)
#define          I2C0BYT                                    (*(volatile unsigned long      *) 0xFFFF0824)
#define          I2C0ALT                                    (*(volatile unsigned long      *) 0xFFFF0828)
#define          I2C0CFG                                    (*(volatile unsigned long      *) 0xFFFF082C)
#define          I2C0DIV                                    (*(volatile unsigned long      *) 0xFFFF0830)
#define          I2C0ID0                                    (*(volatile unsigned long      *) 0xFFFF0838)
#define          I2C0ID1                                    (*(volatile unsigned long      *) 0xFFFF083C)
#define          I2C0ID2                                    (*(volatile unsigned long      *) 0xFFFF0840)
#define          I2C0ID3                                    (*(volatile unsigned long      *) 0xFFFF0844)
#define          I2C0SSC                                    (*(volatile unsigned long      *) 0xFFFF0848)
#define          I2C0FIF                                    (*(volatile unsigned long      *) 0xFFFF084C)

// I2C BUS PERIPHERAL DEVICE 1

#define          I2C1BASE                                   (*(volatile unsigned long      *) 0xFFFF0900)
#define          I2C1MSTA                                   (*(volatile unsigned long      *) 0xFFFF0900)
#define          I2C1SSTA                                   (*(volatile unsigned long      *) 0xFFFF0904)
#define          I2C1SRX                                    (*(volatile unsigned long      *) 0xFFFF0908)
#define          I2C1STX                                    (*(volatile unsigned long      *) 0xFFFF090C)
#define          I2C1MRX                                    (*(volatile unsigned long      *) 0xFFFF0910)
#define          I2C1MTX                                    (*(volatile unsigned long      *) 0xFFFF0914)
#define          I2C1CNT                                    (*(volatile unsigned long      *) 0xFFFF0918)
#define          I2C1ADR                                    (*(volatile unsigned long      *) 0xFFFF091C)
#define          I2C1BYT                                    (*(volatile unsigned long      *) 0xFFFF0924)
#define          I2C1ALT                                    (*(volatile unsigned long      *) 0xFFFF0928)
#define          I2C1CFG                                    (*(volatile unsigned long      *) 0xFFFF092C)
#define          I2C1DIV                                    (*(volatile unsigned long      *) 0xFFFF0930)
#define          I2C1ID0                                    (*(volatile unsigned long      *) 0xFFFF0938)
#define          I2C1ID1                                    (*(volatile unsigned long      *) 0xFFFF093C)
#define          I2C1ID2                                    (*(volatile unsigned long      *) 0xFFFF0940)
#define          I2C1ID3                                    (*(volatile unsigned long      *) 0xFFFF0944)
#define          I2C1SSC                                    (*(volatile unsigned long      *) 0xFFFF0948)
#define          I2C1FIF                                    (*(volatile unsigned long      *) 0xFFFF094C)

// SERIAL PERIPHERAL INTERFACE

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
#define          PLAOUT                                     (*(volatile unsigned long      *) 0xFFFF0B50)

// External Port

#define          EPBASE                                     (*(volatile unsigned long      *) 0xFFFF0C00)
#define          XMCFG                                      (*(volatile unsigned long      *) 0xFFFF0C00)
#define          XM0CON                                     (*(volatile unsigned long      *) 0xFFFF0C10)
#define          XM1CON                                     (*(volatile unsigned long      *) 0xFFFF0C14)
#define          XM2CON                                     (*(volatile unsigned long      *) 0xFFFF0C18)
#define          XM3CON                                     (*(volatile unsigned long      *) 0xFFFF0C1C)
#define          XM0PAR                                     (*(volatile unsigned long      *) 0xFFFF0C20)
#define          XM1PAR                                     (*(volatile unsigned long      *) 0xFFFF0C24)
#define          XM2PAR                                     (*(volatile unsigned long      *) 0xFFFF0C28)
#define          XM3PAR                                     (*(volatile unsigned long      *) 0xFFFF0C2C)

// GPIO AND SERIAL PORT MUX

#define          GPIOBASE                                   (*(volatile unsigned long      *) 0xFFFF0D00)
#define          GP0CON                                     (*(volatile unsigned long      *) 0xFFFF0D00)
#define          GP1CON                                     (*(volatile unsigned long      *) 0xFFFF0D04)
#define          GP2CON                                     (*(volatile unsigned long      *) 0xFFFF0D08)
#define          GP3CON                                     (*(volatile unsigned long      *) 0xFFFF0D0C)
#define          GP4CON                                     (*(volatile unsigned long      *) 0xFFFF0D10)
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
#define          GP3DAT                                     (*(volatile unsigned long      *) 0xFFFF0D50)
#define          GP3SET                                     (*(volatile unsigned long      *) 0xFFFF0D54)
#define          GP3CLR                                     (*(volatile unsigned long      *) 0xFFFF0D58)
#define          GP3PAR                                     (*(volatile unsigned long      *) 0xFFFF0D5C)
#define          GP4DAT                                     (*(volatile unsigned long      *) 0xFFFF0D60)
#define          GP4SET                                     (*(volatile unsigned long      *) 0xFFFF0D64)
#define          GP4CLR                                     (*(volatile unsigned long      *) 0xFFFF0D68)
#define          GP4PAR                                     (*(volatile unsigned long      *) 0xFFFF0D6C)

// FLASH CONTROL INTERFACE 0

#define          FLASH0BASE                                 (*(volatile unsigned long      *) 0xFFFF0E00)
#define          FEE0STA                                    (*(volatile unsigned long      *) 0xFFFF0E00)
#define          FEE0MOD                                    (*(volatile unsigned long      *) 0xFFFF0E04)
#define          FEE0CON                                    (*(volatile unsigned long      *) 0xFFFF0E08)
#define          FEE0DAT                                    (*(volatile unsigned long      *) 0xFFFF0E0C)
#define          FEE0ADR                                    (*(volatile unsigned long      *) 0xFFFF0E10)
#define          FEE0SGN                                    (*(volatile unsigned long      *) 0xFFFF0E18)
#define          FEE0PRO                                    (*(volatile unsigned long      *) 0xFFFF0E1C)
#define          FEE0HID                                    (*(volatile unsigned long      *) 0xFFFF0E20)

// FLASH CONTROL INTERFACE 1

#define          FLASH1BASE                                 (*(volatile unsigned long      *) 0xFFFF0E80)
#define          FEE1STA                                    (*(volatile unsigned long      *) 0xFFFF0E80)
#define          FEE1MOD                                    (*(volatile unsigned long      *) 0xFFFF0E84)
#define          FEE1CON                                    (*(volatile unsigned long      *) 0xFFFF0E88)
#define          FEE1DAT                                    (*(volatile unsigned long      *) 0xFFFF0E8C)
#define          FEE1ADR                                    (*(volatile unsigned long      *) 0xFFFF0E90)
#define          FEE1SGN                                    (*(volatile unsigned long      *) 0xFFFF0E98)
#define          FEE1PRO                                    (*(volatile unsigned long      *) 0xFFFF0E9C)
#define          FEE1HID                                    (*(volatile unsigned long      *) 0xFFFF0EA0)

// Quadrature Encoder

#define          QENBASE                                    (*(volatile unsigned long      *) 0xFFFF0F00)
#define          QENCON                                     (*(volatile unsigned long      *) 0xFFFF0F00)
#define          QENSTA                                     (*(volatile unsigned long      *) 0xFFFF0F04)
#define          QENDAT                                     (*(volatile unsigned long      *) 0xFFFF0F08)
#define          QENVAL                                     (*(volatile unsigned long      *) 0xFFFF0F0C)
#define          QENCLR                                     (*(volatile unsigned long      *) 0xFFFF0F14)
#define          QENSET                                     (*(volatile unsigned long      *) 0xFFFF0F18)

// Pulse Width Modulator

#define          PWMBASE                                    (*(volatile unsigned long      *) 0xFFFF0F80)
#define          PWMCON1                                    (*(volatile unsigned long      *) 0xFFFF0F80)
#define          PWM1COM1                                   (*(volatile unsigned long      *) 0xFFFF0F84)
#define          PWM1COM2                                   (*(volatile unsigned long      *) 0xFFFF0F88)
#define          PWM1COM3                                   (*(volatile unsigned long      *) 0xFFFF0F8C)
#define          PWM1LEN                                    (*(volatile unsigned long      *) 0xFFFF0F90)
#define          PWM2COM1                                   (*(volatile unsigned long      *) 0xFFFF0F94)
#define          PWM2COM2                                   (*(volatile unsigned long      *) 0xFFFF0F98)
#define          PWM2COM3                                   (*(volatile unsigned long      *) 0xFFFF0F9C)
#define          PWM2LEN                                    (*(volatile unsigned long      *) 0xFFFF0FA0)
#define          PWM3COM1                                   (*(volatile unsigned long      *) 0xFFFF0FA4)
#define          PWM3COM2                                   (*(volatile unsigned long      *) 0xFFFF0FA8)
#define          PWM3COM3                                   (*(volatile unsigned long      *) 0xFFFF0FAC)
#define          PWM3LEN                                    (*(volatile unsigned long      *) 0xFFFF0FB0)
#define          PWMCON2                                    (*(volatile unsigned long      *) 0xFFFF0FB4)
#define          PWMICLR                                    (*(volatile unsigned long      *) 0xFFFF0FB8)
/*    Function Pointers for Interrupts  */
typedef void (* tyVctHndlr) (void);

extern tyVctHndlr    IRQ;
extern tyVctHndlr    SWI;
extern tyVctHndlr    FIQ;
extern tyVctHndlr    UNDEF;
extern tyVctHndlr    PABORT;
extern tyVctHndlr    DABORT;

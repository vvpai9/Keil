// ===============================================															
// ADuC7122 HEADER FILE REV 1.3															
// ===============================================															

// Interrupt Controller

#define          INTBASE                                    (*(volatile unsigned long      *) 0xFFFF0000)
// Read only values of current masked IRQs
#define          IRQSTA                                     (*(volatile unsigned long      *) 0xFFFF0000)
// Read only values of current un-masked IRQs
#define          IRQSIG                                     (*(volatile unsigned long      *) 0xFFFF0004)
// IRQ Enable
#define          IRQEN                                      (*(volatile unsigned long      *) 0xFFFF0008)
// IRQ Clr
#define          IRQCLR                                     (*(volatile unsigned long      *) 0xFFFF000C)
// "IRQ Request Write sets IRQ, FIQ for bit position ‘0’"
#define          SWICFG                                     (*(volatile unsigned long      *) 0xFFFF0010)
// Used to indicate where in memory the vectors are stored.
#define          IRQBASE                                    (*(volatile unsigned long      *) 0xFFFF0014)
// IRQ interrupt vector
#define          IRQVEC                                     (*(volatile unsigned long      *) 0xFFFF001C)
// Set the interrupt priority
#define          IRQP0                                      (*(volatile unsigned long      *) 0xFFFF0020)
// Set the interrupt priority
#define          IRQP1                                      (*(volatile unsigned long      *) 0xFFFF0024)
// Set the interrupt priority
#define          IRQP2                                      (*(volatile unsigned long      *) 0xFFFF0028)
// Set the interrupt priority
#define          IRQP3                                      (*(volatile unsigned long      *) 0xFFFF002C)
// When asserted interrupt nesting is enabled for FIQ's or IRQ's
#define          IRQCONN                                    (*(volatile unsigned long      *) 0xFFFF0030)
// Determines if an interrupt is trrigger on rising/falling edge or low/high level.
#define          IRQCONE                                    (*(volatile unsigned long      *) 0xFFFF0034)
// Write a 1 to location to clear an interrupt that was triggered off an edge.
#define          IRQCLRE                                    (*(volatile unsigned long      *) 0xFFFF0038)
// Write/read the IRQ nest status for IRQ.
#define          IRQSTAN                                    (*(volatile unsigned long      *) 0xFFFF003C)
// Read only value of selected masked FIQ
#define          FIQSTA                                     (*(volatile unsigned long      *) 0xFFFF0100)
// Read only value of selected un-masked FIQ
#define          FIQSIG                                     (*(volatile unsigned long      *) 0xFFFF0104)
// FIQ Enable
#define          FIQEN                                      (*(volatile unsigned long      *) 0xFFFF0108)
// Write clears FIQ mask for each bit equal to logical ‘1’
#define          FIQCLR                                     (*(volatile unsigned long      *) 0xFFFF010C)
// Read the FIQ interrupt vector.
#define          FIQVEC                                     (*(volatile unsigned long      *) 0xFFFF011C)
// Write/Read the FIQ Nest status for FIQ's
#define          FIQSTAN                                    (*(volatile unsigned long      *) 0xFFFF013C)

// Remap and System Control

#define          REMAPBASE                                  (*(volatile unsigned long      *) 0xFFFF0200)
#define          REMAP                                      (*(volatile unsigned long      *) 0xFFFF0220)
#define          RSTSTA                                     (*(volatile unsigned long      *) 0xFFFF0230)
#define          RSTCLR                                     (*(volatile unsigned long      *) 0xFFFF0234)

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

// General Purpose Timer 4

#define          TIMER4BASE                                 (*(volatile unsigned long      *) 0xFFFF0380)
#define          T4LD                                       (*(volatile unsigned long      *) 0xFFFF0380)
#define          T4VAL                                      (*(volatile unsigned long      *) 0xFFFF0384)
#define          T4CON                                      (*(volatile unsigned long      *) 0xFFFF0388)
#define          T4CLRI                                     (*(volatile unsigned long      *) 0xFFFF038C)
#define          T4CAP                                      (*(volatile unsigned long      *) 0xFFFF0390)

// PLL and Oscillator Control

#define          PLLBASE                                    (*(volatile unsigned long      *) 0xFFFF0400)
#define          PLLSTA                                     (*(volatile unsigned long      *) 0xFFFF0400)
#define          POWKEY1                                    (*(volatile unsigned long      *) 0xFFFF0404)
#define          POWCON                                     (*(volatile unsigned long      *) 0xFFFF0408)
#define          POWKEY2                                    (*(volatile unsigned long      *) 0xFFFF040C)
#define          PLLKEY1                                    (*(volatile unsigned long      *) 0xFFFF0410)
#define          PLLCON                                     (*(volatile unsigned long      *) 0xFFFF0414)
#define          PLLKEY2                                    (*(volatile unsigned long      *) 0xFFFF0418)

// Power Supply Monitor

#define          PSMBASE                                    (*(volatile unsigned long      *) 0xFFFF0440)
#define          PSMCON                                     (*(volatile unsigned long      *) 0xFFFF0440)

// Band Gap Reference

#define          BANDGAPBASE                                (*(volatile unsigned long      *) 0xFFFF0480)
#define          REFCON                                     (*(volatile unsigned long      *) 0xFFFF0480)

// ADC interface registers

#define          ADCBASE                                    (*(volatile unsigned long      *) 0xFFFF0500)
#define          ADCCON                                     (*(volatile unsigned long      *) 0xFFFF0500)
#define          ADCCP                                      (*(volatile unsigned long      *) 0xFFFF0504)
#define          ADCCN                                      (*(volatile unsigned long      *) 0xFFFF0508)
#define          ADCSTA                                     (*(volatile unsigned long      *) 0xFFFF050C)
#define          ADCDAT                                     (*(volatile unsigned long      *) 0xFFFF0510)
#define          ADCRST                                     (*(volatile unsigned long      *) 0xFFFF0514)
#define          ADCGN                                      (*(volatile unsigned long      *) 0xFFFF0518)
#define          ADCOF                                      (*(volatile unsigned long      *) 0xFFFF051C)
#define          PGAGN                                      (*(volatile unsigned long      *) 0xFFFF0520)

// DAC Interface Peripheral

#define          DACBASE                                    (*(volatile unsigned long      *) 0xFFFF0580)
// DAC0 Control Register
#define          DAC0CON                                    (*(volatile unsigned long      *) 0xFFFF0580)
// DAC0 Data Register
#define          DAC0DAT                                    (*(volatile unsigned long      *) 0xFFFF0584)
// DAC1 Control Register
#define          DAC1CON                                    (*(volatile unsigned long      *) 0xFFFF0588)
// DAC1 Data Register
#define          DAC1DAT                                    (*(volatile unsigned long      *) 0xFFFF058C)
// DAC2 Control Register
#define          DAC2CON                                    (*(volatile unsigned long      *) 0xFFFF0590)
// DAC2 Data Register
#define          DAC2DAT                                    (*(volatile unsigned long      *) 0xFFFF0594)
// DAC3 Control Register
#define          DAC3CON                                    (*(volatile unsigned long      *) 0xFFFF0598)
// DAC3 Data Register
#define          DAC3DAT                                    (*(volatile unsigned long      *) 0xFFFF059C)
// DAC4 Control Register
#define          DAC4CON                                    (*(volatile unsigned long      *) 0xFFFF05A0)
// DAC4 Data Register
#define          DAC4DAT                                    (*(volatile unsigned long      *) 0xFFFF05A4)
// DAC5 Control Register
#define          DAC5CON                                    (*(volatile unsigned long      *) 0xFFFF05A8)
// DAC5 Data Register
#define          DAC5DAT                                    (*(volatile unsigned long      *) 0xFFFF05AC)
// DAC6 Control Register
#define          DAC6CON                                    (*(volatile unsigned long      *) 0xFFFF05B0)
// DAC6 Data Register
#define          DAC6DAT                                    (*(volatile unsigned long      *) 0xFFFF05B4)
// DAC7 Control Register
#define          DAC7CON                                    (*(volatile unsigned long      *) 0xFFFF05B8)
// DAC7 Data Register
#define          DAC7DAT                                    (*(volatile unsigned long      *) 0xFFFF05BC)
// DAC8 Control Register
#define          DAC8CON                                    (*(volatile unsigned long      *) 0xFFFF05C0)
// DAC8 Data Register
#define          DAC8DAT                                    (*(volatile unsigned long      *) 0xFFFF05C4)
// DAC9 Control Register
#define          DAC9CON                                    (*(volatile unsigned long      *) 0xFFFF05C8)
// DAC9 Data Register
#define          DAC9DAT                                    (*(volatile unsigned long      *) 0xFFFF05CC)
// DAC10 Control Register
#define          DAC10CON                                   (*(volatile unsigned long      *) 0xFFFF05D0)
// DAC10 Data Register
#define          DAC10DAT                                   (*(volatile unsigned long      *) 0xFFFF05D4)
// DAC11 Control Register
#define          DAC11CON                                   (*(volatile unsigned long      *) 0xFFFF05D8)
// DAC11 Data Register
#define          DAC11DAT                                   (*(volatile unsigned long      *) 0xFFFF05DC)

// 450 Compatible UART core registers

#define          UARTBASE                                   (*(volatile unsigned long      *) 0xFFFF0800)
// Transmit Holding register
#define          COMTX                                      (*(volatile unsigned long      *) 0xFFFF0800)
// Receive Buffer register
#define          COMRX                                      (*(volatile unsigned long      *) 0xFFFF0800)
// Divisor Latch Low byte register
#define          COMDIV0                                    (*(volatile unsigned long      *) 0xFFFF0800)
// Interrupt Enable register
#define          COMIEN0                                    (*(volatile unsigned long      *) 0xFFFF0804)
// Divisor Latch High byte register
#define          COMDIV1                                    (*(volatile unsigned long      *) 0xFFFF0804)
// Interrupt Identification register
#define          COMIID0                                    (*(volatile unsigned long      *) 0xFFFF0808)
// Line Control register
#define          COMCON0                                    (*(volatile unsigned long      *) 0xFFFF080C)
// Module Control register
#define          COMCON1                                    (*(volatile unsigned long      *) 0xFFFF0810)
// Line Status register
#define          COMSTA0                                    (*(volatile unsigned long      *) 0xFFFF0814)
// Modem Status register
#define          COMSTA1                                    (*(volatile unsigned long      *) 0xFFFF0818)
// Modem Interrupts
#define          COMIID1                                    (*(volatile unsigned long      *) 0xFFFF0824)
// Fraction divider register.
#define          COMDIV2                                    (*(volatile unsigned long      *) 0xFFFF082C)

// I2C0 Port Interface Peripheral

#define          I2C0BASE                                   (*(volatile unsigned long      *) 0xFFFF0880)
// Master control register.
#define          I2C0MCON                                   (*(volatile unsigned long      *) 0xFFFF0880)
// "Master Status, Error, and IRQ register."
#define          I2C0MSTA                                   (*(volatile unsigned long      *) 0xFFFF0884)
// Master receive data register.
#define          I2C0MRX                                    (*(volatile unsigned long      *) 0xFFFF0888)
// Master transmit data register.
#define          I2C0MTX                                    (*(volatile unsigned long      *) 0xFFFF088C)
// Master receive data count register.
#define          I2C0MCNT0                                  (*(volatile unsigned long      *) 0xFFFF0890)
// Master current receive count register
#define          I2C0MCNT1                                  (*(volatile unsigned long      *) 0xFFFF0894)
// 1st Master Address byte register
#define          I2C0ADR0                                   (*(volatile unsigned long      *) 0xFFFF0898)
// 2nd Master Address byte register
#define          I2C0ADR1                                   (*(volatile unsigned long      *) 0xFFFF089C)
// Serial clock period divisor register
#define          I2C0DIV                                    (*(volatile unsigned long      *) 0xFFFF08A4)
// Slave control register
#define          I2C0SCON                                   (*(volatile unsigned long      *) 0xFFFF08A8)
// Slave status register
#define          I2C0SSTA                                   (*(volatile unsigned long      *) 0xFFFF08AC)
// Slave receive data register
#define          I2C0SRX                                    (*(volatile unsigned long      *) 0xFFFF08B0)
// Slave transmit data register
#define          I2C0STX                                    (*(volatile unsigned long      *) 0xFFFF08B4)
// Slave ALT register
#define          I2C0ALT                                    (*(volatile unsigned long      *) 0xFFFF08B8)
// Slave ID register 0
#define          I2C0ID0                                    (*(volatile unsigned long      *) 0xFFFF08BC)
// Slave ID register 1
#define          I2C0ID1                                    (*(volatile unsigned long      *) 0xFFFF08C0)
// Slave ID register 2
#define          I2C0ID2                                    (*(volatile unsigned long      *) 0xFFFF08C4)
// Slave ID register 3
#define          I2C0ID3                                    (*(volatile unsigned long      *) 0xFFFF08C8)
// FIFO status register
#define          I2C0FSTA                                   (*(volatile unsigned long      *) 0xFFFF08CC)

// I2C1 Port Interface Peripheral

#define          I2C1BASE                                   (*(volatile unsigned long      *) 0xFFFF0900)
// Master control register.
#define          I2C1MCON                                   (*(volatile unsigned long      *) 0xFFFF0900)
// "Master Status, Error, and IRQ register."
#define          I2C1MSTA                                   (*(volatile unsigned long      *) 0xFFFF0904)
// Master receive data register.
#define          I2C1MRX                                    (*(volatile unsigned long      *) 0xFFFF0908)
// Master transmit data register.
#define          I2C1MTX                                    (*(volatile unsigned long      *) 0xFFFF090C)
// Master receive data count register.
#define          I2C1MCNT0                                  (*(volatile unsigned long      *) 0xFFFF0910)
// Master current receive count register
#define          I2C1MCNT1                                  (*(volatile unsigned long      *) 0xFFFF0914)
// 1st Master Address byte register
#define          I2C1ADR0                                   (*(volatile unsigned long      *) 0xFFFF0918)
// 2nd Master Address byte register
#define          I2C1ADR1                                   (*(volatile unsigned long      *) 0xFFFF091C)
// Serial clock period divisor register
#define          I2C1DIV                                    (*(volatile unsigned long      *) 0xFFFF0924)
// Slave control register
#define          I2C1SCON                                   (*(volatile unsigned long      *) 0xFFFF0928)
// Slave status register
#define          I2C1SSTA                                   (*(volatile unsigned long      *) 0xFFFF092C)
// Slave receive data register
#define          I2C1SRX                                    (*(volatile unsigned long      *) 0xFFFF0930)
// Slave transmit data register
#define          I2C1STX                                    (*(volatile unsigned long      *) 0xFFFF0934)
// Slave ALT register
#define          I2C1ALT                                    (*(volatile unsigned long      *) 0xFFFF0938)
// Slave ID register 0
#define          I2C1ID0                                    (*(volatile unsigned long      *) 0xFFFF093C)
// Slave ID register 1
#define          I2C1ID1                                    (*(volatile unsigned long      *) 0xFFFF0940)
// Slave ID register 2
#define          I2C1ID2                                    (*(volatile unsigned long      *) 0xFFFF0944)
// Slave ID register 3
#define          I2C1ID3                                    (*(volatile unsigned long      *) 0xFFFF0948)
// FIFO status register
#define          I2C1FSTA                                   (*(volatile unsigned long      *) 0xFFFF094C)

// Serial Port Interface Peripheral

#define          SPIBASE                                    (*(volatile unsigned long      *) 0xFFFF0A00)
// "Read only SPI Status, Error, and IRQ Register"
#define          SPISTA                                     (*(volatile unsigned long      *) 0xFFFF0A00)
// Read only SPI Receive Data Register
#define          SPIRX                                      (*(volatile unsigned long      *) 0xFFFF0A04)
// Write only SPI Transmit Data Register
#define          SPITX                                      (*(volatile unsigned long      *) 0xFFFF0A08)
// Serial Clock Divisor Register
#define          SPIDIV                                     (*(volatile unsigned long      *) 0xFFFF0A0C)
// Configuration Register
#define          SPICON                                     (*(volatile unsigned long      *) 0xFFFF0A10)

// PROGRAMABLE LOGIC ARRAY

#define          PLABASE                                    (*(volatile unsigned long      *) 0xFFFF0B00)
// PLA Element 0 configuration
#define          PLAELM0                                    (*(volatile unsigned long      *) 0xFFFF0B00)
// PLA Element 1 configuration
#define          PLAELM1                                    (*(volatile unsigned long      *) 0xFFFF0B04)
// PLA Element 2 configuration
#define          PLAELM2                                    (*(volatile unsigned long      *) 0xFFFF0B08)
// PLA Element 3 configuration
#define          PLAELM3                                    (*(volatile unsigned long      *) 0xFFFF0B0C)
// PLA Element 4 configuration
#define          PLAELM4                                    (*(volatile unsigned long      *) 0xFFFF0B10)
// PLA Element 5 configuration
#define          PLAELM5                                    (*(volatile unsigned long      *) 0xFFFF0B14)
// PLA Element 6 configuration
#define          PLAELM6                                    (*(volatile unsigned long      *) 0xFFFF0B18)
// PLA Element 7 configuration
#define          PLAELM7                                    (*(volatile unsigned long      *) 0xFFFF0B1C)
// PLA Element 8 configuration
#define          PLAELM8                                    (*(volatile unsigned long      *) 0xFFFF0B20)
// PLA Element 9 configuration
#define          PLAELM9                                    (*(volatile unsigned long      *) 0xFFFF0B24)
// PLA Element 10 configuration
#define          PLAELM10                                   (*(volatile unsigned long      *) 0xFFFF0B28)
// PLA Element 11 configuration
#define          PLAELM11                                   (*(volatile unsigned long      *) 0xFFFF0B2C)
// PLA Element 12 configuration
#define          PLAELM12                                   (*(volatile unsigned long      *) 0xFFFF0B30)
// PLA Element 13 configuration
#define          PLAELM13                                   (*(volatile unsigned long      *) 0xFFFF0B34)
// PLA Element 14 configuration
#define          PLAELM14                                   (*(volatile unsigned long      *) 0xFFFF0B38)
// PLA Element 15 configuration
#define          PLAELM15                                   (*(volatile unsigned long      *) 0xFFFF0B3C)
// PLA clock select
#define          PLACLK                                     (*(volatile unsigned long      *) 0xFFFF0B40)
// PLA source for irq 0 and irq 1
#define          PLAIRQ                                     (*(volatile unsigned long      *) 0xFFFF0B44)
// PLA source for ADC start convert
#define          PLAADC                                     (*(volatile unsigned long      *) 0xFFFF0B48)
// AMBA bus data input for PLA
#define          PLADIN                                     (*(volatile unsigned long      *) 0xFFFF0B4C)
// AMBA bus data output from PLA
#define          PLAOUT                                     (*(volatile unsigned long      *) 0xFFFF0B50)

// GPIO AND SERIAL PORT MUX

#define          GPIOBASE                                   (*(volatile unsigned long      *) 0xFFFF0D00)
// Enable port 0
#define          GP0CON                                     (*(volatile unsigned long      *) 0xFFFF0D00)
// Enable port 1
#define          GP1CON                                     (*(volatile unsigned long      *) 0xFFFF0D04)
// Enable port 2
#define          GP2CON                                     (*(volatile unsigned long      *) 0xFFFF0D08)
// Enable port 3
#define          GP3CON                                     (*(volatile unsigned long      *) 0xFFFF0D0C)
// GPIO Port0 Data Bit Register
#define          GP0DAT                                     (*(volatile unsigned long      *) 0xFFFF0D20)
// GPIO Port0 Data Bit Set Register
#define          GP0SET                                     (*(volatile unsigned long      *) 0xFFFF0D24)
// GPIO Port0 Data Bit Clear Register
#define          GP0CLR                                     (*(volatile unsigned long      *) 0xFFFF0D28)
// GPIO Port0 CON & DAT register
#define          GP0PAR                                     (*(volatile unsigned long      *) 0xFFFF0D2C)
// GPIO Port1 Data Bit Register
#define          GP1DAT                                     (*(volatile unsigned long      *) 0xFFFF0D30)
// GPIO Port1 Data Bit Set Register
#define          GP1SET                                     (*(volatile unsigned long      *) 0xFFFF0D34)
// GPIO Port1 Data Bit Clear Register
#define          GP1CLR                                     (*(volatile unsigned long      *) 0xFFFF0D38)
// GPIO Port1 CON & DAT register
#define          GP1PAR                                     (*(volatile unsigned long      *) 0xFFFF0D3C)
// GPIO Port2 Data Bit Register
#define          GP2DAT                                     (*(volatile unsigned long      *) 0xFFFF0D40)
// GPIO Port2 Data Bit Set Register
#define          GP2SET                                     (*(volatile unsigned long      *) 0xFFFF0D44)
// GPIO Port2 Data Bit Clear Register
#define          GP2CLR                                     (*(volatile unsigned long      *) 0xFFFF0D48)
// GPIO Port2 CON & DAT register
#define          GP2PAR                                     (*(volatile unsigned long      *) 0xFFFF0D4C)
// GPIO Port3 Data Bit Register
#define          GP3DAT                                     (*(volatile unsigned long      *) 0xFFFF0D50)
// GPIO Port3 Data Bit Set Register
#define          GP3SET                                     (*(volatile unsigned long      *) 0xFFFF0D54)
// GPIO Port3 Data Bit Clear Register
#define          GP3CLR                                     (*(volatile unsigned long      *) 0xFFFF0D58)
// GPIO Port3 CON & DAT register
#define          GP3PAR                                     (*(volatile unsigned long      *) 0xFFFF0D5C)
// GPIO Port1 OC enable
#define          GP1OCE                                     (*(volatile unsigned long      *) 0xFFFF0D70)
// GPIO Port2 OC enable
#define          GP2OCE                                     (*(volatile unsigned long      *) 0xFFFF0D74)
// GPIO Port3 OC enable
#define          GP3OCE                                     (*(volatile unsigned long      *) 0xFFFF0D78)

// Flash Control Interface 0

#define          FLASH0BASE                                 (*(volatile unsigned long      *) 0xFFFF0E00)
// Command Status Register
#define          FEE0STA                                    (*(volatile unsigned long      *) 0xFFFF0E00)
// Mode Register
#define          FEE0MOD                                    (*(volatile unsigned long      *) 0xFFFF0E04)
// Command Code Interpreter
#define          FEE0CON                                    (*(volatile unsigned long      *) 0xFFFF0E08)
// "Data Register, data to be written or verified (32 bits)"
#define          FEE0DAT                                    (*(volatile unsigned long      *) 0xFFFF0E0C)
// "Command Location Index, memory array sector address"
#define          FEE0ADR                                    (*(volatile unsigned long      *) 0xFFFF0E10)
// Code signature onto 24 bits LFSR
#define          FEE0SIG                                    (*(volatile unsigned long      *) 0xFFFF0E18)
// 32bits used for user write protection
#define          FEE0PRO                                    (*(volatile unsigned long      *) 0xFFFF0E1C)
// "Protection download, writable with key only"
#define          FEE0HID                                    (*(volatile unsigned long      *) 0xFFFF0E20)

// Flash Control Interface 1

#define          FLASH1BASE                                 (*(volatile unsigned long      *) 0xFFFF0E80)
// Command Status Register
#define          FEE1STA                                    (*(volatile unsigned long      *) 0xFFFF0E80)
// Mode Register
#define          FEE1MOD                                    (*(volatile unsigned long      *) 0xFFFF0E84)
// Command Code Interpreter
#define          FEE1CON                                    (*(volatile unsigned long      *) 0xFFFF0E88)
// "Data Register, data to be written or verified (32 bits)"
#define          FEE1DAT                                    (*(volatile unsigned long      *) 0xFFFF0E8C)
// "Command Location Index, memory array sector address"
#define          FEE1ADR                                    (*(volatile unsigned long      *) 0xFFFF0E90)
// Code signature onto 24 bits LFSR
#define          FEE1SIG                                    (*(volatile unsigned long      *) 0xFFFF0E98)
// 32bits used for user write protection
#define          FEE1PRO                                    (*(volatile unsigned long      *) 0xFFFF0E9C)
// "Protection download, writable with key only"
#define          FEE1HID                                    (*(volatile unsigned long      *) 0xFFFF0EA0)

// Pulse Width Modulator

#define          PWMBASE                                    (*(volatile unsigned long      *) 0xFFFF0F80)
// PWM Control
#define          PWMCON1                                    (*(volatile unsigned long      *) 0xFFFF0F80)
// Compare register 1 for PWM o/ps 1 and 2
#define          PWM1COM1                                   (*(volatile unsigned long      *) 0xFFFF0F84)
// Compare register 2 for PWM o/ps 1 and 2
#define          PWM1COM2                                   (*(volatile unsigned long      *) 0xFFFF0F88)
// Compare register 3 for PWM o/ps 1 and 2
#define          PWM1COM3                                   (*(volatile unsigned long      *) 0xFFFF0F8C)
// Frequency Control for PWM o/ps 1 and 2
#define          PWM1LEN                                    (*(volatile unsigned long      *) 0xFFFF0F90)
// Compare register 1 for PWM o/ps 3 and 4
#define          PWM2COM1                                   (*(volatile unsigned long      *) 0xFFFF0F94)
// Compare register 2 for PWM o/ps 3 and 4
#define          PWM2COM2                                   (*(volatile unsigned long      *) 0xFFFF0F98)
// Compare register 3 for PWM o/ps 3 and 4
#define          PWM2COM3                                   (*(volatile unsigned long      *) 0xFFFF0F9C)
// Frequency Control for PWM o/ps 3 and 4
#define          PWM2LEN                                    (*(volatile unsigned long      *) 0xFFFF0FA0)
// Compare register 1 for PWM o/ps 5 and 6
#define          PWM3COM1                                   (*(volatile unsigned long      *) 0xFFFF0FA4)
// Compare register 2 for PWM o/ps 5 and 6
#define          PWM3COM2                                   (*(volatile unsigned long      *) 0xFFFF0FA8)
// Compare register 3 for PWM o/ps 5 and 6
#define          PWM3COM3                                   (*(volatile unsigned long      *) 0xFFFF0FAC)
// Frequency Control for PWM o/ps 5 and 6
#define          PWM3LEN                                    (*(volatile unsigned long      *) 0xFFFF0FB0)
// PWM Convert Start Control
#define          PWMCON2                                    (*(volatile unsigned long      *) 0xFFFF0FB4)
// PWM Interrupt Clear
#define          PWMCLRI                                    (*(volatile unsigned long      *) 0xFFFF0FB8)
/*    Function Pointers for Interrupts  */
typedef void (* tyVctHndlr) (void);

extern tyVctHndlr    IRQ;
extern tyVctHndlr    SWI;
extern tyVctHndlr    FIQ;
extern tyVctHndlr    UNDEF;
extern tyVctHndlr    PABORT;
extern tyVctHndlr    DABORT;

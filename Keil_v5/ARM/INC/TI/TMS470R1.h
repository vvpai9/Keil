/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2006                                  */
/******************************************************************************/
/*                                                                            */
/*  TMS470R1.h:   Header file for Texas Instruments TMS470R1xxxx              */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* Abbreviations used in this file:                                           */
/* Reg = Register                                                             */
/* Int = Interrupt                                                            */
/* Req = Request                                                              */
/******************************************************************************/

#ifndef __TMS470R1_H
#define __TMS470R1_H

/* Absolute addresses of register structures                                  */
#define MPU_BASE       0xFFFFFE00       /* Memory Protection Unit address     */
#define SM_BASE        0xFFFFFD00       /* System Module address              */
#define IEM_BASE       0xFFFFFC00       /* Interrupt Expansion Module address */
#define MSM1_BASE      0xFFFFF700       /* Memory Security Module 1 address   */
#define MSM2_BASE      0xFFFFF600       /* Memory Security Module 2 address   */
#define HET_BASE       0xFFF7FC00       /* HET  address                       */
#define SPI1_BASE      0xFFF7F800       /* Ser Peripheral Interface 1 address */
#define SCI3_BASE      0xFFF7F600       /* SCI3 address                       */
#define SCI2_BASE      0xFFF7F500       /* SCI2 address                       */
#define SCI1_BASE      0xFFF7F400       /* SCI1 address                       */
#define MIBADC_BASE    0xFFF7F000       /* MIBADC address                     */
#define ECP_BASE       0xFFF7EF00       /* External Clock Prescale address    */
#define EBM_BASE       0xFFF7ED00       /* Expansion Bus Module address       */
#define GIO_BASE       0xFFF7EC00       /* GIO address                        */
#define HECC2_BASE     0xFFF7EA00       /* High-End CAN2 Controller address   */
#define HECC1_BASE     0xFFF7E800       /* High-End CAN1 Controller address   */
#define HECC2_RAM_BASE 0xFFF7E600       /* High-End CAN2 RAM address          */
#define HECC1_RAM_BASE 0xFFF7E400       /* High-End CAN1 RAM address          */
#define SCC2_BASE      0xFFF7E200       /* Standard CAN2 Controller address   */
#define SCC1_BASE      0xFFF7E000       /* Standard CAN1 Controller address   */
#define SCC2_RAM_BASE  0xFFF7DE00       /* Standard CAN2 RAM address          */
#define SCC1_RAM_BASE  0xFFF7DC00       /* Standard CAN1 RAM address          */
#define I2C4_BASE      0xFFF7DB00       /* Inter-Integrated Circuit 4 address */
#define I2C3_BASE      0xFFF7DA00       /* Inter-Integrated Circuit 3 address */
#define I2C2_BASE      0xFFF7D900       /* Inter-Integrated Circuit 2 address */
#define I2C1_BASE      0xFFF7D800       /* Inter-Integrated Circuit 1 address */
#define I2C5_BASE      0xFFF7D500       /* Inter-Integrated Circuit 5 address */
#define SPI2_BASE      0xFFF7D400       /* Ser Peripheral Interface 2 address */
#define C2SIB_BASE     0xFFF7C800       /* CS2IB address                      */
#define FM_BASE        0xFFE88000       /* Flash Module address               */


/* Macro definitions                                                          */
typedef volatile unsigned char      REG_8;
typedef volatile unsigned short int REG_16;
typedef volatile unsigned int       REG_32;

/* Enable both names GLBCTRL and GCR for Global Control Register              */
#define GLBCTRL        GCR


/* System Module                                                              */
typedef struct {
  /* Bus Structure Registers                                                  */
  REG_32 SMCR0;                         /* Static Memory Control Register 0   */
  REG_32 SMCR1;                         /* Static Memory Control Register 1   */
  REG_32 SMCR2;                         /* Static Memory Control Register 2   */
  REG_32 SMCR3;                         /* Static Memory Control Register 3   */
  REG_32 SMCR4;                         /* Static Memory Control Register 4   */
  REG_32 SMCR5;                         /* Static Memory Control Register 5   */
  REG_32 SMCR6;                         /* Static Memory Control Register 6   */
  REG_32 SMCR7;                         /* Static Memory Control Register 7   */
  REG_32 SMCR8;                         /* Static Memory Control Register 8   */
  REG_32 SMCR9;                         /* Static Memory Control Register 9   */
  REG_32 Reserved0;
  REG_32 WCR0;                          /* Write Control Register             */
  REG_32 PCR;                           /* Peripheral Clock Register          */
  REG_32 PLR;                           /* Peripheral Location Register       */
  REG_32 PPROT;                         /* Peripheral Protection Register     */
  REG_32 Reserved1[49];

  /* Memory Registers                                                         */
  REG_32 MFBAHR0;                       /* Memory Fine Base Addr Hi Register 0*/
  REG_32 MFBALR0;                       /* Memory Fine Base Addr Lo Register 0*/
  REG_32 MFBAHR1;                       /* Memory Fine Base Addr Hi Register 1*/
  REG_32 MFBALR1;                       /* Memory Fine Base Addr Lo Register 1*/
  REG_32 MFBAHR2;                       /* Memory Fine Base Addr Hi Register 2*/
  REG_32 MFBALR2;                       /* Memory Fine Base Addr Lo Register 2*/
  REG_32 MFBAHR3;                       /* Memory Fine Base Addr Hi Register 3*/
  REG_32 MFBALR3;                       /* Memory Fine Base Addr Lo Register 3*/
  REG_32 MFBAHR4;                       /* Memory Fine Base Addr Hi Register 4*/
  REG_32 MFBALR4;                       /* Memory Fine Base Addr Lo Register 4*/
  REG_32 MFBAHR5;                       /* Memory Fine Base Addr Hi Register 5*/
  REG_32 MFBALR5;                       /* Memory Fine Base Addr Lo Register 5*/
  REG_32 MCBAHR0;                       /* Memory Coarse Base Addr High Reg 0 */
  REG_32 MCBALR0;                       /* Memory Coarse Base Addr Low  Reg 0 */
  REG_32 MCBAHR1;                       /* Memory Coarse Base Addr High Reg 1 */
  REG_32 MCBALR1;                       /* Memory Coarse Base Addr Low  Reg 1 */
  REG_32 MCBAHR2;                       /* Memory Coarse Base Addr High Reg 2 */
  REG_32 MCBALR2;                       /* Memory Coarse Base Addr Low  Reg 2 */
  REG_32 MCBAHR3;                       /* Memory Coarse Base Addr High Reg 3 */
  REG_32 MCBALR3;                       /* Memory Coarse Base Addr Low  Reg 3 */
  REG_32 MCBAHR4;                       /* Memory Coarse Base Addr High Reg 4 */
  REG_32 MCBALR4;                       /* Memory Coarse Base Addr Low  Reg 4 */
  REG_32 MCBAHR5;                       /* Memory Coarse Base Addr High Reg 5 */
  REG_32 MCBALR5;                       /* Memory Coarse Base Addr Low  Reg 5 */
  REG_32 Reserved2[40];

  /* Real-Time Interrupt (RTI) Registers                                      */
  REG_32 RTICNTR;                       /* Real-Time Interrupt (RTI) Counter  */
  REG_32 RTIPCTL;                       /* RTI Preload Control Register       */
  REG_32 RTICNTL;                       /* RTI Control Register               */
  REG_32 WKEY;                          /* Watchdog Key Register              */
  REG_32 RTICMP1;                       /* RTI Compare Register 1             */
  REG_32 RTICMP2;                       /* RTI Compare Register 2             */
  REG_32 RTICINT;                       /* RTI Compare Int Control Register   */
  REG_32 RTICNTEN;                      /* RTI Counter Enable Register        */

  /* Interrupts                                                               */
  REG_32 IRQIVEC;                       /* IRQ Index Offset Vector Register   */
  REG_32 FIQIVEC;                       /* FIQ Index Offset Vector Register   */
  REG_32 CIMIVEC;                       /* CIM Index Offset Vector Register   */
  REG_32 FIRQPR;                        /* FIQ/IRQ Program Control Register   */
  REG_32 INTREQ;                        /* Pending Int Read Location Register */
  REG_32 REQMASK;                       /* Interrupt Mask Register            */
  REG_32 Reserved3[2];

  /* Parallel Signature Analysis (PSA) Registers                              */
  REG_32 CPUPSA;                        /* CPU Data Bus PSA Registers         */
  REG_32 Reserved4[3];
  REG_32 PSAENABLE;                     /* PSA Enable                         */
  REG_32 Reserved5[30];

  /* Clock Registers                                                          */
  REG_32 GCR_N;                         /* New Global Control Register        */
  REG_32 CLKCNTL;                       /* Clock Control Register             */
  REG_32 Reserved6[2];
  REG_32 GCR;                           /* Global Control Register            */

  /* Reset Registers                                                          */
  REG_32 SYSECR;                        /* System Exception Control Register  */
  REG_32 SYSESR;                        /* System Reset Exception Status Reg  */
  REG_32 ABRTESR;                       /* Abort Exception Status Register    */
  REG_32 GLBSTAT;                       /* Global Status Register             */

  /* Miscellaneous Registers                                                  */
  REG_32 DEV;                           /* Device Identification Register     */
  REG_32 Reserved7;

  /* System Software Interrupt                                                */
  REG_32 SSIF;                          /* System Software Int Flag Register  */
  REG_32 SSIR;                          /* System Software Int Req  Register  */
} regSM_t;


/* Interrupt Expansion Module (IEM)                                           */
typedef struct {
  REG_32 INTPEND0;                      /* Interrupt Pending Register 0       */
  REG_32 INTPEND1;                      /* Interrupt Pending Register 1       */
  REG_32 Reserved0[6];
  REG_32 INTCTRL0;                      /* Interrupt Control Register  0      */
  REG_32 INTCTRL1;                      /* Interrupt Control Register  1      */
  REG_32 INTCTRL2;                      /* Interrupt Control Register  2      */
  REG_32 INTCTRL3;                      /* Interrupt Control Register  3      */
  REG_32 INTCTRL4;                      /* Interrupt Control Register  4      */
  REG_32 INTCTRL5;                      /* Interrupt Control Register  5      */
  REG_32 INTCTRL6;                      /* Interrupt Control Register  6      */
  REG_32 INTCTRL7;                      /* Interrupt Control Register  7      */
  REG_32 INTCTRL8;                      /* Interrupt Control Register  8      */
  REG_32 INTCTRL9;                      /* Interrupt Control Register  9      */
  REG_32 INTCTRL10;                     /* Interrupt Control Register 10      */
  REG_32 INTCTRL11;                     /* Interrupt Control Register 11      */
  REG_32 INTCTRL12;                     /* Interrupt Control Register 12      */
  REG_32 INTCTRL13;                     /* Interrupt Control Register 13      */
  REG_32 INTCTRL14;                     /* Interrupt Control Register 14      */
  REG_32 INTCTRL15;                     /* Interrupt Control Register 15      */
} regIEM_t;


/* Memory Security Module (MSM)                                               */
typedef struct {
  REG_32 MSMKEY0;                       /* KEY0                               */
  REG_32 MSMKEY1;                       /* KEY0                               */
  REG_32 MSMKEY2;                       /* KEY0                               */
  REG_32 MSMKEY3;                       /* KEY0                               */
  REG_32 Reserved0[6];
  REG_32 MSMSCR;                        /* Status and Control Register        */
} regMSM_t;


/* Memory Protection Unit (MPU) Registers                                     */
typedef struct {
  REG_32 MPUAHR0;                       /* MPU Address High Register 0        */
  REG_32 MPUALR0;                       /* MPU Address Low  Register 0        */
  REG_32 MPUAHR1;                       /* MPU Address High Register 1        */
  REG_32 MPUALR1;                       /* MPU Address Low  Register 1        */
  REG_32 MPUAHR2;                       /* MPU Address High Register 2        */
  REG_32 MPUALR2;                       /* MPU Address Low  Register 2        */
  REG_32 MPUAHR3;                       /* MPU Address High Register 3        */
  REG_32 MPUALR3;                       /* MPU Address Low  Register 3        */
  REG_32 MPUCTRL;                       /* MPU Control Register               */
} regMPU_t;


/* F05 Flash Module (FM)                                                      */
typedef struct {
  REG_32 FMBAC1;                        /* Bank Access Control Register 1     */
  REG_32 FMBAC2;                        /* Bank Access Control Register 2     */
  REG_32 FMBSEA;                        /* Bank Sector Enable Register A      */
  REG_32 FMBSEB;                        /* Bank Sector Enable Register B      */
  REG_32 FMBRDY;                        /* Bank Ready Register                */
  REG_32 Reserved0[1787];
  REG_32 FMREGOPT;                      /* Option Control Register            */
  REG_32 Reserved1;
  REG_32 FMBBUSY;                       /* Bank Busy Register                 */
  REG_32 FMPKEY;                        /* Protection Key Register            */
  REG_32 Reserved2[769];
  REG_32 FMPRDY;                        /* Pump Ready Register                */
  REG_32 Reserved3[1274];
  REG_32 FMMAC1;                        /* Module Access Control Register 1   */
  REG_32 FMMAC2;                        /* Module Access Control Register 2   */
  REG_32 FMPAGP;                        /* Pump Active Grace Period Register  */
  REG_32 FMMSTAT;                       /* Module Status Register             */
} regFM_t;


/* Peripherals                                                                */

/* Class II Serial Interface B (C2SIB)                                        */
typedef struct {
  REG_32 C2SIBISR;                      /* Interrupt Status  Register         */
  REG_32 C2SIBICR;                      /* Interrupt Control Register         */
  REG_32 C2SIBGSR;                      /* Global Status  Register            */
  REG_32 C2SIBGCR;                      /* Global Control Register            */
  REG_32 C2SIBTDB;                      /* Transmit Data Bufferter            */
  REG_32 C2SIBCCSR;                     /* Completion Code Status Register    */
  REG_32 C2SIBCTR;                      /* Control Register                   */
  REG_32 C2SIBCLK;                      /* Interface Clock Register           */
  REG_32 C2SIBTBC;                      /* Transmit Byte Counter              */
  REG_32 C2SIBPC1;                      /* Pin Control Register 1             */
  REG_32 C2SIBPC2;                      /* Pin Control Register 2             */
  REG_32 C2SIBPC3;                      /* Pin Control Register 3             */
  REG_32 C2SIBEMU;                      /* Emulation Buffer Register          */
  REG_32 C2SIBRDB;                      /* Receive Data Buffer                */
  REG_32 C2SIBCAL;                      /* Calibration Register               */
} regC2SIB_t;

/* Inter-Integrated Circuit (I2C)                                             */
typedef struct {
  REG_32 I2COAR;                        /* I2C Own Address Register           */
  REG_32 I2CIMR;                        /* I2C Interrupt Mask?Status Register */
  REG_32 I2CISR;                        /* I2C Interrupt Status Register      */
  REG_32 I2CCKL;                        /* I2C Clock Divider Low Register     */
  REG_32 I2CCKH;                        /* I2C Clock Divider High Register    */
  REG_32 I2CCNT;                        /* I2C Data Count Register            */
  REG_32 I2CDRR;                        /* I2C Data Receive Register          */
  REG_32 I2CSAR;                        /* I2C Slave Address Register         */
  REG_32 I2CDXR;                        /* I2C Data Transmit Register         */
  REG_32 I2CMDR;                        /* I2C Mode Register                  */
  REG_32 I2CIVR;                        /* I2C Interrupt Vector Register      */
  REG_32 I2CEMR;                        /* I2C Extended Mode Register         */
  REG_32 I2CPSC;                        /* I2C Prescale Register              */
  REG_32 I2CDIR;                        /* I2C Data Direction Register        */
  REG_32 I2CDOUT;                       /* I2C Data Out Register              */
  REG_32 I2CDIN;                        /* I2C Data Input Register            */
  REG_32 Reserved0[2];
  REG_32 I2CPFNC;                       /* I2C Function Register              */
  REG_32 I2CPDIR;                       /* I2C Direction Register             */
  REG_32 I2CDIN_;                       /* I2C Data Input Register            */
  REG_32 I2CDOUT_;                      /* I2C Data Output Register           */
  REG_32 I2CDSET;                       /* I2C Data Set Register              */
  REG_32 I2CDCLR;                       /* I2C Data Clear Register            */
  REG_32 Reserved1[1];
  REG_32 I2CPID1;                       /* I2C Peripheral ID Register 1       */
  REG_32 I2CPID2;                       /* I2C Peripheral ID Register 2       */
} regI2C_t;

/* Serial Peripheral Interface (SPI)                                          */
typedef struct {
  REG_32 SPICTRL1;                      /* SPI Control Register 1             */
  REG_32 SPICTRL2;                      /* SPI Control Register 2             */
  REG_32 SPICTRL3;                      /* SPI Control Register 3             */
  REG_32 SPIDAT0;                       /* SPI Shift Register 0               */
  REG_32 SPIDAT1;                       /* SPI Shift Register 1               */
  REG_32 SPIBUF;                        /* SPI Buffer Register                */
  REG_32 SPIEMU;                        /* SPI Emulation Register             */
  REG_32 SPIPC1;                        /* SPI Pin Control Register 1         */
  REG_32 SPIPC2;                        /* SPI Pin Control Register 2         */
  REG_32 SPIPC3;                        /* SPI Pin Control Register 3         */
  REG_32 SPIPC4;                        /* SPI Pin Control Register 4         */
  REG_32 SPIPC5;                        /* SPI Pin Control Register 5         */
  REG_32 SPIPC6;                        /* SPI Pin Control Register 6         */
} regSPI_t;

/* Standard CAN Controller (SCC) and High-End Controller Area Network (HECC)  */
typedef struct {
  REG_32 MID;                           /* Message Identifier                 */
  REG_32 MCF;                           /* Message Control Field              */
  REG_32 MDL;                           /* Message Data Low  Word             */
  REG_32 MDH;                           /* Message Data High Word             */
} regCAN_MBX_OBJ_t;
/* SCC RAM                                                                    */
typedef struct {
  regCAN_MBX_OBJ_t CAN_MBX_OBJ[16];     /* CAN Mailbox Objects                */
} regCAN_RAM_t;
/* SCC                                                                        */
typedef struct {
  REG_32 CANME;                         /* Mailbox Enable                     */
  REG_32 CANMD;                         /* Mailbox Direction                  */
  REG_32 CANTRS;                        /* Transmission Request Set           */
  REG_32 CANTRR;                        /* Transmission Request Reset         */
  REG_32 CANTA;                         /* Transmission Acknowledge           */
  REG_32 CANAA;                         /* Abort Acknowledge                  */
  REG_32 CANRMP;                        /* Receive Message Pending            */
  REG_32 CANRML;                        /* Receive Message Lost               */
  REG_32 CANRFP;                        /* Remote Frame Pending               */
  REG_32 CANGAM;                        /* Global Acceptance Mask             */
  REG_32 CANMC;                         /* Master Control                     */
  REG_32 CANBTC;                        /* Bit-Timing Configuration           */
  REG_32 CANES;                         /* Error and Status                   */
  REG_32 CANTEC;                        /* Transmit Error Counter             */
  REG_32 CANREC;                        /* Receive  Error Counter             */
  REG_32 CANGIF0;                       /* Global Interrupt Flag 0            */
  REG_32 CANGIM;                        /* Global Interrupt Mask              */
  REG_32 CANGIF1;                       /* Global Interrupt Flag 1            */
  REG_32 CANMIM;                        /* Mailbox Interrupt Mask             */
  REG_32 CANMIL;                        /* Mailbox Interrupt Level            */
  REG_32 CANOPC;                        /* Overwrite Protection Control       */
  REG_32 CANTIOC;                       /* Tx I/O Control                     */
  REG_32 CANRIOC;                       /* Rx I/O Control                     */
  REG_32 CANLNT;                        /* Reserved                           */
  REG_32 CANTOC;                        /* Reserved                           */
  REG_32 CANTOS;                        /* Reserved                           */
  REG_32 Reserved0[6];
  REG_32 CANLAM0;                       /* Local Acceptance Mask (obj 0..2)   */
  REG_32 Reserved1[2];
  REG_32 CANLAM3;                       /* Local Acceptance Mask (obj 3..5)   */
} regCAN_t;

/* General Input/Output (GIO)                                                 */
typedef struct  {
  REG_32 GIODIR;                        /* GIO Data Direction                 */
  REG_32 GIODIN;                        /* GIO Data Input                     */
  REG_32 GIODOUT;                       /* GIO Data Output                    */
  REG_32 GIODSET;                       /* GIO Data Set                       */
  REG_32 GIODCLR;                       /* GIO Data Cleart                    */
} regGIO_REG_t;
/* GIO                                                                        */
typedef struct {
  REG_32 GIOPWDN;                       /* GIO Power Down                     */
  REG_32 GIOENA1;                       /* GIO Interrupt Enable               */
  REG_32 GIOPOL1;                       /* GIO Interrupt Polarity             */
  REG_32 GIOFLG1;                       /* GIO Interrupt Flag                 */
  REG_32 GIOPRY1;                       /* GIO Interrupt Priority             */
  REG_32 GIOOFFA;                       /* GIO Offset A                       */
  REG_32 GIOEMUA;                       /* GIO Emulation A                    */
  REG_32 GIOOFFB;                       /* GIO Offset B                       */
  REG_32 GIOEMUB;                       /* GIO Emulation B                    */
  regGIO_REG_t GIOA;                    /* GIO Port A Registers               */
  regGIO_REG_t GIOB;                    /* GIO Port B Registers               */
  regGIO_REG_t GIOC;                    /* GIO Port C Registers               */
  regGIO_REG_t GIOD;                    /* GIO Port D Registers               */
  regGIO_REG_t GIOE;                    /* GIO Port E Registers               */
  regGIO_REG_t GIOF;                    /* GIO Port F Registers               */
  regGIO_REG_t GIOG;                    /* GIO Port G Registers               */
  regGIO_REG_t GIOH;                    /* GIO Port H Registers               */
  REG_32 GIOENA2;                       /* GIO Interrupt Enable               */
  REG_32 GIOPOL2;                       /* GIO Interrupt Polarity             */
  REG_32 GIOFLG2;                       /* GIO Interrupt Flag                 */
  REG_32 GIOPRY2;                       /* GIO Interrupt Priority             */
} regGIO_t;

/* External Clock Prescale (ECP)                                              */
typedef struct  {
  REG_32 ECPCTRL;                       /* ECP Control Register               */
} regECP_t;

/* Expansion Bus Multiplexer Module (EBM)                                     */
typedef struct  {
  REG_32 EBDMACR;                       /* EBM DMA Request Control Register   */
  REG_32 EBRWCR;                        /* EBM Read Write Control Register    */
  REG_32 EBACR1;                        /* EBM Address Control Register 1     */
  REG_32 EBDCR;                         /* EBM Data Control Register          */
  REG_32 EBADCR;                        /* EBM Address/Data Control Register  */
  REG_32 EBACR2;                        /* EBM Address Control Register 2     */
  REG_32 EBACR3;                        /* EBM Address Control Register 3     */
  REG_32 EBMCR1;                        /* EBM Control Register 1             */
} regEBM_t;

/* Multi-Buffered Analog-to-Digital Converter (MibADC)                        */
typedef struct {
  REG_32 ADCR1;                         /* Control Register 1                 */
  REG_32 ADCR2;                         /* Control Register 2                 */
  REG_32 ADSR;                          /* Status Register                    */
  REG_32 ADEISR;                        /* Event gr Input-channel Select Reg  */
  REG_32 ADISR1;                        /* Group 1 Input-channel Select Reg   */
  REG_32 ADISR2;                        /* Group 2 Input-channel Select Reg   */
  REG_32 ADCALR;                        /* Calibration and Offset Corr Reg    */
  REG_32 ADDR0;                         /* Digital Result Register        0   */
  REG_32 ADEMDR0;                       /* Emulation Digital Results Reg  0   */
  REG_32 ADDR1;                         /* Digital Result Register        1   */
  REG_32 ADEMDR1;                       /* Emulation Digital Results Reg  1   */
  REG_32 ADDR2;                         /* Digital Result Register        2   */
  REG_32 ADEMDR2;                       /* Emulation Digital Results Reg  2   */
  REG_32 ADDR3;                         /* Digital Result Register        3   */
  REG_32 ADEMDR3;                       /* Emulation Digital Results Reg  3   */
  REG_32 ADDR4;                         /* Digital Result Register        4   */
  REG_32 ADEMDR4;                       /* Emulation Digital Results Reg  4   */
  REG_32 ADDR5;                         /* Digital Result Register        5   */
  REG_32 ADEMDR5;                       /* Emulation Digital Results Reg  5   */
  REG_32 ADDR6;                         /* Digital Result Register        6   */
  REG_32 ADEMDR6;                       /* Emulation Digital Results Reg  6   */
  REG_32 ADDR7;                         /* Digital Result Register        7   */
  REG_32 ADEMDR7;                       /* Emulation Digital Results Reg  7   */
  REG_32 ADDR8;                         /* Digital Result Register        8   */
  REG_32 ADEMDR8;                       /* Emulation Digital Results Reg  8   */
  REG_32 ADDR9;                         /* Digital Result Register        9   */
  REG_32 ADEMDR9;                       /* Emulation Digital Results Reg  9   */
  REG_32 ADDR10;                        /* Digital Result Register       10   */
  REG_32 ADEMDR10;                      /* Emulation Digital Results Reg 10   */
  REG_32 ADDR11;                        /* Digital Result Register       11   */
  REG_32 ADEMDR11;                      /* Emulation Digital Results Reg 11   */
  REG_32 ADDR12;                        /* Digital Result Register       12   */
  REG_32 ADEMDR12;                      /* Emulation Digital Results Reg 12   */
  REG_32 ADDR13;                        /* Digital Result Register       13   */
  REG_32 ADEMDR13;                      /* Emulation Digital Results Reg 13   */
  REG_32 ADDR14;                        /* Digital Result Register       14   */
  REG_32 ADEMDR14;                      /* Emulation Digital Results Reg 14   */
  REG_32 ADDR15;                        /* Digital Result Register       15   */
  REG_32 ADEMDR15;                      /* Emulation Digital Results Reg 15   */
  REG_32 ADINR;                         /* Data Input Register                */
  REG_32 ADCPCR;                        /* Pin Control Register               */
  REG_32 Reserved0[3];
  REG_32 ADSAMPEV;                      /* Sample Control Register Event      */
  REG_32 ADSAMP1;                       /* Sample Control Register 1          */
  REG_32 ADSAMP2;                       /* Sample Control Register 2          */
  REG_32 ADBCR1;                        /* Buffer Control Register 1          */
  REG_32 ADBCR2;                        /* Buffer Control Register 2          */
  REG_32 ADBCR3;                        /* Buffer Control Register 3          */
  REG_32 ADBST;                         /* Buffer Status Register             */
  REG_32 ADTHREV;                       /* Event Group Interrupt Threshold    */
  REG_32 ADTHRG1;                       /* Group 1 Interrupt Threshold        */
  REG_32 ADTHRG2;                       /* Group 2 Interrupt Threshold        */
  REG_32 ADEVTSRC;                      /* Event Source Register              */
} regMIBADC_t;

/* Serial Communication Interface (SCI)                                       */
typedef struct {
  REG_32 SCICCR;                        /* Communication Control Register     */
  REG_32 SCICTL1;                       /* Control Register 1                 */
  REG_32 SCICTL2;                       /* Control Register 2                 */
  REG_32 SCICTL3;                       /* Control Register 3                 */
  REG_32 SCIRXST;                       /* Receiver Status Control Register   */
  REG_32 SCIHBAUD;                      /* Baud Register, High   bits         */
  REG_32 SCIMBAUD;                      /* Baud Register, Middle bits         */
  REG_32 SCILBAUD;                      /* Baud Register, Low    bits         */
  REG_32 SCIRXEMU;                      /* Emulation Buffer Register          */
  REG_32 SCIRXBUF;                      /* Receiver Data Buffer Register      */
  REG_32 SCITXBUF;                      /* Transmit Data Buffer Register      */
  REG_32 SCIPC1;                        /* Pin Control Register 1             */
  REG_32 SCIPC2;                        /* Pin Control Register 2             */
  REG_32 SCIPC3;                        /* Pin Control Register 3             */
} regSCI_t;

/* High-End Timer (HET)                                                       */
typedef struct {
  REG_32 HETGCR;                        /* Global Configuration Register      */
  REG_32 HETPFR;                        /* Prescale Factor Register           */
  REG_32 HETADDR;                       /* HET Current Address Register       */
  REG_32 HETOFF1;                       /* Offser Level 1 Register            */
  REG_32 HETOFF2;                       /* Offser Level 2 Register            */
  REG_32 HETEXC1;                       /* Exception Control Register 1       */
  REG_32 HETEXC2;                       /* Exception Control Register 2       */
  REG_32 HETPRY;                        /* Interrupt Priority Register        */
  REG_32 HETFLG;                        /* Interrupt Flag Register            */
  REG_32 Reserved0[2];
  REG_32 HETHRSH;                       /* HR Share Control Register          */
  REG_32 HETXOR;                        /* HR XOR Control Register            */
  REG_32 HETDIR;                        /* Data Dirrection Register           */
  REG_32 HETDIN;                        /* Input Data Register                */
  REG_32 HETDOUT;                       /* Output Data Register               */
  REG_32 HETSET;                        /* Set Data Register                  */
  REG_32 HETDCLR;                       /* Clear Data Register                */
} regHET_t;


/* Pointer definitions for register structures                                */
#define pSM       ((regSM_t *)       SM_BASE     )
#define pIEM      ((regIEM_t *)      IEM_BASE    )
#define pMSM1     ((regMSM_t *)      MSM1_BASE   )
#define pMSM2     ((regMSM_t *)      MSM2_BASE   )
#define pHET      ((regHET_t *)      HET_BASE    )
#define pSPI1     ((regSPI_t *)      SPI1_BASE   )
#define pSCI3     ((regSCI_t *)      SCI3_BASE   )
#define pSCI2     ((regSCI_t *)      SCI2_BASE   )
#define pSCI1     ((regSCI_t *)      SCI1_BASE   )
#define pMIBADC   ((regMIBADC_t *)   MIBADC_BASE )
#define pECP      ((regECP_t *)      ECP_BASE    )
#define pGIO      ((regGIO_t *)      GIO_BASE    )
#define pEBM      ((regEBM_t *)      EBM_BASE    )
#define pI2C4     ((regI2C_t *)      I2C4_BASE   )
#define pI2C3     ((regI2C_t *)      I2C3_BASE   )
#define pI2C2     ((regI2C_t *)      I2C2_BASE   )
#define pI2C1     ((regI2C_t *)      I2C1_BASE   )
#define pI2C5     ((regI2C_t *)      I2C5_BASE   )
#define pSPI2     ((regSPI_t *)      SPI2_BASE   )
#define pC2SIB    ((regC2SIB_t *)    C2SIB_BASE  )
#define pFM       ((regFM_t *)       FM_BASE     )
#define pMPU      ((regMPU_t *)      MPU_BASE    )


#endif  // __TMS470R1_H


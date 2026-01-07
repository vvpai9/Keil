/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  PIO.H:  Header file for Parallel I/O                                      */
/*          Samsung S3C44B0X                                                  */
/*                                                                            */
/******************************************************************************/

#ifndef __PIO_H
#define __PIO_H


#define PIO_BASE    0x01D20000  // PIO Base Address


// PIO Registers
typedef struct {
  reg32 PCONA;      // Port A Control
  reg32 PDATA;      // Port A Data
  reg32 PCONB;      // Port B Control
  reg32 PDATB;      // Port B Data
  reg32 PCONC;      // Port C Control
  reg32 PDATC;      // Port C Data
  reg32 PUPC;       // Port C Pull-up Control
  reg32 PCOND;      // Port D Control
  reg32 PDATD;      // Port D Data
  reg32 PUPD;       // Port D Pull-up Control
  reg32 PCONE;      // Port E Control
  reg32 PDATE;      // Port E Data
  reg32 PUPE;       // Port E Pull-up Control
  reg32 PCONF;      // Port F Control
  reg32 PDATF;      // Port F Data
  reg32 PUPF;       // Port F Pull-up Control
  reg32 PCONG;      // Port G Control
  reg32 PDATG;      // Port G Data
  reg32 PUPG;       // Port G Pull-up Control
  reg32 SPUCR;      // Special Pull-up Control
  reg32 EXTINT;     // External Interrupt Control
  reg32 EXTINPND;   // External Interrupt Pending
} regPIO;

#define pPIO ((regPIO *)PIO_BASE)


// PCONA: Port A Control Register
#define PA0_OUT         0x00000000
#define PA0_ADDR0       0x00000001
#define PA1_OUT         0x00000000
#define PA1_ADDR16      0x00000002
#define PA2_OUT         0x00000000
#define PA2_ADDR17      0x00000004
#define PA3_OUT         0x00000000
#define PA3_ADDR18      0x00000008
#define PA4_OUT         0x00000000
#define PA4_ADDR19      0x00000010
#define PA5_OUT         0x00000000
#define PA5_ADDR20      0x00000020
#define PA6_OUT         0x00000000
#define PA6_ADDR21      0x00000040
#define PA7_OUT         0x00000000
#define PA7_ADDR22      0x00000080
#define PA8_OUT         0x00000000
#define PA8_ADDR23      0x00000100
#define PA9_OUT         0x00000000
#define PA9_ADDR24      0x00000200

// PCONB: Port B Control Register
#define PB0_OUT         0x00000000
#define PB0_SCKE        0x00000001
#define PB1_OUT         0x00000000
#define PB1_SCLK        0x00000002
#define PB2_OUT         0x00000000
#define PB2_nSCAS       0x00000004
#define PB2_nCAS2       0x00000004
#define PB3_OUT         0x00000000
#define PB3_nSRAS       0x00000008
#define PB3_nCAS3       0x00000008
#define PB4_OUT         0x00000000
#define PB4_nWBE2       0x00000010
#define PB4_nBE2        0x00000010
#define PB4_nDQM2       0x00000010
#define PB5_OUT         0x00000000
#define PB5_nWBE3       0x00000020
#define PB5_nBE3        0x00000020
#define PB5_DQM3        0x00000020
#define PB6_OUT         0x00000000
#define PB6_nGCS1       0x00000040
#define PB7_OUT         0x00000000
#define PB7_nGCS2       0x00000080
#define PB8_OUT         0x00000000
#define PB8_nGCS3       0x00000100
#define PB9_OUT         0x00000000
#define PB9_nGCS4       0x00000200
#define PB10_OUT        0x00000000
#define PB10_nGCS5      0x00000400

// PCONC: Port C Control Register
#define PC0_IN          0x00000000
#define PC0_OUT         0x00000001
#define PC0_DATA16      0x00000002
#define PC0_IISLRCK     0x00000003
#define PC1_IN          0x00000000
#define PC1_OUT         0x00000004
#define PC1_DATA17      0x00000008
#define PC1_IISDO       0x0000000C
#define PC2_IN          0x00000000
#define PC2_OUT         0x00000010
#define PC2_DATA18      0x00000020
#define PC2_IISDI       0x00000030
#define PC3_IN          0x00000000
#define PC3_OUT         0x00000040
#define PC3_DATA19      0x00000080
#define PC3_IISCLK      0x000000C0
#define PC4_IN          0x00000000
#define PC4_OUT         0x00000100
#define PC4_DATA20      0x00000200
#define PC4_VD7         0x00000300
#define PC5_IN          0x00000000
#define PC5_OUT         0x00000400
#define PC5_DATA21      0x00000800
#define PC5_VD6         0x00000C00
#define PC6_IN          0x00000000
#define PC6_OUT         0x00001000
#define PC6_DATA22      0x00002000
#define PC6_VD5         0x00003000
#define PC7_IN          0x00000000
#define PC7_OUT         0x00004000
#define PC7_DATA23      0x00008000
#define PC7_VD4         0x0000C000
#define PC8_IN          0x00000000
#define PC8_OUT         0x00010000
#define PC8_DATA24      0x00020000
#define PC8_nXDACK1     0x00030000
#define PC9_IN          0x00000000
#define PC9_OUT         0x00040000
#define PC9_DATA25      0x00080000
#define PC10_nXDREQ1    0x000C0000
#define PC10_IN         0x00000000
#define PC10_OUT        0x00100000
#define PC10_DATA26     0x00200000
#define PC11_nRTS1      0x00300000
#define PC11_IN         0x00000000
#define PC11_OUT        0x00400000
#define PC11_DATA27     0x00800000
#define PC11_nCTS1      0x00C00000
#define PC12_IN         0x00000000
#define PC12_OUT        0x01000000
#define PC12_DATA28     0x02000000
#define PC12_TxD1       0x03000000
#define PC13_IN         0x00000000
#define PC13_OUT        0x04000000
#define PC13_DATA29     0x08000000
#define PC13_RxD1       0x0C000000
#define PC14_IN         0x00000000
#define PC14_OUT        0x10000000
#define PC14_DATA30     0x20000000
#define PC14_nRTS0      0x30000000
#define PC15_IN         0x00000000
#define PC15_OUT        0x40000000
#define PC15_DATA31     0x80000000
#define PC15_nCTS0      0xC0000000

// PCOND: Port D Control Register
#define PD0_IN          0x00000000
#define PD0_OUT         0x00000001
#define PD0_VD0         0x00000002
#define PD1_IN          0x00000000
#define PD1_OUT         0x00000004
#define PD1_VD1         0x00000008
#define PD2_IN          0x00000000
#define PD2_OUT         0x00000010
#define PD2_VD2         0x00000020
#define PD3_IN          0x00000000
#define PD3_OUT         0x00000040
#define PD3_VD3         0x00000080
#define PD4_IN          0x00000000
#define PD4_OUT         0x00000100
#define PD4_VCLK        0x00000200
#define PD5_IN          0x00000000
#define PD5_OUT         0x00000400
#define PD5_VLINE       0x00000800
#define PD6_IN          0x00000000
#define PD6_OUT         0x00001000
#define PD6_VM          0x00002000
#define PD7_IN          0x00000000
#define PD7_OUT         0x00004000
#define PD7_VFRAME      0x00008000

// PCONE: Port E Control Register
#define PE0_IN          0x00000000
#define PE0_OUT         0x00000001
#define PE0_Fpllo_out   0x00000002
#define PE0_Fout_out    0x00000003
#define PE1_IN          0x00000000
#define PE1_OUT         0x00000004
#define PE1_TxD0        0x00000008
#define PE2_IN          0x00000000
#define PE2_OUT         0x00000010
#define PE2_RxD0        0x00000020
#define PE3_IN          0x00000000
#define PE3_OUT         0x00000040
#define PE3_TOUT0       0x00000080
#define PE4_IN          0x00000000
#define PE4_OUT         0x00000100
#define PE4_TOUT1       0x00000200
#define PE4_TCLK_in     0x00000300
#define PE5_IN          0x00000000
#define PE5_OUT         0x00000400
#define PE5_TOUT2       0x00000800
#define PE5_TCLK_in     0x00000C00
#define PE6_IN          0x00000000
#define PE6_OUT         0x00001000
#define PE6_TOUT3       0x00002000
#define PE6_VD6         0x00003000
#define PE7_IN          0x00000000
#define PE7_OUT         0x00004000
#define PE7_TOUT4       0x00008000
#define PE7_VD7         0x0000C000
#define PE8_OUT         0x00010000
#define PE8_CODECLK     0x00020000

// PCONF: Port F Control Register
#define PF0_IN          0x00000000
#define PF0_OUT         0x00000001
#define PF0_IICSCL      0x00000002
#define PF1_IN          0x00000000
#define PF1_OUT         0x00000004
#define PF1_IICSDA      0x00000008
#define PF2_IN          0x00000000
#define PF2_OUT         0x00000010
#define PF2_nWAIT       0x00000020
#define PF3_IN          0x00000000
#define PF3_OUT         0x00000040
#define PF3_nXBACK      0x00000080
#define PF3_nXDACK0     0x000000C0
#define PF4_IN          0x00000000
#define PF4_OUT         0x00000100
#define PF4_nXBREQ      0x00000200
#define PF4_nXDREQ0     0x00000300
#define PF5_IN          0x00000000
#define PF5_OUT         0x00000400
#define PF5_nRTS1       0x00000800
#define PF5_SIOTxD      0x00000C00
#define PF5_IISLRCK     0x00001000
#define PF6_IN          0x00000000
#define PF6_OUT         0x00002000
#define PF6_TxD1        0x00004000
#define PF6_SIORDY      0x00006000
#define PF6_IISDO       0x00008000
#define PF7_IN          0x00000000
#define PF7_OUT         0x00010000
#define PF7_RxD1        0x00020000
#define PF7_SIORxD      0x00030000
#define PF7_IISDI       0x00040000
#define PF8_IN          0x00000000
#define PF8_OUT         0x00080000
#define PF8_nCTS1       0x00100000
#define PF8_SIOCLK      0x00180000
#define PF8_IISCLK      0x00200000

// PCONG: Port G Control Register
#define PG0_IN          0x00000000
#define PG0_OUT         0x00000001
#define PG0_VD4         0x00000002
#define PG0_EINT0       0x00000003
#define PG1_IN          0x00000000
#define PG1_OUT         0x00000004
#define PG1_VD5         0x00000008
#define PG1_EINT1       0x0000000C
#define PG2_IN          0x00000000
#define PG2_OUT         0x00000010
#define PG2_nCTS0       0x00000020
#define PG2_EINT2       0x00000030
#define PG3_IN          0x00000000
#define PG3_OUT         0x00000040
#define PG3_nRTS0       0x00000080
#define PG3_EINT3       0x000000C0
#define PG4_IN          0x00000000
#define PG4_OUT         0x00000100
#define PG4_IISCLK      0x00000200
#define PG4_EINT4       0x00000300
#define PG5_IN          0x00000000
#define PG5_OUT         0x00000400
#define PG5_IISDI       0x00000800
#define PG5_EINT5       0x00000C00
#define PG6_IN          0x00000000
#define PG6_OUT         0x00001000
#define PG6_IISDO       0x00002000
#define PG6_EINT6       0x00003000
#define PG7_IN          0x00000000
#define PG7_OUT         0x00004000
#define PG7_ISSLRCK     0x00008000
#define PG7_EINT7       0x0000C000

// SPUCR: Special Pull-up Resistor Control Register
#define SPUCR0          0x00000001
#define SPUCR1          0x00000002
#define HZATSTOP        0x00000004

// EXTINT: External Interrupt Control Register
#define EINT0_LOW       0x00000000
#define EINT0_HIGH      0x00000001
#define EINT0_FALLING   0x00000002
#define EINT0_RISING    0x00000004
#define EINT0_BOTH      0x00000006
#define EINT1_LOW       0x00000000
#define EINT1_HIGH      0x00000010
#define EINT1_FALLING   0x00000020
#define EINT1_RISING    0x00000040
#define EINT1_BOTH      0x00000060
#define EINT2_LOW       0x00000000
#define EINT2_HIGH      0x00000100
#define EINT2_FALLING   0x00000200
#define EINT2_RISING    0x00000400
#define EINT2_BOTH      0x00000600
#define EINT3_LOW       0x00000000
#define EINT3_HIGH      0x00001000
#define EINT3_FALLING   0x00002000
#define EINT3_RISING    0x00004000
#define EINT3_BOTH      0x00006000
#define EINT4_LOW       0x00000000
#define EINT4_HIGH      0x00010000
#define EINT4_FALLING   0x00020000
#define EINT4_RISING    0x00040000
#define EINT4_BOTH      0x00060000
#define EINT5_LOW       0x00000000
#define EINT5_HIGH      0x00100000
#define EINT5_FALLING   0x00200000
#define EINT5_RISING    0x00400000
#define EINT5_BOTH      0x00600000
#define EINT6_LOW       0x00000000
#define EINT6_HIGH      0x01000000
#define EINT6_FALLING   0x02000000
#define EINT6_RISING    0x04000000
#define EINT6_BOTH      0x06000000
#define EINT7_LOW       0x00000000
#define EINT7_HIGH      0x10000000
#define EINT7_FALLING   0x20000000
#define EINT7_RISING    0x40000000
#define EINT7_BOTH      0x60000000

// EXTINTPND: External Interrupt Pending Register
#define EXTINTPND0      0x00000001
#define EXTINTPND1      0x00000002
#define EXTINTPND2      0x00000004
#define EXTINTPND3      0x00000008


#endif /* __PIO_H */

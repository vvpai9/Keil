/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  CAN.H:  Header file for Controller Area Network (CAN)                     */
/*          Sharp LH754xx                                                     */
/*                                                                            */
/******************************************************************************/

#ifndef __CAN_H
#define __CAN_H


#define CAN_BASE    0xFFFC5000              /* CAN Base Address */

#define CAN_BUF     0x40                    /* CAN Tx & Rx Buffer Offset */

#define CANMOD      REG8(CAN_BASE + 0x00)   /* Mode Register */
#define CANCMR      REG8(CAN_BASE + 0x04)   /* Command Register */
#define CANSR       REG8(CAN_BASE + 0x08)   /* Status Register */
#define CANIR       REG8(CAN_BASE + 0x0C)   /* Interrupt Register */
#define CANIER      REG8(CAN_BASE + 0x10)   /* Interrupt Enable Register */
#define CANBTR0     REG8(CAN_BASE + 0x18)   /* Bus Timing Register 0 */
#define CANBTR1     REG8(CAN_BASE + 0x1C)   /* Bus Timing Register 1 */
#define CANALC      REG8(CAN_BASE + 0x2C)   /* Arbitration Lost Capture */
#define CANECC      REG8(CAN_BASE + 0x30)   /* Error Code Capture */
#define CANEWLR     REG8(CAN_BASE + 0x34)   /* Error Warning Limit Register */
#define CANRXERR    REG8(CAN_BASE + 0x38)   /* Receive Error Counter */
#define CANTXERR    REG8(CAN_BASE + 0x3C)   /* Transmit Error Counter */
#define ACR0        REG8(CAN_BASE + 0x40)   /* Accept. Code Reg.0, Reset Mode */
#define ACR1        REG8(CAN_BASE + 0x44)   /* Accept. Code Reg.1, Reset Mode */
#define ACR2        REG8(CAN_BASE + 0x48)   /* Accept. Code Reg.2, Reset Mode */
#define ACR3        REG8(CAN_BASE + 0x4C)   /* Accept. Code Reg.3, Reset Mode */
#define AMR0        REG8(CAN_BASE + 0x50)   /* Accept. Mask Reg.0, Reset Mode */
#define AMR1        REG8(CAN_BASE + 0x54)   /* Accept. Mask Reg.1, Reset Mode */
#define AMR2        REG8(CAN_BASE + 0x58)   /* Accept. Mask Reg.2, Reset Mode */
#define AMR3        REG8(CAN_BASE + 0x5C)   /* Accept. Mask Reg.3, Reset Mode */
#define CANRMC      REG8(CAN_BASE + 0x74)   /* Receive Message Counter */
#define CANRBSA     REG8(CAN_BASE + 0x78)   /* Receive Buffer Start Address */

/* CAN Tx & Rx Buffer */
typedef union {
  reg8 fi;          /* Frame Information */
  struct {
    reg8 fi;        /* Frame Information */
    reg8 id[2];     /* 11-bit Identifier */
    reg8 db[8];     /* Data Bytes */
  } sf;             /* Standard Frame */
  struct {
    reg8 fi;        /* Frame Information */
    reg8 id[4];     /* 28-bit Identifier */
    reg8 db[8];     /* Data Bytes */
  } ef;             /* Extended Frame */
} CANBuf;

#define CANTxBuf    ((CANBuf *)(CAN_BASE + CAN_BUF))
#define CANRxBuf    ((CANBuf *)(CAN_BASE + CAN_BUF))


#endif /* __CAN_H */

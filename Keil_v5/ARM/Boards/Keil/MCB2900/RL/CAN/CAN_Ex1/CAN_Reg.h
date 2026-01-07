/*----------------------------------------------------------------------------
 *      RL-ARM - CAN
 *----------------------------------------------------------------------------
 *      Name:    CAN_reg.h
 *      Purpose: Header file for CAN registers of NXP LPC29xx device series
 *      Rev.:    V4.70
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/


#ifndef __CAN_REG_H
#define __CAN_REG_H

#define CAN1_BASE        0xE0080000   /* CAN Controller 1 (CAN0) Base Address*/
#define CAN2_BASE        0xE0081000   /* CAN Controller 2 (CAN1) Base Address*/

/* CAN Controller Register Addresses                                         */
U32 CAN_BASE[] = { CAN1_BASE, CAN2_BASE };

#define CAN_AFM_BASE     0xE0086000   /* CAN Acceptance Filter RAM Base Addr */
#define CAN_AFR_BASE     0xE0087000   /* CAN Acceptance Filter Base Address  */
#define CAN_CS_BASE      0xE0088000   /* CAN Central Registers Base Address  */

/* CAN Acceptance Filter RAM                                                 */
typedef struct  {
  volatile U32 mask[512];   /* ID Masks                                      */
}  regCAN_AFM;

/* CAN Acceptance Filter Registers (regCAN_AFR)                              */
typedef struct  {
  volatile U32 CAMODE;      /* Acceptance filter mode register               */
  volatile U32 CASFESA;     /* Standard frame explicit start address register*/
  volatile U32 CASFGSA;     /* Standard frame group start address register   */
  volatile U32 CAEFESA;     /* Extended frame explicit start address register*/
  volatile U32 CAEFGSA;     /* Extended frame group start address register   */
  volatile U32 CAEOTA;      /* End of acceptance filter tables register      */
  volatile U32 CALUTEA;     /* LUT error address register                    */
  volatile U32 CALUTE;      /* LUT error register                            */
}  regCAN_AFR;

/* CAN Central Registers (regCAN_CR)                                         */
typedef struct  {
  volatile U32 CCCTS;       /* CAN central transmit status register          */
  volatile U32 CCCRS;       /* CAN central receive status register           */
  volatile U32 CCCMS;       /* CAN central miscellaneous register            */
}  regCAN_CR;       

/* CAN Controller Registers (regCAN)                                         */
typedef struct  {
  volatile U32 CCMODE;      /* Mode register                                 */
  volatile U32 CCCMD;       /* Command register                              */
  volatile U32 CCGS;        /* Global controller status and error counter    */
  volatile U32 CCIC;        /* Interrupt and capture                         */
  volatile U32 CCIE;        /* Interrupt enable                              */
  volatile U32 CCBT;        /* Bus timing                                    */
  volatile U32 CCEWL;       /* Error warning limit                           */
  volatile U32 CCSTAT;      /* Status register                               */
  volatile U32 CCRXBMI;     /* Receive frame status                          */
  volatile U32 CCRXBID;     /* Received identifier                           */
  volatile U32 CCCRXBDA;    /* Received data bytes 1 - 4                     */
  volatile U32 CCCRXBDB;    /* Received data bytes 5 - 8                     */
  volatile U32 CCTXB1MI;    /* Transmit frame info       (1)                 */
  volatile U32 CCTXB1ID;    /* Transmit identifier       (1)                 */
  volatile U32 CCTXB1DA;    /* Transmit data bytes 1 - 4 (1)                 */
  volatile U32 CCTXB1DB;    /* Transmit data bytes 5 - 8 (1)                 */
  volatile U32 CCTXB2MI;    /* Transmit frame info       (2)                 */
  volatile U32 CCTXB2ID;    /* Transmit identifier       (2)                 */
  volatile U32 CCTXB2DA;    /* Transmit data bytes 1 - 4 (2)                 */
  volatile U32 CCTXB2DB;    /* Transmit data bytes 5 - 8 (2)                 */
  volatile U32 CCTXB3MI;    /* Transmit frame info       (3)                 */
  volatile U32 CCTXB3ID;    /* Transmit identifier       (3)                 */
  volatile U32 CCTXB3DA;    /* Transmit data bytes 1 - 4 (3)                 */
  volatile U32 CCTXB3DB;    /* Transmit data bytes 5 - 8 (3)                 */
}  regCAN;

/* Pointers to CAN Structures                                                */
#define ptrCAN1        ((regCAN *)CAN1_BASE)
#define ptrCAN2        ((regCAN *)CAN2_BASE)

#endif /* __CAN_REG_H */

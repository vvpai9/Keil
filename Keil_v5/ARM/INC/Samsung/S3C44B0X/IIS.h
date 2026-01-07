/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  IIS.H:  Header file for IIS-Bus Interface                                 */
/*          Samsung S3C44B0X                                                  */
/*                                                                            */
/******************************************************************************/

#ifndef __IIS_H
#define __IIS_H


#define IIS_BASE    0x01D18000  // IIS Base Address


// IIS Registers
typedef struct {
  reg32 IISCON;     // IIS Control
  reg32 IISMOD;     // IIS Mode
  reg32 IISPSR;     // IIS Prescaler
  reg32 IISFIFCON;  // IIS FIFO Control
  reg16 IISFIF;     // IIS FIFO Entry
} regIIS;

#define pIIS ((regIIS *)IIS_BASE)


#endif /* __IIS_H */

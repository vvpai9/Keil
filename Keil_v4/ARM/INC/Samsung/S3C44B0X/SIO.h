/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  SIO.H:  Header file for SIO Interface                                     */
/*          Samsung S3C44B0X                                                  */
/*                                                                            */
/******************************************************************************/

#ifndef __SIO_H
#define __SIO_H


#define SIO_BASE    0x01D14000  // SIO Base Address


// SIO Registers
typedef struct {
  reg32 SIOCON;     // SIO Control
  reg32 SIODAT;     // SIO Data
  reg32 SBRDR;      // SIO Baud Rete Prescaler
  reg32 ITVCNT;     // SIO Interval Counter
  reg32 DCNTZ;      // SIO DMA Count Zero
} regSIO;

#define pSIO ((regSIO *)SIO_BASE)


// SIOCON: SIO Control Register
#define SIO_MODE_DIS    0x00
#define SIO_MODE_INT    0x01
#define SIO_MODE_DMA0   0x02
#define SIO_MODE_DMA1   0x03
#define SIO_HSE         0x04
#define SIO_SB          0x08
#define SIO_CES         0x10
#define SIO_TRS         0x20
#define SIO_DD          0x40
#define SIO_CS          0x80


#endif /* __SIO_H */

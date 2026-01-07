/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  SYSTEM.H:  Header file for CPU Wrapper & Bus Priorities                   */
/*             Samsung S3C44B0X                                               */
/*                                                                            */
/******************************************************************************/

#ifndef __SYSTEM_H
#define __SYSTEM_H


#define CPUW_BASE   0x01C00000  // CPU Wrapper Base Address
#define BUSP_BASE   0x01C40000  // Bus Priorities Base Address


// CPU Wrapper Registers
typedef struct {
  reg32 SYSCFG;     // System Configuration
  reg32 NCACNBE0;   // Non Cacheable Area 0
  reg32 NCACNBE1;   // Non Cacheable Area 1
} regCPUW;

// Bus Priorities Registers
typedef struct {
  reg32 SBUSCON;    // System Bus Control
} regBUSP;

#define pCPUW ((regCPUW *)CPUW_BASE)
#define pBUSP ((regBUSP *)BUSP_BASE)


#endif /* __SYSTEM_H */

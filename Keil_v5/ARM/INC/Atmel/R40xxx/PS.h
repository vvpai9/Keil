/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  PS.H:  Header file for Power Saving                                */
/*                                                                     */
/***********************************************************************/

#ifndef __PS_H
#define __PS_H


/*--------------*/
/* PS Registers */
/*--------------*/
#define PS_CR      REG(PS_BASE + 0x00) /* Control Register */
#ifndef AT91M40400
#define PS_PCER    REG(PS_BASE + 0x04) /* Peripheral Clock Enable  Register */
#define PS_PCDR    REG(PS_BASE + 0x08) /* Peripheral Clock Disable Register */
#define PS_PCSR    REG(PS_BASE + 0x0C) /* Peripheral Clock Status  Register */
#endif


/*-------------------------*/
/* PS_CR: Control Register */
/*-------------------------*/
#define PS_ARM7DIS         (1<<0)


#endif /* __PS_H */

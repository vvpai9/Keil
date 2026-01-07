/******************************************************************************/
/* IRQ.H: IRQ functions definitions                                           */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2006 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/


/* Function that setups and activates interrupt                               */
void Activate_IRQ (int channel, int level, void (*IRQ_Function) ());


/* Function that dectivates interrupt                                         */
void Deactivate_IRQ (int channel);

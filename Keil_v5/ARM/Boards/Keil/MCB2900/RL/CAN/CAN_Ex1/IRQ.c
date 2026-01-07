/*----------------------------------------------------------------------------
 *      RL-ARM - CAN
 *----------------------------------------------------------------------------
 *      Name:    IRQ.c
 *      Purpose: RTX CAN Driver example IRQ handlers
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <LPC29xx.h>                  /* LPC29xx definitions                 */


volatile unsigned int AD_last;        /* Last converted value                */


__irq void ADC2_Handler (void) {      /* ADC 2 Interrupt Handler             */

  AD_last = ADC2_ACD0;                /* Read Conversion Result              */
  ADC2_INT_CLR_STATUS = 1;            /* Clear ADC2 interrupt status         */
}

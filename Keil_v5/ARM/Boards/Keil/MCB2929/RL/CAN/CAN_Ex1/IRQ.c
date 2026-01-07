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


extern volatile          short AD0_val, AD2_val;               


__irq void ADC0_Handler (void) {      /* ADC 0 Interrupt Handler            */

  AD0_val = ADC0_ACD0;                /* Read Conversion Result             */
  ADC0_INT_CLR_STATUS = 1;            /* Clear ADC0 interrupt status        */
}

__irq void ADC2_Handler (void) {      /* ADC 2 Interrupt Handler            */

  AD2_val = ADC2_ACD0;                /* Read Conversion Result             */
  ADC2_INT_CLR_STATUS = 1;            /* Clear ADC2 interrupt status        */
}


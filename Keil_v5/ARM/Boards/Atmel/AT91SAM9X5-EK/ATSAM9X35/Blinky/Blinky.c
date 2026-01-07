/*----------------------------------------------------------------------------
 * Name:    Blinky.c
 * Purpose: Atmel AT91SAM9X35 LED Flasher
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2012 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/
                  

#include <AT91SAM9X35.H>                /* AT91SAM9X35 definitions            */

#define CLOCK_FREQ  64500000            /* Master clock frequency in Hz       */
#define LED_NUM     2                   /* Number of user LEDs                */
const int led_mask[] = { PIO_OER_P21, PIO_OER_P18};
volatile unsigned long SysTickCnt;


__irq void PIT_Handler (void)  {        /* PIT Interrupt Handler (1 ms)       */
  SysTickCnt++;
  AIC->AIC_EOICR = PIT->PIT_PIVR;
}

void Delay (unsigned long tick) {       /* Delay Function                     */
  unsigned long systickcnt;

  systickcnt = SysTickCnt;
  while ((SysTickCnt - systickcnt) < tick);
}

int main (void) {                       /* Main Program                       */
  int num = -1; 
  int dir =  1;

  PMC->PMC_PCER   |= PMC_PCER_PID2;                    /* Enable clock for LED */
  PIOD->PIO_OER   |= PIO_OER_P21;                      /* Config LED as output */
  PIOB->PIO_OER   |= PIO_OER_P18;
  PIOD->PIO_SODR  |= PIO_OER_P21;                      /* Clear the LED        */
  PIOB->PIO_SODR  |= PIO_OER_P18;

  /* Setup System Timer to generate interrupt every 1 ms                      */
  PIT->PIT_MR  = CLOCK_FREQ/16/1000 - 1;
  PIT->PIT_MR |= PIT_MR_PITEN;    /* Run System Timer     */
  PIT->PIT_MR |= PIT_MR_PITIEN;
  AIC->AIC_SVR[SYS_IRQn] = (unsigned int) PIT_Handler;
  AIC->AIC_SMR[SYS_IRQn] = AIC_SMR_SRCTYPE_INT_LEVEL_SENSITIVE;
  AIC->AIC_IECR = AIC_IPR_SYS;    /* Enable ST interrupt  */
  PIT->PIT_MR |= PIT_MR_PITEN;    /* Run System Timer     */


  for (;;) {                            /* Loop forever                       */
    /* Calculate 'num': 0,1,...,LED_NUM-1,LED_NUM-1,...,1,0,0,...             */
    num += dir;
    if (num == LED_NUM) { dir  =  -1; num =  LED_NUM-1; } 
    else if   (num < 0) { dir  =   1; num =  0;         }

    if (num) PIOB->PIO_SODR |= led_mask[num];          /* Turn LED 0 on        */
    else     PIOD->PIO_SODR |= led_mask[num];          /* Turn LED 1 on        */

    Delay(500);                                        /* Delay 500ms          */
    if (num) PIOB->PIO_CODR |= led_mask[num];          /* Turn LED 0 off       */
    else     PIOD->PIO_CODR |= led_mask[num];          /* Turn LED 1 off       */
    Delay(500);                                        /* Delay 500ms          */
  }
}

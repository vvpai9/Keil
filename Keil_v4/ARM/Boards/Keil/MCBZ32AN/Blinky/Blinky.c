/******************************************************************************/
/* Blinky.c: LED Flasher                                                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2009 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/
                  
#include <Z32AN.H>                      /* Z32AN definitions                  */
#include "LCD.h"                        /* LCD function prototypes            */

#define CLOCK_FREQ  96000000            /* Master clock frequency in Hz       */
#define LED_NUM     8                   /* Number of user LEDs                */
const int led_mask[] = { 1<<0, 1<<1, 1<<2, 1<<3, 1<<4, 1<<5, 1<<6, 1<<7 };

#define LEDS_EN         BSP_WR32(GPIO0_BASE | GPIO_OE_SET , 0xFF)
#define LED_ON(mask)    BSP_WR32(GPIO0_BASE | GPIO_OUT_SET, mask)
#define LED_OFF(mask)   BSP_WR32(GPIO0_BASE | GPIO_OUT_CLR, mask)

volatile unsigned char ClockLEDOn;
volatile unsigned char ClockLEDOff;
volatile unsigned long AD_Val;

__irq void TMR8_Handler (void)  {       /* Timer8 Interrupt Handler (1 ms)    */
  static unsigned long ticks;

  ticks++;
  switch (ticks) {
    case  0:
      ClockLEDOn  = 1;                  /* Flag to turn LED on on cycle begin */
      break;
    case  20:
      ClockLEDOff = 1;                  /* Flag to turn LED off after 20 ms   */
      break;
    case  50:                           /* Restart the cycle afer 50 ms       */
      ticks       = 0;
      ClockLEDOn  = 1;
      BSP_WR32(ADC_CMD_REG, (1<<1));  /* Start ADC Conversion               */
    default:
      break;
  }
  BSP_WR32(TMR8_BASE | TMR_INT_REG, 1);	/* Clear timer interrupt              */
  BSP_WR32(INTC_IEND_REG, 0);           /* End interrupt                      */
}

__irq void ADC_Handler (void)  {        /* ADC Interrupt Handler              */
  AD_Val  = BSP_RD32(ADC_FIFO_REG);     /* Read the Converted Value           */
  AD_Val &= 0x3FF;                      /* Mask out Sample Pin information    */
  BSP_WR32(ADC_ISTA_REG, (1<<8));	      /* Clear FIFO Level Interrupt         */
  BSP_WR32(INTC_IEND_REG, 0);           /* End interrupt                      */
}

int main (void) {                       /* Main Program                       */
  unsigned long ad_last;
  int num = -1; 
  int dir =  1;

  LEDS_EN;                              /* Enable GPIOs for LED driving       */

  lcd_init  ();
  lcd_clear ();
  lcd_print (" MCBZ32AN DEMO  ");
  set_cursor(0, 1);
  lcd_print ("  www.keil.com  ");
  lcd_delay (100000000);

  /* Enable ADC measurement to work in interrupt mode                         */
  BSP_WR32(ADC_CFG_REG, (1<<8) | (CLOCK_FREQ/500000));
  BSP_WR32(ADC_INT_REG, (1<<9) | (1<<8) | (0<<0));
  BSP_WR32(INTC_VEC_N_REG + (INTNUM_ADC<<2), (unsigned long)&ADC_Handler);
  BSP_WR32(INTC_EN_REG, BSP_RD32(INTC_EN_REG) | INT_MASK_ADC);

  /* Setup Timer8 to generate interrupt every 1 ms                            */
  BSP_WR32(TMR8_BASE | TMR_CMP_REG, CLOCK_FREQ/1000);
  BSP_WR32(TMR8_BASE | TMR_CTL_REG, TMR_TEN | TMR_MODE_RELOAD);
  BSP_WR32(INTC_VEC_N_REG + (INTNUM_TIMER8<<2), (unsigned long)&TMR8_Handler);
  BSP_WR32(INTC_EN_REG, BSP_RD32(INTC_EN_REG) | INT_MASK_TIMER8);

  for (;;) {                            /* Loop forever                       */
    if (ClockLEDOn) {
      ClockLEDOn  = 0;

      /* Calculate 'num': 0,1,...,LED_NUM-1,LED_NUM-1,...,1,0,0,...           */
      num += dir;
      if (num == LED_NUM) { dir = -1; num =  LED_NUM-1; } 
      else if   (num < 0) { dir =  1; num =  0;         }

      LED_ON(led_mask[num]);            /* Turn LED on                        */
    }
    if (ClockLEDOff) {
      ClockLEDOff = 0;
      LED_OFF(led_mask[num]);           /* Turn LED off                       */
    }
    if (AD_Val != ad_last) {
      ad_last = AD_Val;
      lcd_bargraphXY(0, 1, 16, (ad_last*100)/1024);
    }
  }
}

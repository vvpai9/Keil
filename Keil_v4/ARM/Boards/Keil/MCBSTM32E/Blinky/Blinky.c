/*----------------------------------------------------------------------------
 * Name:    Blinky.c
 * Purpose: LED Flasher for MCBSTM32E
 * Version: V1.00
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2009 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------
 * History:
 *          V1.00 Initial Version
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stm32f10x_lib.h>                        // STM32F10x Library Definitions
#include "STM32_Init.h"                           // STM32 Initialization
#include "GLCD.h"                                 // GLCD function prototypes

#define AD_VALUE_MAX 0xFFF

/*----------------------------------------------------------------------------
  note: 
  LCD corrupts AD values due to HW design.
  set __USE_LCD in "options for target - C/C++ - Define" to enable Output on LCD
  set __USE_DMA in "options for target - C/C++ - Define" to enable ADC in DMA mode
                                                        default is ADC in IRQ mode
 *----------------------------------------------------------------------------*/

volatile unsigned short ADC_ConvertedValue;
volatile unsigned char  Clock1s;
                  char  text[40];


/*----------------------------------------------------------------------------
  Additional LCD defines and functions used to draw a bargraph
 *----------------------------------------------------------------------------*/
#define FONT_WIDTH      16
#define FONT_HEIGHT     24
#define DISPLAY_WIDTH  320

static void drawBargraphH(unsigned short x, unsigned short y, unsigned short len) {
  unsigned short i, j;

  for (i = 0; i < FONT_HEIGHT; i++) {
    for(j = 0; j < len; j++) {
	  GLCD_putPixel(x+i, DISPLAY_WIDTH-1-y-j);       
	}
  }
}


/*----------------------------------------------------------------------------
  Initialises the Analog/Digital converter
  PC4 (ADC Channel14) is used as analog input
  use DMA Channel1 for ADC1 (see DMA request mapping)
 *----------------------------------------------------------------------------*/
static void adc_Init (void) {

//  GPIOC->CRL &= ~0x000F0000;                    // set PIN4 as analog input (see stm32_Init.c)

#ifdef __USE_DMA
  RCC->AHBENR |= (1<<0);                          // enable periperal clock for DMA

  DMA1_Channel1->CMAR  = (u32)&ADC_ConvertedValue;// set channel1 memory address
  DMA1_Channel1->CPAR  = (u32)&(ADC1->DR);        // set channel1 peripheral address
  DMA1_Channel1->CNDTR = 1;                       // transmit 1 word
  DMA1_Channel1->CCR   = 0x00002520;              // configure DMA channel
  DMA1_Channel1->CCR  |= (1 << 0);                // DMA Channel 1 enable
#endif //

  RCC->APB2ENR |= (1<<9);                         // enable periperal clock for ADC1

  ADC1->SQR1  = 0x00000000;                       // only one conversion
  ADC1->SMPR1 = (5<<12);                          // set sample time channel14 (55,5 cycles)
  ADC1->SQR3  = (14<<0);                          // set channel14 as 1st conversion
                                                  //     channel14 = PC4
#ifdef __USE_DMA
  ADC1->CR1   = 0x00000100;                       // use independant mode, SCAN mode
  ADC1->CR2   = 0x000E0103;                       // use data align right,continuous conversion, , DMA mode
#else
  ADC1->CR1   = 0x00000120;                       // use independant mode, SCAN mode, EOC interrupt
  ADC1->CR2   = 0x000E0003;                       // use data align right,continuous conversion
#endif
                                                  // EXTSEL = SWSTART 
                                                  // enable ADC, no external Trigger

  ADC1->CR2  |= 0x00000008;                       // Reset calibration
  while (ADC1->CR2 & 0x00000008);                 // wait unil reset finished

  ADC1->CR2  |= 0x00000004;                       // start calibration
  while (ADC1->CR2 & 0x00000004);                 // wait unil calibration finished

#ifndef __USE_DMA
  NVIC->ISER[0] |= (1 << ADC1_2_IRQChannel);      // enable interrupt
#endif

  ADC1->CR2  |= 0x00500000;                       // start SW conversion
}


#ifndef __USE_DMA
/*----------------------------------------------------------------------------
  calculate an average over 16 AD values
 *----------------------------------------------------------------------------*/
static unsigned short CalcAverage (unsigned short val)  {
  static unsigned short idx      =  0;
  static unsigned short aval[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  static unsigned int   sum      =  0;

  sum = sum - aval[idx] + val;
  aval[idx] = val;         
  idx = (idx +1 ) & 0x1F;

  return (sum >> 5);
}


/*----------------------------------------------------------------------------
  ADC1_2 Interrupt Handler
 *----------------------------------------------------------------------------*/
void ADC_IRQHandler (void) {
  if (ADC1->SR & (1<<1)) {                         // ADC1 EOC interrupt?
//    ADC_ConvertedValue = ADC1->DR;
    ADC_ConvertedValue  = CalcAverage (ADC1->DR);  // calculate average

    ADC1->SR &= ~(1<<1);                           // clear EOC interrupt
  }

}
#endif //__USE_DMA

/*----------------------------------------------------------------------------
  Systick Interrupt Handler
  SysTick interrupt happens every 10 ms
 *----------------------------------------------------------------------------*/
void SysTick_Handler (void) {
  static unsigned long ticks;
  static unsigned long timetick;
  static unsigned char leds = 0x01;

  if (ticks++ >= 99) {                           // Set Clock1s to 1 every 1 second
    ticks   = 0;
    Clock1s = 1;
  }
                                                 // Blink the LEDs depending on ADC_ConvertedValue
  if (timetick++ >= (ADC_ConvertedValue>>8)) {
    timetick   = 0;
    leds     <<= 1;
    if (leds == 0) leds = 0x01;
    GPIOB->ODR = (GPIOB->ODR & 0xFFFF00FF) | (leds << 8);
  }

} // end SysTick_Handler


/*----------------------------------------------------------------------------
  MAIN function
 *----------------------------------------------------------------------------*/
int main (void) {
  int AD_value;
  int AD_valueOld = 0;
  int barLen;

  stm32_Init ();                                  // STM32 setup
  adc_Init();                                     // initialise A/D converter

#ifdef __USE_LCD
  GLCD_init();
  GLCD_clear(White);

  GLCD_setBackColor(Blue);
  GLCD_setTextColor(White);
  GLCD_displayStringLn(Line0, "   MCBSTM32E Demo   ");
  GLCD_displayStringLn(Line1, "       Blinky       ");
  GLCD_displayStringLn(Line2, "    www.keil.com    ");
  GLCD_setBackColor(White);
  GLCD_setTextColor(Blue);

#endif // __USE_LCD

  while (1) {                                     // Loop forever
    AD_value  = ADC_ConvertedValue;               // Read AD value

    if (AD_value != AD_valueOld) {                // If new AD value different than old
	  barLen = (DISPLAY_WIDTH*AD_value)/AD_VALUE_MAX;
#ifdef __USE_LCD
      GLCD_setTextColor(Red);
      drawBargraphH (Line6,      0,               barLen); // draw new bar
      GLCD_setTextColor(White);
      drawBargraphH (Line6, barLen, DISPLAY_WIDTH-barLen); // delete old bar
#endif // __USE_LCD
      AD_valueOld = AD_value;
    }

    if (Clock1s) {                                // Print message with AD value to serial port every second
      Clock1s = 0;
      sprintf(text, "AD value = 0x%04X", AD_value);

      printf("%s\r\n", text);
#ifdef __USE_LCD
      GLCD_setTextColor(Blue);
      GLCD_displayStringLn(Line5, (unsigned char *)text);
#endif // __USE_LCD
    }
  }
}

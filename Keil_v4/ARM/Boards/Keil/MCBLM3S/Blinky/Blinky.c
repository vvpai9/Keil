/******************************************************************************/
/* BLINKY.C: LED Flasher                                                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2008 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#include <LM3Sxxxx.H>

/* LED definitions */
#define RED     0x01
#define YELLOW  0x02
#define GREEN   0x04
#define STOP    0x08
#define GO      0x10


/* LED Output function */
void LED_Out (unsigned long led) {
  GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0 | GPIO_PIN_1 | 
                                GPIO_PIN_2 | GPIO_PIN_3, led);
  GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0,              led >> 4);
}


/* Global variables */
unsigned short Ticks;           // Tick Counter
unsigned long  AD_Val[8];       // A/D Results
unsigned short AD_Value;        // A/D Value


/* SysTick interrupt happens every 10 ms */
void SysTick_Handler (void) {
  unsigned long led = 0;

  if (++Ticks == 100) Ticks = 0;

  /* Ticks control Go LED */
  if (Ticks >= 50) {
    led |= GO;
  }
      
  /* Get the A/D result and start next conversion */
  ADCSequenceDataGet(ADC_BASE, 0, AD_Val);
  ADCProcessorTrigger(ADC_BASE, 0);

  /* Show A/D result as LED bar: Red, Yellow, Green */
  if (AD_Val[0] > 768) {
    led |= RED | YELLOW | GREEN;  
  }
  else if (AD_Val[0] > 512) {
    led |= RED | YELLOW;  
  }
  else if (AD_Val[0] > 256) {
    led |= RED;  
  }

  /* Push button controls Stop LED */
  if (GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_4)) {
    led |= STOP;
  }

  /* Display LEDs */
  LED_Out(led);

  AD_Value = AD_Val[0];
}


/* Main program */
int main (void) {

  /* Set the clocking to run directly from the crystal */
  SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                 SYSCTL_XTAL_6MHZ);

  /* Enable peripherals */
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC);

  /* Configure push button pin as input */
  GPIODirModeSet(GPIO_PORTC_BASE, GPIO_PIN_4, GPIO_DIR_MODE_IN);

  /* Configure LED pins as outputs */
  GPIODirModeSet(GPIO_PORTD_BASE, GPIO_PIN_0 | GPIO_PIN_1 |
                                  GPIO_PIN_2 | GPIO_PIN_3, GPIO_DIR_MODE_OUT);
  GPIODirModeSet(GPIO_PORTB_BASE, GPIO_PIN_0,              GPIO_DIR_MODE_OUT);

  /* Configure A/D channel 0 to use sequence 0 (take one sample and stop) */
  ADCSequenceConfigure(ADC_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);
  ADCSequenceStepConfigure(ADC_BASE, 0, 0, ADC_CTL_CH0 | ADC_CTL_END);
  ADCSequenceEnable(ADC_BASE, 0);

  /* Trigger the initial A/D conversion */
  ADCProcessorTrigger(ADC_BASE, 0);

  /* Setup and enable SysTick with interrupt (100Hz) */
  SysTickPeriodSet(SysCtlClockGet() / 100);
  SysTickEnable();
  SysTickIntEnable();

  /* Endless Loop */
  while (1) {
  }
}

/*----------------------------------------------------------------------------
 * Name:    LED.c
 * Purpose: Low level LED functions
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <LPC24xx.H>                    /* LPC24xx definitions                */
#include <stdint.h>
#include "LED.h"

#define NUM_LEDS  4                     /* Number of LEDs                     */

/* I2C definitions */
#define I2C_AA      0x00000004              /* I2C Assert acknowledge flag */
#define I2C_SI      0x00000008              /* I2C interrupt flag */
#define I2C_STO     0x00000010              /* I2C STOP flag */
#define I2C_STA     0x00000020              /* I2C START flag */
#define I2C_I2EN    0x00000040              /* I2C enable */
static uint32_t LED_State;              /* Currend LED state                  */

/*-----------------------------------------------------------------------------
 *      LED_Init:  Initialize LEDs
 *
 * Parameters: (none)
 * Return:     (none)
 *----------------------------------------------------------------------------*/
void LED_Init (void) {
  PCONP    |=  (1 << 7);                /* Enable clock for I2C0              */

  PINSEL1  &= ~0x03C00000;              /* P0.27 SDA, P0.28 SCL               */
  PINSEL1  |=  0x01400000;              /* PINSEL1 22.23, 24.25               */
  
  I20CONCLR =  I2C_AA  | I2C_SI | 
               I2C_STA | I2C_I2EN;      /* Clear I2C state machine            */

  I20SCLL   =  0x80;                    /* Setup I2C clock speed              */
  I20SCLH   =  0x80;

  I20CONSET =  I2C_I2EN;
  I20CONSET =  I2C_STO;
}


/*-----------------------------------------------------------------------------
 *      LED_Set:  Set value to LEDs
 *
 * Parameters: (none)
 * Return:     (none)
 *----------------------------------------------------------------------------*/
static void LED_Set (uint32_t value) {
  unsigned int val = (value & 0xF);     /* Only 4 bits are used               */

  I20CONCLR =  I2C_AA | I2C_SI | I2C_STA | I2C_STO;
  I20CONSET =  I2C_STA;
  while (!(I20CONSET & I2C_SI));        /* Wait for START                     */
  I20DAT    =  0xC0;                    /* Write to device 0xC0               */
  I20CONCLR =  I2C_SI | I2C_STA;
  while (!(I20CONSET & I2C_SI));        /* Wait for ADDRESS send              */
  I20DAT    =  0x18;                    /* Select LS2 register                */
  I20CONCLR =  I2C_SI;
  while (!(I20CONSET & I2C_SI));            /* Wait for DATA send             */
  I20DAT    =  (0x01 * ((val >> 0) & 1)) |	/* Set data                       */
               (0x04 * ((val >> 1) & 1)) |
               (0x10 * ((val >> 2) & 1)) |
               (0x40 * ((val >> 3) & 1)) ;
	I20CONCLR =  I2C_SI;
  while (!(I20CONSET & I2C_SI));        /* Wait for DATA send                 */
  I20CONSET =  I2C_STO;
  I20CONCLR =  I2C_SI;
  while (I20CONSET & I2C_STO);          /* Wait for STOP                      */
}

/*-----------------------------------------------------------------------------
 *      LED_UnInit:  Uninitialize LEDs; pins are set to reset state
 *
 * Parameters: (none)
 * Return:     (none)
 *----------------------------------------------------------------------------*/
void LED_UnInit(void) {
}

/*-----------------------------------------------------------------------------
 *      LED_On: Turns on requested LED
 *
 * Parameters:  num - LED number
 * Return:     (none)
 *----------------------------------------------------------------------------*/
void LED_On (uint32_t num) {

  LED_State |= (1 << num);
  LED_Set(LED_State);
}

/*-----------------------------------------------------------------------------
 *       LED_Off: Turns off requested LED
 *
 * Parameters:  num - LED number
 * Return:     (none)
 *----------------------------------------------------------------------------*/
void LED_Off (uint32_t num) {

  LED_State &= ~(1 << num);
  LED_Set(LED_State);
}

/*-----------------------------------------------------------------------------
 *       LED_Val: Write value to LEDs
 *
 * Parameters:  val - value to be displayed on LEDs
 * Return:     (none)
 *----------------------------------------------------------------------------*/
void LED_Val (uint32_t val) {
  int i;

  for (i = 0; i < NUM_LEDS; i++) {
    if (val & (1<<i)) {
      LED_On (i);
    } else {
      LED_Off(i);
    }
  }
}

/*-----------------------------------------------------------------------------
 *       LED_Num: Get number of available LEDs
 *
 * Parameters: (none)
 * Return:      number of available LEDs
 *----------------------------------------------------------------------------*/
uint32_t LED_Num (void) {
  return (NUM_LEDS);
}

/*-----------------------------------------------------------------------------
 * End of file
 *----------------------------------------------------------------------------*/

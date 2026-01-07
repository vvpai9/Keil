/*----------------------------------------------------------------------------
 *      RL-ARM - USB
 *----------------------------------------------------------------------------
 *      Name:    IO.c
 *      Purpose: Input/Output
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <RTL.h>
#include <LPC24xx.H>

/* I2C definitions */
#define I2C_AA      0x00000004          /* I2C Assert acknowledge flag        */
#define I2C_SI      0x00000008          /* I2C interrupt flag                 */
#define I2C_STO     0x00000010          /* I2C STOP flag                      */
#define I2C_STA     0x00000020          /* I2C START flag                     */
#define I2C_I2EN    0x00000040          /* I2C enable                         */

#ifdef __RTX
static  OS_MUT      I2C_Mutex;
#else
static unsigned int IntCnt = 0;
#endif



/*-----------------------------------------------------------------------------
  Initialize the I2C interface
 *----------------------------------------------------------------------------*/

void IO_Init (void) {
#ifdef __RTX
  os_mut_init(&I2C_Mutex);
#endif
  
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
  Wait for I2C status
 *----------------------------------------------------------------------------*/
__inline static unsigned int  I2C_WaitValidStatus (unsigned int stat, unsigned int interrupt) {
  unsigned int tout;
  
  tout = 1000;
  while (!(I20CONSET & stat) && (tout--)); /* Wait for START                  */
#ifdef __RTX
    if (tout == 0) return (1);
#else
  if ((tout == 0) || (interrupt != IntCnt)) return (1);
#endif
    else return (0);
}

/*-----------------------------------------------------------------------------
  Set value to LEDs
 *----------------------------------------------------------------------------*/

void Out_Set (unsigned int val) {
  static unsigned int interrupt;
  
  val &= 0x0F;                          /* only 4 bits are used               */

#ifdef __RTX
  os_mut_wait(&I2C_Mutex, 0xFFFF);
  interrupt = 0;
#endif
  while (1) {
#ifndef __RTX
    IntCnt++;
    interrupt = IntCnt;
#endif
    
    I20CONCLR =  I2C_AA | I2C_SI | I2C_STA | I2C_STO;
    I20CONSET =  I2C_STA;    
    if (I2C_WaitValidStatus (I2C_SI, interrupt)) continue;
    I20DAT    =  0xC0;                  /* write to device 0xC0               */
    I20CONCLR =  I2C_SI | I2C_STA;
    if (I2C_WaitValidStatus (I2C_SI, interrupt)) continue;    
    I20DAT    =  0x18;                  /* select LS2 register                */
    I20CONCLR =  I2C_SI;
    if (I2C_WaitValidStatus (I2C_SI, interrupt)) continue;    
    I20DAT    =  (0x01 * ((val >> 0) & 1)) |    /* set data                   */
                 (0x04 * ((val >> 1) & 1)) |
                 (0x10 * ((val >> 2) & 1)) |
                 (0x40 * ((val >> 3) & 1)) ;
    I20CONCLR =  I2C_SI;
    if (I2C_WaitValidStatus (I2C_SI, interrupt)) continue;
    I20CONSET =  I2C_STO;
    I20CONCLR =  I2C_SI;
    if (I2C_WaitValidStatus (I2C_STO, interrupt)) continue;
    else break;
  }
#ifdef __RTX
  os_mut_release(&I2C_Mutex);
#endif
}


/*------------------------------------------------------------------------------
  Get value from the Push Buttons
 *-----------------------------------------------------------------------------*/

U32 In_Get (void) {
  unsigned int val;
  static unsigned int interrupt;

#ifdef __RTX
  os_mut_wait(&I2C_Mutex, 0xFFFF);
  interrupt = 0;
#endif
  while (1) {
#ifndef __RTX
    IntCnt++;
    interrupt = IntCnt;
#endif
    
    I20CONCLR =  I2C_AA | I2C_SI | I2C_STA | I2C_STO;
    I20CONSET =  I2C_STA;
    if (I2C_WaitValidStatus (I2C_SI, interrupt)) continue;
    I20DAT    =  0xC0;                    /* write to device 0xC0             */
    I20CONCLR =  I2C_SI | I2C_STA;
    if (I2C_WaitValidStatus (I2C_SI, interrupt)) continue;
    I20DAT    =  0x00;                    /* select input register 0          */
    I20CONCLR =  I2C_SI;
    if (I2C_WaitValidStatus (I2C_SI, interrupt)) continue;

    I20CONSET =  I2C_STA;
    I20CONCLR =  I2C_SI;
    if (I2C_WaitValidStatus (I2C_SI, interrupt)) continue;
    I20DAT    =  0xC1;                    /* read from device 0xC0            */
    I20CONCLR =  I2C_SI | I2C_STA;
    if (I2C_WaitValidStatus (I2C_SI, interrupt)) continue;

    I20CONCLR =  I2C_SI;
    if (I2C_WaitValidStatus (I2C_SI, interrupt)) continue;
    val = I20DAT;                         /* read data                        */

    I20CONSET =  I2C_STO;
    I20CONCLR =  I2C_SI;
    if (I2C_WaitValidStatus (I2C_SI, interrupt)) continue;
    else break;
  }
#ifdef __RTX
  os_mut_release(&I2C_Mutex);
#endif

  return (~val & 0x0F);                  /* only 4 bits are used              */
}

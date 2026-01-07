/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : Board.h
* Object              : Evaluation Board Features Definition File.
*
* Creation            : JPP   16/Oct/2004
*----------------------------------------------------------------------------
*/
#ifndef Board_h
#define Board_h

#define true  -1
#define false  0

/*-------------------------------*/
/* SAM7Board Memories Definition */
/*-------------------------------*/
// The AT91SAM7S64 embeds a 16-Kbyte SRAM bank, and 64 K-Byte Flash

#define  INT_SARM           0x00200000
#define  INT_SARM_REMAP     0x00000000

#define  INT_FLASH          0x00000000
#define  INT_FLASH_REMAP    0x01000000

#define  FLASH_PAGE_NB      512
#define  FLASH_PAGE_SIZE    128

/*-----------------*/
/* LEDs Definition */
/*-----------------*/
/*                                 PIO   Flash    PA    PB   PIN */


#define LED1            (1<<1)  /* PA1/ PGMEN0 & PWM0 TIOA0  47*/
#define LED2            (1<<2)  /* PA2 / PGMEN1 & PWM1 TIOB0  44 */
#define LED3            (1<<3)  /* PA3          & PWM2 SCK0   43 */
//#define LED4			(1<<4)

#define NB_LED          3

#define LED_MASK        (LED1|LED2|LED3)


/*------------------*/
/* USART Definition */
/*------------------*/
/* SUB-D 9 points J3 DBGU */
#define DBGU_RXD        AT91C_PA9_DRXD    /* JP11 must be close */
#define DBGU_TXD        AT91C_PA10_DTXD   /* JP12 must be close */
#define AT91C_DBGU_BAUD 115200            // Baud rate

#define US_RXD_PIN      AT91C_PA5_RXD0    /* JP9 must be close */
#define US_TXD_PIN      AT91C_PA6_TXD0    /* JP7 must be close */
#define US_RTS_PIN      AT91C_PA7_RTS0    /* JP8 must be close */
#define US_CTS_PIN      AT91C_PA8_CTS0    /* JP6 must be close */

/*--------------*/
/* Master Clock */
/*--------------*/

#define EXT_OC          18432000          // External Oscillator MAINCK
#define MCK             47923200          // MCK (PLLRC div by 2)
#define MCKKHz          (MCK/1000)        // MCK in kHz

#endif /* Board_h */

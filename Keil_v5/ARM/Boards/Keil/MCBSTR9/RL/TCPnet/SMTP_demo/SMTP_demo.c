/*----------------------------------------------------------------------------
 *      RL-ARM - TCPnet
 *----------------------------------------------------------------------------
 *      Name:    SMTP_DEMO.C
 *      Purpose: SMTP Client demo example
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <stdio.h>
#include <RTL.h>
#include <91x_lib.h>                    /* STR912F definitions               */
#include "LCD.h"

#define PCLK       96000000                   /* Timer Clock 96 MHz          */
#define TCLK       10                         /* Timer Clock rate 10/s       */
#define TCNT       (PCLK/TCLK/200-5)          /* Timer Counts                */

/* Enter your valid SMTP Server IP address here. */
U8 srv_ip[4] = { 192,168,0,253 };

BOOL tick;
BOOL tick2;
BOOL sent;
U32  delay;

/*--------------------------- init ------------------------------------------*/

static void init () {
  /* Add System initialisation code here */
  U32 n;

  /* I/O Ports configured as Output (Push-pull) */
  SCU->GPIOOUT[7]  = 0x5555;
  GPIO7->DDR       = 0xFF;
  GPIO7->DR[0x3FC] = 0x00;

  /* Timer 0 as interval timer, reload to 100ms. */
  TIM0->OC2R  =  TCNT;
  TIM0->CR2   =  TIM_FLAG_OC2 | (200 - 1);
  TIM0->CR1   =  TIM_PWM | 0x8000;

  /* UART1 configured for 115200 baud. */
  SCU->GPIOOUT[3] &= 0xFF3F;                 /* Enable TX1 and RX1 pins      */
  SCU->GPIOOUT[3] |= 0x0080;
  SCU->GPIOIN[3]  |= 0x04;
  UART1->IBRD = 0x1A;                        /* Integer divider for 115kBaud */
  UART1->FBRD = 0x03;                        /* Fractional divider           */
  UART1->LCR  = 0x0060;                      /* 8 bits, no Parity, 1 Stop bit*/
  UART1->CR   = 0x0301;                      /* Enable UART                  */

  /* Configure ADC for 8 analog inputs. */
  SCU->GPIOANA = 0xFF;                       /* Enable AINx pins             */

  ADC->CR |= 0x0002;                         /* Power On ADC                 */
  for (n = 0; n < 100000; n ++);             /* Wait > 1 ms  (at 96 MHz)     */
  ADC->CR &= 0xFFF7;                         /* Clear STB bit                */
  for (n = 0; n < 1500; n++);                /* Wait > 15 us (at 96 MHz)     */
  ADC->PRS = 8;                              /* fadc = PCKL/8 (12MHz)        */
  ADC->CCR = 0xFFFF;                         /* A/D Conversion without wdog  */
}


/*--------------------------- LED_out ---------------------------------------*/

void LED_out (U32 val) {
  GPIO7->DR[0x3FC] = val;
}


/*--------------------------- init_display ----------------------------------*/

static void init_display () {
  /* LCD Module.2x16 init*/

  LCD_init ();
  LCD_cur_off ();
  LCD_puts ("    RL-ARM      "
            "  SMTP example  ");
}


/*--------------------------- timer_poll ------------------------------------*/

static void timer_poll () {
  /* System tick timer running in poll mode */

  if (TIM0->SR & TIM_FLAG_OC2) {
    TIM0->SR = ~TIM_FLAG_OC2;
    /* Timer tick every 100 ms */
    timer_tick ();
    tick  = __TRUE;
    tick2 = __TRUE;
  }
}


/*--------------------------- fputc -----------------------------------------*/

int fputc (int ch, FILE *f)  {
  /* Debug output to serial port. */

  if (ch == '\n')  {
    while (!(UART1->FR & 0x0080));
    UART1->DR = '\r';                        /* output CR                    */
  }
  while (!(UART1->FR & 0x0080));
  return (UART1->DR = ch);
}


/*--------------------------- blink_led -------------------------------------*/

static void blink_led () {
  /* Blink the LEDs on MCB-STR9 board */
  const U8 led_val[16] = { 0x48,0x88,0x84,0x44,0x42,0x22,0x21,0x11,
                           0x12,0x0A,0x0C,0x14,0x18,0x28,0x30,0x50 };
  static U32 cnt;

  if (tick == __TRUE) {
    /* Every 100 ms */
    tick = __FALSE;
    LED_out (led_val[cnt]);
    if (++cnt >= sizeof(led_val)) {
      cnt = 0;
    }
  }
}


/*--------------------------- AD_in ----------------------------------------*/

U16 AD_in (U32 ch) {
  /* Read ARM Analog Input */
  U32 val = 0;
  U32 adcr;

  if (ch < 8) {
    adcr = (ADC->CR & ~(0x0007 << 6)) | (ch << 6);
    ADC->CR = adcr | 0x0001;                  /* Setup A/D: Start Convers. */
    for (val = 0; val < 4; val++);            /* Small delay               */
    do {
      val = ADC->CR;                          /* Read A/D Control Register */
    } while ((val & 0x8000) == 0);            /* Wait for end of A/D Conv. */
    switch (ch) {
      case 0: val = ADC->DR0; break;
      case 1: val = ADC->DR1; break;
      case 2: val = ADC->DR2; break;
      case 3: val = ADC->DR3; break;
      case 4: val = ADC->DR4; break;
      case 5: val = ADC->DR5; break;
      case 6: val = ADC->DR6; break;
      case 7: val = ADC->DR7; break;
    }
    val &= 0x03FF;                            /* Extract AINx Value        */
    ADC->CR = adcr;
  }
  return (val);
}


/*---------------------------------------------------------------------------*/

static void smtp_cback (U8 code) {
  /* This function is called by TcpNet to inform about SMTP status. */
  switch (code) {
    case SMTP_EVT_SUCCESS:
      printf ("Email successfully sent\n");
      sent = __TRUE;
      break;
    case SMTP_EVT_TIMEOUT:
      /* Timeout, try again. */
      printf ("Mail Server timeout.\n");
      delay = 0;
      break;
    case SMTP_EVT_ERROR:
      /* Error, try again. */
      printf ("Error sending email.\n");
      delay = 0;
      break;
  }
}

/*---------------------------------------------------------------------------*/

int main (void) {
  /* Main Thread of the TcpNet */

  init ();
  init_display ();
  init_TcpNet ();

  delay = 0;
  sent  = __FALSE;
  while (1) {
    timer_poll ();
    main_TcpNet ();
    blink_led ();
    if (tick2 == __FALSE) {
      continue;
    }
    tick2 = __FALSE;
    if (sent == __TRUE) {
      continue;
    }
    if (++delay == 100) {
      /* After 10 seconds send an email. */
      printf ("Sending email...\n");
      smtp_connect ((U8 *)&srv_ip,25,smtp_cback);
    }
  }
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/

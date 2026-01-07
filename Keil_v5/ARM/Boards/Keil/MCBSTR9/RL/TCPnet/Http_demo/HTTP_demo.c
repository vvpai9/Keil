/*----------------------------------------------------------------------------
 *      RL-ARM - TCPnet
 *----------------------------------------------------------------------------
 *      Name:    HTTP_DEMO.C
 *      Purpose: HTTP Server demo example
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <stdio.h>
#include <RTL.h>
#include <Net_Config.h>
#include <91x_lib.h>                    /* STR912F definitions               */
#include "LCD.h"

#define PCLK       96000000                   /* Timer Clock 96 MHz          */
#define TCLK       10                         /* Timer Clock rate 10/s       */
#define TCNT       (PCLK/TCLK/200-5)          /* Timer Counts                */

BOOL LEDrun;
BOOL LCDupdate;
BOOL tick;
U32  dhcp_tout;
U8   lcd_text[2][16+1] = {"    RL-ARM",       /* Buffer for LCD text         */
                          "  HTTP example"};

extern LOCALM localm[];                       /* Local Machine Settings      */
#define MY_IP localm[NETIF_ETH].IpAdr
#define DHCP_TOUT   50                        /* DHCP timeout 5 seconds      */

static void init_io (void);
static void init_display (void);

#ifdef RTX_KERNEL
 U64 tcp_stack[800/8];                        /* A bigger stack for tcp_task */

 /* Forward references */
 __task void init       (void);
 __task void blink_led  (void);
 __task void timer_task (void);
 __task void tcp_task   (void);
#endif

/*--------------------------- init ------------------------------------------*/

#ifndef RTX_KERNEL

static void init () {
  /* Add System initialisation code here */

  init_io ();
  init_display ();
  init_TcpNet ();

  /* Timer 0 as interval timer, reload to 100ms. */
  TIM0->OC2R = TCNT;
  TIM0->CR2  = TIM_FLAG_OC2 | (200 - 1);
  TIM0->CR1  = TIM_PWM | 0x8000;
}

#else

__task void init (void) {
  /* Add System initialisation code here */ 

  init_io ();
  init_display ();
  init_TcpNet ();

  /* Initialize Tasks */
  os_tsk_prio_self (100);
  os_tsk_create (blink_led, 20);
  os_tsk_create (timer_task, 30);
  os_tsk_create_user (tcp_task, 0, &tcp_stack, sizeof(tcp_stack));
  os_tsk_delete_self();
}

#endif

/*--------------------------- timer_poll ------------------------------------*/

#ifndef RTX_KERNEL

static void timer_poll () {
  /* System tick timer running in poll mode */

  if (TIM0->SR & TIM_FLAG_OC2) {
    TIM0->SR = ~TIM_FLAG_OC2;
    /* Timer tick every 100 ms */
    timer_tick ();
    tick = __TRUE;
  }
}

#else

__task void timer_task (void) {
  /* System tick timer task */
  os_itv_set (10);
  while (1) {
    timer_tick ();
    tick = __TRUE;
    os_itv_wait ();
  }
}

#endif


/*--------------------------- init_io ---------------------------------------*/

static void init_io () {
  U32 n;

  /* I/O Ports configured as Output (Push-pull) */
  SCU->GPIOOUT[7]  = 0x5555;
  GPIO7->DDR       = 0xFF;
  GPIO7->DR[0x3FC] = 0x00;

  /* Push Button Setup */
  SCU->GPIOOUT[3] &= 0xC3FF;                 /* P3.5..6 no output            */
  GPIO3->DDR      &= 0x9F;                   /* P3.5..6 Input (Push Buttons) */

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


/*--------------------------- LED_out ---------------------------------------*/

void LED_out (U32 val) {
  GPIO7->DR[0x3FC] = val;
}


/*--------------------------- AD_in -----------------------------------------*/

U16 AD_in (U32 ch) {
  /* Read ARM Analog Input */
  U32 val = 0;
  U32 adcr;

  if (ch < 8) {
    adcr = (ADC->CR & ~(0x0007 << 6)) | (ch << 6);
    ADC->CR = adcr | 0x0001;                  /* Setup A/D: Start Convers. */
    for (val = 0; val < 4; val++);            /* Small delay               */
    do {
      val = ADC->CR;                         /* Read A/D Control Register */
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


/*--------------------------- get_button ------------------------------------*/

U8 get_button (void) {
  /* Read ARM Digital Input */
  U32 val = 0;

  if (GPIO3->DR[0x20<<2] == 0) {
    /* S2 = P3.5 (INT5) */
    val |= 0x01;
  }
  if (GPIO3->DR[0x40<<2] == 0) {
    /* S3 = P3.6 (INT6) */
    val |= 0x02;
  }
  return (val);
}


/*--------------------------- upd_display -----------------------------------*/

static void upd_display () {
  /* Update LCD Module display text. */

  LCD_cls ();
  LCD_puts (lcd_text[0]);
  LCD_gotoxy (1,2);
  LCD_puts (lcd_text[1]);
  LCDupdate =__FALSE;
}


/*--------------------------- init_display ----------------------------------*/

static void init_display () {
  /* LCD Module.2x16 init*/

  LCD_init ();
  LCD_cur_off ();
  upd_display ();
}


/*--------------------------- dhcp_check ------------------------------------*/

static void dhcp_check () {
  /* Monitor DHCP IP address assignment. */

  if (tick == __FALSE || dhcp_tout == 0) {
    return;
  }
#ifdef RTX_KERNEL
  tick = __FALSE;
#endif
  if (mem_test (&MY_IP, 0, IP_ADRLEN) == __FALSE && !(dhcp_tout & 0x80000000)) {
    /* Success, DHCP has already got the IP address. */
    dhcp_tout = 0;
    sprintf((char *)lcd_text[0],"IP address:");
    sprintf((char *)lcd_text[1],"%d.%d.%d.%d", MY_IP[0], MY_IP[1],
                                               MY_IP[2], MY_IP[3]);
    LCDupdate = __TRUE;
    return;
  }
  if (--dhcp_tout == 0) {
    /* A timeout, disable DHCP and use static IP address. */
    dhcp_disable ();
    sprintf((char *)lcd_text[1]," DHCP failed    " );
    LCDupdate = __TRUE;
    dhcp_tout = 30 | 0x80000000;
    return;
  }
  if (dhcp_tout == 0x80000000) {
    dhcp_tout = 0;
    sprintf((char *)lcd_text[0],"IP address:");
    sprintf((char *)lcd_text[1],"%d.%d.%d.%d", MY_IP[0], MY_IP[1],
                                               MY_IP[2], MY_IP[3]);
    LCDupdate = __TRUE;
  }
}


/*--------------------------- blink_led -------------------------------------*/

#ifndef RTX_KERNEL

static void blink_led () {
  /* Blink the LEDs on MCB-STR9 board */
  const U8 led_val[16] = { 0x48,0x88,0x84,0x44,0x42,0x22,0x21,0x11,
                           0x12,0x0A,0x0C,0x14,0x18,0x28,0x30,0x50 };
  static U32 cnt;

  if (tick == __TRUE) {
    /* Every 100 ms */
    tick = __FALSE;
    if (LEDrun == __TRUE) {
      LED_out (led_val[cnt]);
      if (++cnt >= sizeof(led_val)) {
        cnt = 0;
      }
    }
    if (LCDupdate == __TRUE) {
      upd_display ();
    }
  }
}

#else

__task void blink_led () {
  /* Blink the LEDs on MCB-STR9 board */
  const U8 led_val[16] = { 0x48,0x88,0x84,0x44,0x42,0x22,0x21,0x11,
                           0x12,0x0A,0x0C,0x14,0x18,0x28,0x30,0x50 };
  static U32 cnt;

  LEDrun = __TRUE;
  while(1) {
    /* Every 100 ms */
    if (LEDrun == __TRUE) {
      LED_out (led_val[cnt]);
      if (++cnt >= sizeof(led_val)) {
        cnt = 0;
      }
    }
    if (LCDupdate == __TRUE) {
      upd_display ();
    }
    os_dly_wait(10);
  }
}

#endif


/*---------------------------------------------------------------------------*/

#ifndef RTX_KERNEL

int main (void) {
  /* Main Thread of the TcpNet */

  init ();
  LEDrun = __TRUE;
  dhcp_tout = DHCP_TOUT;
  while (1) {
    timer_poll ();
    main_TcpNet ();
    dhcp_check ();
    blink_led ();
  }
}

#else

__task void tcp_task (void) {
  /* Main Thread of the TcpNet. This task should have */
  /* the lowest priority because it is always READY. */
  dhcp_tout = DHCP_TOUT;
  while (1) {
    main_TcpNet();
    dhcp_check ();
    os_tsk_pass();
  }
}


int main (void) {
  /* Start with 'init' task. */
  os_sys_init(init);
  while(1);
}

#endif


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/

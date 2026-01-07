/*----------------------------------------------------------------------------
 *      RL-ARM - TCPnet
 *----------------------------------------------------------------------------
 *      Name:    SNMP_DEMO.C 
 *      Purpose: SNMP Agent demo example
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

BOOL tick;
U32  dhcp_tout;
BOOL LCDupdate;
U8   lcd_text[2][16+1] = {"    RL-ARM",       /* Buffer for LCD text         */
                          "  SNMP example"};

extern LOCALM localm[];                       /* Local Machine Settings      */
#define MY_IP localm[NETIF_ETH].IpAdr
#define DHCP_TOUT   50                        /* DHCP timeout 5 seconds      */

/*--------------------------- init ------------------------------------------*/

static void init () {
  /* Add System initialisation code here */

  /* I/O Ports configured as Output (Push-pull) */
  SCU->GPIOOUT[7]  = 0x5555;
  GPIO7->DDR       = 0xFF;
  GPIO7->DR[0x3FC] = 0x00;

  /* Push Button Setup */
  SCU->GPIOOUT[3] &= 0xC3FF;                 /* P3.5..6 no output            */
  GPIO3->DDR      &= 0x9F;                   /* P3.5..6 Input (Push Buttons) */

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


/*--------------------------- timer_poll ------------------------------------*/

static void timer_poll () {
  /* System tick timer running in poll mode */

  if (TIM0->SR & TIM_FLAG_OC2) {
    TIM0->SR = ~TIM_FLAG_OC2;
    /* Timer tick every 100 ms */
    timer_tick ();
    tick = __TRUE;
  }
}


/*--------------------------- dhcp_check ------------------------------------*/

static void dhcp_check () {
  /* Monitor DHCP IP address assignment. */

  if (tick == __FALSE || dhcp_tout == 0) {
    return;
  }
  tick = __FALSE;
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


/*---------------------------------------------------------------------------*/

int main (void) {
  /* Main Thread of the TcpNet */

  init ();
  init_display ();
  init_TcpNet ();

  dhcp_tout = DHCP_TOUT;
  LED_out (0x55);

  while (1) {
    timer_poll ();
    main_TcpNet ();
    dhcp_check ();
    if (LCDupdate == __TRUE) {
      upd_display ();
    }
  }
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/

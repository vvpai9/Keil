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
#include <71x_lib.H>

BOOL LEDrun;
BOOL tick;

/*--------------------------- init ------------------------------------------*/

static void init () {
  /* Add System initialisation code here */

  RCCU_MCLKConfig(RCCU_DEFAULT);              /* MCLK = RCLK                 */
  RCCU_FCLKConfig(RCCU_RCLK_2);               /* FCLK = RCLK/2               */
  RCCU_PCLKConfig(RCCU_RCLK_4);               /* PCLK = RCLK/4               */
  RCCU_PLL1Config(RCCU_PLL1_Mul_12, RCCU_Div_2);  /* 48MHz PLL @ 16MHz XTAL  */

  while (RCCU_FlagStatus(RCCU_PLL1_LOCK) == RESET);  /* Wait for PLL to Lock */
  RCCU_RCLKSourceConfig(RCCU_PLL1_Output);           /* Select PLL for RCLK  */

  /* LED pins configured as Push-pull Outputs */
  GPIO_Config(GPIO2, 0xFF00, GPIO_OUT_PP);
  GPIO_ByteWrite (GPIO2, GPIO_MSB, 0x00);

  /* Timer 1 tick interval 100ms. */
  TIM_Init (TIM1);
  TIM_PrescalerConfig (TIM1, 100-1);
  TIM_PWMOModeConfig (TIM1, 0, TIM_HIGH, 12000, TIM_LOW);
  TIM_ITConfig (TIM1, TIM_OCB_IT, ENABLE);
  TIM_CounterConfig (TIM1,TIM_START);

  /* Enable AIN0 Analog Input. */
  GPIO_Config(GPIO1, 0x0001, GPIO_HI_AIN_TRI);

  /* AIN0 configuration. */
  ADC12_Init();
  ADC12_PrescalerConfig(500);
  ADC12_ModeConfig(ADC12_SINGLE);
  ADC12_ChannelSelect(ADC12_CHANNEL0);

  /* Enable RxD0 and TxD0 pins. */
  GPIO_Config(GPIO0, 0x0200, GPIO_AF_PP);
  GPIO_Config(GPIO0, 0x0100, GPIO_IN_TRI_CMOS);

  /* Configure UART0 for 115200 baud, 8 bits, no Parity, 1 Stop bit. */
  UART_OnOffConfig(UART0, ENABLE);
  UART_FifoConfig (UART0, DISABLE);
  UART_FifoReset  (UART0, UART_RxFIFO);
  UART_FifoReset  (UART0, UART_TxFIFO);
  UART_LoopBackConfig(UART0, DISABLE);
  UART_Config(UART0, 115200, UART_NO_PARITY, UART_1_StopBits, UARTM_8D);
  UART_RxConfig(UART0 ,ENABLE);
}


/*--------------------------- timer_poll ------------------------------------*/

static void timer_poll () {
  /* System tick timer running in poll mode */

  if ((TIM_FlagStatus (TIM1, TIM_OCFB) == SET)) {
    /* Timer 1 interrupt rq pending, clear pending interrupt. */
    TIM_FlagClear (TIM1, TIM_OCFB);

    /* Timer tick every 100 ms */
    timer_tick ();
    tick = __TRUE;
  }
}


/*--------------------------- fputc -----------------------------------------*/

int fputc(int ch, FILE *f)  {
  /* Debug output to serial port. */

  sendchar((char *)&ch);
  return (ch);
}


/*--------------------------- LED_out ---------------------------------------*/

void LED_out (U32 val) {

  GPIO_ByteWrite (GPIO2, GPIO_MSB, val);
}


/*--------------------------- AD_in -----------------------------------------*/

U16 AD_in (U32 ch) {
  /* Read ARM Analog Input */
  U32 val = 0;

  if (ch == 0) {
    ADC12_ConversionStart();
    while (ADC12_FlagStatus (ADC12_DA0) == RESET);
    val = ADC12_ConversionValue(ADC12_CHANNEL0);
    val ^= 0x0800;
  }
  return (val);
}


/*--------------------------- get_button ------------------------------------*/

U8 get_button (void) {
  /* Read ARM Digital Input */
  U32 val = 0;

  if ((GPIO1->PD & 0x2000) == 0) {
    /* S2 = P1.13 (Interrupt) */
    val |= 0x01;
  }
  if ((GPIO0->PD & 0x8000) != 0) {
    /* S3 = P0.15 (Wake-Up) */
    val |= 0x02;
  }
  return (val);
}


/*--------------------------- blink_led -------------------------------------*/

static void blink_led () {
  /* Blink the LED on Keil MCB2130 board */
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
  }
}


/*---------------------------------------------------------------------------*/

int main (void) {
  /* Main Thread of the TcpNet */

  init ();
  init_TcpNet ();

  /* Enable PPP server to accept incomming connections. */
  ppp_listen ("Keil", "test");

  LEDrun = __TRUE;
  while (1) {
    timer_poll ();
    main_TcpNet ();
    blink_led ();
  }
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/

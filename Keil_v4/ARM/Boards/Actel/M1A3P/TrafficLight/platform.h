//**********************************************************************
// This code was created by SoC Solutions and is free for use with     *
// Actel products.  For support e-mail support@socsolutions.com.       *
//**********************************************************************

// This header file contains the base address of all the peripherals in the system.

#ifndef PLATFORM_HEADER
#define PLATFORM_HEADER

#define GPIO_BASE_ADDR          0xA0000000
#define UART_BASE_ADDR          0xA1000000
#define TIMER_BASE_ADDR         0xA2000000
#define INTERRUPT_BASE_ADDR     0xA3000000

#define IRQ_UART_RX_MASK        0x00000001
#define IRQ_TIMER_TICK_MASK     0x00000002

#define CM1_NVIC_ENABLE_REG     0xE000E100
#define CM1_NVIC_ENABLECLR_REG  0xE000E180

#define CM1_IRQ0_MASK           0x00000001

#endif /* PLATFORM_HEADER */

//**********************************************************************
// This code was created by SoC Solutions and is free for use with     *
// Actel products.  For support e-mail support@socsolutions.com.       *
//**********************************************************************

// UART functions
extern void uart_puts(unsigned baseAddr, unsigned char *str, unsigned len);
extern void uart_cfg(unsigned baseAddr, unsigned baudRate);
extern unsigned uart_getchar(unsigned baseAddr);

// Timer functions
extern void timer_cfg(unsigned baseAddr, unsigned config, unsigned prescale);
extern void timer_load(unsigned baseAddr, unsigned loadVal);
extern void timer_irq_clear(unsigned baseAddr);

// Interrupt functions
extern void interrupt_irq_enable(unsigned baseAddr, unsigned irqMask);
extern void interrupt_irq_disable(unsigned baseAddr, unsigned irqMask);
extern unsigned interrupt_irq_status(unsigned baseAddr);
extern void cm1_irq_enable(unsigned irqMask);
extern void cm1_irq_disable(unsigned irqMask);

// GPIO functions
extern void gpio_out(unsigned baseAddr, unsigned dataOut);
extern unsigned gpio_in(unsigned baseAddr);

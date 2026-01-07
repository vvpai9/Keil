//**********************************************************************
// This code was created by SoC Solutions and is free for use with     *
// Actel products.  For support e-mail support@socsolutions.com.       *
//**********************************************************************

#define UART_TXDATA_OFFSET			0x00
#define UART_RXDATA_OFFSET			0x04
#define UART_CONTROL1_OFFSET		0x08
#define UART_CONTROL2_OFFSET		0x0C
#define UART_STATUS_OFFSET			0x10

#define UART_CONTROL2_7BITS			0x00
#define UART_CONTROL2_8BITS			0x01

#define UART_CONTROL2_NOPARITY		0x00
#define UART_CONTROL2_PARITY		0x02

#define UART_CONTROL2_EVENPARITY	0x00
#define UART_CONTROL2_ODDPARITY		0x04

#define UART_STATUS_TXREADY_MASK	0x01
#define UART_STATUS_RXREADY_MASK	0x02
#define UART_STATUS_PARITYERR_MASK	0x04
#define UART_STATUS_OVERFLOW_MASK	0x08

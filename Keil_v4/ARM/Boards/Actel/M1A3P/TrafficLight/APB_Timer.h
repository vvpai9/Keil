//**********************************************************************
// This code was created by SoC Solutions and is free for use with     *
// Actel products.  For support e-mail support@socsolutions.com.       *
//**********************************************************************

// Parallel Port register address offsets:
#define TIMER_LOAD_OFFSET      0x00
#define TIMER_CURRENT_OFFSET   0x04
#define TIMER_CONTROL_OFFSET   0x08
#define TIMER_PRESCALE_OFFSET  0x0C
#define TIMER_INTCLR_OFFSET    0x10
#define TIMER_RIS_OFFSET       0x14
#define TIMER_MIS_OFFSET       0x18

#define TIMER_CONTROL_CONTINUOUS  0x00
#define TIMER_CONTROL_ONESHOT     0x04

#define TIMER_CONTROL_IRQDISABLE  0x00
#define TIMER_CONTROL_IRQENABLE   0x02

#define TIMER_CONTROL_DISABLE     0x00
#define TIMER_CONTROL_ENABLE      0x01

#define TIMER_PRESCALE_DIV2       0x00
#define TIMER_PRESCALE_DIV4       0x01
#define TIMER_PRESCALE_DIV8       0x02
#define TIMER_PRESCALE_DIV16      0x03
#define TIMER_PRESCALE_DIV32      0x04
#define TIMER_PRESCALE_DIV64      0x05
#define TIMER_PRESCALE_DIV128     0x06
#define TIMER_PRESCALE_DIV256     0x07
#define TIMER_PRESCALE_DIV512     0x08
#define TIMER_PRESCALE_DIV1024    0x09



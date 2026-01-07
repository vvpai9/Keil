//**********************************************************************
// This code was created by SoC Solutions and is free for use with     *
// Actel products.  For support e-mail support@socsolutions.com.       *
//**********************************************************************

#define CLK_FREQ_HZ         16000000

#define DONT_CARE           1

typedef unsigned            uint32;
typedef unsigned short      uint16;
typedef unsigned char       uint8;

typedef uint32              genAddress;		// The generic address bus
typedef uint32              genData;		// The generic data bus

typedef char			    sint8;

#define PUT_UINT32(addr, data)    (*((volatile uint32 *) (addr)) = (data))
#define PUT_UINT16(addr, data)    (*((volatile uint16 *) (addr)) = (data))
#define PUT_UINT8(addr,  data)    (*((volatile uint8  *) (addr)) = (data))

#define GET_UINT32(addr, pData)   (*(pData) = *((volatile uint32 *) (addr)))
#define GET_UINT16(addr, pData)   (*(pData) = *((volatile uint16 *) (addr)))
#define GET_UINT8(addr,  pData)   (*(pData) = *((volatile uint8  *) (addr)))


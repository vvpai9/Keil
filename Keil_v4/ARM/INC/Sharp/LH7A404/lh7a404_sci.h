/***********************************************************************
 * $Id:: lh7a404_sci.h 14 2007-08-28 16:08:18Z kevinw                  $
 *
 * Project: LH7A404 SCI definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for the LH7A404 component:
 *         Smart Card Interface
 *
 ***********************************************************************
 * Software that is described herein is for illustrative purposes only  
 * which provides customers with programming information regarding the  
 * products. This software is supplied "AS IS" without any warranties.  
 * NXP Semiconductors assumes no responsibility or liability for the 
 * use of the software, conveys no license or title under any patent, 
 * copyright, or mask work right to the product. NXP Semiconductors 
 * reserves the right to make changes in the software without 
 * notification. NXP Semiconductors also make no representation or 
 * warranty that such application will be suitable for the specified 
 * use without further testing or modification. 
 **********************************************************************/

#ifndef LH7A404_SCI_H
#define LH7A404_SCI_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * SCI Register Module Structure
 **********************************************************************/

/* SCI Module Register Structure */ 
typedef struct
{
    volatile UNS_32 data;          /* SCI Data register */
    volatile UNS_32 cr0;           /* SCI Control register zero */
    volatile UNS_32 cr1;           /* SCI Control register one */
    volatile UNS_32 cr2;           /* SCI Control register two */
    volatile UNS_32 ier;           /* SCI Interrupt Enable register */
    volatile UNS_32 retry;         /* SCI Retry Limit register */
    volatile UNS_32 wmark;         /* SCI FIFO Tide water mark reg */
    volatile UNS_32 txcount;       /* SCI TX FIFO Count Clear reg */
    volatile UNS_32 rxcount;       /* SCI TX FIFO Count Clear reg */
    volatile UNS_32 fr;            /* SCI FIFO status register */
    volatile UNS_32 rxtime;        /* SCI Receive Read timeout reg */
    volatile UNS_32 dstat;         /* SCI Direct Status register */
    volatile UNS_32 stable;        /* SCI De-Bounce timer register */
    volatile UNS_32 atime;         /* SCI Activation Event time reg */
    volatile UNS_32 dtime;         /* SCI Deactivation Event time reg */
    volatile UNS_32 atrstime;      /* SCI Time To Start ATR RX reg */
    volatile UNS_32 atrdtime;      /* SCI ATD Max char Duration reg */
    volatile UNS_32 blktime;       /* SCI Block to Block RX TimeOut */
    volatile UNS_32 chtime;        /* SCI Char to Char RX TimeOut */
    volatile UNS_32 clkdiv;        /* SCI External Clock Frequency */
    volatile UNS_32 baud;          /* SCI Baud rate clock register */
    volatile UNS_32 cycles;        /* SCI Baud Cycles register */
    volatile UNS_32 chguard;       /* SCI Char-Char extra guard time */
    volatile UNS_32 blkguard;      /* SCI Block Guard Time register */
    volatile UNS_32 synccr;        /* SCI Sync/Async mux control reg */
    volatile UNS_32 syncdata;      /* SCI Sync Data register */
    volatile UNS_32 rawstat;       /* SCI Raw I/O & clock status reg */
    volatile UNS_32 iir_icr;       /* SCI Interrupt ID/Clear register */
    volatile UNS_32 control;       /* SCI Enable/Pre-Divide register */
} SCI_REGS_T;

/***********************************************************************
 * SCI data register defines
 **********************************************************************/ 

/* SCI data register data load macro */
#define SCI_DATA(n)                 _SBF(0, (n & 0xFF))
/* SCI data register parity error bit */
#define SCI_PARITY                  0x00000100

/***********************************************************************
 * SCI control 0 register defines
 **********************************************************************/ 

/* SCI control register 0 data and parity sense bit */
#define SCI_SENSE                   0x00000001
/* SCI control register 0 data bit order inverse bit */
#define SCI_ORDER                   0x00000002
/* SCI control register 0 transmit parity odd bit */
#define SCI_TXPARITY                0x00000004
/* SCI control register 0 transmit T0 protocol bit */
#define SCI_TXNAK                   0x00000008
/* SCI control register 0 receive parity odd bit */
#define SCI_RXPARITY                0x00000010
/* SCI control register 0 receive T0 protocol bit */
#define SCI_RXNAK                   0x00000020

/***********************************************************************
 * SCI control 1 register defines
 **********************************************************************/ 

/* SCI control register 1 answer to reset duration timer start bit */
#define SCI_ATRDEN                  0x00000001
/* SCI control register 1 block timeout timer start bit */
#define SCI_BLKEN                   0x00000002
/* SCI control register 1 transmit mode bit */
#define SCI_MODE                    0x00000004
/* SCI control register 1 clock Z1 open-drain bit */
#define SCI_CLKZ1                   0x00000008
/* SCI control register 1 block guard timer start bit */
#define SCI_BGTEN                   0x00000010
/* SCI control register 1 enable debounce bypass bit */
#define SCI_EXDBNCE                 0x00000020

/***********************************************************************
 * SCI control 2 register defines
 **********************************************************************/ 

/* SCI control register 2 activate smart card session bit */
#define SCI_STARTUP                 0x00000001
/* SCI control register 2 es-activate smart card session bit */
#define SCI_FINISH                  0x00000002
/* SCI control register 2 warm reset bit */
#define SCI_WRESET                  0x00000004

/***********************************************************************
 * SCI interrupt enable register defines
 **********************************************************************/ 

/* SCI Interrupt Enable register card inserted bit */
#define SCI_CARDINIE                0x00000001
/* SCI Interrupt Enable register card taken-out bit */
#define SCI_CARDOUTIE               0x00000002
/* SCI Interrupt Enable register card power-up bit */
#define SCI_CARDUPIE                0x00000004
/* SCI Interrupt Enable register card power-down bit */
#define SCI_CARDDNIE                0x00000008
/* SCI Interrupt Enable register transmit error bit */
#define SCI_TXERRIE                 0x00000010
/* SCI Interrupt Enable register answer to reset start timeout bit */
#define SCI_ATRSTOUTIE              0x00000020
/* SCI Interrupt Enable register answer to reset duration timeout bit */
#define SCI_ATRDTOUTIE              0x00000040
/* SCI Interrupt Enable register block timeout bit */
#define SCI_BLKTOIE                 0x00000080
/* SCI Interrupt Enable register character timeout bit */
#define SCI_CHTOUTIE                0x00000100
/* SCI Interrupt Enable register receive timeout bit */
#define SCI_RTOUTIE                 0x00000200
/* SCI Interrupt Enable register receive watermark bit */
#define SCI_RXWMARKIE               0x00000400
/* SCI Interrupt Enable register transmit watermark bit */
#define SCI_TXWMARKIE               0x00000800

/***********************************************************************
 * SCI retry limit register defines
 **********************************************************************/ 

/* SCI Retry limit register transmit count load macro */
#define SCI_TXRETRY(n)              _SBF(0, (n & 0x7))
/* SCI Retry limit register receive count load macro */
#define SCI_RXRETRY(n)              _SBF(3, (n & 0x7))

/***********************************************************************
 * SCI FIFO watermark register defines
 **********************************************************************/ 

/* SCI FIFO Watermark register receive watermark load macro */
#define SCI_RXWMARK(n)              _SBF(0, (n & 0xF))
/* SCI FIFO Watermark register transmit watermark load macro */
#define SCI_TXWMARK(n)              _SBF(4, (n & 0xF))

/***********************************************************************
 * SCI TX FIFO count register defines
 **********************************************************************/ 

/* SCI TX FIFO Count register transmit FIFO count load macro */
#define SCI_TXCOUNT(n)              _SBF(0, (n & 0x1F))

/***********************************************************************
 * SCI RX FIFO count register defines
 **********************************************************************/ 

/* SCI RX FIFO Count register transmit FIFO count load macro */
#define SCI_RXCOUNT(n)              _SBF(0, (n & 0x1F))

/***********************************************************************
 * SCI FIFO status register defines
 **********************************************************************/ 

/* SCI FIFO status register transmit FIFO full bit */
#define SCI_TXFF                    0x00000001
/* SCI FIFO status register transmit FIFO empty bit */
#define SCI_TXFE                    0x00000002
/* SCI FIFO status register receive FIFO full bit */
#define SCI_RXFF                    0x00000004
/* SCI FIFO status register receive FIFO empty bit */
#define SCI_RXFE                    0x00000008

/***********************************************************************
 * SCI Read timeout register defines
 **********************************************************************/ 

/* SCI Read Timeout register load macro */
#define SCI_RXTIME(n)               _SBF(0, (n & 0xFFFF))

/***********************************************************************
 * SCI status register defines
 **********************************************************************/ 

/* SCI status register power enabled bit */
#define SCI_POWER                   0x00000001
/* SCI status register reset bit */
#define SCI_CRESET                  0x00000002
/* SCI status register smart clock enabled bit */
#define SCI_CLKEN                   0x00000004
/* SCI status register data enabled bit */
#define SCI_DATAEN                  0x00000008
/* SCI status register clock output enabled bit */
#define SCI_CLKOUTEN                0x00000010
/* SCI status register clock enabled bit */
#define SCI_CLKENB                  0x00000020
/* SCI status register CLKOUT bit */
#define SCI_CLKOUT                  0x00000040
/* SCI status register data output enable bit */
#define SCI_DATAOUTEN               0x00000080
/* SCI status register data enabled bit */
#define SCI_DATAENB                 0x00000100
/* SCI status register card present bit */
#define SCI_CARDPRESENT             0x00000200

/***********************************************************************
 * SCI Debounce Timer register defines
 **********************************************************************/ 

/* SCI Debounce Timer register load macro */
#define SCI_STABLE(n)               _SBF(0, (n & 0xFF))

/***********************************************************************
 * SCI Activation Time Event register defines
 **********************************************************************/ 

/* SCI Activation Time Event register load macro */
#define SCI_ATIME(n)                _SBF(0, (n & 0xFFFF))

/***********************************************************************
 * SCI Deactivation Time Event register defines
 **********************************************************************/ 

/* SCI Deactivation Time Event register load macro */
#define SCI_DTIME(n)                _SBF(0, (n & 0xFFFF))

/***********************************************************************
 * SCI Time to ATR reception register defines
 **********************************************************************/ 

/* SCI Time to ATR reception register load macro */
#define SCI_ATRSTIME(n)             _SBF(0, (n & 0xFFFF))

/***********************************************************************
 * SCI ATR Duration Timeout register defines
 **********************************************************************/ 

/* SCI ATR Duration Timeout register load macro */
#define SCI_ATRDTIME(n)             _SBF(0, (n & 0xFFFF))

/***********************************************************************
 * SCI Block to Block Timeout defines
 **********************************************************************/ 

/* SCI Block to Block Timeout register load macro */
#define SCI_BLKTIME(n)              _SBF(0, (n & 0xFFFF))

/***********************************************************************
 * SCI Char to Char Timeout register defines
 **********************************************************************/ 

/* SCI Char to Char Timeout register load macro */
#define SCI_CHTIME(n)               _SBF(0, (n & 0xFFFF))

/***********************************************************************
 * SCI Char Clock Divider register defines
 **********************************************************************/ 

/* SCI Char Clock Divider register load macro */
#define SCI_CLKDIV(n)               _SBF(0, (n & 0xFFFF))

/***********************************************************************
 * SCI Baud Rate Clock register defines
 **********************************************************************/ 

/* SCI Baud Rate Clock register load macro */
#define SCI_BAUD(n)                 _SBF(0, (n & 0xFFFF))

/***********************************************************************
 * SCI Baud Cycle register defines
 **********************************************************************/ 

/* SCI Baud Cycle register load macro */
#define SCI_BAUD_CYC(n)             _SBF(0, (n & 0xFFFF))

/***********************************************************************
 * SCI Char to Char Guard Time register defines
 **********************************************************************/ 

/* SCI Char to Char Guard Time register load macro */
#define SCI_CHGUARD(n)              _SBF(0, (n & 0xFF))

/***********************************************************************
 * SCI Block to Block Guard Time register defines
 **********************************************************************/ 

/* SCI Block to Block Guard Time register load macro */
#define SCI_BLKGUARD(n)             _SBF(0, (n & 0xFF))

/***********************************************************************
 * SCI Sync / Async Select register defines
 **********************************************************************/ 

/* SCI Sync / Async Select register sync data bit */
#define SCI_SELDATA                 0x00000001
/* SCI Sync / Async Select register sync clock bit */
#define SCI_SELCLK                  0x00000002

/***********************************************************************
 * SCI Sync Data Select register defines
 **********************************************************************/ 

/* SCI Sync Data Select register write data select bit */
#define SCI_WDATA                   0x00000001
/* SCI Sync Data Select register write clock select bit */
#define SCI_WCLK                    0x00000002
/* SCI Sync Data Select register write data enable select bit */
#define SCI_WDATAEN                 0x00000004
/* SCI Sync Data Select register write clock enable select bit */
#define SCI_WCLKEN                  0x00000008

/***********************************************************************
 * SCI Raw Clock Status register defines
 **********************************************************************/ 

/* SCI Raw Clock Status register SCIO signal value bit */
#define SCI_RDATA                   0x00000001
/* SCI Raw Clock Status register SCCLK signal value bit */
#define SCI_RCLK                    0x00000002

/***********************************************************************
 * SCI Interrupt Status register defines
 **********************************************************************/ 

/* SCI Interrupt Status registers card inserted bit */
#define SCI_CARDININTR              0x00000001
/* SCI Interrupt Status registers card taken out bit */
#define SCI_CARDOUTINTR             0x00000002
/* SCI Interrupt Status registers card activated bit */
#define SCI_CARDUPINTR              0x00000004
/* SCI Interrupt Status registers card de-activated bit */
#define SCI_CARDDNINTR              0x00000008
/* SCI Interrupt Status registers transmit error bit */
#define SCI_TXERRINTR               0x00000010
/* SCI Interrupt Status registers answer to reset start timeout bit */
#define SCI_ATRSTOUTINTR            0x00000020
/* SCI Interrupt Status registers answer to reset dur timeout bit */
#define SCI_ATRDTOUTINTR            0x00000040
/* SCI Interrupt Status registers block timeout timeout bit */
#define SCI_BLKTOUTINTR             0x00000080
/* SCI Interrupt Status registers character timeout timeout bit */
#define SCI_CHTOUTINTR              0x00000100
/* SCI Interrupt Status registers read timeout timeout bit */
#define SCI_RTOUTINTR               0x00000200
/* SCI Interrupt Status registers receive watermark bit */
#define SCI_RXWMARKINTR             0x00000400
/* SCI Interrupt Status registers transmit watermark bit */
#define SCI_TXWMARKINTR             0x00000800

/***********************************************************************
 * SCI Interrupt Status register defines
 **********************************************************************/ 

/* SCI Interrupt Status registers all interrupt bits */
#define SCI_ALLINTS                 0x00000FFF

/***********************************************************************
 * SCI Control register register defines
 **********************************************************************/ 

/* SCI Control register smart card interface enable bit */
#define SCI_EN                      0x00000001
/* SCI Control register pre-divisor is 2 enable bit */
#define SCI_PREDIV                  0x00000002
/* SCI Control register GPIO B5 pin is SCI VCC enable bit */
#define SCI_MUX_VCCEN               0x00000010
/* SCI Control register GPIO D6 pin is SCI DETECT enable bit */
#define SCI_MUX_DETECT              0x00000020

/* Macro pointing to WDT registers */
#define SCI ((SCI_REGS_T *)(SCI_BASE))

#endif /* LH7A404_SCI_H */

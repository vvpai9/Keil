/***********************************************************************
 * $Id:: lh79524_eth.h 27 2007-08-31 19:35:06Z kevinw                  $
*
* Project: LH79524 headers
*
* Description:
*      This file contains the structure definitions and manifest
*      constants for LH79524 component:
*          Ethernet MAC
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

#ifndef LH79524_ETH_H
#define LH79524_ETH_H

/***********************************************************************
* Ethernet MAC Module Register Structure
**********************************************************************/
#ifndef __ASSEMBLY__
/* The Address organisation for the MAC device.  All addresses are split into
* two 32-bit register fields.  The first one (bottom) is the lower 32-bits of
* the address and the other field are the high order bits - this may be 16-bits
* in the case of MAC addresses, or 32-bits for the hash address.
* In terms of memory storage, the first item (bottom) is assumed to be at a
* lower address location than 'top'. i.e. top should be at address location of
* 'bottom' + 4 bytes.
*/
typedef struct {
  UNS_32  bottom;     /* Lower 32-bits of address. */
  UNS_32  top;        /* Upper 32-bits of address. */
} MAC_ADDR_T;


/* The set of statistics registers implemented in the LH79524 MAC.
* The statistics registers implemented are a subset of all the statistics
* available, but contains all the compulsory ones.
* For full descriptions on the registers, refer to the LH79524 MAC programmers
* guide or the IEEE 802.3 specifications.
*/
typedef struct {
  UNS_32  pause_rx;           /* Number of pause frames received. */
  UNS_32  frames_tx;          /* Number of frames transmitted OK */
  UNS_32  single_col;         /* Number of single collision frames */
  UNS_32  multi_col;          /* Number of multi collision frames */
  UNS_32  frames_rx;          /* Number of frames received successfully */
  UNS_32  fcs_errors;         /* Number of frames received with crc errors */
  UNS_32  align_errors;       /* Frames received without integer no. bytes */
  UNS_32  def_tx;             /* Frames deferred due to crs */
  UNS_32  late_col;           /* Collisions occuring after slot time */
  UNS_32  excess_col;         /* Number of excessive collision frames. */
  UNS_32  tx_urun;            /* Transmit underrun errors due to DMA */
  UNS_32  crs_errors;         /* Errors caused by crs not being asserted. */
  UNS_32  rx_res_errors;      /* Number of times buffers ran out during rx */
  UNS_32  rx_orun;            /* Receive overrun errors due to DMA */
  UNS_32  rx_symbol_errors;   /* Number of times rx_er asserted during rx */
  UNS_32  excess_length;      /* Number of excessive length frames rx */
  UNS_32  jabbers;            /* Excessive length + crc or align errors. */
  UNS_32  usize_frames;       /* Frames received less than min of 64 bytes */
  UNS_32  sqe_errors;         /* Number of times col was not asserted */
  UNS_32  length_check_errors;/* Number of frames with incorrect length */
  UNS_32  pause_tx;           /* Number of pause frames transmitted. */
  
} MAC_STATS_T;


/* This is the memory map for the LH79524 Enhanced MAC device.
* For full descriptions on the registers, refer to the LH79524 MAC programmers
* guide or the IEEE 802.3 specifications.
*/
typedef struct {
  volatile UNS_32  net_control;      /* Network control 0x00 */
  volatile UNS_32  net_config;       /* Network config 0x04 */
  const volatile UNS_32  net_status; /* Network status, RO, 0x08 */
  const volatile UNS_32  rsvd0;      /* reserved 0x0C*/
  const volatile UNS_32  rsvd1;      /* reserved 0x10*/
  volatile UNS_32  tx_status;        /* Transmit status 0x14 */
  volatile UNS_32  rx_qptr;          /* Receive queue pointer 0x18 */
  volatile UNS_32  tx_qptr;          /* Transmit queue pointer 0x1C */
  volatile UNS_32  rx_status;        /* Receive status 0x20 */
  volatile UNS_32  irq_status;       /* Interrupt status 0x24 */
  volatile UNS_32  irq_enable;       /* Interrupt enable 0x28 */
  volatile UNS_32  irq_disable;      /* Interrupt disable 0x2C */
  const volatile UNS_32 irq_mask;    /* Interrupt mask, RO, 0x30 */
  volatile UNS_32  phy_man;          /* PHY management 0x34 */
  const volatile UNS_32  pause_time; /* Pause time register 0x38 */
  volatile MAC_STATS_T stats;        /* MAC statistics 0x3C - 0x8C */
  volatile MAC_ADDR_T hash_addr;     /* Hash address 0x90 - 0x94 */
  volatile MAC_ADDR_T spec_addr_1;   /* Specific address 1. 0x98 - */
  volatile MAC_ADDR_T spec_addr_2;   /* Specific address 2. */
  volatile MAC_ADDR_T spec_addr_3;   /* Specific address 3. */
  volatile MAC_ADDR_T spec_addr_4;   /* Specific address 4. - 0xB4 */
  volatile UNS_32  id_check;         /* Type ID check 0xB8 */
  volatile UNS_32  tx_pause_quant;   /* Transmit pause quantum. 0xBC*/
  volatile UNS_32  user_io;          /* User IO register, 0xC0 */
  /* 0xC4 to 0xF8 reserved not listed to save */
  /* space, Rev_id in 0xFC, not listed. */
} ETHERNET_REGS_T, *PETHERNET_REGS_T;

/* Define the structure for each queue element in the receive buffers descriptor
* queue list.
* These are the structures that hold information on where the storage buffer
* for received frames are held and also contain status information after a
* frame has been successfully received.
* The rx_qptr register in the MAC_REG structure points to the first of these
* buffer descriptors, the complete list of buffer descriptors specify all the
* information required for the MAC to store incoming frames at the appropriate
* location in memory.
* The structure consists of two 32-bit registers, the first - word0 contains a
* 32-bit word aligned address pointing to the address of the buffer.
* The lower two bits make up the wrap bit indicating the last descriptor and
* the ownership bit to indicate it has been used by the MAC.
* The following register - word1, contains status information regarding why the
* frame was received (the filter match condition) as well as other useful info.
* Both registers have been declared so that they can be accessed as a 32-bit
* value via their 'reg' field, or access each individual bit using the 'bits'
* field.
*/
typedef struct {
  volatile UNS_32 word0;
  volatile UNS_32 word1; /* Will only be updated by MAC */
} RX_BUFF_T;             /* Receive Buffer Queue Element */


/* Define the structure for each queue element in the transmit buffers descriptor
* queue list.
* These are the structures that hold information on where the storage buffer
* for frames to be transmitted are held and also contain status information on
* whether the frame has been successfully transmitted or indicate why not.
* The tx_qptr register in the MAC_REG structure points to the first of these
* buffer descriptors, the complete list of buffer descriptors specify all the
* information required for the MAC to transmit frames in sequence, starting
* with the first descriptor.
* The structure consists of two 32-bit registers, the first - word0 contains a
* 32-bit address pointing to the location of the transmit data.
* The following register - word1, consists of various information to control
* the MAC transmit process.  After transmit, this is updated with status
* information, whether the frame was transmitted OK or why it had failed.
* 'word1' has been declared so that it can be accessed as a 32-bit value via
* its 'reg' field, or can access each individual bit using the 'bits' field.
*/
typedef struct {
  volatile UNS_32  word0; /* 32-bit transmit buffer address */
  volatile UNS_32  word1;
} TX_BUFF_T;              /* Transmit Buffer Queue Element */

#endif /*__ASSEMBLY__ */

/* Define some memory offsets for easier direct access to memory map. */
#define ETH_NET_CONTROL_OFFSET         (0x00)
#define ETH_NET_CONFIG_OFFSET          (0x04)
#define ETH_NET_STATUS_OFFSET          (0x08)
#define ETH_TX_STATUS_OFFSET           (0x14)
#define ETH_RX_QPTR_OFFSET             (0x18)
#define ETH_TX_QPTR_OFFSET             (0x1C)
#define ETH_RX_STATUS_OFFSET           (0x20)
#define ETH_IRQ_STATUS_OFFSET          (0x24)
#define ETH_IRQ_ENABLE_OFFSET          (0x28)
#define ETH_IRQ_DISABLE_OFFSET         (0x2C)
#define ETH_IRQ_MASK_OFFSET            (0x30)
#define ETH_PHY_MAN_OFFSET             (0x34)
#define ETH_PAUSE_TIME_OFFSET          (0x38)
#define ETH_STATS_PAUSE_RX_OFFSET      (0x3C)
#define ETH_STATS_FRAMES_TX_OFFSET     (0x40)
#define ETH_STATS_SINGLE_COL_OFFSET    (0x44)
#define ETH_STATS_MULTI_COL_OFFSET     (0x48)
#define ETH_STATS_FRAMES_RX_OFFSET     (0x4C)
#define ETH_STATS_FCS_ERRORS_OFFSET    (0x50)
#define ETH_STATS_ALIGN_ERRORS_OFFSET  (0x54)
#define ETH_STATS_DEF_TX_OFFSET        (0x58)
#define ETH_STATS_LATE_COL_OFFSET      (0x5C)
#define ETH_STATS_EXCESS_COL_OFFSET    (0x60)
#define ETH_STATS_TX_URUN_OFFSET       (0x64)
#define ETH_STATS_CRS_ERRORS_OFFSET    (0x68)
#define ETH_STATS_RX_RES_ERR_OFFSET    (0x6C)
#define ETH_STATS_RX_ORUN_OFFSET       (0x70)
#define ETH_STATS_RX_SYM_ERR_OFFSET    (0x74)
#define ETH_STATS_EXCESS_LEN_OFFSET    (0x78)
#define ETH_STATS_JABBERS_OFFSET       (0x7C)
#define ETH_STATS_USIZE_FRAMES_OFFSET  (0x80)
#define ETH_STATS_SQE_ERRORS_OFFSET    (0x84)
#define ETH_STATS_LENGTH_ERRORS_OFFSET (0x88)
#define ETH_STATS_PAUSE_TX_OFFSET      (0x8C)
#define ETH_HASH_BOT_OFFSET            (0x90)
#define ETH_HASH_TOP_OFFSET            (0x94)
#define ETH_SPADDR1_BOT_OFFSET         (0x98)
#define ETH_SPADDR1_TOP_OFFSET         (0x9C)
#define ETH_SPADDR2_BOT_OFFSET         (0xA0)
#define ETH_SPADDR2_TOP_OFFSET         (0xA4)
#define ETH_SPADDR3_BOT_OFFSET         (0xA8)
#define ETH_SPADDR3_TOP_OFFSET         (0xAC)
#define ETH_SPADDR4_BOT_OFFSET         (0xB0)
#define ETH_SPADDR4_TOP_OFFSET         (0xB4)
#define ETH_ID_CHECK_OFFSET            (0xB8)
#define ETH_TX_PAUSE_QUANT_OFFSET      (0xBC)
#define ETH_USER_IO_OFFSET             (0xC0)
#define ETH_REV_ID_OFFSET              (0xFC)
#define ETH_REG_TOP_OFFSET             (0xFC)


/* Define some bit positions for registers. */

/* Bit positions for network control register */
#define ETH_CTL_TX_ZEROQ        _BIT(12)     /* Transmit Zero Quantum Pause Frame */
#define ETH_CTL_TX_PFRAME       _BIT(11)     /* Transmit a pause frame */
#define ETH_CTL_TX_HALT         _BIT(10)     /* Halt transmission after current frame */
#define ETH_CTL_TX_START        _BIT(9)      /* Start tx (tx_go) */
#define ETH_CTL_NET_BP          _BIT(8)      /* Enable back pressure i.e. force cols */
#define ETH_CTL_STATS_WR_EN     _BIT(7)      /* Enable writing to statistic registers */
#define ETH_CTL_STATS_INC       _BIT(6)      /* Increment statistic registers */
#define ETH_CTL_STATS_CLR       _BIT(5)      /* Clear statistic registers */
#define ETH_CTL_MDIO_EN         _BIT(4)      /* Enable MDIO port */
#define ETH_CTL_TX_EN           _BIT(3)      /* Enable transmit circuits */
#define ETH_CTL_RX_EN           _BIT(2)      /* Enable receive circuits */
#define ETH_CTL_LB_MAC          _BIT(1)      /* Perform local loopback at MAC */

/* Bit positions for network configuration register */
#define ETH_CFG_RX_IGNORE_FCS    _BIT(19)     /* Ignore FCS errors. */
/* Enable frames to be received in half-duplex mode while transmitting*/
#define ETH_CFG_RX_ENFRM        _BIT(18)     
#define ETH_CFG_RX_NO_FCS       _BIT(17)     /* Discard FCS from received frames. */
#define ETH_CFG_RX_LEN_CHK      _BIT(16)     /* Receive length check. */
#define ETH_CFG_RX_OFFSET_BASE  14          /* Position of LSB for rx buffer offsets. */
#define ETH_CFG_RX_OFFSET0      _SBF(14,0x0)         /* RX offset bit 0. */
#define ETH_CFG_RX_OFFSET1      _SBF(14,0x1)   /* RX offset bit 1. */
#define ETH_CFG_RX_OFFSET2      _SBF(14,0x2)   /* RX offset bit 1. */
#define ETH_CFG_RX_OFFSET3      _SBF(14,0x3)   /* RX offset bit 1. */
#define ETH_CFG_RX_PAUSE_EN     _BIT(13)     /* Enable pause reception */
#define ETH_CFG_RETRY_TEST      _BIT(12)     /* Retry test for speeding up debug */
#define ETH_CFG_MDC_DIV8        _SBF(10,0x00)/* MDC = HCLK/8, */
#define ETH_CFG_MDC_DIV16       _SBF(10,0x01)/* MDC = HCLK/16, */
#define ETH_CFG_MDC_DIV32       _SBF(10,0x02)/* MDC = HCLK/32, */
#define ETH_CFG_FRAME_1536      _BIT(8)      /* Enable reception of 1536 byte frames */
#define ETH_CFG_UNICAST_EN      _BIT(7)      /* Receive unicast hash frames */
#define ETH_CFG_MULTICAST_EN    _BIT(6)      /* Receive multicast hash frames */
#define ETH_CFG_NO_BROADCAST    _BIT(5)      /* Do not receive broadcast frames */
#define ETH_CFG_COPY_ALL        _BIT(4)      /* Copy all frames */
#define ETH_CFG_JUMBOFRM_EN     _BIT(3)      /* Enable acceptance of jumbo frames */
#define ETH_CFG_BIT_RATE        _BIT(2)      /* Enable bit rate mode */
#define ETH_CFG_FULL_DUPLEX     _BIT(1)      /* Enable full duplex */
#define ETH_CFG_SPEED_100       _BIT(0)      /* Set to 100Mb mode */

/* Bit positions for network status register */
#define ETH_NETSTAT_PHY_IDLE        _BIT(2)      /* PHY management is idle */
#define ETH_NETSTAT_MDIO_IN         _BIT(1)      /* Status of mdio_in pin */

/* Bit positions for transmit status register */
#define ETH_TXSTAT_URUN         _BIT(6)      /* Transmit underrun occurred */
#define ETH_TXSTAT_COMPLETE     _BIT(5)      /* Transmit completed OK */
#define ETH_TXSTAT_BUF_EXH      _BIT(4)      /* Transmit buffers exhausted mid frame */
#define ETH_TXSTAT_GO           _BIT(3)      /* Status of tx_go internal variable */
#define ETH_TXSTAT_RETRY_EXC    _BIT(2)      /* Retry limit exceeded */
#define ETH_TXSTAT_COL          _BIT(1)      /* Collision occurred during frame tx */
#define ETH_TXSTAT_USED         _BIT(0)      /* Used bit read in tx buffer */

/* Bit positions for receive status register */
#define ETH_RXSTAT_ORUN         _BIT(2)      /* Receive overrun occurred */
#define ETH_RXSTAT_DONE         _BIT(1)      /* Frame successfully received */
#define ETH_RXSTAT_BUF_USED     _BIT(0)      /* Receive buffer used bit read */

/* Bit positions for interrupts */
#define ETH_IRQ_PAUSE_0     _BIT(13)     /* Pause time has reached zero */
#define ETH_IRQ_PAUSE_RX    _BIT(12)     /* Pause frame received */
#define ETH_IRQ_HRESP       _BIT(11)     /* hresp not ok */
#define ETH_IRQ_RX_ORUN     _BIT(10)     /* Receive overrun occurred */
#define ETH_IRQ_LINK        _BIT(9)      /* Status of link pin changed */
#define ETH_IRQ_TX_DONE     _BIT(7)      /* Frame transmitted ok */
#define ETH_IRQ_TX_ERROR    _BIT(6)      /* Transmit error occurred or no buffers */
#define ETH_IRQ_RETRY_EXC   _BIT(5)      /* Retry limit exceeded */
#define ETH_IRQ_TX_URUN     _BIT(4)      /* Transmit underrun occurred */
#define ETH_IRQ_TX_USED     _BIT(3)      /* Tx buffer used bit read */
#define ETH_IRQ_RX_USED     _BIT(2)      /* Rx buffer used bit read */
#define ETH_IRQ_RX_DONE     _BIT(1)      /* Frame received ok */
#define ETH_IRQ_MAN_DONE    _BIT(0)      /* PHY management operation complete */
#define ETH_IRQ_ALL         (_BITMASK(14) & ~_BIT(8))/* Everything! */

/* Bit positions for PHY maintianece register */
#define ETH_PHYMAINT_STARTFRM   _SBF(30,0x01)      
#define ETH_PHYMAINT_OPER_WRITE _SBF(28,0x01) 
#define ETH_PHYMAINT_OPER_READ  _SBF(28,0x02) 
#define ETH_PHYMAINT_PHYADDR(n) _SBF(23,((n) & 0x1F))      
#define ETH_PHYMAINT_REGADDR(n) _SBF(18,((n) & 0x1F))
#define ETH_PHYMAINT_REQ_FIELD  _SBF(16,0x02)

/* Transmit buffer descriptor status words bit positions. */
#define ETH_TXBUF_USED       _BIT(31)   /* Used bit. */
#define ETH_TXBUF_WRAP       _BIT(30)   /* Wrap bit */
#define ETH_TXBUF_RETRY_EXC  _BIT(29)   /* Retry limit exceeded. */
#define ETH_TXBUF_URUN       _BIT(28)   /* Transmit underrun occurred. */
#define ETH_TXBUF_BUF_EXH    _BIT(27)   /* Buffers exhausted mid frame. */
#define ETH_TXBUF_NO_CRC     _BIT(16)   /* No CRC */
#define ETH_TXBUF_LAST_BUF   _BIT(15)   /* Last buffer */
#define ETH_TXBUF_LEN_MASK   _BITMASK(11)/* Mask for length field */
#define ETH_TXBUF_DUMMY      (0x800087ff)/* Dummy value to check for free buffer */

/* Receive buffer descriptor status words bit positions. */
#define ETH_RXBUF_WRAP        _BIT(1)     /* Wrap bit, the last descriptor*/
#define ETH_RXBUF_OWNERSHIP   _BIT(0)     /* Ownership bit, has been used by MAC*/
#define ETH_RXBUF_ADDR_MASK   ~(0x03)     /* Buffer addres mask*/

#define ETH_RXBUF_BRDCAST    _BIT(31)     /* Broadcast Address Detected */
#define ETH_RXBUF_MULTICAST  _BIT(30)     /* Multicast Hash Match */
#define ETH_RXBUF_UNICAST    _BIT(29)     /* Unicast Hash Match */
#define ETH_RXBUF_EXTADDR    _BIT(28)     /* External Address Match */
#define ETH_RXBUF_SPADDR1    _BIT(26)     /* Specific Address Register 1 Match */
#define ETH_RXBUF_SPADDR2    _BIT(25)     /* Specific Address Register 2 Match */
#define ETH_RXBUF_SPADDR3    _BIT(24)     /* Specific Address Register 3 Match */
#define ETH_RXBUF_SPADDR4    _BIT(23)     /* Specific Address Register 4 Match*/
#define ETH_RXBUF_TYPEID     _BIT(22)     /* Type ID Match*/
#define ETH_RXBUF_VLAN       _BIT(21)     /* VLAN tag detected */
#define ETH_RXBUF_PRIOR      _BIT(20)     /* Priority Tag Detected */
#define ETH_RXBUF_CFI        _BIT(16)     /* Concatenation Format Indicator */
#define ETH_RXBUF_EOF        _BIT(15)     /* Start of frame. */
#define ETH_RXBUF_SOF        _BIT(14)     /* Start of frame. */
#define ETH_RXBUF_LEN_MASK   _BITMASK(11)     /* Mask for the length field. */

/* Revision ID Register */
#define MACB_REV_ID_MODEL_MASK   (0x000F0000)    /* Model ID */
#define MACB_REV_ID_MODEL_BASE   (16)            /* For Shifting */
#define MACB_REV_ID_REG_MODEL    (0x00010000)    /* MACB module ID */
#define MACB_REV_ID_REV_MASK     (0x0000FFFF)    /* Revision ID */



/* Specify the length of the IO space in bytes */
#define IO_PORT_LENGTH 0x100

/* Specify the default receive buffer size. */
#define RX_BUF_SIZE 128


/* Specify size of descriptor queues for software that uses it.. */
#define RXBUF_LENGTH 128
#define TXBUF_LENGTH 128

#endif /*LH79524_ETH_H*/

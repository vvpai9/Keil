/* ----------------------------------------------------------------------
 * Copyright (C) 2013 ARM Limited. All rights reserved.
 *  
 * $Date:        12. September 2013
 * $Revision:    V5.01
 *  
 * Driver:       Driver_ETH_MACn (default: Driver_ETH_MAC0),
                 Driver_ETH_PHYn (default: Driver_ETH_PHY0)
 * Project:      Ethernet Media Access (MAC) Driver and
                 Ethernet Physical Layer Transceiver (PHY) Driver
                 for KSZ8851SNL
 * ---------------------------------------------------------------------- 
 * Use the following configuration settings in the middleware component
 * to connect to this driver.
 * 
 *   Configuration Setting                     Value
 *   ---------------------                     -----
 *   Connect to hardware via Driver_ETH_MAC# = n (default: 0)
 * -------------------------------------------------------------------- */

/* History:
 *  Version 5.01
 *    Based on API V1.10 (namespace prefix ARM_ added)
 *  Version 5.00
 *    Initial release
 */

#include "cmsis_os.h"

#include "ETH_KSZ8851SNL.h"

#include "Driver_SPI.h"
#include "Driver_ETH_MAC.h"
#include "Driver_ETH_PHY.h"

#include "RTE_Device.h"
#include "RTE_Components.h"

#define ARM_ETH_MAC_DRV_VERSION ARM_DRV_VERSION_MAJOR_MINOR(5,01) /* driver version */
#define ARM_ETH_PHY_DRV_VERSION ARM_DRV_VERSION_MAJOR_MINOR(5,01) /* driver version */

/* Default ethernet driver number */
#ifndef ETH_NUM
#define ETH_NUM                 0
#endif

/* SPI port number definition */
#ifndef EMAC_SPI_PORT
#define EMAC_SPI_PORT           0
#endif

/* Receive/transmit Checksum offload enable */
#ifndef EMAC_CHECKSUM_OFFLOAD
#define EMAC_CHECKSUM_OFFLOAD   1
#endif

/* SPI bus speed */
#ifndef EMAC_SPI_BUS_SPEED
#define EMAC_SPI_BUS_SPEED      10000000
#endif

#define _SPI_Driver_(n)     Driver_SPI##n
#define  SPI_Driver_(n)    _SPI_Driver_(n)
extern ARM_DRIVER_SPI       SPI_Driver_(EMAC_SPI_PORT);
#define ptrSPI             (&SPI_Driver_(EMAC_SPI_PORT))

/* Timeouts */
#define TX_TIMEOUT          5000        /* Packet Transmit timeout in us */


/* Driver Version */
static const ARM_DRV_VERSION MAC_DriverVersion = {
  ARM_ETH_MAC_API_VERSION,
  ARM_ETH_MAC_DRV_VERSION
};

/* Driver Capabilities */
static const ARM_ETH_MAC_CAPABILITIES MAC_DriverCapabilities = {
  (EMAC_CHECKSUM_OFFLOAD) ? 1 : 0,      /* rx_checksum_offload_ip   */
  (EMAC_CHECKSUM_OFFLOAD) ? 1 : 0,      /* rx_checksum_offload_udp  */
  (EMAC_CHECKSUM_OFFLOAD) ? 1 : 0,      /* rx_checksum_offload_tcp  */
  (EMAC_CHECKSUM_OFFLOAD) ? 1 : 0,      /* rx_checksum_offload_icmp */
  (EMAC_CHECKSUM_OFFLOAD) ? 1 : 0,      /* tx_checksum_offload_ip   */
  (EMAC_CHECKSUM_OFFLOAD) ? 1 : 0,      /* tx_checksum_offload_udp  */
  (EMAC_CHECKSUM_OFFLOAD) ? 1 : 0,      /* tx_checksum_offload_tcp  */
  (EMAC_CHECKSUM_OFFLOAD) ? 1 : 0,      /* tx_checksum_offload_icmp */
  0,                                    /* media_interface          */
  0,                                    /* mac_address              */
  0,                                    /* event_rx_frame           */
  0                                     /* reserved                 */
};

/* Ethernet MAC local variables */
static uint16_t reg_txcr;
static uint16_t reg_rxcr1;
static uint8_t  rx_count;

/* EMAC Register Read/Write function prototypes */
static ARM_ETH_STATUS reg_rd (uint8_t reg_addr, uint16_t *data);
static ARM_ETH_STATUS reg_wr (uint8_t reg_addr, uint16_t  data);

/* SPI event callback handler */
void SPI_Event_Cb (ARM_SPI_EVENT event) {
}

/**
  \fn          ARM_DRV_VERSION ETH_MAC_GetVersion (void)
  \brief       Get driver version.
  \return      \ref ARM_DRV_VERSION
*/
static ARM_DRV_VERSION MAC_GetVersion (void) {
  return MAC_DriverVersion;
}


/**
  \fn          ARM_ETH_MAC_CAPABILITIES ETH_MAC_GetCapabilities (void)
  \brief       Get driver capabilities.
  \return      \ref ARM_ETH_MAC_CAPABILITIES
*/
static ARM_ETH_MAC_CAPABILITIES MAC_GetCapabilities (void) {
  return MAC_DriverCapabilities;
}

/**
  \fn          ARM_ETH_STATUS ETH_MAC_Initialize (ARM_ETH_MAC_SignalEvent_t cb_event,
                                                  ARM_ETH_MAC_ADDR         *mac_address)
  \brief       Initialize Ethernet MAC Device.
  \param[in]   cb_event       Pointer to \ref ARM_ETH_MAC_SignalEvent
  \param[in,out] mac_address  Pointer to MAC address
  \return      \ref ARM_ETH_STATUS
*/
static ARM_ETH_STATUS MAC_Initialize (ARM_ETH_MAC_SignalEvent_t cb_event,
                                      ARM_ETH_MAC_ADDR         *mac_address) {
  bool     err;
  uint16_t val;

  if (mac_address == NULL) {
    return ARM_ETH_ERROR;
  }

  err = true;
  /* Initialize SPI interface */
  if (ptrSPI->Initialize (SPI_Event_Cb) == ARM_SPI_OK) {
    if (ptrSPI->PowerControl (ARM_POWER_FULL) == ARM_SPI_OK) {
      if (ptrSPI->SlaveSelect (ARM_SPI_SS_INACTIVE) == ARM_SPI_OK) {
        if (ptrSPI->Configure (ARM_SPI_CPOL0_CPHA0, ARM_SPI_MSB_LSB) == ARM_SPI_OK) {
          ptrSPI->BusSpeed (EMAC_SPI_BUS_SPEED);
          err = false;
        }
      }
    }
  }

  if (err) {
    /* SPI Initialization failed */
    return ARM_ETH_ERROR;
  }

  /* Check Device Identification. */
  val = 0;
  reg_rd(REG_CIDER, &val);
  if ((val & 0xFFF0) != PHY_ID) {
    /* Wrong PHY device. */
    return ARM_ETH_ERROR_UNSUPPORTED;
  }

  /* Reset device */
  err  = (reg_wr(REG_GRR, REG_GRR_GSR) != ARM_ETH_OK);
  err |= (reg_wr(REG_GRR, 0)           != ARM_ETH_OK);
  osDelay(10);

  if (err) {
    /* Reset failed */
    return ARM_ETH_ERROR;
  }

  /* Write host MAC address */
  reg_wr(REG_MARL, (mac_address->b[4] << 8) | mac_address->b[5]);
  reg_wr(REG_MARM, (mac_address->b[2] << 8) | mac_address->b[3]);
  reg_wr(REG_MARH, (mac_address->b[0] << 8) | mac_address->b[1]);

  /* Enable Tx Frame Data Pointer Auto Increment */
  reg_wr (REG_TXFDPR, REG_TXFDPR_TXFPAI);

  /* Flush TX queue */
  reg_wr (REG_TXCR, REG_TXCR_FTXQ);

  /* Enable QMU transmit */
  reg_txcr  = REG_TXCR_TXCE | REG_TXCR_TXPE | REG_TXCR_TXFCE;
#if (EMAC_CHECKSUM_OFFLOAD)
  reg_txcr |= REG_TXCR_TCGIP | REG_TXCR_TCGTCP | REG_TXCR_TCGUDP | REG_TXCR_TCGICMP;
#endif
  reg_wr (REG_TXCR, reg_txcr);
  reg_wr (REG_TXQCR, REG_TXQCR_TXQMAM);

  /* Enable Rx Frame Data Pointer Auto Increment */
  reg_wr (REG_RXFDPR, REG_RXFDPR_RXFPAI);

  /* Configure Receive Frame Threshold for one frame */
  reg_wr (REG_RXFCTR, 1);

  /* Flush RX queue */
  reg_wr (REG_RXCR1, REG_RXCR1_FRXQ);

  /* Accept unicast and broadcast packets and enable QMU receive */
  reg_rxcr1  = REG_RXCR1_RXPAFMA | REG_RXCR1_RXMAFMA |
               REG_RXCR1_RXBE    | REG_RXCR1_RXUE    | REG_RXCR1_RXFCE;
#if (EMAC_CHECKSUM_OFFLOAD)
  reg_rxcr1 |= REG_RXCR1_RXIPFCC | REG_RXCR1_RXTCPFCC | REG_RXCR1_RXUDPFCC;
#endif
  reg_wr (REG_RXCR1, reg_rxcr1);

  val  = REG_RXCR2_IUFFP | REG_RXCR2_UDPLFE | REG_RXCR2_SRDBL_FRM;
#if (EMAC_CHECKSUM_OFFLOAD)
  val |= REG_RXCR2_RXICMPFCC;
#endif
  reg_wr (REG_RXCR2, val);

  /* Enable RX Frame Count Threshold and Auto-Dequeue */
  reg_wr (REG_RXQCR, REG_RXQCR_RXFCTE | REG_RXQCR_ADRFE);
  rx_count = 0;

  /* Enable receive interrupts */
  reg_wr (REG_IER, REG_IER_RXIE | REG_IER_RXOIE);

  /* Clear interrupt status */
  reg_wr (REG_ISR, 0xFFFF);

  return ARM_ETH_OK;
}

/**
  \fn          ARM_ETH_STATUS ETH_MAC_Uninitialize (void)
  \brief       De-initialize ETH_MAC Device.
  \return      \ref ARM_ETH_STATUS
*/
static ARM_ETH_STATUS MAC_Uninitialize (void) {

  /* Reset device */
  reg_wr(REG_GRR, REG_GRR_GSR);
  reg_wr(REG_GRR, 0);

  return ARM_ETH_OK;
}

/**
  \fn          ARM_ETH_STATUS ETH_MAC_PowerControl (ARM_POWER_STATE state)
  \brief       Control Ethernet MAC Device Power.
  \param[in]   state  Power state
  \return      \ref ARM_ETH_STATUS
*/
static ARM_ETH_STATUS MAC_PowerControl (ARM_POWER_STATE state) {

  switch (state) {
    case ARM_POWER_OFF:
      break;

    case ARM_POWER_LOW:
      return ARM_ETH_ERROR_UNSUPPORTED;

    case ARM_POWER_FULL:
      break;

    default:
      return ARM_ETH_ERROR_UNSUPPORTED;
  }

  return ARM_ETH_OK;
}

/**
  \fn          uint32_t CalculateCRC (uint8_t *data, uint32_t len)
  \brief       Calculate 32-bit Ethernet CRC value.
  \param[in]   data  Pointer to the buffer containing data
  \param[in]   len   Data buffer length in bytes
  \return      Calculated CRC value
*/
static uint32_t CalculateCRC (uint8_t *buf, uint32_t len) {
  uint32_t a,crc,byte;

  for (crc = 0xFFFFFFFF; len > 0; len--) {
    byte = *buf++;
    for (byte |= 0x100; byte > 0x001; byte >>= 1) {
      a = crc, crc <<= 1;
      if ((a ^ (byte << 31)) & 0x80000000) {
        crc ^= 0x04c11db7;
      }
    }
  }
  return (crc);
}

/**
  \fn          ARM_ETH_STATUS ETH_MAC_SetMulticastAddr (uint32_t          num_addr,
                                                        ARM_ETH_MAC_ADDR *ptr_addr)
  \brief       Configure Ethernet multicast address filtering.
  \param[in]   num_addr   Number of multicast addresses to configure
  \param[in]   ptr_addr   Pointer to multicast addresses
  \return      \ref ARM_ETH_STATUS
*/
static ARM_ETH_STATUS MAC_SetMulticastAddr (uint32_t num_addr, ARM_ETH_MAC_ADDR *ptr_addr) {
  uint16_t ht[4];
  uint32_t crc;

  if (num_addr == 0) {
    /* Disable multicast hash filtering */
    reg_rxcr1 |= REG_RXCR1_RXMAFMA;
    reg_rxcr1 &= ~REG_RXCR1_RXME;
    reg_wr (REG_RXCR1, reg_rxcr1);
    return ARM_ETH_OK;
  }

  /* Calculate 64-bit Hash table for MAC addresses */
  ht[0] = 0;
  ht[1] = 0;
  ht[2] = 0;
  ht[3] = 0;
  
  for ( ; num_addr; ptr_addr++, num_addr--) {
    crc = CalculateCRC (&ptr_addr->b[0], 6) >> 26;
    ht[crc >> 4] |= (1 << (crc & 0x0F));
  }
  reg_wr (REG_MAHTR0, ht[0]);
  reg_wr (REG_MAHTR1, ht[1]);
  reg_wr (REG_MAHTR2, ht[2]);
  reg_wr (REG_MAHTR3, ht[3]);

  /* Enable multicast hash filtering */
  reg_rxcr1 &= ~REG_RXCR1_RXMAFMA;
  reg_rxcr1 |=  REG_RXCR1_RXME;
  reg_wr (REG_RXCR1, reg_rxcr1);

  return ARM_ETH_OK;
}

/**
  \fn          ARM_ETH_STATUS ETH_MAC_SetMode (ARM_ETH_DUPLEX duplex, ARM_ETH_SPEED speed)
  \brief       Set the Ethernet MAC speed and duplex mode.
  \param[in]   duplex  \ref ARM_ETH_DUPLEX
  \param[in]   speed   \ref ARM_ETH_SPEED
  \return      \ref ARM_ETH_STATUS
*/
static ARM_ETH_STATUS MAC_SetMode (ARM_ETH_DUPLEX duplex, ARM_ETH_SPEED speed) {
  /* Not used in this driver */
  return (ARM_ETH_OK);
}

/**
  \fn          ARM_ETH_STATUS ETH_MAC_EnableTx (bool enable)
  \brief       Enable the Ethernet MAC transmit engine.
  \param[in]   enable  Action
               - \b true Enable
               - \b false Disable
  \return      \ref ARM_ETH_STATUS
*/
static ARM_ETH_STATUS MAC_EnableTx (bool enable) {

  if (enable) reg_txcr |=  REG_TXCR_TXE;
  else        reg_txcr &= ~REG_TXCR_TXE;
  return (reg_wr (REG_TXCR, reg_txcr));
}

/**
  \fn          ARM_ETH_STATUS ETH_MAC_EnableRx (bool enable)
  \brief       Enable the Ethernet MAC receive engine.
  \param[in]   enable  Action
               - \b true Enable
               - \b false Disable
  \return      \ref ARM_ETH_STATUS
*/
static ARM_ETH_STATUS MAC_EnableRx (bool enable) {

  if (enable) reg_rxcr1 |=  REG_RXCR1_RXE;
  else        reg_rxcr1 &= ~REG_RXCR1_RXE;
  return (reg_wr (REG_RXCR1, reg_rxcr1));
}

/**
  \fn          ARM_ETH_STATUS ETH_MAC_SendFrame (uint8_t *buf, uint32_t len)
  \brief       Send Ethernet frame.
  \param[in]   buf  Pointer to frame buffer with data to send
  \param[in]   len  Frame buffer length in bytes
  \return      \ref ARM_ETH_STATUS
*/
static ARM_ETH_STATUS MAC_SendFrame (uint8_t *buf, uint32_t len) {
  static uint8_t frameId;
  uint8_t        hdr[4];
  bool           err;
  uint32_t       tick;
  uint16_t       val;

  /* Wait until enough memory free in TX queue */
  tick = osKernelSysTick();
  do {
    val = 0;
    reg_rd (REG_TXMIR, &val);
    val &= 0x01FFF;
    if (val >= (len + 4)) {
      /* Enough size in TXQ for our frame */
      break;
    }
  } while ((osKernelSysTick() - tick) < osKernelSysTickMicroSec(TX_TIMEOUT));

  if (val < (len + 4)) {
    /* Timeout */
    return ARM_ETH_ERROR;
  }

  err = true;
  /* Disable interrupts */
  if (reg_wr (REG_IER, 0) == ARM_ETH_OK) {
    /* Set Start DMA Access bit in RXQCR */
    if (reg_rd (REG_RXQCR, &val) == ARM_ETH_OK) {
      if (reg_wr (REG_RXQCR, val | REG_RXQCR_SDA) == ARM_ETH_OK) {
        err = false;
      }
    }
  }
  if (err) {
    return ARM_ETH_ERROR;
  }

  /* Little/big endian invariant code */
  hdr[0] = frameId++ & 0x3F;
  hdr[1] = 0;
  hdr[2] = (uint8_t)len;
  hdr[3] = (uint8_t)(len >> 8);

  err = true;
  ptrSPI->SlaveSelect (ARM_SPI_SS_ACTIVE);
  /* Send TXQ FIFO Write command */
  if (ptrSPI->TransferByte (SPI_CMD_TXQ_FIFO_WRITE) == ARM_SPI_OK) {
    /* Send TX frame header */
    if (ptrSPI->SendData ((uint8_t *)&hdr, 4) == ARM_SPI_OK) {
      /* Send frame data, add dummy bytes to align data to 4 bytes */
      if (ptrSPI->SendData (buf, (len + 3) & ~3) == ARM_SPI_OK) {
        /* Frame sent to the TX queue */
        err = false;
      }
    }
  }
  ptrSPI->SlaveSelect (ARM_SPI_SS_INACTIVE);
  if (err) {
    return ARM_ETH_ERROR;
  }

  /* Clear Start DMA Access bit in RXQCR */
  reg_wr (REG_RXQCR, val);
  reg_wr (REG_TXQCR, REG_TXQCR_TXQMAM | REG_TXQCR_METFE);

  err = true;
  /* Wait until transmit done */
  tick = osKernelSysTick();
  do {
    if (reg_rd (REG_TXQCR, &val) == ARM_ETH_OK) {
      if (!(val & REG_TXQCR_METFE)) {
        /* Enqueue bit cleared, frame sent */
        err = false;
        break;
      }
    }
  }
  while ((osKernelSysTick() - tick) < osKernelSysTickMicroSec(TX_TIMEOUT));
  
  /* Enable interrupts */
  reg_wr (REG_IER, REG_IER_RXIE | REG_IER_RXOIE);

  return (err) ? ARM_ETH_ERROR : ARM_ETH_OK;
}

/**
  \fn          int32_t ETH_MAC_ReadFrame (uint8_t *buf, uint32_t len)
  \brief       Read data of received Ethernet frame.
  \param[in]   buf  Pointer to frame buffer for data to read into
  \param[in]   len  Frame buffer length in bytes
  \return      number of bytes read, error code if negative
*/
static int32_t MAC_ReadFrame (uint8_t *buf, uint32_t len) {
  uint32_t i;
  uint16_t reg_val;

  rx_count--;
  if (len == 0) {
    /* Release inconsistent frame from the RXQ */
    reg_rd (REG_RXQCR, &reg_val);
    reg_wr (REG_RXQCR, reg_val | REG_RXQCR_RRXEF);
    do {
      reg_rd (REG_RXQCR, &reg_val);
    } while (reg_val & REG_RXQCR_RRXEF);
    return 0;
  }

  /* Clear receive frame pointer */
  reg_wr (REG_RXFDPR, REG_RXFDPR_RXFPAI);

  /* Set Start DMA Access bit in RXQCR */
  reg_rd (REG_RXQCR, &reg_val);
  reg_wr (REG_RXQCR, reg_val | REG_RXQCR_SDA);

  ptrSPI->SlaveSelect (ARM_SPI_SS_ACTIVE);
  /* Send RXQ FIFO Read command */
  ptrSPI->TransferByte (SPI_CMD_RXQ_FIFO_READ);
    
  /* Read dummy bytes of frame header */
  ptrSPI->ReceiveData (buf, 8, 0xFF);

  /* Read received frame */
  ptrSPI->ReceiveData (buf, len, 0xFF);

  /* Read dummy bytes for alignment */
  for (i = ((len + 3) & ~3) - len; i; i--) {
    ptrSPI->TransferByte (0xFF);
  }
  ptrSPI->SlaveSelect (ARM_SPI_SS_INACTIVE);

  /* Clear Start DMA Access bit in RXQCR */
  reg_wr (REG_RXQCR, reg_val);

  return len;
}

/**
  \fn          int32_t ETH_MAC_GetRxFrameSize (void)
  \brief       Get size of received Ethernet frame.
  \return      number of bytes in received frame, error code if negative
*/
static int32_t MAC_GetRxFrameSize (void) {
  uint16_t reg_val;
  uint16_t err;

  if (rx_count == 0) {
    /* Read interrupt status */
    reg_rd (REG_ISR, &reg_val);
    if (!(reg_val & (REG_ISR_RXIS | REG_ISR_RXOIS))) {
      return (0);
    }
    /* Clear interrupt status */
    reg_wr (REG_ISR, reg_val);

    /* Read receive frame count */
    reg_rd (REG_RXFCTR, &reg_val);

    rx_count = reg_val >> 8;
    if (rx_count == 0) {
      /* Receive overrun, flush RXQ */
      reg_val = reg_rxcr1 & ~REG_RXCR1_RXE;
      reg_wr (REG_RXCR1, reg_val);
      reg_wr (REG_RXCR1, reg_val | REG_RXCR1_FRXQ);
      reg_wr (REG_RXCR1, reg_rxcr1);
      return (0);
    }
  }

  /* Check receive frame header status */
  reg_rd (REG_RXFHSR, &reg_val);

  /* Check if frame is valid */
  if (!(reg_val & REG_RXFHSR_RXFV)) {
    reg_rd (REG_RXFHBCR, &reg_val);
    return (0);
  }

  err  = REG_RXFHSR_RXMR | REG_RXFHSR_RXFTL | REG_RXFHSR_RXRF | REG_RXFHSR_RXCE;
#if (EMAC_CHECKSUM_OFFLOAD)
  err |= REG_RXFHSR_RXICMPFCS | REG_RXFHSR_RXIPFCS | REG_RXFHSR_RXTCPFCS | REG_RXFHSR_RXUDPFCS;
#endif
  if (reg_val & err) {
    /* Error, this frame is invalid */
    return (-1);
  }

  /* Read byte count (no CRC) */
  reg_rd (REG_RXFHBCR, &reg_val);
  return ((reg_val & 0x0FFF) - 4);
}

/**
  \fn          ARM_ETH_STATUS reg_rd (uint8_t reg_addr, uint16_t *data)
  \brief       Read Ethernet controller Register through SPI Interface.
  \param[in]   reg_addr  register address
  \param[out]  data      Pointer where the result is written to
  \return      \ref ARM_ETH_STATUS
  \note        This is a local function of the driver.
*/
static ARM_ETH_STATUS reg_rd (uint8_t reg_addr, uint16_t *data) {
  uint8_t        buf[2];
  ARM_ETH_STATUS stat = ARM_ETH_ERROR;

  buf[0]  = SPI_CMD_REGISTER_READ;
  if (reg_addr & 2) { buf[0] |= 0x3 << 4; }
  else              { buf[0] |= 0x3 << 2; }
  buf[0] |= (reg_addr >> 6);
  buf[1]  = (reg_addr << 2);

  if (ptrSPI->SlaveSelect(ARM_SPI_SS_ACTIVE) == ARM_SPI_OK) {
    if (ptrSPI->SendData (buf, 2) == ARM_SPI_OK) {
      if (ptrSPI->ReceiveData (buf, 2, 0xFF) == ARM_SPI_OK) {
        *data = ((uint16_t)buf[1] << 8) | buf[0];
        stat = ARM_ETH_OK;
      }
    }
  }
  if (ptrSPI->SlaveSelect(ARM_SPI_SS_INACTIVE) != ARM_SPI_OK) {
    stat = ARM_ETH_ERROR;
  }
  return (stat);
}

/**
  \fn          ARM_ETH_STATUS reg_wr (uint8_t reg_addr, uint16_t data)
  \brief       Write Ethernet PHY Register through Management Interface.
  \param[in]   reg_addr  register address
  \param[in]   data      16-bit data to write
  \return      \ref ARM_ETH_STATUS
  \note        This is a local function of the driver.
*/
static ARM_ETH_STATUS reg_wr (uint8_t reg_addr, uint16_t data) {
  uint8_t        buf[4];
  ARM_ETH_STATUS stat = ARM_ETH_ERROR;

  buf[0]  = SPI_CMD_REGISTER_WRITE;
  if (reg_addr & 2) { buf[0] |= 0x3 << 4; }
  else              { buf[0] |= 0x3 << 2; }
  buf[0] |= (reg_addr >> 6);
  buf[1]  = (reg_addr << 2);
  buf[2]  = (uint8_t)data;
  buf[3]  = (uint8_t)(data >> 8);

  if (ptrSPI->SlaveSelect(ARM_SPI_SS_ACTIVE) == ARM_SPI_OK) {
    if (ptrSPI->SendData (buf, 4) == ARM_SPI_OK) {
      stat = ARM_ETH_OK;
    }
  }
  if (ptrSPI->SlaveSelect(ARM_SPI_SS_INACTIVE) != ARM_SPI_OK) {
    stat = ARM_ETH_ERROR;
  }
  return (stat);
}


/* MAC Driver Control Block */
ARM_DRIVER_ETH_MAC ARM_Driver_ETH_MAC_(ETH_NUM) = {
  MAC_GetVersion,
  MAC_GetCapabilities,
  MAC_Initialize,
  MAC_Uninitialize,
  MAC_PowerControl,
  MAC_SetMulticastAddr,
  MAC_SetMode,
  MAC_EnableTx,
  MAC_EnableRx,
  MAC_SendFrame,
  MAC_ReadFrame,
  MAC_GetRxFrameSize,
  NULL,
  NULL
};


/* Driver Version */
static const ARM_DRV_VERSION PHY_DriverVersion = {
  ARM_ETH_PHY_API_VERSION,
  ARM_ETH_PHY_DRV_VERSION
};


/**
  \fn          ARM_DRV_VERSION ETH_PHY_GetVersion (void)
  \brief       Get driver version.
  \return      \ref ARM_DRV_VERSION
*/
static ARM_DRV_VERSION PHY_GetVersion (void) {
  return PHY_DriverVersion;
}


/**
  \fn          ARM_ETH_STATUS ETH_PHY_Initialize (ARM_ETH_PHY_Read_t  fn_read,
                                                  ARM_ETH_PHY_Write_t fn_write)
  \brief       Initialize Ethernet PHY Device.
  \param[in]   fn_read   Pointer to \ref ARM_ETH_PHY_Read
  \param[in]   fn_write  Pointer to \ref ARM_ETH_PHY_Write
  \return      \ref ARM_ETH_STATUS
*/
static ARM_ETH_STATUS PHY_Initialize (ARM_ETH_PHY_Read_t fn_read, ARM_ETH_PHY_Write_t fn_write) {
  return (ARM_ETH_OK);
}

/**
  \fn          ARM_ETH_STATUS ETH_PHY_Uninitialize (void)
  \brief       De-initialize Ethernet PHY Device.
  \return      \ref ARM_ETH_STATUS
*/
static ARM_ETH_STATUS PHY_Uninitialize (void) {
  return (ARM_ETH_OK);
}

/**
  \fn          ARM_ETH_STATUS ETH_PHY_PowerControl (ARM_POWER_STATE state)
  \brief       Control Ethernet PHY Device Power.
  \param[in]   state  Power state
  \return      \ref ARM_ETH_STATUS
*/
static ARM_ETH_STATUS PHY_PowerControl (ARM_POWER_STATE state) {
  ARM_ETH_STATUS stat;
  uint16_t       val;

  stat = reg_rd (REG_PMECR, &val);
  if (stat == ARM_ETH_OK) {
    switch (state) {
      case ARM_POWER_OFF:
        /* Select Power Saving Mode */
        val |= 0x3;
        break;
      case ARM_POWER_FULL:
        /* Select Normal Operation Mode */
        val &= ~0x3;
        break;
      default:
        stat = ARM_ETH_ERROR_UNSUPPORTED;
        break;
    }
    if (stat == ARM_ETH_OK) {
      stat = reg_wr(REG_PMECR, val);
    }
  }
  return (stat);
}

/**
  \fn          ARM_ETH_STATUS ETH_PHY_SetInterface (ARM_ETH_INTERFACE interface)
  \brief       Set Ethernet Media Interface.
  \param[in]   interface  \ref ARM_ETH_INTERFACE
  \return      \ref ARM_ETH_STATUS
*/
static ARM_ETH_STATUS PHY_SetInterface (ARM_ETH_INTERFACE interface) {
  /* Not used in this driver */
  return (ARM_ETH_OK);
}

/**
  \fn          ARM_ETH_STATUS ETH_PHY_SetMode (ARM_ETH_MODE mode)
  \brief       Set Ethernet PHY device Operation mode.
  \param[in]   mode  \ref ARM_ETH_MODE
  \return      \ref ARM_ETH_STATUS
*/
static ARM_ETH_STATUS PHY_SetMode (ARM_ETH_MODE mode) {
  uint16_t reg_val;

  reg_val = REG_P1MBCR_HPMDIX;

  switch (mode) {
    case ARM_ETH_MODE_AUTO_NEGOTIATE:
      reg_val |= REG_P1MBCR_ANEN;
      break; 
    case ARM_ETH_MODE_10M_FULL_DUPLEX:
      reg_val |= REG_P1MBCR_FORCEFD;
      break;
    case ARM_ETH_MODE_10M_HALF_DUPLEX:
      break;
    case ARM_ETH_MODE_100M_FULL_DUPLEX:
      reg_val |= REG_P1MBCR_FORCE100 | REG_P1MBCR_FORCEFD;
      break;
    case ARM_ETH_MODE_100M_HALF_DUPLEX:
      reg_val |= REG_P1MBCR_FORCE100;
      break;
    case ARM_ETH_MODE_LOOPBACK:
      reg_val |= REG_P1MBCR_LLB;
      break;
    case ARM_ETH_MODE_ISOLATE:
      reg_val |= REG_P1MBCR_DISTX;
      break;
    default:
      return ARM_ETH_ERROR_UNSUPPORTED;
  }

  return (reg_wr (REG_P1MBCR, reg_val));
}

/**
  \fn          ARM_ETH_LINK_STATE ETH_PHY_GetLinkState (void)
  \brief       Get Ethernet PHY Device Link state.
  \return      \ref ARM_ETH_LINK_STATE
*/
static ARM_ETH_LINK_STATE PHY_GetLinkState (void) {
  uint16_t val;
  ARM_ETH_LINK_STATE state = ARM_ETH_LINK_DOWN;

  if (reg_rd (REG_P1SR, &val) == ARM_ETH_OK) {
    if (val & REG_P1SR_LINKGOOD) {
      /* Link Good bit is set */
      state = ARM_ETH_LINK_UP;
    }
  }
  return (state);
}

/**
  \fn          ARM_ETH_LINK_INFO ETH_PHY_GetLinkInfo (void)
  \brief       Get Ethernet PHY Device Link information.
  \return      \ref ARM_ETH_LINK_INFO
*/
static ARM_ETH_LINK_INFO PHY_GetLinkInfo (void) {
  uint16_t val = 0;
  ARM_ETH_LINK_INFO info;

  reg_rd (REG_P1SR, &val);
  info.speed  = (val & REG_P1SR_OPSPEED)  ? ARM_ETH_SPEED_100M  : ARM_ETH_SPEED_10M;
  info.duplex = (val & REG_P1SR_OPDUPLEX) ? ARM_ETH_DUPLEX_FULL : ARM_ETH_DUPLEX_HALF;

  return (info);
}


/* PHY Driver Control Block */
ARM_DRIVER_ETH_PHY ARM_Driver_ETH_PHY_(ETH_NUM) = {
  PHY_GetVersion,
  PHY_Initialize,
  PHY_Uninitialize,
  PHY_PowerControl,
  PHY_SetInterface,
  PHY_SetMode,
  PHY_GetLinkState,
  PHY_GetLinkInfo
};

/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::Drivers:NAND
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    OneNAND.c
 * Purpose: OneNAND Flash Device connected to Memory Bus Driver
 * Rev.:    V5.04
 *----------------------------------------------------------------------------*/

#include "cmsis_os.h"

#include "OneNAND.h"
#include "OneNAND_Config.h"

#include "Driver_NAND.h"

#define ARM_NAND_DRV_VERSION ARM_DRV_VERSION_MAJOR_MINOR(5,04)   /* driver version */


#if   (NAND_DEV3)
#define NAND_NUM_DEVS 4
#elif (NAND_DEV2)
#define NAND_NUM_DEVS 3
#elif (NAND_DEV1)
#define NAND_NUM_DEVS 2
#elif (NAND_DEV0)
#define NAND_NUM_DEVS 1
#else
#error "No ::File System:Drive:NAND selected"
#endif

#if ((NAND_DEV0 && !NAND_DEV0_RB_PIN_IRQ) || \
     (NAND_DEV1 && !NAND_DEV1_RB_PIN_IRQ) || \
     (NAND_DEV2 && !NAND_DEV2_RB_PIN_IRQ) || \
     (NAND_DEV3 && !NAND_DEV3_RB_PIN_IRQ))
#define NAND_DRV_EVENT  0
#else
#define NAND_DRV_EVENT  1
#endif


#define MEM_16BIT(addr, offs) (*(volatile uint16_t *)((addr)+(offs)))

#define WAIT_TIMEOUT    10000   /* Wait timeout in us */

#define _Driver_NAND_(n)        Driver_NAND##n
#define  Driver_NAND_(n)       _Driver_NAND_(n)
#define _Driver_NAND_Event_(n)  Driver_NAND##n##_##Event
#define  Driver_NAND_Event_(n) _Driver_NAND_Event_(n)


/* Driver Version */
static const ARM_DRV_VERSION DriverVersion = {
  ARM_NAND_API_VERSION,
  ARM_NAND_DRV_VERSION
};

/* Driver Capabilities */
static const ARM_NAND_CAPABILITIES DriverCapabilities = {
  NAND_DRV_EVENT,       /* events   */
  0,                    /* raw_nand */
  1,                    /* one_nand */
  0,                    /* ecc_slc  */
  0,                    /* ecc_mlc  */
  0                     /* reserved */
};


/* NAND Information (Run-Time) */
static struct {
  ARM_NAND_DEVICE       *Device[NAND_NUM_DEVS]; /* Device Description array */
#if (NAND_DRV_EVENT)
  ARM_NAND_SignalEvent_t cb_event;              /* Event Callback */
#endif
} NAND_Info;


/* NAND Bus Information definition */
typedef struct {
  uint32_t addr_base;   /* Base Address */
} const NAND_BUS_INFO;


/* NAND Bus Information */
static NAND_BUS_INFO NAND_BusInfo[NAND_NUM_DEVS] = {
#if (NAND_NUM_DEVS >= 1)
#if (NAND_DEV0)
{ NAND_DEV0_ADDR_BASE },
#else
 { 0 },
#endif
#endif
#if (NAND_NUM_DEVS >= 2)
#if (NAND_DEV1)
{ NAND_DEV1_ADDR_BASE },
#else
 { 0 },
#endif
#endif
#if (NAND_NUM_DEVS >= 3)
#if (NAND_DEV2)
{ NAND_DEV2_ADDR_BASE },
#else
 { 0 },
#endif
#endif
#if (NAND_NUM_DEVS >= 4)
#if (NAND_DEV3)
{ NAND_DEV3_ADDR_BASE }
#else
 { 0 }
#endif
#endif
};


/* Private functions */

/**
  \fn          bool WaitReady (uint32_t addr_base)
  \brief       Wait until device is ready.
  \param[in]   addr_base  Device Base address
  \return      true  - Device is ready
               false - Device is busy, timeout expired
*/
static bool WaitReady (uint32_t addr_base) {
  uint32_t tick;

  /* Wait until device is busy */
  tick = osKernelSysTick();
  do {
    /* Pool Interrupt Status Register (INT bit) */
    if (MEM_16BIT(addr_base, ONENAND_REG_INT) & ONENAND_FLAG_ISR_INT) {
      return true;
    }
  } while ((osKernelSysTick() - tick) < osKernelSysTickMicroSec(WAIT_TIMEOUT));

  return false;
}


/**
  \fn          bool UnlockBlock (uint32_t addr_base, uint32_t pbn)
  \brief       Unlock Block in OneNAND Flash Array.
  \param[in]   addr_base  Device Base address
  \param[in]   pbn        Physical block number
  \return      true   - block unlocked before timeout
               false  - NAND busy, timeout expired
*/
static bool UnlockBlock (uint32_t addr_base, uint32_t pbn) {

  /* Set block address */
  MEM_16BIT(addr_base, ONENAND_REG_SBA) = (uint16_t)pbn;
  
  /* Clear interrupt flags */
  MEM_16BIT(addr_base, ONENAND_REG_INT) = 0x0000;

  /* Write unlock command */
  MEM_16BIT(addr_base, ONENAND_REG_CMD) = ONENAND_CMD_UNLOCK;
  
  /* Wait until operation complete */
  if (WaitReady(addr_base) == true) {
    if (MEM_16BIT(addr_base, ONENAND_REG_WPS) == 0x0004) {
      return true;
    }
  }
  return false;
}


/* Exported functions */

/**
  \fn          ARM_DRV_VERSION NAND_GetVersion (void)
  \brief       Get driver version.
  \return      \ref ARM_DRV_VERSION
*/
static ARM_DRV_VERSION GetVersion (void) {
  return DriverVersion;
}


/**
  \fn          ARM_NAND_CAPABILITIES NAND_GetCapabilities (void)
  \brief       Get driver capabilities.
  \return      \ref ARM_NAND_CAPABILITIES
*/
static ARM_NAND_CAPABILITIES GetCapabilities (void) {
  return DriverCapabilities;
}


/**
  \fn          ARM_NAND_STATUS NAND_Initialize (ARM_NAND_SignalEvent_t  cb_event,
                                                ARM_NAND_DEVICE        *ptr_device,
                                                uint32_t                num_devices)
  \brief       Initialize NAND Interface.
  \param[in]   cb_event    Pointer to \ref ARM_NAND_SignalEvent
  \param[in]   ptr_device  Pointer to device information
  \param[in]   num_devices Number of devices
  \return      \ref ARM_NAND_STATUS
*/
static ARM_NAND_STATUS Initialize (ARM_NAND_SignalEvent_t cb_event,
                                   ARM_NAND_DEVICE       *ptr_device,
                                   uint32_t               num_devices) {
  uint32_t i, n;

  if ((ptr_device  == NULL) ||
      (num_devices == 0)    ||
      (num_devices > NAND_NUM_DEVS)) {
    return ARM_NAND_ERROR;
  }

  for (i = 0; i < NAND_NUM_DEVS; i++) {
    NAND_Info.Device[i] = NULL;
  }

  for (i = 0; i < num_devices; i++) {
    n = ptr_device->device_number;
    if (n >= NAND_NUM_DEVS) return ARM_NAND_ERROR;
    NAND_Info.Device[n] = ptr_device++;
  }

#if (NAND_DRV_EVENT)
  NAND_Info.cb_event = cb_event;
#endif

  return ARM_NAND_ERROR;
}


/**
  \fn          ARM_NAND_STATUS NAND_Uninitialize (void)
  \brief       De-initialize NAND Interface.
  \return      \ref ARM_NAND_STATUS
*/
static ARM_NAND_STATUS Uninitialize (void) {
  return ARM_NAND_OK;
}


/**
  \fn          ARM_NAND_STATUS NAND_PowerControl (ARM_POWER_STATE state)
  \brief       Control the NAND interface power.
  \param[in]   state    Power state
  \return      \ref ARM_NAND_STATUS
*/
static ARM_NAND_STATUS PowerControl (ARM_POWER_STATE state) {

  switch (state) {
    case ARM_POWER_OFF:
      return ARM_NAND_UNSUPPORTED;

    case ARM_POWER_LOW:
      return ARM_NAND_UNSUPPORTED;

    case ARM_POWER_FULL:
      break;

    default:
      return ARM_NAND_UNSUPPORTED;
  }
  return ARM_NAND_OK;
}


/**
  \fn          ARM_NAND_STATUS NAND_ResetDevice (uint32_t dev_num)
  \brief       Reset a NAND device.
  \param[in]   dev_num   Device number
  \return      \ref ARM_NAND_STATUS
*/
static ARM_NAND_STATUS ResetDevice (uint32_t dev_num) {
  ARM_NAND_DEVICE *dev;
  uint32_t         addr_base;
  uint32_t         pbn;

  if (dev_num >= NAND_NUM_DEVS) return ARM_NAND_ERROR;

  dev = NAND_Info.Device[dev_num];
  if (dev == NULL) return ARM_NAND_ERROR;

  addr_base = NAND_BusInfo[dev_num].addr_base;

  /* Clear interrupts */
  MEM_16BIT(addr_base, ONENAND_REG_INT) = 0x0000;

  /* Flash Hot Reset */
  MEM_16BIT(addr_base, ONENAND_REG_CMD) = ONENAND_CMD_RST_HOT;

  if (WaitReady(addr_base) == false) {
    return ARM_NAND_TIMEOUT;
  }

  /* Set configuration */
  MEM_16BIT(addr_base, ONENAND_REG_CFG_1) = (0 << 15) | /* Async mode */
                                            (4 << 12) | /* Latency    */
                                            (0 <<  9) | /* Burst Len  */
                                            (0 <<  8) | /* ECC On     */
                                            (1 <<  7) | /* Ready high */
                                            (1 <<  6) | /* INT high   */
                                            (1 <<  5) | /* IOB Enable */
                                            (0 <<  4) ; /* Rdy 1clock */

  /* Check if controller ready */
  if (MEM_16BIT(addr_base, ONENAND_REG_STAT) != 0) {
    return ARM_NAND_TIMEOUT;
  }

  /* UnLock NAND Flash Array */
  for (pbn = 0; pbn < dev->block_count; pbn++) {
    if (UnlockBlock(addr_base, pbn) == false) {
      /* Block unlock failed */
      return ARM_NAND_ERROR;
    }
  }

  return ARM_NAND_OK;
}


/**
  \fn          ARM_NAND_STATUS NAND_ReadID (uint32_t  dev_num,
                                            uint8_t   addr,
                                            uint8_t  *buf,
                                            uint32_t  len)
  \brief       Read NAND device ID.
  \param[in]   dev_num   Device number
  \param[in]   addr      ID address
  \param[out]  buf       Buffer for data read from NAND
  \param[in]   len       Number of bytes to read (buffer length)
  \return      \ref ARM_NAND_STATUS
*/
static ARM_NAND_STATUS ReadID (uint32_t dev_num, uint8_t addr, uint8_t *buf, uint32_t len) {
  ARM_NAND_DEVICE *dev;
  uint32_t         addr_base;
  uint16_t         val;


  if (dev_num >= NAND_NUM_DEVS) return ARM_NAND_ERROR;
  if (buf == NULL) return ARM_NAND_ERROR;
  if (len < 4) return ARM_NAND_ERROR;

  dev = NAND_Info.Device[dev_num];
  if (dev == NULL) return ARM_NAND_ERROR;
  
  addr_base = NAND_BusInfo[dev_num].addr_base;

  /* Read manufacturer ID */
  val = MEM_16BIT(addr_base, ONENAND_REG_MAN_ID);

  buf[0] = (uint8_t) val;
  buf[1] = (uint8_t)(val >> 8);

  /* Read Device ID */
  val = MEM_16BIT(addr_base, ONENAND_REG_DEV_ID);

  buf[2] = (uint8_t) val;
  buf[3] = (uint8_t)(val >> 8);
 
  return ARM_NAND_OK;
}


/**
  \fn          ARM_NAND_STATUS NAND_ReadParamPage (uint32_t  dev_num,
                                                   uint32_t  col,
                                                   uint8_t  *buf,
                                                   uint32_t  len)
  \brief       Read NAND parameter page.
  \param[in]   dev_num   Device number
  \param[in]   col       Column address
  \param[out]  buf       Buffer for data read from NAND
  \param[in]   len       Number of bytes to read (buffer length)
  \return      \ref ARM_NAND_STATUS
*/
static ARM_NAND_STATUS ReadParamPage (uint32_t dev_num, uint32_t col, uint8_t *buf, uint32_t len) {
  return ARM_NAND_UNSUPPORTED;
}


/**
  \fn          ARM_NAND_STATUS NAND_ReadPage (uint32_t  dev_num,
                                              uint32_t  row,
                                              uint32_t  col,
                                              uint8_t  *buf,
                                              uint32_t  len)
  \brief       Read data from NAND page.
  \param[in]   dev_num   Device number
  \param[in]   row       Row address
  \param[in]   col       Column address
  \param[out]  buf       Buffer for data read from NAND
  \param[in]   len       Number of bytes to read (buffer length)
  \return      \ref ARM_NAND_STATUS
*/
static ARM_NAND_STATUS ReadPage (uint32_t dev_num, uint32_t row, uint32_t col, uint8_t *buf, uint32_t len) {
  ARM_NAND_DEVICE *dev;
  ARM_NAND_STATUS  status;
  uint32_t         addr_base;
  uint32_t         max;
  uint16_t         val, ecc;

  if (dev_num >= NAND_NUM_DEVS) return ARM_NAND_ERROR;
  if (buf == NULL) return ARM_NAND_ERROR;

  dev = NAND_Info.Device[dev_num];
  if (dev == NULL) return ARM_NAND_ERROR;
  
  addr_base = NAND_BusInfo[dev_num].addr_base;

  status = ARM_NAND_OK;

  while (len) {
    /* Set block and page address */
    MEM_16BIT(addr_base, ONENAND_REG_SA_1) = (uint16_t) (row / dev->page_count);
    MEM_16BIT(addr_base, ONENAND_REG_SA_8) = (uint16_t)((row % dev->page_count) << 2);

    /* Set start buffer register: DataRAM0, 4 sectors */
    MEM_16BIT(addr_base, ONENAND_REG_ST_BUF) = 8 << 8;

    /* Clear interrupt flags */
    MEM_16BIT(addr_base, ONENAND_REG_INT) = 0x0000;

    /* Send load command */
    MEM_16BIT(addr_base, ONENAND_REG_CMD) = ONENAND_CMD_LDM_BUF;

    /* Wait until operation complete */
    if (WaitReady(addr_base) == false) {
      return ARM_NAND_TIMEOUT;
    }

    /* Read user data from DataRAM0 buffer */
    for (max = (dev->page_size/512) * 512; len && (col < max); col += 2, len -= 2) {
      val = MEM_16BIT(addr_base, ONENAND_D0BUF_ADDR + col);
      *buf++ = (uint8_t) val;
      *buf++ = (uint8_t)(val >> 8);
    }

    /* Read spare area data from DataRAM0 buffer */
    col = 0;
    for (max = (dev->page_size/512) * 16; len && (col < max); col += 2, len -= 2) {
      val = MEM_16BIT(addr_base, ONENAND_S0BUF_ADDR + col);
      *buf++ = (uint8_t) val;
      *buf++ = (uint8_t)(val >> 8);
    }

    /* Read ECC status */
    ecc = MEM_16BIT(addr_base, ONENAND_REG_ECC_ST);
    if (ecc & 0xAAAA) {
      status = ARM_NAND_ECC_FAILED;
    }
    if (ecc & 0x5555) {
      if (status == ARM_NAND_OK) {
        status = ARM_NAND_ECC_CORRECTED;
      }
    }

    col  = 0;
    row += dev->page_size;
  }

  return status;
}


/**
  \fn          ARM_NAND_STATUS NAND_WritePage (      uint32_t  dev_num,
                                                     uint32_t  row,
                                                     uint32_t  col,
                                               const uint8_t  *buf,
                                                     uint32_t  len)
  \brief       Write data to NAND page.
  \param[in]   dev_num   Device number
  \param[in]   row       Row address
  \param[in]   col       Column address
  \param[out]  buf       Buffer with data to write to NAND
  \param[in]   len       Number of bytes to write (buffer length)
  \return      \ref ARM_NAND_STATUS
*/
static ARM_NAND_STATUS WritePage (uint32_t dev_num, uint32_t row, uint32_t col, const uint8_t *buf, uint32_t len) {
  ARM_NAND_DEVICE *dev;
  uint32_t         addr_base;
  uint32_t         max;
  uint16_t         val;

  if (dev_num >= NAND_NUM_DEVS) return ARM_NAND_ERROR;
  if (buf == NULL) return ARM_NAND_ERROR;

  dev = NAND_Info.Device[dev_num];
  if (dev == NULL) return ARM_NAND_ERROR;
  
  addr_base = NAND_BusInfo[dev_num].addr_base;

  while (len) {
    /* Copy user data to DataRAM0 buffer */
    for (max = (dev->page_size/512) * 512; len && (col < max); col += 2, len -= 2) {
      val  = *buf++;
      val |= *buf++ << 8;
      MEM_16BIT(addr_base, ONENAND_D0BUF_ADDR + col) = val;
    }

    /* Copy spare area data to DataRAM0 buffer */
    col = 0;
    for (max = (dev->page_size/512) * 16; len && (col < max); col += 2, len -= 2) {
      val  = *buf++;
      val |= *buf++ << 8;
      MEM_16BIT(addr_base, ONENAND_D0BUF_ADDR + col) = val;
    }

    /* Set block and page address */
    MEM_16BIT(addr_base, ONENAND_REG_SA_1) = (uint16_t) (row / dev->page_count);
    MEM_16BIT(addr_base, ONENAND_REG_SA_8) = (uint16_t)((row % dev->page_count) << 2);

    /* Set start buffer register: DataRAM0, 4 sectors */
    MEM_16BIT(addr_base, ONENAND_REG_ST_BUF) = 8 << 8;

    /* Clear interrupt flags */
    MEM_16BIT(addr_base, ONENAND_REG_INT) = 0x0000;

    /* Send program command */
    MEM_16BIT(addr_base, ONENAND_REG_CMD) = ONENAND_CMD_PRG_BUF;

    /* Wait until operation complete */
    if (WaitReady(addr_base) == false) {
      return ARM_NAND_TIMEOUT;
    }

    /* Read status */
    if (MEM_16BIT(addr_base, ONENAND_REG_STAT) & ONENAND_STAT_ERROR) {
      /* Programing failed */
      return ARM_NAND_PROGRAM_FAILED;
    }

    col  = 0;
    row += dev->page_size;
  }

  return ARM_NAND_OK;
}


/**
  \fn          NAND_STATUS NAND_NAND_CopyPage (uint32_t dev_num,
                                               uint32_t row_src,
                                               uint32_t row_dst,
                                               uint32_t row_cnt)
  \brief       Copy pages within NAND device.
  \param[in]   dev_num   Device number
  \param[in]   row_src   Source row address
  \param[in]   row_dst   Destination row address
  \param[in]   row_cnt   Number of pages (rows) to copy
  \return      \ref NAND_STATUS
*/
static ARM_NAND_STATUS CopyPage (uint32_t dev_num, uint32_t row_src, uint32_t row_dst, uint32_t row_cnt) {
  ARM_NAND_DEVICE *dev;
  uint32_t         addr_base;

  if (dev_num >= NAND_NUM_DEVS) return ARM_NAND_ERROR;

  dev = NAND_Info.Device[dev_num];
  if (dev == NULL) return ARM_NAND_ERROR;
  
  addr_base = NAND_BusInfo[dev_num].addr_base;

  while (row_cnt--) {
    /* Write source block and page address */
    MEM_16BIT (addr_base, ONENAND_REG_SA_1) = (uint16_t) (row_src / dev->page_count);
    MEM_16BIT (addr_base, ONENAND_REG_SA_8) = (uint16_t)((row_src % dev->page_count) << 2);

    /* Write destination block and page address */
    MEM_16BIT (addr_base, ONENAND_REG_SA_3) = (uint16_t) (row_dst / dev->page_count);
    MEM_16BIT (addr_base, ONENAND_REG_SA_4) = (uint16_t)((row_dst % dev->page_count) << 2);

    /* Set start buffer register: DataRAM0, 4 sectors */
    MEM_16BIT (addr_base, ONENAND_REG_ST_BUF) = 8 << 8;

    /* Clear interrupt flags */
    MEM_16BIT (addr_base, ONENAND_REG_INT) = 0x0000;

    /* Write Copyback Program command */
    MEM_16BIT (addr_base, ONENAND_REG_CMD) = ONENAND_CMD_CPY_BACK;

    /* Wait until ready */
    if (WaitReady(addr_base) == false) {
      return ARM_NAND_TIMEOUT;
    }

    /* Read status */
    if (MEM_16BIT(addr_base, ONENAND_REG_STAT) & ONENAND_STAT_ERROR) {
      /* Operation failed */
      return ARM_NAND_ERROR;
    }

    /* Update source and destination addresses */
    row_src += dev->page_size;
    row_dst += dev->page_size;
  }

  return ARM_NAND_OK;
}


/**
  \fn          ARM_NAND_STATUS NAND_EraseBlock (uint32_t  dev_num,
                                                uint32_t  row)
  \brief       Erase blocks in NAND device.
  \param[in]   dev_num   Device number
  \param[in]   row       Block start row address
  \return      \ref ARM_NAND_STATUS
*/
static ARM_NAND_STATUS EraseBlock (uint32_t dev_num, uint32_t row) {
  ARM_NAND_DEVICE *dev;
  uint32_t         addr_base;

  if (dev_num >= NAND_NUM_DEVS) return ARM_NAND_ERROR;

  dev = NAND_Info.Device[dev_num];
  if (dev == NULL) return ARM_NAND_ERROR;
  
  addr_base = NAND_BusInfo[dev_num].addr_base;

  /* Write block address */
  MEM_16BIT(addr_base, ONENAND_REG_SA_1) = (uint16_t)(row / dev->page_count);

  /* Write 0 to interrupt register */
  MEM_16BIT(addr_base, ONENAND_REG_INT) = 0x0000;

  /* Write erase command */
  MEM_16BIT(addr_base, ONENAND_REG_CMD) = ONENAND_CMD_ERASE;

  /* Wait until operation complete */
  if (WaitReady(addr_base) == false) {
    return ARM_NAND_TIMEOUT;
  }

  return ARM_NAND_OK;
}


/**
  \fn          ARM_NAND_STATUS NAND_ReadStatus (uint32_t dev_num, uint8_t *stat)
  \brief       Read NAND device status.
  \param[in]   dev_num   Device number
  \param[out]  stat      Pointer to store status read from NAND
  \return      \ref ARM_NAND_STATUS
*/
static ARM_NAND_STATUS ReadStatus (uint32_t dev_num, uint8_t *stat) {
  ARM_NAND_DEVICE *dev;

  if (dev_num >= NAND_NUM_DEVS) return ARM_NAND_ERROR;
  if (stat == NULL) return ARM_NAND_ERROR;

  dev = NAND_Info.Device[dev_num];
  if (dev == NULL) return ARM_NAND_ERROR;

  *stat = MEM_16BIT(NAND_BusInfo[dev_num].addr_base, ONENAND_REG_STAT);

  return ARM_NAND_OK;
}


/**
  \fn          void Driver_NANDx_Event (uint32_t dev_num)
  \brief       NAND Driver Event Callback when operation completes.
               Needs to be called on Ready/Busy pin rising edge.
  \param[in]   dev_num   Device number
  \return      \ref NAND_STATUS
*/
#if (NAND_DRV_EVENT)
void Driver_NAND_Event_(NAND_DRIVER) (uint32_t dev_num) {
  if (NAND_Info.cb_event) NAND_Info.cb_event(dev_num);
}
#endif


/* NAND Driver Control Block */
ARM_DRIVER_NAND Driver_NAND_(NAND_DRIVER) = {
  GetVersion,
  GetCapabilities,
  Initialize,
  Uninitialize,
  PowerControl,
  ResetDevice,
  ReadID,
  ReadParamPage,
  ReadPage,
  WritePage,
  CopyPage,
  EraseBlock,
  ReadStatus
};

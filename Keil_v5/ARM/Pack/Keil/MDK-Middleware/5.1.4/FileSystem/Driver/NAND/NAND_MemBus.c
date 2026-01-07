/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::Drivers:NAND
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    NAND_MemBus.c
 * Purpose: NAND Flash Device connected to Memory Bus Driver
 * Rev.:    V5.04
 *----------------------------------------------------------------------------*/

#include "cmsis_os.h"

#include "NAND_MemBus_Config.h"

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


#define MEM_8BIT( addr) (*(volatile uint8_t  *)(addr))
#define MEM_16BIT(addr) (*(volatile uint16_t *)(addr))

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
  1,                    /* raw_nand */
  0,                    /* one_nand */
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
  uint32_t addr_ale;    /* ALE Address  */
  uint32_t addr_cle;    /* CLE Address  */
  uint8_t  data_width;  /* Data Bus Width: 0=>8-bit, 1=>16-bit */
} const NAND_BUS_INFO;


/* NAND Bus Information */
static NAND_BUS_INFO NAND_BusInfo[NAND_NUM_DEVS] = {
#if (NAND_NUM_DEVS >= 1)
#if (NAND_DEV0)
{ NAND_DEV0_ADDR_BASE,
  NAND_DEV0_ADDR_ALE,
  NAND_DEV0_ADDR_CLE,
 (NAND_DEV0_DATA_WIDTH == 16) ? 1 : 0
},
#else
 { 0 },
#endif
#endif
#if (NAND_NUM_DEVS >= 2)
#if (NAND_DEV1)
{ NAND_DEV1_ADDR_BASE,
  NAND_DEV1_ADDR_ALE,
  NAND_DEV1_ADDR_CLE,
 (NAND_DEV1_DATA_WIDTH == 16) ? 1 : 0
},
#else
 { 0 },
#endif
#endif
#if (NAND_NUM_DEVS >= 3)
#if (NAND_DEV2)
{ NAND_DEV2_ADDR_BASE,
  NAND_DEV2_ADDR_ALE,
  NAND_DEV2_ADDR_CLE,
 (NAND_DEV2_DATA_WIDTH == 16) ? 1 : 0
},
#else
 { 0 },
#endif
#endif
#if (NAND_NUM_DEVS >= 4)
#if (NAND_DEV3)
{ NAND_DEV3_ADDR_BASE,
  NAND_DEV3_ADDR_ALE,
  NAND_DEV3_ADDR_CLE,
 (NAND_DEV3_DATA_WIDTH == 16) ? 1 : 0
}
#else
 { 0 }
#endif
#endif
};


/* Private functions */

/**
  \fn          void WriteCmd (uint32_t addr_cle, uint32_t cmd)
  \brief       Write command to the device.
  \param[in]   addr_cle  ALE address
  \param[in]   cmd       Command to write
*/
__inline static void WriteCmd (uint32_t addr_cle, uint32_t cmd) {
   MEM_8BIT(addr_cle) = (uint8_t)cmd;
}


/**
  \fn          void SetAddress (uint32_t addr_ale,
                                uint32_t row_cyc, uint32_t col_cyc,
                                uint32_t row,     uint32_t col)
  \brief       Set device row and column address.

  \param[in]   addr_ale  ALE address
  \param[in]   row_cyc   Number of cycles for row (page) address
  \param[in]   col_cyc   Number of cycles for column (byte) address
  \param[in]   row       Row address to set
  \param[in]   col       Column address to set
*/
static void SetAddress (uint32_t addr_ale,
                        uint32_t row_cyc, uint32_t col_cyc,
                        uint32_t row,     uint32_t col) {

  while (col_cyc--) {
    MEM_8BIT(addr_ale) = (uint8_t)col;
    col >>= 8;
  }
  while (row_cyc--) {
    MEM_8BIT(addr_ale) = (uint8_t)row;
    row >>= 8;
  }
}


/**
  \fn          uint32_t GetStatus (uint32_t dev_num)
  \brief       Read device status register.
  \param[in]   dev_num  Device number
  \return      Status register value
*/
static uint32_t GetStatus (uint32_t dev_num) {

  MEM_8BIT(NAND_BusInfo[dev_num].addr_cle) = ARM_NAND_CMD_STATUS;
  return MEM_8BIT(NAND_BusInfo[dev_num].addr_base);
}


/**
  \fn          bool WaitReady (uint32_t dev_num)
  \brief       Wait until device is ready.
  \param[in]   dev_num  Device number
  \return      true  - Device is ready
               false - Device is busy, timeout expired
*/
static bool WaitReady (uint32_t dev_num) {
  uint32_t status;
  uint32_t tick;

  /* Wait until device is busy */
  tick = osKernelSysTick();
  do {
    /* Read Status Register */
    status = GetStatus(dev_num);
    if (status & ARM_NAND_STAT_RDY) {
      return true;
    }
  } while ((osKernelSysTick() - tick) < osKernelSysTickMicroSec(WAIT_TIMEOUT));

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

  return ARM_NAND_OK;
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

  if (dev_num >= NAND_NUM_DEVS) return ARM_NAND_ERROR;

  dev = NAND_Info.Device[dev_num];
  if (dev == NULL) return ARM_NAND_ERROR;

  /* Write Reset command */
  WriteCmd(NAND_BusInfo[dev_num].addr_cle, ARM_NAND_CMD_RESET);

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

  if (dev_num >= NAND_NUM_DEVS) return ARM_NAND_ERROR;
  if (buf == NULL) return ARM_NAND_ERROR;

  dev = NAND_Info.Device[dev_num];
  if (dev == NULL) return ARM_NAND_ERROR;
  
  addr_base = NAND_BusInfo[dev_num].addr_base;

  /* Write Read ID command */
  WriteCmd(NAND_BusInfo[dev_num].addr_cle, ARM_NAND_CMD_READ_ID);

  /* Set address */
  SetAddress(NAND_BusInfo[dev_num].addr_ale, 0, 1, 0, addr);

  /* Read data */
  while (len--) {
    *buf++ = MEM_8BIT(addr_base);
  }

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
  ARM_NAND_DEVICE *dev;
  uint32_t         addr_base;
  uint32_t         addr_ale;
  uint32_t         addr_cle;

  if (dev_num >= NAND_NUM_DEVS) return ARM_NAND_ERROR;
  if (buf == NULL) return ARM_NAND_ERROR;

  dev = NAND_Info.Device[dev_num];
  if (dev == NULL) return ARM_NAND_ERROR;
  
  addr_base = NAND_BusInfo[dev_num].addr_base;
  addr_ale  = NAND_BusInfo[dev_num].addr_ale;
  addr_cle  = NAND_BusInfo[dev_num].addr_cle;

  /* Write Read Parameter Page command */
  WriteCmd(addr_cle, ARM_NAND_CMD_READ_PARAM_PAGE);

  /* Set address */
  SetAddress(addr_ale, 0, 1, 0, 0);

  /* Wait until device ready */
  if (WaitReady(dev_num) == false) {
    return ARM_NAND_TIMEOUT;
  }

  if (col) {
    /* Write Change Read Column 1ST command */
    WriteCmd(addr_cle, ARM_NAND_CMD_CHANGE_RD_COL_1ST);

    /* Set column address */
    SetAddress(addr_ale, 0, 2, 0, col);

    /* Issue Change Read Column 2ND command */
    WriteCmd(addr_cle, ARM_NAND_CMD_CHANGE_RD_COL_2ND);
  }

  /* Read data */
  while (len--) {
    *buf++ = MEM_8BIT(addr_base);
  }

  return ARM_NAND_OK;
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
  uint32_t         addr_base;
  uint32_t         addr_ale;
  uint32_t         addr_cle;
  uint8_t          data_width;
  uint32_t         page_cnt;
  uint32_t         cnt, n;
  uint16_t         val;
  bool             cached;

  if (dev_num >= NAND_NUM_DEVS) return ARM_NAND_ERROR;
  if (buf == NULL) return ARM_NAND_ERROR;

  dev = NAND_Info.Device[dev_num];
  if (dev == NULL) return ARM_NAND_ERROR;
  
  addr_base  = NAND_BusInfo[dev_num].addr_base;
  addr_ale   = NAND_BusInfo[dev_num].addr_ale;
  addr_cle   = NAND_BusInfo[dev_num].addr_cle;
  data_width = NAND_BusInfo[dev_num].data_width;

  /* Write Read 1st command */
  WriteCmd(addr_cle, ARM_NAND_CMD_READ_1ST);

  /* Set address */
  SetAddress(addr_ale, dev->row_cycles, dev->col_cycles, row, col);

  /* Write Read 2nd command */
  WriteCmd(addr_cle, ARM_NAND_CMD_READ_2ND);

  if ((col + len) > dev->page_size) {
    /* Enable cached read */
    cached = true;
    page_cnt = ((col + len + dev->page_size - 1) / dev->page_size);    
    cnt = dev->page_size - col;
  }
  else {
    /* Disable cached read */
    cached = false;
    page_cnt = 0;
    cnt = len;
  }

  /* Wait until device ready */
  if (WaitReady(dev_num) == false) {
    return ARM_NAND_TIMEOUT;
  }

  do {
    if (cached) {
      if (page_cnt--) {
        /* Write Page Cache Read command */
        WriteCmd(addr_cle, ARM_NAND_CMD_READ_CACHE_SEQUENTIAL);
      }
      else {
        /* Write Read Cache End command */
        WriteCmd(addr_cle, ARM_NAND_CMD_READ_CACHE_END);
      }

      /* Wait until device ready */
      if (WaitReady(dev_num) == false) {
        return ARM_NAND_TIMEOUT;
      }
    }

    /* Switch back to Read Mode */
    WriteCmd(addr_cle, ARM_NAND_CMD_READ_1ST);

    /* Transfer data from NAND chip to memory */
    if (data_width) {
      /* 16-bit bus read */
      for (n = 0; n < cnt; n += 2) {
        val = MEM_16BIT(addr_base);
        buf[n+0] = (uint8_t) val;
        buf[n+1] = (uint8_t)(val >> 8);
      }
    }
    else {
      /* 8-bit bus read transfer */
      for (n = 0; n < cnt; n++) {
        buf[n] = MEM_8BIT(addr_base);
      }
    }

    len -= cnt;
    cnt  = dev->page_size;
    if (cnt > len) cnt = len;
  }
  while (len);

  return ARM_NAND_OK;
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
  uint32_t         addr_ale;
  uint32_t         addr_cle;
  uint8_t          data_width;
  uint32_t         page_cnt;
  uint32_t         cnt, n;
  uint16_t         val;
  bool             cached;

  if (dev_num >= NAND_NUM_DEVS) return ARM_NAND_ERROR;
  if (buf == NULL) return ARM_NAND_ERROR;

  dev = NAND_Info.Device[dev_num];
  if (dev == NULL) return ARM_NAND_ERROR;
  
  addr_base  = NAND_BusInfo[dev_num].addr_base;
  addr_ale   = NAND_BusInfo[dev_num].addr_ale;
  addr_cle   = NAND_BusInfo[dev_num].addr_cle;
  data_width = NAND_BusInfo[dev_num].data_width;

  if ((col + len) > dev->page_size) {
    /* Enable cached program */
    cached = true;
    page_cnt = ((col + len + dev->page_size - 1) / dev->page_size);
    cnt = dev->page_size - col;
  }
  else {
    /* Disable cached program */
    cached = false;
    page_cnt = 0;
    cnt = len;
  }

  do {

    /* Write Page Program 1st command */
    WriteCmd(addr_cle, ARM_NAND_CMD_PROGRAM_1ST);

    /* Set address */
    SetAddress(addr_ale, dev->row_cycles, dev->col_cycles, row, col);

    /* Transfer data from memory to the NAND chip */
    if (data_width) {
      /* 16-bit bus write transfer */
      for (n = 0; n < cnt; n += 2) {
        val = buf[n] | (buf[n+1] << 8);
        MEM_16BIT(addr_base) = val;
      }
    }
    else {
      /* 8-bit bus write transfer */
      for (n = 0; n < cnt; n++) {
        MEM_8BIT(addr_base) = buf[n];
      }
    }

    len -= cnt;
    cnt  = dev->page_size;
    if (cnt > len) cnt = len;

    if (cached) {
      if (page_cnt--) {
        /* Write Page Cache Program 2nd command */
        WriteCmd(addr_cle, ARM_NAND_CMD_PAGE_CACHE_PROGRAM_2ND);

        /* Update address */
        row += dev->page_size;
        col  = 0;

        /* Wait until device ready */
        if (WaitReady(dev_num) == false) {
          return ARM_NAND_TIMEOUT;
        }
      }
    }
  }
  while (len);

  /* Write Page Program 2nd command */
  WriteCmd(addr_cle, ARM_NAND_CMD_PROGRAM_2ND);

  return ARM_NAND_OK;
}


/**
  \fn          ARM_NAND_STATUS NAND_CopyPage (uint32_t dev_num,
                                              uint32_t row_src,
                                              uint32_t row_dst,
                                              uint32_t row_cnt)
  \brief       Copy pages within NAND device.
  \param[in]   dev_num   Device number
  \param[in]   row_src   Source row address
  \param[in]   row_dst   Destination row address
  \param[in]   row_cnt   Number of pages (rows) to copy
  \return      \ref ARM_NAND_STATUS
*/
static ARM_NAND_STATUS CopyPage (uint32_t dev_num, uint32_t row_src, uint32_t row_dst, uint32_t row_cnt) {
  ARM_NAND_DEVICE *dev;
  uint32_t         addr_ale;
  uint32_t         addr_cle;
  uint32_t         status;

  if (dev_num >= NAND_NUM_DEVS) return ARM_NAND_ERROR;

  dev = NAND_Info.Device[dev_num];
  if (dev == NULL) return ARM_NAND_ERROR;
  
  addr_ale = NAND_BusInfo[dev_num].addr_ale;
  addr_cle = NAND_BusInfo[dev_num].addr_cle;

  while (row_cnt--) {
    /* Write Copyback Read 1st command */
    WriteCmd(addr_cle, ARM_NAND_CMD_COPYBACK_READ_1ST);

    /* Set source page address */
    SetAddress(addr_ale, dev->row_cycles, dev->col_cycles, row_src, 0);

    /* Write Copyback Read 2nd command */
    WriteCmd(addr_cle, ARM_NAND_CMD_COPYBACK_READ_2ND);

    /* Wait until device ready */
    if (WaitReady(dev_num) == false) {
      return ARM_NAND_TIMEOUT;
    }
    
    /* Write Copyback Program 1st command */
    WriteCmd(addr_cle, ARM_NAND_CMD_COPYBACK_PROGRAM_1ST);

    /* Set destination page address */
    SetAddress(addr_ale, dev->row_cycles, dev->col_cycles, row_dst, 0);

    /* Write Copyback Program 2nd command */
    WriteCmd(addr_cle, ARM_NAND_CMD_COPYBACK_PROGRAM_2ND);

    /* Wait until device ready */
    if (WaitReady(dev_num) == false) {
      return (ARM_NAND_TIMEOUT);
    }
    
    /* Read status */
    status = GetStatus(dev_num);
    if (status & ARM_NAND_STAT_FAIL) {
      return ARM_NAND_PROGRAM_FAILED;
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
  uint32_t         addr_ale;
  uint32_t         addr_cle;

  if (dev_num >= NAND_NUM_DEVS) return ARM_NAND_ERROR;

  dev = NAND_Info.Device[dev_num];
  if (dev == NULL) return ARM_NAND_ERROR;
  
  addr_ale = NAND_BusInfo[dev_num].addr_ale;
  addr_cle = NAND_BusInfo[dev_num].addr_cle;

  /* Write Block Erase 1st command */
  WriteCmd(addr_cle, ARM_NAND_CMD_ERASE_1ST);

  /* Set source page address */
  SetAddress(addr_ale, dev->row_cycles, 0, row, 0);

  /* Write Block Erase 2nd command */
  WriteCmd(addr_cle, ARM_NAND_CMD_ERASE_2ND);

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

  *stat = GetStatus(dev_num);

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

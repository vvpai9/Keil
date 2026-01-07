//-----------------------------------------------------------------------------
// 91X_MEMS
//-----------------------------------------------------------------------------
#ifndef __91X_MEMS_H
#define __91X_MEMS_H

#include <91x_lib.h>

//-----------------------------------------------------------------------------
// MEMS
//-----------------------------------------------------------------------------
//---Size of MEMs data---
#define MEMS_DATA_SIZE 6

//---address of slave I want to communicate---
#define kLIS3L02DQ_SLAVE_ADDR    0x3A

//-----------------------------------------------------------------------------
//---accelerometer register addresses---
#define OFFSET_X         0x16
#define OFFSET_Y         0x17
#define OFFSET_Z         0x18
#define GAIN_X           0x19
#define GAIN_Y           0x1A
#define GAIN_Z           0x1B
#define CTRL_REG1        0x20
#define CTRL_REG2        0x21
#define STATUS_REG       0x27
#define OUTX_L           0x28
#define OUTX_H           0x29
#define OUTY_L           0x2A
#define OUTY_H           0x2B
#define OUTZ_L           0x2C
#define OUTZ_H           0x2D
#define FF_WU_CFG        0x30
#define FF_WU_SRC        0x31
#define FF_WU_ACK        0x32
#define FF_WU_THS_L      0x34
#define FF_WU_THS_H      0x35
#define FF_WU_DURATION   0x36
#define DD_CFG           0x38
#define DD_SRC           0x39
#define DD_ACK           0x3A
#define DD_THSI_L        0x3C
#define DD_THSI_H        0x3D
#define DD_THSE_L        0x3E
#define DD_THSE_H        0x3F

// Communication control settings
// I2C
#define REPETIR          0x80 
// SPI
#define MEMS_SPI_WRITE   0x00
#define MEMS_SPI_READ    0x80
#define MEMS_SPI_MULTIPLE_BYTES 0x40


//-----------------------------------------------------------------------------
//---Settings for CTRL_REG1---

// Power Down Control (PD)
#define LIS_PD_OFF 0x00
#define LIS_PD_ON  0x40

// Decimation Factor Control (DF)
#define LIS_DF_BY128 0x00
#define LIS_DF_BY64  0x10
#define LIS_DF_BY32  0x20
#define LIS_DF_BY8   0x30

// Self Test
#define LIS_ST_NORMAL 0x00
#define LIS_ST_TEST   0x08

// Enable Axis
#define LIS_EA_ALL    0x07

//-----------------------------------------------------------------------------
//---Settings for CTRL_REG2---

// Full Scale (FS)
#define LIS_FS_2G 0x00
#define LIS_FS_6G 0x80

// Block Data Update (BDU)
#define LIS_BDU_CONTINUOUS 0x00
#define LIS_BDU_WAIT       0x40

// Big/Little Endian Selection (BLE)
#define LIS_BLE_LE 0x00
#define LIS_BLE_BE 0x20

// Data Alignment Selection DAS
#define LIS_DAS_12BIT 0x00
#define LIS_DAS_16BIT 0x01

// Interrupt Enable
#define LIS_INTR_DISABLE 0x00
#define LIS_INTR_ENABLE  0x08

// Data Ready Enable
#define LIS_DRDY_DISABLE 0x00
#define LIS_DRDY_ENABLE  0x04

//-----------------------------------------------------------------------------
#define LIS_BLE_XX LIS_BLE_BE

//-----------------------------------------------------------------------------
typedef struct {
  u8 outx_l;
  u8 outx_h;
  u8 outy_l;
  u8 outy_h;
  u8 outz_l;
  u8 outz_h;
} t_mems_data;
//-----------------------------------------------------------------------------

extern t_mems_data mems_data;
void Periph_Config_MEMs(void);
//void spi_read_reg (u8 reg_addr, u8 *pBuffer, u8 NoOfBytes);
//void spi_write_reg (u8 reg_addr, u8 reg_value);
void SPI_MEMS_Init (void);
void SPI_MEMS_Read (t_mems_data *mems_data);

//-----------------------------------------------------------------------------
#endif


/* ----------------------------------------------------------------------
 * Copyright (C) 2013 ARM Limited. All rights reserved.
 *  
 * $Date:        12. Sept 2013
 * $Revision:    V1.10
 *  
 * Project:      Memory Card Interface (MCI) Driver for Middleware
 * -------------------------------------------------------------------- */

/* History:
 *  Version 1.10
 *    Namespace prefix ARM_ added
 *  Version 1.00
 *    Initial release
 */ 

#ifndef __DRIVER_MCI_H
#define __DRIVER_MCI_H

#include "Driver_Common.h"

#define ARM_MCI_API_VERSION ARM_DRV_VERSION_MAJOR_MINOR(1,10)    /* API version */


/**
\brief Memory Card Command Set
*/
typedef enum _ARM_MC_COMMAND {
  ARM_MC_CMD_GO_IDLE_STATE        =  0,   ///< Reset card to idle state     MMC,SD
  ARM_MC_CMD_SEND_OP_COND         =  1,   ///< Send Op.Cond. Register       MMC,--
  ARM_MC_CMD_ALL_SEND_CID         =  2,   ///< Send Card CID number         MMC,SD
  ARM_MC_CMD_SEND_RELATIVE_ADDR   =  3,   ///< Set Relative Address         MMC,SD
  ARM_MC_CMD_SET_BUS_WIDTH        =  6,   ///< Set Bus Width 1bit/4bits     ---,SD
  ARM_MC_CMD_SELECT_DESELECT_CARD =  7,   ///< Select/Deselect the Card     MMC,SD
  ARM_MC_CMD_SEND_IF_COND         =  8,   ///< Send Interface Condition     ---,SD
  ARM_MC_CMD_SEND_CSD             =  9,   ///< Send Card Specific Data      MMC,SD
  ARM_MC_CMD_SEND_CID             = 10,   ///< Send Card Identificat.Data   MMC,SD
  ARM_MC_CMD_VOLTAGE_SWITCH       = 11,   ///< Switch to 1.8V bus signaling ---,SD
  ARM_MC_CMD_STOP_TRANSMISSION    = 12,   ///< Stop Read or Write transm.   MMC,SD
  ARM_MC_CMD_SEND_STATUS          = 13,   ///< Send Status Register         MMC,SD
  ARM_MC_CMD_SET_BLOCKLEN         = 16,   ///< Set Block Length in bytes    MMC,SD
  ARM_MC_CMD_READ_SINGLE_BLOCK    = 17,   ///< Read a Single Block          MMC,SD
  ARM_MC_CMD_READ_MULTIPLE_BLOCK  = 18,   ///< Read Multiple Blocks         MMC,SD
  ARM_MC_CMD_SEND_TUNING_BLOCK    = 19,   ///< Send 64 bytes tuning pattern MMC,SD
  ARM_MC_CMD_WRITE_SINGLE_BLOCK   = 24,   ///< Write a Block                MMC,SD
  ARM_MC_CMD_WRITE_MULTIPLE_BLOCK = 25,   ///< Write Multiple Blocks        MMC,SD
  ARM_MC_CMD_SET_WRITE_PROT       = 28,   ///< Sets write protection bit    MMC,SD
  ARM_MC_CMD_CLR_WRITE_PROT       = 29,   ///< Clears write protection bit  MMC,SD
  ARM_MC_CMD_SEND_WRITE_PROT      = 30,   ///< Send write protection status MMC,SD
  ARM_MC_CMD_SD_SEND_OP_COND      = 41,   ///< Send App. Op.Cond Register   ---,SD
  ARM_MC_CMD_LOCK_UNLOCK          = 42,   ///< Set/reset the password       MMC,SD
  ARM_MC_CMD_APP_CMD              = 55,   ///< App.Specific Cmd follows     MMC,SD
  ARM_MC_CMD_READ_OCR             = 58,   ///< Read OCR Register            MMC,SD
  ARM_MC_CMD_CRC_ON_OFF           = 59    ///< Turn CRC7 checking on/off    MMC,SD
} ARM_MC_COMMAND;

/**
\brief Memory Card Response Types
*/
typedef enum _ARM_MC_RESPONSE {
  ARM_MC_RESPONSE_NONE = 0,               ///< No response expected
  ARM_MC_RESPONSE_R1,                     ///< Normal response command (48-bit)
  ARM_MC_RESPONSE_R1b,                    ///< R1 response with busy signal (48-bit)
  ARM_MC_RESPONSE_R2,                     ///< CID, CSD register response (136-bit)
  ARM_MC_RESPONSE_R3,                     ///< OCR register response (48-bit)
  ARM_MC_RESPONSE_R4,                     ///< Fast I/O response (48-bit)
  ARM_MC_RESPONSE_R5,                     ///< Interrupt request response (48-bit)
  ARM_MC_RESPONSE_R5b,                    ///< R5 response with busy signal (48-bit)
  ARM_MC_RESPONSE_R6,                     ///< Published RCA response (48-bit)
  ARM_MC_RESPONSE_R7                      ///< Card interface condition (48-bit)
} ARM_MC_RESPONSE;

/**
\brief MCI Card Event
*/
typedef enum _ARM_MCI_EVENT {
  ARM_MCI_EVENT_INSERTED,                 ///< Memory Card inserted
  ARM_MCI_EVENT_REMOVED,                  ///< Memory Card removed
  ARM_MCI_EVENT_BUSY_DEASSERTED           ///< Memory Card Busy flag de-asserted
} ARM_MCI_EVENT;

/**
\brief MCI Card Power
*/
typedef enum _ARM_MCI_POWER {
  ARM_MCI_POWER_OFF = 0,                  ///< Power turned off
  ARM_MCI_POWER_VDD_3V3,                  ///< Power VDD = 3.3V
  ARM_MCI_POWER_VDD_1V8                   ///< Power VDD = 1.8V
} ARM_MCI_POWER;

/**
\brief MCI Card Switch
*/
typedef struct _ARM_MCI_SWITCH {
  uint8_t cd_state : 1;                   ///< Card Detect (CD) state (1 = card inserted)
  uint8_t wp_state : 1;                   ///< Write Protect (WP) state (1 = write protected)
} ARM_MCI_SWITCH;

/**
\brief MCI Bus Mode
*/
typedef enum _ARM_MCI_BUS_MODE {
  ARM_MCI_BUS_OPEN_DRAIN,                 ///< Open Drain CMD line
  ARM_MCI_BUS_PUSH_PULL                   ///< Push-Pull CMD line
} ARM_MCI_BUS_MODE;

/**
\brief MCI Bus Data Width
*/
typedef enum _ARM_MCI_BUS_DATA_WIDTH {
  ARM_MCI_BUS_DATA_WIDTH_1,               ///< Bus data width: 1 bit
  ARM_MCI_BUS_DATA_WIDTH_4,               ///< Bus data width: 4 bits
  ARM_MCI_BUS_DATA_WIDTH_8                ///< Bus data width: 8 bits
} ARM_MCI_BUS_DATA_WIDTH;

/**
\brief MCI Bus Signaling
*/
typedef enum _ARM_MCI_BUS_SIGNALING {
  ARM_MCI_BUS_SIGNALING_3V3,              ///< Bus signaling: 3.3V
  ARM_MCI_BUS_SIGNALING_1V8               ///< Bus signaling: 1.8V
} ARM_MCI_BUS_SIGNALING;

/**
\brief MCI Transfer Mode
*/
typedef enum _ARM_MCI_TRANSFER_MODE {
  ARM_MCI_TRANSFER_READ,                  ///< Read Transfer (from MCI)
  ARM_MCI_TRANSFER_WRITE                  ///< Write Transfer (to MCI)
} ARM_MCI_TRANSFER_MODE;

/**
\brief MCI Status of executed operation
*/
typedef enum _ARM_MCI_STATUS {
  ARM_MCI_OK                       =  0,  ///< Operation succeeded
  ARM_MCI_ERROR                    =  1,  ///< Unspecified error
  ARM_MCI_ERROR_UNSUPPORTED        =  2,  ///< Operation not supported
  ARM_MCI_ERROR_RESPONSE           =  3,  ///< Invalid response received
  ARM_MCI_ERROR_COMMAND_TIMEOUT    =  4,  ///< Command response timeout
  ARM_MCI_ERROR_TRANSFER_TIMEOUT   =  5,  ///< Data transfer timeout
  ARM_MCI_ERROR_CRC                =  6   ///< CRC check failed
} ARM_MCI_STATUS;


// Function documentation
/**
  \fn            ARM_DRV_VERSION ARM_MCI_GetVersion (void)
  \brief         Get driver version.
  \return        \ref ARM_DRV_VERSION
*/
/**
  \fn            ARM_MCI_CAPABILITIES ARM_MCI_GetCapabilities (void)
  \brief         Get driver capabilities.
  \return        \ref ARM_MCI_CAPABILITIES
*/
/**
  \fn            ARM_MCI_STATUS ARM_MCI_Initialize (ARM_MCI_SignalEvent_t cb_event, bool spi_mode)
  \brief         Initialize the Memory Card Interface
  \param[in]     cb_event  Pointer to \ref ARM_MCI_SignalEvent
  \param[in]     spi_mode  SPI Mode (default is native MMC/SD Mode)
  \return        execution status \ref ARM_MCI_STATUS
*/
/**
  \fn            ARM_MCI_STATUS ARM_MCI_Uninitialize (void)
  \brief         De-initialize Memory Card Interface.
  \return        execution status \ref ARM_MCI_STATUS
*/
/**
  \fn            ARM_MCI_STATUS ARM_MCI_PowerControl (ARM_POWER_STATE state)
  \brief         Control Memory Card Interface Power.
  \param[in]     state   Power state \ref ARM_POWER_STATE
  \return        execution status \ref ARM_MCI_STATUS
*/
/**
  \fn            ARM_MCI_STATUS ARM_MCI_BusMode (ARM_MCI_BUS_MODE mode)
  \brief         Setup the bus mode for Memory Card transfers.
  \param[in]     mode  Requested bus mode
  \return        execution status \ref ARM_MCI_STATUS
*/
/**
  \fn            ARM_MCI_STATUS ARM_MCI_BusDataWidth (ARM_MCI_BUS_DATA_WIDTH width)
  \brief         Setup bus data width for Memory Card transfers.
  \param[in]     width  Requested bus data width
  \return        execution status \ref ARM_MCI_STATUS
*/
/**
  \fn            ARM_MCI_STATUS ARM_MCI_BusSignaling (ARM_MCI_BUS_SIGNALING voltage)
  \brief         Set bus signaling voltage for MCI transfers.
  \param[in]     voltage  Requested signaling voltage
  \return        execution status \ref ARM_MCI_STATUS
*/
/**
  \fn            uint32_t ARM_MCI_BusSpeed (uint32_t bps)
  \brief         Setup bus speed for Memory Card transfers.
  \param[in]     bps  Requested speed in bits/s
  \return        Configured bus speed in bits/s
*/
/**
  \fn            ARM_MCI_STATUS ARM_MCI_CardPower (ARM_MCI_POWER voltage)
  \brief         Set Memory Card supply voltage.
  \param[in]     voltage  Memory Card supply voltage \ref ARM_MCI_POWER
  \return        execution status \ref ARM_MCI_STATUS
*/
/**
  \fn            ARM_MCI_SWITCH ARM_MCI_CardSwitchRead (void)
  \brief         Read state of Memory Card switches.
  \return        execution status \ref ARM_MCI_SWITCH
*/
/**
  \fn            ARM_MCI_STATUS ARM_MCI_CardInitialize (void)
  \brief         Perform Memory Card initialization sequence.
  \return        execution status \ref ARM_MCI_STATUS
*/
/**
  \fn            ARM_MCI_STATUS ARM_MCI_SendCommand (ARM_MC_COMMAND   cmd,
                                                     uint32_t         cmd_arg,
                                                     ARM_MC_RESPONSE  response_type,
                                                     uint32_t        *ptr_response)
  \brief         Send Command to card and get the response.
  \param[in]     cmd            Memory Card command \ref ARM_MC_COMMAND
  \param[in]     cmd_arg        Command argument
  \param[in]     response_type  Expected response type
  \param[out]    ptr_response   Pointer to response
  \return        execution status \ref ARM_MCI_STATUS
*/
/**
  \fn            ARM_MCI_STATUS ARM_MCI_SetupTransfer (uint8_t *data,
                                                       uint32_t block_count,
                                                       uint32_t block_size,
                                                       ARM_MCI_TRANSFER_MODE mode)
  \brief         Setup read or write transfer operation.
  \param[in,out] data         Pointer to data block(s) to be written or read
  \param[in]     block_count  Number of blocks
  \param[in]     block_size   Size of a block in bytes
  \param[in]     mode         Read or write transfer mode
  \return        execution status \ref ARM_MCI_STATUS
*/
/**
  \fn            ARM_MCI_STATUS ARM_MCI_ReadTransfer  (uint8_t *data,
                                                       uint32_t block_count,
                                                       uint32_t block_size)
  \brief         Perform read transfer.
  \param[out]    data         Pointer to data block(s) to be read
  \param[in]     block_count  Number of blocks
  \param[in]     block_size   Size of a block in bytes
  \return        execution status \ref ARM_MCI_STATUS
*/
/**
  \fn            ARM_MCI_STATUS ARM_MCI_WriteTransfer (uint8_t *data,
                                                       uint32_t block_count,
                                                       uint32_t block_size)
  \brief         Perform write transfer.
  \param[in]     data         Pointer to data block(s) to be written
  \param[in]     block_count  Number of blocks
  \param[in]     block_size   Size of a block in bytes
  \return        execution status \ref ARM_MCI_STATUS
*/
/**
  \fn            ARM_MCI_STATUS ARM_MCI_AbortTransfer (void)
  \brief         Abort current read/write data transfer.
  \return        execution status \ref ARM_MCI_STATUS
*/

/**
  \fn            void ARM_MCI_SignalEvent (ARM_MCI_EVENT event)
  \brief         Callback function that signals a MCI Card Event.
  \param[in]     event \ref ARM_MCI_EVENT
  \return        none
*/

typedef void (*ARM_MCI_SignalEvent_t) (ARM_MCI_EVENT event);  ///< Pointer to \ref ARM_MCI_SignalEvent : Signal MCI Card Event.

/**
\brief  MCI Driver Capabilities.
*/
typedef struct _ARM_MCI_CAPABILITIES {
  uint32_t cd_state      :  1;            ///< Card Detect State available
  uint32_t cd_event      :  1;            ///< Signal Card Detect change event
  uint32_t wp_state      :  1;            ///< Write Protect State available
  uint32_t busy_event    :  1;            ///< Signal Busy de-asserted event
  uint32_t data_width_4  :  1;            ///< Supports 4-bit data
  uint32_t data_width_8  :  1;            ///< Supports 8-bit data
  uint32_t power_off     :  1;            ///< Supports Card Power Off
  uint32_t vdd_1v8       :  1;            ///< Supports 1.8V Card Power
  uint32_t signaling_1v8 :  1;            ///< Supports 1.8V Signaling
  uint32_t reserved      : 23;            ///< reserved for future use
} ARM_MCI_CAPABILITIES;


/**
\brief  Access structure of the MCI Driver.
*/
typedef struct _ARM_DRIVER_MCI {
  ARM_DRV_VERSION      (*GetVersion)     (void);                           ///< Pointer to \ref ARM_MCI_GetVersion : Get driver version.
  ARM_MCI_CAPABILITIES (*GetCapabilities)(void);                           ///< Pointer to \ref ARM_MCI_GetCapabilities : Get driver capabilities.
  ARM_MCI_STATUS       (*Initialize)     (ARM_MCI_SignalEvent_t cb_event,
                                          bool spi_mode);                  ///< Pointer to \ref ARM_MCI_Initialize : Initialize MCI Interface.
  ARM_MCI_STATUS       (*Uninitialize)   (void);                           ///< Pointer to \ref ARM_MCI_Uninitialize : De-initialize MCI Interface.
  ARM_MCI_STATUS       (*PowerControl)   (ARM_POWER_STATE state);          ///< Pointer to \ref ARM_MCI_PowerControl : Control MCI Interface Power.
  ARM_MCI_STATUS       (*BusMode)        (ARM_MCI_BUS_MODE mode);          ///< Pointer to \ref ARM_MCI_BusMode : Set bus mode for MCI transfers.
  ARM_MCI_STATUS       (*BusDataWidth)   (ARM_MCI_BUS_DATA_WIDTH width);   ///< Pointer to \ref ARM_MCI_BusDataWidth : Set bus data width for MCI transfers.
  ARM_MCI_STATUS       (*BusSignaling)   (ARM_MCI_BUS_SIGNALING voltage);  ///< Pointer to \ref ARM_MCI_BusSignaling : Set bus signaling voltage for MCI transfers.
  uint32_t             (*BusSpeed)       (uint32_t bps);                   ///< Pointer to \ref ARM_MCI_BusSpeed : Set bus speed for MCI transfers.
  ARM_MCI_STATUS       (*CardPower)      (ARM_MCI_POWER voltage);          ///< Pointer to \ref ARM_MCI_CardPower : Set card power supply voltage.
  ARM_MCI_SWITCH       (*CardSwitchRead) (void);                           ///< Pointer to \ref ARM_MCI_CardSwitchRead : Read state of Card switches.
  ARM_MCI_STATUS       (*CardInitialize) (void);                           ///< Pointer to \ref ARM_MCI_CardInitialize : Perform Card initialization sequence.
  ARM_MCI_STATUS       (*SendCommand)    (ARM_MC_COMMAND cmd, 
                                          uint32_t cmd_arg, 
                                          ARM_MC_RESPONSE response_type,
                                          uint32_t *ptr_response);         ///< Pointer to \ref ARM_MCI_SendCommand : Send Command to card and get the response.
  ARM_MCI_STATUS       (*SetupTransfer)  (uint8_t  *data,
                                          uint32_t block_count,
                                          uint32_t block_size,
                                          ARM_MCI_TRANSFER_MODE mode);     ///< Pointer to \ref ARM_MCI_SetupTransfer : Setup transfer operation.
  ARM_MCI_STATUS       (*ReadTransfer)   (uint8_t  *data,
                                          uint32_t block_count,
                                          uint32_t block_size);            ///< Pointer to \ref ARM_MCI_ReadTransfer : Perform read transfer.
  ARM_MCI_STATUS       (*WriteTransfer)  (uint8_t  *data,
                                          uint32_t block_count,
                                          uint32_t block_size);            ///< Pointer to \ref ARM_MCI_WriteTransfer : Perform write transfer.
  ARM_MCI_STATUS       (*AbortTransfer)  (void);                           ///< Pointer to \ref ARM_MCI_AbortTransfer : Abort current read/write transfer.
} const ARM_DRIVER_MCI;


#endif /* __DRIVER_MCI_H */

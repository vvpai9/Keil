/********************************************************************************/
/* Copyright @ 2004 by austriamicrosystems AG                                   */
/* All rights are reserved. Reproduction in whole or in part is                 */
/* prohibited without the written consent of the copyright owner.               */
/* austriamicrosystems reserves the right to make changes without notice at     */
/* any time. The software is provided as is and austriamicrosystems makes       */
/* no warranty, expressed, implied or statutory, including but not limited to   */
/* any implied warranty of merchantability or fitness for any particular        */
/* purpose, or that the use will not infringe any third party patent, copyright */
/* or trademark. Austriamicrosystems should not be liable for any loss or       */
/* damage arising from its use.                                                 */
/********************************************************************************/

/**
 *        PROJECT: AS353x
 *      COPYRIGHT: austriamicrosystems 2004
 *      $Revision: 759 $
 *          $Date: 2007/03/05 12:13:51 $
 *         AUTHOR: P. Marinsek
 *     SUBSTITUTE: M. Barjaktarevic
 *       LANGUAGE: C
 *    DESCRIPTION: MMC/SD - PrimeCell PL180 HW layer
 *
 **/

#ifndef _SD_HW_DRIVER_H_
#define _SD_HW_DRIVER_H_

#include "ams_types.h"

/* ------------------------------- defines ----------------------------------- */

/* block lenght on cards: */
#define SD_BLOCK_LENGTH_POW_2   9
#define SD_BLOCK_LENGTH         (1 << SD_BLOCK_LENGTH_POW_2)

/* PL180 constraint: data count register is 16bit wide, so up to 0xffff bytes
   can be transferred in one read or write request */
#define SD_MAX_TRANSFER (1024 * 64)

/*
 * Description:
 * The register offsets for the MMC controller registers are defined
 * below:
 */
#define MCI_REG_POWER        ( (UWORD32) 0)
#define MCI_REG_CLOCK        ( (UWORD32) 1)
#define MCI_REG_ARGUMENT     ( (UWORD32) 2)
#define MCI_REG_COMMAND      ( (UWORD32) 3)
#define MCI_REG_RESPCMD      ( (UWORD32) 4)
#define MCI_REG_RESPONSE0    ( (UWORD32) 5)
#define MCI_REG_RESPONSE1    ( (UWORD32) 6)
#define MCI_REG_RESPONSE2    ( (UWORD32) 7)
#define MCI_REG_RESPONSE3    ( (UWORD32) 8)
#define MCI_REG_DATATIMER    ( (UWORD32) 9)
#define MCI_REG_DATALENGTH   ( (UWORD32) 10)
#define MCI_REG_DATACTRL     ( (UWORD32) 11)
#define MCI_REG_DATACNT      ( (UWORD32) 12)
#define MCI_REG_STATUS       ( (UWORD32) 13)
#define MCI_REG_CLEAR        ( (UWORD32) 14)
#define MCI_REG_MASK0        ( (UWORD32) 15)
#define MCI_REG_MASK1        ( (UWORD32) 16)
#define MCI_REG_SDSELECT     ( (UWORD32) 17)
#define MCI_REG_FIFOCNT      ( (UWORD32) 18)
#define MCI_REG_FIFO         ( (UWORD32) 32)

/*
 * Description:
 * This macro refers to the Nth register of block at __B
 */
#define MCI_REG_ADDR(__REG) (REGISTER_BASE_SD_MCI + (MCI_REG_##__REG << 2))
#define MCI_REGISTER(__REG) (* ((volatile UWORD32 *) MCI_REG_ADDR(__REG)))

/*
 * Description:
 * Bit masks for Status register
 */
#define MCI_STATUS_CMDCRCFAIL       ( (UWORD32) 0x000001)
#define MCI_STATUS_DATACRCFAIL      ( (UWORD32) 0x000002)
#define MCI_STATUS_CMDTIMEOUT       ( (UWORD32) 0x000004)
#define MCI_STATUS_DATATIMEOUT      ( (UWORD32) 0x000008)
#define MCI_STATUS_TXUNDERRUN       ( (UWORD32) 0x000010)
#define MCI_STATUS_RXOVERRUN        ( (UWORD32) 0x000020)
#define MCI_STATUS_CMDRESPEND       ( (UWORD32) 0x000040)
#define MCI_STATUS_CMDSENT          ( (UWORD32) 0x000080)
#define MCI_STATUS_DATAEND          ( (UWORD32) 0x000100)
#define MCI_STATUS_STARTBITERR      ( (UWORD32) 0x000200)
#define MCI_STATUS_DATABLOCKEND     ( (UWORD32) 0x000400)
#define MCI_STATUS_CMDACTIVE        ( (UWORD32) 0x000800)
#define MCI_STATUS_TXACTIVE         ( (UWORD32) 0x001000)
#define MCI_STATUS_RXACTIVE         ( (UWORD32) 0x002000)
#define MCI_STATUS_TXFIFOHALFEMPTY  ( (UWORD32) 0x004000)
#define MCI_STATUS_RXFIFOHALFFULL   ( (UWORD32) 0x008000)
#define MCI_STATUS_TXFIFOFULL       ( (UWORD32) 0x010000)
#define MCI_STATUS_RXFIFOFULL       ( (UWORD32) 0x020000)
#define MCI_STATUS_TXFIFOEMPTY      ( (UWORD32) 0x040000)
#define MCI_STATUS_RXFIFOEMPTY      ( (UWORD32) 0x080000)
#define MCI_STATUS_TXDATAAVLBL      ( (UWORD32) 0x100000)
#define MCI_STATUS_RXDATAAVLBL      ( (UWORD32) 0x200000)
/*this mask is all the static (clearable) bits*/
#define MCI_STATUS_STATIC_MASK      ( (UWORD32) 0x0007FF)

/*this mask is all bits which will generate a command interrupt*/
#define MCI_STATUS_CMD_INT_MASK    ( MCI_STATUS_CMDCRCFAIL | MCI_STATUS_CMDTIMEOUT | \
                                      MCI_STATUS_CMDSENT    | MCI_STATUS_CMDRESPEND )
/*this mask is all bits which will generate a data error*/
#define MCI_STATUS_DATA_ERR_MASK   ( MCI_STATUS_DATATIMEOUT | MCI_STATUS_RXOVERRUN   | \
                                      MCI_STATUS_STARTBITERR | MCI_STATUS_DATACRCFAIL | \
                                      MCI_STATUS_TXUNDERRUN)
/*this mask is all bits which will generate a fifo data interrupt*/
#define MCI_STATUS_DATA_FIFO_MASK  ( MCI_STATUS_TXFIFOEMPTY | MCI_STATUS_TXFIFOHALFEMPTY | \
                                      MCI_STATUS_RXFIFOFULL  | MCI_STATUS_RXFIFOHALFFULL  | \
                                      MCI_STATUS_RXDATAAVLBL)
/*this mask is all bits which will generate a data interrupt*/
#define MCI_STATUS_DATA_INT_MASK   ( MCI_STATUS_DATA_ERR_MASK   | MCI_STATUS_DATAEND     | \
                                      MCI_STATUS_DATABLOCKEND    | MCI_STATUS_TXFIFOEMPTY | \
                                      MCI_STATUS_TXFIFOHALFEMPTY | MCI_STATUS_RXFIFOFULL  | \
                                      MCI_STATUS_RXFIFOHALFFULL  | MCI_STATUS_RXDATAAVLBL )

/*
 * Description:
 * Bit offsets and masks for Power Control register
 */
#define bsMCI_POWER_CTRL       ( (UWORD32) 0)   /*power mode*/
#define bwMCI_POWER_CTRL       ( (UWORD32) 2)
#define bsMCI_POWER_VOLTAGE    ( (UWORD32) 2)   /*voltage levels*/
#define bwMCI_POWER_VOLTAGE    ( (UWORD32) 4)
#define bsMCI_POWER_CID        ( (UWORD32) 6)   /*card identification mode*/
#define bwMCI_POWER_CID        ( (UWORD32) 2)

/*
 * Description:
 * Bit offsets and masks for Clock Control register
 */
#define bsMCI_CLOCK_CLKDIV     ( (UWORD32) 0)
#define bwMCI_CLOCK_CLKDIV     ( (UWORD32) 8)
#define bsMCI_CLOCK_MODE       ( (UWORD32) 8)
#define bwMCI_CLOCK_MODE       ( (UWORD32) 2)
#define bsMCI_CLOCK_BYPASS     ( (UWORD32) 10)
#define bwMCI_CLOCK_BYPASS     ( (UWORD32) 1)
#define bsMCI_CLOCK_WIDE       ( (UWORD32) 11)
#define bwMCI_CLOCK_WIDE       ( (UWORD32) 1)

/*
 * Description:
 * This specifies the enable and power save options for the PrimeCell
 * The default mode (apMCI_CLOCK_POWERSAVE) will switch the clock off if unused for
 * a period after a command.
 */
#define MCI_CLOCK_DISABLED  0x00       /*Clock wholly disabled*/
#define MCI_CLOCK_ENABLED   0x01       /*Clock enabled*/
#define MCI_CLOCK_POWERSAVE 0x03       /*Clock running in power save mode - DEFAULT*/

/*
 * Description:
 * This enumerated type defines the power states.
 */
#define MCI_POWER_OFF 0x00
#define MCI_POWER_UP  0x02
#define MCI_POWER_ON  0x03

/*
 * Description:
 * expected responses when sending command
 */
#define MCI_RESPOND_NONE  0
#define MCI_RESPOND_SHORT 1
#define MCI_RESPOND_LONG  3

/*
 * Description:
 * Bit offsets and masks for Command register
 */
#define bsMCI_CMD_INDEX        ( (UWORD32) 0)
#define bwMCI_CMD_INDEX        ( (UWORD32) 6)
#define bsMCI_CMD_RESPONSE     ( (UWORD32) 6)
#define bwMCI_CMD_RESPONSE     ( (UWORD32) 2)
#define bsMCI_CMD_INTERRUPT    ( (UWORD32) 8)
#define bwMCI_CMD_INTERRUPT    ( (UWORD32) 1)
#define bsMCI_CMD_PENDING      ( (UWORD32) 9)
#define bwMCI_CMD_PENDING      ( (UWORD32) 1)
#define bsMCI_CMD_ENABLE       ( (UWORD32) 10)
#define bwMCI_CMD_ENABLE       ( (UWORD32) 1)

/*
 * Description:
 * command options mask values
 */
#define MCI_CMDOPT_IGNORE_CRC      1 /*ignores CRC errors as response will not be used*/
#define MCI_CMDOPT_IGNORE_TIMEOUT  2 /*ignores timeout errors*/
#define MCI_CMDOPT_IMMEDIATE       4

/*
 * Description:
 * Bit offsets and masks for Data registers
 */
#define bsMCI_DATA_LENGTH      ( (UWORD32) 0)
#define bwMCI_DATA_LENGTH      ( (UWORD32) 16)

#define bsMCI_DATA_ENABLE      ( (UWORD32) 0)
#define bwMCI_DATA_ENABLE      ( (UWORD32) 1)
#define bsMCI_DATA_DIRECTION   ( (UWORD32) 1)
#define bwMCI_DATA_DIRECTION   ( (UWORD32) 1)
#define bsMCI_DATA_MODE        ( (UWORD32) 2)
#define bwMCI_DATA_MODE        ( (UWORD32) 1)
#define bsMCI_DATA_DMA_ENABLE  ( (UWORD32) 3)
#define bwMCI_DATA_DMA_ENABLE  ( (UWORD32) 1)
#define bsMCI_DATA_BLOCKSIZE   ( (UWORD32) 4)
#define bwMCI_DATA_BLOCKSIZE   ( (UWORD32) 4)

#define MCI_FIFO_UWORDS        ( (UWORD32) 16)
#define MCI_FIFO_BYTES         ( MCI_FIFO_UWORDS * 4 )

/*
 * Description:
 * Data direction modes (transmit or receive)
 */
#define MCI_DATA_TRANSMIT 0x00        /*Data sent from controller to card*/
#define MCI_DATA_RECEIVE  0x01        /*Data sent from card to controller*/

/*
 * Description:
 * This enumerated type defines the command status and matches the bit
 * pattern for the status register.  The detailed values can be checked
 * or the apMCI_CMDSTAT_PASS and apMCI_CMDSTAT_FAIL values can be used.
 * There is one special cases - CMDSTAT_NOPOWER is returned if power-up
 * has not occurred
 */
#define MCI_CMDSTAT_FAIL (MCI_STATUS_CMDCRCFAIL | MCI_STATUS_CMDTIMEOUT)

/*
 * Description:
 * These are the two return types for long/short responses.  It is up
 * to the user to interpret a response in the light of the command sent
 */
typedef union
{
    uint32 rLong[4];           /*long (4 word) format*/
    uint32 rShort;              /*short (1 word) format*/
} mciResponse_t;

typedef enum
{
    MCI_RESULT_OK = 0,
    MCI_RESULT_BUSY,
    MCI_RESULT_ERROR
} mciResult_t;

typedef void (*mciCallBackFn_t)(uint32 status, mciResponse_t *response);



#ifdef __cplusplus
extern "C" { /* allow C++ to use these headers */
#endif /* __cplusplus */

/**
  *   FUNCTION: mciInitialise
  *
  *    PURPOSE: initializes clocks, DMA, PrimeCell's registers
  *
  *  PARAMETER: /
  *
  *    RETURNS: /
 **/
int mciInitialise(void);

/**
  *   FUNCTION: mciDeinitialise
  *
  *    PURPOSE: deinitializes clocks, DMA, PrimeCell's registers
  *
  *  PARAMETER: /
  *
  *    RETURNS: /
 **/
void mciDeinitialise(void);

/**
  *   FUNCTION: mciSendCommand
  *
  *    PURPOSE: waits previous command is finished then sends new command to card
  *
  *  PARAMETER: cmdIndex     - command index
  *             cmdArgument  - command's attribute
  *         expectedResponse - expected response
  *               optionMask - options
  *
  *    RETURNS: 0 - success
 **/
int mciSendCommand(uint32 cmdIndex, uint32 cmdArgument, uint32 expectedResponse, uint32 optionMask);

/**
  *   FUNCTION: mciWriteData
  *
  *    PURPOSE: setup DMA to start coping data from buffer to card
  *
  *  PARAMETER: srcAddress - ponter to source buffer
  *             srcCount   - bytes to transfer
  *
  *    RETURNS: MCI_RESULT_ERROR - error
  *             MCI_RESULT_BUSY  - DMA currently busy, but a cmd call back will be
  *                                triggered when becomes ready
  *             MCI_RESULT_OK    - OK
 **/
mciResult_t mciWriteData(uint32 *srcAddress, uint32 srcCount);

/**
  *   FUNCTION: mciReadData
  *
  *    PURPOSE: setup DMA to start coping data form card to buffer
  *
  *  PARAMETER: dstAddress - ponter to destination buffer
  *             dstCount   - bytes to transfer
  *
  *    RETURNS: MCI_RESULT_ERROR - error
  *             MCI_RESULT_BUSY  - DMA currently busy, but a cmd call back will be
  *                                triggered when becomes ready
  *             MCI_RESULT_OK    - OK
 **/
mciResult_t mciReadData(uint32 *dstAddress, uint32 dstCount);

/**
  *   FUNCTION: mciStopDataTransfer
  *
  *    PURPOSE: stop data transfer and if error occured, release DMA channel
  *
  *  PARAMETER: transferError - set to TRUE if data flow did not finish (was interrupted)
  *
  *    RETURNS: /
 **/
void mciStopDataTransfer(uint transferError);

/**
  *   FUNCTION: mciAbortDataTransfer
  *
  *    PURPOSE: unconditional abort of data transfer. Do not release DMA channel
  *             because a new transfer request on same channel will follow
  *
  *  PARAMETER: /
  *
  *    RETURNS: bytes already transferred from last transfer request up to now
 **/
uint32 mciAbortDataTransfer(void);

/**
  *   FUNCTION: mciIsCardBusy
  *
  *    PURPOSE: poll driver status
  *
  *  PARAMETER: /
  *
  *    RETURNS: 0  - READY
  *             !0 - BUSY
 **/
uint32 mciIsCardBusy(void);

/**
  *   FUNCTION: mciRegisterCallback
  *
  *    PURPOSE: register callback which will be called at each interrupt
  *
  *  PARAMETER: fnCallBack - pointer to callbac function
  *
  *    RETURNS: pointer to previously registered callback
 **/
mciCallBackFn_t mciRegisterCallback(mciCallBackFn_t fnCallBack);

/**
  *   FUNCTION: mciSetDataBusWidth
  *
  *    PURPOSE: set data bus width to 1 or 4
  *
  *  PARAMETER: width - bus width in bits (1 or 4)
  *
  *    RETURNS: 0  - success
  *             !0 - data width not supported
 **/
int mciSetDataBusWidth(uint32 width);

/**
  *   FUNCTION: mciGetStatus
  *
  *    PURPOSE: read last status
  *
  *  PARAMETER: /
  *
  *    RETURNS: PrimeCell status
 **/
uint32 mciGetStatus(void);

/**
  *   FUNCTION: mciSetDataTimeOut
  *
  *    PURPOSE: calculate and apply data timeout in ms
  *
  *  PARAMETER: ms - desired data timeout
  *
  *    RETURNS: /
 **/
void mciSetDataTimeOut(uint32 ms);

/**
  *   FUNCTION: mciSetSdClockRate
  *
  *    PURPOSE: apply new clock frequency to inserted card
  *
  *  PARAMETER: newFrequency - frequency in Hz. If 0, then previous freq. is
  *                            recalculated and applied (usefull when BUS freq. changes)
  *
  *    RETURNS: /
 **/
void mciSetSdClockRate(uint32 clockRate);

/**
  *   FUNCTION: mciApplyNewBusClock
  *
  *    PURPOSE: apply new BUS frequecy and apply recalculated card frequency
  *
  *  PARAMETER: frequency - new BUS frequency in Hz
  *
  *    RETURNS: CGU_OK - OK
 **/
sint mciApplyNewBusClock(uint32 frequency);

#ifdef __cplusplus
} /* allow C++ to use these headers */
#endif /* __cplusplus */

#endif /* _SD_HW_DRIVER_H_ */



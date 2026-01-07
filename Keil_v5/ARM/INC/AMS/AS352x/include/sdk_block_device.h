/*
 *****************************************************************************
 * Copyright @ 2007 by austriamicrosystems AG                                *
 * All rights are reserved.                                                  *
 *                                                                           *
 * Reproduction in whole or in part is prohibited without the written consent*
 * of the copyright owner. Austriamicrosystems reserves the right to make    *
 * changes without notice at any time. The software is provided as is and    *
 * Austriamicrosystems makes no warranty, expressed, implied or statutory,   *
 * including but not limited to any implied warranty of merchantability or   *
 * fitness for any particular purpose, or that the use will not infringe any *
 * third party patent, copyright or trademark. Austriamicrosystems should    *
 * not be liable for any loss or damage arising from its use.                *
 *****************************************************************************
 */

/*
 *      PROJECT:   AS353x
 *      $Revision: 759 $
 *      LANGUAGE:  ANSI C
*/

/*! \file
 *
 *  \author M. Arpa
 *  \author H. Treml (Substitute)
 *
 *  \brief Common interface declaration for all block device driver.
 *  
 *  Common interface declaration for all block device driver.
 *
 */

#ifndef _SDK_BLOCK_DEVICE_H_
#define _SDK_BLOCK_DEVICE_H_

/*
******************************************************************************
* INCLUDES
******************************************************************************
*/

#include "ams_types.h"
#include "apos.h"


#ifdef __cplusplus
extern "C" {        /* allow C++ to use these headers */
#endif /* __cplusplus */

/*
******************************************************************************
* DEFINES
******************************************************************************
*/

/*
******************************************************************************
* GLOBAL MACROS
******************************************************************************
*/

/*
******************************************************************************
* GLOBAL DATA TYPES
******************************************************************************
*/

/**
 * Define new type names for all functions that are common in all block
 * device drivers. 
 **/
typedef apError     (*blkDevInitialise)            ( void );
typedef apError     (*blkDevDeinitialise)          ( void );
typedef apError     (*blkDevReset)                 ( void );
typedef uint32      (*blkDevLogicalBlockSize)      ( void );
typedef uint32      (*blkDevMaxLogicalBlock)       ( void );
typedef sint        (*blkDevIsMediaRemovable)      ( void );
typedef sint        (*blkDevIsMediaConnected)      ( void );
typedef apError     (*blkDevGetError)              ( void );
typedef void        (*blkDevClrError)              ( void );
typedef apError     (*blkDevReadNBlockSetup)
                        ( uint32 srcLogicalBlockAddressOnDevice
                        );
typedef apError     (*blkDevReadNBlockNext)
                        ( void * dstAddress
                        , uint32 numberOfLogicalBlocksToRead 
                        );
typedef apError     (*blkDevReadNBlockFlush)       ( void );
typedef sint32      (*blkDevIsReadDone)            ( void );
typedef uint32      (*blkDevNumberOfBlocksRead)    ( void );
typedef apError     (*blkDevWriteNBlockSetup)
                        ( uint32 destLogicalBlockAddressOnDevice 
                        );
typedef apError     (*blkDevWriteNBlockNext)
                        ( void * srcAddress
                        , uint32 numberOfLogicalBlocksToWrite 
                        );
typedef apError     (*blkDevWriteNBlockFlush)      ( void );
typedef sint32      (*blkDevIsWriteDone)           ( void );
typedef uint32      (*blkDevNumberOfBlocksWritten) ( void );
typedef devCallBack (*blkDevSetCallBack) 
                        ( devCallBack callBackFunction 
                        );
typedef apError     (*blkDevOpenSession)           ( void );
typedef apError     (*blkDevCloseSession)          ( void );


/* --------------- structures --------------------------------------- */


/**
 * Definition of the function poiner table that must be provided by
 * all block device drivers in the system.
 * An instance of the function pointer table for each device
 * driver is provided through a function of the device driver.
 **/
typedef struct _blkDevFunctionTable
{
    /**
     * Functions for device reset, initialisation and deinitialisation.
     * Will perform the  disabling/enabling of clock gating, registration of
     * the ISR at the VIC, etc.
     **/
    blkDevInitialise            initialiseFn;
    blkDevDeinitialise          deinitialiseFn;
    blkDevReset                 resetFn;

    /**
     * Information functions that are necessary to find out the size of 
     * the attached media, the state of the media, etc.
     **/
    blkDevLogicalBlockSize      logicalBlockSizeFn;
    blkDevMaxLogicalBlock       maxLogicalBlockFn;
    blkDevIsMediaRemovable      isMediaRemovableFn;
    blkDevIsMediaConnected      isMediaConnectedFn;

    /**
     * Functions to get the last error that occured since the last time
     * the error condition was cleared. Note that an error must be 
     * explicitly cleared and is not cleared through a read only.
     **/
    blkDevGetError              getErrorFn;
    blkDevClrError              clrErrorFn;

    /**
     * Function to read data from the device. A series of sequential
     * reads should be implemented by calling:
     *     readNBlockSetupFn 
     *     readNBlockNextFn
     *     readNBlockNextFn
     *     ...
     *     readNBlockNextFn
     *     readNBlockFlushFn
     **/
    blkDevReadNBlockSetup       readNBlockSetupFn;
    blkDevReadNBlockNext        readNBlockNextFn;
    blkDevReadNBlockFlush       readNBlockFlushFn;
    blkDevIsReadDone            isReadDoneFn;
    blkDevNumberOfBlocksRead    numberOfBlocksReadFn;
                                
    /**
     * Function to write data to the device. A series of sequential
     * writes should be implemented by calling:
     *     writeNBlockSetupFn 
     *     writeNBlockNextFn
     *     writeNBlockNextFn
     *     ...
     *     writeNBlockNextFn
     *     writeNBlockFlushFn
     **/
    blkDevWriteNBlockSetup      writeNBlockSetupFn;
    blkDevWriteNBlockNext       writeNBlockNextFn;
    blkDevWriteNBlockFlush      writeNBlockFlushFn;
    blkDevIsWriteDone           isWriteDoneFn;
    blkDevNumberOfBlocksWritten numberOfBlocksWrittenFn;
    
    /**
     * When a transfer is completed the user can be informed about this.
     * The call back function will be called by the driver.
     * Note that the function will be called from within an ISR!
     **/
    blkDevSetCallBack           setCallBackFn;
    
    /**
     * Functions to be called to start or stop a session. A session means
     * that any read/write operation shall be finished when stopping a 
     * session.
     **/
    blkDevOpenSession           openSessionFn;   
    blkDevCloseSession          closeSessionFn;    

} blkDevFunctionTable;


#ifdef __cplusplus
} /* allow C++ to use these headers */
#endif /* __cplusplus */

#endif /* _SDK_BLOCK_DEVICE_H_ */



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
 *  \author W. Schoegler (Substitute)
 *
 *  \brief Definition of events
 *  
 *  Definition of events used by 
 *  * device drivers
 *  * file system
 *
 */

#ifndef _AS3525_EVENTS_H_
#define _AS3525_EVENTS_H_

/*
******************************************************************************
* INCLUDES
******************************************************************************
*/

/*
******************************************************************************
* DEFINES
******************************************************************************
*/


/**
 * The task which calls a file system function of the device driver will
 * be suspended and awaked with the events specified here.
 * The suspended task can either be the file system daemon (when non-blocking
 * io is used) or the task which called a block file system function (e.g.
 * fopen, fclose, fread, fwrite).
 * All device driver shall use the same event.
 **/
#define EVENT_FS_IO_READY        0x80

#define FS_IDE_IO_READY                 (EVENT_FS_IO_READY)
#define FS_MMC_IO_READY                 (EVENT_FS_IO_READY)
#define FS_MMC_DMA_CHANNEL_READY        (EVENT_FS_IO_READY)
#define FS_NAF_IO_READY                 (EVENT_FS_IO_READY)

#define FS_MST_IO_READY                 (EVENT_FS_IO_READY)
#define FS_MST_DMA_CHANNEL_READY        (EVENT_FS_IO_READY)
#define EVENT_ADC_IO_READY              (EVENT_FS_IO_READY)

#define USB_CHANGED_EVENT               (EVENT_FS_IO_READY)
#define RTC_CHANGED_EVENT               (0x1<<6)


#endif /* _AS3525_EVENTS_H_ */




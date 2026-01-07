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
 *  \author M. Steinberger
 *  \author M. Arpa (Substitute)
 *
 *  \brief Configuration file for the NAF Types.
 *  
 *  Configuration file for the NAF Types.
 *  Specify here the:
 *  - all supported NAF flash types with their parameters
 *
 */


#ifndef _SDK_NAF_CONFIG_H_
#define _SDK_NAF_CONFIG_H_

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
/*----------------------------------------------------------------------*/
/* NAF Configuration                                                    */
/*----------------------------------------------------------------------*/

/* if chips do not start at line 0 set the number here */
#ifndef SDK_NAF_CHIP_SELECT_OFFSET
   #define SDK_NAF_CHIP_SELECT_OFFSET 0 
#endif

/**
 * For each new Flash the following defines must be set to the appropriate
 * values (check the datasheet of the flash to find the correct values);
 *
 *  #define NAF_PAGES_PER_BLOCK         e.g. 64
 *  #define NAF_PAGE_SIZE_IN_BYTES      e.g. 2048
 *  #define NAF_SPARE_SIZE_IN_BYTES     e.g. 64
 *  #define NAF_MAX_PHY_BLOCK           e.g. 4096
 *  #define NAF_NUM_ADDR_CYCLES         e.g. 5
 *  #define NAF_DEVICE_CODE0            
 *  #define NAF_DEVICE_CODE1            
 *  #define NAF_IS_X16                  e.g. 1
 *  #define NAF_ASSOC_BITS              e.g. 5
 *  #define NAF_SUPPORT_CACHE           e.g. 1
 *  #define NAF_SUPPORT_COPY_BACK       e.g. 1
 *  #define NAF_IS_BIG_BLOCK            e.g. 1
 *  #define NAF_ADDITIONAL_INVALID_BLOCK_INFO_IN_PAGE  e.g 1
 **/


#if ( SDK_NAND_FLASH_TYPE == SDK_NAND_64MB_SB )   /* Samsung K9F1208U0M:  64MB, ID: 0xEC 0x76 0xA5 0xC0 */

    #define NAF_PAGES_PER_BLOCK              32
    #define NAF_PAGE_SIZE_IN_BYTES          512
    #define NAF_SPARE_SIZE_IN_BYTES          16
    #define NAF_MAX_PHY_BLOCK              4096
    #define NAF_MAX_BAD_BLOCK                70
    #define NAF_NUM_ADDR_CYCLES               4
    #define NAF_ASSOC_BITS                    5
    #define NAF_IS_BIG_BLOCK                  0
    #define NAF_ADDITIONAL_INVALID_BLOCK_INFO_IN_PAGE 1 

#elif ( SDK_NAND_FLASH_TYPE == SDK_NAND_128MB_SB )/* Samsung K9K1G08U0B:  128MB, ID: 0xEC 0x79 0xA5 0xC0 */

    #define NAF_PAGES_PER_BLOCK              32
    #define NAF_PAGE_SIZE_IN_BYTES          512
    #define NAF_SPARE_SIZE_IN_BYTES          16
    #define NAF_MAX_PHY_BLOCK              8192
    #define NAF_MAX_BAD_BLOCK               140
    #define NAF_NUM_ADDR_CYCLES               4
    #define NAF_ASSOC_BITS                    6
    #define NAF_IS_BIG_BLOCK                  0
    #define NAF_ADDITIONAL_INVALID_BLOCK_INFO_IN_PAGE 1

#elif ( SDK_NAND_FLASH_TYPE == SDK_NAND_128MB_BB )         

    #define NAF_PAGES_PER_BLOCK              64
    #define NAF_PAGE_SIZE_IN_BYTES         2048
    #define NAF_SPARE_SIZE_IN_BYTES          64
    #define NAF_MAX_PHY_BLOCK              1024
    #define NAF_MAX_BAD_BLOCK                20
    #define NAF_NUM_ADDR_CYCLES               4
    #define NAF_ASSOC_BITS                    3
    #define NAF_ADDITIONAL_INVALID_BLOCK_INFO_IN_PAGE 1  
   
#elif ( SDK_NAND_FLASH_TYPE == SDK_NAND_256MB_BB )         /* Samsung K9F2G08UOM  256MB, ID: 0xEC 0xDA 0x80 0x15 */

    #define NAF_PAGES_PER_BLOCK              64
    #define NAF_PAGE_SIZE_IN_BYTES         2048
    #define NAF_SPARE_SIZE_IN_BYTES          64
    #define NAF_MAX_PHY_BLOCK              2048
    #define NAF_MAX_BAD_BLOCK                40
    #define NAF_NUM_ADDR_CYCLES               5
    #define NAF_ASSOC_BITS                    4
    #define NAF_SUPPORT_CACHE                 0     /* 1 == support, 0 == not supported
                                                      not supported by Application Board V2.1, 
                                                      a hardware patch is needed (WP must be always on VDD) */
    #define NAF_SUPPORT_COPY_BACK             1     
    #define NAF_ADDITIONAL_INVALID_BLOCK_INFO_IN_PAGE 1 


#elif ( SDK_NAND_FLASH_TYPE == SDK_NAND_512MB_BB )         

    #define NAF_INTERLEAVE_BITS               1
    #define NAF_PAGES_PER_BLOCK             128
    #define NAF_PAGE_SIZE_IN_BYTES         2048
    #define NAF_SPARE_SIZE_IN_BYTES          64
    #define NAF_MAX_PHY_BLOCK              2048
    #define NAF_MAX_BAD_BLOCK                80
    #define NAF_NUM_ADDR_CYCLES               5
    #define NAF_ASSOC_BITS                    4
    #define NAF_SUPPORT_COPY_BACK             1    
    #define NAF_SUPPORT_EDC                   1   
    #define NAF_ADDITIONAL_INVALID_BLOCK_INFO_IN_PAGE 3
                                                       
#elif ( SDK_NAND_FLASH_TYPE == SDK_NAND_1024MB_BB )         

    #define NAF_INTERLEAVE_BITS               2
    #define NAF_PAGES_PER_BLOCK           (64*4)
    #define NAF_PAGE_SIZE_IN_BYTES         2048
    #define NAF_SPARE_SIZE_IN_BYTES          64
    #define NAF_MAX_PHY_BLOCK           (8192/4)
    #define NAF_MAX_BAD_BLOCK               160
    #define NAF_NUM_ADDR_CYCLES               5
    #define NAF_ASSOC_BITS                    4
    #define NAF_SUPPORT_COPY_BACK             1  
    #define NAF_SUPPORT_EDC                   1 
    #define NAF_ADDITIONAL_INVALID_BLOCK_INFO_IN_PAGE 7
    #define SDK_NAF_LOSS_MULTIPLIER        2 /* 1 block to add per bootblock for loss */

#elif ( SDK_NAND_FLASH_TYPE == SDK_NAND_1024MB_BB_MLC )         

    #define NAF_PAGES_PER_BLOCK             128
    #define NAF_PAGE_SIZE_IN_BYTES         2048
    #define NAF_SPARE_SIZE_IN_BYTES          64
    #define NAF_MAX_PHY_BLOCK              4160
    #define NAF_MAX_BAD_BLOCK               224
    #define NAF_NUM_ADDR_CYCLES               5
    #define NAF_ASSOC_BITS                    0
    #define NAF_ADDITIONAL_INVALID_BLOCK_INFO_IN_PAGE 1
    #define NAF_SUPPORT_MLC                   1
    #define NAF_SLC_BLOCKS                  256 /* Give about 32 MB fast SLC blocks for FAT, db and hds */
    #define NAF_SUPPORT_CACHE                 1     /* 1 == support, 0 == not supported
                                                      not supported by Application Board V2.1, 
                                                      a hardware patch is needed (WP must be always on VDD) */
                                                      
#elif ( SDK_NAND_FLASH_TYPE == SDK_NAND_2048MB_BB_MLC )         

    #define NAF_PAGES_PER_BLOCK             128
    #define NAF_PAGE_SIZE_IN_BYTES         2048
    #define NAF_SPARE_SIZE_IN_BYTES          64
    #define NAF_MAX_PHY_BLOCK              8192
    #define NAF_MAX_BAD_BLOCK               200
    #define NAF_NUM_ADDR_CYCLES               5
    #define NAF_ASSOC_BITS                    0
    #define NAF_ADDITIONAL_INVALID_BLOCK_INFO_IN_PAGE 127
    #define NAF_SUPPORT_MLC                   1

#elif ( SDK_NAND_FLASH_TYPE == SDK_NAND_2048MB_BB_MLC_T56 ) /* Toshiba 2GB MLC 56nm - TC58NVG4D1DTG00 */

    #define NAF_PAGES_PER_BLOCK             128
    #define NAF_PAGE_SIZE_IN_BYTES         4096
    #define NAF_SPARE_SIZE_IN_BYTES         128 /* FIXME msb: instead of 218 spare bytes, do a macro to check max. fifo size */
    #define NAF_MAX_PHY_BLOCK              4096
    #define NAF_MAX_BAD_BLOCK               160
    #define NAF_NUM_ADDR_CYCLES               5
    #define NAF_ASSOC_BITS                    0
    #define NAF_ADDITIONAL_INVALID_BLOCK_INFO_IN_PAGE 127
    #define NAF_SUPPORT_MLC                   1
    #define NAF_SUPPORT_4K_PAGES              1
    #define NAF_SUPPORT_CACHE                 1     /* 1 == support, 0 == not supported
                                                      not supported by Application Board V2.1, 
                                                      a hardware patch is needed (WP must be always on VDD) */
    
#else

   #error "Unsupported NAND flash type";
   
#endif   

/* default values for not set variables */
#ifndef NAF_INTERLEAVE_BITS
    #define NAF_INTERLEAVE_BITS               0
#endif
#ifndef NAF_SUPPORT_CACHE
    #define NAF_SUPPORT_CACHE                 0  
#endif
#ifndef NAF_SUPPORT_COPY_BACK
    #define NAF_SUPPORT_COPY_BACK             0   
#endif
#ifndef NAF_SUPPORT_EDC
    #define NAF_SUPPORT_EDC                   0
#endif
#ifndef NAF_IS_X16
    #define NAF_IS_X16                        0   
#endif 
#ifndef NAF_IS_BIG_BLOCK
    #define NAF_IS_BIG_BLOCK                  1
#endif 
#ifndef SDK_NAF_LOSS_MULTIPLIER
    #define SDK_NAF_LOSS_MULTIPLIER        1 /* nothing to add for loss */
#endif
#ifndef NAF_SUPPORT_MLC
    #define NAF_SUPPORT_MLC                   0
#endif
#ifndef NAF_SUPPORT_4K_PAGES
    #define NAF_SUPPORT_4K_PAGES              0
#endif
#ifndef NAF_SLC_BLOCKS
    #define NAF_SLC_BLOCKS                    0
#endif

/**
 * The following values are calculated by the pre-processor.
 **/
#define SDK_NAF_BLOCK_SIZE_IN_BYTES    ( (NAF_PAGE_SIZE_IN_BYTES) * (NAF_PAGES_PER_BLOCK) )
#define NAF_SPARE_SIZE_IN_WORDS    ( (NAF_SPARE_SIZE_IN_BYTES) / sizeof(uint32) )

/**
 * The following checks are to avoid incompatible configurations
 **/
#if ( (NAF_SUPPORT_COPY_BACK == 0) && (NAF_SUPPORT_EDC != 0) )
    #error "Cannot have EDC without Copy-Back support.";
#endif

#endif /* _SDK_NAF_CONFIG_H_ */



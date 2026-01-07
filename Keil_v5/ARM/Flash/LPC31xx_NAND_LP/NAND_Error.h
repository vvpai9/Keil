/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright KEIL ELEKTRONIK GmbH 2003 - 2006                         */
/***********************************************************************/
/*                                                                     */
/*  NAND_Error.H   NAND Flash error definitions                        */
/*                                                                     */
/***********************************************************************/

/* Error values that functions can return                                    */
typedef enum   
{ NAND_OK = 0,                      /* No error                              */
  NAND_NOT_IMPLEMENTED_ERROR,       /* Functionality has not been implemented*/
  NAND_NOT_ALLOWED_ERROR,           /* Function does not allow that operation*/
  NAND_INTERFACE_ERROR,             /* Interface with NAND flash error       */
  NAND_ECC_ERROR,                   /* ECC can not repair bit errors         */
  NAND_BAD_BLOCK_ERROR,             /* Accessed block is bad                 */
} NAND_ERROR;

#if !defined (_FLASH470_ERROR_DDEFINES_H_)
   #define _FLASH470_ERROR_DDEFINES_H_

   typedef enum
   {
      FAPI_ERROR_CODE_SUCCESS,                 // Function completed successfully
      FAPI_ERROR_CODE_FAIL,                    // Generic Function Fail code
      FAPI_ERROR_CODE_STATE_MACHINE_TIMEOUT,   // State machine polling never returned ready and timed out
      FAPI_ERROR_CODE_OTP_CHECKSUM_MISMATCH,   // Returned if OTP checksum does not match expected value
      FAPI_ERROR_CODE_INVALID_DELAY_VALUE,     // Returned if the Calculated RWAIT value exceeds 15
      FAPI_ERROR_CODE_INVALID_CORE             // Returned if the specified core does not exist
   } FAPI_ERROR_CODE;
#endif // #if defined (_FLASH470_ERROR_DDEFINES_H_)

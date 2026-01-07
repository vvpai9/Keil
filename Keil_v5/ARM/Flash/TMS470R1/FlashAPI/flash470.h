typedef int BOOL;
typedef unsigned char UBYTE;
typedef unsigned short int UINT16;
typedef unsigned long int UINT32;

#define FALSE 0
#define TRUE 1

typedef struct
{ UINT32 stat1;
  UINT32 stat2;
  UINT32 stat3;
  UINT32 stat4;
} FLASH_STATUS_ST;

typedef struct
{ UINT32 DevID;
  UINT32 LotNo;
  UINT16 FlowCheck;
  UINT16 WaferNo;
  UINT16 Xcoord;
  UINT16 Ycoord;
} FLASH_ENGR_INFO_ST;

typedef volatile UINT32 * FLASH_ARRAY_ST;

#ifdef F05
typedef enum
{ FLASH_CORE0,FLASH_CORE1,FLASH_CORE2,FLASH_CORE3,
  FLASH_CORE4,FLASH_CORE5,FLASH_CORE6,FLASH_CORE7
}  FLASH_CORE;

typedef enum
{ FLASH_SECT0, FLASH_SECT1, FLASH_SECT2, FLASH_SECT3, FLASH_SECT4, FLASH_SECT5, FLASH_SECT6, FLASH_SECT7,
  FLASH_SECT8, FLASH_SECT9, FLASH_SECT10, FLASH_SECT11, FLASH_SECT12, FLASH_SECT13, FLASH_SECT14, FLASH_SECT15,
  FLASH_SECT16, FLASH_SECT17, FLASH_SECT18, FLASH_SECT19, FLASH_SECT20, FLASH_SECT21, FLASH_SECT22, FLASH_SECT23,
  FLASH_SECT24, FLASH_SECT25, FLASH_SECT26, FLASH_SECT27, FLASH_SECT28, FLASH_SECT29, FLASH_SECT30, FLASH_SECT31
} FLASH_SECT;

#else
typedef enum
{ FLASH_CORE0, FLASH_CORE1, FLASH_CORE2, FLASH_CORE3
}  FLASH_CORE;

typedef enum
{ FLASH_SECT0, FLASH_SECT1, FLASH_SECT2, FLASH_SECT3
} FLASH_SECT;
#endif

UINT16 Flash_API_Version_U16(void);

BOOL Flash_Erase_Sector_B (UINT32 *start, UINT32 length, FLASH_CORE core, FLASH_SECT sector,
                           UINT32 delay, FLASH_ARRAY_ST cntl);

BOOL Flash_Blank_B (UINT32 *start, UINT32 length, FLASH_CORE core, FLASH_ARRAY_ST cntl,
                    FLASH_STATUS_ST *status);

BOOL Flash_Compact_B (UINT32 *start, FLASH_CORE core, FLASH_SECT sector, UINT32 delay,
                      FLASH_ARRAY_ST cntl, FLASH_STATUS_ST *status);

BOOL Flash_Erase_B (UINT32 *start, UINT32 length, FLASH_CORE core, FLASH_SECT sector,
                    UINT32 delay, FLASH_ARRAY_ST cntl, FLASH_STATUS_ST *status);

BOOL Flash_Prog_B (UINT32 *start, UINT32 *buffer, UINT32 length, FLASH_CORE core,
                   UINT32 delay, FLASH_ARRAY_ST cntl, FLASH_STATUS_ST *status);

BOOL Flash_Zeros_B (UINT32 *start, UINT32 length, FLASH_CORE core, UINT32 delay,
                   FLASH_ARRAY_ST cntl, FLASH_STATUS_ST *status);

BOOL Flash_Verify_B (UINT32 *start, UINT32 *buffer, UINT32 length, FLASH_CORE core,
                     FLASH_ARRAY_ST cntl, FLASH_STATUS_ST *status);

BOOL Flash_PSA_Verify_B (UINT32 *start, UINT32 length, UINT32 psa, FLASH_CORE core,
                         FLASH_ARRAY_ST cntl, FLASH_STATUS_ST *status);

UINT32 Flash_PSA_Calc_U32 (UINT32 *start, UINT32 length, UINT32 psa_seed, UINT32 mode,
                           FLASH_CORE core, FLASH_ARRAY_ST cntl);

UINT32 PSA_U32 (UINT32 *start, UINT32 length, UINT32 psa_seed);

BOOL Flash_Match_Key_B (volatile UINT32 *key_start, const UINT32 key[], FLASH_ARRAY_ST cntl);

void Flash_Match_Key_V (volatile UINT32 *key_start, const UINT32 key[], FLASH_ARRAY_ST cntl);

#ifndef F05
void Flash_Prog_Key_V (volatile UINT32 *key_start, const UINT32 key[], FLASH_CORE core,
                       UINT32 delay, FLASH_ARRAY_ST cntl);

void Flash_Zero_Key_V (volatile UINT32 *key_start, const UINT32 key[], FLASH_CORE core,
                       UINT32 delay, FLASH_ARRAY_ST cntl);
#endif

void Flash_EngRow_V (UINT32 *start, FLASH_ARRAY_ST cntl, FLASH_STATUS_ST *status);

void Flash_EngInfo_V (UINT32 *start, FLASH_ARRAY_ST cntl, FLASH_ENGR_INFO_ST *info);

#ifdef F05
BOOL OTP_Blank_B (UINT32 *start, UINT32 length, FLASH_CORE core, FLASH_ARRAY_ST cntl,
                  FLASH_STATUS_ST *status);

BOOL OTP_Prog_B (UINT32 *start, UINT32 *buff, UINT32 length, FLASH_CORE core,
                 UINT32 delay, FLASH_ARRAY_ST cntl, FLASH_STATUS_ST *status);

void OTP_Read_V (UINT32 *start, UINT32 *buff, UINT32 length, FLASH_CORE core,
                 FLASH_ARRAY_ST cntl);

BOOL OTP_Verify_B (UINT32 *start, UINT32 *buff, UINT32 length, FLASH_CORE core,
                   FLASH_ARRAY_ST cntl, FLASH_STATUS_ST *status);

BOOL OTP_PSA_Verify_B (UINT32 *start, UINT32 length, UINT32 psa, FLASH_CORE core,
                       FLASH_ARRAY_ST cntl, FLASH_STATUS_ST *status);

void Flash_Set_Vread_V(FLASH_ARRAY_ST cntl);

BOOL Flash_Start_Erase_B (UINT32 *start, FLASH_CORE core, UINT32 delay,
                          FLASH_ARRAY_ST cntl);

UINT16 Flash_Erase_Status_U16 (FLASH_ARRAY_ST cntl);

UINT16 Flash_Aux_Engr_U16(UINT16 *start, FLASH_ARRAY_ST cntl);

void init_state_machine(FLASH_CORE core, UINT32 delay, FLASH_ARRAY_ST cntl);

void Flash_Sector_Select_V(FLASH_CORE core,  FLASH_ARRAY_ST cntl);

void Feed_Watchdog_V(void);

// Added by mangino
void Flash_Track_Pulses_V(FLASH_ARRAY_ST cntl,
			  FLASH_STATUS_ST *status
			  );


#endif

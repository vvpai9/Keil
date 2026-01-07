#if !defined (_FLASH470_H_)
   #define _FLASH470_H_

#include "Flash470ErrorDefines.h"

// define variable types
typedef int BOOL;
typedef unsigned char UBYTE;
typedef unsigned short int UINT16;
typedef unsigned long int UINT32;

// define booleans
   #define FALSE 0
   #define TRUE 1

// define macros

// The PLATFORM flag can be specified in your cl470 CFLAGS as '-dPLATFORM'
// or explicitly in a previous included header file using '#define PLATFORM'
   #if defined (PLATFORM)

// The DUALCPU flag can be specified in your cl470 CFLAGS as '-dDUALCPU'
// or explicitly in a previous included header file using '#define DUALCPU'

      #if defined (DUALCPU)
// using RTI registers
         #define ENA_CLEAN *(volatile UINT32 *)0xfffffc00=0;*(volatile UINT32 *)0xfffffc04=0;
         #define DIS_CLEAN
         #define CLEAN(x) *(volatile UINT32 *)0xfffffc18=x;x=*(volatile UINT32 *)0xfffffc18;
      #else
         #define ENA_CLEAN
         #define DIS_CLEAN
         #define CLEAN(x)
      #endif // #if defined (DUALCPU)

      #define SET_CFG_BIT
      #define CLR_CFG_BIT
      #define READ_FLASH_MEM_U32(a,x) { UINT32 y;x=*(volatile UINT16 *)a;CLEAN(x);y=*(volatile UINT16 *)((UINT32)a+sizeof(UINT16));CLEAN(y);x<<=16;x|=y;}

   #else

// The DUALCPU flag can be specified in your cl470 CFLAGS as '-dDUALCPU'
// or explicitly in a previous included header file using '#define DUALCPU'
      #if defined (DUALCPU)
         #define ENA_CLEAN  *(volatile UINT32 *)0xffffff50=0;
         #define DIS_CLEAN *(volatile UINT32 *)0xffffff50=1;
         #define CLEAN(x) *(volatile UINT32 *)0xffffff40=x;x=*(volatile UINT32 *)0xffffff40;
      #else
         #define ENA_CLEAN
         #define DIS_CLEAN
         #define CLEAN(x)
      #endif // #if defined (DUALCPU)

      #define SET_CFG_BIT *(volatile UINT32 *)0xffffffdc|=0x10;ENA_CLEAN;
      #define CLR_CFG_BIT DIS_CLEAN;*(volatile UINT32 *)0xffffffdc&=~0x10;
      #define READ_FLASH_MEM_U32(a,x) x=*(volatile UINT32 *)a;CLEAN(x);
   #endif // #if defined (PLATFORM)

   #define READ_FLASH_MEM_U16(a,x) x=*(volatile UINT16 *)a;CLEAN(x);
   #define READ_FLASH_MEM_U8(a,x) x=*(volatile UBYTE *)a;CLEAN(x);

// define structures

//////////////////////////////////////////////
// The FLASH_STATUS_ST structure is used for
// storing and retrieving information beyond
// just the return value from a function.
// for example, pulse data from program/erase
// and failing address and data
//////////////////////////////////////////////
typedef struct
{
   UINT32 stat1;
   UINT32 stat2;
   UINT32 stat3;
   UINT32 stat4;
} FLASH_STATUS_ST;

//////////////////////////////////////////////
// The FLASH_ENG_INFO_ST structure contains
// engineering information stored in the
// engineering portion of the Flash (for F10
// this is the ENGR0 row of the engineering
// array, and for F05 the TI OTP sector)
//////////////////////////////////////////////
typedef struct
{
   UINT32 DevID;
   UINT32 LotNo;
   UINT16 FlowCheck;
   UINT16 WaferNo;
   UINT16 Xcoord;
   UINT16 Ycoord;
} FLASH_ENGR_INFO_ST;

////////////////////////////////////////////////////
// The FLASH_ARRAY_ST structure type defined
// a UINT32 array pointer which points to
// the first control base address of a given
// flash module.
// The index of the array defines what 32 bit
// offset from the first address to store the
// intended data.  For example:
//   FLASH_ARRAY_ST cntl=0xffe88000;
//   cntl[4]=0xa5; (this stores 0xa5 to 0xffe88010)
////////////////////////////////////////////////////
typedef volatile UINT32 * FLASH_ARRAY_ST;

////////////////////////////////////////////////////////
// F10 devices can have up to 4 cores per module
// F05, F035 devices can have up to 8 cores per module
////////////////////////////////////////////////////////
typedef enum
{
#if !defined (F10)
   FLASH_CORE0
   ,FLASH_CORE1
   ,FLASH_CORE2
   ,FLASH_CORE3
   ,FLASH_CORE4
   ,FLASH_CORE5
   ,FLASH_CORE6
   ,FLASH_CORE7
#else
   FLASH_CORE0
   ,FLASH_CORE1
   ,FLASH_CORE2
   ,FLASH_CORE3
#endif
} FLASH_CORE;

////////////////////////////////////////////////////////
// F10 devices can have up to  4 sectors per core
// F05 devices can have up to  32 sectors per core
// F035 devices can have up to 16 sectors per core
////////////////////////////////////////////////////////
typedef enum
{
#if !defined (F10)
   FLASH_SECT0
   ,FLASH_SECT1
   ,FLASH_SECT2
   ,FLASH_SECT3
   ,FLASH_SECT4
   ,FLASH_SECT5
   ,FLASH_SECT6
   ,FLASH_SECT7
   ,FLASH_SECT8
   ,FLASH_SECT9
   ,FLASH_SECT10
   ,FLASH_SECT11
   ,FLASH_SECT12
   ,FLASH_SECT13
   ,FLASH_SECT14
   ,FLASH_SECT15
#if defined (F05)
   ,FLASH_SECT16
   ,FLASH_SECT17
   ,FLASH_SECT18
   ,FLASH_SECT19
   ,FLASH_SECT20
   ,FLASH_SECT21
   ,FLASH_SECT22
   ,FLASH_SECT23
   ,FLASH_SECT24
   ,FLASH_SECT25
   ,FLASH_SECT26
   ,FLASH_SECT27
   ,FLASH_SECT28
   ,FLASH_SECT29
   ,FLASH_SECT30
   ,FLASH_SECT31
#endif
#else
   FLASH_SECT0
   ,FLASH_SECT1
   ,FLASH_SECT2
   ,FLASH_SECT3
#endif
} FLASH_SECT;

// below are F035 specific parameters
   #if defined (F035)

// row length for 1 sector of Flash
      #define FLASH_ROW_LENGTH 0x100 // length in bytes - 2048 bits

///////////////////////////////////////////////
// The FLASH_WIDE_WORD_ST structure is used
// for wide words with 128/132/144 bit widths
// any bits above 128 are store in cbit
///////////////////////////////////////////////
typedef struct
{
   UINT16 main[8]; // main data in 16 bit chunks
   UINT16 cbit;    // check bits
   UINT16 flags;   // reserved for flags
} FLASH_WIDE_WORD_ST;

///////////////////////////////////////////////
// The FLASH_TIMING_ST structure contains
// timing information (setup/access/hold)
// for verify or executing a pulse
///////////////////////////////////////////////
typedef struct
{
   UINT32 setup;   // setup time counter
   UINT32 accpls;  // access time/pulse width counter
   UINT32 hold;    // hold time counter
   UINT16 mode;    // flags + verify/execute mode
   UINT16 data;    // data bits
   UINT32 wordlen; // word length in bits (128/132/144)
} FLASH_TIMING_ST;

///////////////////////////////////////////////
// The FLASH_WORD_ST structure contains
// timing information (setup/access/hold)
// for verify or executing a pulse on a word
// of arbitrary length, address data for the
// word in question, and pointers to the
// intended and masked data.  It also con-
// tains pulse statistics
///////////////////////////////////////////////
typedef struct
{
   volatile UINT16 *addr; // address pointer
   UINT16 *bdata;  // pointer to buffer compare data
   UINT16 *pdata;  // pointer to data to program
   UINT32 wordlen; // word length in bits (128/132/144)
   FLASH_ARRAY_ST cntl; // address of flash control base address
   UINT32 delay;   // delay parameter
   UINT32 verify_setup; // verify setup time counter
   UINT32 verify_access; // verify access time counter
   UINT32 verify_hold; // verify hold time counter
   UINT32 write_setup; // write setup time counter
   UINT32 write_pulse; // write pulse time counter
   UINT32 write_hold; // write access time counter
   UINT16 mode;    // flags + verify/execute mode
   UINT16 data;    // data bits
} FLASH_WORD_ST;

///////////////////////////////////////////////
// The FLASH_FSM_INFO_ST structure contains
// timing and CT related information for
// configuring the Flash state machine (FSM)
// which is programmed to the TI OTP sector
///////////////////////////////////////////////
typedef struct
{
   UBYTE  psetup;     // FSMPESETUP bits 15: 8
   UBYTE  esetup;     // FSMPESETUP bits  7: 0
   UINT16 csetup;     // FSMCSETUP: V5STAT (bits 15:12)
                      //            CmpctSetup (bits 11:0)
   UBYTE  pvsetup;    // FSMPVEVSETUP bits 15:8
   UBYTE  evsetup;    // FSMPVEVSETUP bits 7:0
   UINT16 cvsetup;    // FSMCVSETUP: Address/EXECUTEZ access time (bits 15:12)
                      //          CmpctVerSetup (bits 11:0)
   UBYTE  max_fosc_delay; // Max allowed FOSC delay parameter
   UBYTE  pvevaccess;  // FSMPVEVACCESS bits 7:0
   UBYTE  phold;      // FSMPCHOLD bits 15:8
   UBYTE  chold;      // FSMPCHOLD bits 7:0
   UINT16 ehold;      // FSMEHOLD bits 15:0
   UBYTE  pvhold;     // FSMPVEVHOLD bits 15:8
   UBYTE  evhold;     // FSMPVEVHOLD bits 7:0
   UINT16 pwidth;     // FSMPWIDTH bits 15:0
   UINT16 cwidth;     // FSMCWIDTH bits 15:0
   UINT32 ewidth;     // FSMEWIDTH bits 31:0
   UINT16 vwlcmpctct; // FSMVWLCMPCTCT bits 11:0
   UINT16 maxpp;      // FSMMAXPP: Start VNV CT (bits 15:12)
                      //           Max Prog Pulses (bits 11:0)
   UINT16 maxep;      // FSMMAXEP: Stop VNV CT (bits 15:12)
                      //           Max Erase Pulses (bits 11:0)
   UINT16 maxcp;      // FSMMAXCP: Step VNV CT (bits 15:12)
                      //           Max Cmpct Pulses (bits 11:0)
   UINT32 vhvct1;     // FSMVVHCT1 bits 31:0
   UINT16 vhvct2;     // FSMVVHCT2 bits 11:0
   UINT16 vreadct;    // FSMVREADCT bits 3:0
   UINT16 vppct;      // FSMVPPCT bits 15:0
   UINT16 vwlct;      // FSMVWLCT bits 15:4
   UINT32 chksum;     // 32 bit checksum for structure
} FLASH_FSM_INFO_ST;

   #endif // #if defined (F035)

// Function returns API version number only
extern UINT16 Flash_API_Version_U16(void);

// Function returns API Tech ID and Version number
extern UINT32 Fapi_getApiVersion32(void);

extern BOOL Flash_Erase_Sector_B(UINT32 *start,
                                 UINT32 length,
                                 FLASH_CORE core,
                                 FLASH_SECT sector,
                                 UINT32 delay,
                                 FLASH_ARRAY_ST cntl
                                );

extern BOOL Flash_Blank_B(UINT32 *start,
                          UINT32 length,
                          FLASH_CORE core,
                          FLASH_ARRAY_ST cntl,
                          FLASH_STATUS_ST *status
                         );

extern BOOL Flash_Verify_Zeros_B(UINT32 *start,
                                 UINT32 length,
                                 FLASH_CORE core,
                                 FLASH_ARRAY_ST cntl,
                                 FLASH_STATUS_ST *status
                                );

extern BOOL Flash_Compact_B(UINT32 *start,
                            FLASH_CORE core,
                            FLASH_SECT sector,
                            UINT32 delay,
                            FLASH_ARRAY_ST cntl,
                            FLASH_STATUS_ST *status
                           );

extern BOOL Flash_Erase_B(UINT32 *start,
                          UINT32 length,
                          FLASH_CORE core,
                          FLASH_SECT sector,
                          UINT32 delay,
                          FLASH_ARRAY_ST cntl,
                          FLASH_STATUS_ST *status
                         );
#if defined (F035)

#define Flash_Prog_B(m_start,m_buff,m_length,m_core,m_delay,m_cntl,m_status) \
            Flash_Prog_Data_B(m_start,m_buff,m_length,m_core,m_delay,m_cntl,m_status,m_length,CMND_PROG_DATA_MAIN)
#define Flash_Verify_B(m_start,m_buff,m_length,m_core,m_cntl,m_status) \
            Flash_Verify_Data_B(m_start,m_buff,m_length,m_core,m_cntl,m_status,m_length)

#else

extern BOOL Flash_Prog_B(UINT32 *start,
                         UINT32 *buff,
                         UINT32 length,
                         FLASH_CORE core,
                         UINT32 delay,
                         FLASH_ARRAY_ST cntl,
                         FLASH_STATUS_ST *status
                        );

extern BOOL Flash_Verify_B(UINT32 *start,
                           UINT32 *buff,
                           UINT32 length,
                           FLASH_CORE core,
                           FLASH_ARRAY_ST cntl,
                           FLASH_STATUS_ST *status
                          );

#endif //defined F035

extern BOOL Flash_Prog_Data_B(UINT32 *pu32Start,
                              UINT32 *pu32Buffer,
                              UINT32 u32Length,
                              FLASH_CORE oFlashCore,
                              UINT32 u32Delay,
                              FLASH_ARRAY_ST oFlashControl,
                              FLASH_STATUS_ST *poFlashStatus,
                              UINT32 u32BufferLength,
                              UINT16 u16Command
                             );

extern BOOL Flash_Zeros_B(UINT32 *start,
                          UINT32 length,
                          FLASH_CORE core,
                          UINT32 delay,
                          FLASH_ARRAY_ST cntl,
                          FLASH_STATUS_ST *status
                         );

extern BOOL Flash_Verify_Data_B(UINT32 *start,
                                UINT32 *buff,
                                UINT32 length,
                                FLASH_CORE core,
                                FLASH_ARRAY_ST cntl,
                                FLASH_STATUS_ST *status,
                                UINT32 buflen
                               );

#define PSA_U32(a,b,c) psa_u32(a,b,c)
extern UINT32 psa_u32(UINT32 *start,
                      UINT32 length,
                      UINT32 pseed
                     );

extern BOOL Flash_PSA_Verify_B(UINT32 *start,
                               UINT32 length,
                               UINT32 psa,
                               FLASH_CORE core,
                               FLASH_ARRAY_ST cntl,
                               FLASH_STATUS_ST *status
                              );

extern UINT32 Flash_PSA_Calc_U32(UINT32 *start,
                                 UINT32 length,
                                 UINT32 psa_seed,
                                 UINT32 mode,
                                 FLASH_CORE core,
                                 FLASH_ARRAY_ST cntl
                                );

extern BOOL Flash_Match_Key_B(volatile UINT32 *key_start,
                              const UINT32 key[],
                              FLASH_ARRAY_ST cntl
                             );

extern void Flash_Match_Key_V(volatile UINT32 *key_start,
                              const UINT32 key[],
                              FLASH_ARRAY_ST cntl
                             );

extern void Flash_EngRow_V(UINT32 *start,
                           FLASH_ARRAY_ST cntl,
                           FLASH_STATUS_ST *status
                          );

extern void Flash_EngInfo_V(UINT32 *start,
                            FLASH_ARRAY_ST cntl,
                            FLASH_ENGR_INFO_ST *info
                           );

extern BOOL Flash_Vt_Verify_B(UINT32 *start,
                              UINT32 *buff,
                              UINT32 length,
                              FLASH_CORE core,
                              UINT32 delay,
                              FLASH_ARRAY_ST cntl,
                              FLASH_STATUS_ST *status
                             );

extern BOOL Flash_Vt_Verify_Data_B(UINT32 *start,
                                   UINT32 *buff,
                                   UINT32 length,
                                   FLASH_CORE core,
                                   UINT32 delay,
                                   FLASH_ARRAY_ST cntl,
                                   FLASH_STATUS_ST *status,
                                   UINT32 buflen
                                  );

extern BOOL Flash_PSA_Vt_Verify_B(UINT32 *start,
                                  UINT32 length,
                                  UINT32 psa,
                                  FLASH_CORE core,
                                  UINT32 delay,
                                  FLASH_ARRAY_ST cntl,
                                  FLASH_STATUS_ST *status
                                 );

extern BOOL Flash_Vt_Blank_B(UINT32 *start,
                             UINT32 length,
                             FLASH_CORE core,
                             UINT32 delay,
                             FLASH_ARRAY_ST cntl,
                             FLASH_STATUS_ST *status
                            );

extern BOOL Flash_Vt_Verify_Zeros_B(UINT32 *start,
                                    UINT32 length,
                                    FLASH_CORE core,
                                    UINT32 delay,
                                    FLASH_ARRAY_ST cntl,
                                    FLASH_STATUS_ST *status
                                   );

extern void wait_delay(UINT32 u32Delay);

extern void Feed_Watchdog_V(void);

extern void Flash_Read_V(UINT32 *start,
                         UINT32 *buff,
                         UINT32 length,
                         UINT32 mode,
                         FLASH_CORE core,
                         FLASH_ARRAY_ST cntl
                        );

extern FAPI_ERROR_CODE Flash_Vt_Read_V(UINT32 *start,
                                       UINT32 *buff,
                                       UINT32 length,
                                       UINT32 delay,
                                       FLASH_CORE core,
                                       FLASH_ARRAY_ST cntl
                                      );

extern void Flash_Vt_Bit_Count_V(UINT32 *start,
                                 UINT32 *buff,
                                 UINT32 length,
                                 UINT32 delay,
                                 FLASH_CORE core,
                                 FLASH_ARRAY_ST cntl
                                );


   #if defined (F10)
extern void Flash_Prog_Key_V(volatile UINT32 *key_start,
                             const UINT32 key[],
                             FLASH_CORE core,
                             UINT32 delay,
                             FLASH_ARRAY_ST cntl
                            );

extern void Flash_Zero_Key_V(volatile UINT32 *key_start,
                             const UINT32 key[],
                             FLASH_CORE core,
                             UINT32 delay,
                             FLASH_ARRAY_ST cntl
                            );
   #else
extern BOOL OTP_Blank_B(UINT32 *start,
                        UINT32 length,
                        FLASH_CORE core,
                        FLASH_ARRAY_ST cntl,
                        FLASH_STATUS_ST *status
                       );

#if defined (F035)
#define OTP_Prog_B(m_start,m_buff,m_length,m_core,m_delay,m_cntl,m_status) \
            Flash_Prog_Data_B(m_start,m_buff,m_length,m_core,m_delay,m_cntl,m_status,m_length,CMND_PROG_DATA_COTP)

#else
extern BOOL OTP_Prog_B(UINT32 *start,
                       UINT32 *buff,
                       UINT32 length,
                       FLASH_CORE core,
                       UINT32 delay,
                       FLASH_ARRAY_ST cntl,
                       FLASH_STATUS_ST *status
                      );

#endif  //define F035

extern void OTP_Read_V(UINT32 *start,
                       UINT32 *buff,
                       UINT32 length,
                       FLASH_CORE core,
                       FLASH_ARRAY_ST cntl
                      );

extern BOOL OTP_Verify_B(UINT32 *start,
                         UINT32 *buff,
                         UINT32 length,
                         FLASH_CORE core,
                         FLASH_ARRAY_ST cntl,
                         FLASH_STATUS_ST *status
                        );

extern BOOL OTP_PSA_Verify_B(UINT32 *start,
                             UINT32 length,
                             UINT32 psa,
                             FLASH_CORE core,
                             FLASH_ARRAY_ST cntl,
                             FLASH_STATUS_ST *status
                            );

extern void Flash_Set_Vread_V(FLASH_ARRAY_ST cntl);

extern BOOL Flash_Start_Compact_B(UINT32 *start,
                                  FLASH_CORE core,
                                  UINT32 delay,
                                  FLASH_ARRAY_ST cntl
                                 );

extern BOOL Flash_Start_Erase_B(UINT32 *start,
                                FLASH_CORE core,
                                UINT32 delay,
                                FLASH_ARRAY_ST cntl
                               );

extern UINT16 Flash_Compact_Status_U16(FLASH_ARRAY_ST cntl);

extern UINT16 Flash_Erase_Status_U16(FLASH_ARRAY_ST cntl);

extern UINT16 Flash_Status_U16(FLASH_ARRAY_ST cntl);

extern void Flash_Sync_State_Machines_V(FLASH_ARRAY_ST cntl);

extern UINT16 Flash_Aux_Engr_U16(volatile UINT16 *start,
                                 FLASH_ARRAY_ST cntl
                                );

extern void Flash_Sector_Select_V(FLASH_CORE core,
                                  FLASH_ARRAY_ST cntl
                                 );

      #if defined (F035)

extern FAPI_ERROR_CODE Fapi_PollFlashStatus(FLASH_ARRAY_ST oFlashControl,
                                            FLASH_STATUS_ST *oFlashStatus
                                           );

extern BOOL Flash_Erase_Bank_B(UINT32 *start,
                               UINT32 length,
                               FLASH_CORE core,
                               UINT32 delay,
                               FLASH_ARRAY_ST cntl,
                               FLASH_STATUS_ST *status
                              );

extern FAPI_ERROR_CODE setup_state_machine(UINT32 *pu32Start,
                                           FLASH_CORE oFlashCore,
                                           UINT32 u32Delay,
                                           FLASH_ARRAY_ST oFlashControl
                                          );

extern void IssueCommand(volatile UINT16 *pu16Unlock,
                         volatile UINT16 *pu16Address,
                         UINT16 u16Command,
                         UINT32 u32Data,
                         FLASH_ARRAY_ST oFlashControl
                        );

extern UINT32 get_timing(UINT32 n, // (int)(timing / 500ns)
                         UINT32 delay, // delay parameter
                         UINT32 presc, // Flash prescaler
                         UINT32 shft, // bit shift
                         UINT32 min, // min value
                         UINT32 max // max value
                        );

// COD specific sub-functions
// prototype for sector precondition algo
extern BOOL precond_sect(UINT32 *start,
                         FLASH_ARRAY_ST cntl,
                         FLASH_STATUS_ST *status
                        );

// prototype for verify read algo
extern UINT16 verify_read(volatile UINT16 **addr,
                          UINT32 *length,
                          FLASH_ARRAY_ST cntl,
                          UINT32 delay,
                          FLASH_TIMING_ST *timing
                         );

// prototype for pulse algo
extern void exec_pulse(volatile UINT16 *addr,
                       FLASH_ARRAY_ST cntl,
                       UINT32 delay,
                       FLASH_TIMING_ST *timing
                      );

extern UINT32 ceil_div_by_x(UINT32 val,
                            UINT32 denom
                           );

extern UINT32 get_presc_shift(FLASH_ARRAY_ST cntl);

extern UINT32 aligned_byte_width(UINT32 address,
                                 UINT32 length,
                                 UINT32 width
                                );

extern BOOL Flash_Start_Prog_B(UINT32* pu32Start,
                               UINT32  pu32Data,
                               FLASH_CORE oFlashCore,
                               UINT32 u32Delay,
                               FLASH_ARRAY_ST oFlashControl
                              );

extern BOOL Flash_Start_Async_Command_B(UINT32 *pu32Start,
                                        UINT16 u16Command,
                                        UINT32 u32Data,
                                        FLASH_ARRAY_ST oFlashControl
                                       );

extern BOOL Flash_Start_Command_B(UINT32 *pu32Start,
                                  FLASH_CORE oFlashCore,
                                  UINT32 u32Delay,
                                  FLASH_ARRAY_ST oFlashControl,
                                  UINT16 u16Command,
                                  UINT32 u32Data
                                 );

// Return values indicating Flash Write bit size capability
typedef enum
{
   FAPI_WRITE_16BIT,
   FAPI_WRITE_32BIT
} FAPI_WRITE_SIZE;

// Return the supported Flash write size
         #define FAPI_GET_WRITE_SIZE(oFlashControl) (oFlashControl[FSM_ST_MACHINE] & 0x8000)?FAPI_WRITE_32BIT:FAPI_WRITE_16BIT

// Return values indicating Flash Write bit size capability
typedef enum
{
   FAPI_MASTER_CORE,
   FAPI_SLAVE_CORE0
} FAPI_CORE_SELECTOR;

FAPI_ERROR_CODE Fapi_SetupFlashPump(FAPI_CORE_SELECTOR oCoreSelector);
      #else

extern BOOL Flash_Start_Command_B(UINT32 *start,
                                  FLASH_CORE core,
                                  UINT32 delay,
                                  FLASH_ARRAY_ST cntl,
                                  UINT16 cmnd,
                                  UINT16 data
                                 );

      #endif // #if defined (F035)

   #endif // #if defined (F10) #else

#endif // #if defined (__FLASH470_H_)

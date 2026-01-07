/****************************************************************************/
/* sci470.h : SCI Module Register Definitions                              	*/
/*                                                                          */
/* Rev   : 1.1  	                                                        */
/*                                                                          */
/* -------------------------------------------------------------------------*/
/* History:                                                                 */
/* 20-SEP-07	Rev 1.0 	Initial version 				pratip@ti.com   */
/* 																			*/
/*                          SCI register definitions as per 				*/                          
/*                          SCI spec version 1.0 dtd.12/12/05      			*/
/*                                                                          */
/*                          Generated from BLIN470.h,so there are splits in	*/
/*                          reserved bit definitions.  						*/
/*                                                                          */
/* -------------------------------------------------------------------------*/
/*                                                                          */
/* 12-FEB-08    Rev 1.1 	Added types,definitions			pratip@ti.com	*/
/*                          and function prototypes                         */
/*                                                                          */
/* -------------------------------------------------------------------------*/
/*                                                                          */
/* 24-FEB-08    Rev 2.0 	Added sciindexdefinitions	    pratip@ti.com	*/
/*                                                                          */
/****************************************************************************/
/* ------------------------------------------------------------------------- */
/* Define the standard types                                                 */

#if defined(_TMS470_BIG) || defined(__big_endian__)
#ifndef BOOL
#define BOOL  unsigned char
#endif

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef UBYTE
#define UBYTE unsigned char
#endif


#ifndef UINT32
#define UINT32 unsigned int
#endif


#ifndef UWORD
#define UWORD unsigned short
#endif

#ifndef ULONG
#define ULONG unsigned long
#endif

#ifndef CHAR
#define CHAR  char 
#endif


#ifndef NULL
#define NULL  (void *)0
#endif

#ifndef inline                                /* mg 13.04.2010 */
#define inline __inline
#endif


/* ------------------------------------------------------------------------- */
/* SCIn                                                                      */
/*      See the definition of SCIn_ST below.                                 */

    


#define Sci0 (SCI_Ptr)
#define Sci1 (SCI1_Ptr)
#define Sci2 (SCI2_Ptr)
#define Sci3 (SCI3_Ptr)


/* ------------------------------------------------------------------------- */
/* SCICOUNT                                                                  */
/*      The number of SCI's is set by the SCICOUNT environment variable, if  */
/*      not set the driver assumes a single SCI.                             */

#ifndef SCICOUNT
#define SCICOUNT 1
#endif


//SCI


#define SCINOGCR1    0xFFFFFFFF
#define SCINOSETINT  0xFFFFFFFF
#define SCINOCLRINT  0xFFFFFFFF
#define SciNOMODE    0xFFFFFFFF
#define SciNOPORT    0xFFFFFFFF 
#define SciNOBAUD    0
#define SciNOSIZE    0
#define SciNOADDRESS 0xFFFF


typedef unsigned SCIMODE;
    
#define SciTwoStopBits 0x00000010
#define SciOneStopBit  0x00000000
#define SciEvenParity  0x0000000C
#define SciOddParity   0x00000004
#define SciAsync       0x00000002
#define SciIsoSync     0x00000000
#define SciAddrBit     0x00000001
#define SciIdleLine    0x00000000
#define SciRxEN        0x01000000
#define SciRxDmaEN     0x00020000
#define SciContinue    0x00020000
#define SciLoopBack    0x00010000
#define SciTxEN        0x02000000
#define SciTxDmaEN     0x00010000
#define SciIntClock    0x00000020
#define SciExtClock    0x00000000

typedef unsigned SCIPORT;

#define SciClkPinEN 0x00000001
#define SciClkOut   0x00000010
#define SciClkHigh  0x00000100
#define SciClkLow   0x00000000
#define SciClkSet   0x00001000
#define SciClkClr   0x00010000
#define SciClkPdr   0x00100000
#define SciClkPe    0x01000000

#define SciRxPinEN  0x00000002
#define SciRxOut    0x00000020
#define SciRxHigh   0x00000200
#define SciRxLow    0x00000000
#define SciRxSet    0x00002000
#define SciRxClr    0x00020000
#define SciRxPdr    0x00200000
#define SciRxPe     0x02000000

#define SciTxPinEN  0x00000004
#define SciTxOut    0x00000040
#define SciTxHigh   0x00000400
#define SciTxLow    0x00000000
#define SciTxSet    0x00004000
#define SciTxClr    0x00040000
#define SciTxPdr    0x00400000
#define SciTxPe     0x04000000

typedef unsigned SCIDMAPRI;

#define SciDmaHigh  0x00
#define SciDmaLow   0x08

typedef enum
{
    SciClkPin,
    SciRxPin,
    SciTxPin
} SCIPINID;

typedef enum
{
    SciFunctional,
    SciIoIn,
    SciIoOut,
    SciIoOutHigh,
    SciIoOutLow
} SCIQUAL;

typedef enum
{
    SciNoError,
    SciPending,
    SciOverrun,
    SciParity,
    SciFrame,
    SciBreak,
    SciBusBusy,
    SciTimeout,
    SciDmaError,
    SciModeError
} SCIEXPT;

/*------------------------------------------------------------------------- */
/* Note : This discription is also applicable for LIN-SCI, 					*/
/*------------------------------------------------------------------------- */


typedef volatile struct
{

    /* SCI Global Control Register 0 (SCIGCR0)	*/

    union                                      /* 0x00      */
    {
     unsigned int SCIGR0_UL;
     struct
     {
     unsigned int 			: 31;
     unsigned int RESET_B1	: 1;
     }SCIGR0_ST;
    }SCIGR0_UN;


    
    /* SCI Global Control Register 1 (SCIGCR1) */

    union                                      /* 0x04      */
    {
     unsigned int SCIGR1_UL; 
     struct
     {
     unsigned int 					: 6;
     unsigned int TX_ENA_B1			: 1;
     unsigned int RX_ENA_B1			: 1;
     unsigned int 					: 5;
     unsigned int NO_START_STOP_B1	: 1;
     unsigned int CONT_B1			: 1;
     unsigned int LOOP_BACK_B1		: 1;
     unsigned int 					: 2;
	 unsigned int 					: 1;     
     unsigned int 					: 1;
     unsigned int 					: 1;
     unsigned int 					: 1;
     unsigned int POWERDOWN_B1 		: 1; /* [ADAPT_B1]    - in case of LIN	*/
     unsigned int SLEEP_B1			: 1;
     unsigned int SWnRST_B1			: 1;
     unsigned int 					: 1; /* [LIN_MODE_B1] - in case of LIN	*/
     unsigned int CLOCK_B1			: 1;
     unsigned int STOP_B1			: 1;
     unsigned int PARITY_B1			: 1;
     unsigned int PARITY_ENA_B1		: 1;
     unsigned int TIMING_MODE_B1	: 1;
     unsigned int COMM_MODE_B1		: 1;
     }SCIGR1_ST;
    }SCIGR1_UN;



   	/* Reserved   - [SCIGR2] in case of LIN		*/

	unsigned int 		:32;  					/* 0x08		 */



	/* SCI Set Interrupt Register (SCISETINT) 	*/

	union                                      /* 0x0C      */
    {
     unsigned int SCISETINT_UL;
     struct
     {
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int SET_FE_INT_B1: 1;
     unsigned int SET_OE_INT_B1: 1;
     unsigned int SET_PE_INT_B1: 1;
     unsigned int : 5;
     unsigned int SET_RX_DMA_ALL_B1: 1;
     unsigned int SET_RX_DMA_B1: 1;
     unsigned int SET_TX_DMA_B1: 1;
     unsigned int SET_INC_BR_B1: 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 3;
     unsigned int SET_RX_INT_B1: 1;
     unsigned int SET_TX_INT_B1: 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 2;
     unsigned int SET_WAKUP_INT_B1: 1;
     unsigned int SET_BRKDT_INT_B1: 1;
     }SCISETINT_ST;
    }SCISETINT_UN;



 /* */

    union                                      /* 0x10      */
    {
     unsigned int SCICLRINT_UL;
     struct
     {
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int CLR_FE_INT_B1: 1;
     unsigned int CLR_OE_INT_B1: 1;
     unsigned int CLR_PE_INT_B1: 1;
     unsigned int : 5;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 3;
     unsigned int CLR_RX_INT_B1: 1;
     unsigned int CLR_TX_INT_B1: 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 2;
     unsigned int CLR_WAKUP_INT_B1: 1;
     unsigned int CLR_BRKDT_INT_B1: 1;
     }SCICLRINT_ST;
    }SCICLRINT_UN;

    union                                      /* 0x14      */
    {
     unsigned int SCISETINTLVL_UL;
     struct
     {
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int SET_FE_INT_LVL_B1: 1;
     unsigned int SET_OE_INT_LVL_B1: 1;
     unsigned int SET_PE_INT_LVL_B1: 1;
     unsigned int : 5;
     unsigned int SET_RX_DMA_ALL_LVL_B1: 1;
     unsigned int : 2;
     unsigned int SET_INC_BR_INT_LVL_B1: 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 3;
     unsigned int SET_RX_INT_LVL_B1: 1;
     unsigned int SET_TX_INT_LVL_B1: 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 2;
     unsigned int SET_WAKUP_INT_LVL_B1: 1;
     unsigned int SET_BRKDT_INT_LVL_B1: 1;
     }SCISETINTLVL_ST;
    }SCISETINTLVL_UN;

    union                                      /* 0x18      */
    {
     unsigned int SCICLRINTLVL_UL;
     struct
     {
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int CLR_FE_INT_LVL_B1: 1;
     unsigned int CLR_OE_INT_LVL_B1: 1;
     unsigned int CLR_PE_INT_LVL_B1: 1;
     unsigned int : 5;
     unsigned int CLR_RX_DMA_ALL_LVL_B1: 1;
     unsigned int : 2;
     unsigned int CLR_INC_BR_INT_LVL_B1: 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 3;
     unsigned int CLR_RX_INT_LVL_B1: 1;
     unsigned int CLR_TX_INT_LVL_B1: 1;
     unsigned int : 2;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 2;
     unsigned int CLR_WAKUP_INT_LVL_B1: 1;
     unsigned int CLR_BRKDT_INT_LVL_B1: 1;
     }SCICLRINTLVL_ST;
    }SCICLRINTLVL_UN;



	/* SCI Flags Register (SCIFLR)				*/

    union                                      /* 0x1C      */
    {
     unsigned int SCIFLR_UL;
     struct
     {
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int FE_B1: 1;
     unsigned int OE_B1: 1;
     unsigned int PE_B1: 1;
     unsigned int : 8;
     unsigned int INC_BR_B1: 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int RX_WAKE_B1: 1;
     unsigned int TX_EMPTY_B1: 1;
     unsigned int TX_WAKE_B1: 1;
     unsigned int RXRDY_B1: 1;
     unsigned int TXRDY_B1: 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int BUSY_B1: 1;
     unsigned int IDLE_B1: 1;
     unsigned int WAKEUP_B1: 1;
     unsigned int BRKDT_B1: 1;
     }SCIFLR_ST;
    }SCIFLR_UN;



	/* SCI Interrupt Offset Vector 0 (SCIINTVECT0)	*/

    union                                      /* 0x20      */
    {
     unsigned int SCIINTVECT0_UL;
     struct
     {
     unsigned int 				: 27;
     unsigned int INTVECT0_B5	: 5;
     }SCIINTVECT0_ST;
    }SCIINTVECT0_UN;



	/* SCI Interrupt Offset Vector 1 (SCIINTVECT1)	*/

    union                                      /* 0x24      */
    {
     unsigned int SCIINTVECT1_UL;
     struct
     {
     unsigned int 				: 27;
     unsigned int INTVECT1_B5	: 5;
     }SCIINTVECT1_ST;
    }SCIINTVECT1_UN;




    union                                      /* 0x28      */
    {
     unsigned int SCICHAR_UL;
     struct
     {
     unsigned int 			: 13;
     unsigned int 			: 3;
     unsigned int 			: 13;
     unsigned int CHAR_B3 	: 3;
     }SCICHAR_ST;
    }SCICHAR_UN;



	/* SCI Baud Rate Selection Register (SCIBAUD) */

    union                                      /* 0x2C      */
    {
     unsigned int SCIBRSR_UL;
     struct
     {
     unsigned int : 1;
     unsigned int U_B3: 3;
     unsigned int M_B4: 4;
     unsigned int P_B24: 24;
     }SCIBRSR_ST;
    }SCIBRSR_UN;

    union                                      /* 0x30     */
    {
     unsigned int SCIED_UL;
     struct
     {
     unsigned int : 24;
     unsigned char ED_UC;
     }SCIED_ST;
    }SCIED_UN;

    union                                      /* 0x34      */
    {
     unsigned int SCIRD_UL;
     struct
     {
     unsigned int : 24;
     unsigned char RD_UC;
     }SCIRD_ST;
    }SCIRD_UN;

    union                                      /* 0x38      */
    {
     unsigned int SCITD_UL;
     struct
     {
     unsigned int : 24;
     unsigned char TD_UC;
     }SCITD_ST;
    }SCITD_UN;

    union                                      /* 0x3C     */
    {
     unsigned int SCIPIO0_UL;
     struct
     {
     unsigned int : 29;
     unsigned int TXFUNC_B1: 1;
     unsigned int RXFUNC_B1: 1;
     unsigned int CLKFUNC_B1: 1;
     }SCIPIO0_ST;
    }SCIPIO0_UN;

    union                                      /* 0x40      */
    {
     unsigned int SCIPIO1_UL;
     struct
     {
     unsigned int : 29;
     unsigned int TXDIR_B1: 1;
     unsigned int RXDIR_B1: 1;
     unsigned int CLKDIR_B1: 1;
     }SCIPIO1_ST;
    }SCIPIO1_UN;

    union                                      /* 0x44      */
    {
     unsigned int SCIPIO2_UL;
     struct
     {
     unsigned int : 29;
     unsigned int TXIN_B1: 1;
     unsigned int RXIN_B1: 1;
     unsigned int CLKIN_B1: 1;
     }SCIPIO2_ST;
    }SCIPIO2_UN;

    union                                      /* 0x48      */
    {
     unsigned int SCIPIO3_UL;
     struct
     {
     unsigned int : 29;
     unsigned int TXOUT_B1: 1;
     unsigned int RXOUT_B1: 1;
     unsigned int CLKOUT_B1: 1;
     }SCIPIO3_ST;
    }SCIPIO3_UN;

    union                                      /* 0x4C      */
    {
     unsigned int SCIPIO4_UL;
     struct
     {
     unsigned int : 29;
     unsigned int TXSET_B1: 1;
     unsigned int RXSET_B1: 1;
     unsigned int CLKSET_B1: 1;
     }SCIPIO4_ST;
    }SCIPIO4_UN;

    union                                      /* 0x50      */
    {
     unsigned int SCIPIO5_UL;
     struct
     {
     unsigned int : 29;
     unsigned int TXCLR_B1: 1;
     unsigned int RXCLR_B1: 1;
     unsigned int CLKCLR_B1: 1;
     }SCIPIO5_ST;
    }SCIPIO5_UN;

    union                                      /* 0x54      */
    {
     unsigned int SCIPIO6_UL;
     struct
     {
     unsigned int : 29;
     unsigned int TXPDR_B1: 1;
     unsigned int RXPDR_B1: 1;
     unsigned int CLKPDR_B1: 1;
     }SCIPIO6_ST;
    }SCIPIO6_UN;

    union                                      /* 0x58      */
    {
     unsigned int SCIPIO7_UL;
     struct
     {
     unsigned int : 29;
     unsigned int TXPE_B1: 1;
     unsigned int RXPE_B1: 1;
     unsigned int CLKPE_B1: 1;
     }SCIPIO7_ST;
    }SCIPIO7_UN;

    union                                      /* 0x5C      */
    {
     unsigned int SCIPIO8_UL;
     struct
     {
     unsigned int : 29;
     unsigned int TXPSL_B1: 1;
     unsigned int RXPSL_B1: 1;
     unsigned int CLKPSL_B1: 1;
     }SCIPIO8_ST;
    }SCIPIO8_UN;

    unsigned int : 32;						/* 0x60      */
    unsigned int : 32;						/* 0x64      */
    unsigned int : 32;						/* 0x68      */
    unsigned int : 32;						/* 0x6C      */
    unsigned int : 32;						/* 0x70      */
    unsigned int : 32;						/* 0x74      */
    unsigned int : 32;						/* 0x78      */
    unsigned int : 32;						/* 0x7C      */


     union                                  /* 0x80      */
    {
     unsigned int SCIPIO9_UL;
     struct
     {
     unsigned int : 29;
     unsigned int TXSL_B1: 1;
     unsigned int RXSL_B1: 1;
     unsigned int CLKSL_B1: 1;
     }SCIPIO9_ST;
    }SCIPIO9_UN;
    
    unsigned int : 32;                        /* 0x84      */
   
    unsigned int : 32; 						  /* 0x88      */
    
    unsigned int : 32; 						  /* 0x8C		*/
    
    union                                     /* 0x90      */
    {
     unsigned int IODFT_UL;
     struct
     {
     unsigned int BEN_B1: 1;
     unsigned int PBEN_B1: 1;
     unsigned int CEN_B1: 1;
     unsigned int ISFEN_B1: 1;
     unsigned int : 1;
     unsigned int FEN_B1: 1;
     unsigned int PEN_B1: 1;
     unsigned int BRKDTEN_B1: 1;
     unsigned int : 3;
     unsigned int PIN_SAMPLE_MASK_B2: 2;
     unsigned int TX_SHIFT_B3: 3;
     unsigned int : 4;
     unsigned int IODFTENA_B4: 4;
     unsigned int : 6;
     unsigned int LPBENA_B1: 1;
     unsigned int RXPENA_B1: 1;
      }IODFT_ST;
    }IODFT_UN;

} SCI_ST;


/* ------------------------------------------------------------------------- */
/* e_SCIn_ST Instance of LIN/SCI registers, this to defined in the linker    */
/*           command file,if to be used.                                     */

extern SCI_ST e_SCI0_ST, e_SCI1_ST, e_SCI2_ST, e_SCI3_ST;

extern SCI_ST* SCI_Ptr;
extern SCI_ST* SCI1_Ptr;
extern SCI_ST* SCI2_Ptr;
extern SCI_ST* SCI3_Ptr;


/* ------------------------------------------------------------------------- */
/* SCI_CBVOID, SCI_CBADDRSTAT, SCI_CBSTATUS                                  */
/*      User supplied interrupt callback routines                            */

typedef void SCI_CBVOID();
typedef void SCI_CBADDRSTAT(UWORD Address_UW, SCIEXPT Status_N);
typedef void SCI_CBSTATUS(SCIEXPT Status_N);
typedef void SCI_ABORT(SCI_ST *Sci_PST);


/* ------------------------------------------------------------------------- */
/* Interface prototypes                                                      */

void 	SCI_ResetEnter_V(SCI_ST *Sci_PST);
void 	SCI_ResetExit_V(SCI_ST *Sci_PST);
void    SCI_SwResetEnter_V(SCI_ST *Sci_PST);
void    SCI_SwResetExit_V(SCI_ST *Sci_PST);
ULONG   SCI_Init_UL(ULONG Sci_GCR1_uL, ULONG Sci_INT0_uL, SCIPORT PortInit_N, ULONG Baud_UL, UBYTE CharSize_UB,SCI_CBVOID *CbOnBrkdt_PV, SCI_ST *Sci_PST);
void    SCI_PortInit_UL(SCIPORT PortInit1_N,SCIPORT PortInit2_N,SCI_ST *Sci_PST);
SCIEXPT SCI_PowerDownEnter_N(SCI_CBVOID *CbOnWakeUp_PV, SCI_ST *Sci_PST);
void    SCI_PowerDownExit_V(SCI_ST *Sci_PST);
void    SCI_PinModify_V(SCIPINID PinID_N, SCIQUAL PinQual_N, SCI_ST *Sci_PST);
SCIEXPT SCI_SendBreak_N(SCI_ST *Sci_PST);
SCIEXPT SCI_Send_N(UWORD BlockSize_UW, const UBYTE *Src_PUB, UWORD Address_UW, SCI_CBVOID *CbOnSend_PV, SCI_ST *Sci_PST);
SCIEXPT SCI_Receive_N(UWORD BlockSize_UW, UBYTE *Dest_PUB, SCI_CBSTATUS *CbOnReceive_PV, SCI_ST *Sci_PST);
void    SCI_TxInterrupt_V(SCI_ST *Sci_PST);
void    SCI_RxInterrupt_V(SCI_ST *Sci_PST);
void    SCI_ExptInterrupt_V(SCI_ST *Sci_PST);
SCIEXPT SCI_AwaitAddress_N(SCI_CBADDRSTAT *CbOnAddress_PV, SCI_ST *Sci_PST);
ULONG   SCI_InitEx_UL(ULONG Sci_GCR1_uL, ULONG Sci_INT0_uL, SCIPORT PortInit_N, ULONG Baud_UL, UBYTE CharSize_UB, SCI_CBVOID *CbOnBrkdt_PV, ULONG ByteTimeout_UL, BOOL CollisionDetect_B, SCI_ST *Sci_PST);
void    SCI_Abort_V(SCI_ST *Sci_PST);
SCIEXPT SCI_SendByte_N(const UBYTE Byte_UB, SCI_CBVOID *CbOnSend_PV, SCI_ST *Sci_PST);
long    SCI_ReceiveByte_L(SCI_CBSTATUS *CbOnReceive_PV, SCI_ST *Sci_PST);
void    SCI_InitDma_V(SCIDMAPRI DmaIntPri_N, SCI_ST *Sci_PST);
void    SCI_DmaCallback_V(unsigned channel);

void SCI_clean_flags(SCI_ST *Sci_PST);

/*---------------------------------------------------------------------------*/
#ifndef SCIINTERRUPT
	#define SCIINTERRUPT
#endif

#if !defined(SCIINTERRUPT) && !defined(SCIPOLLING) && !defined(SCIDMA)
#error build options SCIINTERRUPT, SCIPOLLONG or SCIDMA not defined
#endif


 
/* ------------------------------------------------------------------------- */
/* SCI_INT_ST                                                                */
/*      We need to hold global paramters for the interrupt service routine,  */
/*      one set of paramters for each SCI.  The number of SCI's is set by    */
/*      the SCICOUNT environment variable, if not set the driver assumes a   */
/*      single SCI.                                                          */

typedef struct
{
    SCI_CBVOID          *BreakAction_PV;
    SCI_CBVOID          *WakeAction_PV;
    SCI_CBADDRSTAT      *AddrAction_PV;

    SCI_CBVOID          *SendAction_PV;
    const unsigned char *Send_PUB;
    unsigned short       Address_US;
    unsigned short       SendLength_US;

    SCI_CBSTATUS        *RecvAction_PV;
    unsigned char       *Recv_PUB;
    unsigned short       RecvLength_US;

#ifdef SCIDMA
    CPCHAIN  txcp;
    CPCHAIN  rxcp;
    unsigned DmaIntPri_N;
#endif

#ifdef SCI_TIMEOUT_V
    unsigned long        ByteTimeout_UL;
    BOOL                 Timeout_B;
#endif

} SCI_INT_ST;

extern SCI_INT_ST SciInt_ST[SCICOUNT];


/* ------------------------------------------------------------------------- */
/* SCI_Index_PST                                                             */

static inline SCI_INT_ST *SCI_Index_PST(SCI_ST *Sci_PST)
{
#if SCICOUNT == 1
    return &SciInt_ST[0];
#endif

#if SCICOUNT == 2
    return Sci_PST == Sci0 ? &SciInt_ST[0] : &SciInt_ST[1];
#endif

#if SCICOUNT == 3
    return Sci_PST == Sci0 ? &SciInt_ST[0] : 
           (Sci_PST == Sci1 ? &SciInt_ST[1] : &SciInt_ST[2]);
#endif

#if SCICOUNT == 4
    return Sci_PST == Sci0 ? &SciInt_ST[0] : 
           (Sci_PST == Sci1 ? &SciInt_ST[1] : 
           (Sci_PST == Sci2 ? &SciInt_ST[2] : &SciInt_ST[3]));
#endif
}

/* ------------------------------------------------------------------------- */
/* SCI_DmaTxChannel_U                                                        */

#ifdef SCIDMA
static inline unsigned SCI_DmaTxChannel_U(SCI_ST *Sci_PST)
{
#if SCICOUNT >= 2
    if (Sci_PST == Sci1) return 15;
#endif
    return 5;
}
#endif


/* ------------------------------------------------------------------------- */
/* SCI_DmaRxChannel_U                                                        */

#ifdef SCIDMA
static inline unsigned SCI_DmaRxChannel_U(SCI_ST *Sci_PST)
{
#if SCICOUNT >= 2
    if (Sci_PST == Sci1) return 14;
#endif
    return 4;
}
#endif


/* ------------------------------------------------------------------------- */
/* SCI_DmaRxChannel_U                                                        */

static inline SCI_ST *SCI_DmaGetSci_PST(unsigned channel)
{
#if SCICOUNT >= 2
    if (channel == 14 || channel == 15) return Sci1;
#else
    return Sci0;                      /* mg 13.04.2010 */
#endif

//    return Sci0;
}

/* ------------------------------------------------------------------------- */
/* SCI_TIMEOUT_V                                                             */
/*      protoype of function to be provided by the OS/Application to		 */
/*      implement system dependant prototype								 */

#ifdef SCI_TIMEOUT_V
void SCI_TIMEOUT_V(unsigned Timeout_UL, SCI_ABORT *Abort_PV, SCI_ST *Sci_ST);
#endif


/* ------------------------------------------------------------------------- */

/*- End of file ------------------------------------------------------------ */


#elif defined(_TMS470_LITTLE) || defined(__little_endian__)
#ifndef BOOL
#define BOOL  unsigned char
#endif

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef UBYTE
#define UBYTE unsigned char
#endif


#ifndef UINT32
#define UINT32 unsigned int
#endif


#ifndef UWORD
#define UWORD unsigned short
#endif

#ifndef ULONG
#define ULONG unsigned long
#endif

#ifndef CHAR
#define CHAR  char 
#endif


#ifndef NULL
#define NULL  (void *)0
#endif



/* ------------------------------------------------------------------------- */
/* SCIn                                                                      */
/*      See the definition of SCIn_ST below.                                 */

    


#define Sci0 (SCI_Ptr)
#define Sci1 (SCI1_Ptr)
#define Sci2 (SCI2_Ptr)
#define Sci3 (SCI3_Ptr)


/* ------------------------------------------------------------------------- */
/* SCICOUNT                                                                  */
/*      The number of SCI's is set by the SCICOUNT environment variable, if  */
/*      not set the driver assumes a single SCI.                             */

#ifndef SCICOUNT
#define SCICOUNT 1
#endif


//SCI


#define SCINOGCR1    0xFFFFFFFF
#define SCINOSETINT  0xFFFFFFFF
#define SCINOCLRINT  0xFFFFFFFF
#define SciNOMODE    0xFFFFFFFF
#define SciNOPORT    0xFFFFFFFF 
#define SciNOBAUD    0
#define SciNOSIZE    0
#define SciNOADDRESS 0xFFFF


typedef unsigned SCIMODE;
    
#define SciTwoStopBits 0x00000010
#define SciOneStopBit  0x00000000
#define SciEvenParity  0x0000000C
#define SciOddParity   0x00000004
#define SciAsync       0x00000002
#define SciIsoSync     0x00000000
#define SciAddrBit     0x00000001
#define SciIdleLine    0x00000000
#define SciRxEN        0x01000000
#define SciRxDmaEN     0x00020000
#define SciContinue    0x00020000
#define SciLoopBack    0x00010000
#define SciTxEN        0x02000000
#define SciTxDmaEN     0x00010000
#define SciIntClock    0x00000020
#define SciExtClock    0x00000000

typedef unsigned SCIPORT;

#define SciClkPinEN 0x00000001
#define SciClkOut   0x00000010
#define SciClkHigh  0x00000100
#define SciClkLow   0x00000000
#define SciClkSet   0x00001000
#define SciClkClr   0x00010000
#define SciClkPdr   0x00100000
#define SciClkPe    0x01000000

#define SciRxPinEN  0x00000002
#define SciRxOut    0x00000020
#define SciRxHigh   0x00000200
#define SciRxLow    0x00000000
#define SciRxSet    0x00002000
#define SciRxClr    0x00020000
#define SciRxPdr    0x00200000
#define SciRxPe     0x02000000

#define SciTxPinEN  0x00000004
#define SciTxOut    0x00000040
#define SciTxHigh   0x00000400
#define SciTxLow    0x00000000
#define SciTxSet    0x00004000
#define SciTxClr    0x00040000
#define SciTxPdr    0x00400000
#define SciTxPe     0x04000000

typedef unsigned SCIDMAPRI;

#define SciDmaHigh  0x00
#define SciDmaLow   0x08

typedef enum
{
    SciClkPin,
    SciRxPin,
    SciTxPin
} SCIPINID;

typedef enum
{
    SciFunctional,
    SciIoIn,
    SciIoOut,
    SciIoOutHigh,
    SciIoOutLow
} SCIQUAL;

typedef enum
{
    SciNoError,
    SciPending,
    SciOverrun,
    SciParity,
    SciFrame,
    SciBreak,
    SciBusBusy,
    SciTimeout,
    SciDmaError,
    SciModeError
} SCIEXPT;

/*------------------------------------------------------------------------- */
/* Note : This discription is also applicable for LIN-SCI, 					*/
/*------------------------------------------------------------------------- */


typedef volatile struct
{

    /* SCI Global Control Register 0 (SCIGCR0)	*/

    union                                      /* 0x00      */
    {
     unsigned int SCIGR0_UL;
     struct
     {
     unsigned int RESET_B1	: 1;
     unsigned int 			: 31;
     }SCIGR0_ST;
    }SCIGR0_UN;


    
    /* SCI Global Control Register 1 (SCIGCR1) */

    union                                      /* 0x04      */
    {
     unsigned int SCIGR1_UL; 
     struct
     {
     unsigned int COMM_MODE_B1		: 1;
     unsigned int TIMING_MODE_B1	: 1;
     unsigned int PARITY_ENA_B1		: 1;
     unsigned int PARITY_B1			: 1;
     unsigned int STOP_B1			: 1;
     unsigned int CLOCK_B1			: 1;
     unsigned int 					: 1; /* [LIN_MODE_B1] - in case of LIN	*/
     unsigned int SWnRST_B1			: 1;
     unsigned int SLEEP_B1			: 1;
     unsigned int POWERDOWN_B1 		: 1; /* [ADAPT_B1]    - in case of LIN	*/
     unsigned int 					: 1;
     unsigned int 					: 1;
     unsigned int 					: 1;
	 unsigned int 					: 1;     
     unsigned int 					: 2;
     unsigned int LOOP_BACK_B1		: 1;
     unsigned int CONT_B1			: 1;
     unsigned int NO_START_STOP_B1	: 1;
     unsigned int 					: 5;
     unsigned int RX_ENA_B1			: 1;
     unsigned int TX_ENA_B1			: 1;
     unsigned int 					: 6;
     }SCIGR1_ST;
    }SCIGR1_UN;



   	/* Reserved   - [SCIGR2] in case of LIN		*/

	unsigned int 		:32;  					/* 0x08		 */



	/* SCI Set Interrupt Register (SCISETINT) 	*/

	union                                      /* 0x0C      */
    {
     unsigned int SCISETINT_UL;
     struct
     {
     unsigned int SET_BRKDT_INT_B1: 1;
     unsigned int SET_WAKUP_INT_B1: 1;
     unsigned int : 2;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int SET_TX_INT_B1: 1;
     unsigned int SET_RX_INT_B1: 1;
     unsigned int : 3;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int SET_INC_BR_B1: 1;
     unsigned int SET_TX_DMA_B1: 1;
     unsigned int SET_RX_DMA_B1: 1;
     unsigned int SET_RX_DMA_ALL_B1: 1;
     unsigned int : 5;
     unsigned int SET_PE_INT_B1: 1;
     unsigned int SET_OE_INT_B1: 1;
     unsigned int SET_FE_INT_B1: 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     }SCISETINT_ST;
    }SCISETINT_UN;



 /* */

    union                                      /* 0x10      */
    {
     unsigned int SCICLRINT_UL;
     struct
     {
     unsigned int CLR_BRKDT_INT_B1: 1;
     unsigned int CLR_WAKUP_INT_B1: 1;
     unsigned int : 2;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int CLR_TX_INT_B1: 1;
     unsigned int CLR_RX_INT_B1: 1;
     unsigned int : 3;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 5;
     unsigned int CLR_PE_INT_B1: 1;
     unsigned int CLR_OE_INT_B1: 1;
     unsigned int CLR_FE_INT_B1: 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     }SCICLRINT_ST;
    }SCICLRINT_UN;

    union                                      /* 0x14      */
    {
     unsigned int SCISETINTLVL_UL;
     struct
     {
     unsigned int SET_BRKDT_INT_LVL_B1: 1;
     unsigned int SET_WAKUP_INT_LVL_B1: 1;
     unsigned int : 2;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int SET_TX_INT_LVL_B1: 1;
     unsigned int SET_RX_INT_LVL_B1: 1;
     unsigned int : 3;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int SET_INC_BR_INT_LVL_B1: 1;
     unsigned int : 2;
     unsigned int SET_RX_DMA_ALL_LVL_B1: 1;
     unsigned int : 5;
     unsigned int SET_PE_INT_LVL_B1: 1;
     unsigned int SET_OE_INT_LVL_B1: 1;
     unsigned int SET_FE_INT_LVL_B1: 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     }SCISETINTLVL_ST;
    }SCISETINTLVL_UN;

    union                                      /* 0x18      */
    {
     unsigned int SCICLRINTLVL_UL;
     struct
     {
     unsigned int CLR_BRKDT_INT_LVL_B1: 1;
     unsigned int CLR_WAKUP_INT_LVL_B1: 1;
     unsigned int : 2;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 2;
     unsigned int CLR_TX_INT_LVL_B1: 1;
     unsigned int CLR_RX_INT_LVL_B1: 1;
     unsigned int : 3;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int CLR_INC_BR_INT_LVL_B1: 1;
     unsigned int : 2;
     unsigned int CLR_RX_DMA_ALL_LVL_B1: 1;
     unsigned int : 5;
     unsigned int CLR_PE_INT_LVL_B1: 1;
     unsigned int CLR_OE_INT_LVL_B1: 1;
     unsigned int CLR_FE_INT_LVL_B1: 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     }SCICLRINTLVL_ST;
    }SCICLRINTLVL_UN;



	/* SCI Flags Register (SCIFLR)				*/

    union                                      /* 0x1C      */
    {
     unsigned int SCIFLR_UL;
     struct
     {
     unsigned int BRKDT_B1: 1;
     unsigned int WAKEUP_B1: 1;
     unsigned int IDLE_B1: 1;
     unsigned int BUSY_B1: 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int TXRDY_B1: 1;
     unsigned int RXRDY_B1: 1;
     unsigned int TX_WAKE_B1: 1;
     unsigned int TX_EMPTY_B1: 1;
     unsigned int RX_WAKE_B1: 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int INC_BR_B1: 1;
     unsigned int : 8;
     unsigned int PE_B1: 1;
     unsigned int OE_B1: 1;
     unsigned int FE_B1: 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     unsigned int : 1;
     }SCIFLR_ST;
    }SCIFLR_UN;



	/* SCI Interrupt Offset Vector 0 (SCIINTVECT0)	*/

    union                                      /* 0x20      */
    {
     unsigned int SCIINTVECT0_UL;
     struct
     {
     unsigned int INTVECT0_B5	: 5;
     unsigned int 				: 27;
     }SCIINTVECT0_ST;
    }SCIINTVECT0_UN;



	/* SCI Interrupt Offset Vector 1 (SCIINTVECT1)	*/

    union                                      /* 0x24      */
    {
     unsigned int SCIINTVECT1_UL;
     struct
     {
     unsigned int INTVECT1_B5	: 5;
     unsigned int 				: 27;
     }SCIINTVECT1_ST;
    }SCIINTVECT1_UN;




    union                                      /* 0x28      */
    {
     unsigned int SCICHAR_UL;
     struct
     {
     unsigned int CHAR_B3 	: 3;
     unsigned int 			: 13;
     unsigned int 			: 3;
     unsigned int 			: 13;
     }SCICHAR_ST;
    }SCICHAR_UN;



	/* SCI Baud Rate Selection Register (SCIBAUD) */

    union                                      /* 0x2C      */
    {
     unsigned int SCIBRSR_UL;
     struct
     {
     unsigned int P_B24: 24;
     unsigned int M_B4: 4;
     unsigned int U_B3: 3;
     unsigned int : 1;
     }SCIBRSR_ST;
    }SCIBRSR_UN;

    union                                      /* 0x30     */
    {
     unsigned int SCIED_UL;
     struct
     {
     unsigned char ED_UC;
     unsigned int : 24;
     }SCIED_ST;
    }SCIED_UN;

    union                                      /* 0x34      */
    {
     unsigned int SCIRD_UL;
     struct
     {
     unsigned char RD_UC;
     unsigned int : 24;
     }SCIRD_ST;
    }SCIRD_UN;

    union                                      /* 0x38      */
    {
     unsigned int SCITD_UL;
     struct
     {
     unsigned char TD_UC;
     unsigned int : 24;
     }SCITD_ST;
    }SCITD_UN;

    union                                      /* 0x3C     */
    {
     unsigned int SCIPIO0_UL;
     struct
     {
     unsigned int CLKFUNC_B1: 1;
     unsigned int RXFUNC_B1: 1;
     unsigned int TXFUNC_B1: 1;
     unsigned int : 29;
     }SCIPIO0_ST;
    }SCIPIO0_UN;

    union                                      /* 0x40      */
    {
     unsigned int SCIPIO1_UL;
     struct
     {
     unsigned int CLKDIR_B1: 1;
     unsigned int RXDIR_B1: 1;
     unsigned int TXDIR_B1: 1;
     unsigned int : 29;
     }SCIPIO1_ST;
    }SCIPIO1_UN;

    union                                      /* 0x44      */
    {
     unsigned int SCIPIO2_UL;
     struct
     {
     unsigned int CLKIN_B1: 1;
     unsigned int RXIN_B1: 1;
     unsigned int TXIN_B1: 1;
     unsigned int : 29;
     }SCIPIO2_ST;
    }SCIPIO2_UN;

    union                                      /* 0x48      */
    {
     unsigned int SCIPIO3_UL;
     struct
     {
     unsigned int CLKOUT_B1: 1;
     unsigned int RXOUT_B1: 1;
     unsigned int TXOUT_B1: 1;
     unsigned int : 29;
     }SCIPIO3_ST;
    }SCIPIO3_UN;

    union                                      /* 0x4C      */
    {
     unsigned int SCIPIO4_UL;
     struct
     {
     unsigned int CLKSET_B1: 1;
     unsigned int RXSET_B1: 1;
     unsigned int TXSET_B1: 1;
     unsigned int : 29;
     }SCIPIO4_ST;
    }SCIPIO4_UN;

    union                                      /* 0x50      */
    {
     unsigned int SCIPIO5_UL;
     struct
     {
     unsigned int CLKCLR_B1: 1;
     unsigned int RXCLR_B1: 1;
     unsigned int TXCLR_B1: 1;
     unsigned int : 29;
     }SCIPIO5_ST;
    }SCIPIO5_UN;

    union                                      /* 0x54      */
    {
     unsigned int SCIPIO6_UL;
     struct
     {
     unsigned int CLKPDR_B1: 1;
     unsigned int RXPDR_B1: 1;
     unsigned int TXPDR_B1: 1;
     unsigned int : 29;
     }SCIPIO6_ST;
    }SCIPIO6_UN;

    union                                      /* 0x58      */
    {
     unsigned int SCIPIO7_UL;
     struct
     {
     unsigned int CLKPE_B1: 1;
     unsigned int RXPE_B1: 1;
     unsigned int TXPE_B1: 1;
     unsigned int : 29;
     }SCIPIO7_ST;
    }SCIPIO7_UN;

    union                                      /* 0x5C      */
    {
     unsigned int SCIPIO8_UL;
     struct
     {
     unsigned int CLKPSL_B1: 1;
     unsigned int RXPSL_B1: 1;
     unsigned int TXPSL_B1: 1;
     unsigned int : 29;
     }SCIPIO8_ST;
    }SCIPIO8_UN;

    unsigned int : 32;						/* 0x60      */
    unsigned int : 32;						/* 0x64      */
    unsigned int : 32;						/* 0x68      */
    unsigned int : 32;						/* 0x6C      */
    unsigned int : 32;						/* 0x70      */
    unsigned int : 32;						/* 0x74      */
    unsigned int : 32;						/* 0x78      */
    unsigned int : 32;						/* 0x7C      */


     union                                  /* 0x80      */
    {
     unsigned int SCIPIO9_UL;
     struct
     {
     unsigned int CLKSL_B1: 1;
     unsigned int RXSL_B1: 1;
     unsigned int TXSL_B1: 1;
     unsigned int : 29;
     }SCIPIO9_ST;
    }SCIPIO9_UN;
    
    unsigned int : 32;                        /* 0x84      */
   
    unsigned int : 32; 						  /* 0x88      */
    
    unsigned int : 32; 						  /* 0x8C		*/
    
    union                                     /* 0x90      */
    {
     unsigned int IODFT_UL;
     struct
     {
     unsigned int RXPENA_B1: 1;
     unsigned int LPBENA_B1: 1;
     unsigned int : 6;
     unsigned int IODFTENA_B4: 4;
     unsigned int : 4;
     unsigned int TX_SHIFT_B3: 3;
     unsigned int PIN_SAMPLE_MASK_B2: 2;
     unsigned int : 3;
     unsigned int BRKDTEN_B1: 1;
     unsigned int PEN_B1: 1;
     unsigned int FEN_B1: 1;
     unsigned int : 1;
     unsigned int ISFEN_B1: 1;
     unsigned int CEN_B1: 1;
     unsigned int PBEN_B1: 1;
     unsigned int BEN_B1: 1;
      }IODFT_ST;
    }IODFT_UN;

} SCI_ST;


/* ------------------------------------------------------------------------- */
/* e_SCIn_ST Instance of LIN/SCI registers, this to defined in the linker    */
/*           command file,if to be used.                                     */

extern SCI_ST e_SCI0_ST, e_SCI1_ST, e_SCI2_ST, e_SCI3_ST;

extern SCI_ST* SCI_Ptr;
extern SCI_ST* SCI1_Ptr;
extern SCI_ST* SCI2_Ptr;
extern SCI_ST* SCI3_Ptr;


/* ------------------------------------------------------------------------- */
/* SCI_CBVOID, SCI_CBADDRSTAT, SCI_CBSTATUS                                  */
/*      User supplied interrupt callback routines                            */

typedef void SCI_CBVOID();
typedef void SCI_CBADDRSTAT(UWORD Address_UW, SCIEXPT Status_N);
typedef void SCI_CBSTATUS(SCIEXPT Status_N);
typedef void SCI_ABORT(SCI_ST *Sci_PST);


/* ------------------------------------------------------------------------- */
/* Interface prototypes                                                      */

void 	SCI_ResetEnter_V(SCI_ST *Sci_PST);
void 	SCI_ResetExit_V(SCI_ST *Sci_PST);
void    SCI_SwResetEnter_V(SCI_ST *Sci_PST);
void    SCI_SwResetExit_V(SCI_ST *Sci_PST);
ULONG   SCI_Init_UL(ULONG Sci_GCR1_uL, ULONG Sci_INT0_uL, SCIPORT PortInit_N, ULONG Baud_UL, UBYTE CharSize_UB,SCI_CBVOID *CbOnBrkdt_PV, SCI_ST *Sci_PST);
void    SCI_PortInit_UL(SCIPORT PortInit1_N,SCIPORT PortInit2_N,SCI_ST *Sci_PST);
SCIEXPT SCI_PowerDownEnter_N(SCI_CBVOID *CbOnWakeUp_PV, SCI_ST *Sci_PST);
void    SCI_PowerDownExit_V(SCI_ST *Sci_PST);
void    SCI_PinModify_V(SCIPINID PinID_N, SCIQUAL PinQual_N, SCI_ST *Sci_PST);
SCIEXPT SCI_SendBreak_N(SCI_ST *Sci_PST);
SCIEXPT SCI_Send_N(UWORD BlockSize_UW, const UBYTE *Src_PUB, UWORD Address_UW, SCI_CBVOID *CbOnSend_PV, SCI_ST *Sci_PST);
SCIEXPT SCI_Receive_N(UWORD BlockSize_UW, UBYTE *Dest_PUB, SCI_CBSTATUS *CbOnReceive_PV, SCI_ST *Sci_PST);
void    SCI_TxInterrupt_V(SCI_ST *Sci_PST);
void    SCI_RxInterrupt_V(SCI_ST *Sci_PST);
void    SCI_ExptInterrupt_V(SCI_ST *Sci_PST);
SCIEXPT SCI_AwaitAddress_N(SCI_CBADDRSTAT *CbOnAddress_PV, SCI_ST *Sci_PST);
ULONG   SCI_InitEx_UL(ULONG Sci_GCR1_uL, ULONG Sci_INT0_uL, SCIPORT PortInit_N, ULONG Baud_UL, UBYTE CharSize_UB, SCI_CBVOID *CbOnBrkdt_PV, ULONG ByteTimeout_UL, BOOL CollisionDetect_B, SCI_ST *Sci_PST);
void    SCI_Abort_V(SCI_ST *Sci_PST);
SCIEXPT SCI_SendByte_N(const UBYTE Byte_UB, SCI_CBVOID *CbOnSend_PV, SCI_ST *Sci_PST);
long    SCI_ReceiveByte_L(SCI_CBSTATUS *CbOnReceive_PV, SCI_ST *Sci_PST);
void    SCI_InitDma_V(SCIDMAPRI DmaIntPri_N, SCI_ST *Sci_PST);
void    SCI_DmaCallback_V(unsigned channel);

void SCI_clean_flags(SCI_ST *Sci_PST);

/*---------------------------------------------------------------------------*/
#ifndef SCIINTERRUPT
	#define SCIINTERRUPT
#endif

#if !defined(SCIINTERRUPT) && !defined(SCIPOLLING) && !defined(SCIDMA)
#error build options SCIINTERRUPT, SCIPOLLONG or SCIDMA not defined
#endif


 
/* ------------------------------------------------------------------------- */
/* SCI_INT_ST                                                                */
/*      We need to hold global paramters for the interrupt service routine,  */
/*      one set of paramters for each SCI.  The number of SCI's is set by    */
/*      the SCICOUNT environment variable, if not set the driver assumes a   */
/*      single SCI.                                                          */

typedef struct
{
    SCI_CBVOID          *BreakAction_PV;
    SCI_CBVOID          *WakeAction_PV;
    SCI_CBADDRSTAT      *AddrAction_PV;

    SCI_CBVOID          *SendAction_PV;
    const unsigned char *Send_PUB;
    unsigned short       Address_US;
    unsigned short       SendLength_US;

    SCI_CBSTATUS        *RecvAction_PV;
    unsigned char       *Recv_PUB;
    unsigned short       RecvLength_US;

#ifdef SCIDMA
    CPCHAIN  txcp;
    CPCHAIN  rxcp;
    unsigned DmaIntPri_N;
#endif

#ifdef SCI_TIMEOUT_V
    unsigned long        ByteTimeout_UL;
    BOOL                 Timeout_B;
#endif

} SCI_INT_ST;

extern SCI_INT_ST SciInt_ST[SCICOUNT];


/* ------------------------------------------------------------------------- */
/* SCI_Index_PST                                                             */

static inline SCI_INT_ST *SCI_Index_PST(SCI_ST *Sci_PST)
{
#if SCICOUNT == 1
    return &SciInt_ST[0];
#endif

#if SCICOUNT == 2
    return Sci_PST == Sci0 ? &SciInt_ST[0] : &SciInt_ST[1];
#endif

#if SCICOUNT == 3
    return Sci_PST == Sci0 ? &SciInt_ST[0] : 
           (Sci_PST == Sci1 ? &SciInt_ST[1] : &SciInt_ST[2]);
#endif

#if SCICOUNT == 4
    return Sci_PST == Sci0 ? &SciInt_ST[0] : 
           (Sci_PST == Sci1 ? &SciInt_ST[1] : 
           (Sci_PST == Sci2 ? &SciInt_ST[2] : &SciInt_ST[3]));
#endif
}

/* ------------------------------------------------------------------------- */
/* SCI_DmaTxChannel_U                                                        */

#ifdef SCIDMA
static inline unsigned SCI_DmaTxChannel_U(SCI_ST *Sci_PST)
{
#if SCICOUNT >= 2
    if (Sci_PST == Sci1) return 15;
#endif
    return 5;
}
#endif


/* ------------------------------------------------------------------------- */
/* SCI_DmaRxChannel_U                                                        */

#ifdef SCIDMA
static inline unsigned SCI_DmaRxChannel_U(SCI_ST *Sci_PST)
{
#if SCICOUNT >= 2
    if (Sci_PST == Sci1) return 14;
#endif
    return 4;
}
#endif


/* ------------------------------------------------------------------------- */
/* SCI_DmaRxChannel_U                                                        */

static inline SCI_ST *SCI_DmaGetSci_PST(unsigned channel)
{
#if SCICOUNT >= 2
    if (channel == 14 || channel == 15) return Sci1;
#endif

//    return Sci0;
}

/* ------------------------------------------------------------------------- */
/* SCI_TIMEOUT_V                                                             */
/*      protoype of function to be provided by the OS/Application to		 */
/*      implement system dependant prototype								 */

#ifdef SCI_TIMEOUT_V
void SCI_TIMEOUT_V(unsigned Timeout_UL, SCI_ABORT *Abort_PV, SCI_ST *Sci_ST);
#endif


/* ------------------------------------------------------------------------- */

/*- End of file ------------------------------------------------------------ */


#endif

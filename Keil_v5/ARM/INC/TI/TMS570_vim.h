/* ------------------------------------------------------------------------- */
/* vim.h : VIM Module Definitions                                            */
/*                                                                           */
/* Copyright (c) Texas Instruments 1997, All right reserved.                 */
/*                                                                           */
/* History:                                                                  */
/*    Rev 1.0  01.07.03  Jean-Marc Mifsud   - jm-mifsud@ti.com               */
/*                                                                           */
/*                       Definition of VIM register set                      */
/*                                                                           */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
#if defined(_TMS470_BIG) || defined(__big_endian__)

typedef volatile struct
{
    unsigned int : 24;                         /* 0x00      */
    unsigned char IRQIVEC_UB;

    unsigned int : 24;                         /* 0x04      */
    unsigned char FIQIVEC_UB;

    unsigned int : 28;	
    unsigned int  NEST_ENABLE:4;              /* 0x08      */

    unsigned int : 16;	
    unsigned int NEST_LEVEL: 8;		
    unsigned int : 6;	
    unsigned int NEST_STAT :1; 	
    unsigned int NEST_OVRN :1;                  /* 0x0c      */

    unsigned int FIRQPR0_UL;                   /* 0x10      */

    unsigned int FIRQPR1_UL;                   /* 0x14      */

    unsigned int FIRQPR2_UL;                   /* 0x18      */

    unsigned int : 32;                         /* 0x1c      */
    
    union
    {
     unsigned int INTREQ0_UL;                   /* 0x20      */
     struct
     {
     unsigned int SYS_SW_INT_B1: 1;
     unsigned int SYS_ER_INT_B1: 1;
     unsigned int CRC_INT_B1: 1;
     unsigned int : 1;
     unsigned int RTI_INT_RQ0_B1: 1;
     unsigned int RTI_INT_RQ1_B1: 1;
     unsigned int RTI_INT_RQ2_B1: 1;
     unsigned int RTI_INT_RQ3_B1: 1;
     unsigned int RTIOVL_RQ0_B1: 1;
     unsigned int RTIOVL_RQ1_B1: 1;
     unsigned int RTITB_RQ_B1: 1;
     unsigned int : 6;
     unsigned int SCI_ER_INT_B1: 1;
     unsigned int SCI_RX_INT_B1: 1;
     unsigned int SCI_TX_INT_B1: 1;     
     unsigned int BER_INT_GA_B1: 1;
     unsigned int HBC_INT_GA_B1: 1;
     unsigned int BTC_INT_GA_B1: 1;
     unsigned int LFS_INT_GA_B1: 1;
     unsigned int FTC_INT_GA_B1: 1;
     
     

     }INTREQ0_ST;
     }INTREQ0_UN;

    unsigned int INTREQ1_UL;                   /* 0x24      */

    unsigned int INTREQ2_UL;                   /* 0x28      */

    unsigned int : 32;                         /* 0x2c      */

    unsigned int REQMASKSET0_UL;               /* 0x30      */

    unsigned int REQMASKSET1_UL;               /* 0x34      */

    unsigned int REQMASKSET2_UL;               /* 0x38      */

    unsigned int : 32;                         /* 0x3c      */

    unsigned int REQMASKCLR0_UL;               /* 0x40      */

    unsigned int REQMASKCLR1_UL;               /* 0x44      */

    unsigned int REQMASKCLR2_UL;               /* 0x48      */

    unsigned int : 32;                         /* 0x4c      */

    unsigned int WAKEMASKSET0_UL;              /* 0x50      */

    unsigned int WAKEMASKSET1_UL;              /* 0x54      */

    unsigned int WAKEMASKSET2_UL;              /* 0x58      */

    unsigned int : 32;                         /* 0x5c      */

    unsigned int WAKEMASKCLR0_UL;              /* 0x60      */

    unsigned int WAKEMASKCLR1_UL;              /* 0x64      */

    unsigned int WAKEMASKCLR2_UL;              /* 0x68      */

    unsigned int : 32;                         /* 0x6c      */

    unsigned int IRQVECREG_UL;                 /* 0x70      */

    unsigned int FIQVECREQ_UL;                 /* 0x74      */

    unsigned int : 9;                          /* 0x78      */
    unsigned int CAPEVTSRC1_B7 :7;
    unsigned int : 9;                          
    unsigned int CAPEVTSRC0_B7 :7;

    unsigned int : 32;                         /* 0x7c      */

    union					/* 0x80 */
    {
     unsigned int CHANCTRL_UL[32];

     struct
     {
   	unsigned int : 1;
	unsigned int CHANMAP0 : 7;
	unsigned int : 1;
	unsigned int CHANMAP1 : 7;
	unsigned int : 1;
	unsigned int CHANMAP2 : 7;
	unsigned int : 1;
	unsigned int CHANMAP3 : 7;
     }CHANCTRL_ST[16];
    }CHANCTRL_UN;

    unsigned int : 32;                         /* 0xc0      */

} VIM_ST;

typedef volatile struct
{
    union
    {
		unsigned int PARFLG_UL;                   /* 0xFDEC      */
		struct
		{
			unsigned int : 31;
			unsigned int PARFLG: 1;     

		} PARFLG_ST;
	}PARFLG_UN;
	union
    {
		unsigned int PARCTL_UL;                   /* 0xFDF0      */
		struct
		{
			unsigned int : 23;
			unsigned int TEST: 1;     
			unsigned int : 4;
			unsigned int PARENA: 4;     

		} PARCTL_ST;
	}PARCTL_UN;
	
	union
    {
		unsigned int ADDERR_UL;                   /* 0xFDF4      */
		struct
		{
			unsigned int : 23;
			unsigned int ADDERR: 7;     
			unsigned int : 1;
			unsigned int : 1;     

		} ADDERR_ST;
	}ADDERR_UN;

	unsigned int FBPAERR_UL;                 /* 0xFDF8      */

    
} VIM_PARITY_ST;

typedef void (*FuncPTR)(void);
typedef volatile struct
{
  FuncPTR ISR[97]; 
} VIM_RAM_ST;

extern VIM_ST 			e_VIM_ST;
extern VIM_RAM_ST 		e_VIM_RAM_ST;
extern VIM_PARITY_ST 	e_VIM_PARITY_ST;

extern VIM_ST *			VIM_Ptr ;
extern VIM_RAM_ST *		VIM_RAM_Ptr;
extern VIM_PARITY_ST * 	VIM_PARITY_Ptr;

#elif defined(_TMS470_LITTLE) || defined(__little_endian__)

typedef volatile struct
{
    unsigned char IRQIVEC_UB;	        	/* 0x00 */
    unsigned int : 24;                           

    unsigned char FIQIVEC_UB;                  /* 0x04      */
    unsigned int : 24; 
    
    unsigned int  NEST_ENABLE:4;		 /* 0x08      */
    unsigned int : 28;	           
    	
    unsigned int NEST_OVRN :1;                  /* 0x0c      */
    unsigned int NEST_STAT :1;
    unsigned int : 6;
    unsigned int NEST_LEVEL: 8;
    unsigned int : 16;	

    unsigned int FIRQPR0_UL;                   /* 0x10      */

    unsigned int FIRQPR1_UL;                   /* 0x14      */

    unsigned int FIRQPR2_UL;                   /* 0x18      */

    unsigned int : 32;                         /* 0x1c      */
    
    union
    {
     unsigned int INTREQ0_UL;                   /* 0x20      */
     struct
     {

     
     
     unsigned int FTC_INT_GA_B1: 1;
     unsigned int LFS_INT_GA_B1: 1;
     unsigned int BTC_INT_GA_B1: 1;
     unsigned int HBC_INT_GA_B1: 1;
     unsigned int BER_INT_GA_B1: 1;
     unsigned int SCI_TX_INT_B1: 1;     
     unsigned int SCI_RX_INT_B1: 1;
     unsigned int SCI_ER_INT_B1: 1;
     unsigned int : 6;
     unsigned int RTITB_RQ_B1: 1;
     unsigned int RTIOVL_RQ1_B1: 1;
     unsigned int RTIOVL_RQ0_B1: 1;
     unsigned int RTI_INT_RQ3_B1: 1;
     unsigned int RTI_INT_RQ2_B1: 1;
     unsigned int RTI_INT_RQ1_B1: 1;
     unsigned int RTI_INT_RQ0_B1: 1;
     unsigned int : 1;
     unsigned int CRC_INT_B1: 1;
     unsigned int SYS_ER_INT_B1: 1;
     unsigned int SYS_SW_INT_B1: 1;
     }INTREQ0_ST;
     }INTREQ0_UN;

    unsigned int INTREQ1_UL;                   /* 0x24      */

    unsigned int INTREQ2_UL;                   /* 0x28      */

    unsigned int : 32;                         /* 0x2c      */

    unsigned int REQMASKSET0_UL;               /* 0x30      */

    unsigned int REQMASKSET1_UL;               /* 0x34      */

    unsigned int REQMASKSET2_UL;               /* 0x38      */

    unsigned int : 32;                         /* 0x3c      */

    unsigned int REQMASKCLR0_UL;               /* 0x40      */

    unsigned int REQMASKCLR1_UL;               /* 0x44      */

    unsigned int REQMASKCLR2_UL;               /* 0x48      */

    unsigned int : 32;                         /* 0x4c      */

    unsigned int WAKEMASKSET0_UL;              /* 0x50      */

    unsigned int WAKEMASKSET1_UL;              /* 0x54      */

    unsigned int WAKEMASKSET2_UL;              /* 0x58      */

    unsigned int : 32;                         /* 0x5c      */

    unsigned int WAKEMASKCLR0_UL;              /* 0x60      */

    unsigned int WAKEMASKCLR1_UL;              /* 0x64      */

    unsigned int WAKEMASKCLR2_UL;              /* 0x68      */

    unsigned int : 32;                         /* 0x6c      */

    unsigned int IRQVECREG_UL;                 /* 0x70      */

    unsigned int FIQVECREQ_UL;                 /* 0x74      */
    			                           
    unsigned int CAPEVTSRC0_B7 :7;  		/* 0x78 */
    unsigned int : 9;  
    unsigned int CAPEVTSRC1_B7 :7;
    unsigned int : 9;  

    unsigned int : 32;                         /* 0x7c      */

     union					/* 0x80 */
    {
//     unsigned char CHANMAP[96];

     unsigned int CHANCTRL_UL[16];
     struct
     {	     
	     unsigned int CHANMAP3 : 7 ;
	     unsigned int : 1;
	     unsigned int CHANMAP2 : 7 ;
	     unsigned int : 1;
	     unsigned int CHANMAP1 : 7 ;
	     unsigned int : 1;
	     unsigned int CHANMAP0 : 7 ;
	     unsigned int : 1;

    }CHANCTRL_ST[16];
    }CHANCTRL_UN;

    unsigned int : 32;                         /* 0xc0      */

} VIM_ST;

typedef volatile struct
{
    union
    {
		unsigned int PARFLG_UL;                   /* 0xFDEC      */
		struct
		{

			unsigned int PARFLG: 1;     
			unsigned int : 31;
		} PARFLG_ST;
	}PARFLG_UN;
	union
    {
		unsigned int PARCTL_UL;                   /* 0xFDF0      */
		struct
		{

			unsigned int PARENA: 4;     
			unsigned int : 4;
			unsigned int TEST: 1;     
			unsigned int : 23;
		} PARCTL_ST;
	}PARCTL_UN;
	
	union
    {
		unsigned int ADDERR_UL;                   /* 0xFDF4      */
		struct
		{

			unsigned int : 1;     
			unsigned int : 1;
			unsigned int ADDERR: 7;     
			unsigned int : 23;
		} ADDERR_ST;
	}ADDERR_UN;

	unsigned int FBPAERR_UL;                 /* 0xFDF8      */

    
} VIM_PARITY_ST;

typedef void (*FuncPTR)(void);
typedef volatile struct
{
  FuncPTR ISR[97]; 
} VIM_RAM_ST;

extern VIM_ST 			e_VIM_ST;
extern VIM_RAM_ST 		e_VIM_RAM_ST;
extern VIM_PARITY_ST 	e_VIM_PARITY_ST;

extern VIM_ST *			VIM_Ptr ;
extern VIM_RAM_ST *		VIM_RAM_Ptr;
extern VIM_PARITY_ST * 	VIM_PARITY_Ptr;

#endif

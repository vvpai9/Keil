/* ------------------------------------------------------------------------- */
/* rti.h : RTI Module Definitions                                            */
/*                                                                           */
/* Copyright (c) Texas Instruments 1997, All right reserved.                 */
/*                                                                           */
/* History:                                                                  */
/*    Rev 1.0  01.13.03  Jean-Marc Mifsud   - jm-mifsud@ti.com               */
/*                                                                           */
/*                       Definition of RTI register set                      */
/*                                                                           */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */

/********************************************************************************
Revision History : 0.2 			06/06/08
Modified by srinath vaddepally (x0069190) to add new register and bits 
Registers added were 
1)RTIWWDRXNCTRL (0xA4)
2)RTIWWDSIZECTRL (0xA8)
3)RTIINTCLRENABLE  (0xAC)
4)RTICOMP0CLR (0xB0)
5)RTICOMP1CLR (0xB4)
6)RTICOMP2CLR (0xB8)
7)RTICOMP3CLR (0xBC)

new bits have added to folowing registers
1)RTIWDSTATUS (0x0)
2)RTIGCTRL  (0x98)

*/

/********************************************************************************/
/****  				contents of rti_def.h   						*************/
/********************************************************************************/


#define RTICOMPINT0  0
#define RTICOMPINT1  1
#define RTICOMPINT2  2
#define RTICOMPINT3  3









#if defined(_TMS470_BIG) || defined(__big_endian__)

typedef volatile struct
{
    union                                      /* 0x00      */ // modified by srinath  since new bits have added 
    {
     unsigned int RTIGCTRL_UL; 
     struct
     {
      unsigned int : 14;
      unsigned int NTUSEL_B2 : 2;
      unsigned int COS_B1 :1;
      unsigned int : 13;                          
      unsigned int CNT1EN_B1 :1;
      unsigned int CNT0EN_B1 :1;
     }RTIGCTRL_ST;
    }RTIGCTRL_UN;

    union                                      /* 0x04      */
    {
     unsigned int RTITBCTRL_UL; 
     struct
     {
      unsigned int : 30;
      unsigned int INC_B1 :1;
      unsigned int TBEXT_B1 :1;
     }RTITBCTRL_ST;
    }RTITBCTRL_UN;

    union                                      /* 0x08      */
    {
     unsigned int RTICAPCTRL_UL; 
     struct
     {
      unsigned int : 30;
      unsigned int CAPCNTR1_B1 :1;
      unsigned int CAPCNTR0_B1 :1;
     }RTICAPCTRL_ST;
    }RTICAPCTRL_UN;

    union                                      /* 0x0c      */
    {
     unsigned int RTICOMPCTRL_UL; 
     struct
     {
      unsigned int : 16;
      unsigned int : 3;
      unsigned int COMPSEL3_B1 :1;
      unsigned int : 3;
      unsigned int COMPSEL2_B1 :1;
      unsigned int : 3;
      unsigned int COMPSEL1_B1 :1;
      unsigned int : 3;
      unsigned int COMPSEL0_B1 :1;
     }RTICOMPCTRL_ST;
    }RTICOMPCTRL_UN;

    unsigned int RTIFRC0_UL;                  /* 0x10      */

    unsigned int RTIUC0_UL;                   /* 0x14      */

    unsigned int RTICPUC0_UL;                 /* 0x18      */

    unsigned int :32;                         /* 0x1c      */

    unsigned int RTICAFRC0_UL;                /* 0x20      */

    unsigned int RTICAUC0_UL;                 /* 0x24      */

    unsigned int :32;                         /* 0x28      */

    unsigned int :32;                         /* 0x2c      */

    unsigned int RTIFRC1_UL;                  /* 0x30      */

    unsigned int RTIUC1_UL;                   /* 0x34      */

    unsigned int RTICPUC1_UL;                 /* 0x38      */

    unsigned int :32;                         /* 0x3c      */

    unsigned int RTICAFRC1_UL;                /* 0x40      */

    unsigned int RTICAUC1_UL;                 /* 0x44      */

    unsigned int :32;                         /* 0x48      */

    unsigned int :32;                         /* 0x4c      */

    unsigned int RTICOMP0_UL;                 /* 0x50      */

    unsigned int RTIUDCP0_UL;                 /* 0x54      */

    unsigned int RTICOMP1_UL;                 /* 0x58      */

    unsigned int RTIUDCP1_UL;                 /* 0x5c      */

    unsigned int RTICOMP2_UL;                 /* 0x60      */

    unsigned int RTIUDCP2_UL;                 /* 0x64      */

    unsigned int RTICOMP3_UL;                 /* 0x68      */

    unsigned int RTIUDCP3_UL;                 /* 0x6c      */

    unsigned int RTITBLCOMP_UL;               /* 0x70      */

    unsigned int RTITBHCOMP_UL;               /* 0x74      */

    unsigned int :32;                         /* 0x78      */

    unsigned int :32;                         /* 0x7c      */

    union                                     /* 0x80      */
    {
     unsigned int RTISETINT_UL; 
     struct
     {
      unsigned int : 13;
      unsigned int SETOVL1INT_B1 :1;
      unsigned int SETOVL0INT_B1 :1;
      unsigned int SETTBINT_B1 :1;
      unsigned int : 4;
      unsigned int SETDMA3_B1 :1;
      unsigned int SETDMA2_B1 :1;
      unsigned int SETDMA1_B1 :1;
      unsigned int SETDMA0_B1 :1;
      unsigned int : 4;
      unsigned int SETINT3_B1 :1;
      unsigned int SETINT2_B1 :1;
      unsigned int SETINT1_B1 :1;
      unsigned int SETINT0_B1 :1;
     }RTISETINT_ST;
    }RTISETINT_UN;

    union                                     /* 0x84      */
    {
     unsigned int RTICLEARINT_UL; 
     struct
     {
      unsigned int : 13;
      unsigned int CLEAROVL1INT_B1 :1;
      unsigned int CLEAROVL0INT_B1 :1;
      unsigned int CLEARBINT_B1 :1;
      unsigned int : 4;
      unsigned int CLEARDMA3_B1 :1;
      unsigned int CLEARDMA2_B1 :1;
      unsigned int CLEARDMA1_B1 :1;
      unsigned int CLEARDMA0_B1 :1;
      unsigned int : 4;
      unsigned int CLEARINT3_B1 :1;
      unsigned int CLEARINT2_B1 :1;
      unsigned int CLEARINT1_B1 :1;
      unsigned int CLEARINT0_B1 :1;
     }RTICLEARINT_ST;
    }RTICLEARINT_UN;

    union                                     /* 0x88      */
    {
     unsigned int RTIINTFLAG_UL; 
     struct
     {
      unsigned int : 13;
      unsigned int OVL1INT_B1 :1;
      unsigned int OVL0INT_B1 :1;
      unsigned int TBINT_B1 :1;
      unsigned int : 12;
      unsigned int INT3_B1 :1;
      unsigned int INT2_B1 :1;
      unsigned int INT1_B1 :1;
      unsigned int INT0_B1 :1;
     }RTIINTFLAG_ST;
    }RTIINTFLAG_UN;

    unsigned int :32;                         /* 0x8c      */

    unsigned int RTIDWDCTRL_UL;               /* 0x90      */
    
    union                                     /* 0x94      */
    {
     unsigned int RTIDWDPRLD_UL; 
     struct
     {
      unsigned int : 20;
      unsigned int DWDPRLD : 12;
     }RTIDWDPRLD_ST;
    }RTIDWDPRLD_UN;
    
    union                                     /* 0x98      */  // modified by srinath since new staus bits have been added 
    {
     unsigned int RTIWDSTATUS_UL; 
     struct
     {
      unsigned int : 26;
	  unsigned int DWWDST_B1 :1;
	  unsigned int ENDTIMEVIOL_B1 :1;
      unsigned int STARTTIMEVIOL_B1 :1;
      unsigned int KEYST_B1 : 1;
      unsigned int DWDST_B1 : 1;
      unsigned int AWDST_B1 : 1;
     }RTIWDSTATUS_ST;
    }RTIWDSTATUS_UN;
    
    union                                     /* 0x9c      */
    {
     unsigned int RTIWDKEY_UL; 
     struct
     {
      unsigned int : 16;
      unsigned int WDKEY : 16;
     }RTIWDKEY_ST;
    }RTIWDKEY_UN;
    
    union                                     /* 0xa0      */
    {
     unsigned int RTIDWDCNTR_UL; 
     struct
     {
      unsigned int : 8;
      unsigned int DWDCNTR : 24;
     }RTIDWDCNTR_ST;
    }RTIDWDCNTR_UN;
  /****************************** added by srinath *********************************/  
   union                                     /* 0xa4      */
    {
     unsigned int RTIWWDRXNCTRL_UL; 
     struct
     {
      unsigned int : 28;
      unsigned int WWDRXN : 4;
     }RTIWWDRXNCTRL_ST;
    }RTIWWDRXNCTRL_UN;
  union                                     /* 0xa8      */
    {
     unsigned int RTIWWDSIZECTRL_UL; 
     struct
     {
         unsigned int WWDSIZE : 32;
     }RTIWWDSIZECTRL_ST;
    }RTIWWDSIZECTRL_UN;
    union                                     /* 0xac      */
    {
     unsigned int RTIINTCLRENABLE_UL; 
     struct
     {
       unsigned int : 4;
       unsigned int INTCLRENABLE3_B4 : 4;
       unsigned int : 4;
	   unsigned int INTCLRENABLE2_B4 : 4;
       unsigned int : 4;
	   unsigned int INTCLRENABLE1_B4 : 4;
       unsigned int : 4;
	   unsigned int INTCLRENABLE0_B4 : 4;

     }RTIINTCLRENABLE_ST;
    }RTIINTCLRENABLE_UN;

  
unsigned int RTICOMP0CLR_UL;                 /* 0xb0      */  
unsigned int RTICOMP1CLR_UL;                 /* 0xb40      */  
unsigned int RTICOMP2CLR_UL;                 /* 0xb8      */ 
unsigned int RTICOMP3CLR_UL;                 /* 0xbc      */ 
  /* union                                     // 0xb0    
    {
     unsigned int RTICOMP0CLR_UL; 
     struct
     {

      unsigned int COMP0CLR : 32;
     }RTICOMP0CLR_ST;
    }RTICOMP0CLR_UN;

 union                                     // 0xb4      
    {
     unsigned int RTICOMP1CLR_UL; 
     struct
     {

      unsigned int COMP1CLR : 32;
     }RTICOMP1CLR_ST;
    }RTICOMP1CLR_UN;

   union                                     // 0xb8      
    {
     unsigned int RTICOMP2CLR_UL; 
     struct
     {

      unsigned int COMP2CLR : 32;
     }RTICOMP2CLR_ST;
    }RTICOMP2CLR_UN;
  
   
    union                                     // 0xbc      
    {
     unsigned int RTICOMP3CLR_UL; 
     struct
     {

      unsigned int COMP3CLR : 32;
     }RTICOMP3CLR_ST;
    }RTICOMP3CLR_UN;*/






    
} RTI_ST;


extern RTI_ST e_RTI_ST,e_RTI0_ST,e_RTI1_ST;
extern RTI_ST * RTI_Ptr;



/****************************************************/
/***        little indian 			****************/
/****************************************************/



#elif defined(_TMS470_LITTLE) || defined(__little_endian__)
#define RTICOMPINT0  0
#define RTICOMPINT1  1
#define RTICOMPINT2  2
#define RTICOMPINT3  3










typedef volatile struct
{
    union                                      /* 0x00      */
    {
     unsigned int RTIGCTRL_UL; 
     struct
     {
      unsigned int CNT0EN_B1 :1;
      unsigned int CNT1EN_B1 :1;
      unsigned int : 13;                          
      unsigned int COS_B1 :1;
      unsigned int NTUSEL_B2 : 2;
      unsigned int : 14;
     }RTIGCTRL_ST;
    }RTIGCTRL_UN;

    union                                      /* 0x04      */
    {
     unsigned int RTITBCTRL_UL; 
     struct
     {
      unsigned int TBEXT_B1 :1;
      unsigned int INC_B1 :1;
      unsigned int : 30;
     }RTITBCTRL_ST;
    }RTITBCTRL_UN;

    union                                      /* 0x08      */
    {
     unsigned int RTICAPCTRL_UL; 
     struct
     {
      unsigned int CAPCNTR0_B1 :1;
      unsigned int CAPCNTR1_B1 :1;
      unsigned int : 30;
     }RTICAPCTRL_ST;
    }RTICAPCTRL_UN;

    union                                      /* 0x0c      */
    {
     unsigned int RTICOMPCTRL_UL; 
     struct
     {
      unsigned int COMPSEL0_B1 :1;
      unsigned int : 3;
      unsigned int COMPSEL1_B1 :1;
      unsigned int : 3;
      unsigned int COMPSEL2_B1 :1;
      unsigned int : 3;
      unsigned int COMPSEL3_B1 :1;
      unsigned int : 3;
      unsigned int : 16;
     }RTICOMPCTRL_ST;
    }RTICOMPCTRL_UN;

    unsigned int RTIFRC0_UL;                  /* 0x10      */

    unsigned int RTIUC0_UL;                   /* 0x14      */

    unsigned int RTICPUC0_UL;                 /* 0x18      */

    unsigned int :32;                         /* 0x1c      */

    unsigned int RTICAFRC0_UL;                /* 0x20      */

    unsigned int RTICAUC0_UL;                 /* 0x24      */

    unsigned int :32;                         /* 0x28      */

    unsigned int :32;                         /* 0x2c      */

    unsigned int RTIFRC1_UL;                  /* 0x30      */

    unsigned int RTIUC1_UL;                   /* 0x34      */

    unsigned int RTICPUC1_UL;                 /* 0x38      */

    unsigned int :32;                         /* 0x3c      */

    unsigned int RTICAFRC1_UL;                /* 0x40      */

    unsigned int RTICAUC1_UL;                 /* 0x44      */

    unsigned int :32;                         /* 0x48      */

    unsigned int :32;                         /* 0x4c      */

    unsigned int RTICOMP0_UL;                 /* 0x50      */

    unsigned int RTIUDCP0_UL;                 /* 0x54      */

    unsigned int RTICOMP1_UL;                 /* 0x58      */

    unsigned int RTIUDCP1_UL;                 /* 0x5c      */

    unsigned int RTICOMP2_UL;                 /* 0x60      */

    unsigned int RTIUDCP2_UL;                 /* 0x64      */

    unsigned int RTICOMP3_UL;                 /* 0x68      */

    unsigned int RTIUDCP3_UL;                 /* 0x6c      */

    unsigned int RTITBLCOMP_UL;               /* 0x70      */

    unsigned int RTITBHCOMP_UL;               /* 0x74      */

    unsigned int :32;                         /* 0x78      */

    unsigned int :32;                         /* 0x7c      */

    union                                     /* 0x80      */
    {
     unsigned int RTISETINT_UL; 
     struct
     {
      unsigned int SETINT0_B1 :1;
      unsigned int SETINT1_B1 :1;
      unsigned int SETINT2_B1 :1;
      unsigned int SETINT3_B1 :1;
      unsigned int : 4;
      unsigned int SETDMA0_B1 :1;
      unsigned int SETDMA1_B1 :1;
      unsigned int SETDMA2_B1 :1;
      unsigned int SETDMA3_B1 :1;
      unsigned int : 4;
      unsigned int SETTBINT_B1 :1;
      unsigned int SETOVL0INT_B1 :1;
      unsigned int SETOVL1INT_B1 :1;
      unsigned int : 13;
     }RTISETINT_ST;
    }RTISETINT_UN;

    union                                     /* 0x84      */
    {
     unsigned int RTICLEARINT_UL; 
     struct
     {
      unsigned int CLEARINT0_B1 :1;
      unsigned int CLEARINT1_B1 :1;
      unsigned int CLEARINT2_B1 :1;
      unsigned int CLEARINT3_B1 :1;
      unsigned int : 4;
      unsigned int CLEARDMA0_B1 :1;
      unsigned int CLEARDMA1_B1 :1;
      unsigned int CLEARDMA2_B1 :1;
      unsigned int CLEARDMA3_B1 :1;
      unsigned int : 4;
      unsigned int CLEARBINT_B1 :1;
      unsigned int CLEAROVL0INT_B1 :1;
      unsigned int CLEAROVL1INT_B1 :1;
      unsigned int : 13;
     }RTICLEARINT_ST;
    }RTICLEARINT_UN;

    union                                     /* 0x88      */
    {
     unsigned int RTIINTFLAG_UL; 
     struct
     {
      unsigned int INT0_B1 :1;
      unsigned int INT1_B1 :1;
      unsigned int INT2_B1 :1;
      unsigned int INT3_B1 :1;
      unsigned int : 12;
      unsigned int TBINT_B1 :1;
      unsigned int OVL0INT_B1 :1;
      unsigned int OVL1INT_B1 :1;
      unsigned int : 13;
     }RTIINTFLAG_ST;
    }RTIINTFLAG_UN;

    unsigned int :32;                         /* 0x8c      */

    unsigned int RTIDWDCTRL_UL;               /* 0x90      */
    
    union                                     /* 0x94      */
    {
     unsigned int RTIDWDPRLD_UL; 
     struct
     {
      unsigned int DWDPRLD : 12;
      unsigned int : 20;
     }RTIDWDPRLD_ST;
    }RTIDWDPRLD_UN;
    
    union                                     /* 0x98      */
    {
     unsigned int RTIWDSTATUS_UL; 
     struct
     {
      unsigned int AWDST_B1 : 1;
      unsigned int DWDST_B1 : 1;
      unsigned int KEYST_B1 : 1;
      unsigned int STARTTIMEVIOL_B1 :1;
	  unsigned int ENDTIMEVIOL_B1 :1;
	  unsigned int DWWDST_B1 :1;
      unsigned int : 26;
     }RTIWDSTATUS_ST;
    }RTIWDSTATUS_UN;
    
    union                                     /* 0x9c      */
    {
     unsigned int RTIWDKEY_UL; 
     struct
     {
      unsigned int WDKEY : 16;
      unsigned int : 16;
     }RTIWDKEY_ST;
    }RTIWDKEY_UN;
    
    union                                     /* 0xa0      */
    {
     unsigned int RTIDWDCNTR_UL; 
     struct
     {
      unsigned int DWDCNTR : 24;
      unsigned int : 8;
     }RTIDWDCNTR_ST;
    }RTIDWDCNTR_UN;

/****************************** added by srinath *********************************/  

 union                                     /* 0xa4      */
    {
     unsigned int RTIWWDRXNCTRL_UL; 
     struct
     {
      unsigned int WWDRXN : 4;
      unsigned int : 28;

     }RTIWWDRXNCTRL_ST;
    }RTIWWDRXNCTRL_UN;
    
   union                                     /* 0xa8      */
    {
     unsigned int RTIWWDSIZECTRL_UL; 
     struct
     {
         unsigned int WWDSIZE : 32;
     }RTIWWDSIZECTRL_ST;
    }RTIWWDSIZECTRL_UN;

	union                                     /* 0xac      */
    {
     unsigned int RTIINTCLRENABLE_UL; 
     struct
     {

       unsigned int INTCLRENABLE0_B4 : 4;
       unsigned int : 4;
	   unsigned int INTCLRENABLE1_B4 : 4;
       unsigned int : 4;
	   unsigned int INTCLRENABLE2_B4 : 4;
       unsigned int : 4;
	   unsigned int INTCLRENABLE3_B4 : 4;
       unsigned int : 4;

     }RTIINTCLRENABLE_ST;
    }RTIINTCLRENABLE_UN;

unsigned int RTICOMP0CLR_UL;                 /* 0xb0      */  
unsigned int RTICOMP1CLR_UL;                 /* 0xb40      */  
unsigned int RTICOMP2CLR_UL;                 /* 0xb8      */ 
unsigned int RTICOMP3CLR_UL;                 /* 0xbc      */ 

     
} RTI_ST;

extern RTI_ST e_RTI_ST,e_RTI0_ST,e_RTI1_ST;
extern RTI_ST * RTI_Ptr;


#endif

/* ------------------------------------------------------------------------- */
/* system.h : SYSTEM Module Definitions                                      */
/*                                                                           */
/* Copyright (c) Texas Instruments 1997, All right reserved.                 */
/*                                                                           */
/* History:                                                                  */
/*    Rev 1.0  01.08.03  Jean-Marc Mifsud   - jm-mifsud@ti.com               */
/*                                                                           */
/*                       Definition of SYSTEM register set                   */
/*                                                                           */
/*    Rev 1.1  09.27.04  Rejith Kunnummal   - rejith@ti.com                  */
/*                       Updated registers definition according to spec      */
/*                       ver A6                                              */
/*                                                                           */
/*    Rev 1.2  13.09.05  Karthik            - rkarthik@ti.com		     */
/*			 Updated the memory related registers definition     */
/*			 from 0x58 to 0x6C according to spec ver A10	     */
/*                                                               */ 
/*    Rev 1.3  02.03.06  chidan            - x0051587@ti.com		     */
/*			 Updated the memory related registers definition     */
/*			 SSWPLL1, SSWPLL2, SSWPLL3,CLKTEST,LPOMONCTL... according to spec ver A13	     */
/*												     */
/*    Rev 1.4  01.15.2009 Ashwin.R    - x0069183@ti.com		           */
/*                 Added the System Frame2 registers 				     */
/* ------------------------------------------------------------------------- */
/*												     */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
#if defined(_TMS470_BIG) || defined(__big_endian__)

typedef volatile struct
{
    union                                      /* 0x00      */
    {
     unsigned int SYSPC1_UL; 
     struct
     {
     unsigned int : 31;                        
     unsigned int ECPCLK_FUN_B1: 1;
     }SYSPC1_ST;
    }SYSPC1_UN;

    union                                      /* 0x04      */
    {
     unsigned int SYSPC2_UL; 
     struct
     {
     unsigned int : 31;                        
     unsigned int ECPCLK_DIR_B1: 1;
     }SYSPC2_ST;
    }SYSPC2_UN;

    union                                      /* 0x08      */
    {
     unsigned int SYSPC3_UL; 
     struct
     {
     unsigned int : 31;                        
     unsigned int ECPCLK_DIN_B1: 1;
     }SYSPC3_ST;
    }SYSPC3_UN;

    union                                      /* 0x0c      */
    {
     unsigned int SYSPC4_UL; 
     struct
     {
     unsigned int : 31;                        
     unsigned int ECPCLK_DOUT_B1: 1;
     }SYSPC4_ST;
    }SYSPC4_UN;
 
    union                                      /* 0x10      */
    {
     unsigned int SYSPC5_UL; 
     struct
     {
     unsigned int : 31;                        
     unsigned int ECPCLK_SET_B1: 1;
     }SYSPC5_ST;
    }SYSPC5_UN;

    union                                      /* 0x14      */
    {
     unsigned int SYSPC6_UL; 
     struct
     {
     unsigned int : 31;                        
     unsigned int ECPCLK_CLR_B1: 1;
     }SYSPC6_ST;
    }SYSPC6_UN;

    union                                      /* 0x18      */
    {
     unsigned int SYSPC7_UL; 
     struct
     {
     unsigned int : 31;                        
     unsigned int ECPCLK_ODE_B1: 1;
     }SYSPC7_ST;
    }SYSPC7_UN;

    union                                      /* 0x1c      */
    {
     unsigned int SYSPC8_UL; 
     struct
     {
     unsigned int : 31;                        
     unsigned int ECPCLK_PLE_B1: 1;
     }SYSPC8_ST;
    }SYSPC8_UN;

    union                                      /* 0x20      */
    {
     unsigned int SYSPC9_UL; 
     struct
     {
     unsigned int : 31;                        
     unsigned int ECPCLK_PS_B1: 1;
     }SYSPC9_ST;
    }SYSPC9_UN;

    union                                      /* 0x24      */
    {
     unsigned int SSWPLL1_UL; 
     struct
     {
     unsigned int : 16;                        
     unsigned int MOD_PH_CAP_INDEX_B8: 8;
     unsigned int : 1;
	 unsigned int COUNTER_READ_READY_B1: 1;
     unsigned int COUNTER_RESET_B1 : 1;
     unsigned int COUNTER_EN_B1 : 1;
     unsigned int TAP_COUNTER_DIS_B3 : 3;
	 unsigned int EXT_COUNTER_EN_B1 : 1;
     }SSWPLL1_ST;
    }SSWPLL1_UN;

    unsigned int SSWPLL2_UL;   /* 0x28      */
    
    unsigned int SSWPLL3_UL; /* 0x2C      */
                
    union                                      /* 0x30      */
    {
     unsigned int CSDIS_UL; 
     struct
     {
     unsigned int : 24;           
     unsigned int CLKSR7OFF_B1: 1;
     unsigned int CLKSR6OFF_B1: 1;
     unsigned int CLKSR5OFF_B1: 1;
     unsigned int CLKSR4OFF_B1: 1;
     unsigned int CLKSR3OFF_B1: 1;
     unsigned int CLKSR2OFF_B1: 1;
     unsigned int CLKSR1OFF_B1: 1;             
     unsigned int CLKSR0OFF_B1: 1;
     }CSDIS_ST;
    }CSDIS_UN;
    
    union                                      /* 0x34      */
    {
     unsigned int CSDISSET_UL; 
     struct
     {
     unsigned int : 24;           
     unsigned int SETCLKSR8OFF_B1: 1;
     unsigned int SETCLKSR7OFF_B1: 1;
     unsigned int SETCLKSR6OFF_B1: 1;
     unsigned int SETCLKSR5OFF_B1: 1;
     unsigned int SETCLKSR4OFF_B1: 1;
     unsigned int SETCLKSR3OFF_B1: 1;
     unsigned int SETCLKSR2OFF_B1: 1;             
     unsigned int SETCLKSR1OFF_B1: 1;
     }CSDISSET_ST;
    }CSDISSET_UN;
    
    union                                      /* 0x38      */
    {
     unsigned int CSDISCLR_UL; 
     struct
     {
     unsigned int : 24;           
     unsigned int CLRCLKSR8OFF_B1: 1;
     unsigned int CLRCLKSR7OFF_B1: 1;
     unsigned int CLRCLKSR6OFF_B1: 1;
     unsigned int CLRCLKSR5OFF_B1: 1;
     unsigned int CLRCLKSR4OFF_B1: 1;
     unsigned int CLRCLKSR3OFF_B1: 1;
     unsigned int CLRCLKSR2OFF_B1: 1;             
     unsigned int CLRCLKSR1OFF_B1: 1;
     }CSDISCLR_ST;
    }CSDISCLR_UN;
    
    union                                      /* 0x3c      */
    {
     unsigned int CDDIS_UL; 
     struct
     {
     unsigned int : 24;           
     unsigned int RTICLK2OFF_B1: 1;
     unsigned int RTICLK1OFF_B1: 1;
     unsigned int VCLKA2OFF_B1: 1;
     unsigned int VCLKA1OFF_B1: 1;
     unsigned int VCLK2OFF_B1: 1;
     unsigned int VCLKPOFF_B1: 1;
     unsigned int HCLKOFF_B1: 1;             
     unsigned int GCLKOFF_B1: 1;
     }CDDIS_ST;
    }CDDIS_UN;
    
    union                                      /* 0x40      */
    {
     unsigned int CDDISSET_UL; 
     struct
     {
     unsigned int : 24;           
     unsigned int SETRTICLK2OFF_B1: 1;
     unsigned int SETRTICLK1OFF_B1: 1;
     unsigned int SETVCLKA2OFF_B1: 1;
     unsigned int SETVCLKA1OFF_B1: 1;
     unsigned int SETVCLK2OFF_B1: 1;
     unsigned int SETVCLKPOFF_B1: 1;
     unsigned int SETHCLKOFF_B1: 1;             
     unsigned int SETGCLKOFF_B1: 1;
     }CDDISSET_ST;
    }CDDISSET_UN;
    
    union                                      /* 0x44      */
    {
     unsigned int CDDISCLR_UL; 
     struct
     {
     unsigned int : 24;           
     unsigned int CLRRTICLK2OFF_B1: 1;
     unsigned int CLRRTICLK1OFF_B1: 1;
     unsigned int CLRVCLKA2OFF_B1: 1;
     unsigned int CLRVCLKA1OFF_B1: 1;
     unsigned int CLRVCLK2OFF_B1: 1;
     unsigned int CLRVCLKPOFF_B1: 1;
     unsigned int CLRHCLKOFF_B1: 1;             
     unsigned int CLRGCLKOFF_B1: 1;
     }CDDISCLR_ST;
    }CDDISCLR_UN;
    
    union                                      /* 0x48      */
    {
     unsigned int GHVSRC_UL; 
     struct
     {
     unsigned int : 4;           
     unsigned int GHVWAKE_B4: 4;
     unsigned int : 4;           
     unsigned int HVLPM_B4: 4;
     unsigned int : 12;           
     unsigned int GHVSRC_B4: 4;
     }GHVSRC_ST;
    }GHVSRC_UN;
    
    union                                      /* 0x4c      */
    {
     unsigned int VCLKASRC_UL; 
     struct
     {
     unsigned int : 20;           
     unsigned int VCLKA2S_B4: 4;
     unsigned int : 4;           
     unsigned int VCLKA1S_B4: 4;
     }VCLKASRC_ST;
    }VCLKASRC_UN;
    
    union                                      /* 0x50      */
    {
     unsigned int RCLKSRC_UL; 
     struct
     {
     unsigned int : 6;           
	 unsigned int RTI2DIV_B2 : 2;
	 unsigned int : 4;
     unsigned int RTI2SRC_B4 : 4;
     unsigned int : 6;
     unsigned int RTI1DIV_B2: 2;
	 unsigned int : 4;
	 unsigned int RTI1SRC_B4: 4;  
     }RCLKSRC_ST;
    }RCLKSRC_UN;
    
    union                                      /* 0x54      */
    {
     unsigned int CSVSTAT_UL; 
     struct
     {
     unsigned int : 24;           
     unsigned int CLKSR8V_B1: 1;
     unsigned int CLKSR7V_B1: 1;
     unsigned int CLKSR6V_B1: 1;
     unsigned int CLKSR5V_B1: 1;
     unsigned int CLKSR4V_B1: 1;
     unsigned int CLKSR3V_B1: 1;
     unsigned int CLKSR2V_B1: 1;             
     unsigned int CLKSR1V_B1: 1;
     }CSVSTAT_ST;
    }CSVSTAT_UN;

    union                                      /* 0x58      */
    {
     unsigned int MSTGCR_UL; 
     struct
     {
	 unsigned int : 8;
	 unsigned int MBIST_ALGSEL_B8 : 8;
     unsigned int : 6;
     unsigned int ROM_DIV_B2 : 2;
	 unsigned int : 4;
     unsigned int MSTGENA_B4: 4;
     }MSTGCR_ST;
    }MSTGCR_UN;

    union                                      /* 0x5C      */
    {
     unsigned int MINITGCR_UL; 
     struct
     {
     unsigned int : 28;
     unsigned int MINITGENA_B4: 4;
     }MINITGCR_ST;
    }MINITGCR_UN;

    unsigned int MSINENA_UL; 		      	/* 0x60      */
    
    unsigned int MSTFAIL_UL;		     	/* 0x64      */

    union                                      	/* 0x68      */
    {
     unsigned int MSTCGSTAT_UL; 
     struct
     {
     unsigned int : 23;
     unsigned int MINIDONE_B1: 1;
     unsigned int : 7;
     unsigned int MSTDONE_B1: 1;
     }MSTCGSTAT_ST;
    }MSTCGSTAT_UN;

  

     unsigned int MINISTAT_UL;		       	/* 0x6C      */

    
    union                                      /* 0x70      */
    {
     unsigned int PLLCTL1_UL; 
     struct
     {
     unsigned int ROS_B1 : 1; 
     unsigned int : 7;           
     unsigned int ROF_B1: 1;
     unsigned int OSCDIV_B1: 1;
     unsigned int : 9;           
     unsigned int PLL_MUL_B5: 5;
     unsigned int : 3;           
     unsigned int PLL_DIV_B5: 5;
     }PLLCTL1_ST;
    }PLLCTL1_UN;
        
    union                                      /* 0x74      */
    {
     unsigned int PLLCTL2_UL; 
     struct
     {
     unsigned int : 8;           
     unsigned int FM_ENA_B1: 1;
     unsigned int : 9;           
     unsigned int PLL_MODFREQ_B6: 6;
     unsigned int : 3;           
     unsigned int PLL_MDEPTH_B5: 5;
     }PLLCTL2_ST;
    }PLLCTL2_UN;
        
    unsigned int : 32;       /*UERRFLAG removed */  /* 0x78      */
    
    

    unsigned int DIEIDL_UL;                    /* 0x7C      */

    unsigned int DIEIDH_UL;                    /* 0x80      */
    
    union                                      /* 0x84      */
    {
     unsigned int VRCTL_UL; 
     struct
     {
     unsigned int : 24;           
     unsigned int VLPMENA_B4: 4;
     unsigned int SLEEPENA_B4: 4;
     }VRCTL_ST;
    }VRCTL_UN;
    
	 union                                      /* 0x88      */
    {
     unsigned int LPOMONCTL_UL; 
     struct
     {
     unsigned int : 7;           
     unsigned int BIAS_ENABLE_B1 : 1;
	 unsigned int : 12;
     unsigned int HFTRIM_B4: 4;
	 unsigned int : 4;
	 unsigned int LFTRIM_B4 : 4;
     }LPOMONCTL_ST;
    }LPOMONCTL_UN;
                             
	union                                      /* 0x8C      */
    {
     unsigned int CLKTEST_UL; 
     struct
     {
     unsigned int : 5;           
     unsigned int ALTLIMPCLOCKENABLE_B1 : 1;
	 unsigned int RANGEDETCTRL_B1 : 1;
	 unsigned int RANGEDETENSSEL_B1 : 1;
	 unsigned int : 4;
	 unsigned int CLK_TEST_EN_B4 : 4;
	 unsigned int : 4;
	 unsigned int SEL_GIO_PIN_B4 : 4;
	 unsigned int : 4;
	 unsigned int SEL_ECP_PIN_B4 : 4;
     }CLKTEST_ST;
    }CLKTEST_UN;
    

    unsigned int : 32;                         /* 0x90      */
    
    unsigned int : 32;                         /* 0x94      */

    unsigned int : 32;                         /* 0x98      */

    unsigned int : 32;                         /* 0x9c      */

    unsigned int : 32;                         /* 0xa0      */

   union                                       /* 0xa4      */
   {
     unsigned int BTRMSEL_UL; 
     struct
     {
     unsigned int BTRMSLRST_B16: 16;           
     unsigned int : 12;
     unsigned int BTRMSEL_B4: 4;
     }BTRMSEL_ST;
    }BTRMSEL_UN;           

	union                                       /* 0xa8      */
   {
     unsigned int IMPFASTS_UL; 
     struct
     {
     unsigned int : 8;           
     unsigned int MASTERID_B8: 8;
	 unsigned int : 5;
	 unsigned int EMIFA_B1 : 1;
	 unsigned int NCBA_B1 : 1;
	 unsigned int VBUSA : 1;
     unsigned int : 7;
	 unsigned int ATYPE : 1;
    }IMPFASTS_ST;
   }IMPFASTS_UN;      
                
    unsigned int IMPFTADD_UL;                  /* 0xac      */

    union
    {
     unsigned int SSISR1_UL;                   /* 0xb0      */
     struct
     {
      unsigned int :16;
      unsigned int SSKEY2_UB  : 8;
      unsigned int SSDATA2_UB : 8;
     } SSISR1_ST;
    }SSISR1_UN;

    union
    {
     unsigned int SSISR2_UL;                   /* 0xb4      */
     struct
     {
      unsigned int :16;
      unsigned int SSKEY1_UB  : 8;
      unsigned int SSDATA1_UB : 8;
     } SSISR2_ST;
    }SSISR2_UN;

    union
    {
     unsigned int SSISR3_UL;                   /* 0xb8      */
     struct
     {
      unsigned int :16;
      unsigned int SSKEY3_UB  : 8;
      unsigned int SSDATA3_UB : 8;
     } SSISR3_ST;
    }SSISR3_UN;

    union
    {
     unsigned int SSISR4_UL;                   /* 0xbc      */
     struct
     {
      unsigned int :16;
      unsigned int SSKEY4_UB  : 8;
      unsigned int SSDATA4_UB : 8;
     } SSISR4_ST;
    }SSISR4_UN;

    union
    {
     unsigned int RAMGCR_UW;                         /* 0xc0      */
     struct
     {
      unsigned int : 12;
	  unsigned int RAM_DFT_EN_B4 : 4;
	  unsigned int : 1;
      unsigned int WST_AENA3_B1  : 1;
      unsigned int : 1;
      unsigned int WST_DENA3_B1  : 1;
      unsigned int : 1;
      unsigned int WST_AENA2_B1  : 1;
      unsigned int : 1;
      unsigned int WST_DENA2_B1  : 1;
      unsigned int : 1;
      unsigned int WST_AENA1_B1  : 1;
      unsigned int : 1;
      unsigned int WST_DENA1_B1  : 1;
      unsigned int : 1;
      unsigned int WST_AENA0_B1  : 1;
      unsigned int : 1;
      unsigned int WST_DENA0_B1  : 1;
     } RAMGCR_ST;
    } RAMGCR_UN;

    union
    {
     unsigned int BMMCR1_UW;                     /* 0xc4      */
     struct
     {
      unsigned int : 28;    
      unsigned int MEMSW_B4: 4;
     }BMMCR1_ST;
    }BMMCR1_UN; 

    union
    {
     unsigned int BMMCR2_UW;
     struct
     {
      unsigned int : 25;                         /* 0xc8      */
      unsigned int PRTYHPI_B1: 1;
      unsigned int PRTYRAM3_B1: 1;
      unsigned int PRTYRAM2_B1: 1;
      unsigned int PRTYCRC_B1: 1;
      unsigned int PRTYPBRG_B1: 1;
      unsigned int PRTYRAM1_B1: 1;
      unsigned int PRTYRAM0_B1: 1;
     }BMMCR2_ST;
    }BMMCR2_UN;

    union
    {
     unsigned int MMUGCR_UW;
     struct
     {
      unsigned int : 31;                         /* 0xcc      */
      unsigned int MPMENA_B1: 1;
     }MMUGCR_ST;
    }MMUGCR_UN; 

    union 
    {
     unsigned int CLKCNTL_UW;
     struct
     {
      unsigned int : 4;                          /* 0xd0      */
      unsigned int VCLK2R_B4: 4;
      unsigned int : 4;                          
      unsigned int VCLKR_B4: 4;
      unsigned int : 7;
      unsigned int PENA_B1: 1;
      unsigned int : 8;
     }CLKCNTL_ST;
    }CLKCNTL_UN;

    union
    {
     unsigned int ECPCNTLR_UW;
     struct
     {
      unsigned int : 7;                         /* 0xd4      */
	  unsigned int ECPSSEL_B1 : 1;
      unsigned int ECPCOS_B1: 1;
      unsigned int : 7;
      unsigned short ECPDIV_UB;
     }ECPCNTLR_ST;
    }ECPCNTLR_UN;

    union
    {
     unsigned int DSPGCR_UW;
     struct
     {
      unsigned int : 31;                        /* 0xd8       */
      unsigned int DSPSHENA_B1: 1;
     }DSPGCR_ST;
    }DSPGCR_UN;
    
    
    union
    {
     unsigned int DEVCR1_UN_UW;
     struct
     {
      unsigned int : 28;                        /* 0xdc       */
      unsigned int DEVPARSEL: 4;
     }DEVCR1_ST;
    }DEVCR1_UN;


    union
    { 
     unsigned int SYSECR_UW;
     struct
     {
      unsigned int : 16;                        /* 0xe0       */
      unsigned int RESET1_B1: 1;
      unsigned int RESET0_B1: 1;
      unsigned int : 14;
     }SYSECR_ST;
    }SYSECR_UN;

    union
    {
     unsigned int SYSESR_UW;
     struct
     {
      unsigned int : 16;                        /* 0xe4       */
      unsigned int PORST_B1: 1;
      unsigned int OSCRST_B1: 1;
      unsigned int WDRST_B1: 1;
      unsigned int : 7;
      unsigned int CPURST_B1: 1;
      unsigned int SWRST_B1: 1;
      unsigned int EXTRST_B1: 1;
      unsigned int VSWRST_B1: 1;
      unsigned int : 1;
      unsigned int MPMODE_B1: 1;
     }SYSESR_ST;
    }SYSESR_UN;

     unsigned int : 32;       /* ITIFLAG removed */    /* 0e8       */
  
   union
   {
    unsigned int GBLSTAT_UW;
    struct
    {
     unsigned int : 22;                        /* 0xec      */
	 unsigned int FBSLIP_B1 : 1;
	 unsigned int RFSLIP_B1 : 1;
	 unsigned int : 7;
     unsigned int OSCFAIL_B1: 1;
    }GBLSTAT_ST;
   }GBLSTAT_UN;

   union
   {
    unsigned int DEV_UW;
    struct
    {
     unsigned int : 16;                        /* 0xf0      */
     unsigned int TIREV_B4: 4;
     unsigned int CUSTSP_B9: 9;
     unsigned int MFR_B2: 2;
     unsigned int ONE_B1: 1;
    }DEV_ST;
   }DEV_UN;

   union
   {
    unsigned int SSIVEC_UW;
    struct
    {
     unsigned int : 16;                        /* 0xf4      */
     unsigned char SSIDATA_UB;
     unsigned char SSIVECT_UB;
    }SSIVEC_ST;
   }SSIVEC_UN;

   union
   {
    unsigned int SSIF_UW;
    struct
    {
     unsigned int : 28;                        /* 0xf8      */
     unsigned int SSI_FLAG4_B1: 1;
     unsigned int SSI_FLAG3_B1: 1;
     unsigned int SSI_FLAG2_B1: 1;
     unsigned int SSI_FLAG1_B1: 1;
    }SSIF_ST;
   }SSIF_UN;

   union
   {
    unsigned int SSIR1_UW;
    struct
    {
     unsigned int : 16;                        /* 0xfc      */
     unsigned char SSKEY1_UB;
     unsigned char SSDATA1_UB;
    }SSIR1_ST;
   }SSIR1_UN;


   /* SYSTEM Register @ Frame 2 = 0xFFFF E100 */

   union                                      /* 0x00      */
    {
     unsigned int PLLCTL3_UL; 
     struct
     {
       unsigned int : 32;  
     }PLLCTL3_ST;
    }PLLCTL3_UN;

   unsigned int : 32;  	/* Reserved register */
 
   union 		/* 0x08 */
  {
    unsigned int STCCCLKDIV_UL;
	struct
   {
    unsigned int : 5 ;
    unsigned int CLKDIV : 3;
    unsigned int : 8;
    unsigned int : 16 ;
    }STCCLKDIV_ST;
   }STCCLK_DIV_UN;

   union 		/* 0x0C */
  {
    unsigned int CLKHB_GLBREG_UL;
	struct
   {
    unsigned int : 16;
    unsigned int : 12;
    unsigned int CLKHBMOD_EN : 4;
    }CLKHB_GLBREG_ST;
   }CLKHB_GLBREG_UN;


   union 		/* 0x10 */
  {
    unsigned int CLKHB_RTIDREG_UL;
	struct
   {
    unsigned int : 16;
    unsigned int CLKHB_RTI2EN  : 4;
    unsigned int : 4;
    unsigned int CLKHBMOD_RTI1EN : 4;
    }CLKHB_RTIDREG_ST;
   }CLKHB_RTIDREG_UN;

   
   union 		/* 0x14 */
  {
    unsigned int HBCD_STAT_UL;
	struct
   {
    unsigned int : 30;
    unsigned int RTI2RDY : 1;
    unsigned int RTI1RDY : 1;
    }HBCD_STAT_ST;
   }HBCD_STAT_UN;


   unsigned int : 32 ;   	/* Reserved 0x18 */
  
   unsigned int : 32; 	/* Reserved 0x1C */

   union 		/* 0x20 */
  {
    unsigned int CLKTRIM1_UL;
	struct
   {
    unsigned int : 28;
    unsigned int SUB_OSC_PERF_SW : 4;
    }CLKTRIM1_ST;
   }CLKTRIM1_UN;

   //unsigned int : 32 ;   	/* Reserved 0x24 */

   union		/* 0x24 */
   {
	unsigned int ECPCNTL0_UL;
	struct
	{
		unsigned int : 7;
		unsigned int ECPSSEL : 1;
		unsigned int ECPCOS : 1;
		unsigned int : 5;
		unsigned int ECPINSEL : 2;
		unsigned int ECPDIV : 16;
	}ECPCNTL0_ST;
   }ECPCNTL0_UN;
  
   //unsigned int : 32; 	/* Reserved 0x28*/

   union 		/* 0x28 */
   {
	unsigned int ECPCNTL1_UL;
	struct
	{
		unsigned int ECP_KEY : 4;
		unsigned int : 3;
		unsigned int ECPSSEL : 1;
		unsigned int ECPCOS : 1;
		unsigned int : 7;
		unsigned int ECPDIV : 16;
	}ECPCNTL1_ST;
   }ECPCNTL1_UN;

   //unsigned int : 32 ;   	/* Reserved 0x2C */

   union 		/* 0x2C */
   {
	unsigned int ECPCNTL2_UL;
	struct
	{
		unsigned int ECP_KEY : 4;
		unsigned int : 3;
		unsigned int ECPSSEL : 1;
		unsigned int ECPCOS : 1;
		unsigned int : 7;
		unsigned int ECPDIV : 16;
	}ECPCNTL2_ST;
   }ECPCNTL2_UN;
  
   //unsigned int : 32; 	/* Reserved 0x30 */

   union 		/* 0x30 */
   {
	unsigned int ECPCNTL3_UL;
	struct
	{
		unsigned int ECP_KEY : 4;
		unsigned int : 3;
		unsigned int ECPSSEL : 1;
		unsigned int ECPCOS : 1;
		unsigned int : 7;
		unsigned int ECPDIV : 16;
	}ECPCNTL3_ST;
   }ECPCNTL3_UN;

   unsigned int : 32 ;   	/* Reserved 0x34 */
  
   unsigned int : 32; 	/* Reserved 0x38 */

   unsigned int : 32 ;   	/* Reserved 0x3C */
  
   unsigned int : 32; 	/* Reserved 0x40 */

   unsigned int : 32 ;   	/* Reserved 0x44 */
  
   unsigned int : 32; 	/* Reserved 0x48 */

   unsigned int : 32 ;   	/* Reserved 0x4C */
  
   unsigned int : 32; 	/* Reserved 0x50 */

   unsigned int : 32 ;   	/* Reserved 0x54 */
  
   unsigned int : 32; 	/* Reserved 0x58 */

   unsigned int : 32 ;   	/* Reserved 0x5C */
  
   unsigned int : 32; 	/* Reserved 0x60 */

   unsigned int : 32 ;   	/* Reserved 0x64 */
  
   unsigned int : 32; 	/* Reserved 0x68 */

   unsigned int : 32 ;   	/* Reserved 0x6C */
  
   unsigned int : 32; 	/* Reserved 0x70 */

   unsigned int : 32 ;   	/* Reserved 0x74 */
  
   unsigned int : 32; 	/* Reserved 0x78 */

   unsigned int : 32 ;   	/* Reserved 0x7C */
  
   unsigned int : 32; 	/* Reserved 0x80 */

   unsigned int : 32 ;   	/* Reserved 0x84 */
  
   unsigned int : 32; 	/* Reserved 0x88 */

   unsigned int : 32 ;   	/* Reserved 0x8C */
  
   unsigned int : 32; 	/* Reserved 0x90 */

   unsigned int : 32 ;   	/* Reserved 0x94 */
  
   unsigned int : 32; 	/* Reserved 0x98 */

   unsigned int : 32 ;   	/* Reserved 0x9C */
  
   unsigned int : 32; 	/* Reserved 0xA0 */

   unsigned int : 32 ;   	/* Reserved 0xA4 */
  
   unsigned int : 32; 	/* Reserved 0xA8 */

   unsigned int : 32 ;   	/* Reserved 0xAC */
  
   unsigned int : 32; 	/* Reserved 0xB0 */

   unsigned int : 32 ;   	/* Reserved 0xB4 */
  
   unsigned int : 32; 	/* Reserved 0xB8 */

   unsigned int : 32 ;   	/* Reserved 0xBC */
  
   unsigned int : 32; 	/* Reserved 0xC0 */

   unsigned int : 32 ;   	/* Reserved 0xC4 */
  
   unsigned int : 32; 	/* Reserved 0xC8 */

   unsigned int : 32 ;   	/* Reserved 0xCC */
  
   unsigned int : 32; 	/* Reserved 0xD0 */

   unsigned int : 32 ;   	/* Reserved 0xD4 */
  
   unsigned int : 32; 	/* Reserved 0xD8 */

   unsigned int : 32 ;   	/* Reserved 0xDC */
  
   unsigned int : 32; 	/* Reserved 0xE0 */

   unsigned int : 32 ;   	/* Reserved 0xE4 */
  
   unsigned int : 32; 	/* Reserved 0xE8 */

   unsigned int : 32 ;   	/* Reserved 0xEC */
   
   unsigned int DIEIDL_REG0_UL : 32 ; /* 0xF0 */
 
   unsigned int DIEIDH_REG1_UL  : 32 ; /* 0xF4 */

   unsigned int DIEIDL_REG2_UL  : 32 ; /* 0xF8 */

   unsigned int DIEIDH_REG3_UL  : 32 ; /* 0xFC */
   


} SYSTEM_ST;


extern SYSTEM_ST e_SYSTEM_ST;
extern  SYSTEM_ST * SYS_Ptr;
 	

/* ------------------------------------------------------------------------- */
/*    SYSTEM Register Base                                                      */
/* ------------------------------------------------------------------------- */

#define SYS_BASE 		0xFFFFFF00
#define SYS2_BASE		0xFFFFE100


#elif defined(_TMS470_LITTLE) || defined(__little_endian__)

typedef volatile struct
{
    union                                      /* 0x00      */
    {
     unsigned int SYSPC1_UL; 
     struct
     {
     unsigned int ECPCLK_FUN_B1: 1;
     unsigned int : 31;                        
     }SYSPC1_ST;
    }SYSPC1_UN;

    union                                      /* 0x04      */
    {
     unsigned int SYSPC2_UL; 
     struct
     {
     unsigned int ECPCLK_DIR_B1: 1;
     unsigned int : 31;                        
     }SYSPC2_ST;
    }SYSPC2_UN;

    union                                      /* 0x08      */
    {
     unsigned int SYSPC3_UL; 
     struct
     {
     unsigned int ECPCLK_DIN_B1: 1;
     unsigned int : 31;                        
     }SYSPC3_ST;
    }SYSPC3_UN;

    union                                      /* 0x0c      */
    {
     unsigned int SYSPC4_UL; 
     struct
     {
     unsigned int ECPCLK_DOUT_B1: 1;
     unsigned int : 31;                        
     }SYSPC4_ST;
    }SYSPC4_UN;
 
    union                                      /* 0x10      */
    {
     unsigned int SYSPC5_UL; 
     struct
     {
     unsigned int ECPCLK_SET_B1: 1;
     unsigned int : 31;                        
     }SYSPC5_ST;
    }SYSPC5_UN;

    union                                      /* 0x14      */
    {
     unsigned int SYSPC6_UL; 
     struct
     {
     unsigned int ECPCLK_CLR_B1: 1;
     unsigned int : 31;                        
     }SYSPC6_ST;
    }SYSPC6_UN;

    union                                      /* 0x18      */
    {
     unsigned int SYSPC7_UL; 
     struct
     {
     unsigned int ECPCLK_ODE_B1: 1;
     unsigned int : 31;                        
     }SYSPC7_ST;
    }SYSPC7_UN;

    union                                      /* 0x1c      */
    {
     unsigned int SYSPC8_UL; 
     struct
     {
     unsigned int ECPCLK_PLE_B1: 1;
     unsigned int : 31;                        
     }SYSPC8_ST;
    }SYSPC8_UN;

    union                                      /* 0x20      */
    {
     unsigned int SYSPC9_UL; 
     struct
     {
     unsigned int ECPCLK_PS_B1: 1;
     unsigned int : 31;                        
     }SYSPC9_ST;
    }SYSPC9_UN;

    union                                      /* 0x24      */
    {
     unsigned int SSWPLL1_UL; 
     struct
     {
	 unsigned int EXT_COUNTER_EN_B1 : 1;
     unsigned int TAP_COUNTER_DIS_B3 : 3;
     unsigned int COUNTER_EN_B1 : 1;
     unsigned int COUNTER_RESET_B1 : 1;
	 unsigned int COUNTER_READ_READY_B1: 1;
     unsigned int : 1;
     unsigned int MOD_PH_CAP_INDEX_B8: 8;
     unsigned int : 16;                        
     }SSWPLL1_ST;
    }SSWPLL1_UN;

    unsigned int SSWPLL2_UL;   /* 0x28      */
    
    unsigned int SSWPLL3_UL; /* 0x2C      */
                
    union                                      /* 0x30      */
    {
     unsigned int CSDIS_UL; 
     struct
     {
     unsigned int CLKSR0OFF_B1: 1;
     unsigned int CLKSR1OFF_B1: 1;             
     unsigned int CLKSR2OFF_B1: 1;
     unsigned int CLKSR3OFF_B1: 1;
     unsigned int CLKSR4OFF_B1: 1;
     unsigned int CLKSR5OFF_B1: 1;
     unsigned int CLKSR6OFF_B1: 1;
     unsigned int CLKSR7OFF_B1: 1;
     unsigned int : 24;           
     }CSDIS_ST;
    }CSDIS_UN;
    
    union                                      /* 0x34      */
    {
     unsigned int CSDISSET_UL; 
     struct
     {
     unsigned int SETCLKSR1OFF_B1: 1;
     unsigned int SETCLKSR2OFF_B1: 1;             
     unsigned int SETCLKSR3OFF_B1: 1;
     unsigned int SETCLKSR4OFF_B1: 1;
     unsigned int SETCLKSR5OFF_B1: 1;
     unsigned int SETCLKSR6OFF_B1: 1;
     unsigned int SETCLKSR7OFF_B1: 1;
     unsigned int SETCLKSR8OFF_B1: 1;
     unsigned int : 24;           
     }CSDISSET_ST;
    }CSDISSET_UN;
    
    union                                      /* 0x38      */
    {
     unsigned int CSDISCLR_UL; 
     struct
     {
     unsigned int CLRCLKSR1OFF_B1: 1;
     unsigned int CLRCLKSR2OFF_B1: 1;             
     unsigned int CLRCLKSR3OFF_B1: 1;
     unsigned int CLRCLKSR4OFF_B1: 1;
     unsigned int CLRCLKSR5OFF_B1: 1;
     unsigned int CLRCLKSR6OFF_B1: 1;
     unsigned int CLRCLKSR7OFF_B1: 1;
     unsigned int CLRCLKSR8OFF_B1: 1;
     unsigned int : 24;           
     }CSDISCLR_ST;
    }CSDISCLR_UN;
    
    union                                      /* 0x3c      */
    {
     unsigned int CDDIS_UL; 
     struct
     {
     unsigned int GCLKOFF_B1: 1;
     unsigned int HCLKOFF_B1: 1;             
     unsigned int VCLKPOFF_B1: 1;
     unsigned int VCLK2OFF_B1: 1;
     unsigned int VCLKA1OFF_B1: 1;
     unsigned int VCLKA2OFF_B1: 1;
     unsigned int RTICLK1OFF_B1: 1;
     unsigned int RTICLK2OFF_B1: 1;
     unsigned int : 24;           
     }CDDIS_ST;
    }CDDIS_UN;
    
    union                                      /* 0x40      */
    {
     unsigned int CDDISSET_UL; 
     struct
     {
     unsigned int SETGCLKOFF_B1: 1;
     unsigned int SETHCLKOFF_B1: 1;             
     unsigned int SETVCLKPOFF_B1: 1;
     unsigned int SETVCLK2OFF_B1: 1;
     unsigned int SETVCLKA1OFF_B1: 1;
     unsigned int SETVCLKA2OFF_B1: 1;
     unsigned int SETRTICLK1OFF_B1: 1;
     unsigned int SETRTICLK2OFF_B1: 1;
     unsigned int : 24;           
     }CDDISSET_ST;
    }CDDISSET_UN;
    
    union                                      /* 0x44      */
    {
     unsigned int CDDISCLR_UL; 
     struct
     {
     unsigned int CLRGCLKOFF_B1: 1;
     unsigned int CLRHCLKOFF_B1: 1;             
     unsigned int CLRVCLKPOFF_B1: 1;
     unsigned int CLRVCLK2OFF_B1: 1;
     unsigned int CLRVCLKA1OFF_B1: 1;
     unsigned int CLRVCLKA2OFF_B1: 1;
     unsigned int CLRRTICLK1OFF_B1: 1;
     unsigned int CLRRTICLK2OFF_B1: 1;
     unsigned int : 24;           
     }CDDISCLR_ST;
    }CDDISCLR_UN;
    
    union                                      /* 0x48      */
    {
     unsigned int GHVSRC_UL; 
     struct
     {
     unsigned int GHVSRC_B4: 4;
     unsigned int : 12;           
     unsigned int HVLPM_B4: 4;
     unsigned int : 4;           
     unsigned int GHVWAKE_B4: 4;
     unsigned int : 4;           
     }GHVSRC_ST;
    }GHVSRC_UN;
    
    union                                      /* 0x4c      */
    {
     unsigned int VCLKASRC_UL; 
     struct
     {
     unsigned int VCLKA1S_B4: 4;
     unsigned int : 4;           
     unsigned int VCLKA2S_B4: 4;
     unsigned int : 20;           
     }VCLKASRC_ST;
    }VCLKASRC_UN;
    
    union                                      /* 0x50      */
    {
     unsigned int RCLKSRC_UL; 
     struct
     {
	 unsigned int RTI1SRC_B4: 4;  
	 unsigned int : 4;
     unsigned int RTI1DIV_B2: 2;
     unsigned int : 6;
     unsigned int RTI2SRC_B4 : 4;
	 unsigned int : 4;
	 unsigned int RTI2DIV_B2 : 2;
     unsigned int : 6;           
     }RCLKSRC_ST;
    }RCLKSRC_UN;
    
    union                                      /* 0x54      */
    {
     unsigned int CSVSTAT_UL; 
     struct
     {
     unsigned int CLKSR1V_B1: 1;
     unsigned int CLKSR2V_B1: 1;             
     unsigned int CLKSR3V_B1: 1;
     unsigned int CLKSR4V_B1: 1;
     unsigned int CLKSR5V_B1: 1;
     unsigned int CLKSR6V_B1: 1;
     unsigned int CLKSR7V_B1: 1;
     unsigned int CLKSR8V_B1: 1;
     unsigned int : 24;           
     }CSVSTAT_ST;
    }CSVSTAT_UN;

    union                                      /* 0x58      */
    {
     unsigned int MSTGCR_UL; 
     struct
     {
     unsigned int MSTGENA_B4: 4;
	 unsigned int : 4;
     unsigned int ROM_DIV_B2 : 2;
     unsigned int : 6;
	 unsigned int MBIST_ALGSEL_B8 : 8;
	 unsigned int : 8;
     }MSTGCR_ST;
    }MSTGCR_UN;

    union                                      /* 0x5C      */
    {
     unsigned int MINITGCR_UL; 
     struct
     {
     unsigned int MINITGENA_B4: 4;
     unsigned int : 28;
     }MINITGCR_ST;
    }MINITGCR_UN;

    unsigned int MSINENA_UL; 		      	/* 0x60      */
    
    unsigned int MSTFAIL_UL;		     	/* 0x64      */

    union                                      	/* 0x68      */
    {
     unsigned int MSTCGSTAT_UL; 
     struct
     {
     unsigned int MSTDONE_B1: 1;
     unsigned int : 7;
     unsigned int MINIDONE_B1: 1;
     unsigned int : 23;
     }MSTCGSTAT_ST;
    }MSTCGSTAT_UN;

  

     unsigned int MINISTAT_UL;		       	/* 0x6C      */

    
    union                                      /* 0x70      */
    {
     unsigned int PLLCTL1_UL; 
     struct
     {
     unsigned int PLL_DIV_B5: 5;
     unsigned int : 3;           
     unsigned int PLL_MUL_B5: 5;
     unsigned int : 9;           
     unsigned int OSCDIV_B1: 1;
     unsigned int ROF_B1: 1;
     unsigned int : 7;           
     unsigned int ROS_B1 : 1; 
     }PLLCTL1_ST;
    }PLLCTL1_UN;
        
    union                                      /* 0x74      */
    {
     unsigned int PLLCTL2_UL; 
     struct
     {
     unsigned int PLL_MDEPTH_B5: 5;
     unsigned int : 3;           
     unsigned int PLL_MODFREQ_B6: 6;
     unsigned int : 9;           
     unsigned int FM_ENA_B1: 1;
     unsigned int : 8;           
     }PLLCTL2_ST;
    }PLLCTL2_UN;
        
    unsigned int : 32;       /*UERRFLAG removed */  /* 0x78      */
    
    

    unsigned int DIEIDL_UL;                    /* 0x7C      */

    unsigned int DIEIDH_UL;                    /* 0x80      */
    
    union                                      /* 0x84      */
    {
     unsigned int VRCTL_UL; 
     struct
     {
     unsigned int SLEEPENA_B4: 4;
     unsigned int VLPMENA_B4: 4;
     unsigned int : 24;           
     }VRCTL_ST;
    }VRCTL_UN;
    
	 union                                      /* 0x88      */
    {
     unsigned int LPOMONCTL_UL; 
     struct
     {
	 unsigned int LFTRIM_B4 : 4;
	 unsigned int : 4;
     unsigned int HFTRIM_B4: 4;
	 unsigned int : 12;
     unsigned int BIAS_ENABLE_B1 : 1;
     unsigned int : 7;           
     }LPOMONCTL_ST;
    }LPOMONCTL_UN;
                             
	union                                      /* 0x8C      */
    {
     unsigned int CLKTEST_UL; 
     struct
     {
	 unsigned int SEL_ECP_PIN_B4 : 4;
	 unsigned int : 4;
	 unsigned int SEL_GIO_PIN_B4 : 4;
	 unsigned int : 4;
	 unsigned int CLK_TEST_EN_B4 : 4;
	 unsigned int : 4;
	 unsigned int RANGEDETENSSEL_B1 : 1;
	 unsigned int RANGEDETCTRL_B1 : 1;
     unsigned int ALTLIMPCLOCKENABLE_B1 : 1;
     unsigned int : 5;           
     }CLKTEST_ST;
    }CLKTEST_UN;
    

    unsigned int : 32;                         /* 0x90      */
    
    unsigned int : 32;                         /* 0x94      */

    unsigned int : 32;                         /* 0x98      */

    unsigned int : 32;                         /* 0x9c      */

    unsigned int : 32;                         /* 0xa0      */

   union                                       /* 0xa4      */
   {
     unsigned int BTRMSEL_UL; 
     struct
     {
     unsigned int BTRMSEL_B4: 4;
     unsigned int : 12;
     unsigned int BTRMSLRST_B16: 16;           
     }BTRMSEL_ST;
    }BTRMSEL_UN;           

	union                                       /* 0xa8      */
   {
     unsigned int IMPFASTS_UL; 
     struct
     {
	 unsigned int ATYPE : 1;
     unsigned int : 7;
	 unsigned int VBUSA : 1;
	 unsigned int NCBA_B1 : 1;
	 unsigned int EMIFA_B1 : 1;
	 unsigned int : 5;
     unsigned int MASTERID_B8: 8;
     unsigned int : 8;           
    }IMPFASTS_ST;
   }IMPFASTS_UN;      
                
    unsigned int IMPFTADD_UL;                  /* 0xac      */

    union
    {
     unsigned int SSISR1_UL;                   /* 0xb0      */
     struct
     {
      unsigned int SSDATA2_UB : 8;
      unsigned int SSKEY2_UB  : 8;
      unsigned int :16;
     } SSISR1_ST;
    }SSISR1_UN;

    union
    {
     unsigned int SSISR2_UL;                   /* 0xb4      */
     struct
     {
      unsigned int SSDATA1_UB : 8;
      unsigned int SSKEY1_UB  : 8;
      unsigned int :16;
     } SSISR2_ST;
    }SSISR2_UN;

    union
    {
     unsigned int SSISR3_UL;                   /* 0xb8      */
     struct
     {
      unsigned int SSDATA3_UB : 8;
      unsigned int SSKEY3_UB  : 8;
      unsigned int :16;
     } SSISR3_ST;
    }SSISR3_UN;

    union
    {
     unsigned int SSISR4_UL;                   /* 0xbc      */
     struct
     {
      unsigned int SSDATA4_UB : 8;
      unsigned int SSKEY4_UB  : 8;
      unsigned int :16;
     } SSISR4_ST;
    }SSISR4_UN;

    union
    {
     unsigned int RAMGCR_UW;                         /* 0xc0      */
     struct
     {
      unsigned int WST_DENA0_B1  : 1;
      unsigned int : 1;
      unsigned int WST_AENA0_B1  : 1;
      unsigned int : 1;
      unsigned int WST_DENA1_B1  : 1;
      unsigned int : 1;
      unsigned int WST_AENA1_B1  : 1;
      unsigned int : 1;
      unsigned int WST_DENA2_B1  : 1;
      unsigned int : 1;
      unsigned int WST_AENA2_B1  : 1;
      unsigned int : 1;
      unsigned int WST_DENA3_B1  : 1;
      unsigned int : 1;
      unsigned int WST_AENA3_B1  : 1;
	  unsigned int : 1;
	  unsigned int RAM_DFT_EN_B4 : 4;
      unsigned int : 12;
     } RAMGCR_ST;
    } RAMGCR_UN;

    union
    {
     unsigned int BMMCR1_UW;                     /* 0xc4      */
     struct
     {
      unsigned int MEMSW_B4: 4;
      unsigned int : 28;    
     }BMMCR1_ST;
    }BMMCR1_UN; 

    union
    {
     unsigned int BMMCR2_UW;
     struct
     {
      unsigned int PRTYRAM0_B1: 1;
      unsigned int PRTYRAM1_B1: 1;
      unsigned int PRTYPBRG_B1: 1;
      unsigned int PRTYCRC_B1: 1;
      unsigned int PRTYRAM2_B1: 1;
      unsigned int PRTYRAM3_B1: 1;
      unsigned int PRTYHPI_B1: 1;
      unsigned int : 25;                         /* 0xc8      */
     }BMMCR2_ST;
    }BMMCR2_UN;

    union
    {
     unsigned int MMUGCR_UW;
     struct
     {
      unsigned int MPMENA_B1: 1;
      unsigned int : 31;                         /* 0xcc      */
     }MMUGCR_ST;
    }MMUGCR_UN; 

    union 
    {
     unsigned int CLKCNTL_UW;
     struct
     {
      unsigned int : 8;
      unsigned int PENA_B1: 1;
      unsigned int : 7;
      unsigned int VCLKR_B4: 4;
      unsigned int : 4;                          
      unsigned int VCLK2R_B4: 4;
      unsigned int : 4;                          /* 0xd0      */
     }CLKCNTL_ST;
    }CLKCNTL_UN;

    union
    {
     unsigned int ECPCNTLR_UW;
     struct
     {
      unsigned short ECPDIV_UB;
      unsigned int : 7;
      unsigned int ECPCOS_B1: 1;
	  unsigned int ECPSSEL_B1 : 1;
      unsigned int : 7;                         /* 0xd4      */
     }ECPCNTLR_ST;
    }ECPCNTLR_UN;

    union
    {
     unsigned int DSPGCR_UW;
     struct
     {
      unsigned int DSPSHENA_B1: 1;
      unsigned int : 31;                        /* 0xd8       */
     }DSPGCR_ST;
    }DSPGCR_UN;
    
    
    union
    {
     unsigned int DEVCR1_UN_UW;
     struct
     {
      unsigned int DEVPARSEL: 4;
      unsigned int : 28;                        /* 0xdc       */
     }DEVCR1_ST;
    }DEVCR1_UN;


    union
    { 
     unsigned int SYSECR_UW;
     struct
     {
      unsigned int : 14;
      unsigned int RESET0_B1: 1;
      unsigned int RESET1_B1: 1;
      unsigned int : 16;                        /* 0xe0       */
     }SYSECR_ST;
    }SYSECR_UN;

    union
    {
     unsigned int SYSESR_UW;
     struct
     {
      unsigned int MPMODE_B1: 1;
      unsigned int : 1;
      unsigned int VSWRST_B1: 1;
      unsigned int EXTRST_B1: 1;
      unsigned int SWRST_B1: 1;
      unsigned int CPURST_B1: 1;
      unsigned int : 7;
      unsigned int WDRST_B1: 1;
      unsigned int OSCRST_B1: 1;
      unsigned int PORST_B1: 1;
      unsigned int : 16;                        /* 0xe4       */
     }SYSESR_ST;
    }SYSESR_UN;

     unsigned int : 32;       /* ITIFLAG removed */    /* 0e8       */
  
   union
   {
    unsigned int GBLSTAT_UW;
    struct
    {
     unsigned int OSCFAIL_B1: 1;
	 unsigned int : 7;
	 unsigned int RFSLIP_B1 : 1;
	 unsigned int FBSLIP_B1 : 1;
     unsigned int : 22;                        /* 0xec      */
    }GBLSTAT_ST;
   }GBLSTAT_UN;

   union
   {
    unsigned int DEV_UW;
    struct
    {
     unsigned int ONE_B1: 1;
     unsigned int MFR_B2: 2;
     unsigned int CUSTSP_B9: 9;
     unsigned int TIREV_B4: 4;
     unsigned int : 16;                        /* 0xf0      */
    }DEV_ST;
   }DEV_UN;

   union
   {
    unsigned int SSIVEC_UW;
    struct
    {
     unsigned char SSIVECT_UB;
     unsigned char SSIDATA_UB;
     unsigned int : 16;                        /* 0xf4      */
    }SSIVEC_ST;
   }SSIVEC_UN;

   union
   {
    unsigned int SSIF_UW;
    struct
    {
     unsigned int SSI_FLAG1_B1: 1;
     unsigned int SSI_FLAG2_B1: 1;
     unsigned int SSI_FLAG3_B1: 1;
     unsigned int SSI_FLAG4_B1: 1;
     unsigned int : 28;                        /* 0xf8      */
    }SSIF_ST;
   }SSIF_UN;

   union
   {
    unsigned int SSIR1_UW;
    struct
    {
     unsigned char SSDATA1_UB;
     unsigned char SSKEY1_UB;
     unsigned int : 16;                        /* 0xfc      */
    }SSIR1_ST;
   }SSIR1_UN;

   /* SYSTEM Register @ Frame 2 = 0xFFFF E100 */

   union                                      /* 0x00      */
    {
     unsigned int PLLCTL3_UL; 
     struct
     {
       unsigned int : 32;  
     }PLLCTL3_ST;
    }PLLCTL3_UN;

   unsigned int : 32;  	/* Reserved register */

   union 		/* 0x08 */
  {
    unsigned int STCCCLKDIV_UL;
	struct
   {
    unsigned int : 16 ;
    unsigned int : 8;
    unsigned int CLKDIV : 3;
    unsigned int : 5;
    }STCCLKDIV_ST;
   }STCCLK_DIV_UN;

   union 		/* 0x0C */
  {
    unsigned int CLKHB_GLBREG_UL;
	struct
   {
    unsigned int CLKHBMOD_EN : 4;
    unsigned int : 12;
    unsigned int : 16;
    }CLKHB_GLBREG_ST;
   }CLKHB_GLBREG_UN;

   union 		/* 0x10 */
  {
    unsigned int CLKHB_RTIDREG_UL;
	struct
   {    
    unsigned int CLKHBMOD_RTI1EN : 4;
    unsigned int : 4;
    unsigned int CLKHB_RTI2EN  : 4;
    unsigned int : 16;
    }CLKHB_RTIDREG_ST;
   }CLKHB_RTIDREG_UN;

   union 		/* 0x14 */
  {
    unsigned int HBCD_STAT_UL;
	struct
   {    
    unsigned int RTI1RDY : 1;
    unsigned int RTI2RDY : 1;
    unsigned int : 30;
    }HBCD_STAT_ST;
   }HBCD_STAT_UN;

   unsigned int : 32 ;   	/* Reserved 0x18 */
  
   unsigned int : 32; 	/* Reserved 0x1C */

   union 		/* 0x20 */
  {
    unsigned int CLKTRIM1_UL;
	struct
   {    
    unsigned int SUB_OSC_PERF_SW : 4;
    unsigned int : 28;
    }CLKTRIM1_ST;
   }CLKTRIM1_UN;

   //unsigned int : 32 ;   	/* Reserved 0x24 */

   union		/* 0x24 */
   {
	unsigned int ECPCNTL0_UL;
	struct
	{
		unsigned int ECPDIV : 16;
		unsigned int ECPINSEL : 2;
		unsigned int : 5;
		unsigned int ECPCOS : 1;
		unsigned int ECPSSEL : 1;
		unsigned int : 7;
	}ECPCNTL0_ST;
   }ECPCNTL0_UN;
  
   //unsigned int : 32; 	/* Reserved 0x28*/

   union 		/* 0x28 */
   {
	unsigned int ECPCNTL1_UL;
	struct
	{
		unsigned int ECPDIV : 16;
		unsigned int : 7;
		unsigned int ECPCOS : 1;
		unsigned int ECPSSEL : 1;
		unsigned int : 3;
		unsigned int ECP_KEY : 4;
	}ECPCNTL1_ST;
   }ECPCNTL1_UN;

   //unsigned int : 32 ;   	/* Reserved 0x2C */

   union 		/* 0x2C */
   {
	unsigned int ECPCNTL2_UL;
	struct
	{
		unsigned int ECPDIV : 16;
		unsigned int : 7;
		unsigned int ECPCOS : 1;
		unsigned int ECPSSEL : 1;
		unsigned int : 3;
		unsigned int ECP_KEY : 4;
	}ECPCNTL2_ST;
   }ECPCNTL2_UN;
  
   //unsigned int : 32; 	/* Reserved 0x30 */

   union 		/* 0x30 */
   {
	unsigned int ECPCNTL3_UL;
	struct
	{
		unsigned int ECPDIV : 16;
		unsigned int : 7;
		unsigned int ECPCOS : 1;
		unsigned int ECPSSEL : 1;
		unsigned int : 3;
		unsigned int ECP_KEY : 4;
	}ECPCNTL3_ST;
   }ECPCNTL3_UN;

   unsigned int : 32 ;   	/* Reserved 0x34 */
  
   unsigned int : 32; 	/* Reserved 0x38 */

   unsigned int : 32 ;   	/* Reserved 0x3C */
  
   unsigned int : 32; 	/* Reserved 0x40 */

   unsigned int : 32 ;   	/* Reserved 0x44 */
  
   unsigned int : 32; 	/* Reserved 0x48 */

   unsigned int : 32 ;   	/* Reserved 0x4C */
  
   unsigned int : 32; 	/* Reserved 0x50 */

   unsigned int : 32 ;   	/* Reserved 0x54 */
  
   unsigned int : 32; 	/* Reserved 0x58 */

   unsigned int : 32 ;   	/* Reserved 0x5C */
  
   unsigned int : 32; 	/* Reserved 0x60 */

   unsigned int : 32 ;   	/* Reserved 0x64 */
  
   unsigned int : 32; 	/* Reserved 0x68 */

   unsigned int : 32 ;   	/* Reserved 0x6C */
  
   unsigned int : 32; 	/* Reserved 0x70 */

   unsigned int : 32 ;   	/* Reserved 0x74 */
  
   unsigned int : 32; 	/* Reserved 0x78 */

   unsigned int : 32 ;   	/* Reserved 0x7C */
  
   unsigned int : 32; 	/* Reserved 0x80 */

   unsigned int : 32 ;   	/* Reserved 0x84 */
  
   unsigned int : 32; 	/* Reserved 0x88 */

   unsigned int : 32 ;   	/* Reserved 0x8C */
  
   unsigned int : 32; 	/* Reserved 0x90 */

   unsigned int : 32 ;   	/* Reserved 0x94 */
  
   unsigned int : 32; 	/* Reserved 0x98 */

   unsigned int : 32 ;   	/* Reserved 0x9C */
  
   unsigned int : 32; 	/* Reserved 0xA0 */

   unsigned int : 32 ;   	/* Reserved 0xA4 */
  
   unsigned int : 32; 	/* Reserved 0xA8 */

   unsigned int : 32 ;   	/* Reserved 0xAC */
  
   unsigned int : 32; 	/* Reserved 0xB0 */

   unsigned int : 32 ;   	/* Reserved 0xB4 */
  
   unsigned int : 32; 	/* Reserved 0xB8 */

   unsigned int : 32 ;   	/* Reserved 0xBC */
  
   unsigned int : 32; 	/* Reserved 0xC0 */

   unsigned int : 32 ;   	/* Reserved 0xC4 */
  
   unsigned int : 32; 	/* Reserved 0xC8 */

   unsigned int : 32 ;   	/* Reserved 0xCC */
  
   unsigned int : 32; 	/* Reserved 0xD0 */

   unsigned int : 32 ;   	/* Reserved 0xD4 */
  
   unsigned int : 32; 	/* Reserved 0xD8 */

   unsigned int : 32 ;   	/* Reserved 0xDC */
  
   unsigned int : 32; 	/* Reserved 0xE0 */

   unsigned int : 32 ;   	/* Reserved 0xE4 */
  
   unsigned int : 32; 	/* Reserved 0xE8 */

   unsigned int : 32 ;   	/* Reserved 0xEC */
   
   unsigned int DIEIDL_REG0_UL : 32 ; /* 0xF0 */
 
   unsigned int DIEIDH_REG1_UL  : 32 ; /* 0xF4 */

   unsigned int DIEIDL_REG2_UL  : 32 ; /* 0xF8 */

   unsigned int DIEIDH_REG3_UL  : 32 ; /* 0xFC */
   


} SYSTEM_ST;


extern SYSTEM_ST e_SYSTEM_ST;
extern  SYSTEM_ST * SYS_Ptr;
 	

/* ------------------------------------------------------------------------- */
/*    SYSTEM Register Base                                                      */
/* ------------------------------------------------------------------------- */

#define SYS_BASE 		0xFFFFFF00
#define SYS2_BASE		0xFFFFE100


 

#endif

/* ------------------------------------------------------------------------- */
/* pcr.h : PCR Register Definitions                                          */
/*   	                                                                     */
/* Copyright (c) Texas Instruments 1997, All right reserved.                 */
/*                                                                           */
/* History:                                                                  */
/*    Rev 1.0  09.25.04  Rejith Kunnummal   - rejith@ti.com                  */
/*                                                                           */
/*                       Definition of PCR registers                         */
/*                                                                           */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
#if defined(_TMS470_BIG) || defined(__big_endian__)

typedef volatile struct
{
 	unsigned int PMPROTSET0_UL;             	/* 0x00		*/
 	
 	unsigned int PMPROTSET1_UL;             	/* 0x04		*/
 	
 	unsigned int : 32;							/* 0x08  	*/
 	
 	unsigned int : 32;							/* 0x0c  	*/
 	
 	unsigned int PMPROTCLR0_UL;					/* 0x10		*/
 	
 	unsigned int PMPROTCLR1_UL;					/* 0x14		*/
 	
 	unsigned int : 32;							/* 0x18  	*/
 	
 	unsigned int : 32;							/* 0x1c  	*/
 	
 	unsigned int PPROTSET0_UL;             		/* 0x20		*/
 	
 	unsigned int PPROTSET1_UL;             		/* 0x24		*/
 	 	
 	unsigned int PPROTSET2_UL;             		/* 0x28		*/
 	
 	unsigned int PPROTSET3_UL;             		/* 0x2c		*/
 	
 	unsigned int : 32;							/* 0x30  	*/
 	
 	unsigned int : 32;							/* 0x34  	*/
 	
 	unsigned int : 32;							/* 0x38  	*/
 	
 	unsigned int : 32;							/* 0x3c  	*/
 	
 	unsigned int PPROTCLR0_UL;             		/* 0x40		*/
 	
 	unsigned int PPROTCLR1_UL;             		/* 0x44		*/
 	 	
 	unsigned int PPROTCLR2_UL;             		/* 0x48		*/
 	
 	unsigned int PPROTCLR3_UL;             		/* 0x4c		*/
 	
 	unsigned int : 32;							/* 0x50  	*/
 	
 	unsigned int : 32;							/* 0x54  	*/
 	
 	unsigned int : 32;							/* 0x58  	*/
 	
 	unsigned int : 32;							/* 0x5c  	*/
 	 	 	
 	unsigned int PCSPWRDWNSET0_UL;             	/* 0x60		*/
 	
 	unsigned int PCSPWRDWNSET1_UL;             	/* 0x64		*/
 	
 	unsigned int PCSPWRDWNSET2_UL;				/* 0x68  	*/
 	
 	unsigned int PCSPWRDWNSET3_UL;				/* 0x6c  	*/
 	 	 	
 	unsigned int PCSPWRDWNCLR0_UL;             	/* 0x70		*/
 	
 	unsigned int PCSPWRDWNCLR1_UL;             	/* 0x74		*/
 	
 	unsigned int PCSPWRDWNCLR2_UL;				/* 0x78  	*/
 	
 	unsigned int PCSPWRDWNCLR3_UL;				/* 0x7c  	*/
 	 	 	
 	unsigned int PSPWRDWNSET0_UL;             	/* 0x80		*/
 	
 	unsigned int PSPWRDWNSET1_UL;             	/* 0x84		*/
 	 	 	
 	unsigned int PSPWRDWNSET2_UL;             	/* 0x88		*/
 	
 	unsigned int PSPWRDWNSET3_UL;             	/* 0x8c		*/
 	
 	unsigned int : 32;							/* 0x90  	*/
 	
 	unsigned int : 32;							/* 0x94  	*/
 	
 	unsigned int : 32;							/* 0x98  	*/
 	
 	unsigned int : 32;							/* 0x9c  	*/
 	 	 	
 	unsigned int PSPWRDWNCLR0_UL;             	/* 0xa0		*/
 	
 	unsigned int PSPWRDWNCLR1_UL;             	/* 0xa4		*/
 	 	 	
 	unsigned int PSPWRDWNCLR2_UL;             	/* 0xa8		*/
 	
 	unsigned int PSPWRDWNCLR3_UL;             	/* 0xac		*/
        
} PCR_ST;

extern PCR_ST e_PCR_ST;
extern PCR_ST e_PCR_B_ST;

extern PCR_ST * PCR_Ptr;
extern PCR_ST * PCR_B_Ptr;

#elif defined(_TMS470_LITTLE) || defined(__little_endian__)

typedef volatile struct
{
 	unsigned int PMPROTSET0_UL;             	/* 0x00		*/
 	
 	unsigned int PMPROTSET1_UL;             	/* 0x04		*/
 	
 	unsigned int : 32;							/* 0x08  	*/
 	
 	unsigned int : 32;							/* 0x0c  	*/
 	
 	unsigned int PMPROTCLR0_UL;					/* 0x10		*/
 	
 	unsigned int PMPROTCLR1_UL;					/* 0x14		*/
 	
 	unsigned int : 32;							/* 0x18  	*/
 	
 	unsigned int : 32;							/* 0x1c  	*/
 	
 	unsigned int PPROTSET0_UL;             		/* 0x20		*/
 	
 	unsigned int PPROTSET1_UL;             		/* 0x24		*/
 	 	
 	unsigned int PPROTSET2_UL;             		/* 0x28		*/
 	
 	unsigned int PPROTSET3_UL;             		/* 0x2c		*/
 	
 	unsigned int : 32;							/* 0x30  	*/
 	
 	unsigned int : 32;							/* 0x34  	*/
 	
 	unsigned int : 32;							/* 0x38  	*/
 	
 	unsigned int : 32;							/* 0x3c  	*/
 	
 	unsigned int PPROTCLR0_UL;             		/* 0x40		*/
 	
 	unsigned int PPROTCLR1_UL;             		/* 0x44		*/
 	 	
 	unsigned int PPROTCLR2_UL;             		/* 0x48		*/
 	
 	unsigned int PPROTCLR3_UL;             		/* 0x4c		*/
 	
 	unsigned int : 32;							/* 0x50  	*/
 	
 	unsigned int : 32;							/* 0x54  	*/
 	
 	unsigned int : 32;							/* 0x58  	*/
 	
 	unsigned int : 32;							/* 0x5c  	*/
 	 	 	
 	unsigned int PCSPWRDWNSET0_UL;             	/* 0x60		*/
 	
 	unsigned int PCSPWRDWNSET1_UL;             	/* 0x64		*/
 	
 	unsigned int PCSPWRDWNSET2_UL;				/* 0x68  	*/
 	
 	unsigned int PCSPWRDWNSET3_UL;				/* 0x6c  	*/
 	 	 	
 	unsigned int PCSPWRDWNCLR0_UL;             	/* 0x70		*/
 	
 	unsigned int PCSPWRDWNCLR1_UL;             	/* 0x74		*/
 	
 	unsigned int PCSPWRDWNCLR2_UL;				/* 0x78  	*/
 	
 	unsigned int PCSPWRDWNCLR3_UL;				/* 0x7c  	*/
 	 	 	
 	unsigned int PSPWRDWNSET0_UL;             	/* 0x80		*/
 	
 	unsigned int PSPWRDWNSET1_UL;             	/* 0x84		*/
 	 	 	
 	unsigned int PSPWRDWNSET2_UL;             	/* 0x88		*/
 	
 	unsigned int PSPWRDWNSET3_UL;             	/* 0x8c		*/
 	
 	unsigned int : 32;							/* 0x90  	*/
 	
 	unsigned int : 32;							/* 0x94  	*/
 	
 	unsigned int : 32;							/* 0x98  	*/
 	
 	unsigned int : 32;							/* 0x9c  	*/
 	 	 	
 	unsigned int PSPWRDWNCLR0_UL;             	/* 0xa0		*/
 	
 	unsigned int PSPWRDWNCLR1_UL;             	/* 0xa4		*/
 	 	 	
 	unsigned int PSPWRDWNCLR2_UL;             	/* 0xa8		*/
 	
 	unsigned int PSPWRDWNCLR3_UL;             	/* 0xac		*/
        
} PCR_ST;

extern PCR_ST e_PCR_ST;
extern PCR_ST e_PCR_B_ST;

extern PCR_ST * PCR_Ptr;
extern PCR_ST * PCR_B_Ptr;

#endif

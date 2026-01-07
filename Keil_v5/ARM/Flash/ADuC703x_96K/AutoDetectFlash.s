FEE1DAT EQU 0xFFFF0E8C

        AREA |.text|, CODE, READONLY

	ALIGN
Blk1Exist  FUNCTION
         EXPORT Blk1Exist
         STMDB    	SP!, {R4,R5,R6}

         LDR         R0,=FEE1DAT
         LDMIA       R0,{R1,R2}
         ADD         R3,R1,#1
         ADD         R4,R2,#2
         STMIA       R0,{R3,R4}
         LDMIA       R0,{R5,R6}
         CMP         R5,R3
         MOVEQ       R0,#1
         MOVNE       R0,#0
         CMP         R6,R4
         MOVNE       R0,#0
         LDMIA	      SP!, {R4,R5,R6}
         BX          LR
	ENDFUNC


	END

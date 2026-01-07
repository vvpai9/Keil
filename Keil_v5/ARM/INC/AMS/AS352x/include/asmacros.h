;
; Copyright: 
; ----------------------------------------------------------------
; This confidential and proprietary software may be used only as
; authorised by a licensing agreement from ARM Limited
;   (C) COPYRIGHT 2000 ARM Limited
;       ALL RIGHTS RESERVED
; The entire notice above must be reproduced on all authorised
; copies and copies may only be made to the extent permitted
; by a licensing agreement from ARM Limited.
; ----------------------------------------------------------------
; File:     asmacros.h,v
; Revision: 1.12
; ----------------------------------------------------------------
; 
;  ----------------------------------------
;  Version and Release Control Information:
; 
;  File Name              : asmacros.h.rca
;  File Revision          : 1.2
; 
;  Release Information    : PrimeCell(TM)-GLOBAL-REL7v0
;  ----------------------------------------
; 
; Standard ARM Assembler macros
;
    
; Joint C/Assembler header file MACRO's
;
; These enable you to include the same constants in C and assembler files
; by using MACRO's to create a file which is readable by both C and Assembler.

; COMMENT
; Purpose: Allow comments common C/Assembler headers
; Syntax : COMMENT <anything you like!>

    MACRO
    COMMENT $a,$b,$c,$d,$e,$f,$g,$h
    MEND

; define
; Purpose: Allow #defines for common C/Assembler headers
; Syntax : #<space/tab>define<spaces><token><spaces><value><comment>
; (// and /* */ comments are stripped, <value> may be empty)
; small variable names are used to speed up the interpreter

    MACRO
$la    define $a
    LCLS aa ; input/value
    LCLA ab ; counter/pointer
    LCLA al ; length
    LCLS as ; scratch
    LCLS at ; token
    
aa    SETS "$a"
    ; first strip off token & exit if token only - no value
al    SETA :LEN:aa
ab    SETA 1
    WHILE (aa:LEFT:ab):RIGHT:1 <> " "
ab     SETA ab+1
     IF ab>al
       MEXIT
     ENDIF
    WEND
at    SETS aa:LEFT:ab
al    SETA al-ab
aa    SETS aa:RIGHT:al
    ; now strip off value - stopping at a comment
ab    SETA 2
    WHILE ab<=al
as     SETS (aa:LEFT:ab):RIGHT:2
     IF as="//":LOR:as="/*"
al      SETA ab-2
     ENDIF
ab     SETA ab+1
    WEND
aa    SETS aa:LEFT:al
$at    EQU $aa
    MEND
    
; ifndef
; Dummy instruction to support guarding of header files

    MACRO
$la    ifndef $a
    MEND

    END



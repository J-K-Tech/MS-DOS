;DSKCPY_ERR	DB	  0
DSKCPY_EXIT	EQU	  1	  ;AN000;DT user chose to exit diskcopy

;DSKCPY_WHICH	DB
DSKCPY_TO_A_720 EQU	  0	  ;AN000;DT
DSKCPY_TO_A_360 EQU	  1	  ;AN000;DT
DSKCPY_TO_B	EQU	  2	  ;AN000;DT

;DSKCPY_OPTION	DB
SOURCE1 	EQU	 0	  ;AN000;DT
NO_SOURCE1	EQU	 1	  ;AN000;DT

NOCHECK 	EQU	  0
DISKCOPY_TO	MACRO	 WHERE,HOW,CHECK	     ;;AN000;
		MOV  DSKCPY_WHICH,WHERE 	     ;;AN000;
		MOV  DSKCPY_OPTION,HOW		     ;;AN000;
		LEA  AX,CHECK			     ;;AN000;
		MOV  DSKCPY_SOURCE,AX		     ;;AN000;
		ENDM				     ;;AN000;

NOPANEL 	EQU	  0			     ;;AN000;
DISKCOPY_PANELS MACRO	 PANEL1, PANEL2, PANEL3      ;;AN000;
		MOV	 DSKCPY_PAN1,PANEL1	     ;;AN000;
		MOV	 DSKCPY_PAN2,PANEL2	     ;;AN000;
		MOV	 DSKCPY_PAN3,PANEL3	     ;;AN000;
		ENDM				     ;;AN000;

INSERT_DISK	MACRO	 DSK_PANEL, SRCH_FILE	     ;;AN000;
		MOV	 DISK_PANEL, DSK_PANEL	     ;;AN000;
		LEA	 DI,SRCH_FILE		     ;;AN000;
		MOV	 SEARCH_FILE, DI	     ;;AN000;
		CALL	 INSERT_DISK_ROUTINE	     ;;AN000;
		ENDM				     ;;AN000;

HANDLE_FORMAT_ERROR MACRO			     ;;AN000;
		LOCAL	FORERR1,FORERR2,FORERR3      ;;AN000;
		CMP	SUB_ERROR,6		     ;;AN000;
		JNE	FORERR1 		     ;;AN000;
		MOV	AX,PAN_DRIVE_ERROR	     ;;AN000;
		JMP	FORERR3 		     ;;AN000;
FORERR1:	CMP	SUB_ERROR,7		     ;;AN000;
		JNE	FORERR2 		     ;;AN000;
		MOV	AX,PAN_WRITE_PROT	     ;;AN000;
		JMP	FORERR3 		     ;;AN000;
FORERR2:	MOV	AX,ERR_GENERAL		     ;;AN000;
FORERR3:	HANDLE_ERROR AX,E_RETURN	     ;;AN000;
		ENDM				     ;;AN000;

; Listing generated by Microsoft (R) Optimizing Compiler Version 19.27.29111.0 

	TITLE	C:\Users\leonf\Desktop\vsCode\c\Interpreter\Interpreter_github\Interpreter\src\variable.c
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB MSVCRTD
INCLUDELIB OLDNAMES

PUBLIC	??_C@_05IJDJACGD@print@				; `string'
PUBLIC	??_C@_02HEBPBKGD@if@				; `string'
PUBLIC	??_C@_05OODBEKIG@while@				; `string'
PUBLIC	??_C@_03MEPDGFMA@var@				; `string'
PUBLIC	??_C@_05PKCPKOLM@undef@				; `string'
PUBLIC	??_C@_04LOAJBDKD@true@				; `string'
PUBLIC	??_C@_05LAPONLG@false@				; `string'
msvcjmc	SEGMENT
__1850469A_corecrt_stdio_config@h DB 01H
__01D10305_corecrt_wstdio@h DB 01H
__9FF75F13_stdio@h DB 01H
__ED9CC025_corecrt_memcpy_s@h DB 01H
__875914C9_corecrt_wstring@h DB 01H
__731387C4_string@h DB 01H
__8478A1A4_tokens@h DB 01H
__E2865EBA_corecrt_math@h DB 01H
__E66679EA_variable@c DB 01H
msvcjmc	ENDS
;	COMDAT ??_C@_05LAPONLG@false@
CONST	SEGMENT
??_C@_05LAPONLG@false@ DB 'false', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_04LOAJBDKD@true@
CONST	SEGMENT
??_C@_04LOAJBDKD@true@ DB 'true', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_05PKCPKOLM@undef@
CONST	SEGMENT
??_C@_05PKCPKOLM@undef@ DB 'undef', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_03MEPDGFMA@var@
CONST	SEGMENT
??_C@_03MEPDGFMA@var@ DB 'var', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_05OODBEKIG@while@
CONST	SEGMENT
??_C@_05OODBEKIG@while@ DB 'while', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_02HEBPBKGD@if@
CONST	SEGMENT
??_C@_02HEBPBKGD@if@ DB 'if', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_05IJDJACGD@print@
CONST	SEGMENT
??_C@_05IJDJACGD@print@ DB 'print', 00H			; `string'
CONST	ENDS
PUBLIC	___local_stdio_printf_options
PUBLIC	__vfprintf_l
PUBLIC	_printf
PUBLIC	_genVarAST
PUBLIC	_genIdentAST
PUBLIC	__JustMyCode_Default
PUBLIC	??_C@_0DB@LJCGOJNF@?$FLSYNTAX?5ERROR?$FN?5expected?5an?5iden@ ; `string'
PUBLIC	??_C@_0BI@COOHKODO@?$FLSYNTAX?5ERROR?$FN?5Line?5?$CFd?6@ ; `string'
PUBLIC	??_C@_0DB@FPDFOMNO@?$FLSYNTAX?5ERROR?$FN?5variable?5needs?5a@ ; `string'
EXTRN	__imp____acrt_iob_func:PROC
EXTRN	__imp____stdio_common_vfprintf:PROC
EXTRN	__imp__calloc:PROC
EXTRN	__imp__malloc:PROC
EXTRN	__imp__exit:PROC
EXTRN	_strcpy:PROC
EXTRN	_strlen:PROC
EXTRN	_newID_token:PROC
EXTRN	_mkastnode_ident:PROC
EXTRN	_binexpr_int:PROC
EXTRN	_scan_curToken:PROC
EXTRN	@__CheckForDebuggerJustMyCode@4:PROC
EXTRN	__RTC_CheckEsp:PROC
EXTRN	__RTC_InitBase:PROC
EXTRN	__RTC_Shutdown:PROC
EXTRN	_Line:DWORD
EXTRN	_currentToken:DWORD
EXTRN	__fltused:DWORD
_DATA	SEGMENT
COMM	?_OptionsStorage@?1??__local_stdio_printf_options@@9@9:QWORD							; `__local_stdio_printf_options'::`2'::_OptionsStorage
_DATA	ENDS
;	COMDAT rtc$TMZ
rtc$TMZ	SEGMENT
__RTC_Shutdown.rtc$TMZ DD FLAT:__RTC_Shutdown
rtc$TMZ	ENDS
;	COMDAT rtc$IMZ
rtc$IMZ	SEGMENT
__RTC_InitBase.rtc$IMZ DD FLAT:__RTC_InitBase
rtc$IMZ	ENDS
;	COMDAT ??_C@_0DB@FPDFOMNO@?$FLSYNTAX?5ERROR?$FN?5variable?5needs?5a@
CONST	SEGMENT
??_C@_0DB@FPDFOMNO@?$FLSYNTAX?5ERROR?$FN?5variable?5needs?5a@ DB '[SYNTAX'
	DB	' ERROR] variable needs a value (Line %d)', 0aH, 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BI@COOHKODO@?$FLSYNTAX?5ERROR?$FN?5Line?5?$CFd?6@
CONST	SEGMENT
??_C@_0BI@COOHKODO@?$FLSYNTAX?5ERROR?$FN?5Line?5?$CFd?6@ DB '[SYNTAX ERRO'
	DB	'R] Line %d', 0aH, 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0DB@LJCGOJNF@?$FLSYNTAX?5ERROR?$FN?5expected?5an?5iden@
CONST	SEGMENT
??_C@_0DB@LJCGOJNF@?$FLSYNTAX?5ERROR?$FN?5expected?5an?5iden@ DB '[SYNTAX'
	DB	' ERROR] expected an identifier (Line %d)', 0aH, 00H ; `string'
CONST	ENDS
; Function compile flags: /Odt
;	COMDAT __JustMyCode_Default
_TEXT	SEGMENT
__JustMyCode_Default PROC				; COMDAT
	push	ebp
	mov	ebp, esp
	pop	ebp
	ret	0
__JustMyCode_Default ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File C:\Users\leonf\Desktop\vsCode\c\Interpreter\Interpreter_github\Interpreter\src\variable.c
;	COMDAT _genIdentAST
_TEXT	SEGMENT
_varName$ = -32						; size = 4
_ID_token$ = -20					; size = 4
_node$ = -8						; size = 4
_genIdentAST PROC					; COMDAT

; 46   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 228				; 000000e4H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-228]
	mov	ecx, 57					; 00000039H
	mov	eax, -858993460				; ccccccccH
	rep stosd
	mov	ecx, OFFSET __E66679EA_variable@c
	call	@__CheckForDebuggerJustMyCode@4

; 47   : 
; 48   : 	struct AST_Node* node = NULL;

	mov	DWORD PTR _node$[ebp], 0

; 49   : 
; 50   : 
; 51   : 	if (currentToken->tokenType != TT_IDENT)

	mov	eax, DWORD PTR _currentToken
	cmp	DWORD PTR [eax], 18			; 00000012H
	je	SHORT $LN2@genIdentAS

; 52   : 	{
; 53   : 		printf("[SYNTAX ERROR] expected an identifier (Line %d)\n", Line);

	mov	eax, DWORD PTR _Line
	push	eax
	push	OFFSET ??_C@_0DB@LJCGOJNF@?$FLSYNTAX?5ERROR?$FN?5expected?5an?5iden@
	call	_printf
	add	esp, 8

; 54   : 		exit(1);

	mov	esi, esp
	push	1
	call	DWORD PTR __imp__exit
	cmp	esi, esp
	call	__RTC_CheckEsp
$LN2@genIdentAS:

; 55   : 	}
; 56   : 	struct Token* ID_token = currentToken;

	mov	eax, DWORD PTR _currentToken
	mov	DWORD PTR _ID_token$[ebp], eax

; 57   : 	char* varName = calloc(strlen(ID_token->IdentToken_name), sizeof(char));

	mov	esi, esp
	push	1
	mov	eax, DWORD PTR _ID_token$[ebp]
	mov	ecx, DWORD PTR [eax+32]
	push	ecx
	call	_strlen
	add	esp, 4
	push	eax
	call	DWORD PTR __imp__calloc
	add	esp, 8
	cmp	esi, esp
	call	__RTC_CheckEsp
	mov	DWORD PTR _varName$[ebp], eax

; 58   : 	varName = strcpy(varName, ID_token->IdentToken_name);

	mov	eax, DWORD PTR _ID_token$[ebp]
	mov	ecx, DWORD PTR [eax+32]
	push	ecx
	mov	edx, DWORD PTR _varName$[ebp]
	push	edx
	call	_strcpy
	add	esp, 8
	mov	DWORD PTR _varName$[ebp], eax

; 59   : 	scan_curToken();

	call	_scan_curToken

; 60   : 
; 61   : 	if (currentToken->tokenType == TT_OP_END)

	mov	eax, DWORD PTR _currentToken
	cmp	DWORD PTR [eax], 6
	jne	SHORT $LN3@genIdentAS

; 62   : 	{
; 63   : 		printf("[SYNTAX ERROR] variable needs a value (Line %d)\n", Line);

	mov	eax, DWORD PTR _Line
	push	eax
	push	OFFSET ??_C@_0DB@FPDFOMNO@?$FLSYNTAX?5ERROR?$FN?5variable?5needs?5a@
	call	_printf
	add	esp, 8

; 64   : 		exit(1);

	mov	esi, esp
	push	1
	call	DWORD PTR __imp__exit
	cmp	esi, esp
	call	__RTC_CheckEsp
$LN3@genIdentAS:

; 65   : 	}
; 66   : 	if (currentToken->tokenType == TT_EQUALS)

	mov	eax, DWORD PTR _currentToken
	cmp	DWORD PTR [eax], 19			; 00000013H
	jne	SHORT $LN4@genIdentAS

; 67   : 	{
; 68   : 		node = mkastnode_ident(TT_IDENT, 0, 0, binexpr_int(0, INTERRUPT_TOKEN_DEFAULT), NULL, newID_token(DT_INT, 1, 0, varName, 0, new_DATA_STRUCT(NULL, NULL, NULL, NULL, NULL, -1, 1)), varName, NULL);

	push	0
	mov	eax, DWORD PTR _varName$[ebp]
	push	eax
	push	1
	push	-1
	push	0
	push	0
	push	0
	push	0
	push	0
	push	0
	call	_new_DATA_STRUCT
	add	esp, 32					; 00000020H
	push	eax
	push	0
	mov	ecx, DWORD PTR _varName$[ebp]
	push	ecx
	push	0
	push	0
	push	1
	push	0
	call	_newID_token
	add	esp, 28					; 0000001cH
	push	eax
	push	0
	push	-1
	push	0
	call	_binexpr_int
	add	esp, 8
	push	eax
	sub	esp, 8
	xorps	xmm0, xmm0
	movsd	QWORD PTR [esp], xmm0
	push	0
	push	0
	push	18					; 00000012H
	call	_mkastnode_ident
	add	esp, 40					; 00000028H
	mov	DWORD PTR _node$[ebp], eax

; 69   : 		return node;

	mov	eax, DWORD PTR _node$[ebp]
	jmp	SHORT $LN1@genIdentAS
$LN4@genIdentAS:

; 70   : 	}
; 71   : 
; 72   : 	printf("[SYNTAX ERROR] Line %d\n", Line);

	mov	eax, DWORD PTR _Line
	push	eax
	push	OFFSET ??_C@_0BI@COOHKODO@?$FLSYNTAX?5ERROR?$FN?5Line?5?$CFd?6@
	call	_printf
	add	esp, 8

; 73   : 	exit(1);

	mov	esi, esp
	push	1
	call	DWORD PTR __imp__exit
	cmp	esi, esp
	call	__RTC_CheckEsp

; 74   : 	return node;

	mov	eax, DWORD PTR _node$[ebp]
$LN1@genIdentAS:

; 75   : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 228				; 000000e4H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
_genIdentAST ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File C:\Users\leonf\Desktop\vsCode\c\Interpreter\Interpreter_github\Interpreter\src\variable.c
;	COMDAT _genVarAST
_TEXT	SEGMENT
_varName$1 = -32					; size = 4
_ID_token$2 = -20					; size = 4
_node$ = -8						; size = 4
_genVarAST PROC						; COMDAT

; 9    : {

	push	ebp
	mov	ebp, esp
	sub	esp, 228				; 000000e4H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-228]
	mov	ecx, 57					; 00000039H
	mov	eax, -858993460				; ccccccccH
	rep stosd
	mov	ecx, OFFSET __E66679EA_variable@c
	call	@__CheckForDebuggerJustMyCode@4

; 10   : 	struct AST_Node* node = NULL;

	mov	DWORD PTR _node$[ebp], 0

; 11   : 	if (currentToken->tokenType == TT_VAR)

	mov	eax, DWORD PTR _currentToken
	cmp	DWORD PTR [eax], 20			; 00000014H
	jne	$LN2@genVarAST

; 12   : 	{
; 13   : 		scan_curToken();

	call	_scan_curToken

; 14   : 
; 15   : 		if (currentToken->tokenType != TT_IDENT)

	mov	eax, DWORD PTR _currentToken
	cmp	DWORD PTR [eax], 18			; 00000012H
	je	SHORT $LN3@genVarAST

; 16   : 		{
; 17   : 			printf("[SYNTAX ERROR] expected an identifier (Line %d)\n", Line);

	mov	eax, DWORD PTR _Line
	push	eax
	push	OFFSET ??_C@_0DB@LJCGOJNF@?$FLSYNTAX?5ERROR?$FN?5expected?5an?5iden@
	call	_printf
	add	esp, 8

; 18   : 			exit(1);

	mov	esi, esp
	push	1
	call	DWORD PTR __imp__exit
	cmp	esi, esp
	call	__RTC_CheckEsp
$LN3@genVarAST:

; 19   : 		}
; 20   : 		struct Token* ID_token = currentToken;

	mov	eax, DWORD PTR _currentToken
	mov	DWORD PTR _ID_token$2[ebp], eax

; 21   : 		char* varName = calloc(strlen(ID_token->IdentToken_name), sizeof(char));

	mov	esi, esp
	push	1
	mov	eax, DWORD PTR _ID_token$2[ebp]
	mov	ecx, DWORD PTR [eax+32]
	push	ecx
	call	_strlen
	add	esp, 4
	push	eax
	call	DWORD PTR __imp__calloc
	add	esp, 8
	cmp	esi, esp
	call	__RTC_CheckEsp
	mov	DWORD PTR _varName$1[ebp], eax

; 22   : 		varName = strcpy(varName, ID_token->IdentToken_name);

	mov	eax, DWORD PTR _ID_token$2[ebp]
	mov	ecx, DWORD PTR [eax+32]
	push	ecx
	mov	edx, DWORD PTR _varName$1[ebp]
	push	edx
	call	_strcpy
	add	esp, 8
	mov	DWORD PTR _varName$1[ebp], eax

; 23   : 		scan_curToken();

	call	_scan_curToken

; 24   : 
; 25   : 		if (currentToken->tokenType == TT_OP_END)

	mov	eax, DWORD PTR _currentToken
	cmp	DWORD PTR [eax], 6
	jne	SHORT $LN4@genVarAST

; 26   : 		{
; 27   : 			node = mkastnode_ident(TT_IDENT, 0, 0, NULL, NULL, newID_token(DT_INT, 0, 0, varName, 1, new_DATA_STRUCT(NULL, NULL, NULL, NULL, NULL, -1, 1)), varName, NULL);

	push	0
	mov	eax, DWORD PTR _varName$1[ebp]
	push	eax
	push	1
	push	-1
	push	0
	push	0
	push	0
	push	0
	push	0
	push	0
	call	_new_DATA_STRUCT
	add	esp, 32					; 00000020H
	push	eax
	push	1
	mov	ecx, DWORD PTR _varName$1[ebp]
	push	ecx
	push	0
	push	0
	push	0
	push	0
	call	_newID_token
	add	esp, 28					; 0000001cH
	push	eax
	push	0
	push	0
	sub	esp, 8
	xorps	xmm0, xmm0
	movsd	QWORD PTR [esp], xmm0
	push	0
	push	0
	push	18					; 00000012H
	call	_mkastnode_ident
	add	esp, 40					; 00000028H
	mov	DWORD PTR _node$[ebp], eax

; 28   : 			scan_curToken();

	call	_scan_curToken

; 29   : 			return node;

	mov	eax, DWORD PTR _node$[ebp]
	jmp	$LN1@genVarAST

; 30   : 		}

	jmp	SHORT $LN6@genVarAST
$LN4@genVarAST:

; 31   : 		else if (currentToken->tokenType == TT_EQUALS)

	mov	eax, DWORD PTR _currentToken
	cmp	DWORD PTR [eax], 19			; 00000013H
	jne	SHORT $LN6@genVarAST

; 32   : 		{
; 33   : 			node = mkastnode_ident(TT_IDENT, 0, 0, binexpr_int(0, INTERRUPT_TOKEN_DEFAULT), NULL, newID_token(DT_INT, 1, 0, varName, 1, new_DATA_STRUCT(NULL, NULL, NULL, NULL, NULL, -1, 1)), varName, NULL);

	push	0
	mov	eax, DWORD PTR _varName$1[ebp]
	push	eax
	push	1
	push	-1
	push	0
	push	0
	push	0
	push	0
	push	0
	push	0
	call	_new_DATA_STRUCT
	add	esp, 32					; 00000020H
	push	eax
	push	1
	mov	ecx, DWORD PTR _varName$1[ebp]
	push	ecx
	push	0
	push	0
	push	1
	push	0
	call	_newID_token
	add	esp, 28					; 0000001cH
	push	eax
	push	0
	push	-1
	push	0
	call	_binexpr_int
	add	esp, 8
	push	eax
	sub	esp, 8
	xorps	xmm0, xmm0
	movsd	QWORD PTR [esp], xmm0
	push	0
	push	0
	push	18					; 00000012H
	call	_mkastnode_ident
	add	esp, 40					; 00000028H
	mov	DWORD PTR _node$[ebp], eax

; 34   : 			return node;

	mov	eax, DWORD PTR _node$[ebp]
	jmp	SHORT $LN1@genVarAST
$LN6@genVarAST:

; 35   : 		}
; 36   : 
; 37   : 		printf("[SYNTAX ERROR] Line %d\n", Line);

	mov	eax, DWORD PTR _Line
	push	eax
	push	OFFSET ??_C@_0BI@COOHKODO@?$FLSYNTAX?5ERROR?$FN?5Line?5?$CFd?6@
	call	_printf
	add	esp, 8

; 38   : 		exit(1);

	mov	esi, esp
	push	1
	call	DWORD PTR __imp__exit
	cmp	esi, esp
	call	__RTC_CheckEsp
$LN2@genVarAST:

; 39   : 
; 40   : 	}
; 41   : 	return node;

	mov	eax, DWORD PTR _node$[ebp]
$LN1@genVarAST:

; 42   : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 228				; 000000e4H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
_genVarAST ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File C:\Users\leonf\Desktop\vsCode\c\Interpreter\Interpreter_github\Interpreter\src\header\tokens.h
;	COMDAT _new_DATA_STRUCT
_TEXT	SEGMENT
_init$ = -8						; size = 4
_strVal$ = 8						; size = 4
_boolVal$ = 12						; size = 4
_doubleVal$ = 16					; size = 4
_intVal$ = 20						; size = 8
_charVal$ = 28						; size = 4
_dataType$ = 32						; size = 4
_minusVal$ = 36						; size = 4
_new_DATA_STRUCT PROC					; COMDAT

; 28   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 204				; 000000ccH
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-204]
	mov	ecx, 51					; 00000033H
	mov	eax, -858993460				; ccccccccH
	rep stosd
	mov	ecx, OFFSET __8478A1A4_tokens@h
	call	@__CheckForDebuggerJustMyCode@4

; 29   : 	struct DATA_STRUCT* init = malloc(sizeof(struct DATA_STRUCT));

	mov	esi, esp
	push	28					; 0000001cH
	call	DWORD PTR __imp__malloc
	add	esp, 4
	cmp	esi, esp
	call	__RTC_CheckEsp
	mov	DWORD PTR _init$[ebp], eax

; 30   : 	init->strVal = strVal;

	mov	eax, DWORD PTR _init$[ebp]
	mov	ecx, DWORD PTR _strVal$[ebp]
	mov	DWORD PTR [eax], ecx

; 31   : 	init->boolVal = boolVal;

	mov	eax, DWORD PTR _init$[ebp]
	mov	ecx, DWORD PTR _boolVal$[ebp]
	mov	DWORD PTR [eax+4], ecx

; 32   : 	init->doubleVal = doubleVal;

	mov	eax, DWORD PTR _init$[ebp]
	mov	ecx, DWORD PTR _doubleVal$[ebp]
	mov	DWORD PTR [eax+8], ecx

; 33   : 	init->intVal = intVal;

	mov	eax, DWORD PTR _intVal$[ebp]
	mov	ecx, DWORD PTR _init$[ebp]
	mov	DWORD PTR [ecx+12], eax

; 34   : 	init->charVal = charVal;

	mov	eax, DWORD PTR _init$[ebp]
	mov	ecx, DWORD PTR _charVal$[ebp]
	mov	DWORD PTR [eax+16], ecx

; 35   : 	init->dataType = dataType;

	mov	eax, DWORD PTR _init$[ebp]
	mov	ecx, DWORD PTR _dataType$[ebp]
	mov	DWORD PTR [eax+20], ecx

; 36   : 	init->minusVal = minusVal;

	mov	eax, DWORD PTR _init$[ebp]
	mov	ecx, DWORD PTR _minusVal$[ebp]
	mov	DWORD PTR [eax+24], ecx

; 37   : 	return init;

	mov	eax, DWORD PTR _init$[ebp]

; 38   : };

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 204				; 000000ccH
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
_new_DATA_STRUCT ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File D:\Windows Kits\10\Include\10.0.18362.0\ucrt\stdio.h
;	COMDAT _printf
_TEXT	SEGMENT
__ArgList$ = -20					; size = 4
__Result$ = -8						; size = 4
__Format$ = 8						; size = 4
_printf	PROC						; COMDAT

; 954  :     {

	push	ebp
	mov	ebp, esp
	sub	esp, 216				; 000000d8H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-216]
	mov	ecx, 54					; 00000036H
	mov	eax, -858993460				; ccccccccH
	rep stosd
	mov	ecx, OFFSET __9FF75F13_stdio@h
	call	@__CheckForDebuggerJustMyCode@4

; 955  :         int _Result;
; 956  :         va_list _ArgList;
; 957  :         __crt_va_start(_ArgList, _Format);

	lea	eax, DWORD PTR __Format$[ebp+4]
	mov	DWORD PTR __ArgList$[ebp], eax

; 958  :         _Result = _vfprintf_l(stdout, _Format, NULL, _ArgList);

	mov	eax, DWORD PTR __ArgList$[ebp]
	push	eax
	push	0
	mov	ecx, DWORD PTR __Format$[ebp]
	push	ecx
	mov	esi, esp
	push	1
	call	DWORD PTR __imp____acrt_iob_func
	add	esp, 4
	cmp	esi, esp
	call	__RTC_CheckEsp
	push	eax
	call	__vfprintf_l
	add	esp, 16					; 00000010H
	mov	DWORD PTR __Result$[ebp], eax

; 959  :         __crt_va_end(_ArgList);

	mov	DWORD PTR __ArgList$[ebp], 0

; 960  :         return _Result;

	mov	eax, DWORD PTR __Result$[ebp]

; 961  :     }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 216				; 000000d8H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
_printf	ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File D:\Windows Kits\10\Include\10.0.18362.0\ucrt\stdio.h
;	COMDAT __vfprintf_l
_TEXT	SEGMENT
__Stream$ = 8						; size = 4
__Format$ = 12						; size = 4
__Locale$ = 16						; size = 4
__ArgList$ = 20						; size = 4
__vfprintf_l PROC					; COMDAT

; 642  :     {

	push	ebp
	mov	ebp, esp
	sub	esp, 192				; 000000c0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-192]
	mov	ecx, 48					; 00000030H
	mov	eax, -858993460				; ccccccccH
	rep stosd
	mov	ecx, OFFSET __9FF75F13_stdio@h
	call	@__CheckForDebuggerJustMyCode@4

; 643  :         return __stdio_common_vfprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);

	mov	esi, esp
	mov	eax, DWORD PTR __ArgList$[ebp]
	push	eax
	mov	ecx, DWORD PTR __Locale$[ebp]
	push	ecx
	mov	edx, DWORD PTR __Format$[ebp]
	push	edx
	mov	eax, DWORD PTR __Stream$[ebp]
	push	eax
	call	___local_stdio_printf_options
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR [eax]
	push	edx
	call	DWORD PTR __imp____stdio_common_vfprintf
	add	esp, 24					; 00000018H
	cmp	esi, esp
	call	__RTC_CheckEsp

; 644  :     }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 192				; 000000c0H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
__vfprintf_l ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File D:\Windows Kits\10\Include\10.0.18362.0\ucrt\corecrt_stdio_config.h
;	COMDAT ___local_stdio_printf_options
_TEXT	SEGMENT
___local_stdio_printf_options PROC			; COMDAT

; 86   :     {

	push	ebp
	mov	ebp, esp
	sub	esp, 192				; 000000c0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-192]
	mov	ecx, 48					; 00000030H
	mov	eax, -858993460				; ccccccccH
	rep stosd
	mov	ecx, OFFSET __1850469A_corecrt_stdio_config@h
	call	@__CheckForDebuggerJustMyCode@4

; 87   :         static unsigned __int64 _OptionsStorage;
; 88   :         return &_OptionsStorage;

	mov	eax, OFFSET ?_OptionsStorage@?1??__local_stdio_printf_options@@9@9 ; `__local_stdio_printf_options'::`2'::_OptionsStorage

; 89   :     }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 192				; 000000c0H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
___local_stdio_printf_options ENDP
_TEXT	ENDS
END

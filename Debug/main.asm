; Listing generated by Microsoft (R) Optimizing Compiler Version 19.27.29111.0 

	TITLE	C:\Users\leonf\Desktop\vsCode\c\Interpreter\Interpreter_github\Interpreter\src\main.c
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB MSVCRTD
INCLUDELIB OLDNAMES

PUBLIC	_Text
PUBLIC	_Line
PUBLIC	_Putback
PUBLIC	_Infile
PUBLIC	_Outfile
PUBLIC	_globl_var_stack
PUBLIC	_var_stack_size
PUBLIC	_currentToken
PUBLIC	_globl_putback_token
PUBLIC	??_C@_05IJDJACGD@print@				; `string'
PUBLIC	??_C@_02HEBPBKGD@if@				; `string'
PUBLIC	??_C@_05OODBEKIG@while@				; `string'
PUBLIC	??_C@_03MEPDGFMA@var@				; `string'
PUBLIC	??_C@_05PKCPKOLM@undef@				; `string'
PUBLIC	??_C@_04LOAJBDKD@true@				; `string'
PUBLIC	??_C@_05LAPONLG@false@				; `string'
PUBLIC	_globl_symtable
_BSS	SEGMENT
_Text	DB	0201H DUP (?)
	ALIGN	4

_Putback DD	01H DUP (?)
_Infile	DD	01H DUP (?)
_Outfile DD	01H DUP (?)
_globl_var_stack DD 01H DUP (?)
_var_stack_size DD 01H DUP (?)
_currentToken DD 01H DUP (?)
_globl_putback_token DD 01H DUP (?)
_globl_symtable DD 01388H DUP (?)
_BSS	ENDS
msvcjmc	SEGMENT
__1850469A_corecrt_stdio_config@h DB 01H
__01D10305_corecrt_wstdio@h DB 01H
__9FF75F13_stdio@h DB 01H
__ED9CC025_corecrt_memcpy_s@h DB 01H
__875914C9_corecrt_wstring@h DB 01H
__731387C4_string@h DB 01H
__8478A1A4_tokens@h DB 01H
__E2865EBA_corecrt_math@h DB 01H
__D01D7B14_main@c DB 01H
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
_DATA	SEGMENT
_Line	DD	01H
_DATA	ENDS
PUBLIC	___local_stdio_printf_options
PUBLIC	__vfprintf_l
PUBLIC	_printf
PUBLIC	_main
PUBLIC	__JustMyCode_Default
PUBLIC	??_C@_08OKJMHBIC@test?4txt@			; `string'
PUBLIC	??_C@_01KDCPPGHE@r@				; `string'
PUBLIC	??_C@_0CC@IPMIMCGM@?$FLERROR?$FN?5could?5not?5open?5file?5?8?$CFs@ ; `string'
EXTRN	__imp____acrt_iob_func:PROC
EXTRN	__imp__fopen:PROC
EXTRN	__imp____stdio_common_vfprintf:PROC
EXTRN	__imp__malloc:PROC
EXTRN	__imp__exit:PROC
EXTRN	_newLinkedList:PROC
EXTRN	_genMainAST:PROC
EXTRN	_interpretMainAST:PROC
EXTRN	_varStack_push_frame:PROC
EXTRN	_mkVarStack:PROC
EXTRN	@__CheckForDebuggerJustMyCode@4:PROC
EXTRN	__RTC_CheckEsp:PROC
EXTRN	__RTC_InitBase:PROC
EXTRN	__RTC_Shutdown:PROC
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
;	COMDAT ??_C@_0CC@IPMIMCGM@?$FLERROR?$FN?5could?5not?5open?5file?5?8?$CFs@
CONST	SEGMENT
??_C@_0CC@IPMIMCGM@?$FLERROR?$FN?5could?5not?5open?5file?5?8?$CFs@ DB '[E'
	DB	'RROR] could not open file ''%s''', 0aH, 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_01KDCPPGHE@r@
CONST	SEGMENT
??_C@_01KDCPPGHE@r@ DB 'r', 00H				; `string'
CONST	ENDS
;	COMDAT ??_C@_08OKJMHBIC@test?4txt@
CONST	SEGMENT
??_C@_08OKJMHBIC@test?4txt@ DB 'test.txt', 00H		; `string'
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
; File C:\Users\leonf\Desktop\vsCode\c\Interpreter\Interpreter_github\Interpreter\src\main.c
;	COMDAT _main
_TEXT	SEGMENT
_ast_root$1 = -32					; size = 4
_tokenList$ = -20					; size = 4
_fileName$ = -8						; size = 4
_argc$ = 8						; size = 4
_argv$ = 12						; size = 4
_main	PROC						; COMDAT

; 39   : {

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
	mov	ecx, OFFSET __D01D7B14_main@c
	call	@__CheckForDebuggerJustMyCode@4

; 40   : 	initGloblVar();

	call	_initGloblVar

; 41   : 	const char* fileName = "test.txt";

	mov	DWORD PTR _fileName$[ebp], OFFSET ??_C@_08OKJMHBIC@test?4txt@

; 42   : 	LinkedList* tokenList = newLinkedList();

	call	_newLinkedList
	mov	DWORD PTR _tokenList$[ebp], eax

; 43   : 
; 44   : 
; 45   : 	Infile = fopen(fileName, "r");

	mov	esi, esp
	push	OFFSET ??_C@_01KDCPPGHE@r@
	mov	eax, DWORD PTR _fileName$[ebp]
	push	eax
	call	DWORD PTR __imp__fopen
	add	esp, 8
	cmp	esi, esp
	call	__RTC_CheckEsp
	mov	DWORD PTR _Infile, eax

; 46   : 	if (Infile != NULL)

	cmp	DWORD PTR _Infile, 0
	je	SHORT $LN2@main

; 47   : 	{
; 48   : 		globl_var_stack = mkVarStack();

	call	_mkVarStack
	mov	DWORD PTR _globl_var_stack, eax

; 49   : 		struct AST_Node* ast_root = genMainAST(0, SCOPE_MODE_DEFAULT);

	push	0
	push	0
	call	_genMainAST
	add	esp, 8
	mov	DWORD PTR _ast_root$1[ebp], eax

; 50   : 		varStack_push_frame();  // globl frame

	call	_varStack_push_frame

; 51   : 		interpretMainAST(ast_root);

	mov	eax, DWORD PTR _ast_root$1[ebp]
	push	eax
	call	_interpretMainAST
	add	esp, 4

; 52   : 
; 53   : #if 0
; 54   : 		struct AST_Node* curNode = ast_root;
; 55   : 		printf("\n\n\ncurNode:  %d\n", curNode->tokenType);
; 56   : #endif
; 57   : 
; 58   : 		/*
; 59   : 		int** intArr = calloc(50, sizeof(int));
; 60   : 		if (intArr[65] == NULL)
; 61   : 		{
; 62   : 			printf("NULL\n");
; 63   : 		}
; 64   : 		*/
; 65   : 
; 66   : 		exit(0);

	mov	esi, esp
	push	0
	call	DWORD PTR __imp__exit
	cmp	esi, esp
	call	__RTC_CheckEsp
$LN2@main:

; 67   : 	}
; 68   : 
; 69   : 	printf("[ERROR] could not open file '%s'\n", fileName);

	mov	eax, DWORD PTR _fileName$[ebp]
	push	eax
	push	OFFSET ??_C@_0CC@IPMIMCGM@?$FLERROR?$FN?5could?5not?5open?5file?5?8?$CFs@
	call	_printf
	add	esp, 8

; 70   : 
; 71   : 	exit(1);

	mov	esi, esp
	push	1
	call	DWORD PTR __imp__exit
	cmp	esi, esp
	call	__RTC_CheckEsp
$LN3@main:

; 72   : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 228				; 000000e4H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
_main	ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File C:\Users\leonf\Desktop\vsCode\c\Interpreter\Interpreter_github\Interpreter\src\main.c
;	COMDAT _initGloblVar
_TEXT	SEGMENT
_initGloblVar PROC					; COMDAT

; 28   : {

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
	mov	ecx, OFFSET __D01D7B14_main@c
	call	@__CheckForDebuggerJustMyCode@4

; 29   : 	currentToken = malloc(sizeof(struct Token));

	mov	esi, esp
	push	56					; 00000038H
	call	DWORD PTR __imp__malloc
	add	esp, 4
	cmp	esi, esp
	call	__RTC_CheckEsp
	mov	DWORD PTR _currentToken, eax

; 30   : 	Line = 1;

	mov	DWORD PTR _Line, 1

; 31   : 	Putback = 0;

	mov	DWORD PTR _Putback, 0

; 32   : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 192				; 000000c0H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
_initGloblVar ENDP
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
INCLUDE Irvine32.inc
.data

str1 BYTE "Calculate Perimeter 2-Hexagon (LOOP and ADD instructions) :", 0dh, 0ah, 0
str2 BYTE "Input Hexagon 1 (side length) : ", 0
str3 BYTE "Input Hexagon 2 (side length) : ", 0
str4 BYTE "Result of Perimeter Hexagon 1 and 2 :", 0dh, 0ah, 0
str5 BYTE "Total Perimeter :", 0

sideHex1 DWORD ?
sideHex2 DWORD ?
Perimeter_hexagon1 DWORD ?
Perimeter_hexagon2 DWORD ?
TotalPerimeter DWORD ?


str6 BYTE "Calculate SUM (unsign INT) index (Odd or Even) in array Hello[6] : ", 0dh, 0ah, 0
str7 BYTE "Integer Input : ", 0
str8 BYTE "Result Sum Hello[Index]: ", 0
str9 BYTE "Sum Hello[even] index location : ", 0
str10 BYTE "Sum Hello[odd] index location : ", 0

HELLO dword 6 dup(0)
TotalEVEN dword ?
TotalODD dword ?


menu1 BYTE "Welcome to Simple Math Activities :",0dh,0ah,0
menu2 BYTE "Main Menu :",0dh,0ah,0
menu3 BYTE "1. To calculate Perimeter Hexagon (Loop and ADD instructions)",0
menu4 BYTE "2. To calculate SUM (unsign int) index [Odd or Even] in an Array Hello [6]",0dh,0ah,0
menu5 BYTE "Select Your Input :",0
menu6 BYTE "Press 'y' to Main Menu or 'n' to Exit the benchmark :",0
menu7 BYTE "Thank you... BYE !!!",0

select DWORD ?
choice BYTE ?

.code
main PROC

menu :
	Call clrscr
	mov edx,offset menu1
	Call WriteString
	Call crlf
	mov edx,offset menu2
	Call WriteString
	Call crlf
	mov edx, offset menu3
	Call WriteString
	Call crlf
	mov edx, offset menu4
	Call WriteString
	Call crlf
	mov edx,offset menu5
	Call WriteString
	Call ReadDec
	mov select,eax

	CMP select,1
	JE periHex_loopAdd
	
	CMP select,2
	JE calSum_oddeven

periHex_loopAdd :
	call Clrscr
	mov edx, offset str1
	call WriteString
	call Crlf

	mov edx, offset str2
	call WriteString
	call ReadDec
	mov sideHex1, eax

	mov edx, offset str3
	call WriteString
	call ReadDec
	mov sideHex2, eax
	call Crlf


	mov eax, 0
	mov ecx, 6
	L1:
	add eax, sideHex1
	LOOP L1
	mov Perimeter_hexagon1, eax

	mov ebx, 0
	mov ecx, 6
	L2:
	add ebx, sideHex2
	LOOP L2
	mov Perimeter_hexagon2, ebx

	add eax, ebx
	mov TotalPerimeter, eax

	call Crlf
	mov edx, offset str4
	call WriteString

	mov eax, Perimeter_hexagon1
	call WriteDec
	call Crlf

	mov eax, Perimeter_hexagon2
	call WriteDec
	call Crlf
	call Crlf

	mov edx, offset str5
	call WriteString
	mov eax, TotalPerimeter
	call WriteDec
	call Crlf
	call Crlf

	mov edx, offset menu6
	Call WriteString
	Call ReadChar
	Call WriteChar
	mov choice, al
	CMP choice, 'y'
	JE menu

	CMP choice, 'n'
	JE bye

	exit

calSum_oddeven :
	call clrscr
	mov edx, offset str6
	call WriteString
	call crlf
	mov ecx, 6
	mov esi, offset HELLO

	L3 :
	mov edx, offset str7
	call WriteString
	call ReadDec
	mov[esi], eax
	add esi, 4
	LOOP L3

	mov ecx, 3
	mov esi, offset HELLO
	mov eax, 0

	L4:
	add eax, [esi]
	add esi, 8
	LOOP L4
	mov TotalEVEN, eax

	mov ecx, 3
	mov esi, offset HELLO
	add esi, 4
	mov eax, 0

	L5:
	add eax, [esi]
	add esi, 8
	LOOP L5
	mov TotalODD, eax

	call crlf
	mov edx, offset str8
	call WriteString
	call crlf
	call crlf

	mov edx, offset str9
	call WriteString
	mov eax, TotalEVEN
	call WriteDec
	call crlf

	mov edx, offset str10
	call WriteString
	mov eax, TotalODD
	call WriteDec
	call crlf
	call crlf

	mov edx, offset menu6
	Call WriteString
	Call ReadChar
	Call WriteChar
	mov choice, al
	CMP choice, 'y'
	JE menu

	CMP choice, 'n'
	JE bye

bye :
	Call crlf
	Call crlf
	mov edx,offset menu7
	Call WriteString
	Call crlf

exit
main ENDP
END main
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

.code
main PROC
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


mov eax,0
mov ecx,6
L1:
add eax,sideHex1
LOOP L1
mov Perimeter_hexagon1,eax

mov ebx,0
mov ecx,6
L2:
add ebx, sideHex2
LOOP L2
mov Perimeter_hexagon2, ebx

add eax, ebx
mov TotalPerimeter,eax

call Crlf
mov edx, offset str4
call WriteString

mov eax,Perimeter_hexagon1
call WriteDec
call Crlf

mov eax,Perimeter_hexagon2
call WriteDec
call Crlf


mov edx,offset str5
call WriteString
mov eax, TotalPerimeter
call WriteDec
call Crlf

exit
main ENDP
END main
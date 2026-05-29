
INCLUDE Irvine32.inc

.data
str1 BYTE "Calculate SUM (unsign INT) index (Odd or Even) in array Hello[6] : ", 0dh, 0ah, 0
str2 BYTE "Integer Input : ", 0
str3 BYTE "Result Sum Hello[Index]: ", 0
str4 BYTE "Sum Hello[even] index location : ", 0
str5 BYTE "Sum Hello[odd] index location : ", 0
HELLO dword 6 dup(0)
TotalEVEN dword ?
TotalODD dword ?

.code
main PROC

call Clrscr
mov edx, offset str1
call WriteString
call crlf
mov ecx, 6
mov esi, offset HELLO

L1:
mov edx, offset str2
call WriteString
call ReadDec
mov[esi], eax
add esi, 4
LOOP L1

mov ecx, 3
mov esi, offset HELLO
mov eax, 0

L2:  
add eax, [esi]
add esi, 8
LOOP L2
mov TotalEVEN, eax

mov ecx, 3
mov esi, offset HELLO
add esi, 4
mov eax, 0

L3:  
add eax, [esi]
add esi, 8
LOOP L3
mov TotalODD, eax

call crlf
mov edx, offset str3
call WriteString
call crlf
call crlf

mov edx, offset str4
call WriteString
mov eax, TotalEVEN
call WriteDec
call crlf

mov edx, offset str5
call WriteString
mov eax, TotalODD
call WriteDec
call crlf

exit
main ENDP
END main
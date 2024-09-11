;lab2task2code
[org 0x0100]
;code
Mov ax, [num1] ;ax=?
Mov ax, [num2] ;ax=?
Mov ax, [num2+2] ;ax=?
Mov ax, [num2+1] ;ax=?
Mov al, [num2+3] ;ax=?
Mov ah, [num1] ;ax=?
Mov ax, [array1] ;ax=?
Mov ax, [array1+2] ;ax=?
Mov al, [array2] ;ax=?
Mov al, [array2+1] ;ax=?
Mov ax, [array2] ;ax=?
mov ax, 0x4c00 ; termination statements
int 21h
; data
num1: dw 0A0Bh
num2: dd 0C0D0E0Dh
array1: dw 0102h , 0304h
array2: db 05h , 06h, 07h
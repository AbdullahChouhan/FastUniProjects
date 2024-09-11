[org 0x0050]

mov ax, [Num]

mov ax, 25h ; Part a
mov bx, 10h

mov cx, ax ; Part b
mov ax, bx
mov bx, cx

mov bx, 0x270 ; Part c
mov word [bx], 0x1234

mov bx, 5 ; Part d
l1: mov ax, [0x100 + bx]
add bx, 2
cmp bx, 0x13
jge l1

mov ax, 0x4c00
int 0x21

Num equ 0x0105
dw 12, 25, 38, 44, 105 ; part d
[org 0x0100]

mov ax, [before]
mov bx, 1010101010101010b
and ax, bx
shr ax, 1
mov dx, ax

mov ax, [before]
mov bx, 0101010101010101b
and ax, bx
shl ax, 1

or ax, dx
mov [after], ax

mov ax, 0x4c00
int 0x21

before: dw 1011001001011101b
after: dw 0
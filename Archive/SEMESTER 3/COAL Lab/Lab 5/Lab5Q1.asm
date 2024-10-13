[org 0x0100]

mov ax, [before]
mov bx, 0000111100001111b
and ax, bx
shl ax, 4
mov dx, ax

mov ax, [before]
mov bx, 1111000011110000b
and ax, bx
shr ax, 4

or ax, dx
mov [after], ax

mov ax, 0x4c00
int 0x21

before: dw 1011001001011101b
after: dw 0
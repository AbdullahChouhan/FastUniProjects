[org 0x0100]

mov cx, multiplier
mov di, 4
mov si, 8

mult:
    mov ax, [num + si]
    mov bx, ax
    add bx, ax
    adc dx, 0
    loop mult

mov [result + si], bx
sub si, 2
add [result + si], dx
mov cx, multiplier
dec dx
jnz mult

mov ax, 0x4c00
int 0x21

num: dd 0, 10000000h
multiplier: dd 00000010h
result: dd 0, 0
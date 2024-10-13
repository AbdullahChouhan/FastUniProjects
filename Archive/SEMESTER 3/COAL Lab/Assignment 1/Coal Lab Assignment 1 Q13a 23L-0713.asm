[org 0x0100]

mov ax, example1
mov bx, example2

cmp bx, 5
jl terminate

bxl5:
    add ax, bx

terminate:
    mov ax, 0x4c00
    int 0x21

example1: dw 3
example2: dw 5
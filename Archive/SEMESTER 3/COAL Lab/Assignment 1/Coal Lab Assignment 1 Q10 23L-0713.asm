[org 0x0100]

mov ch, 10
mov si, 0
mov dx, 0x8000

start:
    cmp ch, 0
    je end

    mov ax, [Array1 + si]

    add si, 2
    dec ch

    cmp ax, dx
    jg store

    jmp start

store:
    mov dx, ax
    jmp start


end:
    mov [Max], dx

mov ax, 0x4c00
int 0x21

Array1: dw 3, -5, 7, 4, -9, 2, 1, 0, 12, -16
Max: dw 0
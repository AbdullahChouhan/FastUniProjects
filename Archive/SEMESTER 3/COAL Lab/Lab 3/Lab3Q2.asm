[org 0x0100]

mov ax, 0

exit:
mov ax, 0x4c00
int 0x21

looplabel:
    inc ax
    cmp ax, 10
    jne looplabel
    jmp exit
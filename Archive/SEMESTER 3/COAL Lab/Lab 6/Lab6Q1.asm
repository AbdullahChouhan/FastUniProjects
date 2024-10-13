[org 0x0100]
jmp start

subtract:
    push bp
    mov bp, sp
    mov ax, [bp + 10]
    sub ax, [bp + 8]
    sub ax, [bp + 6]
    sub ax, [bp + 4]
    mov [bp + 12], ax
    pop bp
    ret 8

start:
    sub sp, 2
    push 0xA
    push 0x1
    push 0x2
    push 0x2
    call subtract
    pop ax

    sub sp, 2
    push 0x9
    push 0x1
    push 0x5
    push 0x0
    call subtract
    pop ax

    sub sp, 2
    push 0xF
    push 0x1
    push 0x8
    push 0x4
    call subtract
    pop ax

mov ax, 0x4c00
int 0x21
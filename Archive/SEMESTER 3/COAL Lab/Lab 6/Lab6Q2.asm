[org 0x0100]
jmp start

subtract:
    push bp
    mov bp, sp
    push ax
    mov ax, [bp + 10]
    sub ax, [bp + 8]
    sub ax, [bp + 6]
    sub ax, [bp + 4]
    mov [bp + 12], ax
    pop ax
    pop bp
    ret 8

AnotherFunction:
    push bp
    mov bp, sp
    push ax
    sub sp, 4
    push word [bp + 10]
    push word [bp + 8]
    push word [bp + 6]
    push word [bp + 4]
    call subtract
    pop ax
    push word [bp + 6]
    push word [bp + 4]
    push 0
    push 0
    call subtract
    pop bx
    add ax, bx
    mov [bp + 12], ax
    pop ax
    pop bp
    ret 8

start:
    sub sp, 2
    push 0xA
    push 0x1
    push 0x2
    push 0x2
    call AnotherFunction
    pop ax

    sub sp, 2
    push 0x9
    push 0x1
    push 0x5
    push 0x0
    call AnotherFunction
    pop ax

    sub sp, 2
    push 0xF
    push 0x1
    push 0x8
    push 0x4
    call AnotherFunction
    pop ax

mov ax, 0x4c00
int 0x21
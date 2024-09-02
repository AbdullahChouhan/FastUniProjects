[org 0x0100]

mov ax, 0
mov cx, 8
mov bx, fib
mov word [bx], 1
add bx, 2
mov word [bx], 1

l1: mov ax, [bx-2]
    add ax, [bx]
    add bx, 2
    mov [bx], ax
    dec cx
    jnz l1

mov ax, 0x4c00
int 0x21

fib: dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
[org 0x0100]

jmp start

sum:
    add cx, dx
    push cx
    pop ax
    ret

start:
    mov cx, [num1]
    mov dx, [num2]
    call sum

mov ax, 0x4c00
int 0x21

num1: dw 0x1234
num2: dw 0x5678
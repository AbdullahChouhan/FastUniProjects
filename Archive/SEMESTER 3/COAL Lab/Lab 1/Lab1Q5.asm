[org 0x0100]

mov ax, [num1]
mov bx, 4

dec bx
l1: add ax, [num1]
    dec bx
    jnz l1
    mov [mresult], ax

l2: inc bx
    sub ax, 3
    jnz l2
    mov [dresult], bx

mov ax, 0x4c00
int 0x21
    
num1: dw 6
mresult: dw 0
dresult: dw 0
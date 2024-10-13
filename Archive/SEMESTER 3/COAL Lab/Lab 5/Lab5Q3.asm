[org 0x0100]

mov ax, [before]
mov dx, 0
mov cx, 16
mov bx, 0

l1:
    shr ax, 1
    adc dx, 0
    loop l1

inc bx
mov cx, 16
mov ax, dx
mov dx, 0
cmp ax, 1
jne l1

mov [iterations], bx

mov ax, 0x4c00
int 0x21

before: dw 1100010110100011b
iterations: dw 0
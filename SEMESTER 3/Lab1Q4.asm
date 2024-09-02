[org 0x0100]

mov ax, [num1]
add ax, [num2]
add ax, [num3]
add ax, [num4]
add ax, [num5]
mov [result], ax

mov ax, 0x4c00
int 0x21

num1: dw 1
num2: dw 2
num3: dw 3
num4: dw 4
num5: dw 5
result: dw 0
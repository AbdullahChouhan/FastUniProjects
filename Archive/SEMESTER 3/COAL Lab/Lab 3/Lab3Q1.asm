[org 0x100]

mov ax, [num1]
mov bx, [num2]
cmp ax, bx
jg num1g
jmp else

exit:
mov ax, 0x4c00
int 0x21

num1g: inc word [num1]
jmp exit
else: dec word [num2]
jmp exit

num1: dw 1
num2: dw 2
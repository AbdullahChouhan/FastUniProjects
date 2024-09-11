[org 0x100]

mov ax, [x]
mov bx, [y]
mov cx, [Z]

cmp ax, bx
jg xgy
jmp xley

exit:
mov ax, 0x4c00
int 0x21

xgy:
    cmp ax, cx
    jle xlz
    xgz:
        sub ax, cx
        mov [result], ax
        jmp exit
    xlz:
        sub cx, ax
        mov [result], cx
        jmp exit
xley:
    cmp bx, cx
    jle ylez
    ygz:
        sub bx, cx
        mov [result], bx
        jmp exit
    ylez:
        sub cx, bx
        mov [result], cx
        jmp exit

x: dw 8
y: dw 15
Z: dw 20
result: dw 0
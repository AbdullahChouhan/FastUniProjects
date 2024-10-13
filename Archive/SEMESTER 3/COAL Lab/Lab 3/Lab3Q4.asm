[org 0x0100]

mov ax, [p]
mov bx, [q]
mov cx, [r]

cmp ax, bx
jl plq
jmp pgeq

exit:
mov ax, 0x4c00
int 0x21

plq:
    cmp ax, cx
    jge pger
    plr:
        mov [smallest], ax
        jmp exit
    pger:
        mov [smallest], cx
        jmp exit
pgeq:
    cmp bx, cx
    jge qger
    qlr:
        mov [smallest], bx
        jmp exit
    qger:
        mov [smallest], cx
        jmp exit

p: dw 0
q: dw 0
r: dw 0
smallest: dw 0
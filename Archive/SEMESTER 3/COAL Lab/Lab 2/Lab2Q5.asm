[org 0x0100]

mov ax, 200h
mov bx, 250h
mov word [200h], 25h
mov word [250h], 15h

mov ax, [bx - 50h] ; part a

mov cx, [250h] ; part b

mov [250h], ax ; part c
mov [200h], cx

mov cx, 0 ; part d
sortOut:
      mov si, 0
      mov bp, 0
      sortIn:
            mov ax, [bp + Num1]
            mov bx, [bp + Num1 + 2]
            cmp ax, bx
            jg swap
            add bp, 2
            cmp bp, 14
            sub bp, cx
            jl sortIn
            add cx, 2
            test si, 0
            je exit
            cmp cx, 14
            jl sortOut

exit:
mov ax, 0x4c00
int 0x21

swap:
      mov [bp + Num1], bx
      mov [bp + Num1 + 2], ax
      or si, 1
      jmp sortIn

Num1: db 2, 1, 0, 0, 1, 3, -1
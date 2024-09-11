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
sortOut: mov dl, 0
         mov cl, 0
         sortIn: mov ax, [cl + Num1]
                 mov bx, [cl + Num1 + 2]
                 cmp ax, bx
                 jg swap
                 add cl, 2
                 cmp cl, 14 - ch
                 jl sortIn
                 add ch, 2
                 cmp dl, 0
                 je exit
                 cmp ch, 14
                 jl sortOut

exit:
mov ax, 0x4c00
int 0x21

swap: mov [cl + Num1], bx
      mov [cl + Num1 + 2], ax
      mov dl, 1
      jmp sortIn

Num1: dw 2, 1, 0, 0, 1, 3, -1
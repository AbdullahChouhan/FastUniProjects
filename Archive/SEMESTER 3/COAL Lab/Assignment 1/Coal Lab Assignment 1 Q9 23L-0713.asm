[org 0x0100]

mov ch, 10
mov di, 0
mov si, 0

start:
    cmp ch, 0
    je end

    mov ax, [Array1 + si]
    mov bx, ax
    
    mov dx, 0
    mov cl, al
    
    cmp ax, 0
    je store
    
square:
    add dx, bx
    dec cl
    jnz square
    
store:
    mov [Array2 + di], dx
    
    add si, 2
    add di, 2
    
    dec ch
    jmp start

end:
mov ax, 0x4C00
int 0x21

Array1: dw 1, 5, 7, 4, 9, 2, 1, 0, 12, 16
Array2: dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
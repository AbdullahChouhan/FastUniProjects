[org 0x100]

jmp start

clrscr:
    pusha
    mov ax, 0xb800
    mov es, ax
    mov di, 0
nextloc:
    mov word [es:di], 0x0720
    add di, 2
    cmp di, 4000
    jne nextloc
    popa
    ret

printRect:
    push bp
    mov bp, sp
    pusha
    mov ax, 0xb800
    mov es, ax
    
    mov al, 80
    mul byte [bp + 10] ; TopLeftY
    add ax, [bp + 8] ; TopLeftX
    shl ax, 1
    mov di, ax

    mov al, 80
    mul byte [bp + 6] ; BottomRightY
    add ax, [bp + 4] ; BottomRightX
    shl ax, 1
    mov cx, ax
    mov bx, [bp + 10] ; TopLeftY
    mov bx, [bp + 8] ; TopLeftX
    mov si, [bp + 6] ; BottomRightY
    mov cx, [bp + 4] ; BottomRightX

    mov ax, 01110000b
nextchar:
    mov [es:di], ax
    add di, 2
    loop nextchar
    popa
    pop bp
    ret 8

start:
    call clrscr
    mov ax, message
    push ax
    push 2 ; TopLeftY
    push 10 ; TopLeftX
    push 20 ; BottomRightY
    push 60 ; BottomRightX
    call printRect

mov ax, 0x4c00
int 0x21

message: db "Hello"
real: dw 5
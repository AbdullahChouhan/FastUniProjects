[org 0x0100]
jmp start

start:
    xor ax, ax
    xor cx, cx
    mov ah, 3Ch
    lea dx, filename
    int 0x21

    mov bx, ax
    mov ah, 40h
    mov cx, strlen
    lea dx, string
    int 0x21

    mov al, bl
    mov ah, 3Eh
    int 0x21

    mov ax, 0x4c00
    int 0x21

filename db "RealTxt.txt", 0
string db "Hello World!", 0
strlen db $ - string
[org 0x0100]
xor di, di
jmp start

handleInput:
    mov byte [string + di], al
    inc di
    ret

start:
    mov ah, 0 ; service 0 – get keystroke
    int 0x16 ; call BIOS keyboard service
    cmp al, 13
    je exit
    call handleInput ; clear the screen
    jmp start

exit:
    mov byte [string + di], '$'
    mov dx, string
    mov ah, 0x09
    int 0x21

    xor ax, ax
    mov ax, 0x4c00 ; terminate program
    int 0x21

string db ""
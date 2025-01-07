; Infinite Key Printing
[org 0x0100]
jmp start
printNum:
    push ax
    pop bx ; bx=ax
    pusha

    mov ax, 0xb800
    mov es, ax ; point es to video base
    xor di, di ; point di to top left column
    mov ax, 0x0720 ; normal attribute
    mov cx, 2000 ; number of screen locations
    cld ; auto increment mode
    rep stosw ; clear the whole screen
    
    xor ax, ax
    mov al, bl ; load number in ax
    mov bx, 10 ; use base 10 for division
    xor cx, cx ; initialize count of digits
    nextdigit:
        mov dx, 0 ; zero upper half of dividend
        div bx ; divide by 10
        add dl, 0x30 ; convert digit into ascii value
        push dx ; save ascii value on stack
        inc cx ; increment count of values
        cmp ax, 0 ; is the quotient zero
        jnz nextdigit ; if no divide it again

    mov ax, cx
    xor di, di
    nextpos:
        pop dx ; remove a digit from the stack
        mov [string + di], dl ; append string
        inc di ; move to next position
        loop nextpos

    mov word [string + di], '$'
    
    xor si, si
    mov dx, string
    mov ah, 0x09
    int 0x21

    popa
    ret


start:
    mov ah, 0 ; service 0 – get keystroke
    int 0x16 ; call BIOS keyboard service
    cmp al, 0x1b
    je exit
    call printNum ; clear the screen
    jmp start

exit:
    xor ax, ax
    mov ax, 0x4c00 ; terminate program
    int 0x21

string db ""
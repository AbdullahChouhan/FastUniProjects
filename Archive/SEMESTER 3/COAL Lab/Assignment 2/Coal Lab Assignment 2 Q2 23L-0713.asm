[org 0x0100]

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

printnum:
    push bp
    mov bp, sp
    push es
    push ax
    push bx
    push cx
    push dx

    mov ax, 0xb800
    mov es, ax ; point es to video base
    mov ax, [bp + 4] ; load number in ax
    mov bx, 10 ; use base 10 for division
    mov cx, 0 ; initialize count of digits

    nextdigit:
        mov dx, 0
        div bx
        add dl, 0x30
        push dx
        inc cx
        cmp ax, 0
        jnz nextdigit
        sub di, cx
        sub di, cx
    nextpos:
        pop dx
        mov dh, 0x07
        mov [es:di], dx
        add di, 2
        loop nextpos

    pop dx
    pop cx
    pop bx
    pop ax
    pop es
    pop bp
    ret 2


printNumbers:
    push bp
    mov bp, sp
    pusha

    mov cx, [bp + 4]
    mov si, cx
    shl si, 1
    mov di, 6
    
    printer:
        mov ax, [bp + si + 4]
        push ax
        sub si, 2
        call printnum
        add di, 160
        loop printer

    pop bp
    popa
    ret 8

start:
    call clrscr
    push 134
    push 189
    push 156
    push 3
    call printNumbers


mov ax, 0x4c00
int 0x21
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

printRect:
    push bp
    mov bp, sp
    pusha

    mov ax, 0xb800
    mov es, ax

    mov al, 160
    mul byte [bp + 10]
    add ax, [bp + 8]
    mov cx, [bp + 4]
    sub cx, [bp + 8]
    mov di, ax

    topLine:
        mov word [es:di], 0x4400
        add di, 2
        loop topLine
        mov cx, [bp + 6]
        sub cx, [bp + 10]

    rightLine:
        mov word[es:di], 0x4400
        add di, 160
        loop rightLine
        mov cx, [bp + 4]
        sub cx, [bp + 8]

    bottomLine:
        mov word[es:di], 0x4400
        sub di, 2
        loop bottomLine
        mov cx, [bp + 6]
        sub cx, [bp + 10]

    leftLine:
        mov word [es:di], 0x4400
        sub di, 160
        loop leftLine

    popa
    pop bp
    ret

start:
    call clrscr
    push word [topleftX] ; bp + 10
    push word [topleftY] ; bp + 8
    push word [bottomrightX] ; bp + 6
    push word [bottomrightY] ; bp + 4
    call printRect

end:
    mov ax, 0x4C00
    int 0x21

topleftX: dw 2 
topleftY: dw 10
bottomrightX: dw 20
bottomrightY: dw 60
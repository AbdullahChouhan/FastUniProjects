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

asteriskTravel:
    push bp
    mov bp, sp
    pusha

    mov ax,0xb800
    mov es,ax

    asteriskInit:
        mov al, 160
        mul byte [bp + 10]
        add ax, [bp + 8]
        mov cx, [bp + 4]
        sub cx, [bp + 8]
        mov di, ax

    asteriskTopLine:
        mov word[es:di], 0x472A
        call sleep
        mov word[es:di], 0x4400
        add di,2
        loop asteriskTopLine
        mov cx,[bp+6]
        sub cx,[bp+10]

    asteriskRightLine:
        mov word[es:di], 0x472A
        call sleep
        mov word[es:di], 0x4400
        add di,160
        loop asteriskRightLine
        mov cx,[bp+4]
        sub cx,[bp+8]

    asteriskBottomLine:
        mov word[es:di], 0x472A
        call sleep
        mov word[es:di], 0x4400
        sub di,2
        loop asteriskBottomLine
        mov cx,[bp+6]
        sub cx,[bp+10]

    asteriskLeftLine:
        mov word[es:di], 0x472A
        call sleep
        mov word[es:di], 0x4400
        sub di,160
        loop asteriskLeftLine
        jmp asteriskInit

    popa
    pop bp
    ret 8

sleep:
    push cx

    mov cx, 0xFFFF
    delay1:
        loop delay1
    mov cx, 0xFFFF
    delay2:
        loop delay2

    pop cx
    ret



start:
    call clrscr
    push word [topleftX] ; bp + 10
    push word [topleftY] ; bp + 8
    push word [bottomrightX] ; bp + 6
    push word [bottomrightY] ; bp + 4
    call printRect
    call asteriskTravel

    mov ax, 0x4C00
    int 0x21

topleftX: dw 2 
topleftY: dw 10
bottomrightX: dw 20
bottomrightY: dw 60
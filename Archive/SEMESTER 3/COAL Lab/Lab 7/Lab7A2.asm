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

    mov dx, 0
    topLine:
        call sleep
        mov word [es:di], 0x4400
        add di, 2
        loop topLine

    mov cx, [bp + 6]
    sub cx, [bp + 10]
    rightLine:
        call sleep
        mov word[es:di], 0x4400
        add di, 160
        loop rightLine

    mov cx, [bp + 4]
    sub cx, [bp + 8]
    bottomLine:
        call sleep
        mov word[es:di], 0x4400
        sub di, 2
        loop bottomLine

    mov cx, [bp + 6]
    sub cx, [bp + 10]
    leftLine:
        call sleep
        mov word [es:di], 0x4400
        sub di, 160
        loop leftLine

    popa
    pop bp
    ret 8

sleep:
    push cx
    cmp dx, 0
    jne skip

    mov cx, 0xFFFF
    delay1:
        loop delay1
    mov cx, 0xFFFF
    delay2:
        loop delay2
    mov cx, 0xFFFF
    delay3:
        loop delay3
    mov cx, 0xFFFF
    delay4:
        loop delay4
        
    skip:
    not dx
    pop cx
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
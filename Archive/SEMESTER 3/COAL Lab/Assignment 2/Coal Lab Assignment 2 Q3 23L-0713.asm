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

cycler:
    mov ax, 0xb800
    mov es, ax ; point es to video base
    mov ds, ax

    mov word [es:2000 - 80], 0x0743
    mov word [es:2158 - 80], 0x0744

    mov ax, 2000 - 80
    mov bx, 2158 - 80
    mov cx, 2

    looper:
        call sleep
        mov si, ax
        mov di, si
        add di, cx
        movsw
        sub si, cx
        mov word [es:si], 0x0720
        mov si, bx
        mov di, si
        sub di, cx
        movsw
        sub si, cx
        mov word [es:si], 0x0720
        add ax, cx
        sub bx, cx
        cmp cx, 2
        jne real
            cmp ax, 2000 - 80 + 78
            jge next
            jmp looper
            next:
                std
                mov cx, -2
                jmp looper
        real:
            cmp ax, 2000 - 80
            jle next2
            jmp looper
            next2:
                cld
                mov ax, 2000 - 80
                mov bx, 2158 - 80
                mov cx, 2
                jmp looper


sleep:
    push cx
    push dx

    mov dx, 0x003
    delay:
        mov cx, 0xFFFF
        delay1:
            loop delay1
    dec dx
    jnz delay

    pop dx
    pop cx
    ret

start:
    call clrscr
    call cycler


mov ax, 0x4c00
int 0x21
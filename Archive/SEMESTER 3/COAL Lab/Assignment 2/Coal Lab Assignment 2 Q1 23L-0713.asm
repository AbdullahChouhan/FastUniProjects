[org 0x0100]
jmp start

sort:
    push bp
    mov bp, sp
    sub sp, 2
    pusha

    mov bx, [bp + 6]
    mov si, [bp + 4]
    mov cx, [si]
    add cx, cx
    sub cx, 2

    sortOut:
        mov si, 0
        mov word [bp - 2], 0
        SortIn:
            mov ax, [bx + si]
            cmp ax, [bx + si + 2]
            jbe noswap
            xchg ax, [bx + si + 2]
            mov [bx + si], ax
            mov word [bp - 2], 1
        noswap:
            add si, 2
            cmp si, cx
            jne SortIn
            cmp word [bp - 2], 1
            je sortOut

    popa
    add sp, 2
    pop bp
    ret   

statsOfArray:
    ; preparations
    push bp
    mov bp, sp
    pusha
    ; post preparations
    
    mov bx, [bp + 12] ; address
    mov si, [bp + 10] ; size
    mov ax, [si]
    ; bp - 2 = min
    ; bp - 4 = max
    ; bp - 6 = med

    ; check if odd
    mov cx, 2
    div cx
    mov si, ax
    mov ax, [bx + si]
    cmp dx, 0
    jne odd
    even:
        add ax, [bx + si + 2]
        div cx
    
    odd:
    mov [bp + 8], ax ; med

    mov si, [bp + 10]
    mov si, [si]
    add si, si
    sub si, 2

    mov ax, [bx]
    mov [bp + 4], ax ; min

    mov ax, [bx + si]
    mov [bp + 6], ax ; max

    ; cleanup
    popa
    pop bp
    ; post cleanup

    ret

start:
    push array1 ; address of array1
    push lenArray1 ; size of array1
    call sort
    sub sp, 6
    call statsOfArray
    pop ax
    pop bx
    pop cx

mov ax, 0x4c00
int 0x21
array1: dw 3, 4, 8, 6
lenArray1: dw 4

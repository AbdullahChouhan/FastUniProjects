[org 0x0100]
jmp start

rotate:

    ; preparations
    push bp
    mov bp, sp
    sub sp, 2 ; 1 localvar
    pusha
    ; post preparations
    
    mov bx, [bp + 10] ; address
    mov si, [bp + 8] ; size
    mov ch, [bp + 6] ; dir
    mov cl, [bp + 4] ; rotations
    sub si, 2
    begin:
    mov word [bp - 2], 0 ; localvariable: ending flag
    mov di, 0
    cmp ch, 0
    jne rotatorprime
    mov di, si
    rotatorprime:
        mov dx, [di + bx]
    rotator:
        mov ax, dx
        cmp ch, 0
        je left
        jmp right
        left:
            sub di, 2
            cmp di, 0
            jnl store
            mov di, si
            mov word [bp - 2], 1
            jmp store
        right:
            add di, 2
            cmp di, si
            jle store
            mov di, 0
            mov word [bp - 2], 1
    store:
        mov dx, [di + bx]
        mov [di + bx], ax
        cmp word [bp - 2], 0
        je rotator
        dec cl
        cmp cl, 0
        jne begin

    ; cleanup
    popa
    add sp, 2
    pop bp
    ; post cleanup

    ret 8

start:
    push before ; address of array
    push 8 ; size
    push 0 ; direction: 0 for left, 1 for right
    push 2 ; rotations
    call rotate

mov ax, 0x4c00
int 0x21

before: dw 1, 2, 3, 4
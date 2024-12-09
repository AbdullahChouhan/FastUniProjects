[org 0x0100]
jmp start
String: db "I am a student of COAL", 0
Substring: db "student", 0

clrscr:
    pusha
    mov ax, 0xb800
    mov es, ax
    mov di, 0
    mov cx, 2000
    mov ax, 0x0720
    cld
    rep stosw
    popa
    ret

Highlight:
    push bp
    mov bp, sp
    pusha

    push ds
    pop es

    mov di, [bp + 4]
    mov cx, 0xffff
    xor al, al
    repne scasb
    inc cx
    not cx
    mov bx, cx ;length of substring

    mov di, [bp + 6]
    mov cx, 0xffff
    xor al, al
    repne scasb
    inc cx
    not cx
    mov dx, cx ;length of string

    mov di, [bp + 6] ;string
    try:
    mov si, [bp + 4] ;substring
    lodsb
    dec si
    mov cx, 0xffff
    repne scasb
    dec di
    mov cx, 0xffff
    repe cmpsb
    inc cx
    not cx
    cmp bx, cx
    je found
    sub di, 2
    sub di, [bp + 6]
    cmp di, dx
    jge notfound
    jmp try

    found:
        mov ax, 0xb800
        mov es, ax
        mov ah, 0x07
        mov cx, di
        mov di, 0
        dec cx
        sub cx, bx
        sub cx, [bp + 6]
        mov si, [bp + 6]
        loopA:
            lodsb
            stosw
            loop loopA
        mov cx, bx
        mov ah, 0x17
        loopB:
            lodsb
            stosw
            loop loopB
        mov cx, [bp + 6]
        add cx, dx
        sub cx, si
        mov ah, 0x07
        loopC:
            lodsb
            stosw
            loop loopC
    jmp exit
    notfound:
        mov ax, 0xb800
        mov es, ax
        mov ah, 0x07
        mov di, 0
        mov cx, dx
        loopD:
            lodsb
            stosw
            loop loopD
    exit:
    popa
    pop bp
    ret 4

start:
    call clrscr
    push String
    push Substring
    call Highlight

mov ax, 0x4c00
int 0x21
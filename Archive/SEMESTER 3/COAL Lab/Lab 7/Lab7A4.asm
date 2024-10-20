[org 0x0100]

mov ax, 0xb800
mov es, ax
mov ds, ax

mov cx, 12 * 160 / 2
mov si, 0
mov di, 1920

cld
rep movsw

mov ax, 0x4c00
int 0x21

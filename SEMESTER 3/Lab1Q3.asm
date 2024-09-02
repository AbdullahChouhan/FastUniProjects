[org 0x0100]

mov ax, [0025h]
mov [0FFFh], ax
mov ax, [0010h]
mov [002fh], ax

mov ax, 0x4c00
int 0x21
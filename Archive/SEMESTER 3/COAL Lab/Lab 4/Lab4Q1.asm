[org 0x0100]

mov bx, 1011000110001001b
mov cx, 16
mov dx, 0

shift:
    rcr bx, 1
    adc dx, 0
    loop shift

mov [numOneBits], dx

mov ax, 1010101110100101b
xor ax, 0000000001111111b

mov [complementedAX], ax

end:
    mov ax, 0x4c00
    int 0x21

numOneBits: dw 0
complementedAX: dw 0
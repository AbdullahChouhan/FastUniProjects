[org 0x0100]

mov ax, [before]
mov cx, 4
mov bl, al
shl ax, 8
firstHalf:
    shl ax, 1
    rcl bl, 1
    loop firstHalf
mov dl, bl

mov ax, [before]
mov cx, 4
mov bh, ah
shr ax, 8
secondHalf:
    shr ah, 1
    rcr bh, 1
    loop secondHalf
mov dh, bh

mov [after], dx

mov ax, 0x4c00
int 0x21

before: dw 1011001001011101b
after: dw 0
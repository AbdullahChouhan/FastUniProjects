[org 0x0100]

mov ax, [num]
mov bx, [num + 2]
mov cx, [num + 4]
mov dx, [num + 6]

shl ax, 1
rcl dx, 1
rcl cx, 1
rcl bx, 1

mov [num], ax
mov [num + 2], bx
mov [num + 4], cx
mov [num + 6], dx

mov ax, 0x4c00
int 0x21

num: dd 100, 200
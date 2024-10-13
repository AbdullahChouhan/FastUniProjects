[org 0x0100]

mov ax, [firstHalf + 4]
mov bx, [secondHalf + 4]
add ax, bx
mov [result + 4], ax

mov ax, [firstHalf]
mov bx, [secondHalf]
adc ax, bx
mov [result], ax

mov ax, 0x4c00
int 0x21

firstHalf: dd 100, 100
secondHalf: dd 200, 200
result: dd 0, 0
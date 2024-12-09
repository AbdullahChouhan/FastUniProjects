; this file gives the defination of random number generator function
; and a prototype for calling this function
[org 0x0100]

jmp start
clrscr: 
	 pusha
	 pushf
	 mov ax, 0xb800
	 mov es, ax ; point es to video base
	 xor di, di ; point di to top left column
	 mov ax, 0x1620 ; space char in normal attribute
	 mov cx, 2000 ; number of screen locations
	 cld ; auto increment mode
	 rep stosw ; clear the whole screen
	 popf
	 popa
	 ret 

delay:
	pusha
	pushf

	mov cx,1000
	mydelay:
	mov bx,1000      ;; increase this number if you want to add more delay, and decrease this number if you want to reduce delay.
	mydelay1:
	dec bx
	jnz mydelay1
	loop mydelay

	popf
	popa
ret	 

; a function to generate random number between 0 and n
; input: n, can be accessed using bp+4
; output: random number can be accessed in function using bp+6
RANDNUM:
   push bp
   mov bp,sp
   pusha
   
   MOV AH, 00h  ; interrupts to get system time        
   INT 1AH      ; CX:DX now hold number of clock ticks since midnight      
   mov  ax, dx
   mov bx, 0xFFF1
   mul bx
   xor  dx, dx
   mov  cx, [bp+4]
   inc cx
   div  cx       ; here dx contains the remainder of the division - from 0 to 9
   mov [bp+6], dx
   popa
   pop bp
   ret 2

printRandom:
	push es
	push cx
	push di
	push ax
	push 0xb800
	pop es
	mov cx, 10
	mov di, 0
	l1:	
		mov ah, 0 ; wait for key stroke
        Int 16h; 

		sub sp,2 ; make space for output
		push 9; maximum value of random number
		call RANDNUM  
		pop ax ;
		mov ah, 07h
		add al, 30h
		stosw
		loop l1
		
	pop	ax
	pop di
	pop cx
	pop es
	ret	

;take first 10 digits of screen and move them to a random place on screen at every key stroke (rest of the screen should be cleared)
;if esc key is pressed return from this function 
movRandomly:
	pusha
	push 0xb800
	pop es
	push 0xb800
	pop ds
	mov si, 0
	mov bx, 2
	l2:
		cld

		mov ah, 0
		int 16h
		cmp ah, 1
		je exit

		mov cx, 10
		mov di, 5000
		rep movsw
		call clrscr
		mov si, di
		sub si, 20

		sub sp, 2
		push (2000 - 10)
		call RANDNUM
		pop ax
		mul bx
		mov di, ax

		mov cx, 10
		rep movsw
		
		mov si, di
		sub si, 20
		jmp l2
	exit:
		popa
		ret

   
start:

	call clrscr
	call printRandom
	call movRandomly ; you have to write the body of this function 

  

mov ax, 0x4c00 ; terminate program
int 21h
 

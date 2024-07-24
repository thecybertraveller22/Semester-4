.dosseg
.model small
.stack 100h

.data

	arr db 5 dup(?)
	var1 db 10,13, 'Enter 4 numbers $'
	var2 db 10,13, 'Sorted array $'
.code
main proc
	mov ax,@data
	mov ds,ax

	;print add here
	mov dx,offset var1
	mov ah,9
	int 21h

	mov cx,4
	mov bx,offset arr
	mov ah,1

	inputloop:
		int 21h
		mov [bx],al
		inc bx
		loop inputloop
	
	mov cx,4
	dec cx

	outerloop:
		mov bx,cx
		mov si,0

	compareloop:
		mov al,arr[si]
		mov dl,arr[si+1]
		cmp al,dl

		;jnc dontswap  ; just toggle these lines for ascending and descending
		jc dontswap ; this is for asending

			mov arr[si],dl
			mov arr[si+1],al
		
		dontswap:
			inc si
			dec bx
			jnz compareloop

			loop outerloop

	mov ah,2
	mov dl,10
	int 21h
	mov dl,13
	int 21h

	;print sorted

	mov dx,offset var2
	mov ah,9
	int 21h

	mov cx,4
	mov bx,offset arr

	output:
		mov dl,[bx]
		mov ah,2
		int 21h
		
		mov dl,32
		mov ah,2
		int 21h

		inc bx
		loop output

	mov ah,4ch
	int 21h
main endp
end main

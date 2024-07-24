dosseg
.model small
.stack 100h
.data
	num db ?
	str1 db 10,13,'Enter a number to find its factors $'
	str2 db 10,13,'The factors are $'
	arr1 db 1 dup (?)
	arr2 db 10 dup (?)
.code

factorial proc

	mov si,offset arr2
	mov bx,offset arr1

	mov cx,10

	l1:
		mov ah,0
		mov al,[bx]
		mov dx,cx
		div dl

		cmp ah,0
		inc bx
		je here

	
		mov [si],al


		mov dx,offset str2
		mov ah,09h
		int 21h

		

		mov dl,[si]
		push dx
		pop dx
		AAM

		;AAM

		mov num,al
		mov dl,ah
		add dl,30h
		mov ah,2
		int 21h
		mov dl,num
		add dl,30h
		mov ah,2
		int 21h
		;inc si
		
		here:
		
	loop l1




	ret
factorial endp

main proc
	mov ax,@data
	mov ds,ax
	mov si,offset arr1
	mov dx,offset str1
	mov ax,0
	mov ah,9
	int 21h
	;take the price of the product
	mov ah,1
	int 21h
    sub al,30h
	mov dl,al
	mov ah,1
	int 21h
    sub al,30h
	mov dh,al
	mov al,dl
	mov dl,10
	mul dl
	add al,dh
	mov [si],al
	

	; outputiing the number here
	MOV dl, 10
	MOV ah, 02h
	INT 21h
	MOV dl, 13
	MOV ah, 02h
	INT 21h


	mov al,[si]
	AAM
	mov bl,al
	mov ch,ah


	mov dl,ch
	add dl,30h
	mov ah,2
	int 21h

	mov dl,bl
	add dl,30h
	mov ah,2
	int 21h

	; calculating the factors

	call factorial





mov ah,4ch
int 21h

main endp
end main
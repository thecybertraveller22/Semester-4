dosseg
.model small
.stack 100h
.data

	arr db 1,2,1,5,8,7,3,1
	;arr db 8 Dup(?)
	str5 db 10,13,'Enter 8 numbers $'
	str1 db 10,13,'Sum is $'
	str2 db 10,13,'Product is $'
	str3 db 10,13,'Division is $'
	str4 db 10,13,'Subtraction is $'
	q db ?
	r db ?
.code

main proc
	

	mov ax,@data
	mov ds,ax

	;mov dx,offset str5
	;mov ah,09h
	;int 21h
	;mov cx,8
	;mov si, offset arr
	
	;input:
		;mov ah,01h
		;int 21h

		;mov [si],al
		;inc si

	;loop input

	;MOV dl, 10
	;MOV ah, 02h
	;INT 21h
	;MOV dl, 13
	;MOV ah, 02h
	;INT 21h

	;mov cx,8
	;mov si, offset arr

	;output:
	;	mov dl,[si]
	;	mov ah,02h
	;	int 21h
	;
		;inc si

	;loop output

	;; addition below

	mov dx,offset str1
	mov ah,09h
	int 21h

	mov si,offset arr

	mov al,[si]

	inc si

	add al,[si]

	mov dl,al
	add dl,30h
	mov ah,02h
	int 21h
	
	;; multiplication below
	
	mov dx,offset str2
	mov ah,09h
	int 21h

	inc si

	mov bl,[si]
	inc si
	mov al,[si]

	mul bl


	mov dl,al
	add dl,30h
	mov ah,02h
	int 21h

	;; subtraction below


	mov dx,offset str4
	mov ah,09h
	int 21h

	inc si

	mov al,[si]
	inc si

	sub al,[si]

	mov dl,al
	add dl,30h
	mov ah,02h
	int 21h

	;; division below

	mov dx,offset str3
	mov ah,09h
	int 21h

	inc si

	mov al,[si]
	inc si
	mov bl,[si]
	xor ah,ah
	div bl

	mov q,al
	mov r,ah

	mov dl,q
	add dl,30h
	mov ah,02h
	int 21h

	mov ah,4ch
	int 21h
main endp
end main
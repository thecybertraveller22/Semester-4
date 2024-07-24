; this program takes 2 numbers and subtracts them
.model small
.stack 100h
.data
.code

main proc

	mov ah,1
	int 21h

	mov bl,al

	mov al,1;
	int 21h

	sub bl,al
	
	add bl,48

	mov dl,bl

	mov ah,2
	int 21h

	mov ah,4ch
	int 21h



	main endp

end main
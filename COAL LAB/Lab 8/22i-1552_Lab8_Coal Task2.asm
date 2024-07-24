dosseg
.model small
.stack 100h
.data
	str1 db 10,13,'Enter a number to find its fib series $'
	num db ?
	str2 db 10,13,'The answer is $'
	num2 db ?
.code

fib proc

	mov al,1
	mov bl,1

	mov cl,5

	l1:
		add al,bl	;1+1=2
		mov dl,al	
		mov al,bl
		mov bl,dl
	loop l1

	;sub bl,1

	mov num2,bl

	mov dl,num2
	add dl,30h
	mov ah,02h
	int 21h


	ret
fib endp


main proc

	mov ax,@data
	mov ds,ax

	;mov dx,offset str1
	;mov ah,09h
	;int 21h


	;mov ah,01h
	;int 21h
	;mov num,al
	call fib
	;*****************


	mov ah,4ch
	int 21h

main endp
end main
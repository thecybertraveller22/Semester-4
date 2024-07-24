dosseg
.model small
.stack 100h
.data

	a db ?
	b db ?
	cc db ?
	d db ?
	e db ?
	f db ?
	g db ?

	str1 db 10,13,'Enter values of abcdefg $'
	str2 db 10,13,'First Condition approved $'
	str3 db 10,13,'Second Condition approved $'
	str4 db 10,13,'Third Condition approved $'
	str5 db 10,13,'The value of A is $'

.code

main proc
	

	mov ax,@data
	mov ds,ax
	
	mov dx,offset str1
	mov ah,09h
	int 21h

	mov ah,1
	int 21h

	mov a,al

	mov ah,1
	int 21h


	mov b,al

	mov ah,1
	int 21h

	mov cc,al

	mov ah,1
	int 21h

	mov d,al

	mov ah,1
	int 21h

	mov e,al

	mov ah,1
	int 21h

	mov f,al
	
	mov ah,1
	int 21h

	mov g,al

	cmp al,f
	je print

	mov al,e
	cmp al,d
	jne print
	jmp exitprogram


	

	print:
		mov al,g
		cmp al,d
		je print2

		mov al,f
		cmp al,e
		jle print2
		jmp exitprogram
	print2:
		mov dx,offset str2
		mov ah,09h
		int 21h
		mov al,a
		cmp al,g
		jg print3
		jmp exitprogram
	print3:
		mov al,b
		cmp al,e
		jle print4
		jmp exitprogram
	print4:
		mov dx,offset str3
		mov ah,09h
		int 21h
		
		mov al,cc
		cmp al,a
		jg print5
		jmp exitprogram
	print5:
		mov al,e
		cmp al,cc
		jge print6
		jmp exitprogram
	print6:
		mov dx,offset str4
		mov ah,09h
		int 21h

		mov dx,offset str5
		mov ah,09h
		int 21h

		mov al,a
		mov dl,al
		mov ah,02h
		int 21h
		jmp exitprogram

	
	exitprogram:
		mov ah,4ch
		int 21h
main endp
end main
dosseg
.model small
.stack 100h
.data
	var1 db 10,13,'even number..$'
	var2 db 10,13,'odd number..$'
.code
	main proc

		mov ax,@data
		mov ds,ax

		mov ah,1
		int 21h
		mov bl,2

		div bl
		cmp ah,0 ;this si the remainder cehck wether it os 0 or not
		je l1 ;then jump to l1
		mov dx,offset var2 ;else print odd number
		mov ah,9
		int 21h
		jmp exit ;exit 
		
		l1:

		mov dx,offset var1
		mov ah,9
		int 21h
		exit:

		mov ah,4ch 
		int 21h


	main endp
end main
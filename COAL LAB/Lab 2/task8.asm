;program to input two numbers and add them
.model small
.stack 100h
.data
.code

Main Proc
	Mov ah,1	;take user input
	Int 21h  
	mov bl,al

	Mov al,1	;task user input
	int 21h

	add bl,al	;add the numbers in the register

	sub bl,48

	mov dl,bl

	mov ah,2
	int 21h

	Mov ah,4ch
	Int 21h
	Main endp
End Main

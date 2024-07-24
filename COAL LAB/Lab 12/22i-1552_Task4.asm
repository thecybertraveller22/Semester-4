.model small
.stack 100h
.data
	x dw 100
	y dw 120
	temp dw ?
.code
main proc
	mov ax,@data
	mov ds,ax
	mov ah,0
	mov al,6
	int 10h
	
	mov cx,100
	
	horizontal_line:
		
		mov temp,cx
		mov ah,0ch
		mov al,0Dh
		mov cx,x
		mov dx,y
		inc x
		int 10h
		mov cx,temp
	
	loop horizontal_line

		mov cx,50

	left_line:
		
		mov temp,cx
		mov ah,0ch
		mov al,0Dh 
		mov cx,x
		mov dx,y
		dec x
		dec y    ; we decrement here intead of increment as dec causes moveing upwards while inc cause y to move downwards , kind of like oppoiste
		int 10h
		mov cx,temp
		
	loop left_line

		mov cx,50

	rightline:
	
		mov temp,cx
		mov ah,0ch
		mov al,0Dh 
		mov cx,x
		mov dx,y
		dec x
		inc y
		int 10h
		mov cx,temp
		
	loop rightline


	mov ah, 4ch
	int 21h
main endp
end main
.model small
.stack 100h
.data
	x dw 50
	y dw 50
	r dw 10

	center_y dw 100
	center_x dw 100

	rightSide dw ?
	leftSide dw ?

	x_m dw ?
	y_m dw ?


.code
main proc
	mov ax,@data
	mov ds,ax
	mov ah,0h 
	mov al,6h
	int 10h
	
	mov cx,360


	;(x-r)^2 + (y-r)^2 <= r^2

	l1:
		push cx
		
		mov ax,r
		mov bx,r
		mul bx
		mov rightSide,ax

		mov ax,x
		sub ax,r

		mov bx,ax
		mul bx
		mov x_m,ax


		mov ax,y
		sub ax,r

		mov bx,ax
		mul bx
		mov y_m,ax

		mov ax,x_m
		add ax,y_m

		mov leftSide,ax

		mov ax,leftSide

		cmp ax,rightSide

		jle here

		jmp overhere

		here:
			mov ah,0ch
			mov al,0fh
			mov cx,x
			mov dx,y
			inc x
			int 10h

		overhere:
			inc x
			inc y
			pop cx

	loop l1

	mov ah,4ch
	int 21h
main endp
end main
dosseg
.model small
.stack 100h
.data

	input db 10,13,'Enter the price in two digit number = $'
	sum_msg db 10,13,'Your Total Bill is = $'
	left db 0
	right db 0
	carryleft db 0
	arr db 5 dup(?)

.code

main proc

	mov ax, @data
	mov ds, ax

	mov cx,5
	mov si,offset arr
	
	l1:
		mov dx,offset input  ; taiing input mesage
		mov ah,9
		int 21h

		mov ah,1
		int 21h

		sub al,48
		mov bh ,al

		mov ah,1
		int 21h
		sub al,48
		mov bl,al     ; bh and bl is the first number
		

	

		add left,bh
		
		add right,bl
		

		
			 ; If the sum exceeds 9, adjust the values
		cmp right, 10
		jb no_overflow
		add left, 1
		sub right, 10
	no_overflow:

		; Move to the next element in the array
		inc si


	cmp left,10
	jb no_overflow2
	add carryleft,1
	sub left,10

	no_overflow2:
		inc si


		
		

		loop l1



		
		
		mov dx,offset sum_msg
		mov ah,09h
		int 21h


		
  
	
		mov ah, 2
		mov dl,10
		int 21h
		mov dl, 13
		int 21h


		mov dl,carryleft
		add dl,48
		mov ah,02h
		int 21h

	
		
		mov dl,left
		add dl,48
		mov ah,02h
		int 21h


		
		mov dl,right
		add dl,48
		mov ah,02h
		int 21h


	



	






	
	no_carry:




		

	

	
	
	

	mov ah, 4ch
	int 21h

main endp

end main
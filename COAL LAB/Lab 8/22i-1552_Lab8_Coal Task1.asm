dosseg
.model small
.stack 100h
.data
	arr db '5','2','3','4','5','5'
	str1 db 10,13,'Enter a number to find $'
	num db ?
	num1 db ?
	str2 db 10,13,'Found $'
	str3 db 10,13,'Not Found $'
	str4 db 10,13,'Back in main $'
	str5 db 10,13,'Enter number to find its count $'
	count1 db ?
	str6 db 10,13,'The number of times this number is repeated is = $'
	str7 db 10,13,'Now finding the largest number in the array $'
	max1 db 0
	str8 db 10,13,'The max number is = $'
	str9 db 10,13,'Now finding the minimum number in the array $'
	min1 db 9
	str10 db 10,13,'The minimum number is = $'
.code

find proc

	mov si,offset arr

	mov cx,6
	mov al,num
	;mov dl,al
	;add dl,30h
	;mov ah,02h
	;int 21h
	l1:

		cmp al,[si]
		je found

		inc si

	loop l1
	
	notfound:
		mov dx,offset str3
		mov ah,09h
		int 21h
		jmp f2

	found:
		mov dx,offset str2
		mov ah,09h
		int 21h

	f2:
		mov dx,offset str4
		mov ah,09h
		int 21h

	ret
find endp

count proc
	mov si,offset arr
	mov bl,0
	mov cx,6
	;mov num1,al
	;mov dl,al
	;add dl,30h
	;mov ah,02h
	;int 21h
	l1:
		cmp al,[si]
		je here

		notcount:
			jmp e

		here:
			inc bl

		
		e:


		inc si 

	loop l1
	
	mov count1,bl
	mov dx,offset str6
	mov ah,09h
	int 21h

	mov dl,count1
	add dl,30h
	mov ah,02h
	int 21h

	ret
count endp

maxnum proc
	

	mov si,offset arr
	mov cx,6
	
	l1:
		mov al,max1
		cmp [si],al
		jg here

		jmp e

		here:
			mov al,[si]
			mov max1,al

		e:


		inc si
	loop l1
	
	mov dx,offset str8
	mov ah,09h
	int 21h

	mov dl,max1
	;add dl,30h
	mov ah,02h
	int 21h

	ret
maxnum endp


minnum proc
	mov si,offset arr
	mov cx,6
	
	l1:
		mov al,max1
		cmp [si],al
		jl here

		jmp e

		here:
			mov al,[si]
			mov max1,al

		e:


		inc si
	loop l1
	
	mov dx,offset str10
	mov ah,09h
	int 21h

	mov dl,max1
	;add dl,30h
	mov ah,02h
	int 21h
	
	ret
minnum endp

main proc

	mov ax,@data
	mov ds,ax



	mov dx,offset str1
	mov ah,09h
	int 21h


	mov ah,01h
	int 21h

	mov num,al

	call find



	mov dx,offset str5
	mov ah,09h
	int 21h


	mov ah,01h
	int 21h

	mov num1,al
	call count
	


	mov dx,offset str7
	mov ah,09h
	int 21h

	call maxnum


	mov dx,offset str9
	mov ah,09h
	int 21h

	call minnum
	;***********************************
	mov ah,4ch
	int 21h
main endp
end main
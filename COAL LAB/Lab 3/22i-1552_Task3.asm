dosseg
.model small
.stack 100h
.data

	var1 db 5
	var2 db 4 

.code

	
main proc
	
	
	mov ax, @data
	mov ds,ax
    mov al, var1
	mov bl, var2
	
	mul bl
	AAM

	mov ch,ah
	mov cl,al

    mov dl,ch
	add dl,48
	mov ah,2
	int 21h
    
    mov dl,cl
	add dl,48
	mov ah,2
   	int 21h


	mov ah,4ch
	int 21h

main endp
end main

dosseg

.model small

.stack 100h

.data
array db 0,1,2,3,4,5,6,7,8,9
result db 10 Dup(?) 

.code

main proc
    mov ax, @data
    mov ds, ax

    mov si, offset array 
    mov di, offset result 

    mov cx, 10 

  
    l1:
        mov al, [si] 
        mov bl,2
        div bl
         
		cmp ah,0 
        ;test ah,ah
        je evenNumber 
        mov byte ptr [di],79      
        jmp nextElement 

    evenNumber:
        mov byte ptr [di], 101     

    nextElement:
        inc si
        inc di 
        loop l1 

    mov si, offset result
    mov cx, 10 

    l2:
    mov dl, [si] ; Load current result character
    mov ah, 02h ; Function to print character
    int 21h ; Print character
    inc si ; Move to next element in the result array
    loop l2 ; 
   

    mov ah, 4ch
    int 21h

main endp

end main

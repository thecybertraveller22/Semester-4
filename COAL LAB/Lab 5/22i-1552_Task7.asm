dosseg

.model small

.stack 100h

.data
array db 2,1,2,1,2
result db 0

.code

main proc
    mov ax, @data
    mov ds, ax

    mov si, offset array 
    
    mov cx, 5
    mov ax,0
    mov bl,0
  
    l1:
        mov al, [si] 
       

        add bl,al
        
		 
        inc si
        
        loop l1 

   
   mov dl,bl
   
   add dl,48
   mov result,dl
   mov ah,02h
   int 21h

   

    mov ah, 4ch
    int 21h

main endp

end main

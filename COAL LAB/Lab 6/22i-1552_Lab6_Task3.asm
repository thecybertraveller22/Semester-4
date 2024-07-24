dosseg
.model small
.stack 100h
.data
array db '0','0','0','0','0','0','0','0','8','1'
var2 db 10,13,'FOUND $'
var3 db 10,13,' NOT FOUND $'
var1 db ?
.code
main proc
    mov ax, @data
    mov ds, ax
    mov si, offset array
  
    mov cx, 10

    mov ah,1
    int 21h

    mov var1,al
    
    
    l1:
        mov al, [si]
       
        cmp var1,al

       
        je cout
      

        inc si 
        loop l1

    
    mov dx,offset var3 
    mov ah,9
    int 21h
    jmp h
        
   cout:
        mov dx,offset var2 
        mov ah,9
        int 21h
    
    h:

    mov ah, 4ch
    int 21h

main endp
end main

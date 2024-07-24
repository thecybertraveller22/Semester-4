dosseg
.model small
.stack 100h
.data

var1 db 6  
var2 db 2  
q db ?     
r db ?     

.code

main proc

    mov ax, @data
    mov ds, ax
    mov al, var1  
    mov bl, var2  
    mov ah, 0  
    div bl        
    mov q, al  
    mov r, ah     

    add q,48
    add r,48

    mov dl, q     ; quotient  
    mov ah, 2
    int 21h

    mov dl, 10
    mov ah, 02h
    int 21h
    mov dl, 13
    mov ah, 02h
    int 21h

    mov dl, r    ; remainder 
    mov ah, 2
    int 21h

    mov ah, 4Ch
    int 21h

main endp
end main

dosseg
.model small
.stack 100h
.data
    
    array db 0,0,0,0,9,0,0,0,8,1
    
.code
main proc
    mov ax, @data
    mov ds, ax
    mov si, offset array
  
    mov cx, 10

    mov bl, [si]
   
greaterloop:
    inc si              
    cmp [si], bl         
    
    jle greater   ;agar value choti ho to jump     

    mov bl, [si]         
    jmp greaterloop      

greater:
    loop greaterloop     

    
    add bl, '0'          
    mov dl, bl           
    mov ah, 2
    int 21h

    mov ah, 2
    mov dl,10
    int 21h
    mov dl, 13
    int 21h

    ; smaller ka kr rhy hain neechay

    mov si, offset array
  
    mov cx, 10

    mov bh, [si]

    smallerloop:
    inc si               
    cmp [si], bh         
    
    jge smaller        

    mov bh, [si]         
    jmp smallerloop     

smaller:
    loop smallerloop     

    add bh, '0'          
    mov dl, bh           
    mov ah, 2
    int 21h

    mov ah, 4ch
    int 21h

main endp
end main

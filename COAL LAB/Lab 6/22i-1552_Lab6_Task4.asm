dosseg
.model small
.stack 100h
.data

    str1 db 10,13,'Enter a number $'
    str2 db 10,13,'Enter another number $'

    ans1 db 10,13,'First number > Second Number$'
    ans2 db 10,13,'Second number > First Number$'

.code

main proc
    mov ax, @data
    mov ds, ax
    
  
    mov dx,offset str1
    mov ah,09h
    int 21h

    

    mov ah,1
    int 21h
    mov bl,al

    mov ah, 2
    mov dl,10
    int 21h
    mov dl, 13
    int 21h

    mov dx,offset str2
    mov ah,09h
    int 21h

    mov ah,1
    int 21h
    mov bh,al

    biggernumber:
        cmp bl,bh

        jg firstgreater
        jmp here

        firstgreater:
           
            mov dx,offset ans1
            mov ah,09h
            int 21h

            mov ah,2
            mov dl,bl
            int 21h
            jmp exit

        here:
           
            mov dx,offset ans2
            mov ah,09h
            int 21h



           jmp exit

        exit:
            mov ah,4ch
            int 21h

main endp
end main

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
        cmp ah, 0
        jne oddNumber ; if odd phir us ko result main dal diya
        
        jmp nextElement ; if even phir sirf increment kr diya
        
        oddNumber:
        mov al,[si]
        mov byte ptr [di], al 
        inc di 

        nextElement:
        inc si 
    loop l1

    ; displaying the new array below
    mov si, offset result
    mov cx, 10

    l2:
        mov dl, [si]
        add dl,'0'
        mov ah, 02h
        int 21h
        inc si
    loop l2 

    mov ah, 4ch
    int 21h
main endp
end main

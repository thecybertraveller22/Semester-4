dosseg
.model small
.stack 100h

.data 
    str1 db 10,13,'The sum of the squares is = $'
    num1 dw 5
    num2 dw 3
    num3 dw 2
    result dw ?
.code
    

    square proc
        mov ax,num1
        mov bx,num1
        mul bx
        mov cx,ax

        mov ax,num2
        mov bx,num2
        mul bx

        add cx,ax

        mov ax,cx
        mov bl,10
        div bl
        mov cl,ah
        mov ch,al
        mov ax,num3
        mov bx,num3
        mul bx
        aam
        add cx,ax
        aaa

        push cx
        pop cx

        ret
    square endp

    main proc

    mov ax,@data
    mov ds,ax
    mov dx,offset str1
    mov ah,09h
    int 21h

    call square

    mov result,cx

    mov dl,ch
    add dl,'0'
    mov ah,02h
    int 21h

    mov dl,cl
    add dl,'0'
    mov ah,02h
    int 21h

    mov ah,4ch
    int 21h



    main endp
    end main

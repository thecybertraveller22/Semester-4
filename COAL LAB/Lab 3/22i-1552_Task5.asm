dosseg
.model small
.stack 100h
.data

string db "Arham",'$'


.code

main proc

    mov ax, @data
    mov ds, ax
    
    mov dx,offset string
    mov ah,9
    int 21h

    mov dl, lengthof string
    add dl,48
    mov ah,2
    int 21h

    mov dl, type string
    add dl,48
    mov ah,2
    int 21h

    mov ah,4ch
    int 21h
   
main endp
end main

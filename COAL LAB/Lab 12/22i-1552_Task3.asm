;Write an assembly language code to draw a square on the screen.

dosseg
.model small
.stack 100h

.data

.code

main proc

mov ah,6
mov al,20
mov bh,00010000b
mov ch,0
mov cl,0
mov dh,30
mov dl,30
int 10h


mov ah,4ch
int 21h


main endp
end main
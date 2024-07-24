;Write an assembly language code to draw a line on the screen.

dosseg
.model small
.stack 100h

.data

.code

main proc

mov ah,6
mov al,1
mov bh,00010000b
mov ch,0
mov cl,5

mov dh,10
mov dl,60
int 10h


mov ah,4ch
int 21h


main endp
end main
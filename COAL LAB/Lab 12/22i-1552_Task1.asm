; Write an assembly language program to display a pixel on the screen.

dosseg
.model small
.stack 100h

.data

.code

main proc

; setting the graphic mode

mov ah,0h ; video mode is being set
mov al,6h
int 10h

;displaying the pixel
mov ah,0ch
mov al,1h  ; white color ky liyay
mov cx,600  ; col
mov dx,150  ; row
int 10h


mov ah,4ch
int 21h


main endp
end main
dosseg

.model small

.stack 100h

.data

array db 10 Dup(?)

.code

main proc

mov ax, @data

mov ds, ax

mov si, offset array

mov cx, 26

; loop

mov al,97

l1:
mov [si],al
mov dx, [si]


mov ah,2

int 21h

;mov dx, [si+1]

inc si
inc al
loop l1

mov ah, 4ch

int 21h

main endp

end main
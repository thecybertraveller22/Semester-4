dosseg
.model small
.stack 100h

.data

    str1 db 10,13,'Enter a multi-digit number $' 
    str2 db 10,13,' The sum of the inputted natural numbers is: $'
    unit db ?
    tens db ?
    sum dw ?
    num dw ?
    q db ?
    r db ?

.code

print proc

    AAM

    mov ch,ah
    mov cl,al

    mov dl,ch
    add dl,30h

    mov ah,02h
    int 21h

    mov dl,cl
    add dl,30h

    mov ah,02h
    int 21h
    ret
print endp

main proc

mov ax,@data
mov ds,ax



mov dx,offset str1
mov ah,09h
int 21h

mov ah,1
int 21h

sub al,30h

mov tens,al

mov ah,1
int 21h

sub al,30h

mov unit,al


mov al,10
mov bl,tens
mul bl
add al,unit

mov ah,0

mov num,ax
add ax,1

mov bx,num
mul bx


mov bl,2
div bl

mov q,al
mov r,ah

mov sum,ax


MOV dl, 10
MOV ah, 02h
INT 21h
MOV dl, 13
MOV ah, 02h
INT 21h



mov ax,sum
mov dx,offset str2
mov ah,09h
int 21h
call print



mov ah,4ch
int 21h

main endp
end main

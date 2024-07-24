dosseg
.model small
.stack 100h

.data

    str1 db 10,13,'Enter a number in the range 0-20 $' 
    str2 db 10,13,'Total Marks out of 100 for 5 subjects are $'
    str3 db 10,13,'The percentage marks out of 100 are $'
    unit db ?
    tens db ?
    sum dw ?
    percentage dw ?
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

mov cx,5
input:
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
    ; mov bl, 0
    ; mov bl, tens
    ; add al,bl
    mov ah,0
    ;mov bh,0
    ;mov bl,tens

    ;add ax,bx

    add sum,ax

loop input


MOV dl, 10
MOV ah, 02h
INT 21h
MOV dl, 13
MOV ah, 02h
INT 21h

mov dx,offset str2
mov ah,09h
int 21h

mov ax,sum
call print

mov dx,offset str3
mov ah,09h
int 21h


mov ax,sum


mov bx,99
div bx  ; ax=ax/bx
mov q,al
mov r,ah





mov bx,99
mul bx

call print

mov ah,4ch
int 21h

main endp
end main

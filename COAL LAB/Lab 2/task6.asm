.MODEL SMALL
.STACK 100H
.DATA
.CODE

MAIN PROC

MOV AH,1
INT 21h

mov dl,al

Add dl,32

mov ah,2
int 21h

MOV AH,4CH
INT 21h

MAIN ENDP

END MAIN
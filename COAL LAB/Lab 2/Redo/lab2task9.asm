dosseg
.model small
.stack 100h
.data
.code

main proc

mov ah,1
int 21h

sub al, 48
mov dl,al

mov ah,1
int 21h
sub al, 48

sub dl,al

add dl,48
mov ah,2
int 21h

mov ah,4ch
int 21h
	

main endp
end main
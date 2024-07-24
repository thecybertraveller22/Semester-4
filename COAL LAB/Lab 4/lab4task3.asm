dosseg
.model small
.stack 100h

.data
	byte_array db 'a','b','c','d','e'
	word_array dw 1234h,5678h,9ABCh
	dword_array dd 12345678h, 87654321h
    string db "Byte",'$'
    string_2 db "Word",'$'
    string_3 db "Dword",'$'
    string_4 db "Values are in the order of :: offset  -> lenght -> size -> type",'$'
    array_length db ?, ?, ?
    array_size db ?, ?, ?   
.code

main proc

	mov ax, @data
    mov ds, ax

    mov dx,offset string_4 
    mov ah,9
    int 21h

    mov ah, 0Eh       ;print new line sequence
    mov al, 0Dh
    int 10h
    mov al, 0Ah
    int 10h

    mov dx,offset string  ; prints byte
    mov ah,9
    int 21h

    mov ah, 0Eh       ;print new line sequence
    mov al, 0Dh
    int 10h
    mov al, 0Ah
    int 10h
    
    mov dx,offset byte_array
    add dx,48
    mov ah,2
    int 21h

    mov dl, 0Ah
    mov ah, 2h
    int 21h

    mov dl, byte ptr lengthof byte_array
    add dl, 48
    mov ah, 2
    int 21h

    mov dl, 0Ah
    mov ah, 2h
    int 21h

    mov dl, byte ptr sizeof byte_array
    add dl, 48
    mov ah, 2
    int 21h

    mov dl, 0Ah
    mov ah, 2h
    int 21h

    mov dl,byte ptr type byte_array
    add dl,48
    mov ah,2
    int 21h

    mov dl, 0Ah
    mov ah, 2h
    int 21h

    
    ; yahan sy word ka hy
    
    mov dx,offset string_2  ; prints word
    mov ah,9
    int 21h

    mov ah, 0Eh       ;print new line sequence
    mov al, 0Dh
    int 10h
    mov al, 0Ah
    int 10h
        
    mov dx,offset word_array
    add dx,48
    mov ah,2
    int 21h

    mov dl, 0Ah
    mov ah, 2h
    int 21h

    mov dl, byte ptr lengthof word_array
    add dl, 48
    mov ah, 2
    int 21h

    mov dl, 0Ah
    mov ah, 2h
    int 21h

    mov dl, byte ptr sizeof word_array
    add dl, 48
    mov ah, 2
    int 21h

    mov dl, 0Ah
    mov ah, 2h
    int 21h

    mov dl,byte ptr type word_array
    add dl,48
    mov ah,2
    int 21h

    mov dl, 0Ah
    mov ah, 2h
    int 21h


    ; yahan sy dword ka hy

    mov dx,offset string_3  ; prints dword
    mov ah,9
    int 21h

    mov ah, 0Eh       ;print new line sequence
    mov al, 0Dh
    int 10h
    mov al, 0Ah
    int 10h
        
    mov dx,offset dword_array
    add dx,48
    mov ah,2
    int 21h

    mov dl, 0Ah
    mov ah, 2h
    int 21h

    mov dl, byte ptr lengthof dword_array
    add dl, 48
    mov ah, 2
    int 21h

    mov dl, 0Ah
    mov ah, 2h
    int 21h

    mov dl, byte ptr sizeof dword_array
    add dl, 48
    mov ah, 2
    int 21h

    mov dl, 0Ah
    mov ah, 2h
    int 21h

    mov dl,byte ptr type dword_array
    add dl,48
    mov ah,2
    int 21h

    mov dl, 0Ah
    mov ah, 2h
    int 21h


    mov ah,4ch
    int 21h


main endp
end main
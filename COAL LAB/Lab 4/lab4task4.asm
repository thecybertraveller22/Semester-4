dosseg
.model small
.stack 100h

.data
    byte_array db 1,2,3,4,5,6
    rollnumber db "1552",'$'
   
    array_length db ?, ?, ?
    array_size db ?, ?, ?   
.code

main proc
    mov ax, @data
    mov ds, ax

    mov al, rollnumber + 3   
    sub al, '0'              
    and al, 1               

    cmp al, 0

    je add_even
    jmp add_odd

add_even:
    mov si, offset byte_array
    mov cx, lengthof byte_array
    mov bl, 1

add_loop:
    mov al, [si]      
    add al, bl        
    mov [si], al      
    add si, 2           
    loop add_loop    

    jmp print_array  

add_odd:
    mov si, offset byte_array + 1
    mov cx, lengthof byte_array - 1
    mov bl, 2

add_loop2:
    mov al, [si]      
    add al, bl       
    mov [si], al      
    add si, 2         
    loop add_loop2    

print_array:
    mov si, offset byte_array  
    mov cx, lengthof byte_array 

print_loop:
    mov dl, [si]     
    add dl, '0'      
    mov ah, 02h     
    int 21h         
    inc si           
    loop print_loop  

   
    mov ah, 4Ch      
    int 21h         

main endp
end main

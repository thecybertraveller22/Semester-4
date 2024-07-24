[org 0x100]

section .data
    rollnumber db 1 

section .text
    mov si, rollnumber 

    mov al, [si]       
    add al, '0'        
    mov dl, al        

    mov ah, 0x02      
    int 0x21          

    mov ax, 0x4c00     
    int 0x21          

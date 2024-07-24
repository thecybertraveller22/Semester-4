dosseg
.model small
.stack 100h

.data


.code

main proc



    mov bx,1
    mov cx,10
    
   L1:
      
    
    push cx
    mov ah,2
    mov dl,32 ; 32 is ascii for spaces , first loop is printing spaces
    ;int 21h

   L2:
    int 21h
    loop L2
   
   


   mov cx,bx
   mov dl,'*'

  L3:
  
   int 21h
   loop L3

   mov ah,2
   mov dl,10
   int 21h
   mov dl,13
   int 21h

   inc bx ; toggle theese to cahnge shape from pyramid to traingle
   inc bx ; toggle theese to cahnge shape from pyramid to traingle


  pop cx

  loop L1
    
                               
       
    
  exit:
  mov ah,4ch
  int 21h

main endp

end main
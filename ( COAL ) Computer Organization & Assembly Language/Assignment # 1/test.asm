; .model small
; .stack 100h

; .data
;     var1 db 'A'          ; var1 is a byte initialized with ASCII value of 'A'
;     var2 db 0            ; var2 is a byte initialized with value 0
;     var3 db 255          ; var3 is a byte initialized with value 255
;     var4 db -128         ; var4 is a byte initialized with value -128
;     var5 db 127          ; var5 is a byte initialized with value 127
;     var6 db -128         ; var6 is a signed byte initialized with value -128
;     var7 db 127          ; var7 is a signed byte initialized with value 127

; .code
; main proc
;     mov ah, 4Ch          ; Set the DOS function to terminate the program
;     int 21h              ; Call DOS interrupt
; main endp

; end main
.model small
.stack 100h

.data
    var1 db 'A'          ; var1 is a byte initialized with ASCII value of 'A'
    var2 db 0            ; var2 is a byte initialized with value 0
    var3 db 255          ; var3 is a byte initialized with value 255
    var4 db -128         ; var4 is a byte initialized with value -128
    var5 db 127          ; var5 is a byte initialized with value 127
    var6 db -128         ; var6 is a signed byte initialized with value -128
    var7 db 127          ; var7 is a signed byte initialized with value 127

.code
main proc
    ; Display the values of the variables
    mov dl, var1
    mov ah, 02h          ; DOS function to display a character
    int 21h              ; Call DOS interrupt

    mov dl, var2
    int 21h

    mov dl, var3
    int 21h

    mov dl, var4
    int 21h

    mov dl, var5
    int 21h

    mov dl, var6
    int 21h

    mov dl, var7
    int 21h

    ; Terminate the program
    mov ah, 4Ch          ; Set the DOS function to terminate the program
    int 21h              ; Call DOS interrupt
main endp

end main

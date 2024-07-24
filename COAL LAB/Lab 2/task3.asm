.MODEL SMALL          ; Declare memory model as small

.STACK 100H           ; Set stack size to 256 bytes (100H in hexadecimal)

.DATA                 ; Data section (empty in this code)

.CODE                 ; Code section

MAIN PROC             ; Start of main procedure

    MOV AH, 1         ; Set AH to 1 to indicate read character function

    INT 21h           ; Call DOS interrupt 21h to read a character from standard input

    mov dl, al        ; Move the character read into DL register

    Inc dl            ; Increment the character (advancing to the next character in ASCII sequence)

    mov ah, 2         ; Set AH to 2 to indicate display character function

    int 21h           ; Call DOS interrupt 21h to display the character in DL

    MOV AH, 4CH       ; Set AH to 4CH to indicate exit program function

    INT 21h           ; Call DOS interrupt 21h to terminate the program

MAIN ENDP             ; End of main procedure

END MAIN              ; End of program with MAIN as entry point

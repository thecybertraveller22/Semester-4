.386
.model flat, stdcall
.stack 4096

ExitProcess PROTO, dwExitCode:DWORD


.data
list db 9,9,9,9,9,9,9
rollnumber dd 2


.code
main PROC

    mov esi, offset list
	mov al,0
	add esi ,rollnumber
	mov [esi],al

     



	push 12345678           ; exit code
	call ExitProcess        ; Or call ExitProcess@4
main ENDP

END main        ;specifying the program's entry point
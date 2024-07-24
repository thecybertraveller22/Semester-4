;22i-1552 Assignment # 1 Q8

dosseg
.model small
.stack 100h 

.data
    namecaps db 'ARHAM',0
    namesmall db 'arham',0
    idword dw 022h,01552h
    iddword dd 0221552h
    idbinword dw 00100010b,001010101010010b
    idbindword dd 001000100001010101010010b
    idworddec dw 34,5458
    iddworddec dd 2233682
    agebinbyte db 00010011b
    agedecbyte db 19
    agebinbyteagain db 00010011b
    CNIChex dq 03D43FE46E7Fh


.code
    main proc
        ; mov ax, @data
        ; mov ds,ax
    main endp
    end main

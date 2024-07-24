mov ax, 0FFFFh

; Flag is 0000 0010 0000 0010

; Carry is 0

; Parity is 0

; Sign is 0

; Zero is 0

; Auxillary is 0

; Overflow is 0

inc ax

; Flag is 0000 0010 0101 0110

; Carry is 0

; Parity is 1

; Sign is 0

; Zero is 1

; Auxillary is 1

; Overflow is 0

mov bl, 4

; Flag is 0000 0010 0101 0110

; Carry is 0

; Parity is 1

; Sign is 0

; Zero is 1

; Auxillary is 1

; Overflow is 0

sub bl, 5

; Flag is 0000 0010 1001 0111

; Carry is 1

; Parity is 1

; Sign is 1

; Zero is 0

; Auxillary is 1

; Overflow is 0
.data
	char: .byte 's'

.text
	li $v0,4
	la $a0,char
	syscall
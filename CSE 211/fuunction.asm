.data
	msg: .asciiz "Hiiiii"
	
.text
	main: 
		jal display		
		
		li $v0,10
		syscall	
		
	display:
		
	li $v0,4	
	la $a0,msg
	syscall
	jr $ra
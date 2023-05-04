.data
	num1: .word 5
	num2: .word 4
	msg: .asciiz "Equal."
	msg2: .asciiz "Not Equal."

.text
	main: 
		
	lw $t0, num1($zero)
	lw $t1, num2($zero)
	
	beq $t0,$t1,equal
	
	bne $t0,$t1,nEqual
					
	li $v0,10
	syscall	
	
	equal:
	
	li $v0,4	
	la $a0,msg
	syscall
				
	li $v0,10
	syscall	
	
	nEqual:
	
	li $v0,4	
	la $a0,msg2
	syscall
				
	li $v0,10
	syscall	
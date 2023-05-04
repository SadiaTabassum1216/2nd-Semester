.data
	prompt: .asciiz "Enter your age: "
	msg: .asciiz "\nYour age is "
	
.text
	li $v0,4	#printing the prompt msg
	la $a0,prompt
	syscall
	
	li $v0,5	#input
	syscall
	
	move $t0,$v0	#storing input
	
	li $v0,4	#printing the next line
	la $a0,msg
	syscall
	
	li $v0,1	#printing the input number
	move $a0,$t0
	syscall
	
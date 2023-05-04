.data
	msg1: .asciiz "Enter the dividend: "
	msg2: .asciiz "\nEnter the divisor: "
	msg3: .asciiz "\nResult of division: Quotient= "
	msg4: .asciiz "  Remainder= "
	
.text
	li $v0,4
	la $a0,msg1
	syscall
	
	li $v0,5	#input dividend
	syscall	
	move $t0,$v0
	
	li $v0,4	
	la $a0,msg2
	syscall
	
	li $v0,5	#input divisor
	syscall	
	move $t1,$v0	
	
	div $t0,$t1	#division	
	mflo $t0	#quotient	
	mfhi $t1	#remainder
	
	li $v0,4	
	la $a0,msg3
	syscall
	
	li $v0,1
	move $a0,$t0	#display quotient
	syscall
	
	li $v0,4	
	la $a0,msg4
	syscall
	
	li $v0,1
	move $a0,$t1	#display remainder
	syscall
	

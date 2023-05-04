.data
	msg1: .asciiz "Enter the multiplier: "
	msg2: .asciiz "\nEnter the multiplicand: "
	msg3: .asciiz "\nResult of multiplication: "
	msg4: .asciiz "\nOverflow."
	
.text
	li $v0,4
	la $a0,msg1
	syscall
	
	li $v0,5	#input multiplier
	syscall	
	move $s0,$v0
	
	li $v0,4	
	la $a0,msg2
	syscall
	
	li $v0,5	#input multiplicand
	syscall	
	move $s1,$v0	
	

	mul  $s2,$s0,$s1	#multiplication	
	mult $s0, $s1
	mfhi $at
	mflo $t0
	sra  $t0,$t0,31		#shifting right
	
	bne $at, $t0,overflow	#checking overflow
		
	li $v0,4	
	la $a0,msg3
	syscall
	
	li $v0,1
	move $a0,$s2		#display result
	syscall	
	
	li $v0,10		#terminate
	syscall
	
	
	overflow:
		li $v0,4	
		la $a0,msg4
		syscall
		
		li $v0,10
		syscall

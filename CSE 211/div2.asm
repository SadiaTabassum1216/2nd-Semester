.data

.text
	addi $s0,$zero,10
	addi $s1,$zero,3
	
	div $s0,$s1
	
	mflo $s0	
	mfhi $s1

	li $v0,1
	move $a0, $s0
	syscall
	
	li $v0,1
	move $a0, $s1
	syscall
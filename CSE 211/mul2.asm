.data

.text
	addi $s0,$zero,1000
	addi $s1,$zero,-50
	
	mult $s0,$s1
	mflo $s2
	
	li $v0,1
	move $a0, $s2
	syscall
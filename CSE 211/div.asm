.data

.text
	addi $s0,$zero,10
	addi $s1,$zero,3
	
	div $t0,$s0,$s1
	
	li $v0,1
	#move $a0, $t0
	add $a0,$zero, $t0
	syscall
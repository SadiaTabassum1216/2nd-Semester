.data
	num1: .word 5
	num2: .word 3

.text
	lw $s0, num1($zero)
	lw $s1, num2($zero)
	
	sub $t0,$s0,$s1
	
	li $v0,1
	move $a0, $t0
	syscall

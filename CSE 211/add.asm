.data
	num1: .word 5
	num2: .word 3

.text
	lw $t0, num1($zero) 	#storing t0=5(num1)
	lw $t1, num2($zero)	#storing t1=3(num2)
	
	add $t2,$t0,$t1		#t2=t0+t1
	
	li $v0,1		#printing command
	add $a0,$zero, $t2	
	syscall	
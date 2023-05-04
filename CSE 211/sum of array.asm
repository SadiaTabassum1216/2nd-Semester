.data
	msg: .asciiz "The sum is: "
	msg2: .asciiz "\nThe average is: "
	array: .word 1, 3, 2, 4, 5
	
.text
main:
	add  $a1,$zero,20	#a1= array size (5*4)
	
loop:
	lw $s0, array($t0)	
	add $t1, $t1, $s0	
	addi $t0,$t0,4	
	bge $t0,$a1,end
	j loop
	
end:
	li $v0,4
	la $a0,msg
	syscall
	
	li $v0,1
	move $a0,$t1	#t1=sum
	syscall
	
	li $v0,4
	la $a0,msg2
	syscall
	
	addi $t3,$zero,5
	div $t1,$t3
	mflo $t2
	
	
	li $v0,1
	move $a0,$t2	#t2= average
	syscall
	
	li $v0,10	#terminate
	syscall
	
	
	
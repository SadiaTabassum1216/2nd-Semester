.data
	matrix: .space 900
	empty: .space 30
	.eqv SIZE 2

	msg1: .asciiz"Enter number of rows in the array: "
	msg2: .asciiz"Enter number of columns in the array: "
	msg3: .asciiz"Enter an array of "
	msg4: .asciiz" characters: \n"
	msg5: .asciiz"\nThe entered "
	msg6: .asciiz" array is:  "
	msg7: .asciiz"\nEnter a row number: "
	msg8: .asciiz"Enter another row number: "
	msg9: .asciiz"\nThe array after Exchange row "
	msg10: .asciiz" and row "
	msg11: .asciiz" is: "
	msg12: .asciiz"x"
	space: .asciiz" "
	newline: .ascii"\n"

.text
	main:
		li $v0, 4
		la $a0, msg1
		syscall
		
		li $v0, 5	#Input row number
		syscall
		move $t2, $v0 	#t0=s0=row num
		move $s0, $v0
		
		li $v0, 4
		la $a0, msg2
		syscall
		
		li $v0, 5	#Input column number
		syscall
		move $t3, $v0	#t3=s1=column num
		move $s1, $v0
			
		li $v0, 4
		la $a0, msg3
		syscall
		
		li $v0, 1
		add $a0, $s0, $zero
		syscall
		
		li $v0, 4
		la $a0, msg12
		syscall
		
		li $v0, 1
		add $a0, $s1, $zero
		syscall
		
		li $v0, 4
		la $a0, msg4
		syscall
		
		
		la $s2, matrix		#storing the address of the matrix
		move $t0, $s0
		
		newRow:
			move $t1, $s1	
			la $a0, empty
			mul $a1, $s1, 2
			addi $a1, $a1, 1
			li $v0, 8	#input a row as string
			syscall
		
		newColumn:
			lb $s3, ($a0)
			sb $s3, ($s2)
			addi $a0, $a0, 2
			addi $s2, $s2, 2
			addi $t1, $t1, -1
			bnez $t1, newColumn
			
			addi $t0, $t0, -1
			bnez $t0, newRow
					
		
		#Statement before printing array
		
		li $v0, 4
		la $a0, msg5
		syscall
		li $v0, 1
		add $a0, $s0, $zero
		syscall
		li $v0, 4
		la $a0, msg12
		syscall
		li $v0, 1
		add $a0, $s1, $zero
		syscall
		li $v0, 4
		la $a0, msg6
		syscall
		
		jal print	#prints array
		
		
		#Exchage rows
		li $v0, 4
		la $a0, msg7
		syscall
		
		li $v0, 5
		syscall
		move $s4, $v0		#row-1: s4
		
		li $v0, 4
		la $a0, msg8
		syscall
		
		li $v0, 5
		syscall
		move $s5, $v0		#row-2: s5
		
		la $s2, matrix
		
		mul $t0, $s4, $s1
		mul $t0, $t0, SIZE
		add $t0, $t0, $s2
		
		mul $t1, $s5, $s1
		mul $t1, $t1, SIZE
		add $t1, $t1, $s2
		
		move $t4, $s1
		
		Exchange:
			lb $t2, ($t0)
			lb $t3, ($t1)
			sb $t2, ($t1)
			sb $t3, ($t0)
			addi $t0, $t0, 2
			addi $t1, $t1, 2
			addi $t4, $t4, -1
			bnez $t4, Exchange
			
		
		#Statement before printing the Array
		
		li $v0, 4
		la $a0, msg9
		syscall
		
		li $v0, 1
		add $a0, $s4, $zero
		syscall
		
		li $v0, 4
		la $a0, msg10
		syscall
		
		li $v0, 1
		add $a0, $s5, $zero
		syscall
		
		li $v0, 4
		la $a0, msg11
		syscall
		
		jal print	#prints array
		
		li $v0, 10
		syscall
	
	#Procedure for printing array
	print:
		la $s2, matrix	
		move $t0, $s0
		
		NewLine:
			move $t1, $s1
			
			li $v0, 4
			la $a0, newline
			syscall
		
		printArray:
			li $v0, 11
			lb $a0, ($s2)
			syscall
			
			li $v0, 4
			la $a0, space
			syscall
			
			addi $s2, $s2, 2
			addi $t1, $t1, -1
			
			bnez $t1, printArray
			
		addi $t0, $t0, -1	#loop decresing
		bnez $t0, NewLine
		
		jr $ra			#return

.data
matrix: .space 900
empty: .space 30
.eqv Data_Size 2
msg2: .asciiz"Enter number of columns in the array: "
msg7: .asciiz"\nEnter a row number: "
msg8: .asciiz"Enter another row number: "
msg9: .asciiz"\nThe array after exchanging row "
msg10: .asciiz" and row "
msg11: .asciiz" is: "
msg1: .asciiz"Enter number of rows in the array: "
msg3: .asciiz"Enter an array of "
msg4: .asciiz" characters: \n"
msg5: .asciiz"\nThe entered "
msg6: .asciiz" array is:  "
multi: .asciiz"x"
space: .asciiz" "
newline: .ascii"\n"
.text
	main:
		#Row taking 
		li $v0, 4
		la $a0, msg1
		syscall
		
		li $v0, 5
		syscall
		move $t2, $v0
		move $s0, $v0		#Here $s0=$t2= row
		
		
		#Column taking
		li $v0, 4
		la $a0, msg2
		syscall
		
		li $v0, 5
		syscall
		move $t3, $v0
		move $s1, $v0		#Here $s1=$t3= column
		
		
		#array Input
		li $v0, 4
		la $a0, msg3
		syscall
		li $v0, 1
		add $a0, $s0, $zero
		syscall
		li $v0, 4
		la $a0, multi
		syscall
		li $v0, 1
		add $a0, $s1, $zero
		syscall
		li $v0, 4
		la $a0, msg4
		syscall
		
		#Code for inputting array
		la $s2, matrix
		move $t0, $s0		# $t0= for row loop
		
		RowLoop:
			move $t1, $s1		# $t1= for column loop
			la $a0, empty		#makes $a0 empty
			mul $a1, $s1, 2
			addi $a1, $a1, 1		# $a1 is for the size of the row
			li $v0, 8
			syscall
		
		ColumnLoop:
			lb $s3, ($a0)		# char goes to $s3 from ($a0). Here s3 is a normal address to store temporary data
			sb $s3, ($s2)		# char goes to ($s2) from $s3 because we initialize the array in ($s2)
			addi $a0, $a0, 2
			addi $s2, $s2, 2
			addi $t1, $t1, -1
			bnez $t1, ColumnLoop
			
			addi $t0, $t0, -1
			bnez $t0, RowLoop
			
		
		
		#array printing
		li $v0, 4
		la $a0, msg5
		syscall
		li $v0, 1
		add $a0, $s0, $zero
		syscall
		li $v0, 4
		la $a0, multi
		syscall
		li $v0, 1
		add $a0, $s1, $zero
		syscall
		li $v0, 4
		la $a0, msg6
		syscall
		
		jal print
		
		#First row input
		li $v0, 4
		la $a0, msg7
		syscall
		li $v0, 5
		syscall
		move $s4, $v0		# $s4= First row taken
		
		#Another row input
		li $v0, 4
		la $a0, msg8
		syscall
		li $v0, 5
		syscall
		move $s5, $v0		# $s5= Another row taken
		
		#Exchanging row
		la $s2, matrix
		#First row address calculating
		mul $t0, $s4, $s1
		mul $t0, $t0, Data_Size
		add $t0, $t0, $s2
		#Another row address calculating
		mul $t1, $s5, $s1
		mul $t1, $t1, Data_Size
		add $t1, $t1, $s2
		
		move $t4, $s1
		exchanging:
			lb $t2, ($t0)
			lb $t3, ($t1)
			sb $t2, ($t1)
			sb $t3, ($t0)
			addi $t0, $t0, 2
			addi $t1, $t1, 2
			addi $t4, $t4, -1
			bnez $t4, exchanging
		
		#array printing
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
		
		jal print
		
	li $v0, 10
	syscall
	
	#Code for printing array
		print:
		la $s2, matrix	
		move $t0, $s0
		
		NewLine:
			move $t1, $s1
			
			li $v0, 4
			la $a0, newline
			syscall
		
		ArrayPrinting:
			li $v0, 11
			lb $a0, ($s2)
			syscall
			
			li $v0, 4
			la $a0, space
			syscall
			
			addi $s2, $s2, 2
			addi $t1, $t1, -1
			
			bnez $t1, ArrayPrinting
			
		addi $t0, $t0, -1
		bnez $t0, NewLine
		
		jr $ra
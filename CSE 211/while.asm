.data
	msg: .asciiz "Loop ends here."
	msg2: .asciiz ", "

.text
   main:
   	addi $t0,$zero,0		#i=0
   	
   	while:
   		bgt $t0,20,exit		#i<20
   		jal print
   		
   		addi $t0,$t0,1		#i++
   		j while
   		
   		li $v0,10
		syscall
		
   	
   	exit:  	  		
		li $v0,4
		la $a0, msg
		syscall	
   				
		li $v0,10
		syscall
		
	print:
		li $v0,1	#prints the number
		move $a0,$t0
		syscall
		
			
		li $v0,4	#prints comma
		la $a0, msg2
		syscall	
		
		jr $ra		#returns
			
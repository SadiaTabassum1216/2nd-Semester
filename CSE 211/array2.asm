.data
    prompt: .asciiz "Enter a number\n" # message
    msg: .asciiz "The array is: "
    colon: .asciiz ": "
    .align 4
    myArray: .space 40
    space: .asciiz " "
    
.text
main:
	
    li $v0,4    		#loading message prompt ,syscall to print
    la $a0,prompt
    syscall
    
    add $t7, $zero,1 

for:      
     
    li $v0,1			#print the serial number
    move $a0, $t7	
    syscall             
    
    
    li $v0,4    
    la $a0,colon
    syscall
                      
    li $v0,5   			 #user input
    syscall
	
    move $s0,$v0
    sw $s0, myArray($t0)	#saving %s0 in array[0]

    addi $t0, $t0,4    		#increasing $t0 index
    add $t7,$t7,1
    
    beq  $t0,40,done		#if (t0=4*10)
    j for			#recursion
 
done:
   sub $t0,$t0,$t0		#t0=0
    
    li $v0,4    		#loading print msg
    la $a0,msg
    syscall
    
 
print:
    lw $s1, myArray($t0)	#storing array[0] in s1  
   
     li $v0,1			#print the value
    
    move $a0, $s1		#stores the array address and return value
    syscall
    
    li $v0,4			#print space
    la $a0,space
    syscall
    
    addi $t0, $t0,4   		#increasing $t0 index
    
    beq $t0,40,exit		#end of loop
    j print
 	
exit:
    li $v0,10
    syscall

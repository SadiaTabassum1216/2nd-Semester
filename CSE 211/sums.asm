.data
    prompt: .asciiz "Enter a number: " # message
    .align 4
    myArray: .space 32
    
.text
main:
while:            # while loop until bytes become 32(4*8)
    beq $t0,32,exit
     
    li $v0,4    #loading message prompt ,syscall to print
    la $a0,prompt
    syscall
     
    li $v0,5    #user input
    syscall

    move $s0,$v0
    sw $s0, myArray($t0)

    addi $t0, $t0,4    #increasing $t0 index 

    j while     #loop back
    

forsum:    
  bge $s0, 6, end_forsum    
  lw $t1,myArray($t0)  # Load the number from array 
  addu $a0, $a0, $t1 # Compute the sum

  addi $t0,$t0,4    
  addi $s0,$s0,1      
  j forsum
  
end_forsum:
  li $v0,1 
  add $a0,$zero, $t0
  syscall   # Print sum
 
exit:

  li $s0, 0
  li $a0, 0
  li $t0, 0
  jal forsum

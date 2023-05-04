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
 
exit:
li $v0,10
syscall

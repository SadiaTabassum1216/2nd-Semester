.data

array: .word 0,0,0,0,0,0,0,0,0,0
print: .asciiz "\nthe sorted array : "
space: .asciiz " "


.text
.globl main
main:
     la $t1,array
     li $s1,10

L1: beq $s1,$s2,L2
li $v0,5
syscall
sw $v0,0($t1)
addi $t1,$t1,4
addi $s2,$s2,1
j L1
li $s1,40
li $s2,0
li $s3,4

L2: beq $s1,$s2,printf
add $t1,$t1,$s2
lw $t0,0($t1)   #a[i]
L3: beq $s3,$s1,incc
add $t1,$t1,$s3
lw $t2,0($t1)   #a[j]
slt $t3,$t0,$t2
beq $t3,$0,swap
L4: addi $s3,$s3,4
j L3

swap:   
sw $t0,0($t1)
sub $t1,$t1,$s2
sw $t2,0($t1)
j L4

incc:
addi $s2,$s2,4
j L2


printf:
la $t1,array
li $t0,0
li $v0,4
la $a0,print
syscall
li $s2,0
li $s1,10
L5: beq $s1,$s2,out
li $v0,1
lw $t0,0($t1)
move $a0,$t0
syscall
li $v0,4
la $a0,space
syscall
addi $s2,$s2,1
addi $t1,$t1,4
j L5

out:
li $v0,10
syscall
.end

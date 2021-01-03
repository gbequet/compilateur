.data
newLine: .asciiz "\n"
segFaultWarning: .asciiz "Segmentation fault"

.text

SEGFAULT:
li $v0, 4
la $a0, segFaultWarning
syscall
j L2


POW:
add $24, $zero, $zero
li $v0, 1

POW_LOOP:
beq $24, $a1, EXIT_POW
mul $v0, $v0, $a0
addi $24, $24, 1
j POW_LOOP

EXIT_POW:
jr $ra

main:
addi $sp, $sp, -4
addi $sp, $sp, -4
lw $8, 4($sp)
li $v0, 1
move $a0, $8
syscall
li $v0, 4
la $a0, newLine
syscall
L1:
lw $9, 0($sp)
li $v0, 1
move $a0, $9
syscall
li $v0, 4
la $a0, newLine
syscall

L2:

li $v0, 10
syscall
.data
newLine: .asciiz "\n"
segFaultWarning: .asciiz "Segmentation fault"

.text

SEGFAULT:
li $v0, 4
la $a0, segFaultWarning
syscall
j L2


POW:
add $24, $zero, $zero
li $v0, 1

POW_LOOP:
beq $24, $a1, EXIT_POW
mul $v0, $v0, $a0
addi $24, $24, 1
j POW_LOOP

EXIT_POW:
jr $ra

main:
addi $sp, $sp, -4
addi $sp, $sp, -4
lw $8, 4($sp)
li $v0, 1
move $a0, $8
syscall
li $v0, 4
la $a0, newLine
syscall
L1:
lw $9, 0($sp)
li $v0, 1
move $a0, $9
syscall
li $v0, 4
la $a0, newLine
syscall

L2:

li $v0, 10
syscall
.data
newLine: .asciiz "\n"
segFaultWarning: .asciiz "Segmentation fault"

.text

SEGFAULT:
li $v0, 4
la $a0, segFaultWarning
syscall
j L5


POW:
add $24, $zero, $zero
li $v0, 1

POW_LOOP:
beq $24, $a1, EXIT_POW
mul $v0, $v0, $a0
addi $24, $24, 1
j POW_LOOP

EXIT_POW:
jr $ra

main:
addi $sp, $sp, -4
addi $sp, $sp, -4
addi $sp, $sp, -4
li $8, 4
sw $8, 8($sp)
L1:
li $8, 8
sw $8, 4($sp)
L2:

L5:

li $v0, 10
syscall

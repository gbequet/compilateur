.data
segFaultWarning: .asciiz "Segmentation fault"
str_false: .asciiz "False"
str_true: .asciiz "True"

.text

SEGFAULT:
li $v0, 4
la $a0, segFaultWarning
syscall
j L44


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
addi $sp, $sp, -24
addi $sp, $sp, -4
li $24, 0
li $25, 0
add $8, $24, $25
li $24, 5
li $25, 1
sub $9, $24, $25
li $24, 6
bge $9, $24, SEGFAULT
li $24, 0
blt $9, $24, SEGFAULT
add $11, $8, $9
li $24, 4
mul $12, $11, $24
li $24, 4
add $13, $24, $12
li $24, 4
move $25, $sp
add $25, $25, $13
sw $24, ($25)
L8:
li $24, 0
li $25, 0
add $14, $24, $25
li $24, 5
li $25, 2
sub $15, $24, $25
li $24, 6
bge $15, $24, SEGFAULT
li $24, 0
blt $15, $24, SEGFAULT
move $8, $16
add $8, $14, $15
li $24, 4
mul $9, $8, $24
li $24, 4
add $10, $24, $9
li $24, 0
li $25, 0
add $11, $24, $25
li $24, 5
li $25, 1
sub $12, $24, $25
li $24, 6
bge $12, $24, SEGFAULT
li $24, 0
blt $12, $24, SEGFAULT
add $14, $11, $12
li $24, 4
mul $15, $14, $24
li $24, 4
add $16, $24, $15
move $8, $16
move $24, $sp
add $24, $24, $16
lw $8, ($24)
move $25, $sp
add $25, $25, $10
sw $9, ($25)
L24:
li $24, 0
li $25, 0
add $10, $24, $25
li $24, 5
li $25, 1
sub $11, $24, $25
li $24, 6
bge $11, $24, SEGFAULT
li $24, 0
blt $11, $24, SEGFAULT
add $13, $10, $11
li $24, 4
mul $14, $13, $24
li $24, 4
add $15, $24, $14
move $24, $sp
add $24, $24, $15
lw $16, ($24)
move $8, $16
li $v0, 1
move $a0, $16
syscall
L33:
.data
str0: .asciiz "\n"
.text
li $v0, 4
la $a0, str0
syscall
L34:
li $24, 0
li $25, 0
add $9, $24, $25
li $24, 5
li $25, 2
sub $10, $24, $25
li $24, 6
bge $10, $24, SEGFAULT
li $24, 0
blt $10, $24, SEGFAULT
add $12, $9, $10
li $24, 4
mul $13, $12, $24
li $24, 4
add $14, $24, $13
move $24, $sp
add $24, $24, $14
lw $15, ($24)
li $v0, 1
move $a0, $15
syscall
L43:
.data
str1: .asciiz "\n"
.text
li $v0, 4
la $a0, str1
syscall

L44:

li $v0, 10
syscall

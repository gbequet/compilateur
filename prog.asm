.data
segFaultWarning: .asciiz "Segmentation fault"
str_false: .asciiz "False"
str_true: .asciiz "True"

.text

SEGFAULT:
li $v0, 4
la $a0, segFaultWarning
syscall
j L23


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
addi $sp, $sp, -4
.data
str0: .asciiz "Entrez le premier entier : "
.text
li $v0, 4
la $a0, str0
syscall
L1:
li $v0, 5
syscall
sw $v0, 4($sp)
L2:
.data
str1: .asciiz "Entrez le deuxieme entier : "
.text
li $v0, 4
la $a0, str1
syscall
L3:
li $v0, 5
syscall
sw $v0, 0($sp)
L4:
lw $10, 4($sp)
sw $10, 12($sp)
L5:
lw $8, 0($sp)
sw $8, 8($sp)
L6:
lw $24, 4($sp)
lw $25, 0($sp)
bne $24, $25, L8
j L16
L8:
lw $24, 4($sp)
lw $25, 0($sp)
bgt $24, $25, L10
j L13
L10:
lw $24, 4($sp)
lw $25, 0($sp)
sub $9, $24, $25
sw $9, 4($sp)
j L6
L13:
lw $24, 0($sp)
lw $25, 4($sp)
sub $8, $24, $25
sw $8, 0($sp)
j L6
L16:
.data
str2: .asciiz "pgcd("
.text
li $v0, 4
la $a0, str2
syscall
L17:
lw $8, 12($sp)
li $v0, 1
move $a0, $8
syscall
L18:
.data
str3: .asciiz ","
.text
li $v0, 4
la $a0, str3
syscall
L19:
lw $9, 8($sp)
li $v0, 1
move $a0, $9
syscall
L20:
.data
str4: .asciiz ") = "
.text
li $v0, 4
la $a0, str4
syscall
L21:
lw $10, 4($sp)
li $v0, 1
move $a0, $10
syscall
L22:
.data
str5: .asciiz "\n"
.text
li $v0, 4
la $a0, str5
syscall

L23:

li $v0, 10
syscall

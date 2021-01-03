.data
segFaultWarning: .asciiz "Segmentation fault"
str_false: .asciiz "False"
str_true: .asciiz "True"

.text

SEGFAULT:
li $v0, 4
la $a0, segFaultWarning
syscall
j L107


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
addi $sp, $sp, -24
addi $sp, $sp, -4
addi $sp, $sp, -4
addi $sp, $sp, -4
.data
str0: .asciiz "Remplissez le tableau :\n"
.text
li $v0, 4
la $a0, str0
syscall
L1:
li $8, 0
sw $8, 44($sp)
L2:
lw $24, 44($sp)
li $25, 5
ble $24, $25, L4
j L18
L4:
.data
str1: .asciiz "t["
.text
li $v0, 4
la $a0, str1
syscall
L5:
lw $8, 44($sp)
li $v0, 1
move $a0, $8
syscall
L6:
.data
str2: .asciiz "] = "
.text
li $v0, 4
la $a0, str2
syscall
L7:
li $24, 0
li $25, 0
add $9, $24, $25
li $24, 5
lw $25, 44($sp)
sub $10, $24, $25
li $24, 6
bge $10, $24, SEGFAULT
li $24, 0
blt $10, $24, SEGFAULT
add $12, $9, $10
li $24, 4
mul $13, $12, $24
li $24, 12
add $14, $24, $13
li $v0, 5
syscall
move $24, $sp
add $24, $24, $14
sw $v0, ($24)
L15:
lw $24, 44($sp)
li $25, 1
add $16, $24, $25
move $8, $16
sw $16, 44($sp)
j L2
L18:
li $8, 0
sw $8, 44($sp)
L19:
lw $24, 44($sp)
li $25, 4
ble $24, $25, L21
j L87
L21:
lw $8, 44($sp)
sw $8, 8($sp)
L22:
lw $24, 44($sp)
li $25, 1
add $8, $24, $25
sw $8, 40($sp)
L24:
lw $24, 40($sp)
li $25, 5
ble $24, $25, L26
j L48
L26:
li $24, 0
li $25, 0
add $8, $24, $25
li $24, 5
lw $25, 40($sp)
sub $9, $24, $25
li $24, 6
bge $9, $24, SEGFAULT
li $24, 0
blt $9, $24, SEGFAULT
add $11, $8, $9
li $24, 4
mul $12, $11, $24
li $24, 12
add $13, $24, $12
move $24, $sp
add $24, $24, $13
lw $14, ($24)
li $24, 0
li $25, 0
add $15, $24, $25
li $24, 5
lw $25, 8($sp)
sub $16, $24, $25
move $8, $16
li $24, 6
bge $16, $24, SEGFAULT
li $24, 0
blt $16, $24, SEGFAULT
add $9, $15, $16
li $24, 4
mul $10, $9, $24
li $24, 12
add $11, $24, $10
move $24, $sp
add $24, $24, $11
lw $12, ($24)
blt $14, $12, L44
j L45
L44:
lw $13, 40($sp)
sw $13, 8($sp)
L45:
lw $24, 40($sp)
li $25, 1
add $8, $24, $25
sw $8, 40($sp)
j L24
L48:
lw $24, 8($sp)
lw $25, 44($sp)
bne $24, $25, L50
j L84
L50:
li $24, 0
li $25, 0
add $8, $24, $25
li $24, 5
lw $25, 44($sp)
sub $9, $24, $25
li $24, 6
bge $9, $24, SEGFAULT
li $24, 0
blt $9, $24, SEGFAULT
add $11, $8, $9
li $24, 4
mul $12, $11, $24
li $24, 12
add $13, $24, $12
move $24, $sp
add $24, $24, $13
lw $14, ($24)
sw $14, 4($sp)
L59:
li $24, 0
li $25, 0
add $8, $24, $25
li $24, 5
lw $25, 8($sp)
sub $9, $24, $25
li $24, 6
bge $9, $24, SEGFAULT
li $24, 0
blt $9, $24, SEGFAULT
add $11, $8, $9
li $24, 4
mul $12, $11, $24
li $24, 12
add $13, $24, $12
move $24, $sp
add $24, $24, $13
lw $14, ($24)
sw $14, 0($sp)
L68:
li $24, 0
li $25, 0
add $8, $24, $25
li $24, 5
lw $25, 44($sp)
sub $9, $24, $25
li $24, 6
bge $9, $24, SEGFAULT
li $24, 0
blt $9, $24, SEGFAULT
add $11, $8, $9
li $24, 4
mul $12, $11, $24
li $24, 12
add $13, $24, $12
lw $24, 0($sp)
move $25, $sp
add $25, $25, $13
sw $24, ($25)
L76:
li $24, 0
li $25, 0
add $15, $24, $25
li $24, 5
lw $25, 8($sp)
sub $16, $24, $25
move $8, $16
li $24, 6
bge $16, $24, SEGFAULT
li $24, 0
blt $16, $24, SEGFAULT
add $9, $15, $16
li $24, 4
mul $10, $9, $24
li $24, 12
add $11, $24, $10
lw $24, 4($sp)
move $25, $sp
add $25, $25, $11
sw $24, ($25)
L84:
lw $24, 44($sp)
li $25, 1
add $13, $24, $25
sw $13, 44($sp)
j L19
L87:
.data
str3: .asciiz "Le tableau trie :\n"
.text
li $v0, 4
la $a0, str3
syscall
L88:
li $8, 0
sw $8, 44($sp)
L89:
lw $24, 44($sp)
li $25, 5
ble $24, $25, L91
j L107
L91:
.data
str4: .asciiz "t["
.text
li $v0, 4
la $a0, str4
syscall
L92:
lw $8, 44($sp)
li $v0, 1
move $a0, $8
syscall
L93:
.data
str5: .asciiz "] = "
.text
li $v0, 4
la $a0, str5
syscall
L94:
li $24, 0
li $25, 0
add $9, $24, $25
li $24, 5
lw $25, 44($sp)
sub $10, $24, $25
li $24, 6
bge $10, $24, SEGFAULT
li $24, 0
blt $10, $24, SEGFAULT
add $12, $9, $10
li $24, 4
mul $13, $12, $24
li $24, 12
add $14, $24, $13
move $24, $sp
add $24, $24, $14
lw $15, ($24)
li $v0, 1
move $a0, $15
syscall
L103:
.data
str6: .asciiz "\n"
.text
li $v0, 4
la $a0, str6
syscall
L104:
move $8, $16
lw $24, 44($sp)
li $25, 1
add $8, $24, $25
sw $8, 44($sp)
j L89

L107:

li $v0, 10
syscall

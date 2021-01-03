.data
segFaultWarning: .asciiz "Segmentation fault"
str_false: .asciiz "False"
str_true: .asciiz "True"

.text

SEGFAULT:
li $v0, 4
la $a0, segFaultWarning
syscall
j L106


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
addi $sp, $sp, -24
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
sw $8, 36($sp)
L2:
lw $24, 36($sp)
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
lw $8, 36($sp)
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
lw $25, 36($sp)
sub $10, $24, $25
li $24, 6
bge $10, $24, SEGFAULT
li $24, 0
blt $10, $24, SEGFAULT
add $12, $9, $10
li $24, 4
mul $13, $12, $24
li $24, 8
add $14, $24, $13
li $v0, 5
syscall
move $24, $sp
add $24, $24, $14
sw $v0, ($24)
L15:
lw $24, 36($sp)
li $25, 1
add $16, $24, $25
move $8, $16
sw $16, 36($sp)
j L2
L18:
li $8, 5
sw $8, 36($sp)
L19:
lw $24, 36($sp)
li $25, 1
bge $24, $25, L21
j L86
L21:
li $8, 0
sw $8, 32($sp)
L22:
lw $24, 36($sp)
li $25, 1
sub $8, $24, $25
lw $24, 32($sp)
ble $24, $8, L25
j L83
L25:
lw $24, 32($sp)
li $25, 1
add $9, $24, $25
li $24, 0
li $25, 0
add $10, $24, $25
li $24, 5
sub $11, $24, $9
li $24, 6
bge $11, $24, SEGFAULT
li $24, 0
blt $11, $24, SEGFAULT
add $13, $10, $11
li $24, 4
mul $14, $13, $24
li $24, 8
add $15, $24, $14
move $24, $sp
add $24, $24, $15
lw $16, ($24)
move $8, $16
li $24, 0
li $25, 0
add $8, $24, $25
li $24, 5
lw $25, 32($sp)
sub $9, $24, $25
li $24, 6
bge $9, $24, SEGFAULT
li $24, 0
blt $9, $24, SEGFAULT
add $11, $8, $9
li $24, 4
mul $12, $11, $24
li $24, 8
add $13, $24, $12
move $24, $sp
add $24, $24, $13
lw $14, ($24)
blt $16, $14, L44
j L80
L44:
li $24, 0
li $25, 0
add $15, $24, $25
li $24, 5
lw $25, 32($sp)
sub $16, $24, $25
move $8, $16
li $24, 6
bge $16, $24, SEGFAULT
li $24, 0
blt $16, $24, SEGFAULT
add $9, $15, $16
li $24, 4
mul $10, $9, $24
li $24, 8
add $11, $24, $10
move $24, $sp
add $24, $24, $11
lw $12, ($24)
sw $12, 4($sp)
L53:
lw $24, 32($sp)
li $25, 1
add $8, $24, $25
li $24, 0
li $25, 0
add $9, $24, $25
li $24, 5
sub $10, $24, $8
li $24, 6
bge $10, $24, SEGFAULT
li $24, 0
blt $10, $24, SEGFAULT
add $12, $9, $10
li $24, 4
mul $13, $12, $24
li $24, 8
add $14, $24, $13
move $24, $sp
add $24, $24, $14
lw $15, ($24)
sw $15, 0($sp)
L63:
li $24, 0
li $25, 0
add $8, $24, $25
li $24, 5
lw $25, 32($sp)
sub $9, $24, $25
li $24, 6
bge $9, $24, SEGFAULT
li $24, 0
blt $9, $24, SEGFAULT
add $11, $8, $9
li $24, 4
mul $12, $11, $24
li $24, 8
add $13, $24, $12
lw $24, 0($sp)
move $25, $sp
add $25, $25, $13
sw $24, ($25)
L71:
lw $24, 32($sp)
li $25, 1
add $15, $24, $25
li $24, 0
li $25, 0
add $16, $24, $25
move $8, $16
li $24, 5
sub $8, $24, $15
li $24, 6
bge $8, $24, SEGFAULT
li $24, 0
blt $8, $24, SEGFAULT
add $10, $16, $8
li $24, 4
mul $11, $10, $24
li $24, 8
add $12, $24, $11
lw $24, 4($sp)
move $25, $sp
add $25, $25, $12
sw $24, ($25)
L80:
lw $24, 32($sp)
li $25, 1
add $14, $24, $25
sw $14, 32($sp)
j L22
L83:
lw $24, 36($sp)
li $25, 1
sub $8, $24, $25
sw $8, 36($sp)
j L19
L86:
.data
str3: .asciiz "Le tableau trie :\n"
.text
li $v0, 4
la $a0, str3
syscall
L87:
li $8, 0
sw $8, 36($sp)
L88:
lw $24, 36($sp)
li $25, 5
ble $24, $25, L90
j L106
L90:
.data
str4: .asciiz "t["
.text
li $v0, 4
la $a0, str4
syscall
L91:
lw $8, 36($sp)
li $v0, 1
move $a0, $8
syscall
L92:
.data
str5: .asciiz "] = "
.text
li $v0, 4
la $a0, str5
syscall
L93:
li $24, 0
li $25, 0
add $9, $24, $25
li $24, 5
lw $25, 36($sp)
sub $10, $24, $25
li $24, 6
bge $10, $24, SEGFAULT
li $24, 0
blt $10, $24, SEGFAULT
add $12, $9, $10
li $24, 4
mul $13, $12, $24
li $24, 8
add $14, $24, $13
move $24, $sp
add $24, $24, $14
lw $15, ($24)
li $v0, 1
move $a0, $15
syscall
L102:
.data
str6: .asciiz "\n"
.text
li $v0, 4
la $a0, str6
syscall
L103:
move $8, $16
lw $24, 36($sp)
li $25, 1
add $8, $24, $25
sw $8, 36($sp)
j L88

L106:

li $v0, 10
syscall
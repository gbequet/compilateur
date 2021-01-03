.data
newLine: .asciiz "\n"
segFaultWarning: .asciiz "Segmentation fault"

.text

SEGFAULT:
li $v0, 4
la $a0, segFaultWarning
syscall
j L17


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
li $24, 5
li $25, 5
add $8, $24, $25
li $24, 1
add $9, $8, $24
li $24, 6
li $25, 4
add $10, $24, $25
li $24, 1
add $11, $10, $24
bne $9, $11, L6
j L8
L6:
.data
str0: .asciiz "v"
.text
li $v0, 4
la $a0, str0
syscall
li $v0, 4
la $a0, newLine
syscall
j L9
L8:
.data
str1: .asciiz "f"
.text
li $v0, 4
la $a0, str1
syscall
li $v0, 4
la $a0, newLine
syscall
L9:
li $24, 5
li $25, 5
add $12, $24, $25
li $24, 6
li $25, 4
add $13, $24, $25
li $24, 1
add $14, $13, $24
bne $12, $14, L14
j L16
L14:
.data
str2: .asciiz "v"
.text
li $v0, 4
la $a0, str2
syscall
li $v0, 4
la $a0, newLine
syscall
j L17
L16:
.data
str3: .asciiz "f"
.text
li $v0, 4
la $a0, str3
syscall
li $v0, 4
la $a0, newLine
syscall

L17:

li $v0, 10
syscall

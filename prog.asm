.data
newLine: .asciiz "\n"
segFaultWarning: .asciiz "Segmentation fault"

.text

SEGFAULT:
li $v0, 4
la $a0, segFaultWarning
syscall
j L36


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
li $24, 1
li $25, 2
blt $24, $25, L4
j L2
L2:
li $24, 3
li $25, 4
blt $24, $25, L4
j L8
L4:
li $24, 5
li $25, 8
blt $24, $25, L6
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
li $24, 1
li $25, 2
blt $24, $25, L13
j L11
L11:
li $24, 3
li $25, 4
blt $24, $25, L13
j L17
L13:
li $24, 5
li $25, 8
bgt $24, $25, L15
j L17
L15:
.data
str2: .asciiz "v"
.text
li $v0, 4
la $a0, str2
syscall
li $v0, 4
la $a0, newLine
syscall
j L18
L17:
.data
str3: .asciiz "f"
.text
li $v0, 4
la $a0, str3
syscall
li $v0, 4
la $a0, newLine
syscall
L18:
li $24, 1
li $25, 2
bgt $24, $25, L22
j L20
L20:
li $24, 3
li $25, 4
blt $24, $25, L22
j L26
L22:
li $24, 5
li $25, 8
blt $24, $25, L24
j L26
L24:
.data
str4: .asciiz "v"
.text
li $v0, 4
la $a0, str4
syscall
li $v0, 4
la $a0, newLine
syscall
j L27
L26:
.data
str5: .asciiz "f"
.text
li $v0, 4
la $a0, str5
syscall
li $v0, 4
la $a0, newLine
syscall
L27:
li $24, 1
li $25, 2
bgt $24, $25, L31
j L29
L29:
li $24, 3
li $25, 4
blt $24, $25, L31
j L35
L31:
li $24, 5
li $25, 8
bgt $24, $25, L33
j L35
L33:
.data
str6: .asciiz "v"
.text
li $v0, 4
la $a0, str6
syscall
li $v0, 4
la $a0, newLine
syscall
j L36
L35:
.data
str7: .asciiz "f"
.text
li $v0, 4
la $a0, str7
syscall
li $v0, 4
la $a0, newLine
syscall

L36:

li $v0, 10
syscall

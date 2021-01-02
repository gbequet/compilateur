.data
newLine: .asciiz "\n"
segFaultWarning: .asciiz "Segmentation fault"

.text

SEGFAULT:
li $v0, 4
la $a0, segFaultWarning
syscall
j L56


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
blt $24, $25, L2
j L4
L2:
li $8, 1
sw $8, -1($sp)
j L5
L4:
li $8, 0
sw $8, -1($sp)
li $24, 3
li $25, 4
blt $24, $25, L7
j L9
li $24, 0
beq $8, $24, L11
li $24, 1
beq $8, $24, L13
li $24, 1
beq $8, $24, L11
li $24, 0
beq $8, $24, L13
L11:
.data
str0: .asciiz "v"
.text
li $v0, 4
la $a0, str0
syscall
li $v0, 4
la $a0, newLine
syscall
j L14
L13:
.data
str1: .asciiz "f"
.text
li $v0, 4
la $a0, str1
syscall
li $v0, 4
la $a0, newLine
syscall
L14:
li $24, 1
li $25, 2
bgt $24, $25, L16
j L18
L16:
li $11, 1
sw $11, -1($sp)
j L19
L18:
li $8, 0
sw $8, -1($sp)
li $24, 3
li $25, 4
blt $24, $25, L21
j L23
li $24, 0
beq $8, $24, L25
li $24, 1
beq $8, $24, L27
li $24, 1
beq $8, $24, L25
li $24, 0
beq $8, $24, L27
L25:
.data
str2: .asciiz "v"
.text
li $v0, 4
la $a0, str2
syscall
li $v0, 4
la $a0, newLine
syscall
j L28
L27:
.data
str3: .asciiz "f"
.text
li $v0, 4
la $a0, str3
syscall
li $v0, 4
la $a0, newLine
syscall
L28:
li $24, 1
li $25, 2
blt $24, $25, L30
j L32
L30:
li $11, 1
sw $11, -1($sp)
j L33
L32:
li $8, 0
sw $8, -1($sp)
li $24, 3
li $25, 4
bgt $24, $25, L35
j L37
li $24, 0
beq $8, $24, L39
li $24, 1
beq $8, $24, L41
li $24, 1
beq $8, $24, L39
li $24, 0
beq $8, $24, L41
L39:
.data
str4: .asciiz "v"
.text
li $v0, 4
la $a0, str4
syscall
li $v0, 4
la $a0, newLine
syscall
j L42
L41:
.data
str5: .asciiz "f"
.text
li $v0, 4
la $a0, str5
syscall
li $v0, 4
la $a0, newLine
syscall
L42:
li $24, 1
li $25, 2
bgt $24, $25, L44
j L46
L44:
li $11, 1
sw $11, -1($sp)
j L47
L46:
li $8, 0
sw $8, -1($sp)
li $24, 3
li $25, 4
bgt $24, $25, L49
j L51
li $24, 0
beq $8, $24, L53
li $24, 1
beq $8, $24, L55
li $24, 1
beq $8, $24, L53
li $24, 0
beq $8, $24, L55
L53:
.data
str6: .asciiz "v"
.text
li $v0, 4
la $a0, str6
syscall
li $v0, 4
la $a0, newLine
syscall
j L56
L55:
.data
str7: .asciiz "f"
.text
li $v0, 4
la $a0, str7
syscall
li $v0, 4
la $a0, newLine
syscall

L56:

li $v0, 10
syscall

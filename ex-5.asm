.data 
m_n : .asciiz "Please enter the number: "
m_r : .asciiz "The result is: "

.text

# print message for get the number
li $v0 , 4
la $a0 , m_n
syscall


# get the number
li $v0 , 5
syscall 
move $t0 , $v0


# initlize the register i need 
li $t1 , 1

# create case loop
loop:
	
	beq $t0 , 0 , print_result
	mul $t1 , $t1 , $t0
	addi $t0, $t0 , -1
	j loop
# print the result and exit programe
print_result:
	li $v0 , 4
	la $a0 , m_r
	syscall 
	
	li $v0 , 1
	move $a0, $t1
	syscall 
	
	li $v0 , 10
	syscall
	


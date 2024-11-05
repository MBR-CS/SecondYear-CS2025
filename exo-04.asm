.data
m_y: .asciiz "Please enter the y: "
m_x: .asciiz "Please enter the x: "
m_r : .asciiz "The result is: "


.text
# print message for get x
li $v0 , 4
la $a0 , m_x
syscall
# get x from user
li $v0 , 5
syscall
move $t0 , $v0 
# print message for get y
li $v0 , 4
la $a0 , m_y
syscall
# get y from user
li $v0 , 5
syscall
move $t1 , $v0 

# Initialize result
li $t2, 1            # $t2 = result = 1
li $t3, 0            # $t3 = counter = 0

loop:
    # Check if counter = y
    beq $t3, $t1, end_loop   # if counter == y, exit loop
    
    # Multiply result by x
    mul $t2, $t2, $t0        # result = result * x
    
    # Increment counter
    addi $t3, $t3, 1         # counter++
    
    # Repeat loop
    j loop
    
    
    
    
end_loop:
    # Print result message
    li $v0, 4
    la $a0, m_r
    syscall

    # Print result number
    li $v0, 1
    move $a0, $t2
    syscall


    # Exit program
    li $v0, 10
    syscall
    

.data
    prompt:     .asciiz "donner un nombre: "
    neg_msg:    .asciiz "\nle nombre est négatif"
    pos_msg:    .asciiz "le nombre est positif\n"
    zero_msg:   .asciiz "le nombre est nulle\n"

.text



    # Print prompt message
    li $v0, 4           # syscall code for print_string
    la $a0, prompt      # load address of prompt string
    syscall

    # Read integer from user
    li $v0, 5           # syscall code for read_int
    syscall
    move $t0, $v0       # save input number in $t0

    # Check if number is negative
    bltz $t0, negative  # if $t0 < 0, branch to negative
    bgtz $t0, positive  # if $t0 > 0, branch to positive
    beq $t0, $zero, zero_case    # if $t0 == 0, branch to zero_case

zero_case:
    li $v0, 4           # syscall code for print_string
    la $a0, zero_msg    # load address of zero message
    syscall
    j exit

negative:
    li $v0, 4           # syscall code for print_string
    la $a0, neg_msg     # load address of negative message
    syscall
    j exit

positive:
    li $v0, 4           # syscall code for print_string
    la $a0, pos_msg     # load address of positive message
    syscall

exit:
    li $v0, 10          # syscall code for exit
    syscall

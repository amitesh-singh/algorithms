.text

.globl _start

# exit(0)
_start:
mov $60, %rax # syscall is $60 for exit! wow!
mov $0, %rdi
syscall

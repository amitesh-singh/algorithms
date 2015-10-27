# Linux 32 bit x86 AT&T programming
# compile: as exit.s -o exit.o && ld -o exit exit.o
# as - Gas compiler

.text # text section started
.globl _start # 

_start:
movl $0, %ebx #exit(0)
movl $1, %eax # exit - syscall is 1
int $0x80 # interrupt call - superman comes to rescue ;)

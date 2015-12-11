.data

msg:
.ascii "Hello, ARM World!\n"
len = . - msg


.text

.globl _start
_start:
//         r0      r1                   r2
// write(int fd, const void *buf, size_t len);
/* write syscall */
mov %r0, $1 
ldr %r1, =msg 
ldr %r2, =len 
mov %r7, $4 /* syscall of write() goes to r7*/
swi $0 // software interrupt

//       r0
//exit(int ret);
/* exit syscall */
mov %r0, $0 
mov %r7, $1 
swi $0

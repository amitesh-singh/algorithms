how to setup arm dev environment on x86/x64 arch
------------------------------------------------
1. install gcc-5-arm-linux-gnueabi  libc6-dev-armel-cross
2. for binary run, install qemu-user-static

how to compile and run
-----------------------
$ arm-linux-gnueabi-as -o hello.o hello.s

$ arm-linux-gnueabi-ld -o hello hello.o

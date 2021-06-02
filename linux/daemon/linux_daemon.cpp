#include <iostream>

extern "C"
{
#include <unistd.h>
}

int main()
{
   //this is how you do it in easy way
   //but it's not POSIX compliant
   //it's part of glibc
   daemon(0, 0);
   while (1)
     {
        sleep(1);
        std::cout << "i am a daemon\n";
     }
   return 0;
}

#include <iostream>
#include <unistd.h>

int main()
{
   std::cout << "process id: " << getpid() << std::endl;
   std::cout << "parent id: " << getppid() << std::endl;

   return 0;
}

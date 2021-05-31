#include <iostream>
#include <unistd.h>
#include <sys/types.h>

int main()
{
   pid_t child_id;

   std::cout << "starting fork()\n";

   child_id = fork();

   if (child_id != 0)
     {
        std::cout << "This is parent: " << getpid() << std::endl;
        std::cout << "child id in parent is: " << child_id << std::endl;
     }
   else
     {
        //this is child since return value of fork() is zero
        std::cout << "This is child: " << getpid() << std::endl;
     }
   return 0;
}

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
   pid_t child_id;

   std::cout << "starting fork()\n";

   child_id = fork();

   if (child_id != 0)
     {
        //parent
        std::cout << "This is parent: " << getpid() << std::endl;
        std::cout << "child id in parent is: " << child_id << std::endl;
        std::cout << "waiting for the child to exit\n";
        waitpid(child_id, nullptr, 0);
     }
   else
     {
        //child
        //this is child since return value of fork() is zero
        std::cout << "This is child: " << getpid() << std::endl;
        exit(0);
     }
   return 0;
}

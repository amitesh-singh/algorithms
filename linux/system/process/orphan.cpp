#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <iostream>

int main()
{
   pid_t pid;

   if ((pid = fork()) < 0)
     {
        perror("fork");
        exit(1);
     }

   if (pid > 0)
     {
        std::cout << "parent is exiting.." << getpid() << std::endl;
        exit(0);
     }
   sleep(100);
   //child is now orphan.
   // now systemd will own this instead

   std::cout << "exiting " << getpid() << std::endl;
   return 0;
}

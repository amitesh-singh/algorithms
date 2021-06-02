#include <iostream>

extern "C"
{
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
}

int main()
{
   pid_t pid;
   std::cout << "going to be a daemon soon\n";

   pid = fork();
   if (pid == -1) return -1;
   //exit from parent
   if (pid != 0)
     exit(EXIT_SUCCESS);

   std::cout << "closing all descriptors\n";
   //can use sysconf(_SC_OPEN_MAX)
   for (int i = 0; i < 1024; ++i)
     close(i);

   //create new session and process group
   setsid();
   //this redirects to stdin 0
   open("/dev/null", O_RDWR);
   dup(0); // 0 is now mapped to 1
   dup(0);// 0 is not mapped to 2

   while (1)
     {
        pause();
     }


   return 0;

}

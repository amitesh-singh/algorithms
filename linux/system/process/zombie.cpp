#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
//refer to this: https://stackoverflow.com/questions/25172425/create-zombie-process

int main()
{
   pid_t pid;

   if ((pid = fork()) < 0)
     {
        perror("fork");
        exit(0);
     }

   //child exits first
   if (pid == 0)
     {
        exit(0);
        //child will become defunct, and wait for either parent to exit
     }

   sleep(100);

   return 0;
}

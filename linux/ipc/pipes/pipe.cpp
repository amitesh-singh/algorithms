#include <iostream>

extern "C"
{
#include <unistd.h>
#include <sys/wait.h>
}

int main()
{
   int fd[2];
   pid_t pid;

   //fd[0] -> reading
   // fd[1] -> writing
   if (pipe(fd) < 0)
     {
        perror("unable to create pipes\n");
     }
   if ((pid = fork()) < 0) //error occurs
     {
        perror("fork error");
     }
   else if (pid != 0)
     {
        //parent
        close(fd[0]);
        std::cout << "parent: " << getpid() << ": writing to child:" << std::endl;
        write(fd[1], "hey child", 10);
        close(fd[1]);
        if (waitpid(pid, NULL, 0) < 0)
          perror("waitpid shit");
        exit(0);
     }
   else
     {
        sleep(10);
        char buf[1024];
        //child
        close(fd[1]);
        read(fd[0], buf, sizeof(buf));
        std::cout << "child: " << getpid() << ":" <<  buf << std::endl;
        close(fd[0]);
     }

   return 0;
}


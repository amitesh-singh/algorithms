#include <iostream>
//sigaction is preferred since it's better
// while handling multiple signals at a time, sigaction gaurantees that
// a recieved signal hanlder will be processed before.

extern "C"
{
#include <signal.h>
#include <unistd.h>
}

//on terminal,do kill -USR1 <processid>
void _sig_usr(int sig)
{
   //using write() since it's signal safe
   //man async-signal
   if (sig == SIGUSR1)
     write(2, "got SIGUSR1\n", 12);
}

int main()
{
   signal(SIGUSR1, _sig_usr);

   while(1)
     {
        pause();
     }

   return 0;
}

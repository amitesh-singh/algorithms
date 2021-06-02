#include <iostream>

extern "C"
{
#include <signal.h>
#include <unistd.h>
}

volatile sig_atomic_t flag;

void _sig_handler(int sig)
{
   if (sig == SIGTERM)
     write(1, "got SIGTERM\n", 13);
   else if (sig == SIGINT)
     write(1, "got SIGINT\n", 12);
}

int main()
{
   struct sigaction handler;
   handler.sa_handler = _sig_handler;

   sigaction(SIGTERM, &handler, NULL);
   sigaction(SIGINT, &handler, NULL);

   while (1) pause();
   return 0;
}


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int signo)
{
  write(1, "signal: ", 9);
  write(1, &signo, 4);
}

int main()
{
  sigset_t set, oset, pset;
  struct sigaction handler;
  handler.sa_handler = handle_sigint;

  sigaction(SIGINT, &handler, NULL);

  sigemptyset(&set);
  sigaddset(&set, SIGINT);
  //block the signal SIGINT, it won't be entertained at all.
  sigprocmask(SIG_BLOCK, &set, &oset);
  printf("old set was %8.8ld.\n", pset);

  sigpending(&pset);
  printf("Pending set was %8.8ld.\n", pset);
  //int x = 1;
  //write(1, &x, 4);
  kill(getpid(), SIGINT); 
  sigpending(&pset);
  printf("Pending set was %8.8ld.\n", pset);
  //unblock the signal, SIGINT
  sigprocmask(SIG_UNBLOCK, &set, &oset);
  
  return 0;
}
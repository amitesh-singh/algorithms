#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *_thread1_func(void *d)
{
  int *iptr = malloc(sizeof (int));
  *iptr = 10;
  printf("Thread number: %ld\n", pthread_self());
  int val = *(int *)d;
  printf("val1: %d\n", val);
  (*iptr)++;

  return iptr;
}

int main()
{
  pthread_t t1, t2;
  int *ret1, ret2;
  int val1 = 10;
  int val2 = 12;

  pthread_create(&t1, NULL, _thread1_func, (void *)&val1);

  pthread_join(t1, &ret1);

  printf("thread1 returns: %d\n", *ret1);
  free(ret1);

  return 0;
}

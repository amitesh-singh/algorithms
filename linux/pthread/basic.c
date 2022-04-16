#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *_thread1_func(void *d)
{
  printf("Thread number: %ld\n", pthread_self());
  int val = *(int *)d;
  printf("val1: %d\n", val);
}

int main()
{
  pthread_t t1, t2;
  int ret1, ret2;
  int val1 = 10;
  int val2 = 12;

  ret1 = pthread_create(&t1, NULL, _thread1_func, (void *)&val1);
  ret2 = pthread_create(&t2, NULL, _thread1_func, (void *)&val2);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("thread1 returns: %d\n", ret1);
  printf("thread2 returns: %d\n", ret2);

  return 0;
}
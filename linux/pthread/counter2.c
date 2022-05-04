#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//or use pthread_mutex_init(&m1, NULL);
//pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m1;
int counter = 0;

void *_thread1_func(void *d)
{
  printf("Thread number: %ld\n", pthread_self());

  pthread_mutex_lock(&m1);
  
  counter++;
  printf("Counter: %d\n", counter);

  pthread_mutex_unlock(&m1);
}

int main()
{
  pthread_t t1, t2;
  int ret1, ret2;

  pthread_mutex_init(&m1, NULL);

  ret1 = pthread_create(&t1, NULL, _thread1_func, NULL);
  ret2 = pthread_create(&t2, NULL, _thread1_func, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("thread1 returns: %d\n", ret1);
  printf("thread2 returns: %d\n", ret2);

  return 0;
}

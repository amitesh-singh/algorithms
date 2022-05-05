#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>


sem_t sem;

void *task(void *d)
{
   int i = (int)d;

   sem_wait(&sem);

   sleep(1);
   printf("tsk = %d\n", i);

   sem_post(&sem);
}

int main()
{
   pthread_t t[3];

   sem_init(&sem, 0, 1);

   for (int i = 0; i < 3; ++i)
     {
        if (pthread_create(&t[i], NULL, task, (void *)i) < 0)
          {
             perror("pthread");
             continue;
          }
     }
   for (int i = 0; i < 3; ++i)
     {
        pthread_join(t[i], NULL);
     }

   sem_destroy(&sem);
   return 0;
}

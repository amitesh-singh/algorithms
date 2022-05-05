#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>

sem_t sem;

void *func(void *d)
{
	sem_wait(&sem);
	printf("Entered\n");
	sleep(4);
	sem_post(&sem);
}

int main()
{
	pthread_t t;
	//(0, 1) --> no post required 
	sem_init(&sem, 0, 0);
	if (pthread_create(&t, NULL, func, NULL) < 0) {
		perror("pthread");
		exit(-1);
	}

	sem_post(&sem);
	pthread_join(t, NULL);

	sem_destroy(&sem);

	return 0;
}

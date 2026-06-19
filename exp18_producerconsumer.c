#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
sem_t empty, full;

void* producer(void* arg)
{
    printf("Producer Running\n");
    return NULL;
}

void* consumer(void* arg)
{
    printf("Consumer Running\n");
    return NULL;
}

int main()
{
    pthread_t p,c;

    sem_init(&empty,0,BUFFER_SIZE);
    sem_init(&full,0,0);

    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);

    pthread_join(p,NULL);
    pthread_join(c,NULL);

    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

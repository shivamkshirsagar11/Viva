#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#define bs 5
#define mi 5
sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[bs];

void * producer(void *pno){
int item;
for (int i = 0;i<mi; i++){
item = rand()%mi;
sem_wait(&empty);
buffer[in] = item;
printf("Producer %d: insert item %d at %d\n",*((int *)pno),buffer[in],in);
in = (in +1)%bs;
sem_post(&full);
}
}

void * consumer(void *cno){
int item;
for (int i = 0;i<mi; i++){
item = buffer[out];
sem_wait(&full);
buffer[out] = item;
printf("Consumer %d: Remove item %d from %d\n",*((int *)cno),item,out);
out= (out +1)%bs;
sem_post(&empty);
}
}

void main (int cnt, char ** args){
    pthread_t pro[5],con[5];
    sem_init(&empty,0,bs);
    sem_init(&full,0,0);

    int a[5] = {1,2,3,4,5};

    for(int i = 0; i < 5; i++) {
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(con[i], NULL);
    }
    sem_destroy(&empty);
    sem_destroy(&full);
}
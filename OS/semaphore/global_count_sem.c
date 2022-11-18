#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

int count = 0;
sem_t s1;
void * printHello(){
sem_wait(&s1);
printf("Count Global Variable: %d\n",count);
count++;
sem_post(&s1);
}

void main(){
pthread_t t1,t2,t3,t4,t5;
	sem_init(&s1,0,1);
	pthread_create(&t1,NULL,printHello,NULL);
	pthread_create(&t2,NULL,printHello,NULL);
	pthread_create(&t3,NULL,printHello,NULL);
	pthread_create(&t4,NULL,printHello,NULL);
	pthread_create(&t5,NULL,printHello,NULL);
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);
	pthread_join(t5,NULL);
	
	
	/*
	pthread_create(&t1,NULL,printHello,NULL);
	pthread_join(t1,NULL);
	pthread_create(&t2,NULL,printHello,NULL);
	pthread_join(t2,NULL);
	pthread_create(&t3,NULL,printHello,NULL);
	pthread_join(t3,NULL);
	pthread_create(&t4,NULL,printHello,NULL);
	pthread_join(t4,NULL);
	pthread_create(&t5,NULL,printHello,NULL);
	pthread_join(t5,NULL);
	*/
}   
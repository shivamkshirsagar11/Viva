#include <pthread.h>
#include <stdio.h>
int count = 0;
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;

void * printHello(){

pthread_mutex_lock(&m1);
printf("Count Global Variable: %d\n",count);
count++;
pthread_mutex_unlock(&m1);
}

void main(){
pthread_t t1,t2,t3,t4,t5;
	
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
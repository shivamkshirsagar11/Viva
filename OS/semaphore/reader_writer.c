#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#define bs 5
#define mi 3
sem_t x;
sem_t write;
int reader_cnt = 0,read_i=0,write_i=0;
int buffer[bs];

void READUNIT(int reader_no){
int item = buffer[read_i];
printf("Reader %d on buffer index %d, item %d\n",reader_no,read_i,item);
read_i = (read_i + 1) % bs;
}

void WRITEUNIT(int writer_no){
int to_write = rand()%11;
int item = buffer[write_i];
buffer[write_i] = to_write;
printf("Writer %d replacing %d with %d on index %d\n",writer_no,item,to_write,write_i);
write_i = (write_i + 1) % bs;
}
void * reader(void *pno){
for(int i = 0;i<mi;i++){
sem_wait(&x);
reader_cnt++;
if(reader_cnt == 1) sem_wait(&write);
sem_post(&x);
READUNIT(*((int *)pno));
sem_wait(&x);
reader_cnt--;
if(reader_cnt == 0) sem_post(&write);
sem_post(&x);
}
}

void * writer(void *cno){
for (int i = 0;i<mi; i++){
sem_wait(&write);
WRITEUNIT(*((int *)cno));
sem_post(&write);
}
}

void main (int cnt, char ** args){
    pthread_t read[5],write_t[5];
    sem_init(&x,0,1);
    sem_init(&write,0,1);
	
printf("In main function\n");
    int a[5] = {1,2,3,4,5};

    for(int i = 0; i < 5; i++) {
        pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&write_t[i], NULL, (void *)writer, (void *)&a[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(read[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(write_t[i], NULL);
    }
    sem_destroy(&x);
    sem_destroy(&write);
}
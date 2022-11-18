#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student{
char * name,*CGPA;
int sem;
};
void * printStudent(void * student){
struct Student * s1 = (struct Student *)student;
printf("Inside Thread\nname: %s\nsem: %d\nCGPA: %s\n",s1->name,s1->sem,s1->CGPA);
}
void main(int cnt, char ** args){
struct Student s1 = {.name = args[1],.sem = atoi(args[2]),.CGPA = args[3]};
pthread_t t1;
int t1r = pthread_create(&t1,NULL,printStudent((void *)&s1),NULL);
if(!t1r){
pthread_join(t1,NULL);
printf("Thread created Successfully :-)\n");
}
else{
printf("Error on creating Thread :-(\n");
}
}
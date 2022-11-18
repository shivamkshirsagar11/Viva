#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include <dirent.h>
void main(int argc, char** argv){
pid_t q = fork();
//pid_t p = fork();
//printf("hello, World!\n");
//first trial
//new activity
if (q > 0){printf("I am parent!\n");
q = fork();
printf("id: %d\n",q);
}
else if (q == 0){printf("I am Child!\n");}
else if (q < 0){printf("Failed to create child!\n");}
}
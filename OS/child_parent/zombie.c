#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include <dirent.h>
void main(int argc, char** argv){
pid_t q = fork();
if (q > 0){printf("I am parent!\n");
pid_t parent = getpid();
printf("parent id : %d\nnow getting sleepy...\n",parent);
sleep(1);
printf("I a woke up now: Parent");
}
else if (q == 0){printf("I am Child!\n");
pid_t parent = getpid();
pid_t child = getppid();
printf("parent id: %d\n",parent);
printf("child with parent id: %d\n",child);
//sleep(3);
//printf("hello i am child!");
}
else if (q < 0){printf("Failed to create child!\n");}
}
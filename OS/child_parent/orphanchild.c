#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include <dirent.h>
#include <sys/wait.h>
void main(int argc, char** argv){
pid_t q = fork();
	if (q > 0){
		printf("I am parent!\n");
		pid_t parent = getpid();
		printf("parent id : %d\nParent waits now...",parent);
		wait(NULL);
		printf("Parent wait over!!\n");
	}
	else if (q == 0){
		printf("I am Child!\n");
		pid_t child= getpid();
		pid_t parent= getppid();
		printf("i am child my parent id: %d\n",parent);
		printf("i m child with parent id: %d\nnow getting sleepy...\n",child);
		sleep(3);
		printf("hello i am child!\n");
	}
	else if (q < 0){
	printf("Failed to create child!\n");
	}
}
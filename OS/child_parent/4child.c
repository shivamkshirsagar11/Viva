#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include <dirent.h>
#include <sys/wait.h>
void main(int argc, char** argv){
pid_t q = fork();
if (q > 0)
{
	printf("------------PARENT-------------\n");
	pid_t parent = getpid();
	printf("PARENT_ID: %d\n",parent);
	q = fork();
	wait(NULL);
	if (q > 0)
	{	
		q = fork();
		wait(NULL);
		if (q > 0)
		{
			q = fork();
			wait(NULL);
			if (q == 0)
			{
				printf("-------------CHILD------------\n");
				pid_t child = getpid();
				pid_t parent = getppid();
				printf("PARENT_ID: %d\nCHILD_ID: %d\n",parent,child);
			}
		
		}
		else if (q == 0)
		{
			printf("-------------CHILD------------\n");
			pid_t child = getpid();
			pid_t parent = getppid();
			printf("PARENT_ID: %d\nCHILD_ID: %d\n",parent,child);
		}
	}
	else if (q == 0)
	{
	printf("-------------CHILD------------\n");
		pid_t child = getpid();
		pid_t parent = getppid();
		printf("PARENT_ID: %d\nCHILD_ID: %d\n",parent,child);
	}	
	}
else if (q == 0)
	{
		printf("-------------CHILD------------\n");
		pid_t child = getpid();
		pid_t parent = getppid();
		printf("PARENT_ID: %d\nCHILD_ID: %d\n",parent,child);
	}
else
	{
	printf("Failed to create child!\n");
	}
}
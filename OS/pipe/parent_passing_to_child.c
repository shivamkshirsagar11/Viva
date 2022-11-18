#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
void main(int cnt, char ** args)
{
	int len = strlen(args[1]);
	int datafd[2];
	int pip = pipe(datafd);
	int p =  fork();
	if(pip != -1)
	{
		if(p>0)
		{
			close(datafd[0]);
			write(datafd[1],args[1],len);
			wait(NULL);
		}
		if(p==0)
		{
			close(datafd[1]);
			char temp[len];
			read(datafd[0],temp,len);
			int fd = open(temp,O_RDONLY);
			if(fd>0)
			{
				char tempdata[1000];
				read(fd,tempdata,sizeof(tempdata));
				printf("content of file...\n%s\n",tempdata);
			}
			else
			{
				printf("Error opening file: %s\n",temp);
			}
		}
	}
	else
	{
		printf("Error creating pipe...:-(\n");
	}
}
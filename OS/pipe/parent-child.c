#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
void main(int cnt, char ** args){
int len = strlen(args[1]);
//printf("message: %s\n",args[1]);
int datafd[2];
int pip = pipe(datafd);
int p =  fork();
if(pip != -1){
if(p>0){
close(datafd[0]);
printf("PARENT ID: %d\n",getpid());
write(datafd[1],args[1],len);
wait(NULL);
}
if(p==0){
printf("I am child\nPARENT ID: %d\n",getppid());
printf("CHILD ID: %d\n",getpid());
close(datafd[1]);
char temp[len];
read(datafd[0],temp,len);
printf("Message from child: %s\n",temp);
}
}
else{
printf("Error creating pipe...:-(\n");
}
}
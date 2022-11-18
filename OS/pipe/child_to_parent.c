#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
void main(int cnt, char ** args){
int len = strlen(args[1]);
//printf("message: %s\n",args[1]);
int datafd[2];
int pip = pipe(datafd);
int datafd2[2];
int pip2 = pipe(datafd2);
int p =  fork();
if(pip != -1 && pip2 != -1){
if(p>0){
close(datafd[0]);
close(datafd2[1]);
write(datafd[1],args[1],len);
wait(NULL);
char temp[1000];
read(datafd2[0],temp,sizeof(temp));
printf("content of file from parent\n%s\n",temp);
}
if(p==0){
close(datafd[1]);
close(datafd2[0]);
char temp[len];
read(datafd[0],temp,len);
int fd = open(temp,O_RDONLY);
if(fd>0){
char tempdata[1000];
int read_byte = read(fd,tempdata,sizeof(tempdata));
write(datafd2[1],tempdata,read_byte);
//printf("content of file...\n%s\n",tempdata);
}
else{
printf("Error opening file: %s\n",temp);
}
}
}
else{
printf("Error creating pipe...:-(\n");
}
}
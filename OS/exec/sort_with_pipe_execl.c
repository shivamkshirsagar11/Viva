#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(int cnt, char ** args){
int arr[2];
int p = pipe(arr);
int q = fork();
if(p>0){
if (q>0){
close(arr[1]);
printf("Parent process\n");
dup2(arr[0],0);
execl("/bin/sort","sort",NULL);
}
if (q==0){
close(arr[0]);
dup2(arr[1],1);
execl("/bin/ls","pwd",NULL);
}
}
else{
printf("error\n");
}
}
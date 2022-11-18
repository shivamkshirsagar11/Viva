#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(int cnt, char ** args){
printf("before execl fxn call\n");
execl("/bin/ls","ls","-l",NULL);
printf("after execl fxn call\n");
}
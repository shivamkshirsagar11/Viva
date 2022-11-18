#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
void main(int argc, char** argv){
char file1[1000],*path;
path = getcwd(file1,sizeof(file1));
printf("%s\n",path);
}

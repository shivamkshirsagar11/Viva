#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
void main(int argc, char** argv){
char file[1000];
for(int i=argc-1;i>0;i--){
int fd1 = open(argv[i],O_RDONLY);
int fd2 = read(fd1,file,sizeof(file));
write(1,file,fd2);
}
}
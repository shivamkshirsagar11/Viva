#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
void main(int argc, char** argv){
char file[1000];
int file_1 = open(argv[1],O_RDONLY);
int file_2 = open(argv[2],O_WRONLY | O_CREAT,S_IRWXU);
int file1_read = read(file_1,file,sizeof(file));
write(file_2,file,file1_read);
}

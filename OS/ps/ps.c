#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include<stdlib.h>
#include <string.h>	
void main(int count, char **args){
DIR * dir_ptr = opendir(args[1]);
//char paths[1000];
struct dirent *dir_data = NULL;
if(dir_ptr){
	printf("Directory %s opened\n---------------\n",args[1]);
	dir_data = readdir(dir_ptr);
	while(dir_data){
		if(atoi(dir_data->d_name)>0){
				//printf("%s ",dir_data->d_name);
				char temp1[100]={},temp2[7]={},pid[20]={},pname[100]={};
				strcpy(temp1,"/proc/");
				strcpy(temp2,"/stat");
				strcat(temp1,dir_data->d_name);
				strcat(temp1,temp2);
				FILE * fp = fopen(temp1,"r");
				fscanf(fp,"%s %s",pid,pname);
				printf("PID: %s\nPName:%s\n---------------\n",pid,pname);
				//printf("%s\n",temp1);
				}
		dir_data = readdir(dir_ptr);
			}
	  }
else{
	printf("Error opening Directory %s\n",args[1]);
    }
}
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ls_recursive(DIR * dir,char *cur_dir){
if(dir){
struct dirent *ddata = readdir(dir);
if(ddata){
    if(ddata->d_type == 4){
        if((int)(*ddata->d_name) != '.'){
            printf("%s\t",ddata->d_name);
            printf("\nDirectory %s opened\n",ddata->d_name);
            char t1[1000]="",* t2 = ddata->d_name;
            strcat(t1,cur_dir);
            strcat(t1,"/");
            strcat(t1,t2);
            DIR * dptr = opendir(t1);
            if(dptr){
            ls_recursive(dptr,t1);
            }
            else{printf("error on further going in dir: %s\n",ddata->d_name);}
        }
        else{
        ls_recursive(dir,cur_dir);
        }
    }
    else{
        printf("%s\t",ddata->d_name);
        ls_recursive(dir,cur_dir);
    }
}
}
}

void main(int cnt, char ** args){
DIR * dptr = opendir(args[1]);
struct dirent * data = NULL;
if(dptr){
printf("Directory %s opened\n",args[1]);
ls_recursive(dptr,args[1]);
data = readdir(dptr);
closedir(dptr);
printf("\n");
}
else{
printf("failed to open %s directory\n",args[1]);
}
}
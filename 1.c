#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main()
{
 char a[10] = "Hi,bro";
 char item[200];

 printf("%p\n",a);
 
 FILE *where;
 int wh;
 char path[20],*p;

 
 pid_t pid;
 pid = getpid();

 printf("my pid = %d\n",pid);
 sprintf(path,"/proc/%d/maps",pid);
 printf("path:%s\n",path);
 
 where = fopen(path,"r");
 while(!feof(where))
 {
 fscanf(where,"%s\n",item);
 printf("%s\n",item);
 }
 fclose(where);
 return 0;
}

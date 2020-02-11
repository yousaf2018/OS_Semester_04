#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc,char **argv)
{
  int n,fileDiscip[2];
  pid_t pid;
  char line[100];
  if(pipe(fileDiscip)<0)
  {
    printf("Error in creating pipe for communication\n");
  }
  if((pid=fork())<0)
  {
    printf("Error in creating new child process\n");
  }
  if(pid>0)
  {
    int x=wait(NULL);
    close(fileDiscip[1]);
    read(fileDiscip[0],line,100);
    printf("Parent process id %d with %s\n",getpid(),line);
  }
  else
  {
    close(fileDiscip[0]);
    write(fileDiscip[1],"Message from Child",19);
    printf("Child process id %d\n",getpid());
  }
}

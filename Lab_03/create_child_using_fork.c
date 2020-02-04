#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int
main(int argc, char *argv[])
{
 printf("hello world (pid:%d)\n", (int) getpid());
 int rc = fork();
 if (rc < 0) {
 // fork failed; exit
 fprintf(stderr, "fork failed\n");
 exit(1);
 } else if (rc == 0) {
 // child (new process)
 printf("hello, I am child (pid:%d)\n", (int) getpid());
 printf("hello, I am child (ppid:%d)\n", (int) getppid());
 while(1)
 {
   printf("i am in child process in infinite loop\n");
 }
 } else {
 // parent goes down this path (original process)
 printf("hello, I am parent of %d (pid:%d)\n",
 rc, (int) getpid());
 printf("hello, I am parent of %d (ppid:%d)\n",
 rc, (int) getppid());
 while(1)
 {
   printf("i am in parent process in infinite loop\n");
 }
 }
 return 0;
}

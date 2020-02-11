#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
 printf("hello world (pid:%d)\n", (int) getpid());
 int rc = fork();
 if (rc < 0) {
 // fork failed; exit
 fprintf(stderr, "fork failed\n");
 exit(1);
 } else if (rc == 0) {
 // child (new process)
 printf("hello, I am child and fully executed before parent process (pid:%d)\n", (int) getpid());
sleep(1);
 } else {
 // parent goes down this path (original process)
 int wc = wait(NULL);
 printf("hello, I am parent of and i am procesing after child process with  %d (wc:%d) (pid:%d)\n",
 rc, wc, (int) getpid());
 }
 return 0;
}

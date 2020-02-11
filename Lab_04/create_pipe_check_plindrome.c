#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
void isPalindrome(char str[])
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = strlen(str) - 1;

    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            printf("%s is Not Palindrome\n", str);
            return;
        }
    }
    printf("%s is palindrome\n", str);
}
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
    char palind[20];
    printf("Enter word to check palindrome\n");
    gets(palind);
    close(fileDiscip[0]);
    write(fileDiscip[1],palind,20);
  }
  else
  {
    close(fileDiscip[1]);
    read(fileDiscip[0],line,100);
    isPalindrome(line);
    printf("I am child process i done my work\n");
    printf("Child process id %d\n",getpid());
  }
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
int isPalindrome(char str[])
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = strlen(str) - 1;

    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
          //  printf("%s is Not Palindrome\n", str);
            return 0;
        }
    }
  //  printf("%s is palindrome\n", str);
    return 1;
}
int main(int argc,char **argv)
{
  int n,fileDiscip1[2],fileDiscip2[2];
  pid_t pid;
  char line[100];
  if(pipe(fileDiscip1)<0)
  {
    printf("Error in creating pipe for communication\n");
  }
  if(pipe(fileDiscip2)<0)
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
    close(fileDiscip1[0]);
    write(fileDiscip1[1],palind,20);
    close(fileDiscip2[1]);
    read(fileDiscip2[0],line,100);
    printf("%s\n",line);
  }
  else
  {
    int check;
    close(fileDiscip1[1]);
    read(fileDiscip1[0],line,100);
    check=isPalindrome(line);
    if(check==0)
    {
      close(fileDiscip2[0]);
      write(fileDiscip2[1],"No",3);
    }
    else
    {
      close(fileDiscip2[0]);
      write(fileDiscip2[1],"Yes",4);
    }
  }
}

#include <stdio.h>

int main()
{
 
  int count = 10;
  char* p = "aaaaaaaabbb";
  while(count--)
  {
    printf("%s\r",p);
    fflush(stdout);
    sleep(1);
  }
  printf("hello word\n");

  return 0;
}

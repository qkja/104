#include<stdio.h>

union DE
{
  char i;
  int a;
}d;

int main()
{
  d.a = 1;
  if(d.i==1)
  {
    printf("小端\n");
  }
  else 
  {
    printf("大端\n");
  }
  return 0;
}

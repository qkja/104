#include <stdio.h>

int func(int x)
{
  int sum = 0;
  int i = 0;
  for(;i<x;i++)
  {
    sum+=i;
  }
  return sum;
}
int main()
{
  int ret = func(100);
  printf("%d\n",ret);
  return 0;
}

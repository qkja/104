#include<stdio.h>
#include<stdlib.h>
int main()
{
  int* p = (int*)malloc(16);
  if(p!=NULL)
  {
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
  }
  int i = 0;
  for(;i<4;i++)
  {
    printf("%d ",p[i]);
  }
  free(p);
  p = NULL;
  return 0;
}

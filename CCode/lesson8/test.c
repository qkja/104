#include "mytest.h"

int main()
{
  int x = 0;
  int y = 0;
  scanf("%d %d",&x,&y);
  printf("%d\n",Add(x,y));
  printf("%d\n",Sub(x,y));
  printf("%d\n",Div(x,y));
  printf("%d\n",Mul(x,y));

  return 0;
}

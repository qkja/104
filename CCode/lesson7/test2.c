#include <stdio.h>

struct A
{
	int _a ;
	int _b : 5;
	int _c : 10;
	int _d : 30;
};

/*int main()
{
 // printf("%d\n",sizeof(struct A));
  return 0;
}*/



int myTest(const char* str)
{

  return 0;
}

int main()
{
  const char* p = "Hello,bit";
  int (*pf)(const char*) = myTest;
  int ret = (*pf)(p);
  printf("%d\n",ret);

  return 0;
}

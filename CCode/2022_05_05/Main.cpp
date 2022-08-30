//#include "test.h"

/*int main()
{
  func(10,2.20);
  return  0;
}*/

#include <iostream>
#include <stdio.h>
using namespace std;

#ifdef __cplusplus
extern "C"
{
#endif 

	void func(int a, int b)
	{
		printf("C : %d %d\n", a, b);
	}

#ifdef __cplusplus
}
#endif 

void func(double a, int b)
{
	printf("C++: %lf %d\n", a, b);
}

int main()
{
	func(1, 2);
	func(1.11, 2);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#ifdef __cplusplus
extern "C"
{
#endif 

	void func(int a, int b)
	{
		printf("C : %d %d\n", a, b);
	}

	void func(double a, int b)
	{
		printf("C : %lf %d\n", a, b);
	}

#ifdef __cplusplus
}
#endif 


int main()
{
	func(1, 2);
	//func(1.11, 2);
	return 0;
}
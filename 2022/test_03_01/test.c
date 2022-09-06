#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
int func(char* str,int len)
{
	assert(str);

}
int main()
{
	char* arr = "abcd defr";
	int len = strlen(arr);
	int ret = func1(arr, len);
	return 0;
}
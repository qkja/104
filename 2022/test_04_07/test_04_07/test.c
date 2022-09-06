#define _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <assert.h>
#include <string.h>

void reserve(char * s)
{
	assert(s);
	int len = strlen(s);
	char ret = s[0];
	s[0] = s[len - 1];
	s[len - 1] = ret;
}
//ab
//abc
//bca
//cab
//abc

bool rotateString(char * s, char * goal){
	assert(s && goal);
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		//½»»»Ò»¸ö
		reserve(s);
		if (strcmp(s, goal) == 0)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	char arr1[4] = "abc";
	char arr2[4] = "cab";
	rotateString(arr1, arr2);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>

void fun(int arr[]) 
{
	arr[0] = 2;
}
int main()
{
	int arr[] = { 1, 2, 3, 4 };
	fun(arr);
	return 0;
}
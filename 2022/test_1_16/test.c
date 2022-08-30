#define _CRT_SECURE_NO_WARNINGS 1

//
//#include<stdio.h>

#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void My_reversal(char arr[], int sz)
{
	if (arr == NULL)
	{
		return;
	}
	char* left = arr;
	char* right = arr + sz - 1;
	while (left < right)
	{
		char ret = *left;
		*left = *right;
		*right = ret;
		left++;
		right--;
	}
}

int Judg_same(char arr1[], char arr2[])
{
	int sz1 = strlen(arr1);
	int sz2 = strlen(arr2);
	if (sz1 == sz2)
	{
		for (int i = 0; i < sz1; i++)
		{
			if (arr1[i] != arr2[i])
			{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

int Judg_reversal(char arr1[], char arr2[])
{

	int sz = strlen(arr1);
	char* p = (char*)malloc(sz + 1);
	for (int i = 0; i <= sz; i++)
	{
		p[i] = arr1[i];
	}
	for (int i = 1; i < sz; i++)
	{
		My_reversal(arr1, i);
		My_reversal(arr1 + i, sz - i);//ADCBA  ABCDA
		My_reversal(arr1, sz);

		if (Judg_same(arr1, arr2) == 1)
		{
			free(p);
			p = NULL;
			return 1;
		}
		for (int j = 0; j <= sz; j++)
		{
			arr1[j] = p[j];
		}
	}

	free(p);
	p = NULL;
	return 0;
}

//int main()
//{
//	char arr1[] = "AABCD";//ADCBA   ABCDA AADCB  BCDAA
//	char arr2[] = "DAABC";
//	int ret = Judg_reversal(arr1,arr2);
//	printf("%d", ret);
//	return 0;
//}

//int main()
//{
//	printf("%d", Judg_same("abc", "abc"));
//	return 0;
//}

//int main()
//{
//	char arr1[10] = { 0 };
//	char arr2[10] = { 0 };
//	Judg_reversal(arr1,arr2);
//	return 0;
//}

//int main()
//{
//	int* p = NULL;
//	int arr[10] = { 0 };
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	//int** pp = &(&a);
//
//
//	/*char* p = "abcd";
//	char* p1 = "abcd";
//	p = "bfed";*/
//	//*p = 'a';
//	/*if (p1 == p)
//	{
//		printf("hehe");
//	}*/
//	/*char* p = "abcde";
//	p = "bcd";
//	printf("%s\n", p);
//	printf("%s", ++p);*/
//	/*int arr[10] = { 1,2,3,4,5 };
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *(arr + i));
//	}*/
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	//int* pp = &arr;
//	int(*p)[10] = &arr;
//	return 0;
//}
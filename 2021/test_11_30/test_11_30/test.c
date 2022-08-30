#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>
#include<string.h>

void resver(char* pa)
{
	assert(pa);
	int len = strlen(pa);
	for (int i = 0; i < len / 2; i++)
	{
		//abcde
		char temp = pa[i];
		pa[i] = pa[len - 1 - i];
		pa[len - 1 - i] = temp;
	}
}

int two_max(int x, int y)
{
	return x > y ? x : y;
}

char* add(char *pa, char*pb)
{
	assert(pa&&pb);
	int len_a = strlen(pa);
	int len_b = strlen(pb);

	resver(pa);
	resver(pb);
	int cath = 0;
	int j = 0;
	int ret = two_max(len_a, len_b);
	char* ans = (char*)malloc(sizeof(char)*(ret + 2));
	for (int i = 0; i < ret; i++)
	{
	
		cath += i < len_a ? (pa[i] == '1') : 0;
		cath += i < len_b ? (pb[i] == '1') : 0;
		ans[j++] = cath % 2 + '0';
		cath /= 2;
	}
	if (cath != 0)
	{
		ans[j++] = '1';
	}
	ans[j] = '\0';

	resver(ans);
	return ans;


}
//
//int main()
//{
//	
//	char arr1[10] = { 0 };
//	char arr2[10] = { 0 };
//	gets(arr1);
//	gets(arr2);
//	char* p = add(arr1, arr2);
//	printf("%s", p);
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	char arr1[10] = { 0 };
//	char arr2[10] = { 0 };
//	
//	gets(arr1);
//	gets(arr2);
//
//	//111111
//	//00111
//
//	int len1 = strlen(arr1);
//
//	return 0;
//}

//int main()
//{
//	/*char arr[10] = { '1', '2' };
//	printf("%d", strlen(arr));
//	printf("%s", arr);*/
//	char arr1[10] = { 0 };
//	char arr2[10] = { 0 };
//	gets(arr1);
//	gets(arr2);
//	char*p = add(arr1, arr2);
//	printf("%s", p);
//	free(p);
//	p = NULL;
//	/*int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		scanf("%c", &arr1[i]);
//	}
//	for (int i = 0; i < sz; i++)
//	{
//		scanf("%c", &arr1[i]);
//	}*/
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int anser = 0;
//	int ret = b;
//	while (ret != 0)
//	{
//		anser = a ^ b;
//		ret = (a & b) << 1;
//		a = anser;
//		b = ret;
//	}
//	printf("%d", a);
//
//	system("pause");
//	return 0;
//}


int myPow(int x, int y)
{

	int ret = 1;
	if (x == 0) {

		return 0;
	}
	while (y > 0) {

		ret *= 2;
		y--;
	}
	return  ret;
}

int calBin(char arr[],int sz) 
{

	//10   -   2
	int ret = 0;
	for (int i = 0; i < sz; i++) {


		ret += myPow(arr[i] - '0', sz - 1-i);
	}
	return ret;
}
//
//int main()
//{
//	char arr[] = { '1', '0','1','0'};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = calBin(arr,sz);
//	printf("%d", ret);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	char arr1[] = { '1','1','1'};
//	char arr2[] = { '1'};
//
//	int a = 0;
//	int b = 0;
//	a = calBin(arr1, 3);
//	b = calBin(arr2, 1);
//	//scanf("%d %d", &a, &b);
//	printf("%d %d ", a, b);
//	int anser = 0;
//	int ret = b;
//	while (ret != 0)
//	{
//		anser = a ^ b;
//		ret = (a & b) << 1;
//		a = anser;
//		b = ret;
//	}
//	printf("%d", a);
//	system("pause");
//	return 0;
//}



#include <stdio.h>
#include <string.h>

//int main()
//{
//	char arr[10000] = { 0 };
//	//输入
//	gets(arr);
//
//	//逆序
//	int len = strlen(arr);
//	char* left = arr;
//	char* right = arr + len - 1;
//
//	while (left<right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//
//		left++;
//		right--;
//	}
//	//打印
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}

void move(int arr[], int sz)
{
	int* left = arr;
	int* right = arr + sz - 1;

	while (left<right)
	{
		//从左向右找一个偶数，停下来
		while ((left<right) && (*left)%2==1)
		{
			left++;
		}
		//从右向左找一个奇数，停下来
		while ((left < right) && (*right) % 2 == 0)
		{
			right--;
		}
		//奇数和偶数交换
		if (left < right)
		{
			int tmp = *left;
			*left = *right;
			*right = tmp;
		}
	}
}

void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int main()
{
	//int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int arr[] = { 1,1,2,1,1,2,1,2 };

	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	move(arr, sz);
	print(arr, sz);

	system("pause");
	return 0;
}



#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//void test()
//{
//	printf("hell");
//}
//
//int main()
//{
//	printf("Hedd");
//	test();
//	return 0;
//}

//int main()
//{
//
//
//	/*int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	
//	int ch = getchar();
//	printf("%d %d", a, b);
//	printf("%c", ch);*/
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int sum = 0;
//	scanf("%d", &n);
//	//1! +  2! + 3!
//	int count = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		count *= i;
//		sum += count;
//	}
//
//	printf("%d", sum);
//	return 0;
//}

//int main()
//{
//
//	/*double d = 1.0e-2;
//	printf("%lf", d);*/
//
//	//int arr[10] = { 0 };
//
//	///*printf("%s", arr + 11);
//	//printf("%s", arr + 10);*/
//
//	//for (int i = 0; i <= 12; i++)
//	//{
//	//	arr[i] = 0;
//	//	printf("hehe %d\n", i);
//	//}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hello bit\n");
//    }
//    return 0;
//}

#include<assert.h>
#include<stdio.h>

unsigned int Mystrlen1(const char* p)
{
	int count = 0;
	if (p == NULL)
		return 0;

	while (*p++!='\0')
	{
		count++;
	}
	return count;
}

unsigned int Mystrlen2(const char* p)
{
    assert(p != NULL);
	int count = 0;
	while (*p++ != '\0')
	{
		count++;
	}
	return count;
}

//int main()
//{
//	char arr[] = "abcde";
//	int ret = Mystrlen2(arr);
//	printf("%d", ret);
//	return 0;
//}

#include<stdio.h>

char* My_strcpy(char* dest, const char* source)
{
	assert((dest != NULL) && (source != NULL));

	char* star = dest;
	while (*dest++ = *source++)
	{
		;
	}

	return star;
}

//int main()
//{
//	char arr1[10] = { 0 };
//	char arr2[] = "hello";
//	My_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	printf("%s\n", My_strcpy(arr1, arr2));
//	return 0;
//}

#include<stdio.h>

void swap(int* pa, int* pb)
{
	int ret = 0;
	ret = *pa;
	*pa = *pb;
	*pb = ret;
}

int absolute(int x)
{
	if (x < 0)
		return -x;
	return x;
}

void adjust_odd_even1(int* p, int sz)
{
	assert(p);
	int* star = p;
	int* end = p + sz - 1;

	while (star < end)
	{
		if((absolute(*star) % 2) == 1)
		{
			star++;
			continue;
		}

		if((absolute(*end) % 2) == 0)
		{
			end--;
			continue;
		}

		swap(star, end);
		star++;
		end--;
	}
}


void adjust_odd_even2(int* p, int sz)
{
	assert(p);
	int* star = p;
	int* end = p + sz - 1;

	while (star< end)
	{
		while ((absolute(*star) % 2) == 1)
		{
			star++;
		}
			
		while ((absolute(*end) % 2) == 0)
		{
			end--;
		}
			
		if (star < end)
		{
			swap(star, end);
			star++;
			end--;
		}
		
	}
}

//int main()
//{
//	int arr[] = { 1,2,1,2,1,2,1,2,1,2};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	adjust_odd_even1(arr,sz);
//	adjust_odd_even2(arr,sz);
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	a = a++;
//	printf("%d", a);
//	return 0;
//}

//int main()
//{
//	printf("%d\n", 1 > 2);
//	printf("%d\n", 1 < 2);
//	return 0;
//}

//int main()
//{
//	printf("%d", !0);
//	return 0;
//}

#include<stdio.h>

int main()
{
	int arr[] = { 1,2,3,4,5,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int count = 0;

	for (int i = 0; i < sz; i++)
	{
		count ^= arr[i];
	}

	printf("%d", count);
	return 0;
}

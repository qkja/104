#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//int main()
//{
//	//char arr = 0;
//	/*scanf("%c", arr);
//	printf("%c\n", arr);*/
//	//int a[3][2] = { 1, 2, 3, 4, 5, 6 }, * p[3];
//	//p[0] = a[1];
//	//printf("%d\n", *(p[0] + 1));
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int k = 0;
//    int m = 0;
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d ", &m);
//        k ^= m;
//    }
//    printf("%d", k);
//    return 0;
//}
int* findPeakElement(int* nums, int numsLen ,int* ret)
{
   //ÅÐ¶Ï¿ÕÖ¸Õë
	int j = 0;
	if (1 == numsLen)
	{
		return NULL;
	}
	int* p = (int*)malloc(sizeof(int) * numsLen);
	if (p != NULL)
	{
		for (int i = 0; i < numsLen; i++)
		{

			if (((i != 0) && (i != numsLen - 1)) && (nums[i] > nums[i + 1]) && (nums[i] > nums[i - 1]))
			{
				p[j] = nums[i];
				j++;
			}
			else if (i == 0)
			{
				if (nums[1] < nums[0])
				{
					p[j] = nums[i];
					j++;
				}
			}
			else if (i == numsLen - 1)
			{
				if (nums[numsLen - 2] < nums[numsLen - 1])
				{
					p[j] = nums[i];
					j++;
				}
			}
		}
	}

	*ret = j;
	return p;
}

//int main()
//{
//	int arr[] = { 2,1,4,1,2,7,8,4 };
//	int ret = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* p = findPeakElement(arr, sz, &ret);
//	for (int i = 0; i < ret; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}
#include<stdio.h>

//int main()
//{
//	int i = 1;
//	char ch = (char)i;
//	printf("%#x", ch);
//	return 0;
//}
//int main()
//{
//	unsigned char i = 7;
//	int j = 0;
//	//0000 0111   7
//	//  
//	int d = 1;
//	for (; i > 0; i -= 3)//  
//	{
//		++j;
//		
//	} 
//	d = i;
//	printf("%d\n", j);
//	printf("%#x\n",d);
//	return 0;
//}
#include <stdio.h>
typedef union
{
	int a;
	struct
	{
		short b;
		short c;
	};
}X;
//int main()
//{
//	X x;
//	x.a = 0x20150810;
//	printf("%x,%x\n", x.b, x.c); //8213  2024
//	return 0;
//}
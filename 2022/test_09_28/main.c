#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdio.h>
void swapArr(int* p1, int* p2,int len)
{
    if (p1 == NULL || p2 == NULL)
        return;
    while (len--)
    {
        int ret = *p1;
        *p1 = *p2;
        *p2 = ret;
        p1++;
        p2++;
    }
}
int main()
{
    int arr1[] = { 1,2,3,4,5 };
    int arr2[] = { 6,7,8,9,10 };
    int sz = sizeof(arr1) / sizeof(arr1[0]);
    swapArr(arr1, arr2,sz);
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr2[i]);
    }
    return 0;
}



//int main()
//{
//    //int a[][3] = { {0,2},{},{3,4,5} };
//    /*int arr[] = { 1,2,(3,4),5 };
//    printf("%d\n", sizeof(arr));*/
//    return 0;
//}
//void reverse_string(char* string)
//{
//
//}
//
//void print(int n)
//{
//	if (n < 10)
//	{
//		printf("%d ", n);
//		return;
//	}
//	print(n / 10);
//	printf("%d ", n % 10);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//	return 0;
//}
//int main()
//{
//	char* p = "aaaa";
//	printf("%d\n", myStrlen(p));
//	printf("%d\n", myStrlenR(p));
//	return 0;
//}

//int myStrlenR(char* p)
//{
//	if (*p == '\0')
//		return 0;
//	return 1+ myStrlenR(++p);
//}
//
//int myStrlen(char* p)
//{
//	int count = 0;
//	while (*p++)
//	{
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char* p = "aaaa";
//	printf("%d\n", myStrlen(p));
//	printf("%d\n", myStrlenR(p));
//	return 0;
//}

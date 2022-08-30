#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

char* My_strcpy(char* dest, const char* src)
{
	assert(dest && src);
	char* p = dest;
	while (*p++ = *src++)
	{
		;
	}
	
	return dest;
}

//int strcmp( const char *string1, const char *string2 );
//int My_strcmp(const char* s1, const char* s2)
//{
//	assert(s1 && s2);
//	while (*s1 != '\0' && *s2 != '\0')
//	{
//		if (*s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		else
//		{
//			return *s1 - *s2;
//		}
//		/*else if (*s1 < *s2)
//		{
//			return *s1 - *s2;
//		}*/
//	}
//	return *s1 - *s2;
//}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int My_strcmp(const char* s1, const char* s2)
{
	assert(s1 && s2);
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return 0;
		}
		s1++;
		s2++;
	}
	return *s1 - *s2;
}

//char* My_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* p = dest;
//	while (*p != '\0')
//	{
//		p++;
//	}
//	while (*src!='\0')
//	{
//		*p = *src;
//		p++;
//		src++;
//	}
//	*p = '\0';
//	return dest;
//}

char* My_strcat(char* dest, const char* src)
{
	assert(dest && src);
	char* p = dest;
	while (*p != '\0')
	{
		p++;
	}
	while (*p++ = *src++)
	{
		;
	}
	return dest;
}

char* My_strstr(const char* s1, const char* s2)
{
	assert(s1 && s2);
	const char* p1 = NULL;
	const char* p2 = NULL;
	/*if (*s2 == '\0')
	{
		return s1;
	}*/
	while (*s1!='\0')
	{
		p1 = s1;
		p2 = s2;
		while (*p1==*p2 && *p1)
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
		{
			return (char*)s1;
		}
		s1++;
	}
	return NULL;

}

//void *memcpy( void *dest, const void *src, size_t count );

void* My_memcpy(void* dest, const void* src, int count)
{
	assert(dest && src);
	for (int i = 0; i < count; i++)
	{
		*((char*)dest + i) = *((char*)src + i);
	}
	return dest;
}

void* My_memmove(void* dest, const void* src, int count)
{
	assert(dest && src);
	if (dest < src)
	{
		for (int i = 0; i < count; i++)
		{
			*((char*)dest + i) = *((char*)src + i);
		}
	}
	else
	{
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return dest;
}

print(char* s)
{
	if (*s)
	{
		print(++s);
		printf("%c", *s);
	}
}
int fun(int x)
{
	return (x == 1) ? 1 : (x + fun(x - 1));//10+f(9)
}

//int main()
//{
//	printf("%d", fun(10));
//	/*char str[] = "Geneius";
//	printf("%c", '\0');
//	printf("%c", 'q');*/
//	//print(str);
//	return 0;
//} 


//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	My_memmove(arr+2, arr + 1, 8);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6 };//2
//	int arr2[5] = { 0 };
//	/*My_memcpy(arr2, arr1, 20);
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", arr2[i]);
//	}*/
//	/*for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", arr2[i]);
//	}*/
//	return 0;
//}
//int main()
//{
//	char* p1 = "aaccc";
//	char* p2 = "aaccc";
//	printf("%s\n", My_strstr(p1, p2));
//	//printf("%s\n", p1);
//	printf("%s\n", strstr(p1, p2));
//	return 0;
//}

//int main()
//{
//	char arr[100] = "12345";
//	char arr2[] = "67\089";
//	My_strcat(arr, arr2);
//	printf("%s", arr);
//	return 0;
//}

//int main()
//{
//	char arr1[] = "aa";
//	char arr2[] = "";
//	int ret = My_strcmp(arr1, arr2);
//	printf("%d", ret);
//	return 0;
//}

//int main()
//{
//	char arr1[] = "abcd";
//	char arr2[20] = { 0 };
//	My_strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}

//char* My_strcpy(char* dest,const char* src)
//{
//	assert(dest && src);
//	char* p = dest;
//
//	while (*p++ = *src++)
//	{
//		;
//	}
//	/*while (*src!='\0')
//	{
//	    *p = *src;
//		p++;
//		src++;
//	}*/
//	return dest;
//}





//char *strcpy( char *strDestination, const char *strSource );

//struct Stu
//{
//	char name[20];
//	int age;
//	char id[11];
//};

//int main()
//{
//	struct Stu stu = { 0 };
//	printf("%d", sizeof(stu));
//	return 0;
//}

//int main()
//{
//	int* p = malloc(4);
//	free(p);
//	p = NULL;
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char arr[1024] = { 0 };
//	int ch = 0;
//	int i = 0;
//	for (i = 0; (ch = getchar()) != '\n'; i++)
//	{
//		arr[i] = ch;
//	}
//
//	for (int j = 0; j < i - 1; j++)
//	{
//		for (int k = 0; k < i - 1 - j; k++)
//		{
//			if (arr[k] > arr[k + 1])
//			{
//				char temp = arr[k];
//				arr[k] = arr[k + 1];
//				arr[k + 1] = temp;
//			}
//		}
//	}
//
//	printf("%s\n", arr);
//	/*for (int j = 0; j < i; j++)
//	{
//		printf()
//	}*/
//	return 0;
//}
int pivotIndex(int* nums, int numsSize) 
{
	int sum = 0;
	for (int i = 0; i < numsSize; i++)
	{
		sum += nums[i];
	}
	
	for (int i = 0; i < numsSize; i++)
	{
		int sum1 = 0;
		for (int j = 0; j < i; j++)
		{
			sum1 += nums[j];
		}
		if (nums[i] + 2 * sum1 == sum)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 1, 7, 3, 6, 5, 6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("%d", pivotIndex(arr, sz));
 	return 0;
}
//#include<stdio.h>
//int main()
//{
//	char arr[1024] = { 0 };
//	while (scanf("%s", arr) != -1) 
//	{
//		int n = strlen(arr);
//		for (int j = 0; j < n - 1; j++)
//		{
//			for (int k = 0; k < n - 1 - j; k++)
//			{
//				if (arr[k] > arr[k + 1])
//				{
//					char temp = arr[k];
//					arr[k] = arr[k + 1];
//					arr[k + 1] = temp;
//				}
//			}
//		}
//		printf("%s\n", arr);
//	}
//	return 0;
//}
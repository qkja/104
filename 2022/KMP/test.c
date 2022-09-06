#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//假如子串小于 两个

void getNext(char* sub,int next[])
{
	assert(sub && next);
	next[0] = -1;
	next[1] = 1;
	int i = 2;
	int k = 0;
	for (; i < (int)strlen(sub);)
	{
		if (-1==k || sub[i - 1] == sub[k])
		{
			next[i] = k + 1;
			i++;
			k++;
		}
		else
		{
			k = next[k];
		}
	}
}

int KMP(char* str, char* sub, int pos)
{
	assert(str && sub);
	int lenStr = strlen(str);
	int lenSub = strlen(sub);
	if (lenStr <= 0 || lenSub <= 0)
	{
		return -1;
	}
	if (pos < 0 || pos >= lenSub)
	{
		return -1;
	}
	int* next = (int*)malloc(sizeof(int) * lenSub);
	if (next == NULL)
	{
		printf("%s\n", strerror(errno));
		return -1;
	}
	
	getNext(sub, next);
	int i = pos;
	int j = 0;
	while (i < lenStr && j < lenSub)
	{
		if (-1 == j || sub[j] == str[i])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	free(next);
	next = NULL;
	if (j >= lenSub)
	{

		return i - j;
	}
	return -1;
}

//int main()
//{
//	char* str = "ababcabcdabcde";
//	char* sub1 = "a";
//	char* sub2 = "abcde";
//	char* sub3 = "abcdef";
//	printf("%d\n", KMP(str, sub1, 0));
//	printf("%d\n", KMP(str, sub2, 0));
//	printf("%d\n", KMP(str, sub3, 0));
//	return 0;
//}


//int main()
//{
//	char sub[] = "abcababcabc";
//	int len = strlen(sub);
//	int* p = (int*)malloc(sizeof(int) * len);
//	if (p != NULL)
//	{
//		getNext(sub, p);
//		for (int i = 0; i < len; i++)
//		{
//			printf("%d ", p[i]);
//		}
//	}
//	
//	free(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	char c = 'A';
//	if('0' <= c <= '9')
//		printf("YES");
//	else
//		printf("NO");
//	return 0;
//}
#include<stdio.h>
//int main()
//{
//	int n = 1001;
//	int ans = 0;
//	for (int i = 1; i <= n; ++i)
//	{
//		ans ^= i % 3;
//	} 
//	printf("%d", ans);
//	return 0;
//}

void swapStr(char* left,char* right)
{
	assert(left&&right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void advanceStr(char* str,int pos)
{
	assert(str);
	int len = strlen(str);
	for (int i = pos - 1; i <=len ; i++)
	str[i] = str[i + 1];
}
void modifyStr(char* str)
{
	assert(str);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (!(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' || str[i] == ' '))
			str[i] = ' ';
	}
	//第二步  修改空格
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			i++;
		}
		else
		{
			if (str[i - 1] != ' ')
				i++;
			else
				advanceStr(str, i);
		}
	}
}
void reverseStr(char* str)
{
	assert(str);
	int len = strlen(str);
	int i = 0,j = 0;
	modifyStr(str);
	while (i <= len)
	{
		if (str[i] != ' '&& str[i] != '\0')
		   i++;
		else if((str[i] == ' ')|| (str[i] == '\0'))
		{
			swapStr(str + j, str + i - 1);
			j = i + 1;
			i++;
		}
	}
	swapStr(str, str + len - 1);
}

//int main()
//{
//	char arr[] = "$bo*y gi!r#l";
//	printf("%s\n", arr);
//	reverseStr(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int j = 0;
//	//printf("%d", '0');
//	scanf("%d", &n);
//	char ch[10] = { 0 };
//	do
//	{
//		ch[j] = (char)(n % 10 + 48);
//		n /= 10;
//		j++;
//	} while (n);
//	//100
//	/*while (n)
//	{
//		ch[j] = (char)(n % 10 + 48);
//		n /= 10;
//		j++;
//	}*/
//	for (int i = 0; i < j; i++)
//	{
//		printf("%c", ch[i]);
//	}
//	//char ch[3] = { 'a','b','c' };
//	return 0;
//}

//优化next数组


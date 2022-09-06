#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//int main()
//{
//	int* k[10][30];
//	printf("%d\n", sizeof(k));
//	return 0;
//}
//int main() {
//	char p1[15] = "abcd", * p2 = "ABCD", str[50] = "xyz";
//	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
//	printf("%s", str);
//	return 0;
//	/*int m[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int(*p)[4] = (int(*)[4])m;
//	printf("%d", p[1][2]);*/
//	return 0;
//}
char* f(char* str, char ch)
{
	char* it1 = str;
	char* it2 = str;
	while (*it2 != '\0')
	{
		while (*it2 == ch)
		{
			it2++;
		} *
			it1++ = *it2++;
	} return str;
}
int main() {
	char a[10];
	strcpy(a, "abcdcccd");
	printf("%s", f(a, 'c'));
	return 0;
}
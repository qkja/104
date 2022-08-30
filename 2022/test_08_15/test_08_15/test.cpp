#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>

//int main()
//{
	/*int a = 1;
	printf("%d\n",(char)(1 << 30));
*/

	/*char a = 101;
	int sum = 200;
	a += 27; sum += a;
	printf("%d\n", (char)sum);*/
	/*printf("char       %d\n", sizeof(char));
	printf("short      %d\n", sizeof(short));
	printf("int        %d\n", sizeof(int));
	printf("long int   %d\n", sizeof(long int));
	printf("long long  %d\n", sizeof(long long));
	printf("float      %d\n", sizeof(float));
	printf("double     %d\n", sizeof(double));*/

	//int value = 1024;
	//char condition = *((char*)(&value));
	//if (condition) 
	//	value += 1; 
	//condition = *((char*)(&value));
	//if (condition) 
	//	value += 1; 
	//condition = *((char*)(&value));
	//printf("%d %d", value, condition);
void func(char *p) { p = p + 1; }
int main()
{
	char s[] = { '1', '2', '3', '4' };
	func(s);
	printf("%c", *s);
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1





//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("%d", a,b);
//	return 0;
//}













//int main()
//{
//	int a = 16;
//	printf("%x\n", a,a);
//	return 0;
//}


//#include <stdio.h>


//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("%d %d %d", a, b);
//	return 0;
//}












//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
////字符串最后一个单词的长度
//int func(char arr[], int len)
//{
//    assert(arr);
//    char* right = arr + len - 1;
//    int count = 0;
//    while (right >= arr && *right != ' ') {
//        count++;
//        right--;
//    }
//    return count;
//}
//int main()
//{
//    char arr[5001] = { 0 };
//    gets(arr);
//    int len = strlen(arr);
//    int ret = func(arr, len);
//    printf("%d\n", ret);
//    return 0;
//}
//int main()
//{
//    char arr[5001] = { 0 };
//    gets(arr);
//    printf("%s", arr);
//    return 0;
//}

//#include <stdio.h>

//int main()
//{
//	float a = 1001.0f;
//	printf("a == %g\n", a);
//	float b = 1000000.132f;
//	printf("b == %g\n", b);
//	return 0;
//}




//int main()
//{
//	float a = 1001.0f;
//	printf("%e\n", a);
//	return 0;
//}



//int main()
//{
//	float a = 1.0f;
//	printf("%15.2f\n", a);
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	printf("%.1d\n", a);
//	return 0;
//}

//int main()
//{
//	int a = 11;
//	printf("%10d\n", a);
//	printf("%-10d\n", a);
//	return 0;
//}

#include <stdio.h>

int main()
{
	
	float x = 0.0f;
	scanf("%f", &x); //  输入 .1
	printf("%lf\n", x);
	return 0;
}

//int main()
//{
//	int i = 0;
//	int j = 0;
//	float x = 0.0f;
//	float y = 0.0f;
//	scanf("%d%d%f%f", &i, &j, &x, &y);   //1-20.3-4.0e3换行
//	printf("i = %d\n", i);
//	printf("j = %d\n", j);
//	printf("x = %f\n", x);
//	printf("y = %f\n", y);
//	return 0;
//}


//int main()
//{
//	char arr[100] = { 0 };
//	scanf("%s", arr);
//	printf("%s\n", arr);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a,&b);
//	printf("a = %d b = %d\n", a,b);
//	int c = 0;
//	scanf("%d", &c);
//	printf("c = %d\n", c);
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
//int main()
//{
//	char ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		getchar();
//		if (ch == 'a')
//			printf("hwhwhw\n");
//		else
//			printf("hahaha\n");
//		//putch(ch);
//	}
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//    char ch = 0;
//    while ((scanf("%c", &ch)) != EOF)
//    {
//        getchar();
//        if (ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u')
//        {
//           printf("Vowel\n");
//        }
//           
//        else
//            printf("Consonant\n");
//    }
//    return 0;
//}

//int main()
//{
//    int n = 0;
//    while ((scanf("%d", &n)) != EOF)
//    {
//        if (0 == n % 2)
//        {
//            printf("Even\n");
//        }
//        else
//        {
//            printf("Odd\n");
//        }
//    }
//
//
//    return 0;
//}

//#include <stdio.h>
//int i;
//int main()
//{
//    i--;
//    if (i > sizeof(i))
//    {
//        printf(">\n");
//    }
//    else
//    {
//        printf("<\n");
//    }
//    return 0;
//}
//#include<stdio.h>



//#include <stdio.h>
//int main()
//{
//    int i = 1;
//    int ret = (++i) + (++i) + (++i);
//    printf("ret = %d\n", ret);
//    return 0;
//}






//int main()
//{
//	int a = 0;
//	int b = 0;
//	a = b = 5; //我们不建议 代码风格不好
//	printf("%d %d", a, b);
//	return  0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("Before a = %d b = %d\n", a, b);
//
//	a = a ^ b;
//	b = a ^ b;     //把 b 赋给 a
//	a = a ^ b;     //把 a 赋给 b
//	printf("After  a = %d b = %d\n", a, b);
//	return 0;
//}




//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	if ((n & (n - 1)) == 0)
//	{
//		printf("YES\n");
//	}
//	return 0;
//}

//int main()
//{
//	int a = -5;
//	int b = a >> 1;
//	printf("%d\n", b);
//	printf("%d\n", a);
//	return 0;
//}

//int main()
//{
//	int a = 5;
//	int b = a << 1;
//	printf("%d\n", b);
//	printf("%d\n", a);
//	return 0;
//}













//#include<stdio.h>
//int main()
//{
//
//	/*int a = -10 >> 1;
//
//	printf("%d", a);*/
//	/*int a = 1 >> 1;
//	int b = 1 << 1;
//	printf("%d\n", a);
//	printf("%d\n", b);*/
//	//double d = 10.0 / 3;
//	////printf("%d\n", d);
//	//printf("%lf\n", d);
//	//return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = 0;
//	while (n)
//	{
//		sum += n;
//		n--;
//	}
//	printf("%d", sum);
//
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d ", n*(n + 1) / 2);
//	return 0;
//}

//int main()
//{
//
//	int a = 0;
//	scanf("%d", &a);
//	int arr[10] = { 0 };
//	int i = 0;
//	//7
//	while (a)
//	{
//		arr[i] = a % 6;
//		a /= 6;
//		i++;
//	}
//	for (i--; i >= 0; i--)
//	{
//		printf("%d", arr[i]);
//	}
//	//char str[] = "abcde";
//	//char* p = str;
//	//printf("%c\n", *p);
//	//printf("%s\n", p);
//	/*int arr1[2] = { 0 };
//	int arr2[2] = { 0 };
//	int* p1 = NULL;
//	p1 = arr1;
//	int* p2 = NULL;
//	p2 = arr2;
//	printf("%d ", *p1);*/
//	return 0;
//}

//#include<stdio.h>

//int main()
//{
//	double de = 10.0;
//	de % 3;
//	return 0;
//}


//int main()
//{
//
//	//按位与等  是补码进行的
//	//double a = 10.0;
//	//a % 2;
//	return 0;
//}
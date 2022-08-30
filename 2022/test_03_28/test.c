#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>

//#define A
//
//#define PI 3.14159f
//#define TWOPI 2*PI

//#define PRINT(n) printf(#n " is value %d\n",n)
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	PRINT(a);
//	PRINT(b);
//	PRINT(c);
//	return 0;
//}

//
//#define MUL(a,b) a * b
//
//int main()
//{
//
//	printf("%d", MUL(2 + 1,2+3));
//	return 0;
//}


//#define MAX(a,b) (a) > (b) ? (a) : (b)
//
//int main()
//{
//    #define A 10
//	printf("%d", A);
//	return 0;
//}


//void func(int x)
//{
//	printf("max = %d\n", x);
//
//}
//int main()
//{
//	int i = 1;
//	func(i++);
//	return 0;
//}
//int main()
//{
//	int i = 2;
//	int j = 1;
//	int max = (i++) > (j) ? (i++) : (j);
//	printf("max = %d\n", max);
//	printf("i = %d\n", i);
//	return 0;
//}


//int main()
//{
//	printf("max = %d\n", MAX(1, 3));
//	return 0;
//}


//int main()
//{
//	printf("max = %d\n", MAX(1,3));
//
//	//printf("%f\n", PI);
//	return 0;
//}

//#define GENERRIC_MAX(type)      \
//type type##_max(type x,type y)  \
//{                               \
//     return x > y ? x : y;      \
//}  
//GENERRIC_MAX(float)
//
//
//int main()
//{
//	
//	float ret = float_max(1.2f, 3.7f);
//	printf("%.1f\n", ret);
//	return 0;
//}
//#define MAX(a,b) (a) > (b) ? (a) : (b)
//#define A(n) n##n
//int main()
//{
//	printf("%d\n", MAX(3, MAX(1, 0)));
//	printf("%d\n", A(A(1)));
//	return 0;
//}


//int main()
//{
//	printf("%s\n", __FILE__);
//	return 0;
//}

//A(1)A(1)

//int main()
//{
//	printf("%s\n", __FILE__);
//	printf("%d\n", __LINE__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//	//printf("%d\n", __STDC__);
//	return 0;
//}


//int main()
//{
//	int a = 18;   //定义一个变量  a
//
//	/*int b = a + 10;
//	int c = 2 * b;*/
//
//	return 0;
//}

//int main()
//{
//	int child = 18;   
//	int parent = 20;
//	return 0;
//}

//int main()
//{
//	int m = N;
//	return 0;
//}
//#define N 10

//int main()
//{
//#define X 3
//#define Y X*2
//#undef X
//#define X 2
//		int z = Y;
//	printf("%d\n", z);
//	return 0;
//}
//#define X 3
//void show()
//{
//	printf("%d",X);
//}
//int main()
//{   
//
//	#undef X
//	show();
//	return 0;
//}
#ifndef __TEST_H__
#define __TEST_H__

#include <stdio.h>
#include <stdlib.h>
#endif 



//#define M 0

//int main()
//{
//#if defined M
//	printf("M已经被定义\n");
//#endif
//
//	printf("Hello word");
//	return 0;
//}

//int main()
//{
//#define X 3
//#define Y X * 2
//#undef X
//#define X 2
//	int z = Y;
//	printf("%d\n", z);
//	return 0;
//}

//void show()
//{
//	printf("%d", X);
//}
//int main()
//{
//#define X 3
//	//#undef X
//	show();
//	return 0;
//}

//#define X 3
//void show()
//{
//	printf("%d", X);
//}
//int main()
//{
//
//#undef X
//	show();
//	return 0;
//}


//int main()
//{
//	
//#ifndef __CPP
//#error 老铁，你用的不是C++的编译器哦
//#endif
//
//	return 0;
//}

//int main()
//{
//	printf("%s, %d\n", __FILE__, __LINE__); 
//#line 60 "hehe.h" //定制化完成
//	printf("%s, %d\n", __FILE__, __LINE__);
//
//	return 0;
//}

//#define M 10
//int main()
//{
//#ifdef M
//#pragma message("M宏已经被定义了")
//#endif
//	return 0;
//}
//#define M(n) #n

//int main()
//{
//
//	printf("%s", M("abcd"));
//	return 0;
//}
//#define N(a,b,c) a##b##c
//
//int main()
//{
//	printf("%d \n", N(1, 1, 1));
//	printf("%d \n", N(1,,1));
//	printf("%d \n", N(1,,));
//	printf("===============\n");
//	printf("%d \n", N(1));
//	printf("%d \n", N(1,1));
//	printf("%d \n", N(1,1,1));
//
//	return 0;
//}

//#define A(x) (x) * (x) * (x) 
//int main()
//{
//	int a = 1;
//	printf("%d", A(++a));
//	return 0;
//}


int compare(int* el, int* e2)
{
    return *el - *e2;
}
int distributeCandies(int* candyType, int candyTypeSize) {
    //第一步  排序
    qsort(candyType, candyTypeSize, sizeof(int), compare);
    for (int i = 0; i < candyTypeSize; i++)
    {
        printf("%d ", candyType[i]);
    }
    //第二步  去重  得到新数组
    /*int n = candyTypeSize / 2;
    int* p = (int*)malloc(sizeof(int) * candyTypeSize);
    int i = 0;
    int j = 0;

    for (i = 0; i < candyTypeSize; i++)
    {
        if (i == 0)
        {
            p[j++] = candyType[0];
        }
        if (candyType[i] != p[j - 1])
        {
            p[j++] = candyType[i];
        }
    }
    return n < j ? n : j;*/
    //第三步  判断数组的长度  和 n 的值
    return 0;
}

int main()
{
    int arr[] = { 100000,0,100000,0,100000,0,100000,0,100000,0,100000,0 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    int ret = distributeCandies(arr, sz);
    printf("%d", ret);
    return 0;
}
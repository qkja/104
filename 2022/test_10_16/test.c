#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdio.h>


//int val = 0;
//int Fib(int n)
//{
//	val++;
//	if (n < 3)
//	{
//		return 1;
//	}
//	return Fib(n - 1) + Fib(n - 2);
//}
//
//int main()
//{
//	int n = 0;
//	while (1)
//	{
//		printf("请输入: ");
//		scanf("%d", &n);
//		Fib(n);
//		printf("递归执行的次数 : %d\n", val);
//		val = 0;
//	}
//	return 0;
//}


// 堆-> 菜市场
// new 一个二维数组
// 地址丢了没有什么影响
// 过几天实现一个内存池 -- 简单的实现
// 最后的针扎 找后面的来挂
// 单例模式
//int main()
//{
//	int* p = (int*)malloc(4);
//	p = NULL;
//	free(p);
//	return 0;
//}
//内存碎片问题
//int main()
//{
//	int* p = (int*)malloc(8);
//	printf("%d", sizeof(p));
//	free(p);
//	return 0;
//}

// 测试 realloc 
// 问题 如果我们第二次开辟失败了,原本的会不会被销毁了
// 我的想法  不会
// 个人想法解释 relloc 先开辟空间 后拷贝开辟,拷贝好之后才会释放

// 测试过后 C++会销毁 C语言不会
//我们重点去查一下


//int main()
//{
//	int* p1 = (int*)malloc(sizeof(int)*2);
//	p1[0] = 0;
//	p1[1] = 1;
//
//	int* p2 = (int*)realloc(p1, 2*1024*1024*1024);
//
//	if (p2 == NULL)
//	{
//		printf("开辟失败\n");
//		printf("%d %d", p1[0], p1[1]);
//		free(p1);
//		return 0;
//	}
//	if (p2 && p2 != p1)
//	{
//		printf("另外开辟空间");
//		p1 = p2;
//	}
//	free(p1);
//	return 0;
//}
//int main()
//{
//	for (int i = 0; i < 2; i++)
//	{
//		int ret = 0;
//		printf("%p\n", &ret);
//	}
//	return 0;
//}
//long long Fac(size_t n)
//{
//	if (n == 0)
//		return 1;
//	return Fac(n - 1)*n;
//}
//int main()
//{
//	long long  n = 1024*1024*100000;
//	Fac(n);
//	return 0;
//}
//void f1()
//{
//	int x = 0;
//	printf("%p\n", &x);
//}
//void f2()
//{
//	int y = 0;
//	printf("%p\n", &y);
//}
//int main()
//{
//	f1();
//	f2();
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//#include <sys/types.h>
//#include <sys/wait.h>

//typedef void (*handler_t)();

//方法集
//std::vector<handler_t> handlers;

//void fun1()
//{
//    printf("hello, 我是方法1\n");
//}
//void fun2()
//{
//    printf("hello, 我是方法2\n");
//}
//
//void Load()
//{
//    //加载方法
//    handlers.push_back(fun1);
//    handlers.push_back(fun2);
//}
//
//int main()
//{
//    pid_t id = fork();
//    if (id == 0)
//    {
//        //子进程
//        while (1)
//        {
//            printf("我是子进程, 我的PID: %d, 我的PPID:%d\n", getpid(), getppid());
//            sleep(3);
//        
//        }
//
//        exit(104);
//    }
//    else if (id > 0)
//    {
//        //父进程
//        // 基于非阻塞的轮询等待方案
//        int status = 0;
//        while (1)
//        {
//            pid_t ret = waitpid(-1, &status, WNOHANG);
//            if (ret > 0)
//            {
//                printf("等待成功, %d, exit sig: %d, exit code: %d\n", ret, status & 0x7F, (status >> 8) & 0xFF);
//                break;
//            }
//            else if (ret == 0)
//            {
//                //等待成功了，但是子进程没有退出
//                printf("子进程好了没，奥， 还没，那么我父进程就做其他事情啦...\n");
//                if (handlers.empty()) Load();
//                for (auto f : handlers)
//                {
//                    f(); //回调处理对应的任务
//                }
//                sleep(1);
//            }
//            else {
//                //出错了，暂时不处理
//            }
//        }
//    }
//    else {
//        //do nothing
//    }
//}
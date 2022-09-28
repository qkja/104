#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//递归和非递归分别实现strlen
int myStrlen(const char* p)
{
	int count = 0;
	while (*p++)
	{
		count++;
	}
	return count;
}
int main()
{
	const char* p = "";
	printf("%d\n", myStrlen(p));
	return 0;
}

//int factorialR(int n)
//{
//	if (n == 1)
//		return 1;
//	return n * factorialR(n - 1);
//}
//
//int factorial(int n)
//{
//	int total = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		total *= i;
//	}
//	return total;
//}
//
//int main()
//{
//	int n = 10;
//	scanf("%d", &n);
//	printf("%d\n", factorial(n));
//	printf("%d\n", factorialR(n));
//	return 0;
//}
//class A
//{
//public:
//
//	void fun1()
//	{
//		cout << (void*)this << endl;
//
//	}
//private:
//
//};
//class C
//{
//public:
//	void aa()
//	{
//		cout << (void*)this << endl;
//	}
//	void fun2()
//	{
//		cout << (void*)this << endl;
//	}
//private:
//
//};
//class B : public A , C
//{
//public:
//	void f()
//	{
//		cout << (void*)this << endl;
//		fun1();
//		fun2(); //
//	}
//};
//
//int main()
//{
//	B b;
//	b.f();
//
//	C* p = (C*)(((char*)(&b)+sizeof(A)));
//	p->aa();
//	return 0;
//}

//int numberOfOne(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		count++;
//		n = n & (n - 1);
//	}
//	return count;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	cout << numberOfOne(n) << endl;
//	return 0;
//}


//struct A
//{
//	A()
//	{
//		b();
//	}
//	void f()
//	{
//		printf("foo");
//	}
//	virtual void b()
//	{
//		cout << "bar";
//	}
//};
//struct B : A
//{
//	void f() { cout << "b_foo"; }
//	void b() { cout << "b_bar"; }
//};
//int main()
//{
//	A* p = new B;
//	p->f();
//	p->b();
//	return 0;
//}

// 列表初始化
//int main()
//{
//	int a = 10;
//	int b = { 10 };
//	int c{ 10 };  // 这个就不要用了
//
//	// 我们最好使用 列表初始化 兼容数组的初始化
//	int* p = new int[3]{ 1,2,3 };
//	delete p;
//	/*int* p1 = new int(4);
//	
//	delete p1;*/
//	return 0;
//}
//#include <vector>
//int main()
//{
//	vector<string> s1({ "1","3" });
//	return 0;
//}

// 我们把 {}看作一种类型  具体的用法知道了
// C++11 增加了一个initializer_list

//int main()
//{
//	auto il = { 1,2,3,4 };
//	cout << typeid(il).name() << endl;
//	return 0;
//}

//v = {10,20,30} 
// 先用  {} 构造一个vector
// 后面 赋值

// 左值  +  右值

//int main()
//{
//	decltype(1.0) ret = 0.11;
//	cout << ret << endl;
//	return 0;
//}

// 左值 右值  是否可以 取地址
// cont 左值引用  可以 接受 右值
// 右值 只能接受 右值
// 左->左

//我们 不能 对右值 却地址  但是 可以对右值引用取地址
//右值引用 可以 引用  move 之后的 左值
// 移动 构造 和 移动 赋值  极大的提高  深拷贝的价值
// 左值 引用 解决 了 传值拷贝的 问题  尤其是深拷贝
// 
// operator+ 这个 左值 引用解决不了
// 后置++也不行   这里 最关键的 是我们返回 函数里面的局部变量  这个需要 拷贝一个临时对象  这里就会出现 问题
// move  就是 把 左值的属性 变成  右值属性
// 增加一个 接受右值的拷贝构造函数

// 右值  分为 将亡值 匿名对象 to_string函数 返回值的值 纯右值  10 ,a+b
// 是不是 将亡值 编译器自动判断
// 我们可以 用  move 改一下属性  可以理解 为 将亡值
// 将亡值 可以 被掠夺资源 资源的转移 是其他函数做的 和move无关
// 
// 
//
//#include <iostream>
//using namespace std;
//bool isLeap(int year)
//{
//	if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
//	{
//		return true;
//	}
//	return false;
//}
//int days(int year, int month, int day)
//{
//	static int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (isLeap(year))
//	{
//		monthDays[2] = 29;
//	}
//	else
//	{
//		monthDays[2] = 28;
//	}
//	int total = day;
//	for (int i = 0; i < month; i++)
//	{
//		total += monthDays[i];
//	}
//	return total;
//}
//
//int main()
//{
//	int year = 0; 
//	int month = 0;
//	int day = 0;
//	//cin >> year >> month >> day;
//	cout << days(year, month, day);
//	return 0;
//}
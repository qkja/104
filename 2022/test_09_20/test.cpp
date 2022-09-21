#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <stack>
using namespace std;

//class A
//{
//public:
//	/*A(int a = 0)
//	{
//		cout << "构造函数" << endl;
//	}*/
//	A(int a,int b)
//	{
//		cout << "构造函数" << endl;
//	}
//	/*A()
//	{
//		cout << "构造函数" << endl;
//	}*/
//	/*A(const A& a)
//	{
//		cout << "拷贝构造" << endl;
//	}*/
//	int a;
//	int b;
//	int* p;
//};
//
//int main()
//{
//	int x = 0;
//
//	A a1(1,2);
//	a1.a = 1;
//	a1.b = 1;
//	a1.p = &x;
//	A a2(a1);
//	return 0;
//}
//class A 
//{
//public:
//	A()
//	{
//		cout << "构造函数" << endl;
//	}
//	/*A(const A& a)
//	{
//		cout << "拷贝构造" << endl;
//	}*/
//	int a;
//	int b;
//};
//int main()
//{
//	A a1;
//	a1.a = 1;
//	a1.b = 1;
//	A a2(a1);
//	return 0;
//}
//int main()
//{
//	short a = (short)65535;
//	short b{ (short)65535 };
//	cout << a << endl;
//	cout << b << endl;
//	return 0;
//}
//class Parenthesis {
//public:
//    bool chkParenthesis(string A, int n) {
//        if (n == 0)
//            return true;
//        stack<char> s;
//        for (const char& e : A)
//        {
//            if (e != '(' && e != ')')
//            {
//                return false;
//            }
//            if (e == '(')
//            {
//                s.push(e);
//            }
//            else if(e == ')')
//            {
//                if (s.empty())
//                {
//                    return false;
//                }
//                s.pop();
//            }
//        }
//        return s.empty();
//    }
//};
//int main()
//{
//    string str = "()(()()";
//    //string str = "()()()";
//
//    cout << Parenthesis().chkParenthesis(str, str.size());
//    return 0;
//}
//int toFib(int n)
//{
//	int left = 0;
//	int right = 1;
//	int sum = 0;
//	while (right < n)
//	{
//		sum = left + right;
//		left = right;
//		right = sum;
//	}
//	return (n - left) < (right - n) ? (n - left) : (right - n);
//	//
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	cout << toFib(n);
//	return 0;
//}


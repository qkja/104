#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <stack>
using namespace std;

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
/**
* User: Qkj
* Description: 
* Date: 2023-06-02
* Time: 16:44
*/
//#include <iostream>
//#include <string>
//#include <stack>
//#include <algorithm>
//using namespace std;
//// day 7
//// 初始化列表那里才是 初始化 
//// 函数体内是赋值
//// 初始化列表 是管不住的 static 的  所有对象共享
//// 必须放在 初始化列表的 的变量
//// const
//// 引用
//// 没有默认构造函数的 自定义对象   ---> 这里建议 有的也放进入 效率高点
////合法括号序列判断
////class Parenthesis {
////public:
////    bool chkParenthesis(string A, int n) {
////        // write code here
////        if (A.empty())
////            return true;
////        if (A.size() != n)
////            return false;
////        stack<char> s;
////        for (int i = 0; i < n; i++)
////        {
////            if (A[i] == '(')
////            {
////                // 入栈
////                s.push(A[i]);
////            }
////            else if (A[i] == ')')
////            {
////                // 出栈
////                if (s.empty())
////                    return false;
////                s.pop();
////            }
////            else
////            {
////                return false;
////            }
////        }
////        return s.empty();
////    }
////};
////int Fib(int n)
////{
////	
////	int left = 0;
////	int right = 1;
////	int sum = 1;
////	while (sum <= n)
////	{
////		sum = left + right;
////		left = right;
////		right = sum;
////	}
////	return sum;
////}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	// 寻找第一个 不比 n 小的 数
//	int left = 0;
//	int right = 1;
//	int sum = 1;
//	// n = 2
//	while (sum <= n)
//	{
//		sum = left + right; // 1 2
//		left = right;       // 1 1
//		right = sum;        // 1 2
//	}
//
//	int ret = min(sum - n, n - left);
//	cout << ret << endl;
//	return 0;
//}
//
//
//class Parenthesis {
//public:
//    bool chkParenthesis(string A, int n) {
//        // write code here
//        if (A.empty())
//            return true;
//        if (A.size() != n)
//            return false;
//        stack<char> s;
//        for (int i = 0; i < n; i++)
//        {
//            if (A[i] == '(')
//            {
//                // 入栈
//                s.push(A[i]);
//            }
//            else if (A[i] == ')')
//            {
//                // 出栈
//                if (s.empty())
//                    return false;
//                s.pop();
//            }
//            else
//            {
//                return false;
//            }
//        }
//        return s.empty();
//    }
//};

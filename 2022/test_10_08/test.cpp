#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
// day 10
using namespace std;
class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here
        if (board.empty())
            return true;
        int row = board.size();    //行
        int col = board[0].size(); //列数
        // 测试 列
        for (int i = 0; i < row; i++)
        {
            int sum = 0;
            for (int j = 0; j < col; j++)
            {
                sum += board[i][j];
            }
            if (sum == col)
                return true;
        }

        // 测试列
        for (int j = 0; j < col; j++)
        {
            int sum = 0;
            for (int i = 0; i < row; i++)
            {
                sum += board[i][j];
            }
            if (sum == row)
                return true;
        }
        // 测试 正斜
        int sum = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if(i == j)
                    sum += board[i][j];
            }
        }
        if (sum == col)
            return true;
        sum = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i == j)
                    sum += board[i][row-i-1];
            }
        }
        if (sum == col)
            return true;
        return false;
    }
};
////////////////////////////////////
// day 9
// 走格子
//int f(int a, int b)
//{
//    if (a == 0 || b == 0)
//        return 1;
//    return f(a - 1, b) + f(a, b - 1);
//}
//
//int main() {
//    int a, b;
//    cin >> a >> b;
//    cout << f(a, b) << endl;
//}

// 位运算 计算  a+b
//class UnusualAdd {
//public:
//    int addAB(int A, int B) {
//        // write code here
//        if (A == 0)
//            return B;
//        if (B == 0)
//            return A;
//        int x = A ^ B;
//        int y = (A & B)<<1;
//        return addAB(x, y);
//    }
//};



//class UnusualAdd {
//public:
//	int addAB(int A, int B) {
//		// write code here
//		int anser = 0;
//		int ret = B;
//		while (ret != 0)
//		{
//			anser = A ^ B;
//			ret = (A & B) << 1;
//			A = anser;
//			B = ret;
//		}
//		return A;
//	}
//};









// day 8
// 引用的 底层是由指针实现的,本质就是一个指针 
// 求最小公倍数 //这里找个简单的方法
// 最小公倍数 = 乘积 / 最大公约数
// 最大公约数 辗转相除法
// 9 6 
// 9%6 = 3
// 6%3 = 0
// 3就是最大公约数
//int main()
//{
//	int x = 0;
//	int y = 0;
//	cin >> x >> y;
//	int mul = x * y;
//	int c = 0;
//	while (c = x % y)
//	{
//		x = y;
//		y = c;
//	}
//	// 这里  y 就是最大公约数
//	cout << mul / y << endl;
//	return 0;
//}
//WY20 两种排序方法
//bool sortByLength(const vector<string>& v)
//{
//	for (int i = 1; i < v.size(); i++)
//	{
//		if (v[i].size() < v[i - 1].size())
//			return false;
//	}
//	return true;
//}
//bool lexSort(const vector<string>& v)
//{
//	for (int i = 1; i < v.size(); i++)
//	{
//		if (v[i] < v[i - 1])
//			return false;
//	}
//	return true;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<string> v;
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//	if (lexSort(v) && sortByLength(v))
//		cout << "both" << endl;
//	else if (lexSort(v))
//		cout << "lexicographically" << endl;
//
//	else if(sortByLength(v))
//		cout << "lengths" << endl;
//	else 
//		cout << "none" << endl;
//
//	
//	return 0;
//}

/////////////////////////////////////////////
// day 7
// 初始化列表那里才是 初始化 
// 函数体内是赋值
// 初始化列表 是管不住的 static 的  所有对象共享
// 必须放在 初始化列表的 的变量
// const
// 引用
// 没有默认构造函数的 自定义对象   ---> 这里建议 有的也放进入 效率高点
//合法括号序列判断
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
//int Fib(int n)
//{
//	
//	int left = 0;
//	int right = 1;
//	int sum = 1;
//	while (sum <= n)
//	{
//		sum = left + right;
//		left = right;
//		right = sum;
//	}
//	return sum;
//}
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
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//class Solution {
//private:
//    int _StrToInt(const string& str,int begin) {
//        int sum = 0;
//        for (int i = begin; i < str.size(); i++)
//        {
//            if (!(str[i] >= '0' && str[i] <= '9'))
//                return 0;
//            sum = sum*10 + (int)(str[i] - '0');
//        }
//        return sum;
//    }
//public:
//    int StrToInt(string str) {
//        if (str.empty())
//            return 0;
//        // 判断 第一个元素
//        if (str[0] == '+' || str[0] == '-')
//        {
//            if (str[0] == '+')
//            {
//                return _StrToInt(str, 1);
//            }
//            else
//            {
//                return -_StrToInt(str, 1);
//            }
//        }
//        else if (str[0] >= '0' && str[0] <= '9')
//        {
//
//            return _StrToInt(str, 0);
//        }
//        else
//        {
//            return 0;
//        }
//    }
//};
//
//int main()
//{
//    cout << Solution().StrToInt("1a33");
//    return 0;
//}


//int f(int n)
//{
//	if (n < 2)
//		return n;
//	else
//		return 2 * f(n - 1) + f(n - 2);
//}
//int f(int n)
//{
//	if (n == 1)
//		return 1;
//	else
//		return (f(n - 1) + n * n * n);
//}
//struct MyStruct
//{
//	long a;
//	short b;
//	int c;
//	int* a4;
//};
//int main()
//{
//	cout << sizeof(MyStruct);
//	//cout << f(3);
//	return 0;
//}

//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
// 
//class Solution {
//private:
//    bool _isSame(TreeNode* t1, TreeNode* t2)
//    {
//        if (t1 == nullptr && t2 == nullptr)
//            return true;
//        if (t1 == nullptr || t2 == nullptr)
//            return false;
//        if (t1->val != t2->val)
//            return false;
//        return _isSame(t1->left, t2->left) && _isSame(t1->right, t2->right);
//    }
//    bool _isSubStructure(TreeNode* A, TreeNode* B) {
//        if (A == nullptr || B == nullptr)
//            return false;
//        bool flg = _isSame(A, B);
//        if (_isSame(A, B))
//            return true;
//        flg = _isSubStructure(A->left, B);
//        if (flg)
//            return true;
//        flg = _isSubStructure(A->right, B);
//        if (flg)
//            return false;
//        return false;
//  
//
//    }
//public:
//   
//    bool isSubStructure(TreeNode* A, TreeNode* B) {
//        return _isSubStructure(A, B);
//    }
//};

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
#include <iostream>
#include <string>
using namespace std;
void func(double& t1, double& t2, double& t3, double& t4)
{
	t1 = (t2 + t3 + 40 + 30) / 4.0;
	t2 = (t1 + t4 + 20 + 30) / 4.0;
	t3 = (t1 + t4 + 15 + 30) / 4.0;
	t4 = (t2 + t3 + 10 + 5)  / 4.0;
}

int main()
{
	double t1 = 20.0;
	double t2 = 20.0;
	double t3 = 15.0;
	double t4 = 15.0;
	int n = 0;
	int i = 0;
	cin >> n;
	while (i < n)
	{
		printf("%-5d %-10.6lf %-10.6lf %-10.6lf %-10.6lf\n", i, t1, t2, t3, t4);
		
		func(t1, t2, t3, t4);
		i++;
	}
	return 0;
}
//day 11

//连续bit数
//int binaryContinuousOne(int n)
//{
//    int count = 0;
//    int maxCount = 0;
//    // 求二进制
//    for (int i = 0; i < 32; i++)
//    {
//        // 这里左翼最好 -1 会死循环 使用 while的时候
//        if ((n >> i & 1) == 1)
//        {
//            count++;
//        }
//        else
//        {
//            if (count > maxCount)
//            {
//                maxCount = count;
//            }
//            count = 0;
//        }
//    }
//    return maxCount;
//}
//int main() 
//{
//    int n = 0;
//    while (cin >> n) 
//    { 
//        cout << binaryContinuousOne(n) << endl;
//    }
//    return 0;
//}

//class LCA {
//public:
//    int getLCA(int a, int b) {
//        // write code here
//        if (a < 0 || b < 0)
//            return -1;
//        while (a != b)
//        {
//            // 找最大
//            if (a < b)
//            {
//                swap(a, b);
//            }
//            //4 5
//            //5 4
//            //2 4
//            //
//            // 找最大的父亲
//            a = a / 2; // 2
//        }
//        return a;
//    }
//    int getLCA2(int a, int b) {
//        // write code here
//        if (a < 0 || b < 0)
//            return -1;
//        while (a != b)
//        {
//            // 找最大
//            if (a < b)
//            {
//                a = a / 2;
//            }
//            else
//            {
//                b = b / 2;
//            }
//          
//        }
//        return a;
//    }
//};
//
//int main()
//{
//    cout << LCA().getLCA(2,3) << endl;
//    cout << LCA().getLCA(4,5) << endl;
//    cout << LCA().getLCA(4,6) << endl;
//    return 0;
//}
//////////////////////////////////////////////////////

//struct TreeNode {
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//};
//// 最近公共祖先
//class Solution {
//public:
//    /**
//     *
//     * @param root TreeNode类
//     * @param p TreeNode类
//     * @param q TreeNode类
//     * @return TreeNode类
//     */
//    TreeNode* nearestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        // write code here
//        if (root == nullptr)
//            return nullptr;
//
//        if (root->val == p->val || root->val == q->val)
//            return root;
//
//        TreeNode* left = nearestCommonAncestor(root->left, p, q);
//        TreeNode* right = nearestCommonAncestor(root->right, p, q);
//
//        if (left != nullptr && right != nullptr)
//            return root;
//        if (left == nullptr)
//            return right;
//        if (right == nullptr)
//            return left;
//        return nullptr;
//    }
//};

//class Solution {
//public:
//    /**
//     *
//     * @param root TreeNode类
//     * @param p TreeNode类
//     * @param q TreeNode类
//     * @return TreeNode类
//     */
//    TreeNode* nearestCommonAncestorHelper(TreeNode* root, TreeNode* p, TreeNode* q)
//    {
//        if (root == nullptr)
//            return nullptr;
//        if (root->val == p->val || root->val == q->val)
//            return root;
//        TreeNode* left = nearestCommonAncestorHelper(root->left, p, q);
//        if (left)
//            return left;
//        TreeNode* right = nearestCommonAncestorHelper(root->right, p, q);
//        if (right)
//            return right;
//        return nullptr;
//    }
//    TreeNode* nearestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        // write code here
//        
//        if (root == nullptr || q == nullptr || p == nullptr)
//            return nullptr;
//        
//        if (root->val == p->val || root->val == q->val)
//            return root;
//        
//        TreeNode* left = nearestCommonAncestorHelper(root->left, p, q);
//        TreeNode* right = nearestCommonAncestorHelper(root->right, p, q);
//        if (left != nullptr && right != nullptr)
//            return root;
//        if (left != nullptr && right == nullptr)
//            return left;
//        if (left == nullptr && right != nullptr)
//            return right;
//        TreeNode* l = nearestCommonAncestor(root->left, p, q);
//        if (l)
//            return l;
//        TreeNode* r = nearestCommonAncestor(root->right, p, q);
//        if (r)
//            return r;
//        return nullptr;
//    }
//};


//int longestSubstringHelper(const string& s1, int begin1
//	, const string& s2, int begin2)
//{
//	int len = 1;
//	++begin2;
//	for (int i = begin1 + 1; i < s1.size() && begin2 < s2.size(); i++)
//	{
//		if (s1[i] != s2[begin2])
//		{
//			break;
//		}
//		else
//		{
//			len++;
//		}
//		begin2++;
//	}
//
//	return len;
//}
//string longestSubstring(const string& lessStr, const string& greaterStr)
//{
//	string maxSub;
//	// 开始遍历 s1 字符串
//	int len = 0;
//	int prev = lessStr.size();
//	for (int i = 0; i < lessStr.size(); i++)
//	{
//
//		int start = 0;
//		while ((start = greaterStr.find(lessStr[i], start)) != string::npos)
//		{
//
//			len = longestSubstringHelper(lessStr, i, greaterStr, start);
//
//			if (len > maxSub.size())
//			{
//				maxSub = lessStr.substr(i, len);
//			}
//			// else if (len == maxSub.size())
//			// {
//			// 	if (start < prev)
//			// 	{
//			// 		maxSub = greaterStr.substr(i, len);
//			// 		prev = start;
//			// 	}
//			// }
//			start = start + 1;
//		}
//
//	}
//	return maxSub;
//}
//int main()
//{
//	string s1;
//	string s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	string greaterStr;
//	string lessStr;
//	if (s1.size() > s2.size())
//	{
//		greaterStr = s1;
//		lessStr = s2;
//	}
//	else
//	{
//		greaterStr = s2;
//		lessStr = s1;
//	}
//
//
//	cout << longestSubstring(lessStr, greaterStr) << endl;
//
//	return 0;
//}
//int longestSubstringHelper(const string& s1, int begin1
//	, const string& s2, int begin2)
//{
//	int len = 1;
//	++begin2;
//	for (int i = begin1+1; i < s1.size() && begin2 < s2.size(); i++)
//	{
//		if (s1[i] != s2[begin2])
//		{
//			break;
//		}
//		else
//		{
//			len++;
//		}
//		begin2++;
//	}
//	
//	return len;
//}
//string longestSubstring(const string& lessStr, const string& greaterStr)
//{
//	string maxSub;
//	// 开始遍历 s1 字符串
//	int len = 0;
//	int prev = lessStr.size();
//	for (int i = 0; i < greaterStr.size(); i++)
//	{
//		int start = 0;
//		while ((start = lessStr.find(greaterStr[i], start)) != string::npos)
//		{
//
//			len = longestSubstringHelper(greaterStr, i, lessStr, start);
//
//			if (len > maxSub.size())
//			{
//				maxSub = greaterStr.substr(i, len);
//			}
//			else if (len == maxSub.size())
//			{
//				if (start < prev)
//				{
//					maxSub = greaterStr.substr(i, len);
//					prev = start;
//				}
//			}
//			start = start + 1;
//		}
//
//	}
//	return maxSub;
//}
//int main()
//{
//	string s1;
//	string s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	string greaterStr;
//	string lessStr;
//	if (s1.size() > s2.size())
//	{
//		greaterStr = s1;
//		lessStr = s2;
//	}
//	else
//	{
//		greaterStr = s2;
//		lessStr = s1;
//	}
//	
//	
//	cout << longestSubstring(lessStr, greaterStr) << endl;
//
//	return 0;
//}

//string longestSubstring(const string& s1, const string& s2)
//{
//	string maxSub;
//	// 开始遍历 s1 字符串
//	int len = 0;
//	
//	string lessString = s1.size() > s2.size() ? s2 : s1;
//    int prev = lessString.size();
//	for (int i = 0; i < s1.size(); i++)
//	{
//
//		int start = 0;
//		while ((start = s2.find(s1[i], start)) != string::npos)
//		{
//			
//			// 找到了 
//			// 这里开始遍历 相同的
//			len = longestSubstringHelper(s1, i, s2, start);
//			
//			if (len > maxSub.size())
//			{
//				maxSub = s1.substr(i, len);
//			}
//			else if(len == maxSub.size())
//			{
//				if (start < prev)
//				{
//					maxSub = s1.substr(i, len);
//					prev = start;
//				}
//			}
//			//if (len < maxSub.size())
//			//{
//			//	// 什么都不做
//			//}
//			//else if (len > maxSub.size())
//			//{
//			//	
//		
//		
//			//		maxSub = s1.substr(i, len);
//		
//			//	
//			//}
//			//else
//			//{
//			//	if (start < prev)
//			//	{
//			//		maxSub = s1.substr(i, len);
//			//		prev = start;
//			//	}
//			//}
//			start = start + 1;
//		}
//		
//	}
//
//
//	return maxSub;
//}
//int main()
//{
//	string s1;
//	string s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	cout << longestSubstring(s1, s2) << endl;
//
//	return 0;
//}
//int bottleToWater(int n)
//{
//	if (n < 2)
//		return 0;
//	if (n == 2)
//		return 1;
//	return n / 3 + bottleToWater(n / 3 + n % 3);
//		
//}
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		cout << bottleToWater(n) << endl;
//	}
//	return 0;
//}
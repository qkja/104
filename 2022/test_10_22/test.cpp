#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

//class Solution {
//public:
//
//
//    bool IsExist(const string& str, vector<string>& dict)
//    {
//        for (int i = 0; i < dict.size(); i++)
//        {
//            if (dict[i] == str)
//                return true;
//        }
//        return false;
//    }
//    //解释一下 从[start,pos]位置,我们切掉的字符串是否可以在 dict中找到
//    bool process1(string& s, int start, int end, vector<string>& dict)
//    {
//        // 这是 递归跳出接口
//
//        if (end == (int)s.size())
//        {
//            if (end == start)
//                return true;
//            string str = s.substr(start, end - start + 1);
//            return IsExist(str, dict);
//        }
//
//        string str = s.substr(start, end - start + 1);
//        // 这里开始查找
//        bool b1 = false;
//        bool b2 = false;
//        /*  if (end == 2)
//          {
//              cout << 1 << endl;
//          }*/
//        if (IsExist(str, dict))
//        {
//            // 找到了
//            b1 = process1(s, end + 1, end + 1, dict)
//                || process1(s, start, end + 1, dict);
//
//        }
//        else
//        {
//            b2 = process1(s, start, end + 1, dict);
//        }
//        return b1 || b2;
//    }
//
//    bool wordBreak(string s, vector<string>& wordDict) {
//        return process1(s, 0, 0, wordDict);
//    }
//};
class Solution {
public:


    bool IsExist(const string& str, vector<string>& dict)
    {
        for (int i = 0; i < dict.size(); i++)
        {
            if (dict[i] == str)
                return true;
        }
        return false;
    }
    //解释一下 从[start,pos]位置,我们切掉的字符串是否可以在 dict中找到

    bool wordBreak(string s, vector<string>& wordDict) {
        int col = s.size();
        int row = col;
        vector<vector<bool>> result;
        result.resize(col + 1);
        for (int i = 0; i < col + 1; i++)
        {
            vector<bool> v(col + 1, 0);
            result[i] = v;
        }
        //这里设置底层
        result[row][col] = true;
        
        for (int i = 0; i < col; i++)
        {
            string str = s.substr(i, col - i + 1);
            bool ret = IsExist(str, wordDict);
            result[row][i] = ret;
        }

        // 这里开始写动归
        for (int i = row - 1; i >= 0; i--)
        {
            for (int j = 0; j < col+1; j++)
            {
                //i ->end
                //j ->be
                //string str = s.substr(start, end - start + 1);
                string str = s.substr(j, i - j + 1);
                bool ret1 = false;
                bool ret2 = false;
                if (IsExist(str, wordDict))
                {
                    ret1 = result[i + 1][i + 1]
                        || result[j][i + 1];
                }
                else
                {
                    ret2 = result[j][i + 1];
                }
                if (i <= j)
                {
                    result[i][j] = ret1 || ret2;
                }
               
            }
        }
        return result[0][0];
    }
};

int main()
{
    //"leetcode"
    //["leet", "code"]
    string str = "lee";
    vector<string> v;
    v.push_back("l");
    v.push_back("ee");
    
    bool b = Solution().wordBreak(str, v);
    cout << b << endl;
    return 0;
}

//class Solution {
//public:
//    bool IsExist(const string& str, unordered_set<string>& dict)
//    {
//        return dict.find(str) != dict.end();
//    }
//
//
//    /*bool IsExist(const string& str, unordered_set<string>& dict)
//    {
//        return dict.find(str) != dict.end();
//    }*/
//  
//    bool wordBreak(string s, unordered_set<string>& dict) {
//        int col = s.size();
//        int row = col;
//        vector<vector<bool>> result;
//        result.resize(col + 1);
//        for (int i = 0; i < col + 1; i++)
//        {
//            vector<bool> v(col + 1, 0);
//            result[i] = v;
//        }
//        //这里设置底层
//        result[row][col] = true;
//        
//        for (int i = 0; i < col; i++)
//        {
//            //这力 i 是start
//            //end = col
//            //string str = s.substr(start, end - start + 1);
//            string str = s.substr(i, col - i + 1);
//            bool ret = IsExist(str, dict);
//            result[row][i] = ret;
//        }
//
//
//        /*for (int i = 0; i < col; i++)
//        {
//            string str = s.substr(i, col - i + 1);
//            bool ret = IsExist(str, dict);
//            result[row][i] = ret;
//        }*/
//
//        // 这里开始写动归
//        for (int i = row - 1; i >=0; i--)
//        {
//            for (int j = 0; j < col + 1; j++)
//            {
//                //string str = s.substr(start, end - start + 1);
//                string str = s.substr(j, i - j + 1);
//                bool ret1 = false;
//                bool ret2 = false;
//                if (IsExist(str, dict))
//                {
//                    ret1 = result[i + 1][i + 1]
//                        || result[j][i + 1];
//                }
//                else
//                {
//                    ret2 = result[j][i + 1];
//                }
//                result[i][j] = ret1 || ret2;
//
//               /* if (IsExist(str, dict))
//                {
//                  ret1 = result[i + 1][i + 1]
//                    || result[j][i + 1];
//                }
//                else
//                {
//                    ret2 = result[j][i + 1];
//                }
//                result[i][j] = ret1 || ret2;*/
//                //bool ret1 = process1(s, end + 1, end + 1, dict);
//                //bool ret2 = process1(s, start, end + 1, dict);
//           
//           }
//        }
//        return result[0][0];
//    }
//};

//class Solution {
//public:
//    bool IsExist(const string& str, unordered_set<string>& dict)
//    {
//        return dict.find(str) != dict.end();
//    }
//    //解释一下 从[start,pos]位置,我们切掉的字符串是否可以在 dict中找到
//    bool process1(string& s, int start, int end, unordered_set<string>& dict)
//    {
//        // 这是 递归跳出接口
//        
//        if (end == (int)s.size())
//        {
//            if (end == start)
//                return true;
//            string str = s.substr(start, end - start + 1);
//            return IsExist(str, dict);
//        }
//
//        string str = s.substr(start, end - start + 1);
//        // 这里开始查找
//        bool b1 = false;
//        bool b2 = false;
//      /*  if (end == 2)
//        {
//            cout << 1 << endl;
//        }*/
//        if (IsExist(str, dict))
//        {
//            // 找到了
//            b1 = process1(s, end + 1, end + 1, dict)
//                || process1(s, start, end + 1, dict);
//
//        }
//        else
//        {
//            b2 = process1(s, start, end + 1, dict);
//        }
//        return b1 || b2;
//    }
//
//    bool wordBreak(string s, unordered_set<string>& dict) {
//        // 我们先来写一个尝试
//        return process1(s, 0, 0, dict);
//    }
//};
//int main()
//{
//    string str = "aabb";
//    string s = str.substr(0, 5);
//    return 0;
//}
//int main()
//{
//    string str = "aabb";
//    unordered_set<string> s;
//    s.insert("a");
//    s.insert("abb");
//    bool b = Solution().wordBreak(str, s);
//    cout << b << endl;
//    return 0;
//}

//class A
//{
//public:
//	int _a;
//};
//
//
//class B
//{
//public:
//	int _b;
//};
//
//class C :public A , public B 
//{
//public:
//	int _c;
//};
//int main()
//{
//	C c;
//	c._a = 1;
//	c._b = 2;
//	c._c = 3;
//	return 0;
//}

//class Solution {
//public:
//	// 写一个尝试
//	// 解释一下 在pos位置及其以后找到几个数何为 sum
//	bool IsExist(vector<int> arr, int pos, int sum)
//	{
//		if (pos == arr.size() && sum != 0)
//			return false;
//		if (sum == 0)
//			return true;
//
//		// 这里没有找到
//		//开始吧
//		bool b1 = false;
//		bool b2 = false;
//		if(arr[pos] <= sum)
//			b1 = IsExist(arr, pos + 1, sum - arr[pos]); // 这里要
//		b2 = IsExist(arr, pos + 1, sum);               // 这里不要
//
//		return b1 || b2;
//	}
//	int getFirstUnFormedNum(vector<int> arr, int len) {
//		if (arr.empty())
//			return -1;
//		int min = arr[0];
//		int max = arr[0];
//		for (int i = 1; i < len; i++)
//		{
//			max += arr[i];
//			if (arr[i] < min)
//				min = arr[i];
//		}
//		// 现在得到 [min, max]
//		// 开始寻找
//		
//		for (int i = min + 1; i < max; i++)
//		{
//			if (!IsExist(arr, 0 ,i))
//			{
//				return i;
//			}
//		}
//		return max + 1;
//	}
//};


//int main()
//{
//	vector<int> v;
//	v.push_back(3);
//	v.push_back(2);
//	v.push_back(1);
//	int ret = Solution().getFirstUnFormedNum(v, v.size());
//	cout << ret << endl;
//
//	return 0;
//}



//int main()
//{
//	//http//www.taobao.com;
//	return 0;
//}

//////////////////////////////////////////
// day 12
// HJ60 查找组成一个偶数最接近的两个素数
// 这里是一个暴力法 N2
// 可以从一半来判断 看看10 10  9 和 11 这里一次来找 N2
// 不过本质没变 但是思想高了一筹
//#include <iostream>
//#include <map>
//#include <stdlib.h>
//using namespace std;
//bool IsPrime(int n)
//{
//    if (n < 2)
//        return false;
//    for (int i = 2; i < n - 1; i++)
//    {
//        if (n % i == 0)
//            return false;
//    }
//    return true;
//}
//int main() {
//    int n = 0;
//    while (cin >> n) { // 注意 while 处理多个 case
//        map<int, int> m; // sum 和  
//        for (int i = 0; i <= n; i++)
//        {
//            if (IsPrime(i) && IsPrime(n - i))
//            {
//                // 这里都是 素数
//                int sub = i - (n - i);
//                m[abs(sub)] = i;
//            }
//        }
//        int min = m.begin()->second;
//        int max = n - min;
//        if (min > max)
//            swap(min, max);
//        cout << min << endl;
//        cout << max << endl;
//    }
//}
//
//
//// 二进制插入
//class BinInsert {
//public:
//    int binInsert(int n, int m, int j, int i) {
//        // 这里就不判断了  按照提议所说
//        // write code here
//        m = m << j;
//        return n | m;
//    }
//};
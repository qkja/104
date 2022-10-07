#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;



/////////////////////////////////////////////////////
// day 4
class Solution {
public:
    string solve(int M, int N) {
        // write code here
        int flag = 0;
        if (M <= 0)
        {
            flag = 1; //负数
            M = -M;
        }
        char table[] = "0123456789ABCDEF";
        string str;
        while (M)
        {
            int ret = M % N;
            str += table[ret];
            M /= N;
        }
        if (flag == 1)
        {
            str += '-';
        }
        reverse(str.begin(), str.end());
        return str;
        // 这个 用 取余法
    }
};

//int main()
//{
//	int x = 0;
//	int y = 0;
//	int z = 0;
//	int m = 0;
//	cin >> x >> y >> z >> m;
//	// 计算  b
//	int a = (x + z) / 2;
//	if (2 * a != (x + z))
//	{
//		cout << "No" << endl;
//		return 0;
//	}
//	int b = a - x;
//	int c = m - b;
//	if (a < 0 || b < 0 || c < 0)
//	{
//		cout << "No" << endl;
//	}
//	else
//	{
//		cout << a << " " << b << " " << c << endl;
//	}
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////
// day 3
//class Solution {
//public:
//    //数组中出现次数超过一半的数字
//    int MoreThanHalfNum_Solution(vector<int> numbers) {
//        if (numbers.empty())
//            return 0;
//         //这里我们用 打擂台的方式
//        int ret = 0;
//        int flag = 0;
//
//        for (int i = 0; i < numbers.size(); i++)
//        {
//            if (flag == 0)
//            {
//                ret = numbers[i];
//                flag = 1;
//            }
//            else if (numbers[i] == ret)
//            {
//                flag++; // 遇到相同的 擂台上增加一个
//            }
//            else
//            {
//                flag--;
//            }
//        }
//        // 擂台上站的 一个或者 几个 就是我们要的
//        // 至于是不是要验证一下  这里看题意了
//        int count = 0;
//        for (int i = 0; i < numbers.size(); i++)
//        {
//            if (ret == numbers[i])
//            {
//                count++;
//                if (count > numbers.size() / 2)
//                {
//                    return ret;
//                }
//            }
//        }
//        return 0;
//    }
//};

//int main()
//{
//    string str;
//    getline(cin, str);
//    str += '#'; //这个作用防止 aaaa111222这个情况 或者 不加  i <= str.size()
//    string cur;
//    string ret;
//    for (int i = 0; i < str.size(); i++)
//    {
//        if (str[i] >= '0' && str[i] <= '9')
//        {
//            cur += str[i];
//        }
//        else
//        {
//            if (cur.size() > ret.size())
//            {
//                ret = cur;
//            }
// 
//            cur.clear();
//     
//        }
//    }
//    cout << ret << endl;
//	return 0;
//}

//int main()
//{
//	string str;
//	getline(cin, str);
//	int flag = 0;
//	int begin = 0;
//	int prevBegin = 0;
//	int max = 0;
//	int count = 0;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] >= '0' && str[i] <= '9')
//		{
//			if (flag == 0)
//			{
//				//第一次找到
//				begin = i;
//				flag = 1; // 
//			}
//			count++; //记录连续找到的次数
//		}
//		else
//		{
//			// 找到了 第一个不是 0-9的字符
//			if (flag == 1)
//			{
//				if (count > max)
//				{
//					max = count;
//					prevBegin = begin;
//				}
//				flag = 0;  // 重新开始
//				count = 0; // 重新计数
//			}
//		}
//	}
//	// 这个 最后一次 找到的 也就是尾部  数字
//	if (flag == 1)
//	{
//		if (count > max)
//		{
//			max = count;
//			prevBegin = begin;
//		}
//		flag = 0;
//	}
//
//	for (int i = 0; i < max; i++)
//	{
//		cout << str[prevBegin + i];
//	}
//	cout << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string str;
//	getline(cin, str);
//	int begin = 0;
//	int len = 0;
//	int result = 0;
//	for (int i = 0; i < str.size(); i++)
//	{
//		// 这里 寻找第一个 数字
//		if (str[i] >= '0' && str[i] <= '9')
//		{
//			begin = i;
//			while (i  < str.size() && str[i] >= '0' && str[i] <= '9')
//			{
//				i++;
//			}
//
//			if (i - begin > len)
//			{
//				//len = i
//				result = begin; // 记录开始位置
//				len = i - begin;// 记录长度
//			}
//		}
//	}
//	for (int i = 0;i < len; i++)
//	{
//		cout << str[result + i];
//	}
//	return 0;
//}
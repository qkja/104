#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
using namespace std;
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
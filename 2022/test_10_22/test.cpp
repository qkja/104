#define _CRT_SECURE_NO_WARNINGS 1



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
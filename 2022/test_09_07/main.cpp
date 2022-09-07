#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;



//class Solution {
//public:
//    int MoreThanHalfNum_Solution(vector<int> numbers) {
//        if (numbers.empty())
//            return 0;
//        map<int, int> m;
//        for (auto& e : numbers)
//        {
//            m[e]++;
//        }
//        auto it = m.begin();
//        while (it != m.end())
//        {
//            if (it->second > (numbers.size() / 2))
//                return it->first;
//            ++it;
//        }
//        return 0;
//    }
//};
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
//				flag = 1;
//			}
//			count++;
//		}
//		else
//		{
//			// 找到了
//			if (flag == 1)
//			{
//				if (count > max)
//				{
//					max = count;
//					prevBegin = begin;
//				}
//				flag = 0;
//				count = 0;
//			}
//		}
//	}
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
//
//}

//int main() {
//
//    int n;
//    cin >> n;
//    vector<int> v;
//    v.resize(n);
//    int tmp = 0;
//    while (n--) {
//        cin >> v[tmp++];
//    }
//    int ret = 0, i = 0;
//    while (i < v.size()) {
//        if (v[i] < v[i + 1]) {
//            while (i < v.size() && v[i] <= v[i + 1]) // 遍历非递减
//                ++i;
//            ++i, ++ret;
//        }
//        else if (v[i] == v[i + 1]) // 相等时不能判断
//            ++i;
//        else {
//            while (i < v.size() && v[i] >= v[i + 1]) // 遍历非递增
//                ++i;
//            ++i, ++ret;
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}








//void sentenceInversion(string& str)
//{
//	int ret = str.find(' ') - 0;
//	auto it = str.begin();
//	while (ret != string::npos)
//	{
//		// 找到了
//		//首先逆置
//		reverse(it, it+ret-(it-str.begin()));
//		it = str.begin() + ret + 1;
//		//int newRet = str.find(' ', ret + 1);
//		ret = str.find(' ', ret + 1);
//		if (ret == string::npos)
//		{
//			reverse(it, str.end());
//		}
//	}
//	reverse(str.begin(), str.end());
//}
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	sentenceInversion(str);
//	//reverse(str.begin(), str.end());
//
//	cout << str;
//	return 0;
//}
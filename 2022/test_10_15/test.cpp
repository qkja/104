#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <iostream>
#include <string>
using namespace std;
//int main()
//{
//	string less;
//	string greater;
//	getline(cin, less);
//	getline(cin, greater);
//	if (less.size() > greater.size())
//		swap(less, greater);
//
//}
//int main()
//{
//	string less;
//	string greater;
//	getline(cin, less);
//	getline(cin, greater);
//	if (less.size() > greater.size())
//		swap(less, greater);
//
//	vector<int> result;
//	if (less[0] == greater[0])
//		result.push_back(0);
//	else
//		result.push_back(1);
//
//	// 这里只看 less 后面补充 要添加的
//
//
//	return 0;
//}


//class Gift {
//public:
//    // 该红包的次数出现超过总数的一半
//    // 这里我们用打擂台的方法
//    int getValue(vector<int> gifts, int n) {
//        // write code here
//        if (gifts.empty())
//            return 0;
//        int flag = gifts[0];
//        int count = 1;
//        for (size_t i = 1; i < gifts.size(); i++)
//        {
//            if (count == 0)
//            {
//                flag = gifts[i];
//                count = 1;
//                continue;
//            }
//            if (gifts[i] == flag)
//            {
//                count++;
//            }
//            else
//            {
//                // 不相等
//                // 这里 --
//                count--;
//            }
//        }
//        count = 0;
//
//        // 验证
//        for (size_t i = 0; i < gifts.size(); i++)
//        {
//            if (gifts[i] == flag)
//                count++;
//        }
//        if (count > gifts.size() / 2)
//            return flag;
//        else
//            return 0;
//    }
//};
/*
* 设Ai为字符串A(a1a2a3 … am)的前i个字符（即为a1, a2, a3 … ai）
* 设Bj为字符串B(b1b2b3 … bn)的前j个字符（即为b1, b2, b3 … bj）
*
* 设 L(i, j)为使两个字符串和Ai和Bj相等的最小操作次数。
* 当ai == bj时 显然 L(i, j) = L(i - 1, j - 1)
* 当ai != bj时
*
* 若将它们修改为相等，则对两个字符串至少还要操作L(i - 1, j - 1)次
* 若删除ai或在bj后添加ai，则对两个字符串至少还要操作L(i - 1, j)次
* 若删除bj或在ai后添加bj，则对两个字符串至少还要操作L(i, j - 1)次
* 此时L(i, j) = min(L(i - 1, j - 1), L(i - 1, j), L(i, j - 1)) + 1
*
*显然，L(i, 0) = i，L(0, j) = j, 再利用上述的递推公式，可以直接计算出L(i, j)值。
*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    string s1, s2;
// 
//    vector<vector<int>> result(s1.size() + 1, vector<int>(s2.size() + 1, 0));
//
//    for (int i = 0; i <= s1.size(); i++)
//        result[i][0] = i;
//    for (int j = 0; j <= s2.size(); j++)
//        result[0][j] = j;
//    for (int i = 1; i <= s1.size(); i++) 
//    {
//        for (int j = 1; j <= s2.size(); j++) 
//        {
//            if (s1[i - 1] == s2[j - 1]) result[i][j] = result[i - 1][j - 1];
//            else {
//                result[i][j] = min({ result[i - 1][j] + 1, result[i][j - 1] + 1,result[i - 1][j - 1] + 1 });
//            }
//        }
//    }
//    cout << result[s1.size()][s2.size()] << endl;;
//
//    return 0;
//}

class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        // write code here
    }
};
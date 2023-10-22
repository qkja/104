/**
* User: Qkj
* Description: 
* Date: 2023-06-02
* Time: 16:52
*/
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// day 8
// 引用的 底层是由指针实现的,本质就是一个指针 
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
// 64 位输出请用 printf("%lld")





#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
      int maxVal = max(a, b);
      for(int i = maxVal; i <= a*b; i++)
      {
        if(i%a == 0 && i%b == 0)
        {
          cout << i << endl;
          break;
        }
      }
    }
    return 0;
}


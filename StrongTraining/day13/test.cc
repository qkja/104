/**
 * User: Qkj
 * Description: 
 * Date: 2023-06-08
 * Time: 15:06
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;
//int main() {
//  string str;
//  getline(cin, str);
//  str += ' ';
//  bool flag = false;
//  string str2;
//  vector<string> v;
//  for (size_t i = 0; i < str.size(); i++) {
//    if (str[i] == '\"') {
//      if (flag == false) {
//        flag = true;
//      } else {
//        v.push_back(str2);
//        str2.clear();
//        flag = false;
//      }
//    } else if (str[i] == ' ') {
//      if (flag == true) {
//        str2 += str[i];
//      } 
//      else {
//        if(!str2.empty())
//          v.push_back(str2);
//        str2.clear();
//      }
//    } else {
//      str2 += str[i];
//    }
//  }
//  cout << v.size() << endl;
//  for (size_t i = 0; i < v.size(); i++)
//    cout << v[i] << endl;
//  return 0;
//}
// 64 位输出请用 printf("%lld")




#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <algorithm>
using namespace std;
void get_dic_num(int val, std::vector<int> &v)
{
  for (size_t i = 2; i <= sqrt(val); i++)
  {
    if (val % i == 0)
    {
      v.push_back(i);
      if(val / i != i)
      {
        v.push_back(val/i);
      }
    }
  }
}
int Jump(int n, int m)
{
  std::vector<int> step(m + 1, INT_MAX);
  step[n] = 0; // 从n 到 n  0 步
  for (size_t i = n; i < step.size(); i++)
  {
    if (step[i] == INT_MAX)
      continue;
    std::vector<int> v;
    get_dic_num(i, v); // 获取 约数并保存
    for (size_t j = 0; j < v.size(); j++)
    {
      if (i + v[j] < step.size())
      {
        step[i + v[j]] = min(step[i + v[j]], step[i] + 1);
      }
    }
  }
  if (step[m] == INT_MAX)
    return -1;
  else
    return step[m];
}
int main()
{
  int n = 0;
  int m = 0;
  int minStep;
  while (cin >> n >> m)
  {
    minStep = Jump(n, m);
    cout << minStep << endl;
  }

  return 0;
}

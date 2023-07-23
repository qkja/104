/**
 * User: Qkj
 * Description:
 * Date: 2023-05-26
 * Time: 10:24
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// https://www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212?tpId=85&&tqId=29868&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
int main()
{
  std::string str1;
  std::string str2;
  std::getline(std::cin, str1);
  std::getline(std::cin, str2);

  std::unordered_set<char> set;
  for (auto &e : str2)
  {
    set.insert(e);
  }
  std::string result;
  for (auto &e : str1)
  {
    auto iter = set.find(e);
    if (iter == set.end())
      result += e;
  }
  std::cout << result << std::endl;
  return 0;
}

// https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue=1&page=1&onlyReference=false
// long long maxSum(const std::vector<long long>& v, int n)
//{
//  long long sum = 0;
//  for(std::size_t i = n; i < v.size(); i+=2)
//    sum += v[i];
//  return sum;
//}
//
// int main() {
//    int n = 0;
//
//    while (cin >> n)
//    {
//      std::vector<long long> v(3*n);
//      for(int i = 0; i < 3*n; i++)
//        cin >> v[i];
//      std::sort(v.begin(), v.end());
//      std::cout << maxSum(v , n) << std::endl;
//    }
//    return 0;
//}



/**
 * User: Qkj
 * Description:
 * Date: 2023-05-18
 * Time: 23:27
 */
#include <vector>
using namespace std;
// https://leetcode.cn/problems/n-th-tribonacci-number/submissions/
// 状态表示什么 就是dp 表里面的一个值
// 如何来的
// 1. 题目要求(简单题目)
// 2. 经验+题目要求(大量做题100-200)
// 3.分析问题的过程中发现子问题(更加抽象)
class Solution
{
public:
  /// @brief 这是一个尝试
  /// @param n 第n个
  /// @return  我们第n个的值
  int process(int n)
  {
    if (n == 0)
      return 0;
    if (n == 1 || n == 2)
      return 1;
    return process(n - 3) + process(n - 2) + process(n - 1);
  }
  /// @brief 我们修改dp
  /// @param n [0, n]
  /// @return dp[n]
  // int dp(int n)
  // {
  //   if (n == 0)
  //     return 0;
  //   if (n == 1 || n == 2)
  //     return 1;
  //   std::vector<int> v(n + 1, 0);
  //   v[1] = 1;
  //   v[2] = 1;
  //   for (int i = 3; i < v.size(); i++)
  //   {
  //     v[i] = v[i - 3] + v[i - 2] + v[i - 1];
  //   }
  //   return v[n];
  // }

  /// @brief 优化
  /// @param n
  /// @return
  int dp(int n)
  {
    if (n == 0)
      return 0;
    if (n == 1 || n == 2)
      return 1;
    int result = 0;
    std::vector<int> v(n + 1, 0);
    int a = 0;
    int b = 1;
    int c = 1;

    for (int i = 3; i < n + 1; i++)
    {
      result = a + b + c;
      a = b;
      b = c;
      c = result;
    }
    return result;
  }

  int tribonacci(int n)
  {
    // return process(n);
    return dp(n);
  }
};
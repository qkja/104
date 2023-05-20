/**
 * User: Qkj
 * Description:
 * Date: 2023-05-18
 * Time: 23:27
 */
#include <vector>
using namespace std;
// https://leetcode.cn/problems/min-cost-climbing-stairs/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      if(cost.empty())
        return 0;
      vector<int> dp(cost.size()+1, 0);
      for(size_t i = 2; i < dp.size(); i++)
      {
        dp[i] = std::min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
      }
      return dp[cost.size()];
    }
};














// https://leetcode.cn/problems/three-steps-problem-lcci/
//class Solution {
//  public:
//    int process(int index, int n)
//    {
//      if(index == n)
//        return 1;
//      if(index > n)
//        return 0;
//      int p1 = process(index + 1, n);
//      int p2 = process(index + 2, n);
//      int p3 = process(index + 3, n);
//      return p1 + p2 + p3;
//    }
//    int process2(int n)
//    {
//      std::vector<int> dp(n + 3, 0);
//      dp[n] = 1;
//      for(int i = n-1; i >= 0; i--)
//        dp[i] = dp[i+1] + dp[i+2] + dp[i+3];
//      return dp[0];
//    }
//
//    int process3(int n)
//    {
//      if(n == 1)
//        return 1;
//      if(n == 2)
//        return 2;
//      if(n == 3)
//        return 4;
//      const int MOD = 1e9 + 7;
//      std::vector<int> dp(n+1, 0);
//      dp[1] = 1;
//      dp[2] = 2;
//      dp[3] = 4;
//      for(int i = 4; i < (int)dp.size(); i++)
//        dp[i] = ((dp[i-1] + dp[i-2])%MOD + dp[i-3]) % MOD;
//      return dp[n];
//    }
//    int waysToStep(int n) {
//      if(n == 0)
//        return 0;
//      //return process(0, n);
//      return process2 (n);
//    }
//};





// https://leetcode.cn/problems/n-th-tribonacci-number/submissions/
// 状态表示什么 就是dp 表里面的一个值
// 如何来的
// 1. 题目要求(简单题目)
// 2. 经验+题目要求(大量做题100-200)
// 3.分析问题的过程中发现子问题(更加抽象)
//class Solution
//{
//public:
//  /// @brief 这是一个尝试
//  /// @param n 第n个
//  /// @return  我们第n个的值
//  int process(int n)
//  {
//    if (n == 0)
//      return 0;
//    if (n == 1 || n == 2)
//      return 1;
//    return process(n - 3) + process(n - 2) + process(n - 1);
//  }
//  /// @brief 我们修改dp
//  /// @param n [0, n]
//  /// @return dp[n]
//  // int dp(int n)
//  // {
//  //   if (n == 0)
//  //     return 0;
//  //   if (n == 1 || n == 2)
//  //     return 1;
//  //   std::vector<int> v(n + 1, 0);
//  //   v[1] = 1;
//  //   v[2] = 1;
//  //   for (int i = 3; i < v.size(); i++)
//  //   {
//  //     v[i] = v[i - 3] + v[i - 2] + v[i - 1];
//  //   }
//  //   return v[n];
//  // }
//
//  /// @brief 优化
//  /// @param n
//  /// @return
//  int dp(int n)
//  {
//    if (n == 0)
//      return 0;
//    if (n == 1 || n == 2)
//      return 1;
//    int result = 0;
//    std::vector<int> v(n + 1, 0);
//    int a = 0;
//    int b = 1;
//    int c = 1;
//
//    for (int i = 3; i < n + 1; i++)
//    {
//      result = a + b + c;
//      a = b;
//      b = c;
//      c = result;
//    }
//    return result;
//  }
//
//  int tribonacci(int n)
//  {
//    // return process(n);
//    return dp(n);
//  }
//};

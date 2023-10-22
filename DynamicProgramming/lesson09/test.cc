/**
 * User: Qkj
 * Description: 完全背包问题
 * Date: 2023-06-15
 * Time: 21:03
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// https://www.nowcoder.com/practice/237ae40ea1e84d8980c1d5666d1c53bc?tpId=230&tqId=2032575&ru=/exam/oj&qru=/ta/dynamic-programming/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196
// int main()
// {
//   int v = 0;
//   int n = 0;
//   cin >> n >> v;
//   vector<int> vi(n, 0); // 体积
//   vector<int> wi(n, 0); // 价值
//   for (int i = 0; i < n; i++)
//     cin >> vi[i] >> wi[i];

//   // 第一个
//   vector<vector<int>> dp(n + 1, vector<int>(v + 1, 0));
//   // 从上往下  -- 从左往右
//   for (int i = 1; i <= n; i++)
//   {
//     for (int j = 0; j <= v; j++)
//     {
//       dp[i][j] = dp[i - 1][j];
//       if (j >= vi[i - 1])
//         dp[i][j] = max(dp[i][j], dp[i][j - vi[i - 1]] + wi[i - 1]);
//     }
//   }
//   cout << dp[n][v] << endl;
//   dp[0][0] = 0;
//   for (int i = 1; i <= v; i++)
//     dp[0][i] = -1;
//   for (int i = 1; i <= n; i++)
//   {
//     for (int j = 0; j <= v; j++)
//     {
//       dp[i][j] = dp[i - 1][j];
//       if (j >= vi[i - 1] && dp[i][j - vi[i - 1]] != -1)
//         dp[i][j] = max(dp[i][j], dp[i][j - vi[i - 1]] + wi[i - 1]);
//     }
//   }
//   int ret = dp[n][v] == -1 ? 0 : dp[n][v];
//   cout << ret << endl;

//   return 0;
// }
// 64 位输出请用 printf("%lld")
// https://leetcode.cn/problems/coin-change/

// class Solution
// {
// public:
//   int coinChange(vector<int> &coins, int amount)
//   {
//     // 1. 创建 dp 表
//     // 2. 初始化
//     // 3. 填表
//     // 4. 返回值
//     const int INF = 0x3f3f3f3f;
//     int n = coins.size();
//     vector<int> dp(amount + 1, INF);
//     dp[0] = 0;
//     for (int i = 1; i <= n; i++)
//       for (int j = coins[i - 1]; j <= amount; j++)
//         dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
//     return dp[amount] >= INF ? -1 : dp[amount];
//   }
// };

// https://leetcode.cn/problems/coin-change-ii/
// class Solution
// {
// public:
//   int change(int amount, vector<int> &coins)
//   {
//     if (coins.empty())
//       return 0;
//     int n = coins.size();
//     int m = amount;
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//     dp[0][0] = 1;
//     for (size_t i = 1; i <= n; i++)
//     {
//       for (size_t j = 0; j <= m; j++)
//       {
//         dp[i][j] = dp[i - 1][j];
//         if (j >= coins[i - 1])
//           dp[i][j] += dp[i][j - coins[i - 1]];
//       }
//     }
//     return dp[n][m];
//   }
// };

// https://leetcode.cn/problems/perfect-squares/
class Solution
{
public:
  int numSquares(int n)
  {
    int m = sqrt(n);
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
      dp[0][i] = 0x3f3f3f3f;
    for (int i = 1; i <= m; i++)
    {
      for (int j = 0; j <= n; j++)
      {
        dp[i][j] = dp[i - 1][j];
        if (j >= i * i)
          dp[i][j] = min(dp[i][j], dp[i][j - i * i] + 1);
      }
    }
    return dp[m][n];
  }
};
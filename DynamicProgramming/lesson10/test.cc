/**
 * User: Qkj
 * Description: 二维费用的背包问题
 * Date: 2023-06-16
 * Time: 19:44
 */
#include <vector>
#include <string>

using namespace std;

// https://leetcode.cn/problems/ones-and-zeroes/
// class Solution
// {
// public:
//   void count(string &str, int &a, int &b)
//   {
//     for (size_t i = 0; i < str.size(); i++)
//     {
//       if (str[i] == '0')
//         a++;
//       else
//         b++;
//     }
//   }
//   int findMaxForm(vector<string> &strs, int m, int n)
//   {
//     if (strs.empty())
//       return 0;
//     int len = strs.size();
//     vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
//     for (int i = 1; i <= len; i++)
//     {
//       for (int j = 0; j <= m; j++)
//       {
//        for (int k = 0; k <= n; k++)
//         {
//           dp[i][j][k] = dp[i - 1][j][k];
//           int a = 0;
//           int b = 0;
//           count(strs[i - 1], a, b);
//           if (j >= a && k >= b)
//             dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - a][k - b] + 1);
//         }
//       }
//     }
//     return dp[len][m][n];
//   }
// };
// https://leetcode.cn/problems/profitable-schemes/
class Solution
{
public:
  int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
  {
    if (group.empty() || profit.empty())
      return 0;
    int len = group.size();
    vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0)));
    // 没有任务
    int MOD = 1e9 + 7;
    for (int i = 0; i <= n; i++)
      dp[0][i][0] = 1; // 选出来一个空集
    for (int i = 1; i <= len; i++)
    {
      for (int j = 0; j <= n; j++)
      {
        for (int k = 0; k <= minProfit; k++)
        {
          dp[i][j][k] = dp[i - 1][j][k];

          if (j >= group[i - 1])
            dp[i][j][k] += dp[i - 1][j - group[i - 1]][max(0, k - profit[i - 1])];
          dp[i][j][k] %= MOD;
        }
      }
    }
    return dp[len][n][minProfit];
  }
};
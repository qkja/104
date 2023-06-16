/**
 * User: Qkj
 * Description: 卡特兰数
 * Date: 2023-06-16
 * Time: 19:45
 */
#include <vector>
using namespace std;

// https://leetcode.cn/problems/unique-binary-search-trees/
class Solution
{
public:
  int numTrees(int n)
  {
    if (n == 0)
      return 1;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (size_t i = 1; i <= n; i++)
    {
      for (int j = 1; j <= i; j++)
      {
        dp[i] += dp[i - j] * dp[j - 1];
      }
    }
    return dp[n];
  }
};
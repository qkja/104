/**
 * User: Qkj
 * Description: 似包非包
 * Date: 2023-06-16
 * Time: 19:45
 */
#include <vector>
using namespace std;
// https://leetcode.cn/problems/combination-sum-iv/
class Solution
{
public:
  int combinationSum4(vector<int> &nums, int target)
  {
    if (nums.empty())
      return 0;

    vector<double> dp(target + 1, 0);
    dp[0] =1;
    for (int i = 1; i <= target; i++)
    {
      for (auto x : nums)
        if (i >= x)
          dp[i] += dp[i - x];
    }
    return dp[target];
  }
};
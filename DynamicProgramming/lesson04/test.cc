/**
 * User: Qkj
 * Description: 子数组 子序列问题
 * Date: 2023-05-30
 * Time: 16:34
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
// https://leetcode.cn/problems/maximum-subarray/submissions/
class Solution
{
public:
  int process3(vector<int> &nums)
  {
    // dp[i] 表示我们在 0-i里面的中连续和的最大值
    //
    // ,如果我们的v[i]+dp[i-1] < v[i],不如把最大的和给v[i]
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    int maxSum = dp[0];
    for (int i = 1; i < nums.size(); i++)
    {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
      maxSum = max(maxSum, dp[i]);
    }
    // 返回值
    return maxSum;
  }
  int maxSubArray(vector<int> &nums)
  {
    if (nums.empty())
      return 0;
    return process3(nums);
  }
};
// https://leetcode.cn/problems/maximum-sum-circular-subarray/
class Solution
{
public:
  int process3(vector<int> &nums)
  {

    int n = nums.size();
    vector<int> f(n + 1, 0);
    vector<int> g(n + 1, 0);
    int maxSum = INT32_MIN;
    int minSum = INT32_MAX;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
      sum += nums[i - 1];
      // 最大值
      f[i] = max(f[i - 1] + nums[i - 1], nums[i - 1]);
      maxSum = max(maxSum, f[i]);

      // 最小值
      g[i] = min(g[i - 1] + nums[i - 1], nums[i - 1]);
      minSum = min(minSum, g[i]);
    }
    // 返回值
    int ret = sum - minSum;
    if (sum == minSum)
    {
      return maxSum;
    }
    else
    {
      return max(sum - minSum, maxSum);
    }
  }
  int maxSubarraySumCircular(vector<int> &nums)
  {
    if (nums.empty())
      return 0;
    return process3(nums);
  }
};

// https://leetcode.cn/problems/maximum-product-subarray/
class Solution
{
public:
  int process3(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> f(n + 1, 1);
    vector<int> g(n + 1, 1);
    int maxSum = INT32_MIN;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
      // 最大值
      int ret = nums[i - 1];
      f[i] = max(ret, max(f[i - 1] * ret, ret * g[i - 1]));
      maxSum = max(maxSum, f[i]);
      g[i] = min(min(f[i - 1] * ret, ret * g[i - 1]), ret);
    }

    return maxSum;
  }
  int maxProduct(vector<int> &nums)
  {
    if (nums.empty())
      return 0;
    return process3(nums);
  }
};
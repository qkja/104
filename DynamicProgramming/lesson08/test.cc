/**
 * User: Qkj
 * Description:
 * Date: 2023-06-13
 * Time: 23:39
 */
// https://www.nowcoder.com/practice/fd55637d3f24484e96dad9e992d3f62e?tpId=230&tqId=2032484&ru=/exam/oj&qru=/ta/dynamic-programming/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196

// #include <iostream>
// #include <vector>

// using namespace std;
// // 处于当前位置index,我们背包的剩余量还有bag,我们可以拿到的最大的价值
// int process(int index, vector<int> &vi, vector<int> &wi, int bag)
// {
//   if (bag < 0)
//     return -1; // 做个标记
//   if (index == vi.size())
//     return 0; // 此时我们物品已经选完了
//   // 不要这个物品
//   int p1 = process(index + 1, vi, wi, bag);
//   // 要这个位置 -- 不是想要就可以要的
//   int p2 = 0;
//   int next = process(index + 1, vi, wi, bag - vi[index]);
//   if (next != -1)
//     p2 = wi[index] + next;
//   return max(p1, p2);
// }

// // 此时我们了解到 我们的转台表示里面是携带  当背包为0的时候的
// int process3(vector<int> &vi, vector<int> &wi, int bag)
// {
//   int n = vi.size();
//   int m = bag;
//   vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//   for (int i = 1; i <= m; i++)
//     dp[0][i] = -1;

//   for (int i = 1; i <= n; i++)
//   {
//     for (int j = 0; j <= m; j++) // 修改遍历顺序
//     {
//       dp[i][j] = dp[i - 1][j];
//       if (j >= vi[i] && dp[i - 1][j - vi[i]] != -1)
//         dp[i][j] = max(dp[i][j], dp[i - 1][j - vi[i]] + wi[i]);
//     }
//   }
//   return dp[0][m] == -1 ? 0 : dp[0][m];
// }
// int process2(vector<int> &vi, vector<int> &wi, int bag)
// {
//   int n = vi.size();
//   int m = bag;
//   vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//   for (int i = n - 1; i >= 0; i--)
//   {
//     for (int j = m; j >= 0; j--)
//     {
//       int p1 = dp[i + 1][j];
//       int p2 = 0;
//       if (j - vi[i] >= 0)
//         p2 = wi[i] + dp[i + 1][j - vi[i]];
//       dp[i][j] = max(p1, p2);
//     }
//   }

//   return dp[0][m];
// }

// int main()
// {
//   int n = 0;
//   vector<int> vi;
//   vector<int> wi;
//   int v = 0; // 体积
//   cin >> n >> v;
//   vi.resize(n);
//   wi.resize(n);
//   for (int i = 0; i < n; i++)
//   {
//     cin >> vi[i] >> wi[i];
//   }

//   cout << process2(vi, wi, v) << endl;
//   cout << process3(vi, wi, v) << endl;
//   return 0;
// }
// 64 位输出请用 printf("%lld")

// #include <iostream>
// #include <string.h>
// using namespace std;
// const int N = 1010;
// int n, V, v[N], w[N];
// int dp[N][N];
// int main()
// {
//   // 读入数据
//   cin >> n >> V;
//   for (int i = 1; i <= n; i++)
//     cin >> v[i] >> w[i];
//   // 解决第一问
//   for (int i = 1; i <= n; i++)
//     for (int j = 0; j <= V; j++) // 修改遍历顺序
//     {
//       dp[i][j] = dp[i - 1][j];
//       if (j >= v[i])
//         dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
//     }
//   cout << dp[n][V] << endl;
//   // 解决第二问
//   memset(dp, 0, sizeof dp);
//   for (int j = 1; j <= V; j++)
//     dp[0][j] = -1;
//   for (int i = 1; i <= n; i++)
//     for (int j = 0; j <= V; j++) // 修改遍历顺序
//     {
//       dp[i][j] = dp[i - 1][j];
//       if (j >= v[i] && dp[i - 1][j - v[i]] != -1)
//         dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
//     }
//   cout << (dp[n][V] == -1 ? 0 : dp[n][V]) << endl;
//   return 0;
// }

// https://leetcode.cn/problems/partition-equal-subset-sum/
#include <vector>
using namespace std;
// class Solution
// {
// public:
//   bool process(vector<int> &nums)
//   {
//     int n = nums.size();
//     int sum = 0;
//     for (auto &e : nums)
//       sum += e;
//     if (sum % 2 == 1)
//       return false;
//     int m = sum / 2;
//     vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
//     for (int i = 0; i <= n; i++)
//       dp[i][0] = true;
//     for (int i = 1; i <= n; i++)
//     {
//       for (int j = 1; j <= m; j++)
//       {
//         dp[i][j] = dp[i - 1][j];
//         if ((j - nums[i - 1]) >= 0)
//           dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
//       }
//     }
//     return dp[n][m];
//   }
//   bool canPartition(vector<int> &nums)
//   {
//     if (nums.empty())
//       return true;
//     return process(nums);
//   }
// };
// https://leetcode.cn/problems/target-sum/
// class Solution
// {
// public:
//   int process(vector<int> &nums, int target)
//   {
//     int sum = 0;
//     for (auto &e : nums)
//       sum += e;

//     int a = (sum + target) / 2;
//     if (a < 0 || (sum + target) % 2 != 0)
//     {
//       return 0;
//     }
//     // cout <<" --" << endl;
//     int n = nums.size();
//     int m = a;
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//     dp[0][0] = 1;
//     // cout <<" --" << endl;

//     for (int i = 1; i <= n; i++)
//     {
//       for (int j = 0; j <= m; j++)
//       {
//         dp[i][j] = dp[i - 1][j];
//         if (j >= nums[i - 1])
//           dp[i][j] += dp[i - 1][j - nums[i - 1]];
//       }
//     }
//     return dp[n][m];
//   }

//   int findTargetSumWays(vector<int> &nums, int target)
//   {
//     if (nums.empty())
//       return 0;
//     return process(nums, target);
//   }
// };

// https://leetcode.cn/problems/last-stone-weight-ii/
// class Solution
// {
// public:
//   int lastStoneWeightII(vector<int> &stones)
//   {
//     // 1. 准备工作
//     int sum = 0;
//     for (auto x : stones)
//       sum += x;
//     int n = stones.size(), m = sum / 2;
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1));
//     for (int i = 1; i <= n; i++)
//       for (int j = 0; j <= m; j++)
//       {
//         dp[i][j] = dp[i - 1][j];
//         if (j >= stones[i - 1])
//           dp[i][j] = max(dp[i][j], dp[i - 1][j - stones[i - 1]] +
//                                        stones[i - 1]);
//       }
//     // 3. 返回结果
//     return sum - 2 * dp[n][m];
//   }
// };
/**
 * User: Qkj
 * Description:
 * Date: 2023-06-26
 * Time: 08:13
 */
#include <iostream>
#include <vector>
using namespace std;
// https://www.nowcoder.com/practice/acead2f4c28c401889915da98ecdc6bf?tpId=230&tqId=2021480&ru=/exam/oj&qru=/ta/dynamic-programming/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196
// int main()
// {
//   int n = 0;
//   int q = 0;

//   while (cin >> n >> q)
//   {
//     vector<int> v(n, 0);
//     for (int i = 0; i < n; i++)
//       cin >> v[i];
//     for (int i = 0; i < q; i++)
//     {
//       int l = 0;
//       int r = 0;
//       cin >> l >> r;
//       l--;
//       r--;
//       long long sum = 0;
//       for (; l <= r && r < n; l++)
//         sum += (long long)v[l];
//       cout << sum << endl;
//     }
//   }
//   return 0;
// }
// 64 位输出请用 printf("%lld")
// 解法二,把这个数组从[i,j]位置开始和保存在一个二维数组中,此时
// 可以根据   1-3 是  0-3的值减去 0-1的值来判断,这里的时间负度 n2
// 这里可以使用一个优化,就像是在背包哪里的优化,二位数组改成一位的,不过我们每一次都要收集结果
// 不过这里你发现没有,此时我们已经拿到答案了,这里就是前缀和
// int main()
// {
//   int n = 0;
//   int q = 0;

//   while (cin >> n >> q)
//   {
//     vector<int> v(n + 1, 0);
//     vector<long long> dp(n + 1, 0);
//     for (int i = 1; i <= n; i++)
//     {
//       cin >> v[i];
//       dp[i] = dp[i - 1] + (long long)v[i];
//     }

//     for (int i = 0; i < q; i++)
//     {
//       int l = 0;
//       int r = 0;
//       cin >> l >> r;

//       cout << dp[r] - dp[l - 1] << endl;
//     }
//   }
//   return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//   int n = 0;
//   int m = 0;
//   int q = 0;
//   while (cin >> n >> m >> q)
//   {
//     vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
//     vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
//     for (int i = 1; i <= n; i++)
//     {
//       for (int j = 1; j <= m; j++)
//       {
//         cin >> v[i][j];
//         dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + v[i][j] - dp[i - 1][j - 1];
//       }
//     }
//     for (int i = 0; i < q; i++)
//     {
//       int x1 = 0;
//       int x2 = 0;
//       int y1 = 0;
//       int y2 = 0;
//       cin >> x1 >> y1 >> x2 >> y2;
//       cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << endl;
//     }
//   }

//   return 0;
// }
// 64 位输出请用 printf("%lld")
// https://leetcode.cn/problems/find-pivot-index/
// class Solution
// {
// public:
//   int pivotIndex(vector<int> &nums)
//   {
//     nums.insert(nums.begin(), 0);
//     vector<int> dp(nums.size(), 0);
//     for (int i = 1; i < nums.size(); i++)
//       dp[i] = dp[i - 1] + nums[i];
//     for (int i = 1; i < nums.size(); i++)
//     {
//       if (dp[i] + dp[i - 1] == dp.back())
//         return i - 1;
//     }
//     return -1;
//   }
// };
// https://leetcode.cn/problems/product-of-array-except-self/
class Solution
{
public:
  // 使用前缀和的变体
  // 前缀积
  // 后缀积
  vector<int> productExceptSelf(vector<int> &nums)
  {
    vector<int> f(nums.size(), 1);
    vector<int> g(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++)
      f[i] = f[i - 1] * nums[i - 1];
    for (int i = nums.size() - 2; i >= 0; i--)
      g[i] = g[i + 1] * nums[i + 1];
    vector<int> ret(nums.size());
    for (int i = 0; i < nums.size(); i++)
      ret[i] = f[i] * g[i];
    return ret;
  }
};
/**
 * User: Qkj
 * Description: 位运算
 * Date: 2023-07-02
 * Time: 23:33
 */
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
// 基础位运算

// https://leetcode.cn/problems/is-unique-lcci/
// 解法一: 使用hash
// 优化:  使用一个 26位的数组
// class Solution
// {
// public:
//   bool isUnique(string astr)
//   {
//     if (astr.empty())
//       return true;
//     unordered_set<char> set;
//     for (auto e : astr)
//       set.insert(e);
//     return set.size() == astr.size();
//   }
// };
// 继续优化: 使用 位图的思想
//
// class Solution
// {
// public:
//   bool isUnique(string astr)
//   {
//     // 利用鸽巢原理
//     if (astr.size() > 26)
//       return false;
//     int bitMap = 0;
//     for (auto e : astr)
//     {
//       int i = e - 'a';
//       if ((bitMap >> i) & 1 == 1)
//         return false;
//       else
//         bitMap |= 1 << i;
//     }
//     return true;
//   }
// };
// https://leetcode.cn/problems/missing-number/
// class Solution
// {
// public:
//   int missingNumber(vector<int> &nums)
//   {
//     int n = nums.size();
//     int result = 0;
//     for (int i = 0; i <= n; i++)
//       result ^= i;
//     for (int i = 0; i < n; i++)
//       result ^= nums[i];
//     return result;
//   }
// };
// https://leetcode.cn/problems/sum-of-two-integers/submissions/
// class Solution
// {
// public:
//   int getSum(int a, int b)
//   {
//     while (b != 0)
//     {
//       int ret = a ^ b;
//       unsigned int carry = (unsigned int)(a & b) << 1;
//       a = ret;
//       b = carry;
//     }
//     return a;
//   }
// };
// https://leetcode.cn/problems/single-number-ii/
// class Solution
// {
// public:
//   int singleNumber(vector<int> &nums)
//   {
//     int ret = 0;
//     for (int i = 0; i < 32; i++)
//     {
//       int sum = 0;
//       // 修改每一位
//       for (int j = 0; j < nums.size(); j++)
//       {
//         if ((nums[j] >> i) & 1 == 1)
//           sum++;
//       }
//       sum %= 3;
//       if (1 == sum)
//         ret |= 1 << i;
//     }
//     return ret;
//   }
// };
// https://leetcode.cn/problems/missing-two-lcci/submissions/
class Solution
{
public:
  vector<int> missingTwo(vector<int> &nums)
  {
    int tmp = 0;
    for (auto x : nums)
      tmp ^= x;
    for (int i = 1; i <= nums.size() + 2; i++)
      tmp ^= i;
    // 找出  a b 不同的哪一位
    int diff = 0;
    while (1)
    {
      if ((tmp >> diff) & 1 == 1)
        break;
    else
      diff++;
    }

    // 开始分类
    vector<int> result(2, 0);
    for (auto x : nums)
    {
      if ((x >> diff)&1 == 1)
        result[0] ^= x;
      else
        result[1] ^= x;
    }
    for (int i = 1; i <= nums.size() + 2; i++)
    {
      if ((i >> diff)&1 == 1)
        result[0] ^= i;
      else
        result[1] ^= i;
    }
    return result;
  }
};
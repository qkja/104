/**
 * User: Qkj
 * Description:
 * Date: 2023-06-18
 * Time: 19:43
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// https://leetcode.cn/problems/minimum-size-subarray-sum/submissions/
//  class Solution
//  {
//  public:
//    int minSubArrayLen(int target, vector<int> &nums)
//    {
//      if (nums.empty() || target <= 0)
//        return 0;
//      int sum = 0;
//      int minLen = INT32_MAX;
//      int begin = 0;
//      for (size_t end = 0; end < nums.size(); end++)
//      {
//        sum += nums[end];

//       while (begin <= end && sum >= target)
//       {
//         minLen = min(minLen, (int)end - begin + 1);
//         sum -= nums[begin++];
//       }
//     }
//     return minLen ==INT32_MAX ? 0 : minLen;
//   }
// };
// https://leetcode.cn/problems/longest-substring-without-repeating-characters/submissions/
class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
  }
};
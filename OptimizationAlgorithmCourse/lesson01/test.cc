/**
 * User: Qkj
 * Description: 双指针
 * Date: 2023-06-13
 * Time: 15:17
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// https://leetcode.cn/problems/move-zeroes/

// class Solution
// {
// public:
//   // void process(vector<int> &nums)
//   // {
//   //   int left = 0;
//   //   int right = nums.size()-1;
//   //   while (left < right)
//   //   {
//   //     if (nums[left] == 0 && nums[right] != 0)
//   //       swap(nums[left], nums[right]);
//   //     left++;
//   //     right--;
//   //   }
//   // }
//   void process(vector<int> &nums)
//   {
//     int left = 0;
//     int right = left + 1;
//     while (right < nums.size())
//     {
//       while (left < nums.size() && nums[left] != 0)
//       {
//         left++;
//       }
//       right = left + 1;
//       while (right < nums.size() && nums[right] == 0)
//       {
//         right++;
//       }
//       if (left < nums.size() && right < nums.size())
//         swap(nums[left], nums[right]);
//     }
//   }
//   void moveZeroes(vector<int> &nums)
//   {
//     if (nums.empty())
//       return;
//     process(nums);
//   }
// };
// https://leetcode.cn/problems/duplicate-zeros/
// class Solution
// {
// public:
//   void duplicateZeros(vector<int> &arr)
//   {
//     if (arr.empty())
//       return;
//     int cur = 0;
//     int dest = -1;
//     // 找到最后一个数
//     int n = arr.size();
//     while (cur < n)
//     {
//       if (arr[cur] != 0)
//         dest++;
//       else
//         dest += 2;
//       if (dest >= n - 1)
//         break;
//       cur++;
//     }

//     // 处理边界情况
//     if (dest == n)
//     {
//       arr[n - 1] = 0;
//       cur--;
//       dest -= 2;
//     }
//     // 完成复写操作
//     while (cur >= 0)
//     {
//       if (arr[cur] != 0)
//         arr[dest--] = arr[cur--];
//       else
//       {
//         arr[dest--] = 0;
//         arr[dest--] = 0;
//         cur--;
//       }
//     }
//   }
// };

// https://leetcode.cn/problems/happy-number/
// class Solution
// {
// public:
//   int process(int val)
//   {
//     string str = to_string(val);
//     int left = 0;
//     int right = str.size() - 1;
//     int result = 0;
//     if (str.size() % 2 != 0)
//     {
//       result += (str[(left + right) / 2] - '0') * (str[(left + right) / 2] - '0');
//     }
//     while (left < right)
//     {
//       result += (str[left] - '0') * (str[left] - '0');
//       result += (str[right] - '0') * (str[right] - '0');
//       left++;
//       right--;
//     }
//     return result;
//   }
//   bool isHappy(int n)
//   {
//     if (n == 0)
//       return false;
//     int slow = n;
//     int fast = process(n);
//     while (slow != fast)
//     {
//       slow = process(slow);
//       fast = process(process(fast));
//     }
//     return slow == 1;
//   }
// };
// https://leetcode.cn/problems/container-with-most-water/
// class Solution
// {
// public:
//   // 这道题的讲解非常有意思,可以多看几遍
//   int maxArea(vector<int> &height)
//   {
//     if (height.empty())
//       return 0;
//     int left = 0;
//     int right = height.size() - 1;

//     int maxVal = 0;
//     while (left < right)
//     {
//       int h = min(height[left], height[right]);
//       int l = right - left;
//       maxVal = max(maxVal, h * l);
//       // 找哪一个比较小
//       if (height[left] < height[right])
//         left++;
//       else
//         right--;
//     }
//     return maxVal;
//   }
// };
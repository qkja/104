/**
 * User: Qkj
 * Description:
 * Time: 10:23
 */
#include <vector>
using namespace std;

// https://leetcode.cn/problems/binary-search/
// class Solution
// {
// public:
//   int search(vector<int> &nums, int target)
//   {
//     if (nums.empty())
//       return -1;
//     int left = 0;
//     int right = nums.size() - 1;
//     while (left <= right)
//     {
//       int mid = (left + right) / 2;
//       if (nums[mid] == target)
//         return mid;
//       else if (target > nums[mid])
//         left = mid + 1;
//       else
//         right = mid - 1;
//     }
//     return -1;
//   }
// };
// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
// class Solution
// {
// public:
//   vector<int> searchRange(vector<int> &nums, int target)
//   {
//     vector<int> v(2,-1);
//     if (nums.empty())
//       return v;
//     int left = 0;
//     int right = nums.size() - 1;
//     // 找第一个
//     while (left <= right)
//     {
//       int mid = (left + right) / 2;
//       if (nums[mid] == target)
//       {
//         v[0] = mid;
//         right = mid - 1;
//       }
//       else if (target > nums[mid])
//       {
//         left = mid + 1;
//       }
//       else
//       {
//         right = mid - 1;
//       }
//     }
//     left = 0;
//     right = nums.size() - 1;
//     while (left <= right)
//     {
//       int mid = (left + right) / 2;
//       if (nums[mid] == target)
//       {
//         v[1] = mid;
//         left = mid + 1;
//       }
//       else if (target > nums[mid])
//       {
//         left = mid + 1;
//       }
//       else
//       {
//         right = mid - 1;
//       }
//     }
//     return v;
//   }
// };
// https://leetcode.cn/problems/search-insert-position/
// class Solution
// {
// public:
//   int searchInsert(vector<int> &nums, int target)
//   {
//     if (nums.empty())
//       return -1;
//     int left = 0;
//     int right = nums.size() - 1;
//     // 找第一个
//     while (left <= right)
//     {
//       int mid = (left + right) / 2;
//       if (nums[mid] == target)
//       {
//         right = mid - 1;
//       }
//       else if (target > nums[mid])
//       {
//         left = mid + 1;
//       }
//       else
//       {
//         right = mid - 1;
//       }
//     }
//     return right+1;
//   }
// };
// https://leetcode.cn/problems/sqrtx/
// class Solution
// {
// public:
//   int mySqrt(int x)
//   {
//     vector<int> nums;
//     double i = 0;
//     while (i * i <= x)
//     {
//       nums.push_back(i);
//       i++;
//     }
//     int left = 0;
//     int right = nums.size() - 1;
//     while (left <= right)
//     {
//       int mid = (left + right) / 2;
//       int ret = nums[mid] * nums[mid];
//       if (ret == x)
//       {
//         return nums[mid];
//       }
//       else if (x > ret)
//       {
//         left = mid + 1;
//       }
//       else
//       {
//         right = mid - 1;
//       }
//     }
//     return nums[right];
//   }
// };
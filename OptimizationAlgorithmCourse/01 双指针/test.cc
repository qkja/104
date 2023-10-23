/**
 * User: Qkj
 * Description: 双指针
 * Date: 2023-06-13
 * Time: 15:17
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
// https://leetcode.cn/problems/valid-triangle-number/
// class Solution
// {
// public:
//   int triangleNumber(vector<int> &nums)
//   {
//     if (nums.size() < 3)
//       return 0;
//     vector<int> v(nums.begin(), nums.end());
//     sort(v.begin(), v.end());
//     int count = 0;
//     for (int i = v.size() - 1; i >= 2; i--)
//     {
//       int begin = 0;
//       int end = i - 1;

//       while (begin < end)
//       {
//         if (v[begin] + v[end] > v[i])
//         {
//           count += (end - begin);
//           end--;
//         }
//         else
//         {
//           // 这里没有不对,对与上面的end发生变化,我们可以很容的想到end是想左侧移动的,也就是值变得更加小了,此时我们begin的值是不需要移动过的
//           begin++;
//         }
//       }
//     }
//     return count;
//   }
// };
// class Solution
// {
// public:
//   int triangleNumber(vector<int> &nums)
//   {
//     if (nums.size() < 3)
//       return 0;
//     vector<int> v(nums.begin(), nums.end());
//     sort(v.begin(), v.end());
//     int count = 0;
//     for (int i = v.size() - 1; i >= 2; i--)
//     {
//       int end = i - 1;
//       for (; end >= 1; end--)
//       {
//         int begin = 0;
//         while (begin < end)
//         {
//           if (v[begin] + v[end] > v[i])
//           {
//             count += (end - begin);
//             break;
//           }
//           else
//           {
//             begin++;
//           }
//         }
//       }
//     }
//     return count;
//   }
// };
// https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/
// class Solution
// {
// public:
//   vector<int> twoSum(vector<int> &nums, int target)
//   {
//     vector<int> v;
//     if (nums.empty())
//       return v;
//     int left = 0;
//     int right = nums.size() - 1;
//     while (left < right)
//     {
//       int sum = nums[left] + nums[right];
//       if (sum == target)
//       {
//         v.push_back(nums[left]);
//         v.push_back(nums[right]);
//         return v;
//       }
//       else if (sum < target)
//       {
//         left++;
//       }
//       else
//       {
//         right--;
//       }
//     }
//     return v;
//   }
// };
// https://leetcode.cn/problems/3sum/
// class Solution
// {
// public:
//   vector<vector<int>> threeSum(vector<int> &nums)
//   {
//     vector<vector<int>> v;
//     if (nums.empty())
//       return v;
//     sort(nums.begin(), nums.end());
//     int begin = 0;
//     while (begin < (nums.size() - 2))
//     {
//       if(nums[begin] > 0)
//         break;
//       // 这里等一下
//       int left = begin + 1;
//       int right = nums.size() - 1;
//       // 这里开始在[l,r] 中找到   和等于  nums[begin]的
//       while (left < right)
//       {
//         int sum = nums[left] + nums[right];
//         if (sum == -nums[begin])
//         {
//           v.push_back({nums[begin], nums[left++], nums[right--]});
//           while (left < right && nums[left] == nums[left - 1])
//           {
//             left++;
//           }
//           while (left < right && nums[right] == nums[right + 1])
//           {
//             right--;
//           }
//         }
//         else if(sum > -nums[begin])
//         {
//             right--;
//         }
//         else
//         {
//             left++;
//         }
//       }
//       begin++;
//       while (begin < (nums.size() - 2) && nums[begin - 1] == nums[begin])
//       {
//         begin++;
//       }
//     }
//     return v;
//   }
// };
// https://leetcode.cn/problems/4sum/
// class Solution
// {
// public:
//   vector<vector<int>> fourSum(vector<int> &nums, int target)
//   {
//     vector<vector<int>> v;
//     if (nums.empty())
//       return v;
//     sort(nums.begin(), nums.end());
//     int index = 0;

//     while (index < (int)(nums.size() - 3))
//     {

//       int begin = index + 1;

//       while (begin < (nums.size() - 2))
//       {

//         // 这里等一下
//         int left = begin + 1;
//         int right = nums.size() - 1;
//         // 这里开始在[l,r] 中找到   和等于  nums[begin]的
//         while (left < right)
//         {

//           long long sum = ((long long)nums[left] + nums[right] + nums[begin] + nums[index]);
//           if (sum == target)
//           {
//             v.push_back({nums[index], nums[begin], nums[left++], nums[right--]});
//             while (left < right && nums[left] == nums[left - 1])
//             {
//               left++;
//             }
//             while (left < right && nums[right] == nums[right + 1])
//             {
//               right--;
//             }
//           }
//           else if (sum > target)
//           {
//             right--;
//           }
//           else
//           {
//             left++;
//           }
//         }
//         begin++;
//         while (begin < (nums.size() - 2) && nums[begin - 1] == nums[begin])
//           begin++;
//       }

//       index++;
//       while (index < (nums.size() - 3) && nums[index - 1] == nums[index])
//         index++;
//     }
//     return v;
//   }
// };

// class Solution
// {
// public:
//   void duplicateZeros(vector<int> &arr)
//   {
//     int src = 0;
//     int dest = -1;
//     int n = arr.size();
//     while (src < n)
//     {
//       if (arr[src] != 0)
//       {
//         dest++;
//       }
//       else
//       {
//         dest += 2;
//       }
//       if (dest >= n - 1)
//         break;
//       src++;
//     }
//     if (dest == n)
//     {
//       arr[n - 1] = 0;
//       src--;
//       dest -= 2;
//     }

//     // 找到我们的数据并且可以将我们的src的元素赋值给我们的dest
//     while (src >= 0)
//     {
//       if (arr[src] != 0)
//       {
//         arr[dest] = arr[src];
//         dest--;
//       }
//       else
//       {
//         arr[dest] = arr[src];
//         arr[dest - 1] = arr[src];
//         dest -= 2;
//       }
//       src--;
//     }
//   }
// };

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int fast = 0;
//         int slow = 0;
//         while(fast < nums.size())
//         {
//             if(nums[fast] != 0)
//             {
//                 nums[slow++] = nums[fast];
//             }
//             fast++;
//         }
//         while(slow < nums.size())
//         {
//             nums[slow++] = 0;
//         }
//     }
// };

// class Solution
// {
// public:
//   int bitSum(int val)
//   {
//     int sum = 0;
//     while (val)
//     {
//       int ret = val % 10;
//       sum += ret * ret;
//       val /= 10;
//     }
//     return sum;
//   }
//   bool isHappy(int n)
//   {
//     int slow = n;
//     int fast = n;
//     while (true)
//     {

//       slow = bitSum(slow);
//       fast = bitSum(bitSum(fast));
//       if (slow == fast)
//         break;
//     }

//     return slow == 1;
//   }
// };

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int left = 0;
//         int right = height.size() -1;
//         int result = 0;
//         while(left < right)
//         {
//             result = max(result, (right-left)*min(height[left], height[right]));
//             if(height[left] < height[right]) left++;
//             else right--;
//         }
//         return result;
//     }
// };
#include <algorithm>
using namespace std;
// class Solution
// {
// public:
//   int triangleNumber(vector<int> &nums)
//   {
//     sort(nums.begin(), nums.end());
//     int i = nums.size() - 1;
//     int result = 0;
//     for (; i >= 2; --i)
//     {
//       int left = 0;
//       int right = i - 1;
//       while (left < right)
//       {
//         if (nums[left] + nums[right] > nums[i])
//         {
//           result += (right - left);
//           right--;
//         }
//         else
//         {
//           left++;
//         }
//       }
//     }
//     return result;
//   }
// };

// class Solution
// {
// public:
//   vector<int> twoSum(vector<int> &price, int target)
//   {
//     vector<int> result(2);
//     sort(price.begin(), price.end());
//     int left = 0;
//     int right = price.size() - 1;
//     while (left < right)
//     {
//       int sum = price[left] + price[right];
//       if (target == sum)
//       {
//         result[0] = price[left];
//         result[1] = price[right];
//         return result;
//       }
//       else if (sum < target)
//       {
//         left++;
//       }
//       else
//       {
//         right--;
//       }
//     }
//     return result;
//   }
// };

// class Solution
// {
// public:

//   vector<vector<int>> threeSum(vector<int> &nums)
//   {
//     vector<vector<int>> reuslt;
//     sort(nums.begin(), nums.end());

//     for (int i = nums.size() - 1; i >= 2;)
//     {
//       int val = nums[i];
//       int left = 0;
//       int right = i - 1;
//       while (left < right)
//       {
//         int sum = nums[left] + nums[right];
//         if (sum + val == 0)
//         {
//           // 收集
//           reuslt.push_back({nums[left], nums[right], val});
//           // 跟新
//           left++;
//           right--;
//           while (left < right && nums[left] == nums[left - 1])
//             left++;
//           while (left < right && nums[right] == nums[right + 1])
//             right--;
//         }
//         else if (sum > -val)
//         {
//           right--;
//         }
//         else
//         {
//           left++;
//         }
//       }

//       while (i >= 2 && nums[i] == val)
//       {
//         i--;
//       }
//     }
//     return reuslt;
//   }
// };

// class Solution
// {
// public:
//   vector<vector<int>> fourSum(vector<int> &nums, int target)
//   {
//     vector<vector<int>> reuslt;
//     sort(nums.begin(), nums.end());
//     int i = nums.size() - 1;
//     while (i >= 3)
//     {
//       long long x = target - nums[i];
//       int j = i - 1;
//       while (j >= 2)
//       {

//         int left = 0;
//         int right = j - 1;
//         // 这里也是
//         long long y = x - nums[j];
//         while (left < right)
//         {
//           int sum = nums[left] + nums[right];
//           if (sum == y)
//           {
//             reuslt.push_back({nums[left], nums[right], nums[j], nums[i]});
//             left++;
//             right--;
//             while (left < right && nums[left] == nums[left - 1])
//               left++;
//             while (left < right && nums[right] == nums[right + 1])
//               right--;
//           }
//           else if (sum > y)
//           {
//             right--;
//           }
//           else
//           {
//             left++;
//           }
//         }

//         while (j >= 2 && (x - nums[j] == y))
//         {
//           --j;
//         }
//       }
//       while (i >= 3 && (target - nums[i] == x))
//       {
//         --i;
//       }
//     }
//     return reuslt;
//   }
// };




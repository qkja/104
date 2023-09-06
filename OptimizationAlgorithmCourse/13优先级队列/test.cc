#include <queue>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <algorithm>
using std::greater;
using std::priority_queue;
using std::string;
using std::unordered_map;
using std::vector;
class MedianFinder
{
  priority_queue<int> left;                             // 大根堆
  priority_queue<int, vector<int>, greater<int>> right; // 小根堆
public:
  MedianFinder()
  {
  }
  void addNum(int num)
  {
    // 分类讨论即可
    if (left.size() == right.size()) // 左右两个堆的元素个数相同
    {
      if (left.empty() || num <= left.top()) // 放 left 里面
      {
        left.push(num);
      }
      else
      {
        right.push(num);
        left.push(right.top());
        right.pop();
      }
    }
    else
    {
      if (num <= left.top())
      {
        left.push(num);
        right.push(left.top());
        left.pop();
      }
      else
      {
        right.push(num);
      }
    }
  }
  double findMedian()
  {
    if (left.size() == right.size())
      return (left.top() + right.top()) / 2.0;
    else
      return left.top();
  }
};

// class Solution
// {
// public:
//   struct Compare
//   {
//     // 建立大堆
//     bool operator()(const std::pair<string, int> &p1, const std::pair<string, int> &p2)
//     {
//       if (p1.second == p2.second)
//       {
//         return p1.first > p2.first;
//       }
//       return p1.second < p2.second;
//     }
//   };

//   vector<string> topKFrequent(vector<string> &words, int k)
//   {
//     unordered_map<string, int> m;
//     for (const auto &str : words)
//       m[str]++;
//     std::priority_queue<std::pair<string, int>, vector<std::pair<string, int>>, Compare> q;
//     for (const auto &e : m)
//       q.push(e);
//     // 一定会保证k的
//     vector<string> result;
//     while (k--)
//     {
//       result.push_back(q.top().first);
//       q.pop();
//     }
//     return result;
//   }
// };
// class KthLargest
// {
// public:
//   KthLargest(int k, vector<int> &nums)
//   {
//     _k = k;
//     for (auto &e : nums)
//     {
//       if (_q.size() < _k)
//       {
//         _q.push(e);
//       }
//       else
//       {
//         if (e > _q.top())
//         {
//           _q.pop();
//           _q.push(e);
//         }
//       }
//     }
//   }

//   int add(int val)
//   {
//     if (_q.size() < _k)
//     {
//       _q.push(val);
//     }
//     else
//     {
//       if (val > _q.top())
//       {
//         _q.pop();
//         _q.push(val);
//       }
//     }
//     return _q.top();
//   }
//   std::priority_queue<int, std::vector<int>, std::greater<int>> _q; // 建立小堆
//   int _k;
// };

// class KthLargest
// {
// public:
//   KthLargest(int k, vector<int> &nums)
//   {
//     _k = k;
//     _nums = nums;
//   }

//   int add(int val)
//   {
//     std::priority_queue<int, std::vector<int>, std::less<int>> bar;
//     _q.swap(bar);
//     _nums.push_back(val);
//     for (auto &e : _nums)
//       _q.push(e);
//     int result = 0;
//     for (int i = 0; i < _k; i++)
//     {
//       result = _q.top();
//       _q.pop();
//     }
//     return result;
//   }
//   std::priority_queue<int, std::vector<int>, std::less<int>> _q; // 建立大堆
//   vector<int> _nums;
//   int _k;
// };

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// class Solution
// {
// public:
//   int lastStoneWeight(vector<int> &stones)
//   {
//     if (stones.empty())
//       return 0;
//     std::priority_queue<int> q;
//     for (auto &e : stones)
//       q.push(e);
//     while (!q.empty())
//     {
//       int more = q.top();
//       q.pop();
//       if (q.empty())
//         return more;
//       int less = q.top();
//       q.pop();
//       int div = std::abs(more - less);
//       if (div != 0)
//         q.push(div);
//     }
//     return 0;
//   }
// };
// int main()
// {
//   int arr[] = {1, 3, 4, 5, 6};
//   std::priority_queue<int> q;
//   for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//   {
//     q.push(arr[i]);
//   }
//   while (!q.empty())
//   {
//     std::cout << q.top() << std::endl;
//     q.pop();
//   }

//   return 0;
// }
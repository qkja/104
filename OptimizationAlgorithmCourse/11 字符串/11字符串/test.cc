#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;
using std::vector;

// class Solution
//{
// public:
//	string addBinary(string a, string b)
//	{
//		if (a.empty())
//			return b;
//		if (b.empty())
//			return a;
//		std::string result;
//
//		int end1 = a.size() - 1;
//		int end2 = b.size() - 1;
//		int sum = 0;
//		while (end1 >= 0 && end2 >= 0)
//		{
//			sum = a[end1] - '0' + b[end2] - '0' + sum;
//			result += ((sum % 2) + '0');
//			sum /= 2;
//			end1--;
//			end2--;
//		}
//		while (end1 >= 0)
//		{
//			sum = sum + a[end1] - '0';
//			result += ((sum % 2) + '0');
//			sum /= 2;
//			end1--;
//		}
//		while (end2 >= 0)
//		{
//			sum = sum + b[end2] - '0';
//			result += ((sum % 2) + '0');
//			sum /= 2;
//			end2--;
//		}
//		// �ж� sum ֵ
//		if (sum != 0)
//		{
//			result += '1';
//		}
//		std::reverse(result.begin(), result.end());
//		return result;
//	}
// };

// class Solution {
// public:
//	string longestCommonPrefix(vector<string>& strs) {
//		string result;
//		if (strs.empty())
//			return result;
//		vector<std::pair<char, int>> v;
//		for (int i = 0; i < strs.size(); i++)
//		{
//			// �õ�һ���ַ�
//			const auto& str = strs[i];
//			for (int j = 0; j < str.size(); j++)
//			{
//				if (j >= v.size())
//				{
//					v.push_back(std::make_pair(str[j], 1));
//				}
//				else
//				{
//					if (str[j] == v[j].first)
//						v[j].second++;
//					else
//						break;
//				}
//			}
//		}
//		// �ж�
//		for (int i = 0; i < v.size(); i++)
//		{
//			if (v[i].second == strs.size())
//				result += v[i].first;
//		}
//		return result;
//	}
// };

// class Solution {
// public:
//	string longestPalindrome(string s)
//	{
//		if (s.empty())
//			return s;
//
//		int n = s.size();
//		vector<vector<bool>> dp(n, vector<bool>(n, false));
//		int index = -1;
//		int maxLen = -1;
//		for (int i = n-1; i >= 0; i--)
//		{
//			for (int j = i; j < n; j++)
//			{
//				if (s[i] == s[j])
//				{
//					if (i == j || i + 1 == j)
//						dp[i][j] = true;
//					else
//						dp[i][j] = dp[i + 1][j - 1];
//
//					if (dp[i][j] && j-i+1 > maxLen)
//					{
//						maxLen = j - i + 1;
//						index = i;
//					}
//				}
//			}
//		}
//		return s.substr(index, maxLen);
//	}
// };

// class Solution
// {
// public:
// 	string multiplyChild(const string &str, char ch)
// 	{
// 		int i = str.size() - 1;
// 		int count = 0;
// 		string result;
// 		while (i >= 0)
// 		{
// 			int ret = (str[i] - '0') * (ch - '0');
// 			result += std::to_string(((ret + count) % 10));
// 			count = (count + ret) / 10;
// 			i--;
// 		}
// 		if (count != 0)
// 			result += std::to_string(count % 10);
// 		reverse(result.begin(), result.end());
// 		return result;
// 	}
// 	// �����ַ������
// 	void addition(string &s1, const string &s2)
// 	{
// 		int i = s1.size() - 1;
// 		int j = s2.size() - 1;
// 		int count = 0;
// 		string result;
// 		while (i >= 0 && j >= 0)
// 		{
// 			int ret = (s1[i] - '0') + (s2[j] - '0') + count;
// 			result += std::to_string(ret % 10);
// 			count = ret / 10;
// 			i--;
// 			j--;
// 		}
// 		while (i >= 0)
// 		{
// 			// ��ʱs1���Ǵ���ʣ��
// 			int ret = s1[i] - '0' + count;
// 			result += std::to_string(ret % 10);
// 			count = ret / 10;
// 			i--;
// 		}
// 		while (j >= 0)
// 		{
// 			// ��ʱs1���Ǵ���ʣ��
// 			int ret = s2[j] - '0' + count;
// 			result += std::to_string(ret % 10);
// 			count = ret / 10;
// 			j--;
// 		}
// 		if (count != 0)
// 			result += std::to_string(count);
// 		reverse(result.begin(), result.end());
// 		s1 = result;
// 	}
// 	string multiply(string num1, string num2)
// 	{
// 		if (num1[0] == '0' || num2[0] == '0')
// 			return "0";
// 		if (num1.empty())
// 			return num2;
// 		if (num2.empty())
// 			return num1;
// 		string result;
// 		string s;
// 		for (int i = num2.size() - 1; i >= 0; i--)
// 		{
// 			// �����ж�һ���ַ��ǲ���o
// 			if (num2[i] != '0')
// 			{
// 				addition(result, multiplyChild(num1, num2[i]) + s);
// 			}
// 			s += "0";
// 		}
// 		return result;
// 	}
// };

// class Solution {
// public:
//     void dfs(vector<int>& nums1, int index1, vector<int>& nums2, int index2, int index)
//     {
//         if(index < 0)
//         return;
//         if(index1 < 0)
//         {
//             // 此时我们v1已经走完了
//             nums1[index] =  nums2[index2];
//             dfs(nums1, index1, nums2, index2-1,index-1);
//             return;
//         }
//         if(index2 < 0)
//         {
//             // 此时v2已经走完了
//             nums1[index] =  nums1[index1];
//             dfs(nums1, index1-1, nums2, index2,index-1);
//             return;
//         }
//         if(nums1[index1] <= nums2[index2])
//         {
//             nums1[index] =  nums2[index2];
//             dfs(nums1, index1, nums2, index2-1,index-1);
//         }
//         else
//         {
//             nums1[index] =  nums1[index1];
//             dfs(nums1, index1-1, nums2, index2,index-1);
//         }
//     }
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         dfs(nums1, m-1, nums2, n-1, m+n-1);
//     }
// };

// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         if(nums.empty())
//         return 0;
//         auto iter = nums.begin();
//         while(iter != nums.end())
//         {
//             if(val == *iter)
//             {
//                 iter = nums.erase(iter);
//             }
//             else
//             {
//                 ++iter;
//             }
//         }
//         return nums.size();
//     }
// };
// class Solution
// {
// public:
// 	int removeDuplicates(vector<int> &nums)
// 	{
// 		set<int> s;
// 		for (auto e : nums)
// 			s.insert(e);
// 		nums.clear();
// 		auto iter = s.begin();
// 		while (iter != s.end())
// 			nums.push_back(*iter++);
// 		return nums.size();
// 	}
// };

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         map<int, int> m;
//         for(auto e: nums)
//         m[e]++;
//         nums.clear();
//         auto iter = m.begin();
//         while(iter != m.end())
//         {
//             nums.push_back(iter->first);
//             if(iter->second != 1)
//             {
//                 nums.push_back(iter->first);
//             }
//             ++iter;
//         }
//         return nums.size();
//     }
// };
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         // 这里修改了数组
//         sort(nums.begin(), nums.end());
//         return nums[nums.size()/2];
//     }
// };
// class Solution {
// public:
//     void reverse(vector<int>& v, int left, int right)
//     {
//         while(left < right)
//         swap(v[left++], v[right--]);
//     }
//     void rotate(vector<int>& nums, int k) {
//         k %= nums.size();
//         reverse(nums, 0, nums.size()-k-1);
//         reverse(nums, nums.size()-k, nums.size()-1);
//         reverse(nums, 0, nums.size()-1);
//     }
// };
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, 0);
//         dp[n-1] = nums[n-1];
//         for(int i = n-2; i >=0; i--)
//         {
//             for(int j = 0;  i +j < n &&  j <= nums[i]; j++)
//             {
//                 dp[i] = max(j+dp[i+j], dp[i]);
//             }
//         }

//         return dp[0]>=n-1;
//     }
// };

// class Solution
// {
// public:
// 	bool canJump(vector<int> &nums)
// 	{
// 		int cover = 0;
// 		for (size_t i = 0; i <= cover; i++)
// 		{
// 			int ret = i + nums[i];
// 			cover = std::max(cover, ret);
// 			if (cover >= nums.size() - 1)
// 				return true;
// 		}
// 		return false;
// 	}
// };
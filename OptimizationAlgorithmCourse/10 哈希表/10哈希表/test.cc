#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using std::sort;
using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> m;
		for (int i = 0; i < strs.size(); i++)
		{
			auto str = strs[i];
			sort(str.begin(), str.end());
			m[str].push_back(strs[i]);
		}
		vector<vector<string>> result;
		auto iter = m.begin();
		while (iter != m.end())
		{
			result.push_back(iter->second);
			iter++;
		}
		return result;
	}
};
//class Solution {
//public:
//	bool containsNearbyDuplicate(vector<int>& nums, int k) {
//		unordered_map<int, int> m;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			// 拿到一个元素
//			auto iter = m.find(nums[i]);
//			if (iter != m.end() && abs(i - iter->second) <= k)
//				return true;
//			m[nums[i]] = i;
//			// 这里注意 k = 2
//			// 1 2 0 3 1 0 1 这种情况,对于最后一1,那么一定说它前面的最近的一个才有可能满足小于<k的特性
//		}
//		return false;
//	}
//};

//class Solution {
//public:
//	bool containsDuplicate(vector<int>& nums) {
//		unordered_set<int> s;
//		for (auto e : nums)
//			s.insert(e);
//		return s.size() != nums.size();
//	}
//};

//class Solution {
//public:
//	bool CheckPermutation(string s1, string s2) {
//		if (s1.size() != s2.size())
//			return false;
//		unordered_map<char, int> m;
//		for (auto ch : s1)
//			m[ch]++;
//		for (int i = 0; i < s2.size(); i++)
//		{
//			m[s2[i]]--;
//			if (m[s2[i]] == -1)
//				return false;
//			if (m[s2[i]] == 0)
//				m.erase(s2[i]);
//		}
//		return m.empty();
//	}
//};

// https://leetcode.cn/problems/two-sum/description/
//class Solution {
//public:
//	vector<int> twoSum(vector<int>& nums, int target) {
//		vector<int> result(2, -1);
//		if (nums.empty())
//			return result;
//		unordered_map<int, int> m;
//		for (int i = 0; i < nums.size(); i++)
//			m[nums[i]] = i;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			int div = target - nums[i];
//			auto iter = m.find(div);
//			if (iter != m.end() && iter->second != i)
//			{
//				result[0] = i;
//				result[1] = iter->second;
//				break;
//			}
//		}
//		return result;
//
//	}
//};
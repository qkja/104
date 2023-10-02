#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
	/**
	* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	*
	*
	* @param head ListNode类
	* @param s string字符串
	* @return int整型
	*/
	int minValue(ListNode* head, string s) {
		if (head == nullptr || s.empty())
			return 0;
		vector<pair<char, int>> v;
		int index = 0;
		while (head)
		{
			v.push_back({ s[index], head->val});
			index++;
			head = head->next;
		}
		int result = 0;
		for (int i = 1; i < v.size(); i++)
		{
			if (v[i].first == v[i - 1].first)
			{
				result += min(v[i].second, v[i - 1].second);
			}
		}
		return result;
	}
};
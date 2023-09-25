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
	* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	*
	*
	* @param head ListNode��
	* @param s string�ַ���
	* @return int����
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
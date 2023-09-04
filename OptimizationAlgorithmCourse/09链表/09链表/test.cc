#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
using std::vector;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//https://leetcode.cn/problems/reverse-nodes-in-k-group/submissions/
//class Solution {
//public:
//	ListNode* reverseKGroup(ListNode* head, int k) {
//		if (head == nullptr)
//			return nullptr;
//		int len = 0;
//		ListNode* cur = head;
//		while (cur)
//		{
//			len++;
//			cur = cur->next;
//		}
//		if (k > len)
//			return head;
//
//		int count = len / k; // 需要经行翻转几次
//
//		ListNode* newHead = nullptr;
//		ListNode* tail = nullptr;
//		ListNode* stail = nullptr;
//
//		ListNode* prev = nullptr;
//		ListNode* node = head;
//
//		while (count--)
//		{
//			int kk = k;
//			stail = node; // 每一次都要保存
//
//			while (kk--)
//			{
//				ListNode* next = node->next;
//				node->next = prev;
//				prev = node;
//				node = next;
//			}
//			//出来了
//			if (newHead == nullptr)
//			{
//				newHead = prev;
//				tail = stail;
//				tail->next = node;
//			}
//			else
//			{
//				tail->next = prev;
//				tail = stail;
//				tail->next = node;
//			}
//			prev = nullptr;
//		}
//		return newHead;
//	}
//};

//class Solution {
//public:
//	ListNode* mergeKLists(vector<ListNode*>& lists) {
//		if (lists.empty())
//			return nullptr;
//		ListNode* head = nullptr;
//		ListNode* tail = nullptr;
//		int n = lists.size();
//		while (true)
//		{
//			// 只有全部为nullptr时退出
//			int minNum = INT_MAX;
//			int index = -1;
//			for (int i = 0; i < n; i++)
//			{
//				// 找到最小的元素
//				if (lists[i] != nullptr && lists[i]->val < minNum)
//				{
//					minNum = lists[i]->val;
//					index = i;
//				}
//			}
//			if (index == -1)
//				break;
//			if (head == nullptr)
//			{
//				head = lists[index];
//				tail = head;
//			}
//			else
//			{
//				tail->next = lists[index];
//				tail = tail->next;
//			}
//			// 更行lists[index]
//			lists[index] = lists[index]->next;
//		}
//		return head;
//	}
//};


//https://leetcode.cn/problems/reorder-list/
//class Solution {
//public:
//	ListNode* invertedList(ListNode* head)
//	{
//		if (head == nullptr)
//			return nullptr;
//		ListNode* prev = nullptr;
//		while (head)
//		{
//
//			ListNode* next = head->next;
//			head->next = prev;
//			prev = head;
//			head = next;
//		}
//		return prev;
//	}
//
//
//	void reorderList(ListNode* head) {
//		if (head == nullptr)
//			return;
//		ListNode* fast = head;
//		ListNode* slow = head;
//		while (fast && fast->next)
//		{
//			fast = fast->next->next;
//			slow = slow->next;
//		}
//		// 拿到位置了
//		ListNode* cur1 = head;
//		ListNode* cur2 = invertedList(slow->next);
//		slow->next = nullptr;
//		ListNode* newHead = nullptr;
//		ListNode* tail = nullptr;
//		while (cur1 && cur2)
//		{
//			ListNode* curnext1 = cur1->next;
//			ListNode* curnext2 = cur2->next;
//			if (newHead == nullptr)
//			{
//				newHead = cur1;
//				cur1->next = cur2;
//				tail = cur2;
//			}
//			else
//			{
//				tail->next = cur1;
//				cur1->next = cur2;
//				tail = cur2;
//			}
//			cur1 = curnext1;
//			cur2 = curnext2;
//		}
//		//只有一个或者两个节点的出现错误
//		// 可以在参数那里判断,也可以在这里.
//		// cu1 cur2 == nullptr
//		if (tail == nullptr)
//		{
//			head = head;
//		}
//		else
//		{
//			tail->next = cur1;
//			head = newHead;
//		}
//	}
//};

//https://leetcode.cn/problems/swap-nodes-in-pairs/
//class Solution {
//public:
//	ListNode* swapPairs(ListNode* head) {
//		if (head == nullptr || head->next == nullptr)
//			return head;
//		ListNode* prev = nullptr;
//		ListNode* node = head;
//		while (node && node->next)
//		{
//			ListNode* next = node->next;
//			ListNode* nextnext = next->next;
//			next->next = node;
//			if (prev == nullptr)
//			{
//				prev = node;
//				prev->next = nullptr;
//				head = next;
//			}
//			else
//			{
//				prev->next = next;
//				prev = node;
//				prev->next = nullptr;
//			}
//			node = nextnext;
//
//		}
//		if (node)
//			prev->next = node;
//		return head;
//	}
//};
//https://leetcode.cn/problems/add-two-numbers/submissions/
//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		if (l1 == nullptr)
//			return l2;
//		if (l2 == nullptr)
//			return l1;
//		ListNode* head = nullptr;
//		ListNode* next = head;
//		ListNode* cur1 = l1;
//		ListNode* cur2 = l2;
//		int sum = 0;
//		int carry = 0;
//		while (cur1 && cur2)
//		{
//			sum = cur1->val + cur2->val + carry;
//			carry = sum / 10;
//			ListNode* new_node = new ListNode(sum%10);
//			if (head == nullptr)
//			{
//				head = new_node;
//				next = head;
//			}
//			else
//			{
//				next->next = new_node;
//				next = new_node;
//			}
//			cur1 = cur1->next;
//			cur2 = cur2->next;
//		}
//		while (cur1 != nullptr)
//		{
//			sum = cur1->val +  carry;
//			carry = sum / 10;
//			ListNode* new_node = new ListNode(sum % 10);
//			next->next = new_node;
//			next = new_node;
//			cur1 = cur1->next;
//		}
//		while (cur2 != nullptr)
//		{
//			sum = cur2->val + carry;
//			carry = sum / 10;
//			ListNode* new_node = new ListNode(sum % 10);
//			next->next = new_node;
//			next = new_node;
//			cur2 = cur2->next;
//		}
//		if (carry != 0)
//		{
//			ListNode* new_node = new ListNode(carry);
//			next->next = new_node;
//			next = new_node;
//		}
//		next->next = nullptr;
//		return head;
//	}
//};
//#include <iostream>
//
//struct A
//{
//	~A()
//	{
//		std::cout << "qq" << std::endl;
//	}
//};
//int main()
//{
//	vector<A*> v;
//	A* a = new A;
//	v.push_back(a);
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include<queue>

using namespace std;

class Solution {
public:
	string sortSentence(string s) {
		if (s.length() == 0)
			return s;
		map<int, string> m;
		string str;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ')
			{
				str += s[i];
				continue;
			}

			int ret = str[str.length() - 1] - '0';
			str.erase(str.end() - 1);
			m.insert(std::pair<int, string>(ret, str));
			str.clear();
		}
		int ret = str[str.length() - 1] - '0';
		str.erase(str.end() - 1);
		m.insert(std::pair<int, string>(ret, str));
		str.clear();
		// 默认事升序
		auto it = m.begin();
		string s2;
		while (it != m.end())
		{
			s2 += it->second;
			s2 += " ";
			++it;
		}
		s2.erase(s2.end() - 1);
		return s2;
	}
};

int main()
{
	string str = "is2 sentence4 This1 a3";
	Solution().sortSentence(str);
	return 0;
}

//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode *next) : val(x), next(next) {}
//};


//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

//class Solution {
//public:
//	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
//		if (arr1.size() == 0)
//			return arr1;
//		// 使用  map
//		map<int,int> m;
//		for (int i = 0; i < arr2.size(); i++)
//		{
//			m[arr2[i]]++;
//		}
//
//		for(int i = )
//	}
//};

//class Solution {
//public:
//	// 递减
//	bool isDecrease(const vector<int>& v)
//	{
//		if (v.size() == 1)
//			return true;
//		for (int i = 1; i < v.size(); i++)
//		{
//			if (v[i] >= v[i - 1])
//				return false;
//		}
//		return true;
//	}
//	// 递增
//	bool isIncrement(const vector<int>& v)
//	{
//		if (v.size() == 1)
//			return true;
//		for (int i = 1; i < v.size(); i++)
//		{
//			if (v[i] <= v[i - 1])
//				return false;
//		}
//		return true;
//	}
//	bool isEvenOddTree(TreeNode* root) {
//		if (root == nullptr)
//			return true;
//
//		// 层序遍历
//		vector<vector<int>> vv;
//		queue<TreeNode*> q;
//		q.push(root);
//		int sz = 1;
//		vector<int> v;
//		while (sz--)
//		{
//			// 出 
//			TreeNode* cur = q.front();
//			v.push_back(cur->val);
//			q.pop();
//			if (cur->left)
//				q.push(cur->left);
//
//			if (cur->right)
//				q.push(cur->right);
//			if (sz == 0)
//			{
//				sz = q.size();
//				vv.push_back(v);
//				v.clear();
//			}
//		}
//
//		// 判断
//		int i = 0;
//		for (vector<int> val : vv)
//		{
//
//			for (int key : val)
//			{
//				// 偶数 下标
//				if (i % 2 == 0)
//				{
//					// 都是 奇数
//					if (key % 2 == 0)
//						return false;
//
//				}
//				else
//				{
//					// 都是  偶数
//					if (key % 2 == 1)
//						return false;
//
//				}
//			}
//			if (i % 2 == 0)
//			{
//				if (!isIncrement(val))
//				{
//					return false;
//				}
//			}
//			else
//			{
//				if (!isDecrease(val))
//					return false;
//			}
//			++i;
//		}
//		return true;
//	}
//};
//class Solution {
//public:
//	int findTilt(TreeNode* root) {
//		if (root == nullptr)
//			return 0;
//		if (root->left == nullptr)
//			return root->right->val;
//		if (root->right == nullptr)
//			return root->left->val;
//		int sum = root->left->val - root->right->val;
//		if (sum < 0)
//			sum = -sum;
//		return sum + findTilt(root->left) + findTilt(root->right);
//	}
//};
//class Solution {
//public:
//	int ans = 0;
//
//	int findTilt(TreeNode* root) {
//		dfs(root);
//		return ans;
//	}
//
//	int dfs(TreeNode* node) {
//		if (node == nullptr) {
//			return 0;
//		}
//		int sumLeft = dfs(node->left);
//		int sumRight = dfs(node->right);
//		ans += abs(sumLeft - sumRight);
//		return sumLeft + sumRight + node->val;
//	}
//};

//class Solution {
//public:
//	int sumRootToLeafChild(TreeNode* root, int sum)
//	{
//		if (root == nullptr)
//			return 0;
//		sum = 2 * sum + root->val;
//		if(root->left == nullptr && root->right == nullptr) {
//			return sum;
//		}
//		return sumRootToLeafChild(root->left, sum) + sumRootToLeafChild(root->right, sum);
//	}
//	int sumRootToLeaf(TreeNode* root) {
//		if (root == nullptr)
//			return 0;
//		return sumRootToLeafChild(root, 0);
//	}
//};
 
//class Solution {
//public:
//	void numColorChild(TreeNode* root, set<int>& s)
//	{
//		if (root == nullptr)
//			return;
//		// 前序遍历
//		s.insert(root->val);
//		numColorChild(root->left, s);
//		numColorChild(root->right, s);
//	}
//	int numColor(TreeNode* root) {
//		if (root == nullptr)
//			return 0;
//		set<int> s;
//		numColorChild(root, s);
//		return s.size();
//	}
//};

//class Solution {
//public:
//	bool isSame(char ch1,char ch2)
//	{
//		// 小写
//		if (ch1 >= 'a' && ch1 <= 'z')
//		{
//			if (ch2 >= 'A' && ch2 <= 'Z')
//			{
//				return ((ch2 + 'a' - 'A') == ch1);
//			}
//			else
//			{
//				return false;
//			}
//		}
//		else
//		{
//			if (ch2 >= 'a' && ch2 <= 'z')
//			{
//				return ((ch1 + 'a' - 'A') == ch2);
//			}
//			else
//			{
//				return false;
//			}
//		}
//	}
//	string makeGoodChild(string s,int n) {
//
//		if (n == 0 || s.empty() || s.size() == 1)
//			return s;
//		string str;
//		int left = 0;
//		int right = 1;
//		while (right <= s.size())
//		{
//			if (!isSame(s[left], s[right]))
//			{
//				str += s[left];
//				left = right;
//				right = left + 1;
//			}
//			else
//			{
//				left = right + 1;
//				right = left + 1;
//			}
//		}
//		return makeGoodChild(str, n - 1);
//	}
//
//	string makeGood(string s) {
//		return makeGoodChild(s, s.size());
//	}
//};
//
//
//int main()
//{
//	string str = "abBAcC";
//	cout << Solution().makeGood(str);
//	return 0;
//}


//class Solution {
//public:
//	int maxDepth(string s) {
//		if (s.empty())
//		{
//			return 0;
//		}
//		if (s.size() == 1)
//		{
//			if (s[0] != '(' && s[0] != ')')
//				return 0;
//		}
//		stack<char> s2;
//		int count = 0;
//		int max = 0;
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (s[i] == '(')
//			{
//				s2.push(s[i]);
//				if (s2.size() > max)
//				{
//					max = s2.size();
//				}
//			}
//			if (s[i] == ')')
//			{
//				s2.pop();
//			}
//		}
//		return max;
//		/*for (int i = 0; i < s.size(); i++)
//		{
//			if (s[i] == ')')
//			{
//				count--;
//
//			}
//			if (s[i] == '(')
//			{
//				count++;
//				if (count > max)
//				{
//					max = count;
//				}
//			}
//		}
//		return max;*/
//	}
//};

//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		if (l1 == nullptr)
//			return l2;
//		if (l2 == nullptr)
//			return l1;
//		//开始计算
//		int count = (l1->val + l2->val) / 10;
//		ListNode* pHead = new ListNode((l1->val + l2->val) % 10);
//		ListNode* cur = pHead;
//		ListNode* b1 = l1->next;
//		ListNode* b2 = l2->next;
//
//		while (b1 != nullptr && b2 != nullptr)
//		{
//			int sum = (b1->val + b2->val + count)%10;
//			count = (b1->val + b2->val + count) / 10;
//			ListNode* node = new ListNode(sum);
//			cur->next = node;
//			cur = node;
//
//			b1 = b1->next;
//			b2 = b2->next;
//		}
//		/*if (b1 == nullptr && b2 == nullptr)
//		{
//			if (count != 0)
//			{
//				ListNode* node = new ListNode(count);
//				cur->next = node;
//			}
//		}*/
//
//		// 要单独讨论了
//		if (b1 == nullptr)
//		{
//			while (b2 != nullptr)
//			{
//				int sum = (count + b2->val)%10;
//				count = (count + b2->val) / 10;
//				ListNode* node = new ListNode(sum);
//				cur->next = node;
//				cur = node;
//				b2 = b2->next;
//			}
//		}
//		if (b2 == nullptr)
//		{
//			while (b1 != nullptr)
//			{
//				int sum = (count + b1->val) % 10;
//				count = sum / 10;
//				ListNode* node = new ListNode(sum);
//				cur->next = node;
//				cur = node;
//				b1 = b1->next;
//			}
//		}
//		if (count != 0)
//		{
//			ListNode* node = new ListNode(count);
//			cur->next = node;
//		}
//		return pHead;
//	}
//};

//class Solution {
//public:
//	ListNode* removeZeroSumSublists(ListNode* head) {
//		if (head == nullptr)
//			return nullptr;
//		map<int, ListNode*> m;
//		int sum = 0;
//		ListNode* cur = head;
//		while (cur != nullptr)
//		{
//			sum += cur->val;
//			m[sum] = cur;
//			cur = cur->next;
//		}
//	}
//};
//class Solution {
//public:
//	/**
//	 *
//	 * @param head ListNode类
//	 * @param m int整型
//	 * @param n int整型
//	 * @return ListNode类
//	 */
//	ListNode* reverseBetween(ListNode* head, int m, int n) {
//		// write code here
//		if (head == nullptr)
//			return nullptr;
//		ListNode* begin = head;
//		int len = n - m;
//		ListNode* pHead = nullptr;
//		ListNode* cur = nullptr;
//		ListNode* prev = nullptr;
//		ListNode* end = nullptr;
//		// m 2
//		while (m--)
//		{
//			// 尾插
//			if (pHead == nullptr)
//			{
//				pHead = begin;
//				cur = pHead;
//			}
//			else
//			{
//				cur->next = begin;
//				prev = cur;
//				cur = cur->next;
//			}
//			if (m == 0)
//			{
//				end = begin;
//			}
//			begin = begin->next;
//		}
//		// 尾插
//		while (len--)
//		{
//			ListNode* nextBegin = begin->next;
//			begin->next = cur;
//			cur = begin;
//			begin = nextBegin;
//		}
//
//		if (prev == nullptr)
//		{
//			pHead = cur;
//		}
//		else
//		{
//			prev->next = cur;
//		}
//		if (begin == nullptr)
//		{
//			end -> next = nullptr;
//		}
//		while (begin != nullptr)
//		{
//			end->next = begin;
//			begin = begin->next;
//			end = end->next;
//		}
//
//		return pHead;
//	}
//};
//
//int main()
//{
//	ListNode* head = new ListNode(1);
//	ListNode* node2 = new ListNode(2);
//	head->next = node2;
//	ListNode* node3 = new ListNode(3);
//	node2->next = node3;
//	ListNode* node4 = new ListNode(4);
//	node3->next = node4;
//
//	ListNode* node5 = new ListNode(5);
//	node4->next = node5;
//	Solution().reverseBetween(head,2,4);
//	delete head;
//	delete node2;
//	delete node3;
//	delete node4;
//	delete node5;
//	return 0;
//}
 
//class Solution {
//public:
//	int getDecimalValue(ListNode* head) {
//		if (head == nullptr)
//			return 0;
//		int count = 0;
//		ListNode* cur = head;
//		while (cur != nullptr)
//		{
//			count = 2 * count + cur->val;
//			cur = cur->next;
//		}
//		return count;
//	}
//};





//class Solution {
//public:
//	int search(vector<int>& nums, int target) {
//		if (nums.empty())
//			return -1;
//		map<int, int> m;
//		int i = 0;
//		for (int val : nums)
//		{
//			m.insert(std::pair<int, int>(val, i++));
//		}
//		if (m.size() != nums.size())
//			return -1;
//		auto f = m.find(target);
//		if (f != m.end())
//			return f->second;
//		else
//			return -1;
//	}
//};

//class Solution {
//public:
//	int searchInsert(vector<int>& nums, int target) {
//		if (nums.empty())
//			return 0;
//		int left = 0;
//		int right = nums.size();
//		while (left < right)
//		{
//			int mid = (left + right) / 2;
//			if (nums[mid] > target)
//			{
//				right = mid;
//			}
//			else if (nums[mid] < target)
//			{
//				left = mid + 1;
//			}
//			else
//			{
//				return mid;
//			}
//		}
//
//		return left;
//	}
//};
//class Solution {
//public:
//	vector<int> runningSum(vector<int>& nums) {
//		vector<int> v;
//		if (nums.empty())
//			return v;
//		int sum = 0;
//		auto it = nums.begin();
//		while (it != nums.end())
//		{
//			sum += *it;
//			v.push_back(sum);
//			++it;
//		}
//		return v;
//	}
//};
//class Solution {
//public:
//	int searchInsert(vector<int>& nums, int target) {
//		if (nums.empty())
//			return -1;
//		int begin = 0;
//		int end = nums.size() - 1;
//		while (begin < end)
//		{
//			int mid = begin + ((end - begin) >> 1);
//			if (nums[mid] < target)
//				begin = mid + 1;
//			else if (nums[mid] > target)
//				end = mid;
//			else
//				return mid;
//		}
//		return -1;
//	}
//};

/*bool isLetter(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
bool isSpace(char ch)
{
	return ch == ' ';
}
bool isNumber(char ch)
{
	return ch >= '0' && ch <= '9';
}
int main() 
{
	string str;
	getline(std::cin, str);
	auto it = str.begin();
	int countLetter = 0;
	int countSpace = 0;
	int countNumber = 0;
	int countOther = 0;
	while (it != str.end())
	{
		if (isLetter(*it))
		{
			countLetter++;
		}
		else if (isSpace(*it))
		{
			countSpace++;
		}
		else if (isNumber(*it))
		{
			countNumber++;
		}
		else
		{
			countOther++;
		}
		++it;
	}
	cout << countLetter << endl;
	cout << countSpace << endl;
	cout << countNumber << endl;
	cout << countOther << endl;
	return 0;
}*/

//int func(int n)
//{
//	if (n < 3)
//		return n;
//	int left = 1;
//	int right = 2;
//	for (int i = 3; i <= n; i++)
//	{
//		int count = 2 * right + left;
//		left = right;
//		right = count;
//	}
//	return right;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int ret = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> ret;
//
//		if (ret < 3)
//		{
//			cout << ret << endl;
//		}
//		else
//		{
//			int left = 1;
//			int right = 2;
//			for (int i = 3; i <= n; i++)
//			{
//				int count = 2 * right + left;
//				left = right;
//				right = count;
//				right %= 32767;
//			}
//			cout << right % 32767 << endl;
//		}
//	}
//	return 0;
//}
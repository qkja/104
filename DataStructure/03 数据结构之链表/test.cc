#include <iostream>
#include <unordered_map>
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// class Solution
// {
// public:
//     ListNode *reverseList(ListNode *head)
//     {
//         if (head == nullptr)
//             return head;
//         ListNode *prev = nullptr;
//         ListNode *node = head;
//         while (node)
//         {
//             ListNode *next = node->next;
//             node->next = prev;
//             prev = node;
//             node = next;
//         }
//         return prev;
//     }
// };

// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         if (head == nullptr)
//             return head;
//         ListNode* prev = nullptr;
//         ListNode* node = head;
//         ListNode* newHead = prev;
//         while (node != nullptr)
//         {
//             if (node->val != val)
//             {
//                 if (prev == nullptr)
//                     newHead = node;
//                 prev = node;
//                 node = node->next;
//             }
//             else
//             {
//                 if (prev != nullptr)
//                     prev->next = node->next;
//                 node = node->next;
//             }
//         }
//         return newHead;
//     }
// };

// class Solution
// {
// public:
//     ListNode *middleNode(ListNode *head)
//     {
//         ListNode *fast = head;
//         ListNode *slow = head;
//         while (fast && fast->next)
//         {
//             fast = fast->next->next;
//             slow = slow->next;
//         }

//         return slow;
//     }
// };

// struct ListNode
// {
//     int val;
//     struct ListNode *next;
//     ListNode(int x) : val(x), next(NULL)
//     {
//     }
// };
// class Solution
// {
// public:
//     ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
//     {
//         ListNode *fast = pListHead;
//         while (k)
//         {
//             if (fast == nullptr)
//                 break;
//             fast = fast->next;
//             --k;
//         }
//         if (k > 0)
//             return nullptr;
//         ListNode *slow = pListHead;
//         while (fast)
//         {
//             fast = fast->next;
//             slow = slow->next;
//         }
//         return slow;
//     }
// };

// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
//     {
//         if (list1 == nullptr)
//             return list2;
//         if (list2 == nullptr)
//             return list1;
//         ListNode *newHead = new ListNode;
//         ListNode *tail = newHead;
//         while (list1 && list2)
//         {
//             if (list1->val < list2->val)
//             {
//                 tail->next = list1;
//                 list1 = list1->next;
//             }
//             else
//             {
//                 tail->next = list2;
//                 list2 = list2->next;
//             }
//             tail = tail->next;
//         }

//         while (list1)
//         {
//             tail->next = list1;
//             list1 = list1->next;
//             tail = tail->next;
//         }
//         while (list2)
//         {
//             tail->next = list2;
//             list2 = list2->next;
//             tail = tail->next;
//         }
//         ListNode *result = newHead->next;
//         delete newHead;
//         return result;
//     }
// };

// class Partition
// {
// public:
//     ListNode *partition(ListNode *pHead, int x)
//     {
//         if (pHead == nullptr)
//             return pHead;
//         // 记录 比x小的
//         ListNode *newHead1 = nullptr;
//         // 记录 比x大的
//         ListNode *newHead2 = nullptr;
//         ListNode *tail1 = newHead1;
//         ListNode *tail2 = newHead2;
//         while (pHead)
//         {
//             if (pHead->val < x)
//             {
//                 if (newHead1 == nullptr)
//                 {
//                     newHead1 = pHead;
//                     tail1 = pHead;
//                 }
//                 else
//                 {
//                     tail1->next = pHead;
//                     tail1 = pHead;
//                 }
//             }
//             else
//             {
//                 if (newHead2 == nullptr)
//                 {
//                     newHead2 = pHead;
//                     tail2 = pHead;
//                 }
//                 else
//                 {
//                     tail2->next = pHead;
//                     tail2 = pHead;
//                 }
//             }
//             pHead = pHead->next;
//         }

//         if (newHead1)
//         {
//             tail1->next = newHead2;
//             if(tail2)
//                 tail2->next = nullptr;
//             return newHead1;
//         }

//         tail2->next = nullptr;
//         return newHead2;
//     }
// };

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
// class Partition
// {
// public:
//     ListNode *partition(ListNode *pHead, int x)
//     {
//         if (pHead == nullptr)
//             return pHead;
//         // 记录 比x小的
//         ListNode *newHead1 = new ListNode(0);
//         // 记录 比x大的
//         ListNode *newHead2 = new ListNode(0);

//         ListNode *tail1 = newHead1;
//         ListNode *tail2 = newHead2;

//         while (pHead)
//         {
//             if (pHead->val < x)
//             {
//                 tail1->next = pHead;
//                 tail1 = pHead;
//             }
//             else
//             {
//                 tail2->next = pHead;
//                 tail2 = pHead;
//             }
//             pHead = pHead->next;
//         }

//         if (newHead1->next)
//         {
//             tail1->next = newHead2->next;
//             tail2->next = nullptr;
//             pHead = newHead1->next;
//         }
//         else
//         {
//             pHead = newHead2->next;
//         }
//         delete newHead1;
//         delete newHead2;
//         return pHead;
//     }
// };
// class Solution
// {
// public:
//     int size(ListNode *headA)
//     {
//         int count = 0;
//         while (headA)
//         {
//             count++;
//             headA = headA->next;
//         }
//         return count;
//     }

//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
//     {
//         if (headA == nullptr || headB == nullptr)
//             return nullptr;
//         int lenA = size(headA);
//         int lenB = size(headB);
//         int k = 0;
//         if (lenA > lenB)
//         {
//             k = lenA - lenB;
//             while (k > 0)
//             {
//                 headA = headA->next;
//                 k--;
//             }
//         }
//         else
//         {
//             k = lenB - lenA;
//             while (k > 0)
//             {
//                 headB = headB->next;
//                 k--;
//             }
//         }

//         while (headA && headB)
//         {
//             if (headA == headB)
//                 return headA;
//             headB = headB->next;
//             headA = headA->next;
//         }
//         return nullptr;
//     }
// };

// class PalindromeList
// {

//     ListNode *reverseList(ListNode *head)
//     {
//         if (nullptr == head || head->next == nullptr)
//             return head;
//         ListNode *newHead = reverseList(head->next);
//         head->next->next = head;
//         head->next = nullptr;
//         return newHead;
//     }

// public:
//     bool chkPalindrome(ListNode *A)
//     {
//         if (A == nullptr)
//             return true;
//         ListNode *fast = A;
//         ListNode *slow = fast;
//         int count = 0;
//         while (fast && fast->next)
//         {
//             ++count;
//             fast = fast->next->next;
//             slow = slow->next;
//         }
//         ListNode *B = reverseList(slow);

//         while (count--)
//         {
//             if (A->val != B->val)
//             {
//                 return false;
//             }
//             A = A->next;
//             B = B->next;
//         }
//         return true;
//     }
// };

// class Solution
// {
// public:
//     bool hasCycle(ListNode *head)
//     {
//         if (head == nullptr)
//             return false;
//         ListNode *fast = head;
//         ListNode *slow = fast;
//         while (fast && fast->next)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//             if (fast == slow)
//                 return true;
//         }
//         return false;
//     }
// };

// class Solution {
// public:
//     ListNode* detectCycle(ListNode* head)
//     {
//         if (head == nullptr)
//             return nullptr;
//         ListNode* fast = head;
//         ListNode* low = head;

//         ListNode* node = nullptr;
//         while (fast && fast->next && low)
//         {
//             fast = fast->next->next;
//             low = low->next;
//             if (fast == low)
//             {
//                 node = fast;
//                 break;
//             }
//         }
//         if (node == nullptr)
//             return nullptr;
//         while (node != head)
//         {
//             node = node->next;
//             head = head->next;
//         }
//         return head;
//     }
// };

// class Node
// {
// public:
//     int val;
//     Node *next;
//     Node *random;

//     Node(int _val)
//     {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

// class Solution
// {
// public:
//     Node *copyRandomList(Node *head)
//     {
//         if (head == nullptr)
//             return nullptr;
//         std::unordered_map<Node *, Node *> m;
//         Node *newHead = nullptr;
//         Node *tail = nullptr;
//         Node *node = head;
//         while (node)
//         {
//             Node *cur = new Node(node->val);
//             cur->random = node->random;
//             if (tail == nullptr)
//             {
//                 newHead = cur;
//             }
//             else
//             {
//                 tail->next = cur;
//             }
//             tail = cur;
//             m[node] = cur;
//             node = node->next;
//         }

//         node = newHead;
//         while (node)
//         {
//             if (node->random)
//             {
//                 node->random = m[node->random];
//             }
//             node = node->next;
//         }
//         return newHead;
//     }
// };
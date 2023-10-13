
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* prev = nullptr;
        ListNode* node = head;
        while (node)
        {
            ListNode* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
};

//class Solution {
//public:
//    ListNode* removeElements(ListNode* head, int val) {
//        if (head == nullptr)
//            return head;
//        ListNode* prev = nullptr;
//        ListNode* node = head;
//        ListNode* newHead = prev;
//        while (node != nullptr)
//        {
//            if (node->val != val)
//            {
//                if (prev == nullptr)
//                    newHead = node;
//                prev = node;
//                node = node->next;
//            }
//            else
//            {
//                if (prev != nullptr)
//                    prev->next = node->next;
//                node = node->next;
//            }
//        }
//        return newHead;
//    }
//};
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> vv;
        if (pRoot == nullptr) {
            return vv;
        }
        queue<TreeNode*> q;
        q.push(pRoot);
        int size = 1;
        vector<int> v;
        int flag = 0;
        while (size--) {
            TreeNode* ret = q.front();
            q.pop();
            if (ret->left)
                q.push(ret->left);
            if (ret->right)
                q.push(ret->right);

            v.push_back(ret->val);

            if (size == 0)
            {
                if (flag == 0) 
                {
                    flag = 1;
                }
                else 
                {
                    // ÄæÖÃÒ»ÏÂ
                    reverse(v.begin(), v.end());
                    flag = 0;
                }
                vv.push_back(v);
                v.clear();
                size = q.size();
            }

        }// endofwhile
        return vv;
    }

};

int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* tL = new TreeNode(2);
    TreeNode* tR = new TreeNode(3);
    TreeNode* t4 = new TreeNode(4);
    TreeNode* t5 = new TreeNode(5);
    root->left = tL;
    root->right = tR;
    tR->left = t4;
    tR->right = t5;
    Solution().Print(root);
    return 0;
}

//class Solution {
//public:
//    struct myCompare {
//        bool operator()(int x, int y) {
//            string sx = to_string(x);
//            string sy = to_string(y);
//
//            string A = sx;
//            A += sy;
//
//            string B = sy;
//            B += sx;
//
//            return A < B;
//        }
//    };
//    string PrintMinNumber(vector<int> numbers) {
//        if (numbers.empty())
//            return "";
//        //myCompare cmp;
//        //sort(numbers.begin(), numbers.end(), cmp);
//        sort(numbers.begin(), numbers.end(), myCompare());
//        string str;
//        for (auto& val : numbers)
//            str += to_string(val);
//        return str;
//    }
//};
//
//int main()
//{
//    vector<int> v;
//    v.push_back(3);
//    v.push_back(32);
//    v.push_back(321);
//    string str = Solution().PrintMinNumber(v);
//    cout << str << endl;
//    return 0;
//}
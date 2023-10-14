#include <vector>
using namespace std;

// struct TreeNode
// {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// class Solution
// {
// public:
//   bool isUnivalTree(TreeNode *root)
//   {
//     if (root == nullptr)
//       return true;
//     int val = root->val;

//     if (root->left && root->left->val != val)
//     {
//       return false;
//     }
//     if (root->right && root->right->val != val)
//     {
//       return false;
//     }

//     return isUnivalTree(root->left) && isUnivalTree(root->right);
//   }
// };

// class Solution
// {
// public:
//   bool isSameTree(TreeNode *p, TreeNode *q)
//   {
//     if (p == nullptr && q == nullptr)
//       return true;
//     if (p == nullptr || q == nullptr)
//       return false;
//     if (p->val != q->val)
//       return false;
//     return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//   }
// };

// class Solution
// {
// public:
//   bool _isSymmetric(TreeNode *root1, TreeNode *root2)
//   {
//     if (root1 == nullptr && root2 == nullptr)
//       return true;
//     if (root1 == nullptr || root2 == nullptr)
//       return false;

//     if (root1->val != root2->val)
//       return false;
//     return _isSymmetric(root1->left, root2->right) && _isSymmetric(root1->right, root2->left);
//   }

//   bool isSymmetric(TreeNode *root)
//   {
//     if (root == nullptr)
//       return true;
//     return _isSymmetric(root->left, root->right);
//   }
// };

// class Solution
// {
// public:
//   // 跟左右
//   void _preorderTraversal(vector<int> &v, TreeNode *root)
//   {
//     if (root == nullptr)
//       return;
//     v.push_back(root->val);
//     _preorderTraversal(v, root->left);
//     _preorderTraversal(v, root->right);
//   }
//   vector<int> preorderTraversal(TreeNode *root)
//   {
//     vector<int> result;
//     _preorderTraversal(result, root);
//     return result;
//   }
// };

// class Solution
// {
// public:
//   void _inorderTraversal(vector<int> &v, TreeNode *root)
//   {
//     if (root == nullptr)
//       return;
//     _inorderTraversal(v, root->left);
//     v.push_back(root->val);
//     _inorderTraversal(v, root->right);
//   }
//   vector<int> inorderTraversal(TreeNode *root)
//   {
//     vector<int> result;
//     _inorderTraversal(result, root);
//     return result;
//   }
// };

// class Solution
// {
// public:
//   void _postorderTraversal(vector<int> &v, TreeNode *root)
//   {
//     if (root == nullptr)
//       return;
//     _postorderTraversal(v, root->left);
//     _postorderTraversal(v, root->right);
//     v.push_back(root->val);
//   }
//   vector<int> postorderTraversal(TreeNode *root)
//   {
//     vector<int> result;
//     _postorderTraversal(result, root);
//     return result;
//   }
// };

// class Solution
// {
// public:
//   bool isSameTree(TreeNode *p, TreeNode *q)
//   {
//     if (p == nullptr && q == nullptr)
//       return true;
//     if (p == nullptr || q == nullptr)
//       return false;
//     if (p->val != q->val)
//       return false;
//     return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//   }
//   bool isSubtree(TreeNode *root, TreeNode *subRoot)
//   {
//     if (root == nullptr && subRoot == nullptr)
//       return true;
//     if (root == nullptr || subRoot == nullptr)
//       return false;
//     if (root->val == subRoot->val)
//     {
//       if (isSameTree(root, subRoot))
//         return true;
//     }
//     return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//   }
// };

#include <iostream>
#include <string>
using namespace std;
struct TreeNode
{
  char val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

void _inorderTraversal(TreeNode *root)
{
  if (root == nullptr)
    return;
  _inorderTraversal(root->left);
  cout << root->val << " ";
  _inorderTraversal(root->right);
}

TreeNode *createTree(int &index, std::string &str)
{
  if (index > str.size())
    return nullptr;
  if (str[index] == '#')
  {
    ++index;
    return nullptr;
  }

  TreeNode *node = new TreeNode(str[index++]);
  node->left = createTree(index, str);
  node->right = createTree(index, str);
  return node;
}
void destory(TreeNode *root)
{
  if (root == nullptr)
    return;
  destory(root->left);
  destory(root->right);
  delete root;
}
int main()
{
  string str;
  getline(cin, str);
  int index = 0;
  TreeNode *root = createTree(index, str);
  _inorderTraversal(root);
  destory(root);
  return 0;
}
// 64 位输出请用 printf("%lld")
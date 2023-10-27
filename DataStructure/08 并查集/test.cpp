#include <iostream>
#include "UnionFindSet.hpp"
using namespace std;
int main()
{
  std::cout << "hello" << std::endl;
  return 0;
}
// int main()
//{
//	string a[] = { "hello", "1", "lis" };
//	//UnionFindSet<string> ufs(a, 3);
//	UnionFindSet<string> ufs(3);
//	return 0;
// }

// https://leetcode.cn/problems/bLyHh0/

// class Solution {
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         // ���ٸ�����
//         UnionFindSet<int> ufs(isConnected.size());
//         for (int i = 0; i < isConnected.size(); i++)
//         {
//             for (int j = 0; j < isConnected[i].size(); j++)
//             {
//                 if (isConnected[i][j] == 1)
//                 {
//                     // ����ϲ�
//                     ufs.Union(i, j);
//                 }
//             }
//         }
//         return ufs.size();
//     }
// };

// class Solution {
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         vector<int> ufs(isConnected.size(), -1);
//         auto f = [&ufs](int x)
//         {
//             while (ufs[x] >= 0)
//             {
//                 x = ufs[x];
//             }
//             return x;
//         };
//         for (int i = 0; i < isConnected.size(); i++)
//         {
//             for (int j = 0; j < isConnected[i].size(); j++)
//             {
//                 if (isConnected[i][j] == 1)
//                 {
//                     int root1 = f(i);
//                     int root2 = f(j);
//                     if (root1 != root2)
//                     {
//                         ufs[root1] += ufs[root2];
//                         ufs[root2] = root1;
//                     }
//                 }
//             }
//         }
//         int result = 0;
//         for (int i = 0; i < ufs.size(); ++i)
//         {
//             if (ufs[i] < 0) ++result;
//         }
//         return result;
//     }
// };

// https://leetcode.cn/problems/satisfiability-of-equality-equations/discussion/
// class Solution {
// public:
//     bool equationsPossible(vector<string>& equations) {
//         vector<int> ufs(26, -1);
//         auto f = [&ufs](int x)
//         {
//             while (ufs[x] >= 0)
//             {
//                 x = ufs[x];
//             }
//             return x;
//         };
//         for (auto& str : equations)
//         {
//             // �Ȱ�
//             if (str[1] == '=')
//             {
//                 int root1 = f(str[0] - 'a');
//                 int root2 = f(str[3] - 'a');
//                 if (root1 != root2)
//                 {
//                     ufs[root1] += ufs[root2];
//                     ufs[root2] = root1;
//                 }
//
//             }
//         }
//         for (auto& str : equations)
//         {
//             // �Ȱ�
//             if (str[1] == '!')
//             {
//                 int root1 = f(str[0] - 'a');
//                 int root2 = f(str[3] - 'a');
//                 if (root1 == root2)
//                 {
//                     return false;
//                 }
//
//             }
//         }
//         return true;
//     }
// };

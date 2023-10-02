#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

// class Solution
// {
// public:

//   struct Comper
//   {
//     bool operator()(const std::pair<int, int>& p1, const std::pair<int, int>& p2)
//     {
//       if(p1.second == p2.second)
//       {
//         return p1.first < p2.first;
//       }
//       return p1.second > p2.second;
//     }
//   };

//   vector<int> getLuckyNum(vector<vector<int>> &nums)
//   {
//     vector<int> result;
//     if (nums.empty())
//       return result;
//     int len = nums.size();
//     unordered_map<int, int> m;
//     for (int i = 1; i < 34; i++)
//       m[i] = len;

//     // 遍历整个数组
//     for (auto &e : nums)
//     {
//       for (auto &val : e)
//         m[val]--;
//     }

//     // 开始出现一个小堆

//     std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, Comper> q;
//     auto iter = m.begin();

//     while (iter != m.end())
//     {

//       if (q.size() < 7)
//       {
//         q.push({iter->first, iter->second});
//       }
//       else
//       {
//         // 判断
//         if (q.top().second < iter->second)
//         {
//           q.pop();
//           q.push({iter->first, iter->second});
//         }
//         else if (q.top().second == iter->second && q.top().first > iter->first)
//         {
//           q.pop();
//           q.push({iter->first, iter->second});
//         }
//       }
//        ++iter;
//     }
//     while (!q.empty())
//     {
//       result.push_back(q.top().first);
//       q.pop();
//     }
//     sort(result.begin(), result.end());
//     return result;
//   }
// };

// class Solution
// {
// public:

//   struct Comper
//   {
//     bool operator()(const std::pair<int, int>& p1, const std::pair<int, int>& p2)
//     {
//       return p1.second < p2.second;
//     }
//   };

//   vector<int> getLuckyNum(vector<vector<int>> &nums)
//   {
//     vector<int> result;
//     if (nums.empty())
//       return result;
//     int len = nums.size();
//     unordered_map<int, int> m;
//     for (int i = 1; i < 34; i++)
//       m[i] = len;

//     // 遍历整个数组
//     for (auto &e : nums)
//     {
//       for (auto &val : e)
//         m[val]--;
//     }
//     // 开始出现一个小堆

//     std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, Comper> q;
//     auto iter = m.begin();
//     while (iter != m.end())
//     {

//       if (q.size() < 7)
//       {
//         q.push({iter->first, iter->second});
//       }
//       else
//       {
//         // 判断
//         if (q.top().second < iter->second)
//         {
//           q.pop();
//           q.push({iter->first, iter->second});
//         }
//         else if (q.top().second == iter->second && q.top().first > iter->first)
//         {
//           q.pop();
//           q.push({iter->first, iter->second});
//         }
//         ++iter;
//       }
//     }
//     while (!q.empty())
//     {
//       result.push_back(q.top().first);
//       q.pop();
//     }
//     sort(result.begin(), result.end());
//     return result;
//   }
// };

// #include <iostream>
// #include <string>
// #include <unordered_map>
// #include <vector>
// #include <algorithm>
// using namespace std;
// void func(string &str, vector<int> &v)
// {
//   int begin = 0;
//   while (true)
//   {
//     auto pos = str.find(',', begin);
//     if (pos == std::string::npos)
//     {
//       v.push_back(stoi(str.substr(begin)));
//       break;
//     }
//     v.push_back(stoi(str.substr(begin, pos - begin)));
//     begin = pos + 1;
//   }
// }

// int func2(unordered_map<int, int> &m, vector<int> &v, int root, int node, int val)
// {
//   int now_node = node;
//   int result = 0;
//   int index = -1;
//   while (now_node != root)
//   {
//     if (now_node ^ val > result)
//     {
//       index = now_node;
//       result = max(result, now_node ^ val);
//     }

//     now_node = m[now_node];
//   }
//   if (now_node ^ val > result)
//   {
//     index = now_node;
//     result = max(result, now_node ^ val);
//   }

//   return index;
// }

// int main()
// {
//   string parent_str;
//   getline(cin, parent_str);
//   vector<int> parents;
//   func(parent_str, parents);
//   // for (auto e : parents)
//   //   cout << e << endl;

//   int root = -1;
//   unordered_map<int, int> m;
//   for (int i = 0; i < parents.size(); i++)
//   {
//     if (parents[i] == -1)
//     {
//       root = i;
//     }
//     else
//     {
//       m[i] = parents[i];
//     }
//   }

//   // 此时可以了
//   vector<int> result;
//   string str;
//   while (cin >> str)
//   {
//     vector<int> v;
//     func(str, v);
//     result.push_back(func2(m, parents, root, v[0], v[1]));
//   }

//   for (int i = 0; i < result.size(); i++)
//   {
//     if (i == result.size() - 1)
//     {
//       cout << result[i] << endl;
//     }
//     else
//     {
//       cout << result[i] << ",";
//     }
//   }
//   return 0;
// }
// // 64 位输出请用 printf("%lld")

// #include <iostream>
// #include <string>
// #include <unordered_map>
// #include <vector>
// #include <algorithm>
// using namespace std;
// void func(string &str, vector<int> &v, int &root, unordered_map<int, int> &m)
// {
//   int begin = 0;
//   int index = 0;
//   int val = 0;
//   while (true)
//   {
//     auto pos = str.find(',', begin);
//     if (pos == std::string::npos)
//     {
//       val = stoi(str.substr(begin));
//       if (val == -1)
//       {
//         root = index;
//       }
//       else
//       {
//         m[index] = val;
//       }
//       break;
//     }
//     val = stoi(str.substr(begin));
//     if (val == -1)
//     {
//       root = index;
//     }
//     else
//     {
//       m[index] = val;
//     }
//     begin = pos + 1;
//     index++;
//   }
// }

// int func2(unordered_map<int, int> &m, int root, int node, int val)
// {
//   int now_node = node;
//   int result = 0;
//   int index = -1;

//   while (now_node != root)
//   {
//     if ((now_node ^ val) > result)
//     {
//       index = now_node;
//       result = max(result, now_node ^ val);
//     }

//     now_node = m[now_node];
//   }
//   if ((now_node ^ val) > result)
//   {
//     index = now_node;
//     result = max(result, now_node ^ val);
//   }

//   return index;
// }

// int main()
// {
//   string parent_str;
//   getline(cin, parent_str);
//   vector<int> parents;
//   int root = -1;
//   unordered_map<int, int> m;

//   func(parent_str, parents, root, m);

//   int a = 0;
//   int b = 0;
//   string result;
//   while ((scanf("%d,%d", &a, &b)) != EOF)
//   {
//     result += to_string(func2(m, root, a, b));
//     result += ",";
//   }
//   // result.erase(result.end());
//   result.resize(result.size() - 1);
//   printf("%s", result.c_str());
//   return 0;
// }
// 64 位输出请用 printf("%lld")

// int main()
// {
//   int a = 0;
//   int b = 0;
//   scanf("%d,%d", &a, &b);
//   printf("%d %d", a, b);
//   return 0;
// }

// #include <iostream>
// #include <string>
// #include <unordered_map>
// #include <vector>
// #include <algorithm>
// using namespace std;
// void func(string &str, int &root, unordered_map<int, int> &m)
// {
//   int begin = 0;
//   int index = 0;
//   int val = 0;
//   while (true)
//   {
//     auto pos = str.find(',', begin);
//     if (pos == std::string::npos)
//     {
//       val = stoi(str.substr(begin));
//       if (val == -1)
//       {
//         root = index;
//       }
//       else
//       {
//         m[index] = val;
//       }
//       break;
//     }
//     val = stoi(str.substr(begin));
//     if (val == -1)
//     {
//       root = index;
//     }
//     else
//     {
//       m[index] = val;
//     }
//     begin = pos + 1;
//     index++;
//   }
// }

// int func2(unordered_map<int, int> &m, int root, int node, int val)
// {
//   int now_node = node;
//   int result = 0;
//   int index = -1;

//   while (now_node != root)
//   {
//     if ((now_node ^ val) > result)
//     {
//       index = now_node;
//       result = max(result, now_node ^ val);
//     }
//     now_node = m[now_node];
//   }

//   if ((now_node ^ val) > result)
//   {
//     index = now_node;
//     result = max(result, now_node ^ val);
//   }

//   return index;
// }

// int main()
// {
//   string parent_str;
//   getline(cin, parent_str);

//   int root = -1;
//   unordered_map<int, int> m;

//   func(parent_str, root, m);

//   int a = 0;
//   int b = 0;
//   string result;
//   while ((scanf("%d,%d", &a, &b)) != EOF)
//   {
//     result += to_string(func2(m, root, a, b));
//     result += ",";
//   }
//   result.resize(result.size() - 1);
//   printf("%s", result.c_str());
//   return 0;
// }
// #include <iostream>
// #include <vector>

// using namespace std;

// vector<int> result;
// void is_min(vector<int> &help)
// {
//   if (result.empty())
//   {
//     result = help;
//     return;
//   }
//   for (int i = 0; i < result.size(); i++)
//   {
//     if (result[i] < help[i])
//     {
//       result = help;
//       return;
//     }
//   }
// }
// void func(const vector<int> &v, int index, vector<int> &help)
// {
//   if (index == v.size())
//   {
//     is_min(help);
//     return;
//   }

//   for (int i = index; i < v.size(); i++)
//   {
//     help.push_back(v[i]);
//     func(v, i + 1, help);
//     help.pop_back();
//   }
// }
// int main()
// {
//   int n = 0;
//   vector<int> v(n, 0);
//   cin >> n;
//   for (int i = 0; i < n; i++)
//     cin >> v[i];
//   vector<int> help;
//   func(v, 0, help);
//   for (auto &e : result)
//     cout << e << " ";
//   cout << endl;
//   return 0;
// }

// // 64 位输出请用 printf("%lld")

// #include <iostream>
// #include <string>
// using namespace std;
// string func(string s, string t)
// {
//   for (int i = 0; i < t.size(); i++)
//   {
//     if (s == t)
//       return "Yes";
//     if (s[i] != t[i])
//     {
//       // 更新所有的s[i]
//       for (size_t j = 0; i < s.size(); i++)
//       {
//         if (s[j] == s[i])
//           s[j] = t[i];
//       }
//     }
//   }
//   return "NO";
// }
// int main()
// {
//   int n = 0;
//   cin >> n;
//   for (int i = 0; i < n; i++)
//   {
//     string s;
//     string t;

//     getline(cin, s);
//     getline(cin, t);

//     cout << func(s, t) << endl;
//   }
//   return 0;
// }
// // 64 位输出请用 printf("%lld")

// #include <iostream>
// using namespace std;

// int main() {
//     int a, b;
//     while (cin >> a >> b) { // 注意 while 处理多个 case
//         cout << a + b << endl;
//     }
// }
// // 64 位输出请用 printf("%lld")

#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
  int n = 0;
  cin >> n;
  getchar();

  for (int i = 0; i < n; i++)
  {
    string s;
    string t;
    getline(cin, s);
    getline(cin, t);
    set<char> s1;
    set<char> s2;

    string s_copy;
    string t_copy;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] != t[i])
      {
        s_copy += s[i];
        t_copy += t[i];
      }
    }
    for (auto e : s_copy)
      s1.insert(e);
    for (auto e : t_copy)
      s2.insert(e);
    // 重复元素的个数
    int ret1 = s_copy.size() - s1.size();
    int ret2 = t_copy.size() - s2.size();
    if (ret1 <= ret2)
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }
  return 0;
}
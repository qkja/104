<<<<<<< HEAD
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> result;
//void is_min(vector<int> &help)
//{
//  if (result.empty())
//  {
//    result = help;
//    return;
//  }
//  for (int i = 0; i < result.size(); i++)
//  {
//    if (result[i] < help[i])
//    {
//      result = help;
//      return;
//    }
//  }
//}
//void func(const vector<int> &v, int index, vector<int> help, vector<bool>& falgs)
//{
//    if (help.size() == v.size())
//    {
//        is_min(help);
//        return;
//    }
//    for (int i = 0; i < v.size(); i++)
//    {
//        // 碰到当前元素
//        if (falgs[i] == true)
//        {
//            help.push_back(v[i]);
//            falgs[i] == false;
//            func(v, i+1, help, falgs);
//            falgs[i] == true;
//        }
//        else
//        {
//            func(v, 0, help, falgs);
//        }
//           
//
//    }
//}
//int main()
//{
//  int n = 0;
//  cin >> n;
//  vector<int> v(n, 0);
//
//  for (int i = 0; i < n; i++)
//    cin >> v[i];
//  vector<int> help;
//  vector<bool> falgs(n, true);
//
//  func(v, 0, help, falgs);
//  for (auto &e : result)
//    cout << e << " ";
//  cout << endl;
//  return 0;
//}

// 64 位输出请用 printf("%lld")

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//string func(string s, string t)
//{
//    for (int i = 0; i < t.size(); i++)
//    {
//
//        if (s[i] != t[i])
//        {
//            // 更新所有的s[i]
//            for (size_t j = 0; j < s.size(); j++)
//            {
//                if (s[j] == s[i])
//                    s[j] = t[i];
//            }
//        }
//        if (s == t)
//            return "Yes";
//    }
//    return "No";
//}
//int main()
//{
//    int n = 0;
//    cin >> n;
//    getchar();
//
//    for (int i = 0; i < n; i++)
//    {
//        string s;
//        string t;
//
//        getline(cin, s);
//        getline(cin, t);
//        string s1 = s;
//        string t1 = t;
//        sort(s1.begin(), s1.end());
//        sort(t1.begin(), t1.end());
//        if(s1 == t1)
//            cout << "Yes" << endl;
//        else
//        {
//            cout << func(s, t) << endl;
//        }
//      
//    }
//    return 0;
//}
//// 64 位输出请用 printf("%lld")
//#include <iostream>
//#include <string>
//#include <unordered_map>
//using namespace std;
//
//bool canTransform(const std::string& s, const std::string& t) {
//    if (s.length() != t.length()) {
//        return false;
//    }
//
//    std::unordered_map<char, char> transformation; // 用于存储字符映射关系
//
//    for (int i = 0; i < s.length(); ++i) {
//        char ch1 = s[i];
//        char ch2 = t[i];
//
//        // 如果已经有映射关系，检查是否一致
//        if (transformation.find(ch1) != transformation.end() && transformation[ch1] != ch2) {
//            return false;
//        }
//
//        // 建立映射关系
//        transformation[ch1] = ch2;
//    }
//
//    return true;
//}
//
//int main() {
//    std::string s = "abcda";
//    std::string t = "edced";
//
//    bool result = canTransform(s, t);
//
//    if (result) {
//        std::cout << "Yes" << std::endl;
//    }
//    else {
//        std::cout << "No" << std::endl;
//    }
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
=======
// #include <iostream>
// #include <vector>
>>>>>>> cdebc3f4e03e45990ea8f6abfc56c8537395dead

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

<<<<<<< HEAD
const int MOD = 1000000007;

int dp[105][15][75]; // dp[i][j][k]表示考虑前i位数字，选择j个数字修改，得到模75余数为k的方案数
int digits[105];    // 存储正整数的每一位数字

int main() {
    // 输入正整数
    int n;
    cin >> n;

    // 将正整数转换为数组形式
    int len = 0;
    while (n > 0) {
        digits[len++] = n % 10;
        n /= 10;
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    // 动态规划计算修改方法数量
    for (int i = 1; i <= len; ++i) {
        for (int j = 0; j <= min(i, 10); ++j) {
            for (int k = 0; k < 75; ++k) {
                // 不修改当前位
                dp[i][j][k] = dp[i - 1][j][k];

                // 修改当前位
                if (j > 0) {
                    int new_k = (k * 10 + digits[i - 1]) % 75;
                    dp[i][j][new_k] = (dp[i][j][new_k] + dp[i - 1][j - 1][k]) % MOD;
                }
            }
        }
    }


    int ans = 0;
    for (int j = 1; j <= 10; ++j) {
        ans = (ans + dp[len][j][0]) % MOD;
    }

    cout << ans << endl;

    return 0;
}
=======
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
>>>>>>> cdebc3f4e03e45990ea8f6abfc56c8537395dead

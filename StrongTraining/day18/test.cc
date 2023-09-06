// #include <iostream>
// using namespace std;
// int fib(int n)
// {
//     if(n < 3)
//     return  1;
//     return fib(n-1)+fib(n-2);
// }
// int main()
// {
//    int n = 0;
//     while (cin >> n)
//     { // 注意 while 处理多个 case
//        cout << fib(n) <<endl;
//     }
// }
// // 64 位输出请用 printf("%lld")

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//int main()
//{
//  string s;
//  string t;
//  getline(cin, s); // 这个是普通的字符串
//  getline(cin, t); // 这个是完整的字符串
//  // 这里全部转成小写
//  for (auto &e : s)
//  {
//    if (e >= 'A' && e <= 'Z')
//      e = e + 'a' - 'A';
//  }
//  for (auto &e : t)
//  {
//    if (e >= 'A' && e <= 'Z')
//      e = e + 'a' - 'A';
//  }
//  int n = s.size();
//  int m = t.size();
//  vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
//  dp[0][0] = true;
//
//  for (int i = 1; i <= n; i++)
//  {
//    for (int j = 1; j <= m; j++)
//    {
//      if (s[i - 1] == '?')
//      {
//        dp[i][j] = dp[i - 1][j - 1];
//      }
//      else if (s[i - 1] == '*')
//      {
//        for (int index = j; index > 0; index--)
//        {
//          if (t[index - 1] > 'a' && t[index - 1] < 'z' || t[index - 1] > '0' && t[index - 1] < '0')
//          {
//            dp[i][j] = dp[i - 1][index];
//          }
//          else
//          {
//            break;
//          }
//        }
//      }
//      else
//      {
//        // 'a', '.'
//        if (s[i - 1] == t[j - 1])
//          dp[i][j] = dp[i - 1][j - 1];
//      }
//    }
//  }
//  
//  if (dp[n][m])
//  {
//    cout << "true" << endl;
//  }
//  else
//  {
//    cout << "false" << endl;
//  }
//  return 0;
//}
// 64 位输出请用 printf("%lld")

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    string t;
    getline(cin, s); // 这个是普通的字符串
    getline(cin, t); // 这个是完整的字符串
    // 这里全部转成小写
    for (auto& e : s) {
        if (e >= 'A' && e <= 'Z')
            e = e + 'a' - 'A';
    }
    for (auto& e : t) {
        if (e >= 'A' && e <= 'Z')
            e = e + 'a' - 'A';
    }
    int n = s.size();
    int m = t.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '*')
            dp[i][0] = true;
        else
            break;;
    }
    for (int i = 1; i <= n; i++) 
    {
        if (i == 2)
        {
            int a = 10;
        }
        for (int j = 1; j <= m; j++)
        {
                //if (s[i - 1] == '?' && (t[j - 1] >= 'a' && t[j - 1] <= 'z') || t[j - 1] >= '0' && t[j - 1] <= '9') {
            if (s[i - 1] == '?' 
                && ((t[j - 1] >= 'a' && t[j - 1] <= 'z')
                    || (t[j - 1] >= '0' && t[j - 1] <= '9')))
                {
                dp[i][j] = dp[i - 1][j - 1];
                  }
                 else if (s[i - 1] == '*') {
                for (int index = j; index >= 0; index--) {
                    dp[i][j] = dp[i][j] || dp[i - 1][index];

                    // 此时问题来了,
                    if (index - 1 >= 0 && !((t[index - 1] >= 'a' && t[index - 1] <= 'z'
                        || t[index - 1] >= '0' && t[index - 1] <= '9'))) {
                        break;
                    }
                }
            }
            else {
                // 'a', '.'
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    //   cout << "true"<<endl;  cout << "true"<<endl;
    if (dp[n][m]) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;

    }
    return 0;
}
// 64 位输出请用 printf("%lld")
#include <algorithm>
#include <iostream>
using namespace std;

//int main()
//{
//    int n = 0;
//    while (cin >> n)
//    {
//        int count = 0;
//        while (true)
//        {
//            count += n / 3;
//            n = n % 3 + n / 3;
//            if (n == 2)
//            {
//                count++;
//                break;
//            }
//            if (n < 2)
//            {
//                break;
//            }
//        }
//        if (count)
//            cout << count << endl;
//    }
//
//}
//// 64 位输出请用 printf("%lld")

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);
    if (s1.size() > s2.size())
        swap(s1, s2);
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLen = 0;
    int index = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            if (dp[i][j] > maxLen)
            {
                maxLen = dp[i][j];
                index = i - maxLen;
            }
        }
    }
    cout << s1.substr(index, maxLen) << endl;
    return 0;;
}
// 64 位输出请用 printf("%lld")
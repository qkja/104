//#include <iostream>
//#include <iterator>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int main() {
//    string str;
//    getline(cin, str);
//    reverse(str.begin(), str.end());
//    cout << str << endl;
//    return 0;
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

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLen = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            if (dp[i][j] > maxLen) {
                maxLen = dp[i][j];
            }
        }
    }
    cout << maxLen << endl;
    return 0;;
}
// 64 位输出请用 printf("%lld")
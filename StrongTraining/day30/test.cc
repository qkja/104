// #include <iostream>
// #include <string>
// #include <unordered_map>
// using namespace std;

// int main() {
//     string cipher_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//     string original_letter = "VWXYZABCDEFGHIJKLMNOPQRSTU";
//     unordered_map<char, char> m;
//     for (int i = 0; i < cipher_alphabet.size(); i++)
//         m[cipher_alphabet[i]] = original_letter[i];

//     string str;
//     while (getline(cin, str)) {
//         string result;
//         for (int i = 0; i < str.size(); i++) {
//             if (str[i] == ' ')
//                 result += str[i];
//             else
//                 result += m[str[i]];
//         }
//         cout <<result << endl;
//     }
// }
// // 64 位输出请用 printf("%lld")
#include <iostream>
#include <set>
#include <math.h>
using namespace std;
void is_prime_number(int val, set<int> &s)
{
  s.clear();
  for (int i = 2; val > 1 && i <= sqrt(val); i++)
  {
    while (val % i == 0)
    {
      s.insert(i);
      val /= i;
    }
  }
  if (val > 1)
    s.insert(val);
}
int main()
{
  int n = 0;
  while (cin >> n)
  { // 注意 while 处理多个 case
    set<int> s;
    is_prime_number(n, s);

    cout << s.size() << endl;
  }
}
// 64 位输出请用 printf("%lld")
/**
 * User: Qkj
 * Description:
 * Date: 2023-05-26
 * Time: 09:34
 */
#include <iostream>
#include <vector>
using namespace std;
// https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062
// int fib(int n)
// {

//   if (n == 0)
//     return 0;
//   if (n == 1)
//     return 1;
//   ;
//   if (n == 2)
//     return 2;
//   int left = 1;
//   int right = 2;
//   for (int i = 3; i <= n; i++)
//   {
//     int sum = (left + right) % 10000;
//     left = right;
//     right = sum;
//   }
//   return right;
// }

// int main()
// {
//   int n = 0;
//   while (cin >> n)
//   {
//     // cout << fib(n)<<endl;
//     for (size_t i = 0; i < n; i++)
//     {
//       int val = 0;
//       cin >> val;
//       printf("%04d", fib(val) % 10000);
//     }
//     printf("\n");
//   }

//   return 0;
// }
// 64 位输出请用 printf("%lld")
//https://www.nowcoder.com/questionTerminal/e2422543519249f292d8435394ab82fe
#include <iostream>
#include <string>
using namespace std;
void calculate_the_number_of_roots(int &n)
{
  // 拿到所有的值
  // 11
  int sum = 0;
  while (n)
  {
    sum += n % 10;
    n = n / 10;
  }
  n = sum;
}
int main()
{
  string str;
  while (cin >> str)
  {
    int n = 0;
    for (int i = 0; i < str.size(); ++i)
    {
      n += str[i] - '0';
    }
    while (n >= 10)
    {
      calculate_the_number_of_roots(n);
    }
    cout << n << endl;
  }
  return 0;
}
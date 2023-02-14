/**
 * User: Qkj
 * Description:
 * Date: 2023-02-14
 * Time: 19:18
 */

// #include <iostream>
// #include <algorithm>
// using namespace std;
// string fun(int x, int y)
// {
//   if (x == 0)

//     return "0";
//   bool flag = false;
//   if (x < 0)
//   {
//     flag = true;
//     x = -x;
//   }
//   string str = "0123456789ABCDEF";

//   string result;

//   while (x)
//   {
//     result += str[x % y];
//     x /= y;
//   }
//   if (flag)
//     result += "-";
//   reverse(result.begin(), result.end());

//   return result;
// }
// int main()
// {
//   int a, b;
//   while (cin >> a >> b)
//   {
//     cout << fun(a, b) << endl;
//   }
// }

// #include <iostream>
// #include <cstdio>
// using namespace std;

// #include <iostream>
// using namespace std;

// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <vector>

// #include <iostream>
// #include <algorithm>
// using namespace std;
// string fun(int x, int y)
// {

//   string str = "0123456789ABCDEF";

//   string result;

//   while (x)
//   {
//     result += str[x % y] ;
//     x /= y;
//   }

//   reverse(result.begin(), result.end());

//   return result;
// }
// int main()
// {
//   int a, b;
//   while (cin >> a >> b)
//   {
//     cout << fun(a, b) << endl;
//   }
// }

// #include <iostream>
// using namespace std;
// int fun(int x, int y)
// {
//   int count = 0;
//   while (x)
//   {
//     int ret = x % y;
//     count = count * 10 + ret;
//     x /= y;
//   }
//   return count;
// }
// int main()
// {
//   int a, b;
//   while (cin >> a >> b)
//   {
//     cout << fun(a, b) << endl;
//   }
// }
// 64 位输出请用 printf("%lld")
// using namespace std;
// int main()
// {
//   int x = 0;
//   int y = 0;
//   int z = 0;
//   int m = 0;
//   cin >> x >> y >> z >> m;
//   // 计算  b
//   int a = (x + z) / 2;
//   if (2 * a != (x + z))
//   {
//     cout << "No" << endl;
//     return 0;
//   }
//   int b = a - x;
//   int c = m - b;
//   if (a < 0 || b < 0 || c < 0)
//   {
//     cout << "No" << endl;
//   }
//   else
//   {
//     cout << a << " " << b << " " << c << endl;
//   }
//   return 0;
// }
// 64 位输出请用 printf("%lld")

// int func(int x)
// {
//   int count = 0;
//   while (x)
//   {
//     count++;
//     x = x & (x - 1); // 与运算
//   }
//   return count;
// }

// void func(char **m)
// {
//   ++m;
//   cout << *m << endl;
//   printf("%p\n", *m);
//   cout << (char*)*m << endl;
// }
// int main()
// {
//   static char *a[] = {"morning", "afternoon", "evening"};
//   char **p;
//   p = a;
//   func(p);
//   return 0;
// }

// int main()
// {
//   int m = 0123, n = 123;
//   printf("%o %o\n", m, n);
//   return 0;
// }
/**
 * User: Qkj
 * Description:
 * Date: 2023-02-13
 * Time: 20:19
 */

#include <iostream>
using namespace std;

#include <iostream>
#include <string>
#include <algorithm>

#include <iostream>
using namespace std;

class Solution
{
public:
  // 数组中出现次数超过一半的数字
  int MoreThanHalfNum_Solution(vector<int> numbers)
  {
    if (numbers.empty())
      return 0;
    // 这里我们用 打擂台的方式
    int ret = 0;
    int flag = 0;

    for (int i = 0; i < numbers.size(); i++)
    {
      if (flag == 0)
      {
        ret = numbers[i];
        flag = 1;
      }
      else if (numbers[i] == ret)
      {
        flag++; // 遇到相同的 擂台上增加一个
      }
      else
      {
        flag--;
      }
    }
    // 擂台上站的 一个或者 几个 就是我们要的
    // 至于是不是要验证一下  这里看题意了
    int count = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
      if (ret == numbers[i])
      {
        count++;
        if (count > numbers.size() / 2)
        {
          return ret;
        }
      }
    }
    return 0;
  }
};

// int main()
// {
//   string str;
//   getline(cin, str);
//   str += '#'; // 这个作用防止 aaaa111222这个情况 或者 不加  i <= str.size()
//   string cur;
//   string ret;
//   for (int i = 0; i < str.size(); i++)
//   {
//     if (str[i] >= '0' && str[i] <= '9')
//     {
//       cur += str[i];
//     }
//     else
//     {
//       if (cur.size() > ret.size())
//       {
//         ret = cur;
//       }
//       else
//         cur.clear();
//     }
//   }
//   cout << ret << endl;
//   return 0;
// }

// 64 位输出请用 printf("%lld")

// #include <stdio.h>
// int main()
// {
//   long long a = 1, b = 2, c = 3;
//   printf("%d %d %d\n", a, b, c);
//   return 0;
// }

// int main()
// {
//   int n = 0;
//   char ch = 0;
//   int j = 0;
//   // 注意  for 第一个字段只能使用一次
//   for (ch = getchar(); ch != '\n'; n++)
//   {
//     cout << ch << j++<< endl;
//   }
//   return 0;
// }

// int main()
// {
//   int x = 3, y = 3;
//   switch (x % 2)
//   {
//   case 1:
//     switch (y)
//     {
//     case 0:
//       cout << "first";
//     case 1:
//       cout << "second";
//       break;
//     default:
//       cout << "hello";
//     }
//   case 2:
//     cout << "third";
//   }
// }

// #include <stdio.h>
// int main()
// {
//   char a[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 0}, *p;
//   int i;
//   i = 8;
//   // 这里  分析   数字名+1 和 &数组名 + 1的区别
//   // 我们不关心,只要知道  指针解引用 后占据几个自己,我们+1就跳过几个字节
//   // &数组名  解引用我们   认为是 数组
//   p = a + i;
//   printf("%s\n", p - 3);
// }
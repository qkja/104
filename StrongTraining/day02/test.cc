/**
 * User: Qkj
 * Description:
 * Date: 2023-05-26
 * Time: 10:56
 */
#include <iostream>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>

using namespace std;
// https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue=1&page=1&onlyReference=false
//  int main()
//  {

//   int n = 0;

//   while (cin >> n)
//   {
//     std::vector<int> v(n + 1);
//     for (int i = 0; i < n; i++)
//     {
//       cin >> v[i];
//     }
//     int i = 0;
//     int count = 0;
//     while (i < n)
//     {
//       if (i + 1 < n && v[i] < v[i + 1])
//       {
//         // 进入非递减序列
//         while (i + 1 < n && v[i] <= v[i + 1])
//         {
//           i++;
//         }
//         count++;
//         i++;
//       }
//       else if (i + 1 < n && v[i] == v[i + 1])
//       {
//         i++;
//       }
//       else
//       {
//         while (i + 1 < n && v[i] >= v[i + 1])
//         {
//           i++;
//         }
//         count++;
//         i++;
//       }
//     }
//     std::cout << count << std::endl;
//   }
//   return 0;
// }
// https://www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355?tpId=85&&tqId=29867&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <string>
// using namespace std;
// void myReverse(string &str, int begin, int end)
// {
//   while (begin < end)
//   {

//     swap(str[begin], str[end]);
//     begin++;
//     end--;
//   }
// }
// int main()
// {
//   string str;
//   getline(cin, str);
//   int begin = 0;

//   for (int i = 0; i < str.size(); i++)
//   {
//     if (str[i] == ' ')
//     {
//       myReverse(str, begin, i - 1);
//       begin = i + 1;
//     }
//   }
//   myReverse(str, begin, str.size() - 1);

//   // cout << "------------" << endl;
//   myReverse(str, 0, str.size() - 1);
//   cout << str << endl;
// }
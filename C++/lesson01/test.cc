#include <sys/stat.h>
#include <unistd.h>
#include <iostream>

// int main()
// {
//   int ret = access("../lesson01/file.txt", F_OK);
//   if (ret == 0)
//   {
//     std::cout << "存在" << std::endl;
//   }
//   else
//   {
//     std::cout << "不存在" << std::endl;
//   }
//   return 0;
// }
// #include <string>

// int main()
// {
//   umask(2);
//   std::string str = "../lesson";
//   for (int i = 1; i < 27; i++)
//   {
//     std::string s = str;
//     if (i < 10)
//       s += '0';
//     s += std::to_string(i);
//     int ret = access(s.c_str(), F_OK);
//     if (ret == 0)
//     {
//       std::cout << s << " 存在" << std::endl;
//     }
//     else
//     {
//       mkdir(s.c_str(), 0777);
//     }
//   }

//   return 0;
// }
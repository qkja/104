/**
 * User: Qkj
 * Description:
 * Date: 2023-02-02
 * Time: 15:17
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <time.h>
#include <time.h>

#include <unordered_set>
#include <unordered_map>
using namespace std;

void test_op()
{
  int n = 10000;
  vector<int> v;
  v.reserve(n);

  srand(time(0));
  for (int i = 0; i < n; ++i)
  {
    // v.push_back(rand()+i);  // 重复少
    v.push_back(rand()); // 重复多
  }

  size_t begin1 = clock();
  set<int> s;
  for (auto e : v)
  {
    s.insert(e);
  }
  size_t end1 = clock();

  size_t begin2 = clock();
  unordered_set<int> us;
  for (auto e : v)
  {
    us.insert(e);
  }
  size_t end2 = clock();

  cout << s.size() << endl;

  cout << "set insert:" << end1 - begin1 << endl;
  cout << "unordered_set insert:" << end2 - begin2 << endl;

  // size_t begin3 = clock();
  // for (auto e : v)
  // {
  //   s.find(e);
  // }
  // size_t end3 = clock();

  // size_t begin4 = clock();
  // for (auto e : v)
  // {
  //   us.find(e);
  // }
  // size_t end4 = clock();
  // cout << "set find:" << end3 - begin3 << endl;
  // cout << "unordered_set find:" << end4 - begin4 << endl;

  // size_t begin5 = clock();
  // for (auto e : v)
  // {
  //   s.erase(e);
  // }
  // size_t end5 = clock();

  // size_t begin6 = clock();
  // for (auto e : v)
  // {
  //   us.erase(e);
  // }
  // size_t end6 = clock();
  // cout << "set erase:" << end5 - begin5 << endl;
  // cout << "unordered_set erase:" << end6 - begin6 << endl;
}



int main()
{

   test_op();

  return 0;
}

// int main()
// {
//   unordered_map<string, string> dict;
//   dict.insert(make_pair("string", "字符串"));
//   dict.insert(make_pair("sort", "排序"));
//   dict.insert(make_pair("string", "字符串"));
//   dict.insert(make_pair("string", "字符串"));
//   auto it = dict.begin();
//   while (it != dict.end())
//   {
//     cout << it->first << ":" << it->second << endl;
//     it++;
//   }
//   return 0;
// }

// #include <iostream>
// #include <unordered_set>
// using namespace std;

// int main()
// {
//   unordered_set<int> s;
//   s.insert(3);
//   s.insert(4);
//   s.insert(5);
//   s.insert(3);
//   s.insert(1);
//   s.insert(2);
//   s.insert(6);

//   unordered_set<int>::iterator it = s.begin();
//   while (it != s.end())
//   {
//     cout << *it << " ";
//     ++it;
//   }
//   cout << endl;
//   return 0;
// }

// #include <iostream>
// #include <string>
// #include "UnorderedMap.h"
// #include "HashTable.h"
// #include "UnorderedSet.h"

// using namespace std;
// void test_set()
// {
//   bit::unordered_set<int> dict;
//   dict.insert(1);
//   dict.insert(2);
//   dict.insert(3);
//   dict.insert(4);

//   bit::unordered_set<int>::iterator it = dict.begin();
//   while (it != dict.end())
//   {
//     cout << *it << " ";
//     ++it;
//   }
//   cout << endl;

//   it = dict.find(3);
//   if (it != dict.end())
//   {
//     cout << "找到了" << endl;
//   }
// }

// void test_map()
// {

//   bit::unordered_map<string, string> dict;

//   dict.insert(make_pair("sort", "排序"));
//   dict.insert(make_pair("left", "左侧"));
//   dict["left1"] = "剩余1";

//   bit::unordered_map<string, string>::iterator it = dict.begin();
//   while (it != dict.end())
//   {
//     cout << it->first << " " << (*it).second << endl;
//     it++;
//   }

//   dict["left"] = "剩余";
//   it = dict.begin();
//   while (it != dict.end())
//   {
//     cout << it->first << " " << (*it).second << endl;
//     it++;
//   }
// }
// #include <unordered_map>

// int main()
// {
//   test_map();
//   //test_set();
//   unordered_map<int,int> m;
  
//     return 0;
// }

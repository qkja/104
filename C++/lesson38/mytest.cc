/**
 * User: Qkj
 * Description:
 * Date: 2023-02-02
 * Time: 15:17
 */

#include <iostream>
#include <string>
#include "UnorderedMap.h"
#include "HashTable.h"
#include "UnorderedSet.h"

using namespace std;
void test_set()
{
  bit::unordered_set<int> dict;
  dict.insert(1);
  dict.insert(2);
  dict.insert(3);
  dict.insert(4);
  dict.erase(4);
  dict.erase(40);
  bit::unordered_set<int>::iterator it = dict.begin();
  while (it != dict.end())
  {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
}

void test_map()
{
  // bit::unordered_map<string, string> dict;
  // bool ret = dict.insert(make_pair("sort", "排序"));
  // cout << ret << endl;
  // ret = dict.insert(make_pair("left", "左侧"));
  // cout << ret << endl;

  // ret = dict.insert(make_pair("left", "剩余"));
  // cout << ret << endl;

  // ret = dict.erase("left");
  // cout << ret << endl;
  // ret = dict.insert(make_pair("left", "剩余"));
  // cout << ret << endl;

  // bit::unordered_map<string, string> dict;

  // dict.insert(make_pair("sort", "排序"));
  // dict.insert(make_pair("left", "左侧"));
  // dict.insert(make_pair("left", "剩余"));

  // bit::unordered_map<string, string>::iterator it = dict.begin();
  // while (it != dict.end())
  // {
  //   cout << it->first << " " << (*it).second << endl;
  //   it++;
  // }
  // dict.insert(make_pair("1111", "剩余"));
  // cout << "=====================" << endl;
  // it = dict.begin();
  // while (it != dict.end())
  // {
  //   cout << it->first << " " << (*it).second << endl;
  //   it++;
  // }
  // dict.insert(make_pair("1111", "剩余"));
  // 删除
  // dict.erase("1111");
  // it = dict.begin();
  // while (it != dict.end())
  // {
  //   cout << it->first << " " << (*it).second << endl;
  //   it++;
  // }
}

int main()
{
  // test_map();
  test_set();
  return 0;
}

// int main()
// {
//   int a[] = {20,5,8,99999,10,30,50};
//   Bucket::HashTable<int, int> ht;
//   for(auto e:a)
//   {
//     ht.insert(make_pair(e,e));
//   }
//   return 0;
// }

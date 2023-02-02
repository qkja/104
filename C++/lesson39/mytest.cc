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

  bit::unordered_set<int>::iterator it = dict.begin();
  while (it != dict.end())
  {
    cout << *it << " ";
    ++it;
  }
  cout << endl;

  it = dict.find(3);
  if (it != dict.end())
  {
    cout << "找到了" << endl;
  }
}

void test_map()
{

  bit::unordered_map<string, string> dict;

  dict.insert(make_pair("sort", "排序"));
  dict.insert(make_pair("left", "左侧"));
  dict["left1"] = "剩余1";

  bit::unordered_map<string, string>::iterator it = dict.begin();
  while (it != dict.end())
  {
    cout << it->first << " " << (*it).second << endl;
    it++;
  }

  dict["left"] = "剩余";
  it = dict.begin();
  while (it != dict.end())
  {
    cout << it->first << " " << (*it).second << endl;
    it++;
  }
}
#include <unordered_map>

int main()
{
  test_map();
  //test_set();
  unordered_map<int,int> m;
  
    return 0;
}

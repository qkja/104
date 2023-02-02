/**
* User: Qkj
* Description: 
* Date: 2023-02-01
* Time: 22:07
*/
#include "HashTable.h"
#include <iostream>
using namespace std;
int main()
{
  int a[] = {20, 5,8,99999,10,30,50};
  HashTable<int, int> ht;
  for(auto e:a)
  {
    ht.insert(make_pair(e,e));
  }
  ht.insert(make_pair(15,15));
  return 0;
}

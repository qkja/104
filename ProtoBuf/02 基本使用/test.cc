/**
* User: Qkj
* Description: 测试序列化与反序列化
* Date: 2023-09-19
* Time: 18:42
*/


#include <iostream>
#include "contacts.pb.h"

using namespace std;

int main()
{
  string people_str;
  {
    contacts::PeopleInfo people;
    people.set_age(20);
    people.set_name("张三");
    if(!people.SerializeToString(&people_str)) { cout << "序列化失败" << endl;}
    cout << people_str << endl;
  }
  return 0;
}

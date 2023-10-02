/**
* User: Qkj
* Description: 
* Date: 2023-09-19
* Time: 19:23
*/
#include <iostream>
#include "contacts.pb.h"
#include <string>
#include <fstream>

using namespace std;

void add_people_info(contacts::PeopleInfo* people_info)
{
  cout <<"-----------------" << endl;
  cout << "请输入姓名: " ;
  string name;
  getline(cin, name);
  people_info->set_name(name);
  cout << "请输入年龄: " ;
  int age = 0;
  cin >> age;
  people_info->set_age(age);
  cin.ignore(256, '\n');
  for(int i = 0; ;++i)
  {
    cout << "请输入电话: " << endl;
    string number;
    getline(cin, number);
    if(number.empty()) break;
    contacts::PeopleInfo_Phone* phone = people_info->add_phone();
    phone->set_number(number);
  }
  cout << "添加联系人成功" << endl;
}

int main(int argc, char** argv)
{
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  if(2 != argc) {cout << "Usage:  " << argv[0] << " 失败" << "\t\n"; return -1;}
  contacts::Contacts contacts;
  fstream input(argv[1], ios::in|ios::binary);
  if(input.is_open() == false) {cout << "打开 " << argv[1] << "失败"; return -2;}
  if(!contacts.ParseFromIstream(&input)) {cout << " 反序列化失败" << endl; return -3;}
  
  add_people_info(contacts.add_contacts());


  fstream output(argv[1], ios::out|ios::trunc|ios::binary);
  if(!contacts.SerializeToOstream(&output)) {cout << "反序列失败" << endl; return -4;}

  input.close();
  output.close();
  return 0;
}

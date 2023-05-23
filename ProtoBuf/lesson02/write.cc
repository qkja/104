#include <iostream>
#include <fstream>

#include "contacts.pb.h"
using namespace std;

void AddPeopleInfo(contacts2::PeopleInfo *people_info_ptr)
{
  cout << "-------------新增联系人-------------" << endl;
  cout << "请输入联系人姓名: ";
  string name;
  getline(cin, name);
  people_info_ptr->set_name(name);
  cout << "请输入联系人年龄: ";
  int age;
  cin >> age;
  people_info_ptr->set_age(age);

  // 直到遇到\n,就停止清除,\n也很会
  // 或者清楚了 256,停止,或者清楚不到256,停止
  cin.ignore(256, '\n');
  for (int i = 1;; i++)
  {
    cout << "请输入联系人电话" << i << "(只输入回车完成电话新增): ";
    string number;
    getline(cin, number);
    if (number.empty())
    {
      break;
    }

    contacts2::PeopleInfo_Phone *phone = people_info_ptr->add_phone();
    phone->set_number(number);
  }
  cout << "-----------添加联系人成功-----------" << endl;
}

int main()
{
  contacts2::Contacts contacts;

  fstream input("contacts.bin", ios::in | ios::binary);

  if (!input.is_open())
    cout << "Contacts.bin not find, create new file !" << endl;
  else if (!contacts.ParseFromIstream(&input))
  {
    cerr << "parse error" << endl;
    input.close();
    return -1;
  }
  AddPeopleInfo(contacts.add_contacts());

  fstream output("contacts.bin", ios::out | ios::trunc | ios::binary);
  if (!contacts.SerializeToOstream(&output))
  {
    cerr << "Failed to write contacts." << endl;
    input.close();
    output.close();
    return -1;
  }
  input.close();
  output.close();

  return 0;
}
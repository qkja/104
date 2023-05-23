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

    cout << "请输入电话类型(1.移动 2. 固话): ";
    int type = 0;
    cin >> type;
    cin.ignore(256, '\n');
    switch (type)
    {
    case 1:
      phone->set_type(contacts2::PeopleInfo_Phone_PhoneType_MP);
      break;
    case 2:
      phone->set_type(contacts2::PeopleInfo_Phone_PhoneType_TEL);
      break;
    default:
      cout << "选择出现错误" << endl;

      break;
    }
  }
  contacts2::Address addr;
  cout << "请输入地址内容 家庭: ";
  string home_addr;
  getline(cin, home_addr);
  cout << "请输入地址内容 工作: ";

  string unit_addr;
  getline(cin, unit_addr);
  addr.set_home_address(home_addr);
  addr.set_unit_address(unit_addr);

  people_info_ptr->mutable_data()->PackFrom(addr);

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
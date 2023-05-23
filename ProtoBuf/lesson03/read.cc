#include <iostream>
#include <fstream>

#include "contacts.pb.h"
using namespace std;
void PrintContacts(contacts2::Contacts &con)
{
  for (size_t i = 0; i < con.contacts_size(); i++)
  {

    // 拿到元素
    cout << "第 " << i + 1 << " 个联系人" << endl;

    const contacts2::PeopleInfo &people = con.contacts(i);
    cout << "姓名: " << people.name() << endl;
    cout << "年龄: " << people.age() << endl;
    for (size_t j = 0; j < people.phone_size(); j++)
    {
      const contacts2::PeopleInfo_Phone &phone = people.phone(j);
      cout << "电话 " << j + 1 << " " << phone.number();
      cout << " (" << phone.PhoneType_Name(phone.type()) << ")";
      cout << endl;
    }

    // 打印地址信息
    if (people.has_data() && people.data().Is<contacts2::Address>())
    {
      contacts2::Address addr;
      people.data().UnpackTo(&addr);
      if (!addr.home_address().empty())
      {
        cout << "家庭地址: " << addr.home_address() << endl;
      }
      if (!addr.unit_address().empty())
      {
        cout << "家庭地址: " << addr.unit_address() << endl;
      }
    }
  }
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

  // 此事可以反序列化
  PrintContacts(contacts);
  input.close();

  return 0;
}

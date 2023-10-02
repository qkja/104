/**
* User: Qkj
* Description: 读取通讯录 
* Date: 2023-09-19
* Time: 19:51
*/

#include <iostream>
#include <string>
#include "contacts.pb.h"
#include <fstream>
#include <errno.h>

using namespace std;
void PrintfContacts(const contacts::Contacts& contacts)
{
  for(int i = 0; i < contacts.contacts_size(); i++)
  {
    const contacts::PeopleInfo& people_info = contacts.contacts(i);
    cout << "姓名: " << people_info.name() << endl;
    cout << "年龄: " << people_info.age() << endl;
    for(int j = 0; j < people_info.phone_size(); j++)
    {
      const contacts::PeopleInfo_Phone& phone = people_info.phone(j);
      cout << phone.number() << endl;
    }
  }
}



int main(int argc, char* argv[])
{
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  if(2 != argc) 
  {
    cout  << "--------------" << endl;
    return -1;
  }



using namespace contacts;
// 以二进制方式读取 contacts
Contacts contacts;
fstream input(argv[1], ios::in | ios::binary);
if (!contacts.ParseFromIstream(&input)) {
cerr << "Failed to parse contacts." << endl;
input.close();
return -1;
}
// 打印 contacts
PrintfContacts(contacts);
input.close();
google::protobuf::ShutdownProtobufLibrary();
return 0;

  // 以二进制 方式读取 contacts
  //contacts::Contacts contacts;
  //cout  << "1--------------" << endl;
  //
  //fstream input(argv[1], ios::in | ios::binary);
  //
  //cout  << "2--------------" << endl;
  //if (!contacts.ParseFromIstream(&input)) {
  // input.close();
  // cout << strerror(errno);
  // return -1;
  //}

  //cout  << "3--------------" << endl;
  // // 打印 contacts
  //PrintfContacts(contacts);
  //input.close();
  //google::protobuf::ShutdownProtobufLibrary();
  //return 0;
}


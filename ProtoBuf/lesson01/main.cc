/**
 * User: Qkj
 * Description: 
 * Date: 2023-05-22
 * Time: 05:43
 */
#include <iostream>
#include <string>
#include "contacts.pb.h"

int main()
{
  std::string str;
  {
  // 注意,我们这里每一个proto 存在一个类
  
  contacts::PeopleInfo people;
  people.set_name("张珊");
  people.set_age(20);

  //序列化
  if(!people.SerializeToString(&str))
  {
    std::cerr << "序列化失败" << std::endl;
    return -1;
  }
  // 这里应该是乱码
  std::cerr << "序列化成功: " << str  <<std::endl;

  }
  // 反序列化
  {
  contacts::PeopleInfo people2;
  if(!people2.ParseFromString(str))
  {
    std::cerr << "反序列化失败" << std::endl;
    return -1;
  }

  std::cout << "反序列化成功" << std::endl;
  std::cout << "name: " << people2.name()  
    << " age: "<< people2.age() << std::endl;
  }
  return 0;
}

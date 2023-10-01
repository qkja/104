// 类
// struct A
// {
// };
//#include <iostream>
//#include <string>
//using namespace std;

// int main()
// {
//   char arr[10] = { 'a','b', '\0', 'c'};
//   string str = "hel";
//   str += arr;
//   cout << str << endl;
//   // str += '\0';
//   // str += "hhe";
//   cout << str.size() << std::endl;
//   return 0;
// }

// 注意this指针
#include <string>
#include <iostream>
class MyClass
{
public:

	static std::string s_str;
};
std::string MyClass::s_str = "hello";
int main()
{
	std::cout << MyClass::s_str << std::endl;
	return 0;
}
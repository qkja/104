#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream ifs;
	ifs.open("test.cpp", std::ifstream::in);
	char ch = '0';

	//我们如何拷贝一份文件
	ofstream ofs("testCopy.cpp");

	while (ifs.eof())
	{
		
		//char ch = ifs.getline();
		ofs << ch;
	}




	//过滤空格和换行
	/*while (ifs >> ch)
	{
		cout << ch;
	}*/
	//while (ifs) // 这里重载 operator bool
	//	//注意这里的用到了继承(隐藏/重定义) 复用了 父类的
	//{
	//	// 一个字符字符的度
	//	char ch = ifs.get();
	//	cout << ch;
	//}
	return 0;
}




// 循环输入 这里是为什么
// 这里C语言是返回值　
// cim 的返回值 也是 cin
// 这里如何变成  bool 的
// 里面 重载了 operator bool
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		cout << str << endl;
//	}
//	return 0;
//}

// 如何结束 scanf cin ctrl +z  scanf 

// oj 是如何 跑到 这里的测试用例应该是一个文件  这里可以重定向,等下我们需要甾Linux中试试

// 里面 重载了 operator bool



//int main()
//{
//	string str;
//	while (cin >> str) // 调用 cin operator>>(istream& cin, string& str)
//		// 后面cin 遇到了() 又碰到了operator bool
//	{
//		cout << str << endl;
//	}
//
//	return 0;
//}
//我们梳理一下

//class Date
//{
//    friend ostream& operator << (ostream& out, const Date& d);
//    friend istream& operator >> (istream& in, Date& d);
//public:
//    Date(int year = 1, int month = 1, int day = 1)
//        :_year(year)
//        , _month(month)
//        , _day(day)
//    {}
//    operator bool()
//    {
//        // 这里是随意写的，假设输入_year为0，则结束
//        if (_year == 0)
//            return false;
//        else
//            return true;
//    }
//    operator int()
//    {
//        return _year + _month + _day;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//istream& operator >> (istream& in, Date& d)
//{
//    in >> d._year >> d._month >> d._day;
//    return in;
//}
//
//ostream& operator << (ostream& out, const Date& d)
//{
//    out << d._year << " " << d._month << " " << d._day;
//    return out;
//}

//int main()
//{
//    Date d1(0, 11, 12);
//    int ret = d1;
//    cout << ret << endl;
//    return 0;
//}

//int main()
//{
//    Date d1(0, 11, 12);
//    Date d2(1, 11, 12);
//    if (d1)
//        cout << "d1._year != 0" << endl;
//    else
//        cout << "d1._year == 0" << endl;
//
//
//    if (d2)
//        cout << "d2._year != 0" << endl;
//    else
//        cout << "d2._year == 0" << endl;
//    return 0;
//}
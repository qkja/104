#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void func()
	{
		cout << "非const成员函数" << endl;
	}
	void Print() const
	{
		Date ret(*this);
		ret.func();
		cout << "const成员函数" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2022, 7, 10);
	d1.Print();
	return 0;
}

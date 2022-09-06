#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

void TestDate1()
{
	Date d1(2002, 10, 14);
	Date d2(2002, 10, 14);
	Date d3(2002, 2, 14);
	if (d1 == d2)
	{
		cout << "==" << endl;
	}
	cout << (d2 != d3) << endl;
	cout << (d1 != d1) << endl;
}

void TestDate2()
{
	Date d1(2022, 5, 19);
	d1 += 19;
	d1.Print();
}

void TestDate3()
{
	Date d1(2022, 5, 20);
	d1 = d1 +(-10000);
	//d1 -= 10000;
	d1.Print();
}

void TestDate4()
{
	Date d1(2022, 5, 20);
	(++d1).Print();
	d1.Print();
}

void TestDate5()
{
	Date d1(2022, 5, 20);
	Date d2(1900, 1, 1);
	int day = d1 - d2;
	cout << day;
}

void TestDate6()
{
	Date d1(2022, 5, 22);
	const Date d2(2022, 5, 22);
	cout << &d1 << endl;
	//cout << &d2 << endl;
}

int main()
{
	//TestDate1();
	//TestDate2();
	//TestDate3();
	//TestDate4();
	//TestDate5();
	TestDate6();
	return 0;
}
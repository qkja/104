//#include "Date.h"
//
//void test6()
//{
//  Date d1(2022,7,7);
//  Date d2 = d1 - 10000;
//  d2.Print();
//  d1.Print();
//  /*d1.Print();
//  d1 += (-10000);
//  d1.Print();
//
//  d1 = d1 - (-10000);
//  d1.Print();
//  d1 = d1 + (-10000);
//  d1.Print();*/
//}
//
//int main()
//{
//  //test6();
//  Date d1(2022,7,7);
//  Date d2 = d1++;
//  d2.Print();
//  d1.Print();
//
//
//  cout << "=========" << endl;
//
//  Date d3 = --d2;
//  d3.Print();
//  d3--.Print();
//  d3.Print();
//  return 0;
//}


/*void test5()
{
  Date d1(2022,7,7);
  d1 -= 10000;
  d1.Print();
  Date d2(d1);
  d1 += 10000;
  d2.Print();
  cout << d2 - d1 << endl;
  cout << d1 - d2 << endl;
  //d1 += 10000;
  
}

int main()
{
  test5();
  return 0;
}
void test4()
{
  Date d1(400,2,13);
  Date d2;
  Date d3;
  d3 = d2 = d1;

  d2.Print();
  d3.Print();
}

int main()
{
  test4();
  return 0;
}

void test3()
{
  Date d1(400,2,30);
  d1.Print();
}

int main()
{
  test3();
  return 0;
}
void test2()
{
  Date d1(1032,11,23);
  Date d2(1032,11,15);
  if(d1 > d2)
  {
    cout << " > " << endl;
  }
}

int main()
{
  test2();
  return 0;
}

void test1()
{
  Date d1(2022,7,6);
  Date d2(2022,7,6);
  if(d1 == d2)
  {
    cout << " == " << endl;
  }

}

int main()
{
  test1();
  return 0;
}
void test1()
{

  Date d1(2022,7,6);
  Date d2(2022,7,6);

  if(d1 == d2)
  {
    cout << "==" << endl;
  }
}

void test2()
{
  Date d1(1000,10,3);
  Date d2(888,21,4);
  if(d1 > d2)
  {
    cout << ">" << endl;
  }
}

void test3()
{
  Date d1(400,2,-10);
  cout << "dddddddddd" << endl;
}

void test4()
{
  Date d1(1400,2,12);
  Date d2(1300,1,10);
  cout << (d1 == d2) << endl;
  cout << (d1 < d2) << endl;
  cout << (d1 <= d2) << endl;
  cout << (d1 > d2) << endl;
  cout << (d1 >= d2) << endl;
  cout << (d1 != d2) << endl;
}

int main()
{
  //test1();
  //test2();
  //test3();
  test4();
  return 0;
}*/

#include <iostream>
using namespace std;
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//Date& Date::operator++()
//	//{
//	//	// 假设我们已经重载了  =  和 +
//	//	*this = *this + 1;
//	//	return *this;
//	//}
//	//Date Date:: operator++(int)
//	//{
//	//	// 假设我们已经重载了  =  和 +
//	//	Date ret(*this);
//	//	*this = *this + 1;
//	//	return ret;
//	//}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//
//    return 0;
//}

//int main()
//{
//    int a = 10;
//    const int* pa = &a;
//    
//    cout << *pa << endl;
//    return 0;
//}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//void Print()
	//{
	//	//this = nullptr;
	//	//*this
	//}
	Date* operator&()
	{
		return this;
	}
	const Date* operator&() const
	{
		return this;
	}
	
	friend std::ostream& operator<<(std::ostream& out, const Date& date);

private:
	int _year;
	int _month;
	int _day;
};

std::ostream& operator<<(std::ostream& out ,const Date& date)
{
	out << date._year << "-" << date._month << "-" << date._day;
	return out;
}

int main()
{
	Date d1(2022, 7, 7);
	cout << d1 << d1; // 很不习惯
	return 0;
}



//int main()
//{
//	/*Date d;
//	Date* pd = &d;
//	Date* const pd2 = &d;*/
//	//d.Print();
//	//cin >> d;
//	//cout << d;
//	return 0;
//}

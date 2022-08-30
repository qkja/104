#include <iostream>
#include <assert.h>
#include <stdio.h>

using std::cout;
using std::endl;
using std::cin;
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
    if(year > 0 
        && month > 0 
        && month < 13
        && day <= isLegitimate(year,month)
        )
    {
      _year = year;
      _month = month;
      _day = day;
    }
    else 
    {
      // 这里应该抛出一个异常 
      // 现在我还不太会
      //assert(NULL);
      cout << "输入不合法" << endl;
    }
  }

  int isLegitimate(const int year,const int month);
  bool isLeap(const int year);  




  //析构函数
  ~Date();
  // 拷贝构造
  Date(const Date& d);

  void Print() const;


	inline bool operator==(const Date& d) const
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

  // 逻辑运算符 重载
  bool operator>(const Date& d) const;
  bool operator>=(const Date& d) const;
  bool operator<(const Date& d) const ;
  bool operator<=(const Date& d) const;
  bool operator!=(const Date& d) const;


  // 算数运算符 重载
  // 这个等号 的重载必须要加上  const  后面我会返回临时变量，具有常性
  Date& operator=(const Date& d);

  Date& operator+=(const int day);
  Date operator+(const int day) const;
  
  int operator-(const Date& d) const;
  Date operator-(const int day) const;
  Date& operator-=(const int day);
  
  // ++  
  //后置   
  Date operator++(int i);
  //前置
  Date& operator++();

  // --
  //后置
  Date operator--(int i);
  //前置
  Date& operator--();
private:
	int _year;
	int _month;
	int _day;
};



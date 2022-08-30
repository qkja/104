#include "Date.h"

int Date::isLegitimate(const int year,const int month)  
{
  
  static int monthDay[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
  assert(month > 0 && month < 13);
  //判断闰年
  if(isLeap(year) && month == 2)
  {
    return 29;
  }
  return  monthDay[month];
  //得到月份判断
  //判断天数
  
}

bool Date::isLeap(int year)
{
  assert(year > 0);
  return (year % 4 == 0 && year %100 != 0)
    || year % 400 == 0;
}

Date::Date(const Date& d)
{
  _year = d._year;
  _month = d._month;
  _day = d._day;
}

Date::~Date()
{
  _year = 0;
  _month = 0;
  _day = 0;
}

void Date::Print() const 
{
  printf("%d-%02d-%02d",_year,_month,_day);
  cout << endl; 
}

bool Date:: operator>(const Date& d) const 
{
  return (_year > d._year)
    ||(_year == d._year && _month > d._month)
    ||(_year == d._year && _month == d._month && _day > d._day);
}

bool Date::operator>=(const Date& d) const 
{
  return *this > d || *this == d;
}

bool Date::operator<(const Date& d) const 
{
  return !(*this >= d);
}

bool Date::operator<=(const Date& d) const 
{
  return !(*this > d);
}

bool Date::operator!=(const Date& d) const 
{
  return !(*this ==  d);
}


Date& Date::operator=(const Date& d) 
{
  if(this != &d)
  {
    _year = d._year;
    _month = d._month;
    _day = d._day;
  }
  return *this;
}
// 重置 + 
Date Date::operator+(const int day) const 
{
  //先判断  day 是否是 小于零
  if(day < 0)
  {
    return (*this)-(-day);
  }
  // 第一步  来个第三方 不要修改原来的
  Date ret(*this);
  ret._day += day;
  while(ret._day > ret.isLegitimate(ret._year,ret._month))
  {
    ret._day -= ret.isLegitimate(ret._year,ret._month);
    
    if(ret._month == 12)
    {
      ret._month = 1;
      ret._year += 1;
    }
    else 
    {
      ret._month += 1;
    }
  }

  return ret;
}


Date& Date::operator+=(const int day)
{
  //判断 是不是 小于 0
  if(day < 0)
  {
    return (*this) = (*this) - (-day);
  }
  return (*this) = (*this) + day;
}

int Date:: operator-(const Date& d) const 
{
  // 给一个 数  来计数
  int count = 0;
  int flag = 1;
  // 不能修改原来的，这里用一个第三方
  Date ret(*this);
  if(ret > d)
  {
    flag = -1;
  }
  while(ret != d)
  {
    ret += flag;
    count++;
  }
  return flag*count;
  
}

Date Date::operator-(const int day) const
{
  // day 的大小 
  if(day < 0)
  {
    return (*this) + (-day);
  }
  Date ret(*this);
  ret._day -= day;

  //开始判断  _day 
  while(ret._day <= 0)
  {
    // 找上一个月的
    if(ret._month == 1)
    {
      ret._month = 12;
      ret._year -= 1;
    }
    else 
    {
      ret._month -= 1;
    }
    int days = ret.isLegitimate(ret._year,ret._month);
    ret._day += days;
  }
  return ret;
} 

Date& Date::operator-=(const int day)
{
  if(day < 0)
  {
    return(*this) = (*this)+(-day);
  }
  return (*this) = (*this) - day;
}
// ++  
// 后置   
Date Date::operator++(int)
{
  Date ret(*this);
  *this += 1;
  return ret;
}

//前置
Date& Date::operator++()
{
  *this += 1;
  return *this;
}

// --
//后置
Date Date:: operator--(int)
{
  Date ret(*this);
  *this -= 1;
  return ret;
}
//前置
Date& Date::operator--()
{
  *this -= 1;
  return *this;
}

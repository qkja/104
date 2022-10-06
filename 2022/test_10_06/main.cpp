#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

// 异常
// 传统的C语言  终止程序 + int x = 0;
//
//double Division(int a, int b)
//{
//	if (b == 0)
//		throw "Division by zero condition";
//	else
//		return (1.0 * a) / b;
//}
//void Probability()
//{
//	int val = rand();
//	if (val < RAND_MAX / 4)
//	{
//		string str("%25概率抛异常-> ");
//		str += to_string(val);
//		throw str; // 抛异常
//	}
//	else
//	{
//		cout << val << endl;
//	}
//}
//void func()
//{
//	try
//	{
//		Probability();
//		//Division(1,0);
//	}
//	// 这里 的引用 是 创建的那个临时对象
//	//catch (const string& s)
//	catch(const exception& s)
//	{
//		++x;
//		s.what();
//		//cout << s << endl;
//	}
//	/*catch (const char* s)
//	{
//		cout << s << endl;
//	}*/
//	/*catch (...)
//	{
//		cout << "未知异常" << endl;
//	}*/
//}返回错误码
//
//int main()
//{
//	srand(time(0));
//	const int N = 1000;
//	for (int i = 0; i < N; i++)
//	{
//		func();
//	}
//	cout << "抛异常次数 : " << x  << endl;
//	cout << "实际概率 : " << (x * 1.0) / N << endl;
//	return 0;
//}
#include <stdlib.h>
#include <Windows.h>

class Exception
{
public:
	Exception(const string& errmsg, int id)
		:_errmsg(errmsg)
		, _id(id)
	{}
	// 虚函数
	virtual string what() const
	{
		return _errmsg;
	}
	// 这里 
	int getId()
	{
		return _id;
	}
protected:
	string _errmsg;
	int _id; // 错误码
};
// 数据库异常
class SqlException : public Exception
{
public:
	SqlException(const string& errmsg, int id, const string& sql)
		:Exception(errmsg, id) // 帮助父类构造
		, _sql(sql) // sql语句
	{}
	virtual string what() const
	{
		string str = "SqlException:";
		str += _errmsg;
		str += "->";
		str += _sql;
		return str;
	}
private:
	const string _sql;
};

// 缓存异常
class CacheException : public Exception
{
public:
	CacheException(const string& errmsg, int id)
		:Exception(errmsg, id)
	{}
	virtual string what() const
	{
		string str = "CacheException:";
		str += _errmsg;
		return str;
	}
};

// 网络异常
class HttpServerException : public Exception
{
public:
	HttpServerException(const string& errmsg, int id, const string& type)
		:Exception(errmsg, id)
		, _type(type)
	{}
	virtual string what() const
	{
		string str = "HttpServerException:";
		str += _type;
		str += ":";
		str += _errmsg;
		return str;
	}
private:
	const string _type;
};

void SQLMgr()
{
	srand(time(0));
	if (rand() % 7 == 0)
	{
		throw SqlException("权限不足", 100, "select * from name = '张三'");
	}
	//cout << "数据库 正确" << endl;
	//throw "xxxxxx";
}
void CacheMgr()
{
	srand(time(0));
	if (rand() % 5 == 0)
	{
		throw CacheException("权限不足", 100);
	}
	else if (rand() % 6 == 0)
	{
		throw CacheException("数据不存在", 101);
	}
	SQLMgr();
}
void HttpServer()
{
	// ...
	srand(time(0));
	// 0 1 2  66%的概率
	if (rand() % 3 == 0)
	{
		throw HttpServerException("请求资源不存在", 100, "get");
	}
	 
	else if (rand() % 4 == 0)
	{
		throw HttpServerException("权限不足", 101, "post");
	}

	// 这个   网络请求正确
	CacheMgr();
}
int main()
{
	while (1)
	{
		//this_thread::sleep_for(chrono::seconds(1));
		::Sleep(1000);
		try {
			HttpServer();
		}

		catch (const Exception& e) // 这里捕获父类对象就可以
		{
			// 多态
			cout << e.what() << endl;
		}
		catch (...)
		{
			cout << "Unkown Exception" << endl;
		}
	}
	return 0;
}
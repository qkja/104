#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
namespace bit
{
	class string
	{
	public:
		string();
		string(const string& str);
		string(const char* str);
		~string();
		char* string_char();

		string& operator=(const string& s);
		void resize(int n, char ch);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

	void string::resize(int n, char ch)
	{
		if (n > _cap)
		{

		}
		else
		{

		}
	}







	char* string::string_char()
	{
		return _str;
	}

	string::string()
		:_size(0)
		,_capacity(0)
	{
		_str = new char[1];
		_str[0] = '\0';
	}
	string& string::operator=(const string& s)
	{
		if (this == &s)
		{
			return *this;
		}
		if (_str)
		{
			delete[] _str;
		}
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
		return *this;
	}

	string::string(const char* str)
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}

	string::string(const string& str)
		:_str(new char[strlen(str._str) + 1])
	{
		strcpy(_str, str._str);
	}

	string::~string()
	{
		if (_str)
		{
			delete[] _str;
		}
	}
}

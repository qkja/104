#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

//int main()
//{
//	//int* p1 = new int(1);
//	int* p1 = new int[10] {1, 2, 3, 4};
//	for (int i = 0; i < 10; i++)
//	{
//		std::cout << p1[i] << std::endl;
//	}
//	delete[] p1;
//	return 0;
//}

//int main()
//{
//	auto il1 = { 10, 20, 30 };
//	auto il2 = { 10, 20, 30,40,50,60 };
//	std::cout << sizeof(il1) << std::endl;
//	std::cout << sizeof(il2) << std::endl;
//	return 0;
//}
//int main()
//{
//	int b = 0;
//	int&& a = b;
//	cout << &a << endl;
//	return 0;
//}
//int main()
//{
//	string s1("hello");
//	string s2 = move(s1);
//	return 0;
//}

namespace bit
{
    class string
    {
    public:

        string(const char* str = "")
            :_size(strlen(str))
            , _capacity(_size)
        {
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }
        // 拷贝构造
        string(const string& s)
            :_str(nullptr)
        {
            cout << "string(const string& s) -- 深拷贝" << endl;
            string tmp(s._str);
            swap(tmp);
        }
        // 移动构造
        //string(string&& s)
        //    :_str(nullptr)
        //    , _size(0)
        //    , _capacity(0)
        //{
        //    cout << "string(string&& s) -- 移动语义" << endl;
        //    swap(s);
        //}
        ~string()
        {
            delete[] _str;
            cout << "~string()" << endl;

            _str = nullptr;
        }

        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                char* tmp = new char[n + 1];
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
                _capacity = n;
            }
        }
        void push_back(char ch)
        {
            if (_size >= _capacity)
            {
                size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
                reserve(newcapacity);
            }
            _str[_size] = ch;
            ++_size;
            _str[_size] = '\0';
        }
        string& operator+=(char ch)
        {
            push_back(ch);
            return *this;
        }
    private:
        void swap(string& s)
        {
            ::swap(_str, s._str);
            ::swap(_size, s._size);
            ::swap(_capacity, s._capacity);
        }
    private:
        char* _str;
        size_t _size;
        size_t _capacity; // 不包含最后做标识的\0
    };

    //这个实现是不对的
    bit::string to_string(int val)
    {
        bit::string str;
        while (val > 0)
        {
            int x = val % 10;
            val /= 10;
            str += ('0' + x);
        }
        return str;
    }
}
int main()
{
    bit::string str = bit::to_string(123);
    return 0;
}
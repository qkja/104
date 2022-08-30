#define _CRT_SECURE_NO_WARNINGS 1


//template<class T>
//void Swap(T& left, T& right);


//string& insert(size_t pos, const char* str)
//{
//	assert(pos <= _size);
//	size_t len = strlen(str);
//	if (_size + len > _capacity)
//	{
//		reserve(_size + len);
//	}
//
//	// 第一步  移动相应的宽度
//
//	int end = strlen（_str） + 1;
//	
//	while (end > pos)
//	{
//        end--;
//		_str[end + len] = _str[end];
//		//end--;
//	}
//	strncp(_str+end,str,len)
//	return *this;

template<class T>
class Student
{
public:
	Student();
	~Student();
private:
	T* elem;
	szie_t _size;
	szie_t _cap;
};

template<class T>

Student<T>::Student()
{
	_cap = 4;
	_elem = new T[_cap];
	_size = 10;
}

template<class T>
Student<T>::~Student()
{
	if (elem)
	{
		delete[] elem;
		_size = 0;
		_cap = 0;
	}
}

//int main()
//{
//	Student<char> student;
//	return 0;
//}

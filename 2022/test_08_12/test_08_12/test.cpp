#define _CRT_SECURE_NO_WARNINGS 1


//int main()
//{
//	vector<int> v(10,1);
//	vector<int>::iterator it = v.begin();
//	v.erase(it);
//	cout << v.capacity() << endl;
//	*it;
//	return 0;
//}

//int main()
//{
//	vector<char> v2(10, 'x');
//	for (auto e : v2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	// 排除法
//	vector<int> v1(10, 2);
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	vector<char> v2(10, 'x');
//	for (auto e : v2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}
//#include <iostream>
//#include <vector>
//
//using namespace std;
//int main()
//{
//	// 排除法
//	vector<vector<int>> vv;
//	vector<int> v1(10, 1);
//	vector<int> v2(10, 2);
//	vector<int> v3(10, 3);
//	vector<int> v4(10, 4);
//	vector<int> v5(10, 5);
//
//	vv.push_back(v1);
//	vv.push_back(v2);
//	vv.push_back(v3);
//	vv.push_back(v4);
//	vv.push_back(v5);
//	for (vector<int>& val : vv)
//	{
//		for (int e : val)
//		{
//			cout << e << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}


//void reserve(size_t n = 0)
//{
//	size_t oldsize = size();
//
//	if (n > capacity())
//	{
//		// 开一块空间
//		T* tmp = new T[n];
//		// 判断  原本空间有没有 数据
//		if (_start)
//		{
//			// 这里直接 赋值  对于 自定义类型 会自动深拷贝
//			for (int i = 0; i<size(); i++)
//			{
//				tmp[i] = _start[i];
//			}
//			//memcpy(tmp, _start, size()*sizeof(T));
//			delete[] _start;
//		}
//
//		_start = tmp;
//		_finish = tmp + oldsize;
//		_endOfStoage = tmp + n;
//	}
//
//}

int func()
{
	int a = 10;
	return a;
}
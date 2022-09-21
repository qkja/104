#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
//using namespace std;
//bool sortByLength(const vector<string>& v)
//{
//	if (v.empty())
//		return false;
//	for (int i = 1; i < v.size(); i++)
//	{
//		if (v[i].size() < v[i - 1].size())
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//bool lexSort(const vector<string>& v)
//{
//	if (v.empty())
//		return false;
//	for (int i = 1; i < v.size(); i++)
//	{
//		if (v[i] < v[i - 1])
//			return false;
//	}
//	return true;
//
//}
//int main()
//{
//	int n;
//	cin >> n;
//	vector<string> v;
//	string str;
//	/*string str1 = "aaa";
//	string str2 = "z";*/
//	/*v.push_back(str1);
//	v.push_back(str2);*/
//	getchar();
//	while (n--)
//	{
//		getline(std::cin, str);
//		v.push_back(str);
//		str.clear();
//	}
//
//	bool len = sortByLength(v);
//	bool lex = lexSort(v);
//
//	if (len == true && lex == true)
//	{
//		cout << "both" << endl;
//	}
//	else if (len == true && lex != true)
//	{
//		cout << "lengths" << endl;
//	}
//	else if (len != true && lex == true)
//	{
//		cout << "lexicographically" << endl;
//	}
//	else
//	{
//		cout << "none" << endl;
//	}
//
//	return 0;
//}




//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int LCM(int min, int max)
//{
//	for (int i = min; i < max * min; i++)
//	{
//		if (i % min == 0 && i % max == 0)
//		{
//			return i;
//		}
//	}
//	return max * min;
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	cin >> m;
//	cin >> n;
//	int min = m > n ? n : m;
//	int max = m < n ? n : m;
//	cout << LCM(min, max) << endl;
//	return 0;
//}
//int main()
//{
//	string str1 = "car";
//	string str2 = "cat";
//	cout << (str1 < str2) << endl;
//	str1.clear();
//	return 0;
//}



//bool sortByLength(const vector<string>& v)
//{
//	if (v.empty())
//		return true;
//	for (int i = 1; i < v.size(); i++)
//	{
//		if (v[i].size() < v[i - 1].size())
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//bool lexSort(const vector<string>& v)
//{
//	if (v.empty())
//		return true;
//	for (int i = 1; i < v.size(); i++)
//	{
//		if (v[i] < v[i - 1])
//			return false;
//	}
//	return true;
//
//}

//int main()
//{
//	vector<string> v;
//	string str1 = "car";
//	string str2 = "carriage";
//	cout << lexSort(v) << endl;
//	return 0;
//}

//int main()
//{
//	int n;
//	cin >> n;
//	vector<string> v;
//	string str;
//	while (n--)
//	{
//		getline(std::cin, str);
//		v.push_back(str);
//	}
//
//	bool len = sortByLength(v);
//	bool lex = lexSort(v);
//	if (len && lex)
//	{
//		cout << "both" << endl;
//	}
//	else if (len)
//	{
//		cout << "lengths" << endl;
//
//	}
//	else if (lex)
//	{
//		cout << "lexicographically" << endl;
//
//	}
//	else
//	{
//		cout << "none" << endl;
//
//	}
//	
//	return 0;
//}




//class A
//{
//public:
//	static int _n;
//	A()
//	{
//		_n++;
//	}
//	~A()
//	{
//		_n--;
//	}
//	static int get()
//	{
//		return _n;
//	}
//};
//int A::_n = 0;
//int main()
//{
//	A* a = new A;
//	delete a;
//	cout << A::get() << endl;
//	return 0;
//}
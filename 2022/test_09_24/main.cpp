#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
bool isPrimeNumber(int n)
{
	if (n <= 1)
		return false;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
void primeNumber(vector<int>& v, int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (isPrimeNumber(i))
		{
			v.push_back(i);
		}
	}
}
int main()
{
	int n = 0;
	cin >> n;
	vector<int> v;
	primeNumber(v, n);
	int min = n;
	int flag = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int a = n - v[i];
		if (isPrimeNumber(a))
		{
			if (abs(a - v[i]) < min)
			{
				min = abs(a - v[i]);
				flag = v[i];
			}
		}
	}
	if (flag > n - flag)
	{
		cout << n - flag << endl;
		cout << flag << endl;
	}
	else
	{
		cout << flag << endl;
		cout << n - flag << endl;
	}
	return 0;
}

//class BinInsert {
//public:
//    int binInsert(int n, int m, int j, int i) {
//        // write code here
//        m = m << j;
//        return n | m;
//    }
//};

//class MyClass
//{
//public:
//	~MyClass()
//	{
//		delete this;
//		this = nullptr;
//	}
//private:
//
//};
//
//
//int main()
//{
//	MyClass m;
//	return 0;
//}












//void binary(vector<int>& v, int n)
//{
//	while (n)
//	{
//		v.push_back(n % 2);
//		n /= 2;
//	}
//}
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> v1;
//
//	//　求二进制
//	binary(v1, n);
//	vector<int> v2;
//
//	int count = 0;
//	for (int i = 0; i < v1.size(); i++)
//	{
//		if (v1[i] == 1)
//		{
//			v2.push_back(1);
//		}
//		else
//		{
//			if (!v2.empty())
//			{
//				int size = v2.size();
//				if (size > count)
//				{
//					count = size;
//				}
//				v2.clear();
//			}
//		}
//	}
//	if (!v2.empty())
//	{
//		int size = v2.size();
//		if (size > count)
//		{
//			count = size;
//		}
//		v2.clear();
//	}
//	cout << count << endl;
//	return 0;
//}

//class LCA {
//public:
//    int getLCA(int a, int b) {
//        // write code here
//        a = a - 1;
//        b = b - 1;
//        int min = a > b ? b : a;
//        int max = a > b ? a : b;
//        while (max != min)
//        {
//            if ((max - 1) / 2 == min)
//            {
//                return min + 1;
//            }
//            else
//            {
//                max = (max - 1) / 2;
//                if (max < min)
//                {
//                    std::swap(min, max);
//                }
//            }
//            /*if ((max - 2) / 2 == min)
//                return min;
//            else
//            {
//                max = (max - 2) / 2;
//            }*/
//
//        }
//        return max+1;
//    }
//};
//int main()
//{
//    int ret = LCA().getLCA(9,8);
//    std::cout << ret << std::endl;
//    return 0;
//}

//class MyClass
//{
//public:
//	void foo();
//private:
//
//};
//
//void MyClass::foo()
//{
//
//		delete this;
//
//}
//
//
//int main()
//{
//	MyClass* m = new MyClass;
//	m->foo();
//	int a = 10;
//
//	return 0;
//}
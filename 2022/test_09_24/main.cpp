#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void binary(vector<int>& v, int n)
{
	while (n)
	{
		v.push_back(n % 2);
		n /= 2;
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int> v1;

	//　求二进制
	binary(v1, n);
	vector<int> v2;

	int count = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i] == 1)
		{
			v2.push_back(1);
		}
		else
		{
			if (!v2.empty())
			{
				int size = v2.size();
				if (size > count)
				{
					count = size;
				}
				v2.clear();
			}
		}
	}
	if (!v2.empty())
	{
		int size = v2.size();
		if (size > count)
		{
			count = size;
		}
		v2.clear();
	}
	cout << count << endl;
	return 0;
}

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
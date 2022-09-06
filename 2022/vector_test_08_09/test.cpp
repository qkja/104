#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	vector<int> v(10,1);
//	vector<int>::iterator pos = v.begin();
//	printf("pos : %p\n", pos);
//
//	int i = 0;
//	while (i < 100)
//	{
//		if (i == 1)
//		{
//			printf("pos : %p\n", pos);
//			cout << "²âÊÔ" << endl;
//		}
//		v.insert(pos, 2);
//		i++;
//	}
//	return 0;
//}
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
		{
			it++;
		}
	}
	for (int val : v)
	{
		cout << val << " ";
 	}

	return 0;
}

//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	vector<int>::iterator it = v.begin();
//
//	it = v.insert(it, 10);
//
//	return 0;
//}
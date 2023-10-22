#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;
//
//int main() {
//	int n = 0;
//	while (cin >> n) {
//		vector<int> v(2 * n - 1, 0);
//		vector<int> v_cpoy(2 * n - 1, 0);
//		v[n - 1] = 1;
//
//		for (int i = 1; i < n; i++) {
//			// 计算一下
//			for (int j = 0; j < 2 * n - 1; j++) {
//				v_cpoy[j] = v[j];
//				if (j - 1 >= 0)
//					v_cpoy[j] += v[j - 1];
//				if (j + 1 < 2 * n - 1)
//					v_cpoy[j] += v[j + 1];
//			}
//			v = v_cpoy;
//		}
//		// 计算v
//		int i = 0;
//		for (; i< 2 * n - 1; i++) {
//			if (v[i] % 2 == 0)
//			{
//				std::cout << i + 1 << std::endl;
//				break;
//			}
//		}
//		if (i == 2 * n - 1)
//			std::cout << -1 << std::endl;
//	}
////}
//// 64 位输出请用 printf("%lld")
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//	int n = 0;
//	while (cin >> n) {
//		vector<int> v(2 * n - 1, 0);
//		vector<int> v_cpoy(2 * n - 1, 0);
//
//		v[n - 1] = 1;
//
//		for (int i = 1; i < n; i++) {
//			// 计算一下
//			if (i % 2 == 1) {
//				for (int j = 0; j < 2 * n - 1; j++) {
//					v_cpoy[j] = v[j];
//					if (j - 1 >= 0)
//						v_cpoy[j] += v[j - 1];
//					if (j + 1 < 2 * n - 1)
//						v_cpoy[j] += v[j + 1];
//				}
//			}
//			else {
//				for (int j = 0; j < 2 * n - 1; j++) {
//					v[j] = v_cpoy[j];
//					if (j - 1 >= 0)
//						v[j] += v_cpoy[j - 1];
//					if (j + 1 < 2 * n - 1)
//						v[j] += v_cpoy[j + 1];
//				}
//			}
//		}
//		int i = 0;
//		if (n % 2 == 1) {
//			for (; i < 2 * n - 1; i++) {
//				if (v[i] % 2 == 0) {
//					std::cout << i + 1 << std::endl;
//					break;
//				}
//			}
//		}
//		else {
//			for (; i < 2 * n - 1; i++) {
//				if (v_cpoy[i] % 2 == 0) {
//					std::cout << i + 1 << std::endl;
//					break;
//				}
//			}
//		}
//		// 计算v
//
//
//		if (i == 2 * n - 1)
//			std::cout << -1 << std::endl;
//	}
//}
//// 64 位输出请用 printf("%lld")
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		if (n<3)    { cout << -1 << endl; }
//		else
//		{
//			if (n % 2 == 1)    { cout << 2 << endl; }
//			else if (n % 4 == 0)    { cout << 3 << endl; }
//			else    { cout << 4 << endl; }
//		}
//	}
//	return 0;
//}

#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	getline(std::cin, str);
	char ch = 0;
	std::cin >> ch;
	if (ch >= 'A' && ch <= 'Z')
		ch = ch + 'a' - 'A';
	int count = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 'a' - 'A';
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ch)
			count++;
	}
	std::cout << count << std::endl;
	return 0;
}
// 64 位输出请用 printf("%lld")
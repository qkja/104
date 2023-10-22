#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <iterator>
//#include <string>
//#include <unordered_map>
//using namespace std;
//
//int main() {
//	string str;
//	getline(cin, str);
//	unordered_map<char, int> m;
//	for (auto e : str)
//		m[e]++;
//	int i = 0;
//	for (i = 0; i < str.size(); i++) {
//		if (m[str[i]] == 1) {
//			cout << str[i] << endl;
//			break;
//		}
//	}
//	if (i == str.size())
//		cout << -1 << endl;
//
//	return  0;
//}
//// 64 位输出请用 printf("%lld")

#include <iostream>
#include <vector>
using namespace std;
int func(int x, int y) {
	if (x > y)
		swap(x, y);
	for (int i = x; i >= 1; i--) {
		if (y % i == 0 && x % i == 0)
			return i;
	}
	return 0;
}
int main() {
	int n = 0;
	int a = 0;
	while (cin >> n >> a) {
		vector<int> b(n);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < n; i++) {
			if (a >= b[i]) {
				a += b[i];
			}
			else {
				a += func(a, b[i]);
			}
		}
		cout << a << endl;
	}

	return 0;
}
// 64 位输出请用 printf("%lld")
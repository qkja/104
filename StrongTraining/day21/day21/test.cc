#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <type_traits>
//#include <vector>
//using namespace std;
//void func(vector<int>& v, int k) {
//	vector<int> v_help(v.size());
//
//	while (k--) {
//		int left = v.size() / 2 - 1;
//		int right = v.size() - 1;
//		int index = v.size() - 1;
//		while (left >= 0) {
//			v_help[index--] = v[right--];
//			v_help[index--] = v[left--];
//		}
//		v.swap(v_help);
//	}
//}
//int main() {
//	int t = 0;
//	cin >> t;
//	vector<vector<int>> v;
//	vector<int> k_v;
//	for (int i = 0; i < t; i++) {
//		int n = 0;
//		int k = 0;
//		cin >> n >> k;
//		vector<int> n_v;
//		for (int j = 0; j < 2 * n; j++) {
//			int val = 0;
//			cin >> val;
//			n_v.push_back(val);
//		}
//		k_v.push_back(k);
//		v.push_back(n_v);
//	}
//	for (int i = 0; i < t; i++) {
//		func(v[i], k_v[i]);
//		for (auto e : v[i]) {
//			cout << e << " ";
//		}
//		cout << endl;
//	}
//	return 0;;
//}
//// 64 位输出请用 printf("%lld")

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}
	string op;
	cin >> op;
	int index = 0;
	int left = 0;
	int right = 0;
	if (n <= 4) {
		left = 0;
		right = n - 1;
		for (int i = 0; i < op.size(); i++) {
			if (op[i] == 'U') {
				index--;
				if (index == -1)
					index = n - 1;
			}
			else {
				index++;
				if (index == n)
					index = 0;
			}
		}
	}
	else {
		left = 0;
		right = left + 3;
		for (int i = 0; i < op.size(); i++) {
			if (op[i] == 'U') {
				index--;
				if (index == -1) {
					index = n - 1;
					right = n - 1;
					left = right - 3;
				}
				else {
					if (index < left) {
						left--;
						right--;
					}

				}
			}
			else {
				index++;
				if (index == n) {
					left = 0;
					right = left + 3;
					index = 0;
				}
				else {
					if (index > right) {
						left++;
						right++;
					}

				}
			}
		}



	}
	for (; left <= right; left++)
		cout << v[left] << " ";
	cout << endl;
	cout << v[index] << endl;
	return 0;
}
// 64 位输出请用 printf("%lld")
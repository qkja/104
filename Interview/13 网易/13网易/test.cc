#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//int main() {
//	int n = 0;
//	cin >> n;
//	string s1; // 队伍1
//	string s2; // 队伍2
//	cin >> s1 >> s2;
//	unordered_map<string, int> m1; // 记录1的队伍
//	unordered_map<string, int> m2; // 记录2的队伍
//	int sum1 = 0;
//	int sum2 = 0;
//	string mvp;
//	int max_score = 0;
//	for (int i = 0; i < n; i++) {
//		string name;
//		string team;
//		int score = 0;
//		cin >> name >> team >> score;
//		if (team == s1) {
//			sum1 += score;
//			m1[name] += score;
//			if (m1[name] > max_score) {
//				mvp = name;
//				max_score = m1[name];
//			}
//		}
//		else {
//			sum2 += score;
//			m2[name] += score;
//			if (m2[name] > max_score) {
//				mvp = name;
//				max_score = m2[name];
//			}
//		}
//
//	}
//	if (sum1 > sum2) {
//		cout << s1 << endl;
//	}
//	else if (sum1 < sum2) {
//		cout << s2 << endl;
//
//	}
//	else {
//		cout << "ended in a draw" << endl;
//	}
//	cout << mvp << endl;
//	return 0;
//}
// 64 位输出请用 printf("%lld")

//#include <iostream>
//#include <string>
//#include <vector>
//#include <unordered_map>
//using namespace std;
#include <stdio.h>
//void func()
//{
//	printf("hell");
//}
//int main()
//{
//	func();
//	func(2);
//	return 0;
//}
//int main() 
//{
//	int n = 0; // 玩家个数
//	int m = 0; // m个图形
//	int q = 0; // q个询问
//	cin >> n >> m >> q;
//	unordered_map<int, pair<pair<int, int>, pair<int, int>>> m_m;
//	// 一个玩家的 x, y位置 和 b 是否存在buff,以及 c阵营
//
//	for (int i = 0; i < n;++i)
//	{
//		int x = 0;
//		int y = 0;
//		int b = 0;
//		int c = 0;
//		cin >> x >> y >> b >> c;
//		m_m[i + 1].first.first = x;
//		m_m[i + 1].first.second = y;
//		m_m[i + 1].second.first = b;
//		m_m[i + 1].second.second = c;
//	}
//	vector<vector<pair<int, int>>> borad1; // 矩形
//	vector<vector<pair<pair<int,int>, int>>> borad2; // 源性
//
//	borad1.resize(m);
//	borad2.resize(m);
//	int indexi = 0;
//	int indexj = 0;
//	for (int i = 0; i < m; ++i)
//	{
//		int type = 0;
//		cin >> type;
//		if (type)
//		{
//			// 这里是矩形
//			int dx = 0;
//			int dy = 0;
//			for (int j = 0; j < 4; j++)
//			{
//				cin >> dx >> dy;
//				borad1[indexi].push_back({ dx, dy });
//			}
//			indexi++;
//		}
//		else
//		{
//			// 这里是软性
//			int cx = 0;
//			int cy = 0;
//			int cr = 0;
//			cin >> cx >> cy >> cr;
//			borad2[indexj].push_back({ { cx, cy }, cr });
//		}
//	}
//
//
//	for (int i = 0; i < q; i++)
//	{
//		int q1 = 0;
//		int q2 = 0;
//		cin >> q1 >> q2;
//		//unordered_map<int, pair<pair<int, int>, pair<int, int>>> m_m;
//		// 一个玩家的 x, y位置 和 b 是否存在buff,以及 c阵营
//
//		// q1 和 q2 是一个阵营de
//		if (m_m[q1].second.second == m_m[q2].second.second)
//		{
//			if (m_m[q2].second.first == 1)
//			{
//				cout << 0 << endl;
//			}
//			else
//			{
//				cout << 1 << endl;
//			}
//		}
//		else
//		{
//			// 不是
//			if (m_m[q2].second.first == 1)
//			{
//				cout << 0 << endl;
//			}
//			else
//			{
//				// 没有buff,观察我们q1和q2是不是在一个草品
//				cout << 0 << endl;
//
//			}
//		}
//		
//	}
//	return 0;  
//
//}
// 64 位输出请用 printf("%lld")
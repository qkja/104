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
//	string s1; // ����1
//	string s2; // ����2
//	cin >> s1 >> s2;
//	unordered_map<string, int> m1; // ��¼1�Ķ���
//	unordered_map<string, int> m2; // ��¼2�Ķ���
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
// 64 λ������� printf("%lld")

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
//	int n = 0; // ��Ҹ���
//	int m = 0; // m��ͼ��
//	int q = 0; // q��ѯ��
//	cin >> n >> m >> q;
//	unordered_map<int, pair<pair<int, int>, pair<int, int>>> m_m;
//	// һ����ҵ� x, yλ�� �� b �Ƿ����buff,�Լ� c��Ӫ
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
//	vector<vector<pair<int, int>>> borad1; // ����
//	vector<vector<pair<pair<int,int>, int>>> borad2; // Դ��
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
//			// �����Ǿ���
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
//			// ����������
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
//		// һ����ҵ� x, yλ�� �� b �Ƿ����buff,�Լ� c��Ӫ
//
//		// q1 �� q2 ��һ����Ӫde
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
//			// ����
//			if (m_m[q2].second.first == 1)
//			{
//				cout << 0 << endl;
//			}
//			else
//			{
//				// û��buff,�۲�����q1��q2�ǲ�����һ����Ʒ
//				cout << 0 << endl;
//
//			}
//		}
//		
//	}
//	return 0;  
//
//}
// 64 λ������� printf("%lld")
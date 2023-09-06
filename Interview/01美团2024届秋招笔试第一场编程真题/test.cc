/**
* User: Qkj
* Description:
* Date: 2023-08-28
* Time: 20:48
*/
//#include <iostream>
//#include <cstdio>
//using namespace std;
//int main()
//{
//	int num = 0;  // ��Ʒ��
//	while (cin >> num)
//	{
//		double total_sum = 0.0;
//		double div_sum = 0.0;
//		bool falg = false;
//		for (int i = 0; i < num; i++)
//		{
//			double x = 0.0;
//			double y = 0.0;
//			cin >> x >> y;
//			if (x <= 0.0 || y <= 0.0 || x < y)
//			{
//				falg = true;
//			}
//			total_sum += x;
//			div_sum += y;
//		}
//		// ������ ���Ǳ�֤�� �ۿۼ۲�С�� ����
//		double x = 0.0;  // ����
//		double y = 0.0;  // �ۿ�
//		cin >> x >> y;
//		if (falg || x <= 0.0 || y <= 0.0 || x < y)
//		{
//			std::cout << "error" << std::endl;
//
//		}
//		else {
//
//			if (total_sum >= x)
//				total_sum -= y;
//
//			if (total_sum <= 0) {
//				std::cout << "error" << std::endl;
//			}
//			else {
//				double total = total_sum < div_sum ? total_sum : div_sum;
//				printf("%.2lf\n", total);
//			}
//		}
//
//
//	}
//	return 0;
//}
// 64 λ������� printf("%lld")


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
	int n = 0;
	while (std:: cin >> n)
	{
		getchar();
		std::string s;
		std::string t;
		std::getline(std::cin, s);
		std::getline(std::cin, t);
		if (s.size() != t.size() && s.size() != n)
			continue;
		std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
		int maxLen = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (s[i - 1] == t[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					if (dp[i][j] > maxLen)
					{
						maxLen = dp[i][j];
						if (maxLen == 2)
						{
							cout << i << j << endl;
						}
					}
				}
			}
		}
		std::cout << maxLen << std::endl;
	}
	return 0;
}
// 64 λ������� printf("%lld")
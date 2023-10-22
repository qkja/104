/**
* User: Qkj
* Description: 
* Date: 2023-06-02
* Time: 16:16
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int w = 0; // 列号
//	int h = 0; // 行号
//
//	cin >> w >> h;
//	// 我们设计棋牌
//	vector<vector<int>> board(h, vector<int>(w, 1));
//
//	for (int i = 0; i < board.size(); i++)
//	{
//		for (int j = 0; j < board[i].size(); j++)
//		{
//			int higth = i - 2;
//			int low = i + 2;
//			if (board[i][j] == 1 && higth >= 0)
//			{
//				board[higth][j] = 0;
//			}
//
//			if (board[i][j] == 1 && low <h)
//			{
//				board[low][j] = 0;
//			}
//
//			int left = j - 2;
//			int right = j + 2;
//
//			if (board[i][j] == 1 && left >=0)
//			{
//				board[i][left] = 0;
//			}
//
//			if (board[i][j] == 1 && right < w)
//			{
//				board[i][right] = 0;
//			}
//		}
//	}
//	int sum = 0;
//	for (int i = 0; i < board.size(); i++)
//	{
//		for (int j = 0; j < board[i].size(); j++)
//		{
//			sum += board[i][j];
//		}
//	}
//	cout << sum << endl;
//	return 0;
//}
//// 64 位输出请用 printf("%lld")
//
//class Solution {
//public:
//	int StrToInt(string str) {
//		if (str.empty())
//			return 0;
//		int begin = 0;
//		bool flag = false;
//		if (str[0] == '-')
//		{
//			flag = true;
//			begin = 1;
//		}
//		if (str[0] == '+')
//		{
//			begin = 1;
//		}
//		long long result = 0;
//		for (; begin < str.size(); begin++)
//		{
//			if (str[begin] >= '0' && str[begin] <= '9')
//			{
//				result = 10 * result + str[begin] - '0';
//			}
//			else
//			{
//				return 0;
//			}
//		}
//        if(flag)
//         result = - result;
//		return result;
//	}
//};



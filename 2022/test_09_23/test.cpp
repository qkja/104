#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//int length(const string& str)
//{
//	int len = str.size();
//	if (len <= 4)
//		return 5;
//	else if (len >= 5 && len <= 7)
//		return 10;
//	else
//		return 25;
//}
//
//bool letter(const string& str)
//{
//	for (auto& e : str)
//	{
//		if (e >= 'a' && e <= 'z' || e >= 'A' && e <= 'Z')
//			return true;
//	}
//	return false;
//}
//
//bool number(const string& str)
//{
//	for (auto& e : str)
//	{
//		if (e >= '0' && e <= '9')
//			return true;
//	}
//	return false;
//}
//
//int numbers(const string& str)
//{
//	int count = 0;
//	for (auto& e : str)
//	{
//		if (e >= '0' && e <= '9')
//			count++;
//	}
//	return count;
//}
//
//int symbols(const string& str)
//{
//	int count = 0;
//	for (auto& e : str)
//	{
//		if (e >= 0x21 && e <= 0x2F
//			|| e >= 0x3A && e <= 0x40
//			|| e >= 0x5B && e <= 0x60
//			|| e >= 0x7B && e <= 0x7E
//		    )
//			count++;
//	}
//	return count;
//}
//
//bool uppercaseandOrLowercase(const string& str)
//{
//	int upper = 0;
//	int lower = 0;
//	for (auto& e : str)
//	{
//		if (e >= 'a' && e <= 'z')
//		{
//			lower = 1;
//		} 
//		if (e >= 'A' && e <= 'Z')
//		{
//			upper = 1;
//		}
//	}
//	if (lower == 1 && upper == 1)
//		return true;
//	else
//		return false;
//}
//
//int passwordStrength(const string& str)
//{
//	int sum = 0;
//	sum += length(str);
//
//	// 有没有字母
//	bool haveLetter = letter(str);
//	bool upOrLower = uppercaseandOrLowercase(str);
//
//	if (haveLetter)
//	{
//		if (upOrLower)
//			sum += 20;
//		else
//			sum += 10;
//	}
//
//	// 判断有没有数字
//	bool haveNumber = number(str);
//	int count = numbers(str); // 几个数字
//
//	if (haveNumber)
//	{
//		if (count == 1)
//			sum += 10;
//		else
//			sum += 20;
//	}
//	if (symbols(str))
//	{
//		if (symbols(str) == 1)
//			sum += 10;
//		else
//			sum += 25;
//	}
//	// 这里是奖励
//	if (upOrLower && haveNumber && symbols(str))
//		return sum + 5;
//	if(haveLetter && !upOrLower && haveNumber && symbols(str))
//		return  sum + 3;
//	if (haveLetter && !upOrLower && haveNumber)
//		return sum + 2;
//	return sum;
//}
//int main()
//{
//	string password;
//	getline(std::cin, password);
//	int ret = passwordStrength(password);
//	cout << ret << endl;
//	/*if (ret >= 90)
//	{
//		cout << "VERY_SECURE" << endl;
//	}
//	else if (ret >= 80)
//	{
//		cout << "SECURE" << endl;
//	}
//	else if (ret >= 70)
//	{
//		cout << "VERY_STRONG" << endl;
//	}
//	else if (ret >= 60)
//	{
//		cout << "STRONG" << endl;
//	}
//	else if (ret >= 50)
//	{
//		cout << "AVERAGE" << endl;
//	}
//	else if (ret >= 25)
//	{
//		cout << "WEAK" << endl;
//	}
//	else
//	{
//		cout << "VERY_WEAK" << endl;
//	}*/
//	return 0;
//}

//class Board {
//public:
//    bool checkWonChild(const vector<vector<int>>& board, int row, int col) {
//
//        //判断 行 
//        int rowSum = 0;
//        for (int i = col+1;  col + 3 <= board[row].size() && i < col + 3; i++)
//        {
//            rowSum += board[row][i];
//        }
//
//        int colSum = 0;
//        for (int i = row + 1; row + 3 <= board.size() && i < row + 3; i++)
//        {
//            colSum += board[i][col];
//        }
//        // 判断对角线 这里一一判断
//        int leftRiagonalSum = 0;
//        if (row - 1 >= 0 && col + 1 < board[row].size())
//        {
//            leftRiagonalSum += board[row - 1][col + 1];
//        }
//
//        if (row + 1 < board.size() && col - 1 >= 0)
//        {
//            leftRiagonalSum += board[row + 1][col - 1];
//        }
//
//        int rightRiagonalSum = 0;
//        if (row - 1 >= 0 && col - 1 >= 0)
//        {
//            rightRiagonalSum += board[row - 1][col - 1];
//        }
//
//        if (row + 1 < board.size() && col + 1 < board[row].size())
//        {
//            rightRiagonalSum += board[row + 1][col + 1];
//        }
//        return 2 == rowSum
//            || 2 == colSum
//            || 2 == leftRiagonalSum
//            || 2 == rightRiagonalSum;
//    }
//    bool checkWon(vector<vector<int> > board) {
//        if (board.empty())
//            return true;
//        for (int i = 0; i < board.size(); i++)
//        {
//            for (int j = 0; j < board[i].size(); j++)
//            {
//                if (board[i][j] == 1)
//                {
//                    //检测是不是 赢了
//                    if (checkWonChild(board, i, j))
//                    {
//                        return true;
//                    }
//                }
//            }
//        }
//        return false;
//    }
//};
//
//
//int main()
//{
//    vector<int> v1;
//    v1.push_back(1);
//    v1.push_back(0);
//    v1.push_back(1);
//
//    vector<int> v2;
//    v2.push_back(1);
//    v2.push_back(-1);
//    v2.push_back(-1);
//
//    vector<int> v3;
//    v3.push_back(1);
//    v3.push_back(-1);
//    v3.push_back(0);
//
//    vector<vector<int>> vv;
//    vv.push_back(v1);
//    vv.push_back(v2);
//    vv.push_back(v3);
//    cout << Board().checkWon(vv) << endl;
//    return 0;
//}

//class MyClass
//{
//public:
//
//
//private:
//
//};
//int main()
//{
//	cout << sizeof(MyClass) << endl;
//	/*const int a = 10;
//	int* p = (int*)(&a);
//	*p = 20;
//	cout << a << (*p) << endl;*/
//	return 0;
//}

//int main()
//{
//	const int a = 10;
//	int* p = (int*)(&a);
//	*p = 20;
//	cout << a << (*p) << endl;
//	return 0;
//}
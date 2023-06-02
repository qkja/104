/**
 * User: Qkj
 * Description: 
 * Date: 2023-06-02
 * Time: 17:47
 */
//class Board {
//public:
//    bool checkWon(vector<vector<int> > board) {
//        // write code here
//        if (board.empty())
//            return true;
//        int row = board.size();    //行
//        int col = board[0].size(); //列数
//        // 测试 列
//        for (int i = 0; i < row; i++)
//        {
//            int sum = 0;
//            for (int j = 0; j < col; j++)
//            {
//                sum += board[i][j];
//            }
//            if (sum == col)
//                return true;
//        }
//
//        // 测试列
//        for (int j = 0; j < col; j++)
//        {
//            int sum = 0;
//            for (int i = 0; i < row; i++)
//            {
//                sum += board[i][j];
//            }
//            if (sum == row)
//                return true;
//        }
//        // 测试 正斜
//        int sum = 0;
//        for (int i = 0; i < row; i++)
//        {
//            for (int j = 0; j < col; j++)
//            {
//                if(i == j)
//                    sum += board[i][j];
//            }
//        }
//        if (sum == col)
//            return true;
//        sum = 0;
//        for (int i = 0; i < row; i++)
//        {
//            for (int j = 0; j < col; j++)
//            {
//                if (i == j)
//                    sum += board[i][row-i-1];
//            }
//        }
//        if (sum == col)
//            return true;
//        return false;
//    }
//};

//#include<iostream>
//#include<string>
//using namespace std;
//class A {
//  friend long fun(A s) {
//    if (s.x < 3) {
//      return 1;
//    }
//    return s.x + fun(A(s.x - 1));
//  }
//  public:
//  A(long a) {
//    x = a--;
//  }
//  private:
//  long x;
//};
//int main() {
//  int sum = 0;
//  for (int i = 0; i < 5; i++) {
//    sum += fun(A(i));
//  }
//  cout << sum;
//  return 0;
//}




#include <iostream>
#include <string>

using namespace std;

int isLen(string & s)
{
	int len = s.size();
	if(len <= 4)
		return 5;
	if(len <= 7)
		return 10;
	return 25;
}

int isDigit(string& s)
{
	string str = "0123456789";
	int count = 0;
	for(size_t i = 0; i < s.size(); i++)
	{
		if(str.find(s[i]) != string::npos)
			count++;
	}
	if(count == 0)
		return 0;
	if(count == 1)
		return 10;
	return 20;
}
int isWords(string& s)
{
	string str1 = "qwertyuioplkjhgfdsazxcvbnm";
	string str2 = "QWERTYUIOPLKJHGFDSAZXCVBNM";
	int ret1 = 0;
	int ret2 = 0;
	for(size_t i = 0; i < s.size(); i++)
	{
		if(str1.find(s[i]) != string::npos)
			ret1++;
		if(str2.find(s[i]) != string::npos)
			ret2++;
	}
	if(ret1 == 0 && ret2==0)
		return 0;
	if(ret1 == 0 || ret2 == 0)
		return 10;
	return 20;

}

int isSymbol(string& s)
{
	string str = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
	int count = 0;
	for(size_t i = 0; i < s.size(); i++)
	{
		if(str.find(s[i]) != string::npos)
			count++;
	}
	if(count == 0)
		return 0;
	if(count == 1)
		return 10;
	return 25;
}


int result(string& s)
{
	if(s.empty())
		return 0;
	int len = isLen(s);
	int words = isWords(s);
	int symbol = isSymbol(s);
	int digit = isDigit(s);
	int sum = len;
	sum += words;
	sum += symbol;
	sum += digit;

	if(words == 20 && digit != 0&&symbol !=0)
		sum += 5;
	else if(words == 10 && digit !=0 &&symbol !=0)
		sum += 3;
	else if(words == 10 && digit !=0 && symbol ==0)
		sum += 2;
	return sum;
}

int main()
{
	string str;
	while (cin >> str) 
	{

		int ret = result(str);
		if(ret >= 90)
			cout << "VERY_SECURE" << endl;
		else if(ret>=80)
			cout <<"SECURE"<<endl;
		else if(ret>=70)
			cout <<"VERY_STRONG"<<endl;
		else if(ret>=60)
			cout <<"STRONG"<<endl;
		else if(ret>=50)
			cout <<"AVERAGE"<<endl;
		else if(ret>=25)
			cout <<"WEAK"<<endl;
		else 
			cout <<"VERY_WEAK"<<endl;
	}
	return 0;
}
// 64 位输出请用 printf("%lld")

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>;
#include <vector>
#include <assert.h>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	string str;
	cin >> str;
	vector<int> v;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		v.push_back(i + 1);
	}
	int flag = 1; //开始页码
	int cursor = 1; //开始页码
	//这里开始遍历字符串
	//这里默认 n > 4
	for (int i = 0; i < str.size(); i++)
	{
		// 这里判断 U 往上走
		if (str[i] == 'U')
		{
			if (cursor == 1)
			{
				// 这里 就 直接跳到最后
				cursor = v[n - 1];
				// 开始页码
				flag = v[n - 4];
			}
			else
			{

			}
		}
		else if (str[i] == 'D')
		{

		}
		else
		{
			assert(false);
		}
	}
	return 0;
}
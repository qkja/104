#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int longestSubstringHelper(const string& s1, int begin1
	, const string& s2, int begin2)
{
	int len = 1;
	++begin2;
	for (int i = begin1 + 1; i < s1.size() && begin2 < s2.size(); i++)
	{
		if (s1[i] != s2[begin2])
		{
			break;
		}
		else
		{
			len++;
		}
		begin2++;
	}

	return len;
}
string longestSubstring(const string& lessStr, const string& greaterStr)
{
	string maxSub;
	// ¿ªÊ¼±éÀú s1 ×Ö·û´®
	int len = 0;
	int prev = lessStr.size();
	for (int i = 0; i < lessStr.size(); i++)
	{

		int start = 0;
		while ((start = greaterStr.find(lessStr[i], start)) != string::npos)
		{

			len = longestSubstringHelper(lessStr, i, greaterStr, start);

			if (len > maxSub.size())
			{
				maxSub = lessStr.substr(i, len);
			}
			// else if (len == maxSub.size())
			// {
			// 	if (start < prev)
			// 	{
			// 		maxSub = greaterStr.substr(i, len);
			// 		prev = start;
			// 	}
			// }
			start = start + 1;
		}

	}
	return maxSub;
}
int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	string greaterStr;
	string lessStr;
	if (s1.size() > s2.size())
	{
		greaterStr = s1;
		lessStr = s2;
	}
	else
	{
		greaterStr = s2;
		lessStr = s1;
	}


	cout << longestSubstring(lessStr, greaterStr).size() << endl;

	return 0;
}
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	string str;
//	cin >>str;
//	reverse(str.begin(), str.end());
//	cout << str;
//	return 0;
//}
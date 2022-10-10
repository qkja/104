#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
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
	// 开始遍历 s1 字符串
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


	cout << longestSubstring(lessStr, greaterStr) << endl;

	return 0;
}
//int longestSubstringHelper(const string& s1, int begin1
//	, const string& s2, int begin2)
//{
//	int len = 1;
//	++begin2;
//	for (int i = begin1+1; i < s1.size() && begin2 < s2.size(); i++)
//	{
//		if (s1[i] != s2[begin2])
//		{
//			break;
//		}
//		else
//		{
//			len++;
//		}
//		begin2++;
//	}
//	
//	return len;
//}
//string longestSubstring(const string& lessStr, const string& greaterStr)
//{
//	string maxSub;
//	// 开始遍历 s1 字符串
//	int len = 0;
//	int prev = lessStr.size();
//	for (int i = 0; i < greaterStr.size(); i++)
//	{
//		int start = 0;
//		while ((start = lessStr.find(greaterStr[i], start)) != string::npos)
//		{
//
//			len = longestSubstringHelper(greaterStr, i, lessStr, start);
//
//			if (len > maxSub.size())
//			{
//				maxSub = greaterStr.substr(i, len);
//			}
//			else if (len == maxSub.size())
//			{
//				if (start < prev)
//				{
//					maxSub = greaterStr.substr(i, len);
//					prev = start;
//				}
//			}
//			start = start + 1;
//		}
//
//	}
//	return maxSub;
//}
//int main()
//{
//	string s1;
//	string s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	string greaterStr;
//	string lessStr;
//	if (s1.size() > s2.size())
//	{
//		greaterStr = s1;
//		lessStr = s2;
//	}
//	else
//	{
//		greaterStr = s2;
//		lessStr = s1;
//	}
//	
//	
//	cout << longestSubstring(lessStr, greaterStr) << endl;
//
//	return 0;
//}

//string longestSubstring(const string& s1, const string& s2)
//{
//	string maxSub;
//	// 开始遍历 s1 字符串
//	int len = 0;
//	
//	string lessString = s1.size() > s2.size() ? s2 : s1;
//    int prev = lessString.size();
//	for (int i = 0; i < s1.size(); i++)
//	{
//
//		int start = 0;
//		while ((start = s2.find(s1[i], start)) != string::npos)
//		{
//			
//			// 找到了 
//			// 这里开始遍历 相同的
//			len = longestSubstringHelper(s1, i, s2, start);
//			
//			if (len > maxSub.size())
//			{
//				maxSub = s1.substr(i, len);
//			}
//			else if(len == maxSub.size())
//			{
//				if (start < prev)
//				{
//					maxSub = s1.substr(i, len);
//					prev = start;
//				}
//			}
//			//if (len < maxSub.size())
//			//{
//			//	// 什么都不做
//			//}
//			//else if (len > maxSub.size())
//			//{
//			//	
//		
//		
//			//		maxSub = s1.substr(i, len);
//		
//			//	
//			//}
//			//else
//			//{
//			//	if (start < prev)
//			//	{
//			//		maxSub = s1.substr(i, len);
//			//		prev = start;
//			//	}
//			//}
//			start = start + 1;
//		}
//		
//	}
//
//
//	return maxSub;
//}
//int main()
//{
//	string s1;
//	string s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	cout << longestSubstring(s1, s2) << endl;
//
//	return 0;
//}
//int bottleToWater(int n)
//{
//	if (n < 2)
//		return 0;
//	if (n == 2)
//		return 1;
//	return n / 3 + bottleToWater(n / 3 + n % 3);
//		
//}
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		cout << bottleToWater(n) << endl;
//	}
//	return 0;
//}
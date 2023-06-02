/**
* User: Qkj
* Description: 
* Date: 2023-06-02
* Time: 15:27
*/

//#include <iostream>
//#include <string>
//using namespace std;
//
//bool isPalindromeString(const string& str)
//{
//	int begin = 0;
//	int end = str.size() - 1;
//	while (begin < end)
//	{
//		if (str[begin] != str[end])
//		{
//			return false;
//		}
//		begin++;
//		end--;
//	}
//	return true;
//}
//
//int main() 
//{
//	string a;
//	string b;
//	std::getline(std::cin, a);
//	std::getline(std::cin, b);
//	int count = 0;
//	for (int i = 0; i <= a.size(); i++)
//	{
//		string str = a;
//		str.insert(i, b);
//		if (isPalindromeString(str) == true)
//			count++;
//	}
//	std::cout << count << std::endl;
//	return 0;
//}





//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//int main()
//{
//	int n = 0;
//	std::cin >> n;
//	std::vector<int> v;
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> v[i];
//	}
//	int maxSum = v[0];
//	int left = maxSum;
//
//	for (int i = 1; i < n; i++)
//	{
//		int ret = std::max(left + v[i], v[i]);
//		if (ret > maxSum)
//		{
//			maxSum = ret;
//			
//		}
//		left = ret;
//	}
//
//	
//	std::cout << maxSum << std::endl;
//	return 0;
//} 





#include <cstring>

#include <iostream>
using namespace std;

int main()
{
  char str1[100] = "abcd";
  char str2[10] = "efg";
 cout << strcat(str1+2, str2) << endl;
  cout << str1<< endl;
  return 0;
}



























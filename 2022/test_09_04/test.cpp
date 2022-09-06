#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
bool InclusiveSeven(int n)
{
	while (n)
	{
		int ret = n % 10;
		if (ret == 7)
			return true;
		n /= 10;
	}
	return false;
}
bool relatedToSeven(int n)
{
	return n % 7 == 0 || InclusiveSeven(n);
}
int main() {
	int n = 0;
	cin >> n;
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (relatedToSeven(i))
			count++;
	}
	cout << count;
}

//typedef struct List_t
//{
//	struct List_t* next;
//	struct List_t* prev;
//	char data[1];
//}list_t;
//int main()
//{
//	printf("%d", sizeof(list_t));
//	return 0;
//}


//void fut(int** s, int p[2][3])
//{
//	**s = p[1][1];
//} 
//int main()
//{
//	int a[2][3] = { 1,3,5,7,9,11 }, * p;
//	p = (int*)malloc(sizeof(int));
//	fut(&p, a);
//	printf("%d", *p);
//	return 0;
//}

//class Solution {
//public:
//    int multiplyChild(int min, int max) {
//        if (min == 1)
//            return max;
//        return max + multiplyChild(min - 1, max);
//    }
//
//    int multiply(int A, int B) {
//        if (A > B)
//            return multiplyChild(B, A);
//        else
//            return multiplyChild(A, B);
//    }
//};

//class Solution {
//public:
//    string compressString(string S) {
//        if (S.empty())
//        {
//            return S;
//        }
//        string str;
//        int i = 0;
//        int ret = 0;
//        int count = 0;
//        while (ret < S.size())
//        {
//            while (ret < S.size() && S[ret] == S[i])
//            {
//                count++;
//                ret++;
//            }
//            if (count != 0)
//            {
//                str += S[i];
//                str += std::to_string(count);
//            }
//            i = i + count;
//            ret = i;
//            count = 0;
//        }
//        if (str.length() >= S.length())
//        {
//            return S;
//        }
//        else
//        {
//            return str;
//        }
//    }
//};
//class Solution {
//public:
//    string compressString(string S) {
//        if (S.empty())
//        {
//            return S;
//        }
//        map<char, int> m;
//        for (int i = 0; i < S.length(); i++)
//        {
//            m[S[i]]++;
//        }
//        auto it = m.begin();
//        string str;
//        while (it != m.end())
//        {
//            str += it->first;
//            str += std::to_string(it->second);
//            ++it;
//        }
//        if (str.length() > S.length())
//        {
//            return S;
//        }
//        else
//        {
//            return str;
//        }
//    }
//};

//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	v.reserve(3 * n);
//	int ret = 0;
//	for (int i = 0; i < 3 * n; i++)
//	{
//		cin >> ret;
//		v.push_back(ret);
//	}
//	sort(v.begin(), v.end(),greater<int>());
//	int sum = 0;
//	for (int i = 1; i < 2 * n - 1; i++)
//	{
//		sum += v[i];
//	}
//	cout << sum;
//	return 0;
//}
//They are students.
//aeiou
//int main()
//{
//	string str1 = "They are students.";
//	string str2 = "aeiou";
//	string str3;
//	/*getline(cin, str1);
//	getline(cin, str2);*/
//	for (int i = 0; i < str1.length(); i++)
//	{
//		if (str2.find(str1[i]) == string::npos)
//		{
//			//cout << str1[i] << " ";
//			str3 += str1[i];
//		}
//	}
//	/*str1 = str3;
//	cout << str1 << endl;*/
//	return 0;
//}
//int main()
//{
//	int a = 1, b = 2, c = 3;
//	if (a == 1 && b++ == 2)
//	{
//		if (b != 2 || c-- != 3)
//		{
//			cout << a << b << c;
//		}
//	}
//	return 0;
//}

//#include<vector>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    long long  res = 0, n;
//    long long  temp;
//    cin >> n;
//    int a = 3 * n;
//    vector<long long> ve;
//    while (a-- > 0)
//    {
//        cin >> temp;
//        ve.push_back(temp);
//    }
//    sort(ve.begin(), ve.begin() + 3 * n, greater<int>());
//    for (int i = 1; i <= (2 * n - 1); i = i + 2)
//        res = res + ve[i];
//    cout << res;
//}


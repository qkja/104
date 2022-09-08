#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    void reverse(string& str, int left, int right)
    {
        right = right - 1;
        while (left < right)
        {
            swap(str[left], str[right]);
            left++;
            right--;
        }
    }

    string reverseLeftWords(string s, int n) {
        if (s.empty() || n == 0)
            return s;

        reverse(s, 0, n);
        reverse(s, n, s.size());
        reverse(s, 0, s.size());
        return s;
    }
};

//class Solution {
//public:
//    string replaceSpace(string s) {
//        string str;
//        if (s.empty())
//        {
//            return str;
//        }
//        auto it = s.begin();
//        while (it != s.end())
//        {
//            if (*it == ' ')
//                str += "%20";
//            else
//                str += *it;
//            ++it;
//        }
//        return str;
//    }
//};
//mapped_type& operator[](const key_type& k)
//{
//	pair<iterator,bool> ret = insert(make_pair(k,mapped_type()));
//	return ret.fiest->second;
//}
//{
//
//(*((this->insert(make_pair(k, mapped_type()))).first)).second
//
//}


int main()
{

}
//int main()
//{
//	set<int> s;
//	s.insert(1);
//	s.insert(3);
//	s.insert(2);
//	auto it = s.begin();
//	while (it != s.end())
//	{
//		*it = 10;
//		cout << *it << " ";
//		++it;
//	}
//	return 0;
//}

//int main()
//{
//	map<string, string> m;
//	auto ret1 = m.insert(pair<string, string>("left", "×ó±ß"));
//	auto ret2 = m.insert(pair<string, string>("left", "Ê£Óà"));
//
//	return 0;
//}

//int main()
//{
//	map<string, string> m;
//	m.insert(pair<string, string>("peach", "ÌÒ×Ó"));
//	m.insert(pair<string, string>("left", "×ó±ß"));
//	map<string, string>::iterator it = m.begin();
//	while (it != m.end())
//	{
//		cout << (*it).first <<" " << it->second << endl;
//		it++;
//	}
//	cout << "=======================" << endl;
//
//	m["left"] = "Ê£Óà";
//	//auto find = m.find("left");
//	/*if (find != m.end())
//	{
//		find->second = "Ê£Óà";
//	}*/
//
//	it = m.begin();;
//	while (it != m.end())
//	{
//		cout << (*it).first << " " << it->second << endl;
//		it++;
//	}
//
//	return 0;
//}

//int main()
//{
//	map<int, int> m;
//	m.insert(std::pair<int, int>(1, 1));
//	m.insert(make_pair(2,2));
//
//	return 0;
//}



//template<class T1,class T2>
//struct pair
//{
//	T1 fiest;
//	T2 second;
//};
//int main()
//{
//	multiset<int> s;
//	s.insert(1);
//	s.insert(2);
//	s.insert(2);
//	s.insert(3);
//	cout << s.count(2) << endl;
//	for (const int& val : s)
//	{
//		cout << val << " ";
//	}
//	cout << endl;
//
//
//	return 0;
//}
//int main()
//{
//	set<int> s;
//	s.insert(1);
//	s.insert(2);
//	s.insert(2);
//	s.insert(3);
//	for (const int& val : s)
//	{
//		cout << val << " ";
//	}
//	cout << endl;
//	s.erase(2);
//	for (const int& val : s)
//	{
//		cout << val << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	set<int> s;
//	s.insert(1);
//	s.insert(2);
//	s.insert(2);
//	s.insert(3);
//	cout << s.count(1) << endl;
//	return 0;
//}

//int main()
//{
//	set<int> s;
//	auto it = s.insert(1);
//	s.insert(1);
//	return 0;
//}
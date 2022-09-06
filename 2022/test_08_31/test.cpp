#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(2);
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	return 0;
}
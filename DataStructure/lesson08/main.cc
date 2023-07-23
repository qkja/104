#include <iostream>
#include <vector>
#include "sort.hpp"
using namespace std;

#define CAP 100000

vector<int> g_1 = {1};
vector<int> g_2 = {1, 1, 2, 3};
vector<int> g_3 = {3, 2, 1, 1};
vector<int> g_4 = {3, 1, 1, 2};
vector<vector<int>> vv = {g_1, g_2, g_3, g_4};
void Print(const vector<int> &v)
{
	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	srand((unsigned)time(nullptr));
	for (int i = 0; i < 4; i++)
	{
		Print(vv[i]);
		QuickSort(vv[i]);
		Print(vv[i]);
	}
	return 0;
}
#pragma once
#include <map>
#include <string>
#include <vector>
using namespace std;

//template <class T>
//class UnionFindSet
//{
//public:
//	UnionFindSet(const T* a, size_t n)
//	{
//		for (int i = 0; i < n; ++i)
//		{
//			_a.push_back(a[i]);
//			_indexMap[a[i]] = i; // 这里重复的先不关心
//		}
//	}
//	~UnionFindSet()
//	{
//
//	}
//
//private:
//	vector<T> _a;
//	map<T, int> _indexMap;
//};

template <class T>
class UnionFindSet
{
public:
	UnionFindSet(size_t n)
		:_ufs(n, -1)
	{

	}
	~UnionFindSet()
	{

	}
public:
	// 合并
	void Union(int x1, int x2)
	{
		int root1 = findRoot(x1);
		int root2 = findRoot(x2);
		if (root1 == root2)
			return;
		_ufs[root1] += _ufs[root2];
		_ufs[root2] = root1;
	}
	
	// 找根
	int findRoot(int x)
	{
		int parent = x;
		while (_ufs[parent] >= 0)
		{
			parent = _ufs[parent];
		}
		return parent;
	}

	bool InSet(int x, int y)
	{
		return findRoot(x) == findRoot(y);
	}
	size_t size()
	{
		int result = 0;
		for (int i = 0; i < _ufs.size(); ++i)
		{
			if (_ufs[i] < 0) ++result;
		}
		return result;
	}
private:
	vector<T> _ufs;
};
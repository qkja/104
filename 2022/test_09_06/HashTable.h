#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <vector>
using std::vector;
using std::pair;
template<class K, class V>
struct HashData
{
	pair<K, V> _kv;

};

template<class K,class V>
class HashTable
{
public:

private:
	vector<V> _v;
};


#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <vector>
using std::vector;
using std::pair;
enum State
{
	EMPTY,   // 空
	EXITS,   // 存在
	DELETE   // 删除
};
template<class K, class V>
struct HashData
{
	pair<K, V> _kv;
	State _state;
};

template<class K,class V>
class HashTable
{
public:
	void insert(const pair<K,V>& kv)
	{

		// 扩容 负载因子
		if (_table.size()==0 || _count * 10 % _table.size() > 7)
		{
			size_t newSize = _table.size() == 0 ? 4 : 2 * _table.size();

			// 这里需要重新哈希
			HashTable<K, V> h;
			h._table.reserve(newSize);
			for (auto& v : _table)
			{
				if (v._state == EXITS)
				{
					h.insert(v);
				}
			}
			_table.swap(h._table);
		}

		// 算位置 K 一个整数
		size_t i = kv.first;
		size_t beginI = i % _table.size();// z注意为何是size
		size_t hashI = beginI;
		int i = 1;
		while (_table[hashI]._state == EXITS)
		{
			hashI = (beginI + i) % _table.size();
			i++;
		}
		// 找到了 空
		_table[hashI]._kv = kv;
		_table[hashI]._state = EXITS;
		_count++;
	}
private:
	vector<HashData<K,V>> _table; // 原因  后面 map 要用
	size_t _count = 0; // 因子
};
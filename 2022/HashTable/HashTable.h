#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <vector>
using namespace std;

namespace bit
{
	enum State
	{
		EMPTY,
		EXITS,
		DELETE
	};
	template <class K, class V>
	struct HashData
	{
		HashData()
			:_state(EMPTY)
		{}
		pair<K, V> _kv;
		State _state;
	};

	template <class K, class V>
	class HashTable
	{
		typedef HashData<K, V> HashNode;
	public:
		// 析构函数  要不要 写
		bool Insert(const pair<K, V>& kv)
		{
			// 去重
			if (Find(kv.first) != nullptr)
			{
				return false;
			}
			// 扩容  负载因子
			if (_tables.size() == 0 || 10 * _n / _tables.size() >= 7)
			{
				size_t newSize = _tables.size() == 0 ? 10 : 2 * _tables.size();
				HashTable<K, V> newHT;
				newHT._tables.resize(newSize);
				for (auto& e : _tables)
				{
					if (e._state == EXITS)
					{
						newHT.Insert(e._kv);
					}
				}
				newHT._tables.swap(_tables);
			}

			// 线性探测
			size_t starti = kv.first;
			starti = starti % _tables.size();
			size_t hashi = starti;
			int i = 0;
			while (_tables[hashi]._state == EXITS)
			{
				hashi = starti + i;
				i++;
				hashi %= _tables.size();
			}
			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXITS;
			_n++;
			return true;
		}
		HashNode* Find(const K& key)
		{
			if (_n == 0)
			{
				return nullptr;
			}
			size_t starti = key;
			starti = starti % _tables.size();
			size_t hashi = starti;
			int i = 1;
			while (_tables[hashi]._state != EMPTY)
			{
				if (_tables[hashi]._state == EXITS
					&& _tables[hashi]._kv.first == key)
				{
					--_n;
					return &_tables[hashi];
				}
				hashi = starti + i;
				i++;
				hashi %= _tables.size();
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashNode* ret = Find(key);
			if (ret != nullptr)
				ret->_state = DELETE;
			return true;
		}

	private:
		vector<HashNode> _tables;
		int _n = 0;
	};

	/*void test_hash1()
	{
		int arr[] = { 20, 5, 8, 99999, 10, 30, 50 };
		HashTable<int, int> hs;
		for (int val : arr)
		{
			hs.Insert(make_pair(val, val));
		}
		hs.Insert(make_pair(20, 20));
		hs.Erase(20);
		if (hs.Find(50))
		{
			cout << "找到了" << endl;
		}
	}*/

	void test_hash2()
	{
		int arr[] = { 20, 5, 8, 99999, 10, 30, 50 };
		HashTable<int, int> hs;
		for (int val : arr)
		{
			hs.Insert(make_pair(val, val));
		}
		hs.Insert(make_pair(20, 20));
		hs.Erase(20);
		if (hs.Find(50))
		{
			cout << "找到了" << endl;
		}
	}
}

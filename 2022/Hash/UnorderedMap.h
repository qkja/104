#define _CRT_SECURE_NO_WARNINGS 1
#include "HashTable.h"

namespace bit
{
	template<class K, class V, class HashFunc = Hash<K>>
	class unordered_map
	{
		struct MapKoyOfT
		{
			const K& operator()(const pair<K, V>& data)
			{
				return data.first;
			}
		};
	public:
		typedef typename HashTable<K, pair<K, V>, MapKoyOfT, HashFunc>::iterator iterator;
		iterator begin()
		{
			return _map.begin();
		}
		iterator end()
		{
			return _map.end();
		}
		V& operator[](const K& key)
		{
			pair<iterator, bool> it = insert(make_pair(key,V()));

			return it.first->second;
		}
		pair<iterator, bool> insert(const pair<K, V>& data)
		{
			return _map.insert(data);
		}
		iterator find(const K& key)
		{
			return _map.find(key);
		}
		bool erase(const K& key)
		{
			return _map.erase(key);
		}
	private:
		HashTable<K, pair<K, V>, MapKoyOfT, HashFunc> _map;
	};
	void test_map2()
	{
		unordered_map<string, int> m;
		m["Æ»¹û"]++;
		m["Ïã½¶"] = 2;
		unordered_map<string, int>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << (*it).first << " : " << (*it).second << endl;
			it++;
		}
	}
	void test_map1()
	{
		unordered_map<int,int> m;
		m.insert(make_pair(0, 0));
		m.insert(make_pair(1, 1));
		m.insert(make_pair(10, 10));
		auto it = m.begin();
		while (it != m.end())
		{
			cout << (*it).first << " : " << (*it).second << endl;
			++it;
		}
		m.erase(10);
		cout << "================" << endl;
		it = m.begin();;
		while (it != m.end())
		{
			cout << (*it).first << " : " << (*it).second << endl;
			++it;
		}
		/*for (auto& e : m)
		{
			cout << e.first << " : " << e.second << endl;
		}*/
	}
}

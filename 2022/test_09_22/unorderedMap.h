#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
namespace OpenHash
{
	template<class K, class V>
	class UnorderedMap
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& data)
			{
				return data.first;
			}
		};

	public:
		bool insert(const pair<K, V>& data)
		{
			return _map.Insert(data);
		}
		bool erase(const K& key)
		{
			return _map.Erase(key);
		}
		bool find(const K& key)
		{
			return _map.Find(key);
		}
	private:
		HashBucket<K, pair<K, V>, MapKeyOfT> _map;
	};

	void test_map1()
	{
		UnorderedMap<int, int> m;
		m.insert(make_pair(1, 1));
		m.insert(make_pair(2, 2));
		m.insert(make_pair(3, 3));
		m.insert(make_pair(3, 3));
		m.erase(3);
		m.erase(1);
	}
}
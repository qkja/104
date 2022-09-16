#define _CRT_SECURE_NO_WARNINGS 1
#include "RBTree.h"
namespace bit
{
	template<class K, class V>
	class Map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& data)
			{
				return data.first;
			}
		};
	public:

		typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::const_iterator const_iterator;
		iterator begin()
		{
			return _map.Begin();
		}
		iterator end()
		{
			return _map.End();
		}
	public:
		iterator find(const K& k)
		{
			return _map.Find(k);
		}
		V& operator[](const K& k)
		{
			pair<iterator, bool> p = _map.Insert(make_pair(k, V()));
			return p.first->second;
		}
		pair<iterator, bool> insert(const pair<K, V>& data)
		{
			return _map.Insert(data);
		}


	private:
		RBTree<K, pair<K, V>, MapKeyOfT> _map;
	};
	/*void test_map1()
	{
		Map<int, int> m;
		m.insert(make_pair(1, 1));
		m.insert(make_pair(2, 2));
		m.insert(make_pair(3, 3));
		m.insert(make_pair(4, 4));
		auto it = m.begin();
		while (it != m.end())
		{
			
			cout << it->first << it->second << endl;
			++it;
		}
	}*/

	void test_map2()
	{


		Map<string, string> dict;
		dict["insert"];
		dict["insert"] = "²åÈë";
		dict["left"] = "×ó±ß";
		dict["left"] = "Ê£Óà";


	}
}

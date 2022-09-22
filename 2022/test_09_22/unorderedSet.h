#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
namespace OpenHash
{
	template<class K>
	class UnorderedSet
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& data)
			{
				return data;
			}
		};
	public:
		bool insert(const K& data)
		{
			return _set.Insert(data);
		}
		bool erase(const K& key)
		{
			return _set.Erase(key);
		}
		bool find(const K& key)
		{
			return _set.Find(key);
		}

	private:
		//template<class K, class T, class KeyOfT, class HF = HashFunc<T>>
		HashBucket<K, K, SetKeyOfT> _set;
	};

	void test_set1()
	{
		UnorderedSet<int> s;
		s.insert(1);
		s.insert(12);
		s.insert(11);
	}
}
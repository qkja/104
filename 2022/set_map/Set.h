#define _CRT_SECURE_NO_WARNINGS 1
#include "RBTree.h"

namespace bit
{
	template<class K>
	class Set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};
	public:
		//typedef typename RBTree<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;
		iterator begin() const
		{
			return _set.Begin();
		}
		iterator end()  const
		{
			return _set.End();
		}
	public:
		pair<iterator, bool> insert(const K& k)
		{
			pair<typename RBTree<K, K, SetKeyOfT>::iterator, bool> p = _set.Insert(k);
			return make_pair(iterator(p.first._node), p.second);
			//return _set.Insert(k);
		}

		iterator find(const K& key) const
		{
			return _set.Find(key);
		}

	private:
		RBTree<K, K, SetKeyOfT> _set;
	};

	void test_set2()
	{
		Set<int> s;
		s.insert(1);
		s.insert(3);
		s.insert(0);
		auto it = s.find(1);
		if (it != s.end())
		{
			cout << "ур╣╫ак" << endl;
		}
		//auto it = s.begin();
		
		/*while (it != s.end())
		{
			*it = 2;
			cout << *it << " ";
			it++;
		}*/
	}

	//void test_set1()
	//{
	//	Set<int> s;
	//	s.insert(1);
	//	s.insert(2);
	//	auto it = s.end();
	//	while (it != s.begin())
	//	{

	//		//cout << *it << endl;
	//		cout << *it << endl;
	//		it--;
	//	}
	//	//auto it = s.begin();
	//	//while (it != s.end())
	//	//{
	//	//	
	//	//	//cout << *it << endl;
	//	//	cout << *it << endl;
	//	//	it++;
	//	//}
	//}
}
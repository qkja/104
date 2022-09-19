#define _CRT_SECURE_NO_WARNINGS 1
#include "HashTable.h"
namespace bit
{
	/*class Date
	{
	public:
		int _year;
		int _month;
		int _days;
		bool operator==(const Date& date) const
		{
			return _year == date._year
				&& _month == date._month
				&& _days == date._days;
		}
	};

	struct DataHashFunc
	{
		size_t operator()(const Date& date)
		{
			return date._days + date._month + date._year;
		}
	};*/
	template<class T>
	struct Hash
	{
		size_t operator()(const T& data)
		{
			return data;
		}
	};
	template<>
	struct Hash<string>
	{
		size_t operator()(const string& data)
		{
			// y有人 做了 一个测试   冲突不可避免 上一个  hash 131  ...
			size_t hash = 0;
			for (int ch : data)
			{
				hash = hash * 131 + ch;
			}
			return hash;
		}
	};
	template<class K, class HashFunc = Hash<K>>
	class unordered_set
	{
		struct SetKoyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename HashTable<K, K, SetKoyOfT, HashFunc>::iterator iterator;
		pair<iterator, bool> insert(const K& key)
		{
			return _set.insert(key);
		}
		iterator find(const K& key)
		{
			return _set.find(key);
		}
		bool erase(const K& key)
		{
			return _set.erase(key);
		}
		iterator begin()
		{
			return _set.begin();
		}
		iterator end()
		{
			return _set.end();
		}

	private:
		HashTable<K, K, SetKoyOfT, HashFunc> _set;
	};

	void test_set3()
	{
		unordered_set<int> s;
		s.insert(1);
		s.insert(2);
		s.insert(3);
		s.insert(4);

		/*unordered_set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << endl;
			++it;
		}*/

		if (s.find(4) != s.end())
		{
			cout << "找到了" << endl;
		}
		s.erase(4);
		if (s.find(4) != s.end())
		{
			cout << "找到了" << endl;
		}
    }
	//void test_set2()
	//{
	//	unordered_set<Date, DataHashFunc> s;
	//	Date d1;
	//	d1._days = 1;
	//	d1._month = 1;
	//	d1._year = 1;
	//	Date d2;

	//	d2._days = 0;
	//	d2._month = 2;
	//	d2._year = 1;
	//	s.insert(d1);
	//	s.insert(d2);
	//}

	//void test_set1()
	//{
	//	unordered_set<Date, DataHashFunc> s;
	//	Date d1;
	//	d1._days = 1;
	//	d1._month = 1;
	//	d1._year = 1;
	//	Date d2;

	//	d2._days = 0;
	//	d2._month = 2;
	//	d2._year = 1;
	//	/*s.insert(0);
	//	s.insert(1);
	//	s.insert(10);*/
	//}
}
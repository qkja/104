#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <vector>
using namespace std;
//开散列  哈希桶
namespace Bucket
{
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
	template<class K, class V>
	struct HashNode
	{
		HashNode(const pair<K, V>& kv)
			:_kv(kv)
			,_next(nullptr)
		{}
		HashNode<K, V>* _next;
		pair<K, V> _kv;
	};

	template<class K,class V,  class HashFunc = Hash<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:

		bool insert(const pair<K, V>& kv)
		{
			if (find(kv.first))
			{
				return false;
			}
			//扩用 负载因子 以
			HashFunc hf;

			if (_n == _tables.size())
			{
				size_t newSize = _tables.size() == 0? 10 : 2 * _tables.size();

				// 这里我们用 跟家简单的用法
				vector<Node*> newTable;
				newTable.resize(newSize);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						// 在这里  直接   使用源节点
						size_t starti = hf(cur->_kv.first);
						//size_t starti = cur->_kv.first;
						starti %= newTable.size();
						cur->_next = newTable[starti];
						newTable[starti] = cur;
						cur = next;
					}
					_tables[i] = nullptr;
				}
				_tables.swap(newTable);
				/*HashTable<K, V, HashFunc> newHT;
				newHT._tables.resize(newSize);
				for (Node*& e : _tables)
				{
					Node* cur = e;
					while (cur)
					{
						newHT.insert(cur->_kv);
						cur = cur->_next;
					}
				}

				newHT._tables.swap(_tables);*/
			}
			//算位置
			size_t hashi = hf(kv.first);
			hashi %= _tables.size();

			Node* node = new Node(kv);
			
			//头插
			Node* prev = _tables[hashi];
			_tables[hashi] = node;
			node->_next = prev;
			_n++;
			return true;
		}

		Node* find(const K& key)
		{
			if (_n == 0)
				return nullptr;
			HashFunc hf;

			size_t hashi = hf(key);
			hashi %= _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return nullptr;
		}
		bool erase(const K& key)
		{
			HashFunc hf;
			size_t hashi = hf(key);
			hashi %= _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					// 删除
					Node* node = _tables[hashi];
					cur->_kv = node->_kv;
					_tables[hashi] = _tables[hashi]->_next;
					delete node;
					_n--;
					return true;
				}
				cur = cur->_next;
			}

			return false;
		}

	private:
		vector<Node*> _tables;
		size_t _n = 0;
	};

	void test2()
	{
		string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
		HashTable<string, int> countHT;

		for (auto& str : arr)
		{
			auto ret = countHT.find(str);
			if (ret)
			{
				ret->_kv.second++;
			}
			else
			{
				countHT.insert(make_pair(str, 1));
			}
		}
		countHT.erase("苹果");
		countHT.erase("西瓜");
		cout << "hahha" << endl;
		cout << endl;
	}

	/*void test1()
	{
		HashTable<int, int> hs;
		hs.insert(make_pair(0, 0));
		hs.insert(make_pair(1, 1));
		hs.insert(make_pair(2, 2));
		hs.insert(make_pair(3, 3));
		hs.insert(make_pair(4, 4));
		hs.insert(make_pair(10, 10));

		if (hs.find(1))
		{
			cout << "找到了" << endl;
		}
		else
		{
			cout << "没有找到" << endl;
		}
	}*/
}

//namespace bit
//{
//	// 模板  得到 key
//	template<class T>
//	struct Hash
//	{
//		size_t operator()(const T& data)
//		{
//			return data;
//		}
//	};
//	//template<>
//	//struct Hash<string>
//	//{
//	//	size_t operator()(const string& data)
//	//	{
//	//		// 一种方法
//	//		return data[0];
//	//	}
//	//};
//	// 上面的方法 是不对的  相同的第一个字符 就会冲突
//
//	//template<>
//	//struct Hash<string>
//	//{
//	//	size_t operator()(const string& data)
//	//	{
//	//		// 这里还存在一个方法 把所有  字符 给加起来  ab 和  ba 冲突
//	//		size_t hash = 0;
//	//		for (int ch : data)
//	//		{
//	//			hash += ch;
//	//		}
//	//		return hash;
//	//	}
//	//};
//	template<>
//	struct Hash<string>
//	{
//		size_t operator()(const string& data)
//		{
//			// y有人 做了 一个测试   冲突不可避免 上一个  hash 131  ...
//			size_t hash = 0;
//			for (int ch : data)
//			{
//				hash = hash * 131 + ch;
//			}
//			return hash;
//		}
//	};
//
//	enum State
//	{
//		EMPTY,
//		EXITS,
//		DELETE
//	};
//	template <class K, class V>
//	struct HashData
//	{
//		HashData()
//			:_state(EMPTY)
//		{}
//		pair<K, V> _kv;
//		State _state;
//	};
//
//	template <class K, class V, class HashFunc = Hash<K>>
//	class HashTable
//	{
//		typedef HashData<K, V> HashNode;
//	public:
//		// 析构函数  要不要 写
//		bool Insert(const pair<K, V>& kv)
//		{
//			// 去重
//			if (Find(kv.first) != nullptr)
//			{
//				return false;
//			}
//			// 扩容  负载因子
//			if (_tables.size() == 0 || 10 * _n / _tables.size() >= 7)
//			{
//				size_t newSize = _tables.size() == 0 ? 10 : 2 * _tables.size();
//				HashTable<K, V, HashFunc> newHT;
//				newHT._tables.resize(newSize);
//				for (auto& e : _tables)
//				{
//					if (e._state == EXITS)
//					{
//						newHT.Insert(e._kv);
//					}
//				}
//				newHT._tables.swap(_tables);
//			}
//
//			// 线性探测
//			HashFunc hf;
//			size_t starti = hf(kv.first);
//			starti = starti % _tables.size();
//			size_t hashi = starti;
//			int i = 0;
//			while (_tables[hashi]._state == EXITS)
//			{
//				hashi = starti + i;
//				i++;
//				hashi %= _tables.size();
//			}
//			_tables[hashi]._kv = kv;
//			_tables[hashi]._state = EXITS;
//			_n++;
//			return true;
//		}
//		HashNode* Find(const K& key)
//		{
//			if (_n == 0)
//			{
//				return nullptr;
//			}
//			HashFunc hf;
//			// 这一步 还是 比较 重要的
//			size_t starti = hf(key);
//			starti = starti % _tables.size();
//			size_t hashi = starti;
//			int i = 1;
//			while (_tables[hashi]._state != EMPTY)
//			{
//				if (_tables[hashi]._state == EXITS
//					&& _tables[hashi]._kv.first == key)
//				{
//					--_n;
//					return &_tables[hashi];
//				}
//				hashi = starti + i;
//				i++;
//				hashi %= _tables.size();
//			}
//			return nullptr;
//		}
//
//		bool Erase(const K& key)
//		{
//			HashNode* ret = Find(key);
//			if (ret != nullptr)
//				ret->_state = DELETE;
//			return true;
//		}
//
//	private:
//		vector<HashNode> _tables;
//		int _n = 0;
//	};
//	void test_hash5()
//	{
//		string str[] = { "aaaa","abbb","ccccc","accc" };
//
//		HashTable<string, int> hs;  // 模板的特化
//		for (const string& e : str)
//		{
//			hs.Insert(make_pair(e, 0));
//		}
//		cout << endl;
//		HashTable<string, int> hs2(hs);  // 模板的特化
//		cout << endl;
//	}
//	/*void test_hash5()
//	{
//		string str[] = { "aaaa","abbb","ccccc","accc" };
//		cout << Hash<string>()(str[0]) << endl;
//		cout << Hash<string>()(str[1]) << endl;
//		cout << Hash<string>()(str[2]) << endl;
//		cout << endl;
//	}*/
//
//	/*void test_hash4()
//	{
//		string str[] = { "aaaa","abbb","ccccc","accc" };
//
//		HashTable<string, int, Hash<string>> hs;
//		for (const string& e : str)
//		{
//			hs.Insert(make_pair(e, 0));
//		}
//		cout << endl;
//	}*/
//
//	/*void test_hash3()
//	{
//		int arr[] = { 20, 5, 8, 99999, 10, 30, 50 };
//		HashTable<int, int, Hash<int>> hs;
//		for (int val : arr)
//		{
//			hs.Insert(make_pair(val, val));
//		}
//		hs.Insert(make_pair(20, 20));
//		hs.Erase(20);
//		if (hs.Find(50))
//		{
//			cout << "找到了" << endl;
//		}
//	}*/
//
//	/*void test_hash1()
//	{
//		int arr[] = { 20, 5, 8, 99999, 10, 30, 50 };
//		HashTable<int, int> hs;
//		for (int val : arr)
//		{
//			hs.Insert(make_pair(val, val));
//		}
//		hs.Insert(make_pair(20, 20));
//		hs.Erase(20);
//		if (hs.Find(50))
//		{
//			cout << "找到了" << endl;
//		}
//	}*/
//
//	/*void test_hash2()
//	{
//		int arr[] = { 20, 5, 8, 99999, 10, 30, 50 };
//		HashTable<int, int> hs;
//		for (int val : arr)
//		{
//			hs.Insert(make_pair(val, val));
//		}
//		hs.Insert(make_pair(20, 20));
//		hs.Erase(20);
//		if (hs.Find(50))
//		{
//			cout << "找到了" << endl;
//		}
//	}*/
//}

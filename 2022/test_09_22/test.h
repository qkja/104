#define _CRT_SECURE_NO_WARNINGS 1
// 注意：假如实现的哈希表中元素唯一，即key相同的元素不再进行插入
// 为了实现简单，此哈希表中我们将比较直接与元素绑定在一起
#include <iostream>
#include <vector>
using namespace std;

namespace OpenHash
{
	template<class T>
	struct HashBucketNode
	{
		HashBucketNode(const T& data)
			:_pNext(nullptr)
			, _data(data)
		{}
		HashBucketNode<T>* _pNext;
		T _data;
	};
	// 这是哈希函数
	template<class K>
	class HashFunc
	{
	public:
		size_t operator()(const K& val)
		{
			return val;
		}
	};
	template<>
	class HashFunc<string>
	{
	public:
		size_t operator()(const string& s)
		{
			const char* str = s.c_str();
			unsigned int seed = 131; // 31 131 1313 13131 131313
			unsigned int hash = 0;
			while (*str)
			{
				hash = hash * seed + (*str++);
			}

			return hash;
		}
	};

	// 声明一下
	template<class K, class T, class KeyOfT, class HF>
	class HashBucket;
	// 实现 哈希表的迭代器
	template<class K, class T, class KeyOfT, class HF>
	class Iterator_HashBucket
	{
		typedef HashBucketNode<T> Node;
		typedef Iterator_HashBucket<K, T, KeyOfT, HF> Self;
	public:
		Iterator_HashBucket(Node* node, HashBucket<K, T, KeyOfT, HF>* pht)
			:_node(node)
			,_pht(pht)
		{}
		Iterator_HashBucket()
		{}
		//Self& operator++()
		//{
		//	if (_node->_pNext)
		//	{
		//		_node = _node->_pNext;
		//	}
		//	else
		//	{
		//		KeyOfT kot;
		//		HF hf;
		//		size_t hashi = hf(kot(_node->_data));
		//		hashi %= _pht->_table.size();
		//		++hashi;
		//		//找下一个不为空的桶
		//		for (; hashi < _pht->_table.size(); ++hashi)
		//		{
		//			if (_pht->_table[hashi])
		//			{
		//				_node = _pht->_table[hashi];
		//				break;
		//			}
		//		}
		//		// 没有找到不为空的桶，用nullptr去做end标识
		//		if (hashi == _pht->_table.size())
		//		{
		//			_node = nullptr;
		//		}
		//	}
		//	return *this;
		//}
		Self& operator++()
		{
			if (_node->_pNext != nullptr)
			{
				_node = _node->_pNext;
			}
			else
			{
				// 这里需要找 下一个 非空的哈希桶
				// 第一步 找到当前的桶
				KeyOfT kot;
				HF hf;
				size_t starti = hf(kot(_node->_data));
				starti = starti % _pht->_table.size();
				starti++;
				/*size_t starti = hf(kot(_node->_data));
				size_t hashi = starti % _pht->_table.size();
				int i = hashi + 1;*/
				for (; starti < _pht->_table.size(); starti++)
				{
					if (_pht->_table[starti] != nullptr)
					{
						_node = _pht->_table[starti];
						break;
					}
				}
				if (starti == _pht->_table.size())
				{
					_node = nullptr;
				}
			}
			return *this;
		}
		Self operator++(int)
		{
			Self ret(*this);
			++(*this);
			return ret;
		}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}
	private:
		Node* _node;
		HashBucket<K, T, KeyOfT, HF>* _pht;
	};

	

	// 本文所实现的哈希桶中key是唯一的
	template<class K, class T, class KeyOfT, class HF = HashFunc<K>>
	class HashBucket
	{
		typedef HashBucketNode<T> Node;
		typedef HashBucket<K, T, KeyOfT, HF> Self;
		template<class K, class T, class KeyOfT, class HF>
		friend class Iterator_HashBucket;


	public:
		// 迭代器
		typedef Iterator_HashBucket<K, T, KeyOfT, HF> iterator;
		iterator begin()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				if (cur != nullptr)
				{
					return iterator(cur, this);
				}
			}
			return end();
		}
		iterator end()
		{
			return iterator(nullptr, this);
		}

	public:
		~HashBucket()
		{
			Clear();
		}
		// 哈希桶中的元素不能重复
		bool Insert(const T& data)
		{
			HF hf;
			KeyOfT kot;
			if (Find(kot(data)))
			{
				return false;
			}
			if (_size == _table.size())
			{
				// 扩容  需要重新 哈希 先来个效率低的
				size_t newSize = _table.size() == 0 ? 10 : 2 * _table.size();

				Self newHT;
				newHT._table.resize(newSize);
				for (size_t i = 0; i < _table.size();i++)
				{
					Node* cur = _table[i];
					while (cur)
					{
						newHT.Insert(cur->_data);
						cur = cur->_pNext;
					}
				}
				Swap(newHT);
			}

			size_t starti = hf(kot(data));
			size_t hashi = starti % _table.size();
			Node* node = new Node(data);
			node->_pNext = _table[hashi];
			_table[hashi] = node;
			_size++;
			return true;
		}
		// 删除哈希桶中为data的元素(data不会重复)
		bool Erase(const K& key)
		{
			if (_size == 0)
			{
				return false;
			}
			HF hf;
			KeyOfT kot;
			size_t starti = hf(key);
			size_t hashi = starti % _table.size();
			Node* cur = _table[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					cur->_data = _table[hashi]->_data;
					cur = _table[hashi];
					_table[hashi] = _table[hashi]->_pNext;
					delete cur;
					--_size;
					return true;
				}
				cur = cur->_pNext;
			}
			return false;
		}

		bool Find(const K& key)
		{
			if (_size == 0)
			{
				return false;
			}
			HF hf;
			KeyOfT kot;
			size_t starti = hf(key);
			size_t hashi = starti % _table.size();
			Node* cur = _table[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return true;
				}
				cur = cur->_pNext;
			}
			return false;

		}

		size_t Size()const
		{
			return _size;
		}

		bool Empty()const
		{
			return 0 == _size;
		}

		void Clear()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_pNext;
					delete cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
		}

		size_t BucketCount()const
		{
			return _table.capacity();
		}

		void Swap(Self& ht)
		{
			_table.swap(ht._table);
			swap(_size, ht._size);
		}

	private:
		vector<Node*> _table;
		size_t _size;      // 哈希表中有效元素的个数
	};
}


//using std::vector;
//using std::pair;
//namespace Close_Hash
//{
//	enum State
//	{
//		EMPTY,
//		EXIST,
//		DELETE
//	};
//
//	template<class K, class T>
//	class HashTable
//	{
//		struct Elem
//		{
//			pair<K, T> _val;
//			State _state;
//		};
//
//	public:
//		HashTable(size_t capacity = 3)
//			:_ht(capacity)
//			, _size(0)
//			, _totalSize(0)
//		{
//			for (size_t i = 0; i < capacity; ++i)
//				_ht[i]._state = EMPTY;
//		}
//
//		// 插入
//		bool Insert(const pair<K, T>& val)
//		{
//			if (Find(val.first))
//			{
//				return false;
//			}
//
//			// 这里是扩容  这里已经提前开了三个
//			if (10 * _size / _ht.size() >= 7)
//			{
//				size_t newSize = _ht.size() == 0 ? 10 : 2 * _ht.size();
//
//				HashTable<K, T> newHT;
//				newHT._ht.resize(newSize);
//				for (auto& e : _ht)
//				{
//					if (e._state == EXIST)
//					{
//						newHT.Insert(e._val);
//					}
//				}
//				Swap(newHT);
//				_totalSize = _size;
//			}
//
//			size_t starti = val.first;
//			size_t hashi = starti % _ht.size();
//			//开始线性探测
//			int i = 1;
//			while (_ht[hashi]._state == EXIST)
//			{
//				hashi = starti + i;
//				++i;
//			}
//			//这里 对应的不是  空 就是 被删除了
//			_ht[hashi]._val = val;
//			_ht[hashi]._state = EXIST;
//			++_size;
//			++_totalSize;
//			return true;
//		}
//
//		// 查找
//		size_t Find(const K& key)
//		{
//			size_t starti = key;
//			size_t hashi = starti % _ht.size();
//			int i = 1;
//			while (_ht[hashi]._state != EMPTY)
//			{
//				if (_ht[hashi]._state == EXIST
//					&& _ht[hashi]._val.first == key)
//				{
//					return 1;
//				}
//				hashi = starti + i;
//				++i;
//				hashi %= _ht.size(); // 这里是有问题的  假设  3个空间 ,其中 两个有效,一个无效 出问题
//				if (hashi == starti % _ht.size())
//				{
//					return 0;
//				}
//			}
//			return 0;
//		}
//
//		// 删除
//		bool Erase(const K& key)
//		{
//			size_t starti = key;
//			size_t hashi = starti % _ht.size();
//			int i = 1;
//			while (_ht[hashi]._state != EMPTY)
//			{
//				if (_ht[hashi]._state == EXIST
//					&& _ht[hashi]._val.first == key)
//				{
//					_ht[hashi]._state = DELETE;
//					_size--;
//					return true;
//				}
//				hashi = starti + i;
//				++i;
//				hashi %= _ht.size();
//				if (hashi == starti % _ht.size())
//				{
//					return 0;
//				}
//			}
//			return false;
//		}
//
//		size_t Size()const
//		{
//			return _size;
//		}
//
//		bool Empty() const
//		{
//			return _size == 0;
//		}
//
//		void Swap(HashTable<K, T>& ht)
//		{
//			swap(_size, ht._size);
//			swap(_totalSize, ht._totalSize);
//			_ht.swap(ht._ht);
//		}
//	private:
//		vector<Elem> _ht;
//		size_t _size;       // 这个应该是 有效元素
//		size_t _totalSize;  // 哈希表中的所有元素：有效和已删除, 扩容时候要用到
//	};
//	void test1()
//	{
//		HashTable<int, int> hs;
//		hs.Insert(make_pair(1, 1));
//		hs.Insert(make_pair(2, 2));
//		hs.Insert(make_pair(3, 3));
//		hs.Insert(make_pair(11, 11));
//		if (hs.Find(1))
//		{
//			cout << "找到了" << endl;
//		}
//		else
//		{
//			cout << "没找到" << endl;
//        }
//		hs.Erase(1);
//		if (hs.Find(1))
//		{
//			cout << "找到了" << endl;
//		}
//		else
//		{
//			cout << "没找到" << endl;
//		}
//	}
//}
#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;
//开散列  哈希桶
namespace bit
{
	template<class T>
	struct HashNode
	{
		HashNode(const T& data)
			:_data(data)
			,_next(nullptr)
		{}
		HashNode<T>* _next;
		T _data;
	};
	// 先去声明一下
	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable;
	// 分装迭代器
	template<class K, class T, class KeyOfT, class HashFunc>
	class __HTIterator
	{
		typedef HashNode<T> Node;
		typedef __HTIterator<K, T, KeyOfT, HashFunc> Self;
	public:
		__HTIterator(Node* node, HashTable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node)
			,_pht(pht)
		{}
		__HTIterator()
		{}
		Self operator++(int)
		{
			Self ret(*this);
			++(*this);
			return ret;
		}
		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				KeyOfT kot;
				HashFunc hf;
				size_t hashi = hf(kot(_node->_data));
				hashi %= _pht->_tables.size();
				++hashi;
				//找下一个不为空的桶
				for (; hashi < _pht->_tables.size(); ++hashi)
				{
					if (_pht->_tables[hashi])
					{
						_node = _pht->_tables[hashi];
						break;
					}
				}
				// 没有找到不为空的桶，用nullptr去做end标识
				if (hashi == _pht->_tables.size())
				{
					_node = nullptr;
				}
			}
			return *this;
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
		HashTable<K, T, KeyOfT, HashFunc>* _pht;
	};

	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable
	{
		template<class K, class T, class KeyOfT, class HashFunc>
		friend class __HTIterator;
		typedef HashNode<T> Node;
	public:
		typedef __HTIterator<K, T, KeyOfT, HashFunc> iterator;


		iterator begin()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node* cur = _tables[i];
				if (cur)
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


		~HashTable()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
			_n = 0;
		}
		// 有的 人要求表的大小是素数, 这里优化一点  
		// 有人 就打了一个表
		size_t GetNextPrime(size_t prime)
		{
			const int PRIMECOUNT = 28;
			static const size_t primeList[PRIMECOUNT] =
			{
				53ul, 97ul, 193ul, 389ul, 769ul,
				1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
				49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
				1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
				50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
				1610612741ul, 3221225473ul, 4294967291ul
			};

			// 获取比prime大那一个素数
			size_t i = 0;
			for (; i < PRIMECOUNT; ++i)
			{
				if (primeList[i] > prime)
					return primeList[i];
			}
			// 这里 就会异常 算是  保存了 一般是数据 超了 一般 
			return primeList[i];
		}
		pair<iterator,bool> insert(const T& data)
		{
			HashFunc hf;
			KeyOfT kot;
			if (find(kot(data)) != end())
			{
				return make_pair(iterator(nullptr,this),false);
			}
	

			if (_n == _tables.size())
			{
				//size_t newSize = _tables.size() == 0 ? 10 : 2 * _tables.size();
				size_t newSize = GetNextPrime(_tables.size());
				if (_tables.size() == newSize)
				{
					assert(false);
				}
				// 这里我们用 跟家简单的用法
				vector<Node*> newTable;

				newTable.resize(newSize);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t starti = hf(kot(cur->_data));
						starti %= newTable.size();
						cur->_next = newTable[starti];
						newTable[starti] = cur;
						cur = next;
					}
					_tables[i] = nullptr;
				}
				_tables.swap(newTable);
			}
			//算位置
			size_t hashi = hf(kot(data));
			hashi %= _tables.size();

			Node* node = new Node(data);
			
			//头插
			Node* prev = _tables[hashi];
			_tables[hashi] = node;
			node->_next = prev;
			_n++;
			return make_pair(iterator(node, this),true);
		}

		iterator find(const K& key)
		{
			if (_n == 0)
				return iterator(nullptr, this);
			HashFunc hf;
			KeyOfT kot;
			size_t hashi = hf(key);
			hashi %= _tables.size();
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return iterator(cur, this);
				}
				cur = cur->_next;
			}
			return iterator(nullptr, this);
		}
		bool erase(const K& key)
		{
			HashFunc hf;
			KeyOfT kot;

			size_t hashi = hf(key);
			hashi %= _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					// 删除
					Node* node = _tables[hashi];
					cur->_data = node->_data;
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
}


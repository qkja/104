#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
#include <vector>
#include "priority_queue.hpp"
#include "list.hpp"
using namespace std;

int main()
{
	bite::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	bite::list<int>::reverse_iterator rit = l.rbegin();
	while (rit!= l.rend())
	{
		cout << *rit << endl;
		++rit;
	}
	return 0;
}

//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(13);
//	v.push_back(-1);
//
//	sort(v.begin(), v.end(),greater<int>());
//	for (int val : v)
//	{
//		cout << val << " ";
//	}
//	return 0;
//}

struct Goods
{
	string _name;
	double _price;
	size_t _saleNum;
	//...

	/*bool operator<(const Goods& g) const
	{
		return _price < g._price;
	}*/
};

struct LessPrice
{
	bool operator()(const Goods& g1, const Goods& g2) const
	{
		return g1._price < g2._price;
	}
};

struct GreaterPrice
{
	bool operator()(const Goods& g1, const Goods& g2) const
	{
		return g1._price > g2._price;
	}
};

struct LessSaleNum
{
	bool operator()(const Goods& g1, const Goods& g2) const
	{
		return g1._saleNum < g2._saleNum;
	}
};


struct GreaterSaleNum
{
	bool operator()(const Goods& g1, const Goods& g2) const
	{
		return g1._saleNum > g2._saleNum;
	}
};

//int main()
//{
//	Goods gds[4] = { { "苹果", 2.1, 1000}, { "香蕉", 3.0, 200}, { "橙子", 2.2,300}, { "菠萝", 1.5,50} };
//
//	
//	cout << "=======================" << endl;
//	for (int i = 0; i < 4; i++)
//	{
//		cout << gds[i]._name << " price : " << gds[i]._price << " saleNum: " << gds[i]._saleNum << endl;
//
//	}
//	cout << "=======================" << endl;
//
//	sort(gds, gds + 4, LessSaleNum());
//	cout << "=======================" << endl;
//
//	for (int i = 0; i < 4; i++)
//	{
//		cout << gds[i]._name << " price : " << gds[i]._price << " saleNum: " << gds[i]._saleNum << endl;
//
//	}
//	cout << "=======================" << endl;
//
//	sort(gds, gds + 4, GreaterSaleNum());
//	cout << "=======================" << endl;
//
//	for (int i = 0; i < 4; i++)
//	{
//		cout << gds[i]._name << " price : " << gds[i]._price << " saleNum: " << gds[i]._saleNum << endl;
//
//
//	}
//	cout << "=======================" << endl;
//
//	return 0;
//}





















//bool comFare(int x, int y)
//{
//	return x > y;
//}
//int main()
//{
//	//bit::priority_queue<int, vector<int>, bool(*)(int, int)> p(comFare);
//	bit::priority_queue<int> p;
//	p.push(1);
//	p.push(3);
//	p.push(2);
//	p.push(0);
//    p.push(-1);
//	while (!p.empty())
//	{
//		cout << p.top() << " ";
//		p.pop();
//	}
//	return 0;
//}



//
////int main()
////{
////	priority_queue<int,vector<int>, greater<int>> p;
////	p.push(1);
////	p.push(2);
////	p.push(0);
////	p.push(-1);
////	p.push(1100);
////	while (!p.empty())
////	{
////		cout << p.top() << " ";
////		p.pop();
////	}
////	return 0;
////}
//
//
//
//#include <vector>
//#include <iostream>
//#include <assert.h>
//
//namespace bit
//{
//    template<class T>
//    struct less
//    {
//        
//        bool operator()(const T& t1, const T& t2) const
//        {
//            return t1 < t2;
//        }
//    };
//
//    template<class T>
//    struct greater
//    {
//        bool operator()(const T& x, const T& y) const
//        {
//            return x > y;
//        }
//    };
//
//    template<class T, class Container = std::vector<T>, class Compare = less<T>>
//    class priority_queue
//    {
//    public:
//        priority_queue()
//        {
//
//        }
//
//        template <class InputIterator>
//
//        priority_queue(InputIterator first, InputIterator last)
//        {
//            while (first != last)
//            {
//                push(*first);
//                ++first;
//            }
//        }
//        // 建堆
//        void push(const T& x)
//        {
//            _con.push_back(x);
//            adjustUp(_con.size() - 1);
//        }
//
//        void pop()
//        {
//            assert(!_con.empty());
//            std::swap(_con[0], _con[size() - 1]);
//            _con.pop_back();
//            adjustDwon(0);
//        }
//        const T& top()
//        {
//            return _con[0];
//        }
//
//        bool empty()
//        {
//            return _con.empty();
//        }
//        size_t size()
//        {
//            return _con.size();
//        }
//
//    private:
//
//        //大堆 用  小于  
//        //小堆 用  大于
//        void adjustDwon(size_t parent)
//        {
//            Compare comFunc;
//            size_t child = 2 * parent + 1;
//            while (child < size())
//            {
//                if (child +1 < size() && comFunc(_con[child],_con(child + 1)))
//                {
//                    child++;
//                }
//
//                if (com(_con[parent], _con[child]))
//                {
//                    std::swap(_con[parent], _con[child]);
//                    parent = child;
//                    child = 2 * child + 1;
//                }
//                else
//                {
//                    break;
//                }
//            }
//
//        }
//        void adjustUp(int child)
//        {
//            // 先 建大堆
//            Compare comFunc;
//            size_t parent = (child - 1) / 2;
//            while (child > 0)
//            {
//                if (comFunc(_con[parent], _con[child]))
//                {
//                    std::swap(_con[parent], _con[child]);
//                    child = parent;
//                    parent = (child - 1) / 2;
//                }
//                else
//                {
//                    break;
//                }
//            }
//        }
//    private:
//        Container _con;
//    };
//
//}
//
//int main()
//{
//    bit::priority_queue<int> p;
//    p.push(1);
//    p.push(2);
//    p.push(0);
//    p.push(-1);
//    p.push(1100);
//    while (!p.empty())
//    {
//    	cout << p.top() << " ";
//    	p.pop();
//    }
//    return 0;
//}

//int main()
//{
//	bite::list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//	l.push_back(5);
//	l.push_back(6);
//	l.push_back(7);
//	l.push_front(10);
//	
//	bite::list<int>::iterator it = l.begin();
//	cout << l.front() << endl;
//	cout << l.back() << endl;
//	/*while (it != l.end())
//	{
//		cout << *it << endl;
//		it++;
//	}*/
//	return 0;
//}






//int main()
//{
//	::list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(2);
//	l.push_back(4);
//	l.push_back(4);
//	l.push_back(6);
//	l.push_back(7);
//	auto it = l.begin();
//	while (it != l.end())
//	{
//		if (*it % 2 == 0)
//		{
//			l.insert(it, *it * 10);
//		}
//		it++;
//	}
//
//	for (int val : l)
//	{
//		cout << val << " ";
//	}
//
//	return 0;
//}

//void func(const bit::list<int>& l)
//{
//	bit::list<int>::const_iterator it = l.begin();
//	while (it != l.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//}
//int main()
//{
//	bit::list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//	l.push_back(5);
//	l.push_back(6);
//	l.push_back(7);
//
//	func(l);
//
//
//
//	return 0;
//}

//using namespace std;
//
//int main()
//{
//	list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//	l.push_back(5);
//	l.push_back(6);
//	l.push_back(7);
//	l.push_front(10);
//
//	list<int>::const_iterator it = l.begin();
//	while (it != l.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//
//
//
//	return 0;
//}
//int main()
//{
//	::list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(2);
//	l.push_back(4);
//	l.push_back(4);
//	l.push_back(6);
//	l.push_back(7);
//	auto it = l.begin();
//	l.erase(it);
//	
//	*it;
//
//	return 0;
//}

//int main()
//{
//    bit::priority_queue<int> p;
//    p.push(1);
//    p.push(2);
//    p.push(0);
//    p.push(-1);
//    p.push(1100);
//    while (!p.empty())
//    {
//        cout << p.top() << " ";
//        p.pop();
//    }
//    return 0;
//}
//struct MyStruct
//{
//    bool operator()(const int x, const int y)
//    {
//        return x > y;
//    }
//};
//
//int main()
//{
//    MyStruct comfunc;
//    cout << comfunc(1, 2) << endl;
//    return 0;
//}


//#include <stack>
//
//int main()
//{
//	stack<int,vector<int>> s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	s.push(4);
//	while (!s.empty())
//	{
//		cout << s.top() << endl;
//		s.pop();
//	}
//
//	return 0;
//}
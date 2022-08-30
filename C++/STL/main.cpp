#include <iostream>      
#include "list.hpp"

using namespace std;    
//struct A
//{
//  A(int a = 0,int b= 0)
//  {
//    a1 = a;
//    a2 = b;
//  }
//
//  int a1;
//  int a2;
//};
//
//int main()
//{
//  bit::list<A> l;
//  l.push_back(A(1,2));
//  l.push_back(A(1,2));
//  l.push_back(A(1,2));
//  bit::list<A>::iterator it = l.begin();
//  while(it != l.end())
//  {
//    cout << it->a1 <<  " " << it->a2 <<endl;
//    it++;
//  }
//return 0;
//}
//
//



int main()
{
  bit::list<int> l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  l.push_back(4);
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);
  l.push_front(10);
  
  bit::list<int>::iterator it = l.begin();
  while(it != l.end())
  {
   cout <<*it << endl;
   it++;
  }



  return 0;
}
  //bit::list<int>::iterator it = l.begin();
  //while(it != l.end())
  //{
  //
  //  cout << *it << " ";
  //  ++it;
  //}

  //cout << endl;
  //return 0;

//int main()      
//{      
//    bit::Vector<bit::Vector<int>> vv;      
//    bit::Vector<int> v1(10, 1);      
//    bit::Vector<int> v2(10, 2);      
//    bit::Vector<int> v3(10, 3);
//    bit::Vector<int> v4(10, 4);
//    bit::Vector<int> v5(10, 5);
//
//    vv.push_back(v1);
//    vv.push_back(v2);
//    vv.push_back(v3);
//    vv.push_back(v4);
//    vv.push_back(v5);
//    for (bit::Vector<int>& val : vv)    
//    {    
//        for (int e : val)                                                                                         
//        {       
//            cout << e << " ";      
//        }       
//        cout << endl;      
//    }         
//    return 0;      
//}  
//
//
//
//
//
//





/*#include <iostream>
#include "Vector.hpp"

using namespace std;
int main()
{
  bit::Vector<bit::Vector<int>> vv;
  bit::Vector<int> v1(10, 1);
  bit::Vector<int> v2(10, 2);

  vv.push_back(v1);
	vv.push_back(v2);

	for (bit::Vector<int>& val : vv)
	{
		for (int e : val)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	return 0;
}

#include "list.hpp"
#include "stack.hpp"

#include "priority_queue.hpp"
using namespace std;

int main()
{
  bit::priority_queue<int> p;
  p.push(1);
  p.push(3);
  p.push(0);
  p.push(8);
  p.push(7);
  p.push(10);
  p.push(0);
  p.push(-1);
  p.push(3);
  while(!p.empty())
  {
    cout << p.top() << " ";
    p.pop();
  }
  cout << endl;

  return 0;
}


*/

/*int main()
{
  bit::stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  while(!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
  return 0;
}

void func( const bit:: list<int> & l)
{
  bit::list<int>::const_iterator cit = l.begin();
  while(cit != l.end())
  {
    cout << *cit << " ";
    cit++;
  }
  cout << endl;
}

int main()
{
  bit::list<int> l;
  l.push_back(1);
  l.push_back(1);
  l.push_back(1);
  l.push_back(1);

  func(l);
  return 0;
}
int main()
{
  bit::list<int> l;
  l.push_back(1);
  l.push_back(1);
  l.push_back(1);
  l.push_back(1);
  l.push_back(1);
  l.push_back(1);
  l.push_back(1);
  l.push_back(1);
  l.push_back(1);
  l.push_back(1);
  l.push_back(1);


  bit::list<int>::iterator it = l.begin();
  while(it != l.end())
  {
    cout <<*it << " ";
    it++;
  }
  cout << endl;
  return 0;
}
int main()
{
  bit::string s;
  s += 'c';
  s += "abdefr";
  cout << s.c_str() << endl;
  return 0;
}
int main()
{
  bit::string s;
  s.push_back('a');
  s.append("bcdefg");
  cout << s.c_str() << endl;
  return 0;
}
int main()
{
  bit::string s;
  s.insert(0,"aaaaaaaaaabbbbbbb");
  cout << s.c_str() << endl;

  return 0;
}

int main()
{
  bit::string s;
  s.reserve(10);
  cout << "size: " <<s.size() << endl;
  cout << "capacity:" << s.capacity()<< endl;
  s.reserve(1);
  cout << "size: " <<s.size() << endl;
  cout << "capacity:" << s.capacity()<< endl;
  return 0;
}*/

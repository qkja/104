#include <iostream>
#include <list>

using namespace std;

namespace std 
{
  void test_list1()
  {
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);

    auto it = lt.begin();
    while(it != lt.end())
    {
      cout << *it << " ";
      it++;
    }
    cout << endl;
  }

  void test_list2()
  {

  }
}

int main()
{
  std::test_list1();
  return 0;
}

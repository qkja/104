#include <iostream>
using std::cout;
using std::endl;
template<class T>
T add(const T& left, const T& right)
{
	cout << "T add" << endl;
	return left + right;
}

int main()
{
  add(1,2);
  return 0;
}

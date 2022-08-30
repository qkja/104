#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	size_t cap = s.capacity();

  cout << "capacity : " << cap << endl;
	for (int i = 0; i < 100; i++)
	{
		s.push_back('a');
		if(s.capacity() != cap)
		{
			cap = s.capacity();
			cout << "new capacity : " << cap;
			cout << endl;
		}
	}

	return 0;
}

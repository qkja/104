#include <iostream>
class A
{
public:
	A(int a = 0)
		:_a(a)
	{
    std::cout << "sss" <<std::endl;
	}
private:
	int _a;
};

int main()
{
	A* a = (A*)operator new(sizeof(A));

	// 定位 new
	new(a)A (1);
	return 0;
}
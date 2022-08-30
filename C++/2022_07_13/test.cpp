#include <iostream>
using std::cout;
using std::cin;
using std::endl;
class Widget
{
public:
	Widget()
	{

	}
	Widget(const Widget& w)
	{
		cout << "Widget(const Widget& w)" << endl;
	}

private:

};

Widget f(Widget u)
{
	Widget v(u);
	Widget w = v;
	return w;
}

int main()
{
	Widget x;
	Widget y = f(f(x));
	return 0;
}

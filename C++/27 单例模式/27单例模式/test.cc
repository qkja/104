#define _CRT_SECURE_NO_WARNINGS 1

// 只能在堆上开辟
class HeapOnly
{
public:
	static HeapOnly* CreatObj(int a, int b)
	{
		return new HeapOnly(a, b);
	}

private:
	// 构造函数私有

	HeapOnly(int a, int b)
		:_a(a),
		_b(b)
	{}
	HeapOnly()
		:_a(0),
		_b(0)
	{}
	// 同时拷贝构造也需要私有，禁止拷贝创建对象
	HeapOnly(const HeapOnly& h) = delete;
	// 赋值不一定需要delete，因为赋值不能创建新对象
	// HeapOnly& operator=(const HeapOnly& h) = delete;

	int _a;
	int _b;
};

int main()
{
	HeapOnly a;
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

// ֻ���ڶ��Ͽ���
class HeapOnly
{
public:
	static HeapOnly* CreatObj(int a, int b)
	{
		return new HeapOnly(a, b);
	}

private:
	// ���캯��˽��

	HeapOnly(int a, int b)
		:_a(a),
		_b(b)
	{}
	HeapOnly()
		:_a(0),
		_b(0)
	{}
	// ͬʱ��������Ҳ��Ҫ˽�У���ֹ������������
	HeapOnly(const HeapOnly& h) = delete;
	// ��ֵ��һ����Ҫdelete����Ϊ��ֵ���ܴ����¶���
	// HeapOnly& operator=(const HeapOnly& h) = delete;

	int _a;
	int _b;
};

int main()
{
	HeapOnly a;
	return 0;
}
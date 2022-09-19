#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
namespace bit
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			// + 1 保证的足够的 bit位 最多 浪费8个
			_bit.resize(N / 8 + 1, 0);
		}

		void set(size_t x)
		{
			// 把 x 映射的改成 1
			int i = x / 8;
			int j = x % 8;
			_bit[i] = _bit[i] | (1 << j);
		}

		void reset(size_t x)
		{
			// 把 x 映射的改成 0
			int i = x / 8;
			int j = x % 8;

			_bit[i] = _bit[i] & (~(1 << j));
		}

		bool test(size_t x)
		{
			//判断 在不在
			int i = x / 8;
			int j = x % 8;
			return _bit[i] & (1 << j);
		}
	private:
		std::vector<char> _bit;
	};

	void test_bitset1()
	{
		bitset<100> b;
		b.set(19);
		b.set(18);
		b.set(19);
		b.reset(18);
		if (b.test(18))
		{
			std::cout << "找到了" << std::endl;
		}
	}
}
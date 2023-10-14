#include <vector>

class Heap
{
public:
	// �ѵĹ���
	Heap()
	{
		_size = 0;
	}
	Heap(std::vector<int>& v)
		:_v(v), _size(v.size())
	{
		for (int parent = ((_v.size() - 2) / 2); parent >= 0; parent--)
		{
			adjustDown(_v.size(), parent);
		}
	}

	~Heap()
	{
	}

	// �ѵĲ���
	void HeapPush(int x)
	{
		if (_size == _v.size())
		{
			int newSize = _size == 0 ? 4 : 2 * _size;
			_v.resize(newSize);
		}
		_v[_size] = x;
		// ���ϵ���
		_size++;
		adjustUp(_size);
	}
	// �ѵ�ɾ��
	void HeapPop()
	{
		if (HeapEmpty()) return;

		std::swap(_v[0], _v[_size - 1]);

		_size--;

		adjustDown(_size, 0);
	}
	// ȡ�Ѷ�������
	int HeapTop()
	{
		if (HeapEmpty()) return -1;
		return _v[0];
	}
	// �ѵ����ݸ���
	int HeapSize()
	{
		return _size;
	}
	int HeapEmpty()
	{
		return _size == 0;
	}

private:
	void adjustUp(int size)
	{
		int child = size - 1;
		int parent = (child - 1) / 2;
		while (child > 0)
		{
			if (_v[parent] > _v[child]) 
			{
				std::swap(_v[parent], _v[child]);
			}
			else
			{
				break;
			}
			child = parent;
			parent = (child - 1) / 2;
		}
	}
	void adjustDown(int size, size_t root)
	{
		int parent = root;
		int child = 2 * root + 1;// ����
		while (child < size)
		{
			// ����child
			if (child + 1 < size && _v[child + 1] < _v[child])
			{
				child++;
			}

			if (_v[parent] > _v[child])
			{
				std::swap(_v[parent], _v[child]);
			}
			else
			{
				break;
			}
			parent = child;
			child = 2 * parent + 1;
		}
	}
private:

	std::vector<int> _v;
	int _size;
};

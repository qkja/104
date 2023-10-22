#pragma once
#include <vector>
#include <map>
#include <iostream>

// 矩阵的版本
namespace matrix
{
	// V 是顶点
	// W weight 全职
	// Direction:是否是又向的 false 无向的
	template<class V, class W, W MAX_W = INT_MAX, bool Direction = false>
	class Graph
	{
	public:
		// 1. 图的创建 
		// 1.1  一般是IO输入, 但是我们为了要测试,
		// 1.2  关系进入文件
		// 1.3  手动添加和修改
		Graph(const V* a, size_t n)
		{

			_vertexs.reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				_vertexs.push_back(a[i]);
				_indexMap[a[i]] = i;
			}

			_matrix.resize(n);
			for (size_t i = 0; i < _matrix.size(); i++)
			{
				(_matrix[i]).resize(n, MAX_W);
			}
		}
		~Graph()
		{}
	public:
		// 添加边
		void AddEdge(const V& src, const V& dst, const W& w)
		{
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);
			_matrix[srci][dsti] = w;
			if (Direction == false)
			{
				// 无向图也添加
				_matrix[dsti][srci] = w;
			}
		}

		size_t GetVertexIndex(const V& v)	const
		{
			auto iter = _indexMap.find(v);
			if (iter == _indexMap.end())
			{
				throw std::invalid_argument("顶点不存在");
				return -1;  // 防止编译器的检测,出现告警
			}
			return iter->second;
		}
		void BFS(const V& v)
		{

		}
		void Print()const
		{
			// 打印顶点
			for (size_t i = 0; i < _vertexs.size(); i++)
			{
				std::cout << "[" << i << "]->" << _vertexs[i] << std::endl;
			}
			std::cout <<std::endl;
			std::cout << "  ";
			for (size_t i = 0; i < _vertexs.size(); i++)
			{
				std::cout << i << " ";
			}
			std::cout << std::endl;
			
			for (size_t i = 0; i < _matrix.size(); i++)
			{
				std::cout << i << " ";
				for (size_t j = 0; j < _matrix[i].size(); j++)
				{
					//std::cout << _matrix[i][j] << " ";
					if (_matrix[i][j] == MAX_W)
					{
						std::cout << "*" << " ";
					}
					else
					{
						std::cout << _matrix[i][j] << " ";
					}
				}
				std::cout << std::endl;
			}
		}
	private:
		std::vector<V> _vertexs; // 顶点
		std::map<V, int> _indexMap; // 顶点和下标的关系
		std::vector<std::vector<W>> _matrix; // 邻接矩阵
	};

	void TestGraph()
	{
		Graph<char, int, INT_MAX, true> g("0123", 4);
		g.AddEdge('0', '1', 1);
		g.AddEdge('0', '3', 4);
		g.AddEdge('1', '3', 2);
		g.AddEdge('1', '2', 9);
		g.AddEdge('2', '3', 8);
		g.AddEdge('2', '1', 5);
		g.AddEdge('2', '0', 3);
		g.AddEdge('3', '2', 6);
		g.Print();
	}
}
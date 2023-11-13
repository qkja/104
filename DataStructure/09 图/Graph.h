#pragma once
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <functional>
#include "UnionFindSet.hpp"

namespace matrix
{
	using namespace std;

	template <class V, class W, W MAX_W = INT_MAX, bool Direction = false>
	class Graph
	{
		typedef Graph<V, W, MAX_W, Direction> Self;

	public:
		Graph() = default;
		Graph(const V *a, size_t n)
		{
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				_vertexs.push_back(a[i]);
				_indexMap[a[i]] = i;
			}
			_matrix.resize(n, std::vector<W>(n, MAX_W));
		}

	public:
		// 深度遍历
		void DFS(const V &src)
		{
			size_t srci = GetVertexIndex(src);
			std::vector<bool> visited(_vertexs.size(), false);
			_DFS(srci, visited);
		}
		// 宽度遍历
		void BFS(const V &src)
		{
			size_t srci = GetVertexIndex(src);
			std::vector<bool> visited(_vertexs.size(), false);
			std::queue<size_t> q;
			q.push(srci);
			visited[srci] = true;
			while (!q.empty())
			{
				int len = q.size();
				while (len--)
				{
					size_t front = q.front();
					q.pop();
					std::cout << front << " : " << _vertexs[front] << " ";
					for (size_t i = 0; i < _matrix[front].size(); ++i)
					{
						if (_matrix[front][i] != MAX_W && visited[i] == false)
						{
							q.push(i);
							visited[i] = true;
						}
					}
				}
				std::cout << std::endl;
			}
		}
		struct Edge
		{
			size_t _srci;
			size_t _dsti;
			W _w;
			Edge(size_t srci, size_t dsti, const W &w)
				: _srci(srci), _dsti(dsti), _w(w)
			{
			}
			bool operator>(const Edge &e2) const
			{
				return _w > e2._w;
			}
		};


		// 最小生成树Kruskal算法
		W Kruskal(Self &minTree)
		{
			// 最小生成树
			minTree._vertexs = _vertexs;
			minTree._indexMap = _indexMap;
			minTree._matrix.resize(_vertexs.size(), std::vector<W>(_vertexs.size(), MAX_W));
			std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> minq;
			size_t n = _vertexs.size();
			for (size_t i = 0; i < n; ++i)
			{
				for (size_t j = 0; j < n; ++j)
				{
					if (i < j && _matrix[i][j] != MAX_W)
					{
						minq.push(Edge(i, j, _matrix[i][j]));
					}
				}
			}
			int size = 0;
			W totalW = W();
			UnionFindSet ufs(n);
			while (!minq.empty())
			{
				Edge min = minq.top();
				minq.pop();
				if (ufs.InSet(min._srci, min._dsti) == false)
				{
					std::cout << _vertexs[min._srci] << "->" << _vertexs[min._dsti] << ":" << min._w << std::endl;
					minTree._AddEdge(min._srci, min._dsti, min._w);
					ufs.Union(min._srci, min._dsti);
					++size;
					totalW += min._w;
				}
				else
				{
					// std::cout << _vertexs[min._srci] << "->" <<_vertexs[min._dsti] << ":" << min._w << std::endl;
					//std::cout << "成环了" << std::endl;
				}
			}
			if (size != n - 1)
			{
				return W();
			}
			return totalW;
		}


		// 最小生成树Prim 算法
		W Prim(Self &minTree, const V &src)
		{
			// 最小生成树
			size_t n = _vertexs.size();
			minTree._vertexs = _vertexs;
			minTree._indexMap = _indexMap;
			minTree._matrix.resize(n, std::vector<W>(n, MAX_W));

			size_t srci = GetVertexIndex(src);

			std::vector<bool> X(n, false);
			std::vector<bool> Y(n, true);
			X[srci] = true;
			Y[srci] = false;

			std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> minq;
			for (size_t i = 0; i < n; ++i)
			{
				if (_matrix[srci][i] != MAX_W)minq.push(Edge(srci, i, _matrix[srci][i]));
			}

			size_t count = 0;
			W totalW = W();
			while (!minq.empty())
			{
				Edge min = minq.top();
				minq.pop();
				// 如何判环, 本质上是从  srci 中开始选
				if (X[min._dsti])
				{
					std::cout << "构成环了  ";
					std::cout << _vertexs[min._srci] << " -> " << _vertexs[min._dsti] << ":" << min._w << std::endl;
				}
				else
				{
					minTree._AddEdge(min._srci, min._dsti, min._w);
					X[min._dsti] = true;
					Y[min._dsti] = false;

					std::cout << _vertexs[min._srci] << " -> " << _vertexs[min._dsti] << ":" << min._w << std::endl;
					++count;
					totalW += min._w;
					if (count == n - 1)
						break;
					for (size_t i = 0; i < n; ++i)
					{
						if (_matrix[min._dsti][i] != MAX_W && Y[i])minq.push(Edge(min._dsti, i, _matrix[min._dsti][i]));
					}
				}
			} // end of while

			if (count != n - 1)
				return W();
			return totalW;
		}

		size_t GetVertexIndex(const V &v)
		{
			auto iter = _indexMap.find(v);
			if (iter == _indexMap.end())
			{
				throw std::invalid_argument("不存在的顶点");
				return -1;
			}
			return iter->second;
		}
		// 添加边
		void AddEdge(const V &src, const V &dst, const W &w)
		{
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);
			_AddEdge(srci, dsti, w);
		}

		bool BellmanFord(const V& src, std::vector<W>& dist, std::vector<int>& parentPath)
		{
			size_t srci = GetVertexIndex(src);
			size_t n = _vertexs.size();
			dist.resize(n, MAX_W);
			parentPath.resize(n, -1);
			// 先更新srci->srci为最小值
			dist[srci] = W();
			parentPath[srci] = 0;

			for (size_t k = 0; k < n; ++k)
			{ 
				bool upDate = false;
				std::cout<<"更新第 "  << k << std::endl;
				//std::cout << << k << "21" << std::endl;
				for (size_t i = 0; i < n; ++i)
				{
					for (size_t j = 0; j < n; ++j)
					{
						if (_matrix[i][j] != MAX_W && dist[i] + _matrix[i][j] < dist[j])
						{
							std::cout << _vertexs[i] << " -> " << _vertexs[j] << ":" << _matrix[i][j] << std::endl;
							upDate = true;
							dist[j] = dist[i] + _matrix[i][j];
							parentPath[j] = i;
						}
					}
				}

				if (false == upDate)
				{
					break;
				}
			}
			for (size_t i = 0; i < n; ++i)
			{
				for (size_t j = 0; j < n; ++j)
				{
					if (_matrix[i][j] != MAX_W && dist[i] + _matrix[i][j] < dist[j])
						return false;
				}
			}

			return true;
		}

		void Dijkstra(const V& src, std::vector<W>& dist, std::vector<int>& pPath)
		{
			size_t srci = GetVertexIndex(src);
			size_t n = _vertexs.size();
			dist.resize(n, MAX_W);
			pPath.resize(n, -1);
			dist[srci] = 0;
			pPath[srci] = 0;

			std::vector<bool> S(n, false); // 已经确定的最短路径的集合, 可以理解是和Q的合体
			for (size_t i = 0; i < n; i++)
			{
				// 每一次从 Q中选取一个 到 srci最小的
				size_t u = 0;
				W min = MAX_W;
				for (size_t j = 0; j < n; j++)
				{
					if (S[j] == false && dist[j] < min)
					{
						u = j;
						min = dist[j];
					}
				}

				// 将这个给  S
				S[u] = true;
				// 开始我们的松弛

				for (size_t v = 0; v < n; v++)
				{
					// 我们已经规定了  进入S的不能选了
					if ( S[v] == false 
						&& _matrix[u][v] != MAX_W 
						&& dist[u] + _matrix[u][v] < dist[v])
					{
						dist[v] = dist[u] + _matrix[u][v];
						pPath[v] = u;
					}
				}
			}
		}
		// 下面说一下我们可以解决带负权的算法
		// 下面是暴力更新
		// 他是找中止边，
		bool BellmanFord(const V& src, std::vector<W>& dist, std::vector<int>& pPath)
		{
			size_t srci = GetVertexIndex(src);
			size_t n = _vertexs.size();
			dist.resize(n, MAX_W);
			pPath.resize(n, -1);
			// 这里是自己到自己
			dist[srci] = W();
			for (size_t i = 0; i < n; i++)
			{
				for (size_t j = 0; j < n; j++)
				{
					if (_matrix[i][j] != MAX_W && dist[i] + _matrix[i][j] < dist[j])
					{

					}
				}
			}

		}



		void PrintShotPath(const V& src, std::vector<W>& dist, std::vector<int>& pPath)
		{
			size_t srci = GetVertexIndex(src);
			size_t n = _vertexs.size();
			for (size_t i = 0; i < n; ++i)
			{

				std::vector<int> path;
				path.push_back(i);
				int parent = pPath[i];
				while (parent != srci)
				{
					path.push_back(parent);
					parent = pPath[parent];
				}
				path.push_back(parent);
				std::reverse(path.begin(), path.end());

				// 打印
				for (auto e : path)
				{
					std::cout << _vertexs[e] << "->";
				}
				std::cout << dist[i] << std::endl;
			}
		}

		void FloydWarShall(vector<vector<W>>& vvDist, vector<vector<int>>&
			vvParentPath)
		{
			size_t N = _vertexs.size();
			vvDist.resize(N);
			vvParentPath.resize(N);
			// 初始化权值和路径矩阵
			for (size_t i = 0; i < N; ++i)
			{
				vvDist[i].resize(N, MAX_W);
				vvParentPath[i].resize(N, -1);
			}
			for (size_t i = 0; i < N; ++i)
			{
				for (size_t j = 0; j < N; ++j)
				{
					if (_matrix[i][j] != MAX_W)
					{
						vvDist[i][j] = _matrix[i][j];
						vvParentPath[i][j] = i;
					}
					else
					{
						vvParentPath[i][j] = -1;
					}
					if (i == j)
					{
						vvDist[i][j] = 0;
						vvParentPath[i][j] = -1;
					}
				}
			}
		}
		void Print()
		{
			size_t n = _vertexs.size();
			for (size_t i = 0; i < n; ++i)
			{
				std::cout << i << " -> [ " << _vertexs[i] << " ]" << std::endl;
			}
			std::cout << std::endl;

			std::cout << "  ";
			for (size_t i = 0; i < n; ++i)
				printf("%4d", i);
			std::cout << std::endl;
			for (size_t i = 0; i < n; ++i)
			{
				std::cout << i << " ";
				for (size_t j = 0; j < n; ++j)
				{
					if (_matrix[i][j] == MAX_W)
					{
						printf("%4c", '*');
					}
					else
					{
						printf("%4d", _matrix[i][j]);
					}
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}

	private:
		void _AddEdge(size_t srci, size_t dsti, const W &w)
		{
			_matrix[srci][dsti] = w;
			if (Direction == false)
				_matrix[dsti][srci] = w;
		}
		void _DFS(size_t root, std::vector<bool> &visited)
		{
			std::cout << root << " : " << _vertexs[root] << std::endl;
			visited[root] = true;
			for (size_t i = 0; i < _matrix[root].size(); ++i)
			{
				if (_matrix[root][i] != MAX_W && visited[i] == false)
				{
					_DFS(i, visited);
				}
			}
		}

	private:
		std::vector<V> _vertexs;
		std::map<V, int> _indexMap;
		std::vector<std::vector<W>> _matrix;
	};

	void TestGraphBellmanFord()
	{
		/*const char* str = "syztx";
		Graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.AddEdge('s', 't', 6);
		g.AddEdge('s', 'y', 7);
		g.AddEdge('y', 'z', 9);
		g.AddEdge('y', 'x', -3);
		g.AddEdge('z', 's', 2);
		g.AddEdge('z', 'x', 7);
		g.AddEdge('t', 'x', 5);
		g.AddEdge('t', 'y', 8);
		g.AddEdge('t', 'z', -4);
		g.AddEdge('x', 't', -2);
		vector<int> dist;
		vector<int> parentPath;
		g.BellmanFord('s', dist, parentPath);
		g.PrintShotPath('s', dist, parentPath);*/

		// 微调图结构，带有负权回路的测试
		const char* str = "syztx";
		Graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.AddEdge('s', 't', 6);
		g.AddEdge('s', 'y', 7);
		g.AddEdge('y', 'x', -3);
		g.AddEdge('y', 'z', 9);
		g.AddEdge('y', 'x', -3);
		g.AddEdge('y', 's', 1); // 新增
		g.AddEdge('z', 's', 2);
		g.AddEdge('z', 'x', 7);
		g.AddEdge('t', 'x', 5);
		g.AddEdge('t', 'y', -8); // 更改
		g.AddEdge('t', 'z', -4);
		g.AddEdge('x', 't', -2);
		vector<int> dist;
		vector<int> parentPath;
		g.BellmanFord('s', dist, parentPath);
		g.PrintShotPath('s', dist, parentPath);
	}
	void TestGraphDijkstra()
	{
		const char* str = "sytx";
		Graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.AddEdge('s', 't', 10);
		g.AddEdge('s', 'y', 5);
		g.AddEdge('t', 'y', -7);
		g.AddEdge('y', 'x', 3);
		std::vector<int> dist;
		std::vector<int> parentPath;
		g.Dijkstra('s', dist, parentPath);
		g.PrintShotPath('s', dist, parentPath);
	}


	void TestGraphMinTree()
	{
		const char *str = "abcdefghi";
		Graph<char, int> g(str, strlen(str));
		g.AddEdge('a', 'b', 4);
		g.AddEdge('a', 'h', 8);
		// g.AddEdge('a', 'h', 9);
		g.AddEdge('b', 'c', 8);
		g.AddEdge('b', 'h', 11);
		g.AddEdge('c', 'i', 2);
		g.AddEdge('c', 'f', 4);
		g.AddEdge('c', 'd', 7);
		g.AddEdge('d', 'f', 14);
		g.AddEdge('d', 'e', 9);
		g.AddEdge('e', 'f', 10);
		g.AddEdge('f', 'g', 2);
		g.AddEdge('g', 'h', 1);
		g.AddEdge('g', 'i', 6);
		g.AddEdge('h', 'i', 7);

		Graph<char, int> kminTree;
		std::cout << "Kruskal:" << std::endl;
		g.Kruskal(kminTree);
		kminTree.Print();
		Graph<char, int> pminTree;
		std::cout << "Prim:" << g.Prim(pminTree, 'a') << std::endl;
		pminTree.Print();
	}

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


	void TestGraphDBFS()
	{
		std::string a[] = { "张三", "李四", "王五", "赵六", "周七" };
		Graph<std::string, int> g1(a, sizeof(a) / sizeof(std::string));

		g1.AddEdge("张三", "李四", 100);
		g1.AddEdge("张三", "王五", 200);
		g1.AddEdge("王五", "赵六", 30);
		g1.AddEdge("王五", "周七", 30);

		// g1.Print();
		// g1.BFS("张三");
		g1.DFS("张三");
	}
}

namespace link_table
{
	template <class W>
	struct Edge
	{
		// int srci;
		int _dsti; // 目标点的下标
		W _w;      // 权值
		struct Edge *_next;
		Edge(int dsti, const W &w)
			: _dsti(dsti), _w(w), _next(nullptr)
		{
		}
	};

	template <class V, class W, bool Direction = false>
	class Graph
	{
	public:
		typedef struct Edge<W> Edge;
		Graph(const V *a, size_t n)
		{
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				_vertexs.push_back(a[i]);
				_indexMap[a[i]] = i;
			}
			_table.resize(n, nullptr);
		}

	public:
		size_t GetVertexIndex(const V &v)
		{
			auto iter = _indexMap.find(v);
			if (iter == _indexMap.end())
			{
				throw std::invalid_argument("不存在的顶点");
				return -1;
			}
			return iter->second;
		}
		// 添加边
		void AddEdge(const V &src, const V &dst, const W &w)
		{
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);

			Edge *eg = new Edge(dsti, w);
			eg->_next = _table[srci];
			_table[srci] = eg;

			if (Direction == false)
			{
				Edge *eg2 = new Edge(srci, w);
				eg2->_next = _table[dsti];
				_table[dsti] = eg2;
			}
		}
		void Print()
		{
			size_t n = _vertexs.size();
			for (size_t i = 0; i < n; ++i)
			{
				std::cout << i << " -> [ " << _vertexs[i] << " ]" << std::endl;
			}
			std::cout << std::endl;
			for (size_t i = 0; i < _table.size(); ++i)
			{
				std::cout << _vertexs[i] << "[ " << i << " ]-> ";
				Edge *cur = _table[i];
				while (cur)
				{
					std::cout << "[ " << _vertexs[cur->_dsti] << ":" << cur->_dsti << " ] -> ";
					cur = cur->_next;
				}
				std::cout << "nullptr" << std::endl;
				;
			}
		}

	private:
		std::vector<V> _vertexs;
		std::map<V, int> _indexMap;
		std::vector<Edge *> _table;
	};
	void TestGraph()
	{
		std::string a[] = { "张三", "李四", "王五", "赵六" };
		Graph<std::string, int, true> g1(a, 4);
		g1.AddEdge("张三", "李四", 100);
		g1.AddEdge("张三", "王五", 200);
		g1.AddEdge("王五", "赵六", 30);
		g1.Print();
	}
}
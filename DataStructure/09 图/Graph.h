#pragma once
#include <vector>
#include <map>
#include <limits.h>
#include <iostream>

namespace matrix
{
  template <class V, class W, W MAX_W = INT_MAX, bool Direction = false>
  class Graph
  {
  public:
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
    size_t GetVertexIndex(const V &v)
    {
      auto iter = _indexMap.find(v);
      if (iter == _indexMap.end())
      {
        throw std::invalid_argument("顶点不存在");
        return -1;
      }
      return iter->second;
    }
    // 添加边
    void AddEdge(const V &src, const V &dst, const W &w)
    {
      size_t srci = GetVertexIndex(src);
      size_t dsti = GetVertexIndex(dst);
      _matrix[srci][dsti] = w;
      if (Direction == false)
        _matrix[dsti][srci] = w;
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
      {
        std::cout << i << " "; 
      }
      std::cout << std::endl;
      for (size_t i = 0; i < n; ++i)
      {
       
        std::cout << i << " "; 
        for (size_t j = 0; j < n; ++j)
        {
          //std::cout << _matrix[i][j] << " ";
          if(_matrix[i][j] == MAX_W)
          {
            printf("* ");
          }
          else 
          {
            printf("%d ", _matrix[i][j]);
          }
        }
        std::cout << std::endl;
      }
      std::cout << std::endl;
    }

  private:
    std::vector<V> _vertexs;
    std::map<V, int> _indexMap;
    std::vector<std::vector<W>> _matrix;
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

// #include <map>
// #include <vector>
// #include <limits.h>
// #include <iostream>
//
//// ����İ汾
// namespace matrix
//{
//	// V �Ƕ���
//	// W weight ȫְ
//	// Direction:�Ƿ�������� false �����
//	template<class V, class W, W MAX_W = INT_MAX, bool Direction = false>
//	class Graph
//	{
//	public:
//		// 1. ͼ�Ĵ���
//		// 1.1  һ����IO����, ��������Ϊ��Ҫ����,
//		// 1.2  ��ϵ�����ļ�
//		// 1.3  �ֶ����Ӻ��޸�
//		Graph(const V* a, size_t n)
//		{
//
//			_vertexs.reserve(n);
//			for (size_t i = 0; i < n; i++)
//			{
//				_vertexs.push_back(a[i]);
//				_indexMap[a[i]] = i;
//			}
//
//			_matrix.resize(n);
//			for (size_t i = 0; i < _matrix.size(); i++)
//			{
//				(_matrix[i]).resize(n, MAX_W);
//			}
//		}
//		~Graph()
//		{}
//	public:
//		// ���ӱ�
//		void AddEdge(const V& src, const V& dst, const W& w)
//		{
//			size_t srci = GetVertexIndex(src);
//			size_t dsti = GetVertexIndex(dst);
//			_matrix[srci][dsti] = w;
//			if (Direction == false)
//			{
//				// ����ͼҲ����
//				_matrix[dsti][srci] = w;
//			}
//		}
//
//		size_t GetVertexIndex(const V& v)	const
//		{
//			auto iter = _indexMap.find(v);
//			if (iter == _indexMap.end())
//			{
//				throw std::invalid_argument("���㲻����");
//				return -1;  // ��ֹ�������ļ��,���ָ澯
//			}
//			return iter->second;
//		}
//		void BFS(const V& v)
//		{
//
//		}
//		void Print()const
//		{
//			// ��ӡ����
//			for (size_t i = 0; i < _vertexs.size(); i++)
//			{
//				std::cout << "[" << i << "]->" << _vertexs[i] << std::endl;
//			}
//			std::cout <<std::endl;
//			std::cout << "  ";
//			for (size_t i = 0; i < _vertexs.size(); i++)
//			{
//				std::cout << i << " ";
//			}
//			std::cout << std::endl;
//
//			for (size_t i = 0; i < _matrix.size(); i++)
//			{
//				std::cout << i << " ";
//				for (size_t j = 0; j < _matrix[i].size(); j++)
//				{
//					//std::cout << _matrix[i][j] << " ";
//					if (_matrix[i][j] == MAX_W)
//					{
//						std::cout << "*" << " ";
//					}
//					else
//					{
//						std::cout << _matrix[i][j] << " ";
//					}
//				}
//				std::cout << std::endl;
//			}
//		}
//	private:
//		std::vector<V> _vertexs; // ����
//		std::map<V, int> _indexMap; // ������±�Ĺ�ϵ
//		std::vector<std::vector<W>> _matrix; // �ڽӾ���
//	};
//
//	void TestGraph()
//	{
//		Graph<char, int, INT_MAX, true> g("0123", 4);
//		g.AddEdge('0', '1', 1);
//		g.AddEdge('0', '3', 4);
//		g.AddEdge('1', '3', 2);
//		g.AddEdge('1', '2', 9);
//		g.AddEdge('2', '3', 8);
//		g.AddEdge('2', '1', 5);
//		g.AddEdge('2', '0', 3);
//		g.AddEdge('3', '2', 6);
//		g.Print();
//	}
// }

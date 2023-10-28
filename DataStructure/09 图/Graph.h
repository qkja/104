#pragma once
#include <map>
#include <vector>
#include <string>
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
        //throw std::invalid_argument("顶点不存在");
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


namespace link_table
{
    template <class W>
    struct Edge
    {
        //int srci;
        int _dsti; // 目标点的下标 
        W _w;     // 权值
        struct Edge* _next;
        Edge(int dsti, const W& w)
            :_dsti(dsti)
            , _w(w)
            , _next(nullptr)
        {

        }

    };

    template <class V, class W, bool Direction = false>
    class Graph
    {
    public:
        typedef  Edge<W> Edge;
        Graph(const V* a, size_t n)
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
        size_t GetVertexIndex(const V& v)
        {
            auto iter = _indexMap.find(v);
            if (iter == _indexMap.end())
            {
                //throw std::invalid_argument("顶点不存在");
                return -1;
            }
            return iter->second;
        }
        // 添加边
        void AddEdge(const V& src, const V& dst, const W& w)
        {
            size_t srci = GetVertexIndex(src);
            size_t dsti = GetVertexIndex(dst);

            Edge* eg = new Edge(dsti, w);
            eg->_next = _table[srci];
            _table[srci] = eg;

            if (Direction == false)
            {
                Edge* eg2 = new Edge(srci, w);
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
                Edge* cur = _table[i];
                while (cur)
                {
                    std::cout << "[ " <<_vertexs[cur->_dsti] <<":" << cur->_dsti << " ] -> ";
                    cur = cur->_next;
                }
                std::cout << "bullptr" << std::endl;;
            }
           
        }

    private:
        std::vector<V> _vertexs;
        std::map<V, int> _indexMap;
        std::vector<Edge*> _table;
    };
    void TestGraph()
    {
        std::string a[] = { "张三", "李四", "王五", "赵六" };
        Graph< std::string, int, true> g1(a, 4);
        g1.AddEdge("张三", "李四", 100);
        g1.AddEdge("张三", "王五", 200);
        g1.AddEdge("王五", "赵六", 30);
        g1.Print();
    }
}

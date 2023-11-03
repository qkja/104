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
      // while(!q.empty())
      //{
      //   size_t front = q.front();
      //   q.pop();
      //   std::cout << front << " : " << _vertexs[front] << std::endl;
      //   // 把他的临界顶点入队列
      //   for(size_t i = 0; i < _matrix[front].size(); ++i)
      //   {
      //     if(_matrix[front][i] != MAX_W && visited[i] == false)
      //     {
      //       q.push(i);
      //       visited[i] = true;
      //     }
      //   }
      // }

      // 这里顺便添加一层的遍历
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
          // std::cout << _vertexs[min._srci] << "->" <<_vertexs[min._dsti] << ":" << min._w << std::endl;
          minTree._AddEdge(min._srci, min._dsti, min._w);
          ufs.Union(min._srci, min._dsti);
          ++size;
          totalW += min._w;
        }
        else
        {
          // std::cout << _vertexs[min._srci] << "->" <<_vertexs[min._dsti] << ":" << min._w << std::endl;
          std::cout << "成环了" << std::endl;
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
      int n = _vertexs.size();
      minTree._vertexs = _vertexs;
      minTree._indexMap = _indexMap;
      minTree._matrix.resize(n, std::vector<W>(n, MAX_W));

      size_t srci = GetVertexIndex(src);

      std::set<size_t> X;
      std::set<size_t> Y;
      X.insert(srci);
      for (size_t i = 0; i < n; ++i)
      {
          if (i == srci)
              continue;
          Y.insert(i);
      }

      //  此时 X和Y已经是两个集合了
      // 下面 是 X-> Y集合中链接的边中选择最小的边


      //for (size_t i = 0; i < n; i++)
      //{
      //  if (i != srci)
      //    Y.insert(i);
      //}

      //// 开始选边
      //std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> minq;
      //for(size_t i = 0; i < n; i++)
      //{
      //  if(_matrix[srci][i] != MAX_W)
      //  {
      //    minq.push(Edge(srci, i,_matrix[srci][i] ));
      //  }
      //}
    }




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
      _AddEdge(srci, dsti, w);
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
    // Graph<char, int> pminTree;
    // std::cout << "Prim:" << g.Prim(pminTree, 'a') << std::endl;
    // pminTree.Print();
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
    std::string a[] = {"张三", "李四", "王五", "赵六", "周七"};
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
    std::string a[] = {"张三", "李四", "王五", "赵六"};
    Graph<std::string, int, true> g1(a, 4);
    g1.AddEdge("张三", "李四", 100);
    g1.AddEdge("张三", "王五", 200);
    g1.AddEdge("王五", "赵六", 30);
    g1.Print();
  }
}

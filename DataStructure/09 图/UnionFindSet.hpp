#pragma once
#include <map>
#include <vector>
class UnionFindSet
{
public:
  UnionFindSet(size_t n)
      : _ufs(n, -1)
  {
  }

public:
  // 1. 合并两个元素
  void Union(int x1, int x2)
  {
    int root1 = FindRoot(x1);
    int root2 = FindRoot(x2);
    if (root1 == root2)
      return;

    if (std::abs(_ufs[root1]) < std::abs(_ufs[root2]))
      std::swap(root1, root2);

    _ufs[root1] += _ufs[root2];
    _ufs[root2] = root1;
  }
  // 3.判断两个元素是不是在一个集合
  bool InSet(int x1, int x2)
  {
    return FindRoot(x1) == FindRoot(x2);
  }
  // 4. 判断集合的个数
  size_t SetSize()
  {
    size_t ret = 0;
    for (const auto &e : _ufs)
    {
      if (e < 0)
        ++ret;
    }
    return ret;
  }

private:
  // 2. 查找一个元素的根
  int FindRoot(int x)
  {
    // if(x < 0 || s >= _ufs.size())
    int root = x;
    while (_ufs[root] >= 0)
    {
      root = _ufs[root];
    }
    // 这里可以在在查找的时候缩短下路径
    while (_ufs[x] >= 0)
    {
      int parent = _ufs[x]; // 保存一下父亲节点
      _ufs[x] = root;
      x = parent;
    }
    return root;
  }

private:
  std::vector<int> _ufs;
};

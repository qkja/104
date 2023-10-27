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
    // 1.1 找根
    // 1.2 判断根是不是在一个集合
    // 1.3 合并
    int root1 = FindRoot(x1);
    int root2 = FindRoot(x2);
    if (root1 == root2)
      return;

    // 两个几个加起来
    // _ufs[root1] += _ufs[root2];
    // 更新父节点
    // _ufs[root2] = root1;
    // 合并两个元素的时候尽量缩短下路径
    // 两个集合是是谁想谁合并
    // 这里希望数据量小的往大的集合合并
    if(std::abs(_ufs[root1])  < std::abs(_ufs[root2]))
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
    while(_ufs[x] >= 0)
    {
      int parent = _ufs[x];// 保存一下父亲节点
      _ufs[x] = root;
      x = parent;
    }
    return root;
  }

private:
  std::vector<int> _ufs;
};

// template<class T>
// class UnionFindSet
//{
//   public:
//     UnionFindSet(const T* a, size_t n)
//     {
//       for(size_t i = 0; i < n; ++i)
//       {
//         _a.push_back(a[i]);
//         _indexMap[a[i]] = i;
//       }
//     }
//   private:
//     std::vector<T> _a;          // 编号找人
//     std::map<T, int> _indexMap; // 人找编号
// };
//  #pragma once
//  #include <map>
//  #include <string>
//  #include <vector>
//  using namespace std;
// template <class T>
// class UnionFindSet
//{
// public:
//	UnionFindSet(const T* a, size_t n)
//	{
//		for (int i = 0; i < n; ++i)
//		{
//			_a.push_back(a[i]);
//			_indexMap[a[i]] = i; // �����ظ����Ȳ�����
//		}
//	}
//	~UnionFindSet()
//	{
//
//	}
//
// private:
//	vector<T> _a;
//	map<T, int> _indexMap;
// };

// template <class T>
// class UnionFindSet
// {
// public:
// 	UnionFindSet(size_t n)
// 		:_ufs(n, -1)
// 	{

// 	}
// 	~UnionFindSet()
// 	{

// 	}
// public:
// 	// �ϲ�
// 	void Union(int x1, int x2)
// 	{
// 		int root1 = findRoot(x1);
// 		int root2 = findRoot(x2);
// 		if (root1 == root2)
// 			return;
// 		_ufs[root1] += _ufs[root2];
// 		_ufs[root2] = root1;
// 	}

// 	// �Ҹ�
// 	int findRoot(int x)
// 	{
// 		int parent = x;
// 		while (_ufs[parent] >= 0)
// 		{
// 			parent = _ufs[parent];
// 		}
// 		return parent;
// 	}

// 	bool InSet(int x, int y)
// 	{
// 		return findRoot(x) == findRoot(y);
// 	}
// 	size_t size()
// 	{
// 		int result = 0;
// 		for (int i = 0; i < _ufs.size(); ++i)
// 		{
// 			if (_ufs[i] < 0) ++result;
// 		}
// 		return result;
// 	}
// private:
// 	vector<T> _ufs;
// };
// https://leetcode.cn/problems/bLyHh0/submissions/
// class Solution
// {
//   class UnionFindSet
//   {
//   public:
//     UnionFindSet(size_t n)
//         : _ufs(n, -1)
//     {
//     }

//   public:
//     // 1. 合并两个元素
//     void Union(int x1, int x2)
//     {
//       // 1.1 找根
//       // 1.2 判断根是不是在一个集合
//       // 1.3 合并
//       int root1 = FindRoot(x1);
//       int root2 = FindRoot(x2);
//       if (root1 == root2)
//         return;

//       // 两个几个加起来
//       _ufs[root1] += _ufs[root2];
//       // 更新父节点
//       _ufs[root2] = root1;
//     }
//     // 3.判断两个元素是不是在一个集合
//     bool InSet(int x1, int x2)
//     {
//       return FindRoot(x1) == FindRoot(x2);
//     }
//     // 4. 判断集合的个数
//     size_t SetSize()
//     {
//       size_t ret = 0;
//       for (const auto &e : _ufs)
//       {
//         if (e < 0)
//           ++ret;
//       }
//       return ret;
//     }

//   private:
//     // 2. 查找一个元素的根
//     int FindRoot(int x)
//     {
//       // if(x < 0 || s >= _ufs.size())
//       int parent = x;
//       while (_ufs[parent] >= 0)
//       {
//         parent = _ufs[parent];
//       }
//       return parent;
//     }

//   private:
//     std::vector<int> _ufs;
//   };

// public:
//   int findCircleNum(vector<vector<int>> &isConnected)
//   {
//     int n = isConnected.size();
//     UnionFindSet ufs(n);
//     for(int i = 0; i < n; i++)
//     {
//       for(int j = 0; j < n; ++j)
//       {
//         if(isConnected[i][j] == 1)
//         {
//           ufs.Union(i, j);
//         }
//       }
//     }
//     return ufs.SetSize();
//   }
// };
//#include <vector>
//#include <string>
//using namespace std;
//
//class Solution
//{
//public:
//  bool equationsPossible(vector<string> &equations)
//  {
//    vector<int> ufs(26, -1);
//    auto findRoot = [&ufs](int x)
//    {
//      while (ufs[x] >= 0)
//      {
//        x = ufs[x];
//      }
//      return x;
//    };
//    // 把相等的值放在一个集合中
//    for (auto &str : equations)
//    {
//      if (str[1] == '=')
//      {
//        int root1 = findRoot(str[0] - 'a');
//        int root2 = findRoot(str[3] - 'a');
//        if (root1 != root2)
//        {
//          ufs[root1] += ufs[root2];
//          ufs[root2] = root1;
//        }
//      }
//    }
//    for (auto &str : equations)
//    {
//      if (str[1] == '!')
//      {
//        int root1 = findRoot(str[0] - 'a');
//        int root2 = findRoot(str[3] - 'a');
//        if (root1 == root2)
//        {
//          return false;
//        }
//      }
//    }
//    return true;
//  }
//};

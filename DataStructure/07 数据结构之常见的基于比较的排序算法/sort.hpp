#ifndef __SORT_HPP__
#define __SORT_HPP__
#include <vector>

// 1. 插入排序

// 直接插入排序的思想是  我们找到一个待排序的数组,在有序空间内从右向左第一个比他小的数据,否则就把他交换
bool InsertionSort(std::vector<int> &v)
{
  if (v.empty())
    return true;
  for (int i = 1; i < v.size(); i++)
  {
    int val = v[i];
    int j = i - 1;
    while (j >= 0)
    {
      if (v[j] > val)
        v[j + 1] = v[j];
      else
        break;
      j--;
    }
    v[j + 1] = val;
  }
  return true;
}

// 下面开始分析   空间 1 时间复杂度 好 n, 坏  n^2
// 如何优化   -- > 折半查找 --> 二分查找 --> 这里不写了

// 2. 选择排序: 从无序的空间内找到一个最小的值,放在有序空间
bool SelectSort(std::vector<int> &v)
{
  if (v.empty())
    return true;
  for (size_t i = 0; i < v.size(); i++)
  {
    for (size_t j = i + 1; j < v.size(); j++)
    {
      if (v[j] < v[i])
        std::swap(v[j], v[i]);
    }
  }
  return true;
}

// 分析   不稳定  空间 1 时间 好坏都是n2
// 3. 希尔排序: 是插入排序的优化,我们发现数据有序的时候这里接近 1
// 那么我们来实现分组
void shell(std::vector<int> &v, int k)
{
  for (int i = k; i < v.size(); i++)
  {
    int val = v[i];
    int j = i - k;
    while (j >= 0)
    {
      if (v[j] > val)
      {
        v[j + k] = v[j];
      }
      else
      {
        break;
      }
      j -= k;
    }
    v[j + k] = val;
  }
}

bool ShellSort(std::vector<int> &v)
{
  if (v.empty())
    return true;
  int k = v.size();
  while (k > 1)
  {
    k = k / 3 + 1;
    shell(v, k);
  }

  return true;
}

// 分析  实践 1.3-1.5  空间  1 不稳定

// 4. 冒泡排序
bool BubbleSort(std::vector<int> &v)
{
  if (v.empty())
    return true;
  for (size_t i = 0; i < v.size() - 1; i++)
  {
    for (size_t j = 1; j < v.size() - i; j++)
    {
      if (v[j - 1] > v[j])
        std::swap(v[j - 1], v[j]);
    }
  }
  return true;
}

// 分析  空间  1实践  n2 稳定

// 5. 堆排序
void adjustDown(std::vector<int> &v, int parent, int size)
{
  int child = 2 * parent + 1;
  while (child < size)
  {
    if (child + 1 < size && v[child + 1] > v[child])
    {
      child++;
    }
    if (v[child] >= v[parent])
    {
      // 交换
      std::swap(v[child], v[parent]);
    }
    else
    {
      break;
    }
    parent = child;
    child = 2 * parent + 1;
  }
}

bool Heapsort(std::vector<int> &v)
{
  if (v.empty())
    return true;

  // 建立堆
  for (int parent = (v.size() - 1 - 1) / 2; parent >= 0; parent--)
  {
    adjustDown(v, parent, v.size());
  }

  // 进行排序--> 把所有的
  for (int i = 0; i < v.size() - 1; i++)
  {
    std::swap(v[0], v[v.size() - 1 - i]);
    adjustDown(v, 0, v.size() - i - 1);
  }
  return true;
}

// 6. 快速排序
// 那么什么是快速排序,很简单,我们每一次选择一个数字,使得我们左侧的数不必比他大,右侧的数据不必不它小
// 让后依次递归下去

// 如何选择
// 霍尔法
int PartSort1(std::vector<int> &v, int left, int right)
{
  // 选左为key
  int keyi = left;
  int key = v[left];
  while (left < right)
  {
    // 右先走
    while (left < right && v[right] > key)
    {
      right--;
    }

    while (left < right && v[left] <= key)
    {
      left++;
    }
    // 注意,这里一定不会越界
    std::swap(v[left], v[right]);
  }
  std::swap(v[keyi], v[left]);
  return left;
}

int PartSort2(std::vector<int> &v, int left, int right)
{
  // 选右做key
  int keyi = right;
  int key = v[keyi];
  while (left < right)
  {
    // 左先走

    while (left < right && v[left] <= key)
    {
      left++;
    }
    while (left < right && v[right] >= key)
    {
      right--;
    }

    // 注意,这里一定不会越界
    std::swap(v[left], v[right]);
  }
  std::swap(v[keyi], v[left]);
  return left;
}
// 挖坑法 那么什么是挖坑法
// 选左作为 key,被选的地方形成一个坑位,此时右侧继续找 比 key小的,找到后填坑,自己形成坑位,
// 此时左侧继续开始找比key大的,找到后填坑

int PartSort3(std::vector<int> &v, int left, int right)
{
  int hoti = left;
  int key = v[left];
  while (left < right)
  {
    while (left < right && v[right] >= key)
    {
      right--;
    }
    v[hoti] = v[right];
    hoti = right;
    while (left < right && v[left] <= key)
    {
      left++;
    }
    v[hoti] = v[left];
    hoti = left;
  }
  v[hoti] = key;
  return left;
}

// 前后指针法
// cur 如果比 key小,prev 走一个,让后交换
// 比key大,直接走
int PartSort4(std::vector<int> &v, int left, int right)
{
  int key = left;
  int prev = left;
  for (int cur = left + 1; cur <= right; cur++)
  {
    // 注意,我们
    if (v[cur] < v[key] && v[++prev] != v[cur])
      std::swap(v[prev], v[cur]);
  }

  std::swap(v[prev], v[key]);
  return prev;
}
int GetMidIndex(std::vector<int> &v, int left, int right)
{
  int mid = (left + right) / 2; // 这里就不妨溢出了
  if (v[left] < v[mid])
  {
    if (v[mid] < v[right])
    {
      return mid;
    }
    else
    {
      //  m r l
      if (v[left] > v[right])
      {
        return left;
      }
      else
      {
        return right;
      }
    }
  }
  else
  {
    // left  mid
    if (v[mid] > v[right])
    {
      return mid;
    }
    else
    {
      // l > m
      if (v[left] > v[right])
        return right;
      else
        return left;
    }
  }
}

int PartSort5(std::vector<int> &v, int left, int right)
{
  int midi = GetMidIndex(v, left, right);
  std::swap(v[midi], v[left]);
  int key = left;
  int prev = left;
  for (int cur = left + 1; cur <= right; cur++)
  {
    // 注意,我们
    if (v[cur] < v[key] && v[++prev] != v[cur])
      std::swap(v[prev], v[cur]);
  }

  std::swap(v[prev], v[key]);
  return prev;
}

void QuickSort(std::vector<int> &v, int left, int right)
{
  if (left >= right)
    return;
  // int keyi = PartSort1(v, left, right);
  // int keyi = PartSort2(v, left, right);
  // int keyi = PartSort3(v, left, right);
  // int keyi = PartSort4(v, left, right);
  int keyi = PartSort5(v, left, right);
  QuickSort(v, left, keyi - 1);
  QuickSort(v, keyi + 1, right);
}
void QuickSort2(std::vector<int> &v, int left, int right)
{
  if (left >= right)
    return;
  // if(right - left < 10)
  // {
  //   // 去插入排序把
  //   // z这里由于我们再插入的时候没有使用指针,不太好直接调用,记住就可以了
  //   return;
  // }
  int keyi = PartSort5(v, left, right);
  QuickSort2(v, left, keyi - 1);
  QuickSort2(v, keyi + 1, right);
}

bool QuickSort(std::vector<int> &v)
{
  if (v.empty())
    return true;
  QuickSort(v, 0, v.size() - 1);
  return true;
}

// 快排是要优化的,这里我们有两个
// 选key值优化   随机选 --> 三数取中--> 选择三个数不是最大也不是最小的
// 选好后,直接给左或者右
// 小区间优化

// 快排改成非递归





// 7. 归并排序

#endif
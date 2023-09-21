#include <iostream>
#include <vector>

using namespace std;

vector<int> result;
void is_min(vector<int> &help)
{
  if (result.empty())
  {
    result = help;
    return;
  }
  for (int i = 0; i < result.size(); i++)
  {
    if (result[i] < help[i])
    {
      result = help;
      return;
    }
  }
}
void func(const vector<int> &v, int index, vector<int> &help)
{
  if (index == v.size())
  {
    is_min(help);
    return;
  }

  for (int i = index; i < v.size(); i++)
  {
    help.push_back(v[i]);
    func(v, i + 1, help);
    help.pop_back();
  }
}
int main()
{
  int n = 0;
  vector<int> v(n, 0);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> v[i];
  vector<int> help;
  func(v, 0, help);
  for (auto &e : result)
    cout << e << " ";
  cout << endl;
  return 0;
}

// 64 位输出请用 printf("%lld")
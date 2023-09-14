#include <vector>
using std::vector;

class Solution {
public:
    void dfs(vector<int>& a, vector<int>& b, vector<int>& c, int n)
    {
        if (1 == n)
        {
            c.push_back(a.back());
            a.pop_back();
            return;
        }
        dfs(a, c, b, n - 1);
        c.push_back(a.back());
        a.pop_back();
        dfs(b, a, c, n - 1);
    }
    void hanota(vector<int>& a, vector<int>& b, vector<int>& c) {
        dfs(a, b, c, a.size());
    }
};
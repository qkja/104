/**
 * User: Qkj
 * Description:
 * Date: 2023-05-25
 * Time: 21:28
 */
#include <vector>
#include <iostream>
using namespace std;
// https://www.nowcoder.com/practice/72a99e28381a407991f2c96d8cb238ab?tpId=49&&tqId=29305&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
// class Bonus
// {
// public:
//   // 在(x,y) 前往右小角我们的拿到礼物的最大
//   int process(int x, int y, int row, int col, vector<vector<int>> &board)
//   {
//     if (x == row)
//       return 0;
//     if (y == col)
//       return 0;
//     if (x == row - 1 && y == col - 1)
//     {
//       return board[x][y];
//     }

//     int p1 = process(x + 1, y, row, col, board);
//     int p2 = process(x, y + 1, row, col, board);
//     return board[x][y] + std::max(p1, p2);
//   }

//   int getMost(vector<vector<int>> board)
//   {
//     // write code here
//     if (board.empty())
//       return 0;
//     int row = board.size();
//     int col = board[0].size();

//     std::vector<std::vector<int>> dp(row + 1, std::vector<int>(col + 1, 0));
//     // 初始化
//     for (int i = 1; i <= row; i++)
//     {
//       for (int j = 1; j <= col; j++)
//       {
//         dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + board[i - 1][j - 1];
//       }
//     }
//     return dp[row][col];
//   }
// };

// https://www.nowcoder.com/practice/cf24906056f4488c9ddb132f317e03bc?tpId=37&&tqId=21266&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
// #include <vector>
// #include <iostream>
// using namespace std;
// vector<vector<int>> vv = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // 上 下 左 右
// void backtraing(vector<vector<int>>& v, vector<std::pair<int, int>>& result,
//     vector<std::pair<int, int>>& path, int x, int y,
//     vector<vector<bool>>& falg)
// {
//     // 收集结果

//     if (x == v.size() - 1 && y == v.back().size() - 1 && v[x][y] == 0)
//     {
//         path.push_back({ x, y });
//         for (auto& e : path)
//         {
//             result.push_back(e);
//         }
//         return;
//     }

//     if (v[x][y] == 1)
//         return;

//     for (int i = 0; i < 4; i++)
//     {
//         // 先把 数据如进去
//         path.push_back({ x, y });
//         falg[x][y] = true;
//         int xx = x + vv[i][0];
//         int yy = y + vv[i][1];
//         if (xx >= 0 && xx < v.size() && yy >= 0 && yy < v.back().size()
//             && falg[xx][yy] == false)
//         {
 
//             backtraing(v, result, path, xx, yy, falg);
//         }
//         path.pop_back();
//     }
// }
// int main()
// {
//     int n = 0; // 列
//     int m = 0; // 行
//     cin >> n >> m;
//     vector<vector<int>> v(n, vector<int>(m, 0));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> v[i][j];
//         }
//     }
//     vector<std::pair<int, int>> result;
//     vector<std::pair<int, int>> path;
//     vector<vector<bool>> falg(n, vector<bool>(m, false));
//     backtraing(v, result, path, 0, 0, falg);
//     for (auto& e : result)
//     {
//         cout << "(" << e.first << "," << e.second << ")" << endl;
//     }
//     return 0;
// }

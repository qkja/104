/**
 * User: Qkj
 * Description: 路径问题
 * Date: 2023-05-24
 * Time: 18:58
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
class Solution
{
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon)
  {
    int m = dungeon.size(), n = dungeon[0].size();
    // 建表 + 初始化
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[m][n - 1] = dp[m - 1][n] = 1;
    // 填表
    for (int i = m - 1; i >= 0; i--)
      for (int j = n - 1; j >= 0; j--)
      {
        dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
        dp[i][j] = max(1, dp[i][j]);
      }
    // 返回结果
    return dp[0][0];
  }
};

// class Solution
// {
// public:
//   int minPathSum(vector<vector<int>> &grid)
//   {
//     int n = grid.size();
//     int m = grid.back().size();
//     std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, INT_MAX));
//     dp[0][1] = 0;
//     for (size_t i = 1; i <= n; i++)
//     {
//       for (size_t j = 1; j <= m; j++)
//       {
//         dp[i][j] = std::min(dp[i][j - 1], dp[i - 1][j]) + grid[i - 1][j - 1];
//       }
//     }
//     return dp[n][m];
//   }
// };

// class Solution
// {
// public:
//   int minFallingPathSum(vector<vector<int>> &matrix)
//   {
//     int n = matrix.size();
//     int m = matrix.back().size();
//     std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(m + 2,INT_MAX));
//     for (size_t i = 0; i <= m; i++)
//     {
//       dp[0][i] = 0;
//     }
//     for (size_t i = 1; i <= n; i++)
//     {
//       for (size_t j = 1; j <= m; j++)
//       {
//         dp[i][j] = (long long)(std::min(dp[i - 1][j], std::min(dp[i - 1][j + 1], dp[i - 1][j - 1])) + (long long)matrix[i - 1][j - 1]);
//       }
//     }
//     long long minVal = dp[n][0];
//     for (size_t i = 1; i <= m; i++)
//     {
//       minVal = std::min(minVal, dp[n][i]);
//     }
//     return minVal;
//   }
// };
// class Solution
// {
// public:
//   int maxValue(vector<vector<int>> &grid)
//   {
//     int n = grid.size();
//     int m = grid.back().size();
//     std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
//     for (size_t i = 1; i <= n; i++)
//     {
//       for (size_t j = 1; j <= m; j++)
//       {

//         dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
//       }
//     }
//     return dp[n][m];
//   }
// };
// class Solution
// {
// public:
//   int maxValue(vector<vector<int>> &grid)
//   {
//     int n = grid.size();
//     int m = grid.size();
//     std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
//     for (size_t i = 1; i <= n; i++)
//     {
//       for (size_t j = 1; j <= m; j++)
//       {

//         dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
//       }
//     }
//     return dp[n][m];
//   }
// };
// class Solution
// {
// public:
//   int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
//   {
//     // 参数判断
//     obstacleGrid = {{0, 0}};
//     int n = obstacleGrid.size();
//     int m = obstacleGrid.back().size();
//     std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
//     std::cout << n + 1 << " " << m + 1 << std::endl;
//     dp[0][1] = 1;

//     for (size_t i = 1; i <= n; i++)
//     {
//       for (size_t j = 1; j <= m; j++)
//       {
//         if (obstacleGrid[i - 1][j - 1] == 0)
//         {
//           dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//           std::cout << i << " " << j << std::endl;
//         }
//       }
//     }
//     return dp[n][m];
//   }
// };

// int main()
// {
//   vector<vector<int>> obstacleGrid;
//   Solution().uniquePathsWithObstacles(obstacleGrid);
//   return 0;
// }
// class Solution
// {
// public:
//   int uniquePaths(int m, int n)
//   {
//     // 参数检测
//     std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
//     dp[0][1] = 1;
//     for (size_t i = 1; i <= m; i++)
//     {
//       for (size_t j = 1; j <= n; j++)
//       {
//         dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//       }
//     }

//     return dp[m][n];
//   }
// };
// #include <vector>
// #include <algorithm>
// #include <iostream>

// using namespace std;
// https://leetcode.cn/problems/dungeon-game/
// class Solution
// {
// public:
//   int process1(int x, int y, int row, int col, vector<vector<int>> &grid)
//   {
//     if (x == row || y == col)
//       return INT32_MAX;
//     if (x == row - 1 && y == col - 1)
//     {
//       return std::max(1 - grid[x][y], 1);
//     }

//     int p1 = process1(x + 1, y, row, col, grid);
//     int p2 = process1(x, y + 1, row, col, grid);

//     return std::max(std::min(p1, p2) - grid[x][y], 1);
//   }

//   int process2(vector<vector<int>> &grid)
//   {
//     int row = grid.size();
//     int col = grid.back().size();
//     vector<vector<int>> dp(row + 1, vector<int>(col + 1, INT32_MAX));
//     dp[row - 1][col - 1] = std::max((1 - grid[row - 1][col - 1]) % INT32_MAX, 1);
//     for (int i = row - 1; i >= 0; i--)
//     {
//       for (int j = col - 1; j >= 0; j--)
//       {
//         if (i == row - 1 && j == col - 1)
//           continue;
//         dp[i][j] = std::max((std::min(dp[i + 1][j], dp[i][j + 1]) - grid[i][j]) % INT32_MAX, 1);
//       }
//     }
//     return dp[0][0];
//   }

//   int calculateMinimumHP(vector<vector<int>> &grid)
//   {
//     // 假设都是负数,我们应该求的是最大的路径和
//     if (grid.empty())
//       return 0;
//     int row = grid.size();
//     int col = grid.back().size();
//     // return process1(0, 0, row, col, grid);
//     return process2(grid);
//   }
// };
// // https://leetcode.cn/problems/minimum-path-sum/submissions/
// class Solution
// {
// public:
//   int process1(int x, int y, int row, int col, vector<vector<int>> &grid)
//   {
//     if (x == row || col == y)
//       return INT32_MAX;
//     if (x == row - 1 && y == col - 1)
//       return grid[x][y];
//     int p1 = process1(x + 1, y, row, col, grid);
//     int p2 = process1(x, y + 1, row, col, grid);
//     return grid[x][y] + std::min(p1, p2);
//   }
//   int process2(vector<vector<int>> &grid)
//   {
//     int row = grid.size();
//     int col = grid.back().size();
//     vector<vector<int>> dp(row + 1, vector<int>(col + 1, INT32_MAX));
//     dp[row - 1][col - 1] = grid[row - 1][col - 1];
//     for (int i = row - 1; i >= 0; i--)
//     {
//       for (int j = col - 1; j >= 0; j--)
//       {
//         if (i == row - 1 && j == col - 1)
//           continue;
//         dp[i][j] = std::min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
//       }
//     }
//     return dp[0][0];
//   }
//   int process3(vector<vector<int>> &grid)
//   {
//     int row = grid.size();
//     int col = grid.back().size();
//     // 一某一个位置为结尾
//     vector<vector<int>> dp(row + 1, vector<int>(col + 1, INT32_MAX));

//     // 初始化
//     dp[0][1] = 0;
//     for (size_t i = 1; i <= row; i++)
//     {
//       for (size_t j = 1; j <= col; j++)
//       {
//         dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
//       }
//     }
//     return dp[row][col];
//   }
//   int minPathSum(vector<vector<int>> &grid)
//   {
//     if (grid.empty())
//       return 0;
//     int row = grid.size();
//     int col = grid.back().size();
//     // return process1(0, 0, row, col, grid);
//     // return process2(grid);
//     return process3(grid);
//   }
// };
// https://leetcode.cn/problems/minimum-falling-path-sum/

// class Solution
// {
// public:
//   int process(int x, int y, int row, int col, const vector<vector<int>> &matrix)
//   {

//     if (y < 0 || y == col)
//       return INT32_MAX;

//     if (x == row - 1)
//       return matrix[x][y];

//     int p1 = process(x + 1, y, row, col, matrix);
//     int p2 = process(x + 1, y - 1, row, col, matrix);
//     int p3 = process(x + 1, y + 1, row, col, matrix);

//     return matrix[x][y] + std::min(p1, std::min(p2, p3)) % INT32_MAX;
//     ;
//   }
//   int process2(const vector<vector<int>> &matrix)
//   {

//     int row = matrix.size();
//     int col = matrix.back().size();
//     vector<vector<int>> dp(row + 1, vector<int>(col + 1 + 1, INT32_MAX));
//     for (int i = row - 1; i >= 0; i--)
//     {
//       for (int j = 1; j <= col; j++)
//       {
//         dp[i][j] = std::min(dp[i + 1][j], std::min(dp[i + 1][j - 1], dp[i + 1][j + 1])) % INT32_MAX + matrix[i][j - 1];
//       }
//     }
//     int result = dp[0][1];
//     for (int i = 2; i <= col; i++)
//     {
//       result = std::min(result, dp[0][i]);
//     }
//     return result;
//   }

//   int process3(const vector<vector<int>> &matrix)
//   {
//     int row = matrix.size();
//     int col = matrix.back().size();
//     vector<vector<int>> dp(row + 1, vector<int>(col + 2, INT32_MAX));
//     // 初始化
//     for (int i = 0; i < col + 2; i++)
//     {
//       dp[0][i] = 0;
//     }

//     // 填表
//     for (int i = 1; i <= row; i++)
//     {
//       for (int j = 1; j <= col; j++)
//       {
//         dp[i][j] =std::min(dp[i - 1][j], std::min(dp[i - 1][j - 1], dp[i - 1][j + 1])) % INT32_MAX + matrix[i-1][j - 1];
//       }
//     }
//     int result = dp[row][1];
//     for (int i = 2; i <= col; i++)
//     {
//       result = std::min(result, dp[row][i]);
//     }
//     return result;
//   }

//   int minFallingPathSum(vector<vector<int>> &matrix)
//   {
//     if (matrix.empty())
//       return 0;

//     // return process2(matrix);
//     return process3(matrix);
//   }
// int minFallingPathSum(vector<vector<int>> &matrix)
// {
//   if (matrix.empty())
//     return 0;
//   int row = matrix.size();
//   int col = matrix.back().size();
//   int num = INT32_MAX;
//   for (int i = 0; i < col; i++)
//   {
//     int ret = process(0, i, row, col, matrix);
//     // cout<< ret << endl;
//     if (ret < num)
//       num = ret;
//   }
//   return num;
// }
// };

// https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/
// class Solution {
// public:
//  int process1(int x, int y, int row, int col, const vector<vector<int>>& grid)
//  {
//    if(x == row)
//      return 0;
//    if(y == col)
//      return 0;
//    if(x == row-1 && y == col-1)
//      return grid[x][y];
//    int p1 = process1(x+1, y, row, col, grid);
//    int p2 = process1(x, y+1, row, col, grid);
//    return grid[x][y] + std::max(p1, p2);
//  }
//
//  int process2(const vector<vector<int>>& grid)
//  {
//    int row = grid.size();
//    int col = grid.back().size();
//    vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
//    dp[row-1][col-1] = grid[row-1][col-1];
//    for(int i = row-1; i >= 0; i--)
//    {
//      for(int j = col-1; j >= 0; j--)
//      {
//        if(i == row-1 && j == col-1)
//          continue;
//        dp[i][j] = std::max(dp[i+1][j], dp[i][j+1]) + grid[i][j];
//      }
//    }
//    return dp[0][0];
//  }
//  int process3(const vector<vector<int>>& grid)
//  {
//    // 状态定义
//    // 以dpp[i][j]为结尾,我们礼物的最大的价值
//    // 状态方程
//    // dp[i][j] = max(dp[i-1[j], dp[i][j]) + giedp[i][j]
//    // 初始化
//    // 填表顺序
//    // 返回值
//    int row = grid.size();
//    int col = grid.back().size();
//    vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
//    for(int i = 1; i <= row; i++)
//    {
//      for(int j = 1; j <= col; j++)
//      {
//        dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
//      }
//    }
//    return dp[row][col];
//  }
//
//  int maxValue(vector<vector<int>>& grid) {
//      if(grid.empty())
//        return 0;
//      return process2(grid);
//    }
//};

// https://leetcode.cn/problems/unique-paths-ii/

// class Solution
// {
// public:
//   // 在[row][col]处走,到达最下方我们的路径个数
//   int process(int row, int col, int rowLen, int colLen, vector<vector<int>> &obstacleGrid)
//   {
//     if (row == rowLen && col == colLen && obstacleGrid[row][col] == 0)
//       return 1; // 路径是对的
//     if (row > rowLen || col > colLen)
//       return 0;

//     // 这里我们走正常的
//     if (obstacleGrid[row][col] == 1)
//     {
//       return 0; // 表明此路不通
//     }
//     // 向下走
//     int p1 = process(row + 1, col, rowLen, colLen, obstacleGrid);
//     // 向右走
//     int p2 = process(row, col + 1, rowLen, colLen, obstacleGrid);
//     return p1 + p2;
//   }
//   // row [0, n] col [0, m]
//   long long process2(const vector<vector<int>> &obstacleGrid)
//   {
//     int n = obstacleGrid.size();
//     int m = obstacleGrid[0].size();
//     std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(m + 1));

//     // 初始化
//     if (obstacleGrid[n - 1][m - 1] == 0)
//       dp[n - 1][m - 1] = 1;
//     else
//       dp[n - 1][m - 1] = 0;
//     for (int i = n - 1; i >= 0; i--)
//     {
//       for (int j = m - 1; j >= 0; j--)
//       {
//         if (i == n - 1 && j == m - 1)
//           continue;
//         if (obstacleGrid[i][j] == 0)
//           dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
//       }
//     }
//     return dp[0][0];
//   }

//   int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
//   {
//     if (obstacleGrid.empty())
//       return 0;
//     int m = obstacleGrid.size();
//     int n = obstacleGrid[0].size();
//     if (m <= 0 || n <= 0)
//       return 0;
//     std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
//     // 初始化
//     dp[0][1] = 1;
//     for (int i = 1; i < m + 1; i++)
//     {
//       for (int j = 1; j < n + 1; j++)
//       {
//         if (obstacleGrid[i - 1][j - 1] == 0)
//           dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//       }
//     }
//     return dp[m][n];
//     // return process2(obstacleGrid);
//     // int row = obstacleGrid.size();
//     // int col = obstacleGrid[0].size();
//     // return process(0, 0, row - 1, col - 1, obstacleGrid);
//   }
// };

// https://leetcode.cn/problems/unique-paths/
// class Solution
// {
// public:
//   int uniquePaths(int m, int n)
//   {
// if (m <= 0 || n <= 0)
//   return 0;
// std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
// // 初始化
// dp[0][1] = 1;
// for (int i = 1; i < m + 1; i++)
// {
//   for (int j = 1; j < n + 1; j++)
//   {
//     dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//   }
// }
// return dp[m][n];
//   }
// };

// class Solution {
// public:
//     // 这是一个尝试,startx, starty 是我们当前所在的位置
//     //  aimx, aimy 是我们的目标
//     // 返回值是我们的路径数
//     int process1(int startx, int starty, int aimx, int aimy)
//     {
//         if (startx > aimx)
//             return 0;
//         if (starty > aimy)
//             return 0;
//         if (startx == aimx && starty == aimy)
//             return 1;
//         int p1 = process1(startx + 1, starty, aimx, aimy);
//         int p2 = process1(startx, starty+1, aimx, aimy);
//         return p1 + p2;
//     }
//     // startx[0, m] starty[0, n]
//     int process2(int m, int n)
//     {
//         std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
//         dp[m-1][n-1] = 1;
//         for (int i = m-1; i >= 0; i--)
//         {
//             for (int j = n-1; j >= 0; j--)
//             {
//                 if (i == m-1 && j == n-1)
//                     continue;
//                 dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
//             }
//         }
//         return dp[0][0];
//     }
//     int uniquePaths(int m, int n) {
//         //return process1(0, 0, m - 1, n - 1);
//         return process2(m,n);
//     }
// };

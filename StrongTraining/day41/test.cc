// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;
// const int N = 20;

// int arr[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
// int func(vector<string> &v, char ch, int x, int y, int arr[])
// {
//     // 上下

//     // 左右
//     // 左下
//     // 右上

//     int count = -1;

//     while (x >= 0 && y >= 0 && x < N && y < N)
//     {
//         if (v[x][y] == ch)
//         {
//             count++;
//             x += arr[0];
//             y += arr[1];
//         }
//         else
//         {
//             break;
//         }
//     }
//     return count;
// }
// string solve(vector<string> &v)
// {
//     for (int i = 0; i < (int)v.size(); i++)
//     {
//         for (int j = 0; j < (int)v[i].size(); j++)
//         {
//             if (v[i][j] != '.')
//             {
//                 // 这里开始了
//                 int k = 0;
//                 // 上下
//                 k = func(v, v[i][j], i, j, arr[0]) + func(v, v[i][j], i, j, arr[1]);
//                 if (k >= 4)
//                 {
//                     return "Yes";
//                 }
//                 // 左右
//                 k = func(v, v[i][j], i, j, arr[2]) + func(v, v[i][j], i, j, arr[3]);
//                 if (k >= 4)
//                 {
//                     return "Yes";
//                 }
//                 k = func(v, v[i][j], i, j, arr[4]) + func(v, v[i][j], i, j, arr[5]);
//                 if (k >= 4)
//                 {
//                     return "Yes";
//                 }
//                 k = func(v, v[i][j], i, j, arr[6]) + func(v, v[i][j], i, j, arr[7]);
//                 if (k >= 4)
//                 {
//                     return "Yes";
//                 }
//             }
//         }
//     }
//     return "No";
// }
// int main()
// {

//     vector<string> v(N);
//     while (cin >> v[0])
//     {
//         for (int i = 1; i < N; i++)
//         {
//             cin >> v[i];
//         }
//         cout << solve(v) << endl;
//     }
//     return 0;
// }
// 64 位输出请用 printf("%lld")

#include <iostream>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n = 0;
    const string op = "+-*/";
    stack<int> s;
    while (cin >> n)
    {
        string str;
        for (int i = 0; i < n; i++)
        {
            cin >> str;
            if (op.find(str) != std::string::npos)
            {
                // 这是操作
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                int result = 0;
                switch (str[0])
                {
                case '+':
                    result = left + right;
                    break;
                case '-':
                    result = left - right;
                    break;
                case '*':
                    result = left * right;
                    break;
                case '/':
                    result = left / right;
                    break;
                default:
                    break;
                }
                s.push(result);
            }
            else
            {
                s.push(stoi(str));
            }
        }
        cout << s.top() << endl;
        s.pop();
    }
}
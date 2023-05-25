/**
 * User: Qkj
 * Description: 
 * Date: 2023-05-24
 * Time: 22:38
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;
// https://www.nowcoder.com/practice/3959837097c7413a961a135d7104c314?tpId=37&&tqId=21275&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

// 这个递归函数的意思是从 x
int process(int x, int y, std::string& src, std::string& desc)
{
  if(x == src.size())
    return desc.size() - y;
  if(y == desc.size())
    return src.size() - x;
  if(src[x] == desc[y])
    return process(x+1, y+1, src, desc);
  else{
    // 如果不相等
    int a = process(x+1, y+1, src, desc) + 1; // 直接替换
    int b = process(x, y+1, src, desc) + 1;
    int c = process(x+1, y, src, desc) + 1;
    return std::min(a,std::min(b,c));
  }
}
// x[0, src.size()]
// y[0, desc.size()]
int process2(std::string& src, std::string& desc)
{
  int n = src.size();
  int m = desc.size();
  std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));

  // 初始化
  for(int i = 0; i <= m; i++)
  {
    dp[n][i] = m-i;
  }
  for(int i = 0; i<=n; i++)
  {
    dp[i][m] = n-i;
  }

  for(int i = n-1; i>=0;i--)
  {
    for(int j = m-1; j>=0;j--)
    {
      if(src[i] == desc[j])
      {
        dp[i][j] = dp[i+1][j+1];
      }
      else 
      {
        dp[i][j] = std::min(dp[i+1][j+1], std::min(dp[i+1][j], dp[i][j+1])) +1;
      }
    }
  }

  return dp[0][0];
}
int main()
{
  std::string str1;
  std::string str2;
  std::getline(std::cin, str1);
  std::getline(std::cin, str2);
  std::cout << process2(str1, str2) << endl;
  //std::cout << process(0, 0, str1, str2) << endl;
  return 0;
}



// https://www.nowcoder.com/practice/fbcf95ed620f42a88be24eb2cd57ec54?tpId=49&&tqId=29311&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
//class Gift {
//public:
//    int getValue(vector<int> gifts, int n) {
//        // write code here
//        if(gifts.empty())
//          return 0;
//        int falg = gifts[0];
//        int count = 1;
//        for(std::size_t i = 1; i < gifts.size(); i++)
//        {
//          if(count == 0)
//          {
//            falg = gifts[i];
//            count++;
//            continue;
//          }
//          if(falg == gifts[i])
//            count++;
//          else
//            count--;
//        }
//        count = 0;
//        for(std::size_t i = 0; i < gifts.size(); i++)
//        {
//          if(falg == gifts[i])
//            count++;
//        }
//        if(count > n/2)
//          return falg;
//        else 
//          return 0;
//    }
//};

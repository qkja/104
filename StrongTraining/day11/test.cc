/**
 * User: Qkj
 * Description: 
 * Date: 2023-06-03
 * Time: 17:33
 */
#include <iostream>
#include <string>
using namespace std;




class LCA {
  public:
    int getLCA(int a, int b) {
      // write code here
      if(a <= 0 || b <=0)
        return -1;
      int minNum = min(a,b);
      int maxNum = max(a, b);
      while(minNum != 1 &&maxNum!=1)
      {
        maxNum = maxNum /2;
        if(maxNum == minNum)
        {
          return minNum;
        }
        if (maxNum < minNum)
          swap(minNum, maxNum); 
      }
      return 1 ;

    }
};

int main()
{
  std::cout << LCA().getLCA(8,9) << std::endl;
  return 0;
}

//day 11

////连续bit数
//int binaryContinuousOne(int n)
//{
//    int count = 0;
//    int maxCount = 0;
//    // 求二进制
//    for (int i = 0; i < 32; i++)
//    {
//        if ((n >> i & 1) == 1)
//        {
//            count++;
//        }
//        else
//        {
//            if (count > maxCount)
//            {
//                maxCount = count;
//            }
//            count = 0;
//        }
//    }
//    return maxCount;
//}
//int main() 
//{
//    int n = 0;
//    while (cin >> n) 
//    { 
//        cout << binaryContinuousOne(n) << endl;
//    }
//    return 0;
//}

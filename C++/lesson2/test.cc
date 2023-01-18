/**
* User: Qkj
* Description: 
* Date: 2023-01-18
* Time: 11:48
*/
#include <iostream>
using namespace std;
void output(int x){
  cout << x << endl;
}
void output(float x){
  cout << x << endl;
}

int main()
{
  // 由于 数据是不知道我们如和在底层进行截断
  //
  output(0.5);
  return 0;
}

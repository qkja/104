#include <iostream>
#include <string>
#include <vector>
// 1. 头文件
#include <sw/redis++/redis++.h> // sw是啥意思,作者名字的缩写,以后精良不要使用缩写,容易误会

int main()
{

  // 2. 创建一个对象
  sw::redis::Redis redis("tcp://127.0.0.1:6379"); // 需要知道地址和port,就是和一个url

  // 3. 使用ping操作, 然客户端给服务器发送一个ping操作,服务器返回内容
  std::string result = redis.ping();
  std::cout << result << std::endl;
  // 4. 使用makfile编译文件
  return 0;
}
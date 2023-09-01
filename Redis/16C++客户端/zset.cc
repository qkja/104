#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <set>
#include <cerrno>
#include <sw/redis++/redis++.h>

#include "util.hpp"

// string 类型
extern void test1(sw::redis::Redis &redis); // zadd zrange
extern void test2(sw::redis::Redis &redis); // hexists
extern void test3(sw::redis::Redis &redis); // hexists
extern void test4(sw::redis::Redis &redis); // hkeys hvals
extern void test5(sw::redis::Redis &redis); // hmset hmset

int main()
{

  sw::redis::Redis redis("tcp://127.0.0.1:6379"); // 需要知道地址和port,就是和一个url
  // test1(redis);
  // test2(redis);
  // test3(redis);
  // test4(redis);
  test5(redis);
  // test6(redis);

  return 0;
}
void test5(sw::redis::Redis &redis) // zcard
{
    std::cout << "zadd" << std::endl;
  redis.flushall();
  redis.zadd("key", "卢布", 99);
  redis.zadd("key", {std::make_pair("张云", 90),
                     std::make_pair("历史", 50)});
  std::cout << redis.zrank("key", "卢布").value() << std::endl;

}
void test4(sw::redis::Redis &redis) // zcard
{
  std::cout << "zadd" << std::endl;
  redis.flushall();
  redis.zadd("key", "卢布", 99);
  redis.zadd("key", {std::make_pair("张云", 90),
                     std::make_pair("历史", 50)});

  std::cout << redis.zscore("key", "卢布").value() << std::endl;
}
void test3(sw::redis::Redis &redis) // zcard
{
  std::cout << "zadd" << std::endl;
  redis.flushall();
  redis.zadd("key", "卢布", 99);
  redis.zadd("key", {std::make_pair("张云", 90),
                     std::make_pair("历史", 50)});

  std::cout << redis.zrem("key", "卢布") << std::endl;
  std::cout << redis.zcard("key") << std::endl;
}
void test2(sw::redis::Redis &redis) // zcard
{
  std::cout << "zadd" << std::endl;
  redis.flushall();
  redis.zadd("key", "卢布", 99);
  redis.zadd("key", {std::make_pair("张云", 90),
                     std::make_pair("历史", 50)});
  std::vector<std::pair<std::string, double>> v = {std::make_pair("合适", 91),
                                                   std::make_pair("运发", 78)};
  redis.zadd("key", v.begin(), v.end());
  std::cout << redis.zcard("key") << std::endl;
}
void test1(sw::redis::Redis &redis) // zadd
{
  std::cout << "zadd" << std::endl;
  redis.flushall();
  redis.zadd("key", "卢布", 99);
  redis.zadd("key", {std::make_pair("张云", 90),
                     std::make_pair("历史", 50)});
  std::vector<std::pair<std::string, double>> v = {std::make_pair("合适", 91),
                                                   std::make_pair("运发", 78)};
  redis.zadd("key", v.begin(), v.end());
  // 两种风格
  // 入如果是string,那么只要和一个.如果是pair.俺么是
  std::vector<std::string> result1;
  redis.zrange("key", 0, -1, std::back_inserter(result1));

  std::vector<std::pair<std::string, double>> result2;
  redis.zrange("key", 0, -1, std::back_inserter(result2));
  printContainer(result1);

  for (auto e : result2)
  {
    std::cout << e.first << " " << e.second << std::endl;
  }
}
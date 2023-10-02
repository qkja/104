#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <set>
#include <cerrno>
#include <sw/redis++/redis++.h>

#include "util.hpp"

// string 类型
extern void test1(sw::redis::Redis &redis); // hset
extern void test2(sw::redis::Redis &redis); // hexists
extern void test3(sw::redis::Redis &redis); // hexists
extern void test4(sw::redis::Redis &redis); // hkeys hvals
extern void test5(sw::redis::Redis &redis); // hmset hmset
extern void test6(sw::redis::Redis &redis); // sinterstore

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
void test5(sw::redis::Redis &redis) // hmset hmset
{
  std::cout << " hmset hmset" << std::endl;
  redis.flushall();
  redis.hmset("key", {std::make_pair("f1", "111"),
                      std::make_pair("f2", "222")});
  std::vector<std::pair<std::string, std::string>> fileds = {
      std::make_pair("f4", "444"),
      std::make_pair("f5", "555"),
      std::make_pair("f6", "666")};
  redis.hset("key", fileds.begin(), fileds.end());
  std::vector<std::string> values;
  redis.hmget("key", {"f1", "f2", "f4"}, std::back_inserter(values));
  printContainer(values);
}
void test4(sw::redis::Redis &redis) // hkeys hvals
{
  std::cout << "  hkeys hvals" << std::endl;
  redis.flushall();
  redis.hset("key", "f1", "111");
  redis.hset("key", std::make_pair("f2", "222"));
  redis.hset("key", {std::make_pair("f3", "333"),
                     std::make_pair("f4", "444")});
  std::vector<std::string> fileds;
  redis.hkeys("key", std::back_inserter(fileds));
  printContainer(fileds);

  std::vector<std::string> values;
  redis.hvals("key", std::back_inserter(values));
  printContainer(values);
}
void test3(sw::redis::Redis &redis) // hexists
{
  std::cout << " hexists" << std::endl;
  redis.flushall();
  redis.hset("key", "f1", "111");
  redis.hset("key", std::make_pair("f2", "222"));
  redis.hset("key", {std::make_pair("f3", "333"),
                     std::make_pair("f4", "444")});
  std::cout << redis.hdel("key", "f1") << std::endl;
  std::cout << redis.hdel("key", {"f3", "f4"}) << std::endl;
  ;
}
void test2(sw::redis::Redis &redis) // hexists
{
  std::cout << " hexists" << std::endl;
  redis.flushall();
  redis.hset("key", "f1", "111");
  redis.hset("key", std::make_pair("f2", "222"));
  redis.hset("key", {std::make_pair("f3", "333"),
                     std::make_pair("f4", "444")});
  if (redis.hexists("key", "f1"))
    std::cout << "存在" << std::endl;
}
void test1(sw::redis::Redis &redis) // hset
{
  std::cout << " hset" << std::endl;
  redis.flushall();
  redis.hset("key", "f1", "111");
  redis.hset("key", std::make_pair("f2", "222"));
  redis.hset("key", {std::make_pair("f3", "333"),
                     std::make_pair("f4", "444")});

  std::vector<std::pair<std::string, std::string>> fileds = {
      std::make_pair("f4", "444"),
      std::make_pair("f5", "555"),
      std::make_pair("f6", "666")};
  redis.hset("key", fileds.begin(), fileds.end());
  auto result = redis.hget("key", "f3");
  if (result)
    std::cout << result.value() << std::endl;
}

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <set>
#include <cerrno>
#include <sw/redis++/redis++.h>

#include "util.hpp"

// string 类型
extern void test1(sw::redis::Redis &redis); // sadd smember
extern void test2(sw::redis::Redis &redis); // sismember
extern void test3(sw::redis::Redis &redis); // scard
extern void test4(sw::redis::Redis &redis); //  spop
extern void test5(sw::redis::Redis &redis); // sinter
extern void test6(sw::redis::Redis &redis); // sinterstore

int main()
{

  sw::redis::Redis redis("tcp://127.0.0.1:6379"); // 需要知道地址和port,就是和一个url
  // test1(redis);
  // test2(redis);
  // test3(redis);
  // test4(redis);
  test5(redis);
  test6(redis);

  return 0;
}
void test6(sw::redis::Redis &redis) // sinterstore
{
  std::cout << " sinter" << std::endl;
  redis.flushall();
  redis.sadd("key1", {"111", "222", "333", "444"});
  redis.sadd("key2", {"555", "666", "333", "444"});

  std::cout << redis.sinterstore("key3", {"key1", "key2"}) << std::endl;
  std::set<std::string> s;

  redis.smembers("key3", std::inserter(s, s.end()));
  printContainer(s);
}

void test5(sw::redis::Redis &redis) // sinter
{
  std::cout << " sinter" << std::endl;
  redis.flushall();
  redis.sadd("key1", {"111", "222", "333", "444"});
  redis.sadd("key2", {"555", "666", "333", "444"});
  std::set<std::string> s;
  redis.sinter({"key1", "key2"}, std::inserter(s, s.end()));
  printContainer(s);
}
void test4(sw::redis::Redis &redis) //  spop
{
  using namespace std::chrono_literals;

  std::cout << " scard" << std::endl;
  redis.flushall();
  redis.sadd("key", {"111", "222", "333", "444"});
  auto result = redis.spop("key");
  if (result)
    std::cout << result.value() << std::endl;
}
void test3(sw::redis::Redis &redis) // scard
{
  using namespace std::chrono_literals;

  std::cout << " scard" << std::endl;
  redis.flushall();
  redis.sadd("key", {"111", "222", "333", "444"});
  std::cout << redis.scard("key") << std::endl;
}
void test2(sw::redis::Redis &redis) // sismember
{
  using namespace std::chrono_literals;

  std::cout << " sismember" << std::endl;
  redis.flushall();
  redis.sadd("key", {"111", "222", "333", "444"});
  if (redis.sismember("key", "111"))
  {
    std::cout << "存在" << std::endl;
  }
  if (!redis.sismember("key", "555"))
  {
    std::cout << "不存在" << std::endl;
  }
}
void test1(sw::redis::Redis &redis) // sadd smember
{
  using namespace std::chrono_literals;

  std::cout << " sadd smember" << std::endl;
  redis.flushall();
  redis.sadd("key", {"111", "222"});
  std::vector<std::string> result;
  redis.smembers("key", std::back_inserter(result));
  printContainer(result);
}
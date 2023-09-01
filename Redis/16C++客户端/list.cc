#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <cerrno>
#include <sw/redis++/redis++.h>

#include "util.hpp"

// string 类型
extern void test1(sw::redis::Redis &redis); // lpush lrange
extern void test2(sw::redis::Redis &redis); // rpush
extern void test3(sw::redis::Redis &redis); // rpop lpop
extern void test4(sw::redis::Redis &redis); // blpop brpop
extern void test5(sw::redis::Redis &redis); // llen

int main()
{

  sw::redis::Redis redis("tcp://127.0.0.1:6379"); // 需要知道地址和port,就是和一个url
  // test1(redis);
  // test2(redis);
  // test3(redis);
  // test4(redis);

  test5(redis);
  // test6(redis);
  // test7(redis);
  return 0;
}
void test5(sw::redis::Redis &redis) // llen
{
  std::cout << "llen" << std::endl;
  redis.flushall();
  redis.rpush("key", "111");
  redis.rpush("key", {"222", "333"});

  std::cout << "lenn: " << redis.llen("key") << std::endl;
}
void test4(sw::redis::Redis &redis) // blpop brpop
{
  std::cout << " blpop brpop" << std::endl;
  redis.flushall();
  auto result = redis.blpop("key");
  // auto result = redis.blpop("key1", "key2"....);
  if (result)
  {
    std::cout << "key: " << result.value().first << std::endl;
    // std::cout << "key: " << result->first << std::endl; // 这个是允许的,范围内部的成员变量
    std::cout << "value: " << result.value().second << std::endl;
  }
}

void test3(sw::redis::Redis &redis) // rpop lpop
{
  using namespace std::chrono_literals;

  std::cout << "rpush lrange" << std::endl;
  redis.flushall();
  redis.rpush("key", "111");
  redis.rpush("key", {"222", "333"});
  std::vector<std::string> v = {"444", "555", "666"};
  redis.rpush("key", v.begin(), v.end());

  // 111  222  333 444
  auto left = redis.lpop("key");
  if (left)
    std::cout << left.value() << std::endl;
  auto right = redis.rpop("key");
  if (right)
    std::cout << right.value() << std::endl;
}
void test2(sw::redis::Redis &redis) // lpop
{
  using namespace std::chrono_literals;

  std::cout << "rpush lrange" << std::endl;
  redis.flushall();
  redis.rpush("key", "111");
  redis.rpush("key", {"222", "333"});
  std::vector<std::string> v = {"444", "555", "666"};
  redis.rpush("key", v.begin(), v.end());
  std::vector<std::string> result;

  redis.lrange("key", 0, -1, std::back_inserter(result));
  printContainer(result);
}

void test1(sw::redis::Redis &redis) //
{
  using namespace std::chrono_literals;

  std::cout << " lpush lrange" << std::endl;
  redis.flushall();
  redis.lpush("key", "111");
  redis.lpush("key", {"222", "333"});
  std::vector<std::string> v = {"444", "555", "666"};
  redis.lpush("key", v.begin(), v.end());
  std::vector<std::string> result;

  redis.lrange("key", 0, -1, std::back_inserter(result));
  printContainer(result);
}

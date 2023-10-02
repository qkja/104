#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <cerrno>
#include <sw/redis++/redis++.h>

#include "util.hpp"

// string 类型
extern void test1(sw::redis::Redis &redis); // get set 操作
extern void test2(sw::redis::Redis &redis); // expire and ttl
extern void test3(sw::redis::Redis &redis); // NX XX
extern void test4(sw::redis::Redis &redis); //  mset
extern void test5(sw::redis::Redis &redis); // mget
extern void test6(sw::redis::Redis &redis); // getrange setrange
extern void test7(sw::redis::Redis &redis); // incr decr

int main()
{

  sw::redis::Redis redis("tcp://127.0.0.1:6379"); // 需要知道地址和port,就是和一个url
  // test1(redis);
  // test2(redis);
  // test3(redis);
  // test4(redis);
  // test6(redis);
  test7(redis);

  return 0;
}

void test7(sw::redis::Redis &redis) // mget
{
  using namespace std::chrono_literals;

  std::cout << "incr decr" << std::endl;
  redis.flushall();
  redis.set("key", "111");
  long long result = redis.incr("key");
  std::cout << "result " << result << std::endl;

  auto value = redis.get("key");
  std::cout << value.value() << std::endl;
  result = redis.decr("key");
  std::cout << "result " << result << std::endl;
  value = redis.get("key");
  std::cout << value.value() << std::endl;
}

void test6(sw::redis::Redis &redis) // mget
{
  using namespace std::chrono_literals;

  std::cout << "getrange setrange" << std::endl;
  redis.flushall();
  redis.set("key", "aaabbbeee");
  std::string result = redis.getrange("key", 2, 5);
  std::cout << result << std::endl;
  redis.setrange("key", 2, "11");
  result = redis.getrange("key", 0, -1);
  std::cout << result << std::endl;
}

void test4(sw::redis::Redis &redis) //
{
  using namespace std::chrono_literals;

  std::cout << "  mget mset 操作" << std::endl;
  redis.flushall();
  redis.mset({std::make_pair("key1", "111"), std::make_pair("key2", "222")});
  auto value = redis.get("key1");
  std::cout << value.value() << std::endl;
  value = redis.get("key2");
  std::cout << value.value() << std::endl;

  // 或者使用
  // std::vector<std::pair<std::string, std::string>> v;
  // redis.mset(v.begin(), v.end());
}
void test3(sw::redis::Redis &redis) // NX XX
{
  using namespace std::chrono_literals;

  std::cout << " NX XX 操作" << std::endl;
  redis.flushall();
  redis.set("key", "111", 0s, sw::redis::UpdateType::NOT_EXIST);
  auto value = redis.get("key");
  std::cout << value.value() << std::endl;
  redis.set("key", "222", 0s, sw::redis::UpdateType::NOT_EXIST);
  value = redis.get("key");
  std::cout << value.value() << std::endl;
}
void test2(sw::redis::Redis &redis) // expire and ttl
{
  using namespace std::chrono_literals;
  std::cout << "expire and ttl 操作" << std::endl;
  redis.flushall();
  redis.set("key", "111", std::chrono::seconds(10));
  std::this_thread::sleep_for(5s);

  auto it = redis.ttl("key");
  std::cout << it << std::endl;
}

void test1(sw::redis::Redis &redis) // get set 操作
{
  std::cout << "get set 操作" << std::endl;
  redis.flushall();
  // 函数参数和命令选项是非常对应的,kv,都是string
  redis.set("key", "111");
  auto value = redis.get("key");
  std::cout << "value: " << value.value() << std::endl;
  redis.set("key", "222");
  value = redis.get("key");
  std::cout << "value: " << value.value() << std::endl;
}
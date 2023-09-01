#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <cerrno>
#include <sw/redis++/redis++.h>

#include "util.hpp"

// 通用命令演示
extern void test1(sw::redis::Redis &redis); // get set 操作
extern void test2(sw::redis::Redis &redis); // exists
extern void test3(sw::redis::Redis &redis); // delete
extern void test4(sw::redis::Redis &redis); // keys
extern void test5(sw::redis::Redis &redis); // expire and ttl
extern void test6(sw::redis::Redis &redis); // type
extern void test7(sw::redis::Redis &redis); // type
extern void test8(sw::redis::Redis &redis); // type
extern void test9(sw::redis::Redis &redis); // type

int main()
{

  sw::redis::Redis redis("tcp://127.0.0.1:6379"); // 需要知道地址和port,就是和一个url
  // test1(redis);
  // test2(redis);
  // test4(redis);
  // test5(redis);
  test6(redis);

  return 0;
}

void test6(sw::redis::Redis &redis)
{
  std::cout << "type 操作" << std::endl;
  redis.flushall();
  // 函数参数和命令选项是非常对应的,kv,都是string
  redis.set("key1", "111");
  std::string str = redis.type("key1");
  std::cout << "Key1: " << str << std::endl;

  redis.lpush("key2", "111");
  str = redis.type("key2");
  std::cout << "Key2: " << str << std::endl;

  redis.hset("key3", "11", "22");
  str = redis.type("key3");
  std::cout << "key3: " << str << std::endl;

  redis.sadd("key4", "aaa");
  str = redis.type("key4");
  std::cout << "key4: " << str << std::endl;

  redis.zadd("key5", "卢布", 99);
  str = redis.type("key5");
  std::cout << "key5: " << str << std::endl;
}
void test4(sw::redis::Redis &redis)
{
  std::cout << "keys 操作" << std::endl;
  redis.flushall();
  // 函数参数和命令选项是非常对应的,kv,都是string
  redis.set("key1", "111");
  redis.set("key2", "222");
  redis.set("key3", "333");
  redis.set("key4", "444");
  redis.set("key5", "555");
  // 第二个参数是一个迭代器, 需要给定空间
  std::vector<std::string> result;
  auto iter = std::back_inserter(result);
  redis.keys("*", iter);
  printContainer<std::vector<std::string>>(result);
  // printContainer(result);
}

void test1(sw::redis::Redis &redis)
{
  std::cout << "get set 操作" << std::endl;
  redis.flushall();
  // 函数参数和命令选项是非常对应的,kv,都是string
  redis.set("key1", "111");
  redis.set("key2", "222");
  redis.set("key3", "333");

  auto value1 = redis.get("key1");
  if (value1) // 隐式转化
    std::cout << value1.value() << std::endl;

  auto value2 = redis.get("key2");
  if (value2)
    std::cout << value2.value() << std::endl;

  auto value3 = redis.get("key3");
  if (value3)
    std::cout << value3.value() << std::endl;

  auto value4 = redis.get("key4");
  if (value4)
    std::cout << value4.value() << std::endl;
}

void test2(sw::redis::Redis &redis)
{
  std::cout << "exists 操作" << std::endl;
  redis.flushall();
  // 函数参数和命令选项是非常对应的,kv,都是string
  redis.set("key", "111");
  auto ret = redis.exists("key");
  std::cout << ret << std::endl;
  ret = redis.exists("key2");
  std::cout << ret << std::endl;

  // redis.exists({"key1", "key2", "key2"}); // 多个key
}
void test5(sw::redis::Redis &redis)
{
  using namespace std::chrono_literals;
  std::cout << "expire and ttl 操作" << std::endl;
  redis.flushall();
  redis.set("key", "111");
  redis.expire("key", std::chrono::seconds(10)); // std::chrono::seconds这个更好一些,也是使用10
  // sleep(5); // 这个最好不要用,系统函数
  // 尽量使用逼走军裤
  std::this_thread::sleep_for(3s); // 3s是一个字面值常量
  auto it = redis.ttl("key");
  std::cout << it << std::endl;
}

void test3(sw::redis::Redis &redis) // delete
{
  std::cout << "delete 操作" << std::endl;
  redis.flushall();
  // 函数参数和命令选项是非常对应的,kv,都是string
  redis.set("key", "111");
  redis.del("key"); // {key,key, key}
}
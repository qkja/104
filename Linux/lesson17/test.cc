/**
 * User: Qkj
 * Description:
 * Date: 2023-08-09
 * Time: 19:35
 */
#include "../../../install/mycode/blockqQueue/blockqQueue.hpp"
#include "../../../install/mycode/ringQueue/ringQueue.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <string>
#include <unistd.h>
#include "../../../install/mycode/task/tack.hpp"
#include <memory>
#include "../../../install/mycode/threadPool/threadPool.hpp"
using namespace std;


int main()
{
  const string str = "+-*/%";

  unique_ptr<ThreadPool<Task>> tp(ThreadPool<Task>::getInstance());
  tp->start(); // 开启线程池
  srand((unsigned long)time(nullptr) ^ getpid() ^ pthread_self());

  sleep(1);
  while (1)
  {
    int one = rand() % 50;
    int two = rand() % 10;
    char op = str[rand() % str.size()];
    Task t(one, two, op);
    Log() << "主线程派发任务 " << one << op << two << "=?" << endl;
    // 田间任务
    tp->push(t);
    sleep(1);
  }

  // cout << "hello bit "<< endl;
  return 0;
}
//int main()
//{
//  const string str = "+-*/%";
//
//  // unique_ptr<ThreadPool<int>> tp(new ThreadPool<int>());
//  unique_ptr<ThreadPool<Task>> tp(new ThreadPool<Task>());
//  tp->start();
//  srand((unsigned long)time(nullptr) ^ getpid() ^ pthread_self());
//
//  sleep(1);
//  while (1)
//  {
//    int one = rand() % 50;
//    int two = rand() % 10;
//    char op = str[rand() % str.size()];
//    Task t(one, two, op);
//    Log() << "主线程派发任务 " << one << op << two << "=?" << endl;
//    tp->push(t);
//    sleep(1);
//  }
//
//  // cout << "hello bit "<< endl;
//  return 0;
//}
//using namespace std;
//void *productor(void *args)
//{
//  RingQueue<int> *p = (RingQueue<int> *)args;
//  while (true)
//  { 
//
//    int data = rand() % 10;
//    p->push(data);
//    cout << "pthread[ " << pthread_self() << " ] 生产了一个数据 " << data << endl;
// 
//  }
//}
//
//void *consumer(void *args)
//{
//
//  RingQueue<int> *p = (RingQueue<int> *)args;
//  while (true)
//  {
//    sleep(10);
//    int data = p->pop();
//    cout << "pthread[ " << pthread_self() << " ] 消费了一个数据 " << data << endl;
//  
//  }
//}
//
//int main()
//{
//
//
//  srand((unsigned long)time(nullptr) ^ getpid());
//  RingQueue<int> rq;
//  pthread_t c1;
//  pthread_t c2;
//  pthread_t c3;
//  pthread_t c4;
//
//  pthread_t p1;
//  pthread_t p2;
//  pthread_t p3;
//  pthread_t p4;
//
//  pthread_create(&p1, nullptr, productor, &rq);
//  pthread_create(&p2, nullptr, productor, &rq);
//  pthread_create(&p3, nullptr, productor, &rq);
//  pthread_create(&p4, nullptr, productor, &rq);
//
//  pthread_create(&c1, nullptr, consumer, &rq);
//  pthread_create(&c2, nullptr, consumer, &rq);
//  pthread_create(&c3, nullptr, consumer, &rq);
//  pthread_create(&c4, nullptr, consumer, &rq);
//
//  pthread_join(p1, nullptr);
//  pthread_join(p2, nullptr);
//  pthread_join(p3, nullptr);
//  pthread_join(p4, nullptr);
//
//  pthread_join(c1, nullptr);
//  pthread_join(c2, nullptr);
//  pthread_join(c3, nullptr);
//  pthread_join(c4, nullptr);
//
//  // cout << "hello bit" << endl;
//  return 0;
//}
//
//
//
////std::string str = "+-*/%";
//void *consumer(void *args)
//{
//  BlockqQueue<Task> *p = (BlockqQueue<Task> *)args;
//
//  while (true)
//  {
//    //sleep(1);
//
//    Task t = p->pop();
//    int one = 0;
//    int two = 0;
//    char op = 0;
//    t.get(&one, &two, &op);
//    int result = t();
//    cout << "我 [ " << pthread_self() << " ] 消费了一个任务 "
//         << one << " " << op << " " << two << "=" << result << endl;
//  }
//}
//
//void *producer(void *args)
//{
//  BlockqQueue<Task> *p = (BlockqQueue<Task> *)args;
//
//  while (true)
//  {
//
//    int one = rand() % 10;
//    int two = rand() % 10;
//    char op = str[rand() % str.size()];
//    Task t(one, two, op);
//    p->push(t);
//    cout << "我 [ " << pthread_self() << " ] 生产了一个任务 "
//         << one << " " << op << " " << two << "=?" << endl;
//    sleep(1);
//  }
//}
//
//int main()
//{
//  srand((unsigned long)time(nullptr));
//  BlockqQueue<Task> bq;
//  pthread_t c, q;
//  pthread_create(&c, nullptr, consumer, &bq);
//  pthread_create(&q, nullptr, producer, &bq);
//
//  pthread_join(c, nullptr);
//  pthread_join(q, nullptr);
//  return 0;
//}
//void *consumer(void *args)
//{
//  BlockqQueue<int> *p = (BlockqQueue<int> *)args;
//
//  while (true)
//  {
//    int ret = p->pop();
//    cout << "我消费了一个数据 " << ret << endl;
//    //sleep(1);
//  }
//}
//
//void *producer(void *args)
//{
//  BlockqQueue<int> *p = (BlockqQueue<int> *)args;
//  while (true)
//  {
//
//    int ret = rand() % 10;
//    p->push(ret);
//    cout << "我生产了一个数据 " << ret << endl;
//    sleep(1);
//  }
//}
//int main()
//{
//  srand((unsigned long)time(nullptr));
//
//  BlockqQueue<int> bq;
//  pthread_t c, q;
//  pthread_create(&c, nullptr, consumer, &bq);
//  pthread_create(&q, nullptr, producer, &bq);
//
//  pthread_join(c, nullptr);
//  pthread_join(q, nullptr);
//  return 0;
//}
//
// #include <iostream>
// #include <pthread.h>
// #include <vector>
// #include <functional>

// using namespace std;

// pthread_cond_t cond;
// // 定义一个互斥锁
// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// // 定义一个全局退出变量
// volatile bool quit = false;

// vector<function<void()>> funcs;
// void show()
// {
//   cout << "hello print()" << endl;
// }
// void print()
// {
//   cout << "hello show()" << endl;
// }
// void *waitCommand(void *args)
// {
//   pthread_detach(pthread_self()); // 线程分离,之所以在这里,主要我们也不想等待了,反正主线程还需要一段时间结束,够我们线程分离的
//   while (!quit)
//   {

//     pthread_cond_wait(&cond, &mutex);
//     for (auto f : funcs)
//     {
//       f();
//     }
//   }

//   cout << "thread id  " << pthread_self() << "  end" << endl;
// }

// int main()
// {
//   // 加载任务
//   funcs.push_back(show);
//   funcs.push_back(print);
//   funcs.push_back([]()
//                   { cout << "你好世界" << endl; });

//   pthread_cond_init(&cond, nullptr);

//   pthread_t t1, t2, t3;
//   pthread_create(&t1, nullptr, waitCommand, nullptr);
//   pthread_create(&t2, nullptr, waitCommand, nullptr);
//   pthread_create(&t3, nullptr, waitCommand, nullptr);

//   while (true)
//   {
//     sleep(1);
//     pthread_cond_signal(&cond); // 一个一个的老
//   }

//   pthread_cond_broadcast(&cond);

//   pthread_cond_destroy(&cond);
//   return 0;
// }

// pthread_cond_t cond;
// // 定义一个互斥锁
// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// volatile bool quit = false;
// void *waitCommand(void *args)
// {
//   while (!quit)
//   {
//     pthread_cond_wait(&cond, &mutex);
//     cout << "thread id  " << pthread_self() << "  running" << endl;
//   }
//   cout << "thread id  " << pthread_self() << "  ending" << endl;
//   // 这里解锁 -- 后面我们会知道原因的
//   pthread_mutex_unlock(&mutex);
// }

// int main()
// {
//   pthread_cond_init(&cond, nullptr);

//   pthread_t t1, t2, t3;
//   pthread_create(&t1, nullptr, waitCommand, nullptr);
//   pthread_create(&t2, nullptr, waitCommand, nullptr);
//   pthread_create(&t3, nullptr, waitCommand, nullptr);

//   while (true)
//   {
//     //  控制
//     char n = 0;

//     cout << "请输入你的commmand: ";
//     cin >> n; // cin cout 交叉使用缓冲区会被强制刷新
//     if (n == 'n')
//     {
//       // cout << "aaaaaaaaaaaa" << endl;
//       // 唤醒一个线程
//       // pthread_cond_signal(&cond);
//       pthread_cond_broadcast(&cond);
//     }
//     else
//     {
//       quit = true;
//       // sleep(5);

//       pthread_cond_broadcast(&cond);
//       break;
//     }
//     sleep(1);
//   }

//   pthread_join(t1, nullptr);
//   pthread_join(t2, nullptr);
//   pthread_join(t3, nullptr);

//   pthread_cond_destroy(&cond);
//   return 0;
// }
// pthread_cond_t cond;
// // 定义一个互斥锁
// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// void *waitCommand(void *args)
// {
//   while (true)
//   {
//     // 让所有的线程等待被唤醒 注意锁的使用还没开始
//     // 所有的线程都会在这里等着,给我排队.等着一个一个被叫醒
//     pthread_cond_wait(&cond, &mutex);
//     cout << "thread id  " << pthread_self() << "  running" << endl;
//   }
// }

// int main()
// {
//   pthread_cond_init(&cond, nullptr);

//   pthread_t t1, t2, t3;
//   pthread_create(&t1, nullptr, waitCommand, nullptr);
//   pthread_create(&t2, nullptr, waitCommand, nullptr);
//   pthread_create(&t3, nullptr, waitCommand, nullptr);

//   while (true)
//   {
//     //  控制
//     char n = 0;

//     cout << "请输入你的commmand: ";
//     cin >> n; // cin cout 交叉使用缓冲区会被强制刷新
//     if (n == 'n')
//     {
//       pthread_cond_broadcast(&cond);
//     }
//     else
//     {
//       break;
//     }
//     sleep(1);
//   }

//   pthread_join(t1, nullptr);
//   pthread_join(t2, nullptr);
//   pthread_join(t3, nullptr);

//   pthread_cond_destroy(&cond);
//   return 0;
// }

// // 定义一个条件变量,这个我们使用接口来进行初始化
// pthread_cond_t cond;
// // 定义一个互斥锁
// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// void *waitCommand(void *args)
// {
//   while (true)
//   {
//     cout << "thread id  " << pthread_self() << "  running" << endl;
//   }
// }

// int main()
// {
//   // 第二个参数直接置为NULL
//   pthread_cond_init(&cond, nullptr);

//   pthread_t t1, t2, t3;
//   pthread_create(&t1, nullptr, waitCommand, nullptr);
//   pthread_create(&t2, nullptr, waitCommand, nullptr);
//   pthread_create(&t3, nullptr, waitCommand, nullptr);

//   // 控制语句

//   pthread_join(t1, nullptr);
//   pthread_join(t2, nullptr);
//   pthread_join(t3, nullptr);

//   pthread_cond_destroy(&cond);
//   return 0;
// }

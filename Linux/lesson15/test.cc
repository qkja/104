/**
 * User: Qkj
 * Description: 线程
 * Date: 2023-08-09
 * Time: 18:32
 */

// int tickets = 100;

// void *getTickets(void *args)
// {
//   //  static_cast 相近类型的转换
//   const char *name = static_cast<const char *>(args);

//   while (true)
//   {

//     if (tickets > 0)
//     {

//       cout << name << " 抢到了票, 票的编号: " << tickets << endl;
//       tickets--;
//       sleep(1);
//     }
//     else
//     {
//       // 票抢到几张,就算没有了呢？0
//       cout << name << "] 已经放弃抢票了,因为没有了..." << endl;
//       break;
//     }
//   }

//   return nullptr;
// }

// int main()
// {
//   pthread_t tid1;
//   pthread_t tid2;
//   pthread_t tid3;
//   pthread_t tid4;
//   pthread_create(&tid1, nullptr, getTickets, (void *)"thread 1");
//   pthread_create(&tid2, nullptr, getTickets, (void *)"thread 2");
//   pthread_create(&tid3, nullptr, getTickets, (void *)"thread 3");
//   pthread_create(&tid4, nullptr, getTickets, (void *)"thread 4");

//   int n = pthread_join(tid1, nullptr);
//   cout << n << ":" << strerror(n) << endl;
//   n = pthread_join(tid2, nullptr);
//   cout << n << ":" << strerror(n) << endl;
//   n = pthread_join(tid3, nullptr);
//   cout << n << ":" << strerror(n) << endl;
//   n = pthread_join(tid4, nullptr);
//   cout << n << ":" << strerror(n) << endl;

//   return 0;
// }

// pthread_mutex_t mutex;

// int tickets = 1000;

// void *getTickets(void *args)
// {
//   const char *name = static_cast<const char *>(args);

//   while (true)
//   {
//     pthread_mutex_lock(&mutex);
//     if (tickets > 0)
//     {
//       usleep(10000);
//       cout << name << " 抢到了票, 票的编号: " << tickets << endl;
//       tickets--;
//       pthread_mutex_unlock(&mutex);
//     }
//     else
//     {
//       // 票抢到几张,就算没有了呢？0
//       cout << name << "] 已经放弃抢票了,因为没有了..." << endl;
//       pthread_mutex_unlock(&mutex);

//       break;
//     }
//   }

//   return nullptr;
// }

// int main()
// {
//   // 初始化锁
//   pthread_mutex_init(&mutex, nullptr);

//   pthread_t tid1;
//   pthread_t tid2;
//   pthread_t tid3;
//   pthread_t tid4;
//   pthread_create(&tid1, nullptr, getTickets, (void *)"thread 1");
//   pthread_create(&tid2, nullptr, getTickets, (void *)"thread 2");
//   pthread_create(&tid3, nullptr, getTickets, (void *)"thread 3");
//   pthread_create(&tid4, nullptr, getTickets, (void *)"thread 4");

//   int n = pthread_join(tid1, nullptr);
//   cout << n << ":" << strerror(n) << endl;
//   n = pthread_join(tid2, nullptr);
//   cout << n << ":" << strerror(n) << endl;
//   n = pthread_join(tid3, nullptr);
//   cout << n << ":" << strerror(n) << endl;
//   n = pthread_join(tid4, nullptr);
//   cout << n << ":" << strerror(n) << endl;
//   pthread_mutex_destroy(&mutex);
//   return 0;
// }
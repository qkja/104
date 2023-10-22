/**
 * User: Qkj
 * Description:
 * Date: 2023-08-08
 * Time: 15:26
 */
#include "comm.h"

int flags = IPC_CREAT | IPC_EXCL;
int main()
{
  umask(0);
  key_t key = CreateKey();
  Log() << "key: " << key << std::endl;
  int shmid = shmget(key, MEM_SIZE, flags | 0666);
  if (shmid < 0)
  {
    Log() << "shmget fali  " << strerror(errno) << std::endl;
    return 1;
  }

  Log() << "shmget success  shmid " << shmid << std::endl;

  // 这里使用共享内存
  // 挂接
  Log() << "shmat begin " << std::endl;
  char *str = (char *)shmat(shmid, nullptr, 0); // 0 默认读写

  while (true)
  {
    printf(".%s\n", str);
    sleep(1);
  }

  // 去关联
  Log() << "shmdt begin " << std::endl;
  shmdt(str);
  Log() << "shmctl begin " << std::endl;
  shmctl(shmid, IPC_RMID, nullptr);
  Log() << "shmctl success  shmid " << shmid << std::endl;
  ;
  return 0;
}
// #define flags IPC_CREAT|IPC_EXCL
// // 服务端
// int main()
// {
//   key_t key = CreateKey();
//   Log() << "key: " << key << std::endl;
//   int shmid = shmget(key, MEM_SIZE, flags);
//   if (shmid < 0)
//   {
//     Log() << "shmget fali  " << strerror(errno) << std::endl;
//     return 1;
//   }

//   Log() << "shmget success  shmid " << shmid << std::endl;

//   return 0;
// }
// int main()
// {
//   umask(0);
//   mkfifo(IPC_PATH, 0666);
//   std::cout << "----------------------" << std::endl;
//   int fd = open(IPC_PATH, O_RDONLY);
//   std::cout << fd << std::endl;

//   std::cout << "----------------------" << std::endl;

//   return 0;
// }

// int main()
// {
//   umask(0);

//   if (mkfifo(IPC_PATH, 0666) < 0)
//   {
//     std::cerr << "mkfifo errno " << errno << std::endl;
//     return 1;
//   }
//   // 打开管道文件
//   int fd = open(IPC_PATH, O_RDONLY);
//   if (fd < 0)
//   {
//     std::cerr << "openerrno " << errno << std::endl;
//     return 2;
//   }
// // 正常的通信过程
// #define NUM 1024
//   char buffer[NUM];
//   while (true)
//   {
//     memset(buffer, '\0', sizeof(buffer));

//     // 开始读
//     ssize_t s = read(fd, buffer, sizeof(buffer) - 1);

//     if (s == 0)
//     {
//       std::cout << "客户端推出了,我也推出了" << std::endl;
//       break;
//     }
//     else if (s > 0)
//     {
//       buffer[s] = '\0';
//       std::cout << "客户端发送了一条信息 -> " << buffer
//                 << std::endl;
//     }
//     else
//     {
//       assert(0);
//     }
//   }

//   close(fd);
//   std::cout << "服务端退出了" << std::endl;
//   return 0;
// }
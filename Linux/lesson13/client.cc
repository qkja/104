/**
 * User: Qkj
 * Description:
 * Date: 2023-08-08
 * Time: 15:26
 */
#include "comm.h"

int main()
{
  key_t key = CreateKey();
  Log() << "key: " << key << std::endl;
  Log() << "shmget begin" << std::endl;

  // 仅仅是获取
  int shmid = shmget(key, MEM_SIZE, IPC_CREAT);
  // 挂接
  Log() << "shmat begin" << std::endl;
  char *str = (char *)shmat(shmid, nullptr, 0);
  int cnt = 0;
  while (cnt < 26)
  {
    str[cnt] = 'A' + cnt;
    cnt++;
    str[cnt] = '\0';
    sleep(5);
  }

  Log() << "shmdt begin" << std::endl;
  shmdt(str);
  return 0;
}
// int main()
// {
//   return 0;
// }

// int main()
// {
//   printf("你是否要打开命名管道 1/0: ");
//   fflush(stdout);
//   int ret = 0;
//   scanf("%d", &ret);
//   if (ret == 1)
//   {
//     open(IPC_PATH, O_WRONLY);
//   }
//   return 0;
// }
// int main()
// {
//   int fd = open(IPC_PATH, O_WRONLY);
//   if (fd < 0)
//   {
//     std::cerr << "open : " << errno << std::endl;
//     return 1;
//   }
// #define NUM 1024
//   char line[NUM];
//   while (true)
//   {
//     std::cout << "请输入你的消息: ";
//     fflush(stdout);
//     memset(line, '\0', sizeof(line));

//     if (fgets(line, sizeof(line) - 1, stdin) != NULL)
//     {
//       // fgets 读取是    abc\n\0  他会把 '\n' 带上也会自动添加'\0' -- C语言接口
//       line[strlen(line) - 1] = '\0';
//       write(fd, line, strlen(line));
//     }
//     else
//     {
//       break;
//     }
//   }
//   close(fd);
//   std::cout << "客户端退出了" << std::endl;

//   return 0;
// }
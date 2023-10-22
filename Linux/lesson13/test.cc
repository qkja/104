/**
* User: Qkj
* Description: 进程通信
* Date: 2023-08-07
* Time: 21:50
*/

// #include <unistd.h>
// #include <stdio.h>
// #include <iostream>
// #include <errno.h>
// using namespace std;

// int main()
// {
//   int pipefd[2] = {0};
//   if (pipe(pipefd) != 0)
//   {
//     cerr << "pipe open fail" << errno << endl;
//   }
//   // 创建子进程
//   pid_t id = fork();
//   if (id < 0)
//   {
//     // 失败
//   }
//   else if (id == 0)
//   {
//     // child 关闭 写
//     close(pipefd[1]);
//   }
//   else
//   {
//     // parent 关闭 读
//     close(pipefd[0]);
//   }

//   return 0;
// }
// int main()
// {
//   int pipefd[2] = {0};
//   pipe(pipefd);
//   printf("pipefd[0] %d\n", pipefd[0]);
//   printf("pipefd[1] %d\n", pipefd[1]);
//   return 0;
// }
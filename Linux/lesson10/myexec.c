/**
 * User: Qkj
 * Description:
 * Date: 2023-08-01
 * Time: 20:26
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
  //printf("hello\n");
  printf("hello");
    pid_t id = fork();
//    if (id == 0)
//    {
//        // child
//
//        // 发生进程替
//        execl("/home/qkj/104/Linux/lesson10/", "mycmd", NULL);
//        exit(1); // 只要子进程执行这个语句,替换一定失败了
//    }
//
//    // 到这里 一定是父进程  (如果替换成功的话)
//    int status = 0;
//    pid_t ret = waitpid(id, &status, 0); // 阻塞等待
//
//    sleep(3);
//
//    if (ret == id)
//    {
//        printf("父进程等待成功\n");
//    }
//
    return 0;
}

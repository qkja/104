/**
* User: Qkj
* Description: 
* Date: 2023-05-22
* Time: 15:22
*/
#include <stdio.h>
#include <unistd.h>
int main()
{
  pid_t id = fork();
  if(id != 0)
  {

    // parent
    while(1)
    {
      sleep(1);
    }
  }
  else 
  {

    // child
    return 1;
  }
  return 0;
}











//int main()                                                                     
//{
//    pid_t id = fork();
//    if(id == 0)
//    {
//        // child
//        while(1)
//        {
//            printf("我是子进程 pid : %d\n",getpid());
//            sleep(1);
//        }
//    }
//    else
//    {
//        while(1)
//        {
//            printf("id %d\n", id);
//            sleep(1);
//        }
//    }
//    return 0;
//}


//#include <stdio.h>
//#include <unistd.h>
//int main()                                                                     
//{
//    pid_t id = fork();
//    if(id)
//    {
//
//    printf("id %d\n", id);
//    }
//    if(id == 0)
//    {
//      printf("getpid %d\n", getpid());
//      return 0;
//    }
//    
//    return 0;
//}

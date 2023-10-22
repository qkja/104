/**
 * User: Qkj
 * Description:
 * Date: 2023-08-08
 * Time: 15:26
 */
#include "../util.hpp"
#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

// 2. 需要bind吗？？需要,但是不需要自己显示的bind！ 不要自己bind！！！！
// 3. 需要listen吗？不需要的！
// 4. 需要accept吗？不需要的!

volatile bool quit = false;

static void Usage(std::string proc)
{
  std::cerr << "Usage:\n\t" << proc << " serverIp serverPort" << std::endl;
  std::cerr << "Example:\n\t" << proc << " 127.0.0.1 8081\n"
            << std::endl;
}
// ./clientTCP serverIp serverPort
int main(int argc, char *argv[])
{

  std::string serverIp = argv[1];
  uint16_t serverPort = atoi(argv[2]);

  // 1. 创建socket SOCK_STREAM
  int sock = socket(AF_INET, SOCK_STREAM, 0);

  // 2. connect,发起链接请求,你想谁发起请求呢？？当然是向服务器发起请求喽
  // 2.1 先填充需要连接的远端主机的基本信息
  struct sockaddr_in server;
  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(serverPort);
  inet_aton(serverIp.c_str(), &server.sin_addr);

  // 2.2 发起请求,connect 会自动帮我们进行bind！
  if (connect(sock, (const struct sockaddr *)&server, sizeof(server)) != 0)
  {
    std::cerr << "connect: " << strerror(errno) << std::endl;
  }

  std::cout << "info : connect success: " << sock << std::endl;

  std::string message;
  while (!quit)
  {
    message.clear();
    std::cout << "请输入你的消息>>> ";
    std::getline(std::cin, message);
    if (strcasecmp(message.c_str(), "quit") == 0)
      quit = true;

    ssize_t s = write(sock, message.c_str(), message.size());
  }
  close(sock);
  return 0;
}
/**
 * User: Qkj
 * Description:
 * Date: 2023-08-22
 * Time: 16:10
 */
#include "./split/netcalculator_split.hpp"
#include "./split/Server.hpp"
#include "TcpServer.hpp"
#include <memory>
static void Usage(std::string proc)
{
  std::cerr << "Usage:\n\t" << proc << " port " << std::endl;
}

// 这个就是我们业务就可以了
int BeginHandler(Connection *conn, std::string &str, sevice_t service)
{
  std::cout << "-----------  begin  ------------------" << std::endl;

  // conn->outbuffer += str;
  logMessage(DEBUG, "报文: %s : inbuffer: %s", str.c_str(), conn->inbuffer.c_str());
  // std::cout << str << std::endl;

  // 反序列化
  // 1 + 1X2 + 2X3 + 3X
  struct Request req;
  if (!Parser(str, &req))
  {
    return -1;
  }
  struct Response resp = service(req);
  std::string outbuffer;
  Serialize(&outbuffer, &resp);
  // 这里就是一个信号

  conn->outbuffer += outbuffer;
  conn->sender_(conn);
  if (conn->outbuffer.empty())
    conn->R->EnableReadWrite(conn->sock_, true, false);
  else
    conn->R->EnableReadWrite(conn->sock_, true, true);
  // 能不能直接条用这个sende方法呢?
  // 谈谈发送问题
  // conn->R->EnableReadWrite(conn->sock_, true, true);
  std::cout << "-----------  end   ------------------" << std::endl;

  return 1;
}

int HandlerRequest(Connection *conn, std::string &str)
{
  return BeginHandler(conn, str, calculator);
}
int main(int argc, char *argv[])
{

  if (argc != 2)
  {
    Usage(argv[0]);
    exit(-1);
  }

  std::uint16_t port = atoi(argv[1]);

  std::unique_ptr<TcpServer> reactor(new TcpServer(port, splitPagce, HandlerRequest));
  reactor->Run();
  return 0;
}
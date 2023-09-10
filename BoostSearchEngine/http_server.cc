// #include "searcher.hpp"
// #include "cpp-httplib/httplib.h"
// const std::string root_path = "./wwwroot";

// int main()
// {
//   httplib::Server svr;
//   // 设置跟目录
//   svr.set_base_dir(root_path.c_str());
//   svr.Get("hi", [](const httplib::Request& req, httplib::Response& rsp){
//     rsp.set_content("hello word!", "text/plain; charset=utf-8");
//   });
//   svr.listen("192.168.65.129", 8080);
//   return 0;
// }

#include "searcher.hpp"
#include "cpp-httplib/httplib.h"
#include "log.hpp"
#include "daemonize.hpp"

const std::string root_path = "./wwwroot";
const std::string input = "data/raw_html/raw.txt";
int main()
{
  // daemonize(); //守护进程化
  // 初始化sercher
  ns_searcher::Searcher search;
  search.InitSearcher(input);

  httplib::Server svr;
  svr.set_base_dir(root_path.c_str()); // 设置跟目录

  svr.Get("/s", [&search](const httplib::Request &req, httplib::Response &rsp)
          {
            if (req.has_param("word") == false)
            {
              rsp.set_content("必须要搜索关键字", "text/plain; charset=utf-8");
              return;
            }

            std::string word = req.get_param_value("word");
            LOG(NORMAL, "用户搜索的: " + word);

            std::string json_string;
            search.Search(word, &json_string);
            LOG(NORMAL, json_string.c_str() + word);
            rsp.set_content(json_string, "application/json");
            // rsp.set_content("hello word!", "text/plain; charset=utf-8");
          });
  LOG(NORMAL, "服务器启动成功");
  svr.listen("0.0.0.0", 8081);

  return 0;
}

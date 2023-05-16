/**
 * User: Qkj
 * Description: 
 * Date: 2023-05-15
 * Time: 23:17
 */
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// 空间配置器  
















//int main()
//{
//  int i = 123;
//  double d = 4.1234;
//  ostringstream oss;
//  oss << i;
//  cout << oss.str() << endl;
//  //oss << d; // 这是追加
//  oss.str("");
//  //oss.str().clear();
//
//  oss << d;
//  cout << oss.str() << endl;
//  return 0;
//}









//struct ServerInfo
//{
//  char _address[32];
//  int _port;
//};
//struct ConfigManager
//{
//  public:
//    ConfigManager(const char* filename)
//      :_filename(filename)
//    {}
//    void WriteBin(const ServerInfo& info)
//    {
//      ofstream ofs(_filename, ios_base::out | ios_base::binary);
//      ofs.write((const char*)&info, sizeof(info));
//    }
//    void ReadBin(ServerInfo& info)
//    {
//      ifstream ifs(_filename, ios_base::in | ios_base::binary);
//      ifs.read((char*)&info, sizeof(info));
//    }void WriteText(const ServerInfo& info)
//    {
//      ofstream ofs(_filename);
//      ofs << info._address << " " << info._port<< " "<<info._date;
//    }
//    void ReadText(ServerInfo& info)
//    {
//      ifstream ifs(_filename);
//      ifs >> info._address >> info._port>>info._date;
//    }
//  private:
//    string _filename; // 配置文件
//};
//int main()
//{
//  ServerInfo winfo = { "192.0.0.1", 80, { 2022, 4, 10 } };
//  // 二进制读写
//  ConfigManager cf_bin("test.bin");
//  cf_bin.WriteBin(winfo);
//  ServerInfo rbinfo;
//  cf_bin.ReadBin(rbinfo);
//  cout << rbinfo._address << " " << rbinfo._port <<" "
//    <<rbinfo._date << endl;
//  // 文本读写
//  ConfigManager cf_text("test.text");
//  cf_text.WriteText(winfo);
//  ServerInfo rtinfo;
//  cf_text.ReadText(rtinfo);
//  cout << rtinfo._address << " " << rtinfo._port << " " <<
//    rtinfo._date << endl;
//  return 0;
//}
//
//
//struct ServerInfo
//{
//  string _address[32];
//  //char _address[32];
//  int _port;
//};
//
//std::ofstream& operator <<(std::ofstream& out, ServerInfo& ser)
//{
//  out << ser.
//}
//struct ConfigManager
//{
//  public:
//    ConfigManager(const char* filename)
//      :_filename(filename)
//    {}
//    // 二进制写
//    void WriteBin(const ServerInfo& info)
//    {
//      ofstream ofs(_filename, ios_base::out | ios_base::binary);
//      ofs.write((const char*)&info, sizeof(info));
//    }
//    // 二进制读
//    void ReadBin(ServerInfo& info)
//    {
//      ifstream ifs(_filename, ios_base::in | ios_base::binary);
//      ifs.read((char*)&info, sizeof(info));
//    }
//    // C++文件流的优势就是可以对内置类型和自定义类型，都使用
//    // 一样的方式，去流插入和流提取数据
//    // 当然这里自定义类型Date需要重载>> 和 <<
//    // istream& operator >> (istream& in, Date& d)
//    // ostream& operator << (ostream& out, const Date& d)
//    void WriteText(const ServerInfo& info)
//    {
//      ofstream ofs(_filename);
//      ofs << info._address << " " << info._port<< " "<<info._date;
//    }
//    void ReadText(ServerInfo& info)
//    {
//      ifstream ifs(_filename);
//      ifs >> info._address >> info._port>>info._date;
//    }
//  private:
//    string _filename; // 配置文件
//};
//int main()
//{
//  ServerInfo info = {"hello", 18};
//
//  // 文本方式 写入文件
//  // 二进制   写入文件
//
//
//  return 0;
//}
//
//
//int main()
//{
//  ifstream ifs("test.cc");
//  while(ifs)
//  {
//    char ch = ifs.get();
//    //char ch = '\0';
//    //ifs.get(ch);
//    cout.put(ch);
//  }
//  return 0;
//}
//
//int main()
//{
//  ifstream in_file; // 打开一个输入流, 默认是 in 
//  ifstream in_file("file.txt", std::ios::binary); // 二进制打开一个输入流
//  return  0;
//}
//int main()
//{
//  // 我们最好不要 C++ 和 C语言混用,如果混用也是可以的
//  // 不过我们要小心.
//  return 0;
//}
//int main()
//{
//  // scanf 从文件流中读取,读取成功放回的是个数
//  // 那么 cin >> a 是如何, 本质 重载了operator bool  
//  int a = 0;
//  while(cin >> a)
//  {
//    cout << a << endl;
//  }
//  return 0;
//}
//int main()
//{
//  std::cerr<< "hello" << std::endl;
//  std::clog<< "hello" << std::endl;
//  return 0;
//}

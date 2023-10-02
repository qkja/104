#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
// void Print(int n, int &x)
// {
//   // 这里不好找到id
//   for (int i = 0; i < n; ++i)
//   {
//     cout << this_thread::get_id() << " " << x++ << endl;
//     std::this_thread::sleep_for(std::chrono::milliseconds(10));
//   }
// }

// int main()
// {
//   int x = 0;
//   // 注意,这里我们即使使用引用也是一份拷贝,这是mutex独特的限制,记住就行了
//   thread t1([&x]()
//             {
//         cout << this_thread::get_id() << " " << x++ << endl;
//     std::this_thread::sleep_for(std::chrono::milliseconds(10)); },
//             100, ref(x));

//   thread t2([&x]()
//             {
//     cout<< this_thread::get_id() << " " << x++ << endl;
//     std::this_thread::sleep_for(std::chrono::milliseconds(10)); },
//             100, ref(x));

//   t1.join();
//   t2.join();
//   cout << " " << x << endl;

//   return 0;
// }
// mutex mtx; // 这里最好不要使用全局的变量

// void Print(int n)
// {
//   // 这里不好找到id
//   for (int i = 0; i < n; ++i)
//   {
//     mtx.lock();

//     cout << this_thread::get_id() << " " << i << endl;
//     std::this_thread::sleep_for(std::chrono::milliseconds(10));
//     mtx.unlock();
//   }
// }
// void Print(int n, int &x)
// {
//   // 这里不好找到id
//   for (int i = 0; i < n; ++i)
//   {
//     mtx.lock();

//     cout << this_thread::get_id() << " " << x++ << endl;
//     std::this_thread::sleep_for(std::chrono::milliseconds(10));
//     mtx.unlock();
//   }
// }

// int main()
// {
//   int x = 0;
//   // 注意,这里我们即使使用引用也是一份拷贝,这是mutex独特的限制,记住就行了
//   thread t1(Print, 100, ref(x));
//   thread t2(Print, 100, ref(x));

//   t1.join();
//   t2.join();
//   cout << " " << x << endl;

//   return 0;
// }

// #define _CRT_SECURE_NO_WARNINGS 1
//
// #include <iostream>
// #include <functional>
// #include <string>
//
// using std::cin;
// using std::cout;
// using std::endl;
// using std::function;

// int main()
//{
//	std::string str = "hello";
//	std::move(str);
//
//	return 0;
// }
// int main()
//{
//	//int a = 1;
//	//int b = 0;
//	//auto fun1 = [&](int c){b = 1; b = a + c;  };
//	//fun1(10);
//	//cout << b << endl;
//	int x = 10;
//	auto add_x = [&x] { x *= 2; return 10; };//ȡ�������б��ĳ�����
//	cout << add_x() << endl;
//	cout << x << endl;
//	return 0;
// }
// template <class F, class T>
// T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	return f(x);
// }
// double f(double i)
//{
//	return i / 2;
// }
// struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
// };
// int main()
//{
//	// ������
//	cout << useF(f, 11.11) << endl; // count:1 count:0025C140  5.555
//	// ��������
//	cout << useF(Functor(), 11.11) << endl; // count:1 count: 0025C144 3.70333
//	// lamber����ʽ
//	cout << useF([](double d) -> double
//	{ return d / 4; },
//	11.11)
//	<< endl; // count : 1 count: 0025C148 2.7775
//	return 0;
// }

// template<class F, class T>
// T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//
//	return (f(x));
// }
// double f(double i) {
//	return i / 2;
// }
// struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
// };
//
//
// int main()
//{
//	// ������
//	function<double(double)> fn1 = f;
//	//function<double(double)> fn1 ( f); ֧��
//	cout << useF(fn1, 11.11) << endl;
//
//	// ��������
//	function<double(double)> fn2 = Functor();
//	//function<double(double)> fn2(Functor());   //��֧�֣���Ϊfunction<double(double)>��Functor()����ͬһ�����ͣ�����ƥ��ƥ�䲻�ϣ�
//	//function<double(Functor,double)> fn2=&Functor::operator();  //֧��
//	//function<double(double)> fn2 = bind(&Functor::operator(), Functor(), placeholders::_1); //֧��
//	cout << useF(fn2, 11.11) << endl;
//
//	// lamber����ʽ
//	function<double(double)> fn3([](double d)->double { return d / 4; });
//	cout << useF(fn3, 11.11) << endl;
//	return 0;
// }
// template<class F, class T>
// T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	return f(x);
// }
// double f(double i)
//{
//	return i / 2;
// }
// struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
// };
// int main()
//{
//	// ������
//	cout << useF(f, 11.11) << endl;
//	// ��������
//	cout << useF(Functor(), 11.11) << endl;
//	// lamber����ʽ
//	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
//	return 0;
// }

// int main()
// {
//   int x = 0;
//   // 注意,这里我们即使使用引用也是一份拷贝,这是mutex独特的限制,记住就行了
//   int n = 10;
//   thread t1([&]()
//             {
//               for (int i = 0; i < n; ++i)
//               {
//                 cout << this_thread::get_id() << " " << x++ << endl;
//                 std::this_thread::sleep_for(std::chrono::milliseconds(10));
//               } });

//   thread t2([&]()
//             {
//               for (int i = 0; i < n; ++i)
//               {
//                 cout << this_thread::get_id() << " " << x++ << endl;
//                 std::this_thread::sleep_for(std::chrono::milliseconds(10));
//               } });

//   t1.join();
//   t2.join();
//   cout << " " << x << endl;

//   return 0;
// }
#include <vector>

int main()
{
  int x = 0;
  // 注意,这里我们即使使用引用也是一份拷贝,这是mutex独特的限制,记住就行了
  int n = 10;
  int m = 4;
  vector<thread> v(m);
  for (int i = 0; i < m; i++)
  {
    v[i] = thread([&]()
                  {
                for (int i = 0; i < n; ++i)
                {
                  cout << this_thread::get_id() << " " << x++ << endl;
                  std::this_thread::sleep_for(std::chrono::milliseconds(10));
                } });
  }
  for (int i = 0; i < m; i++)
  {
    v[i].join();
  }
  cout << " " << x << endl;

  return 0;
}
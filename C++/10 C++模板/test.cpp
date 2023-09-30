//通常情况下** 使用模板可以实现一些与类型无关的代码, 但对于一些特殊类型的可能会得到一些错误的结果**

//template <class T1, class T2>
//class Data
//{
//public:
//    Data() { cout << "Data<T1, T2>" << endl; }
//
//private:
//    T1 _d1;
//    T2 _d2;
//};
//
//template <>
//class Data<int, int>
//{
//public:
//    Data() { cout << "Data<int, int>" << endl; }
//
//private:
//    int _d1;
//    int _d2;
//};
//
//// 两个参数偏特化为指针类型
//template <typename T1, typename T2>
//class Data<T1*, T2*>
//{
//public:
//    Data() { cout << "Data<T1*, T2*>" << endl; }
//
//private:
//    T1 _d1;
//    T2 _d2;
//};
//// 两个参数偏特化为引用类型
//template <typename T1, typename T2>
//class Data<T1&, T2&>
//{
//public:
//    Data(const T1& d1, const T2& d2)
//        : _d1(d1), _d2(d2)
//    {
//        cout << "Data<T1&, T2&>" << endl;
//    }
//
//private:
//    const T1& _d1;
//    const T2& _d2;
//};
//void test2()
//{
//    Data<double, int> d1;        // 调用特化的int版本
//    Data<int, double> d2;        // 调用基础的模板
//    Data<int*, int*> d3;       // 调用特化的指针版本
//    Data<int&, int&> d4(1, 2); // 调用特化的引用版本
//}
//
//int main()
//{
//    test2();
//    return 0;
//}
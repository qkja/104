#include <iostream>
using namespace std;
typedef void (*ViPointer)();

class A
{
public:
  virtual void func()
  {
    cout << "a" << endl;
  }

private:
  int _a = 1;
};
class B : public A
{
public:
  virtual void func()
  {
    cout << "b" << endl;
  }

private:
  int _a = 1;
};
class C : public A
{
public:
  virtual void func()
  {
    cout << "c" << endl;
  }

private:
  int _a = 1;
};
void print_virtual_function_table(void *p)
{
  ViPointer *ptr = (ViPointer *)(*((long long *)p));
  int i = 0;

  // while (*(int*)(ptr+i) && ptr[i]!= nullptr)
  while (ptr[i] != (ViPointer)0x600db0)
  {
    printf("[%d] : %p\n", i, ptr[i]);
    ptr[i]();
    i++;
  }
}

int main()
{
  // cout << sizeof(A) << endl;
  // A a;
  // cout << sizeof(int *) << endl;
  // print_virtual_function_table(&a);

  A a;
  B b;
  C c;
  print_virtual_function_table(&a);
  print_virtual_function_table(&b);
  print_virtual_function_table(&c);
  return 0;
}
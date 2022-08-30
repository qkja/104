#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string reverseOnlyLetters(string s) 
{
  string::iterator beg = s.begin(); 
  string::iterator end = s.end();
  while(beg != end)
  {
    if(!((*beg) >= 'a' && (*beg) <= 'z' 
        || (*beg) >='A' && (*beg) <= 'Z'
        ))
    {
      beg++;
    }
    if(!((*end) >= 'a' && (*end) <= 'z' 
        || (*end) >='A' && (*end) <= 'Z'
        ))
    {
      end--;
    }

    //swap(*beg,*end);
    char ch = *beg;
    *beg = *end;
    *end = ch;
  }
  return s;

}

int main()
{
  std::string s1("hello");
  std::string::iterator it = s1.begin();
  while(it != s1.end())
  {
    cout << *it << " ";
    it++;
  }
  cout<< endl;
  cout<< s1 <<endl;
  return 0;
}

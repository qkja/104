#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
long long NumberOfRoot(long long n)
{
    // 到这里的都是 大于10的
    long long sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main()
{
    string str;
    while (cin >> str)
    {
        // 这里把str 变成 int 
        long long sum = 0;
        for (char ch : str)
        {
            sum += (ch - '0');
        }
        while (sum > 9)
        {
            sum = NumberOfRoot(sum);
        }
        cout << sum << endl;
    }
    return 0;
}
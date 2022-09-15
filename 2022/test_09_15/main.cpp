#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int _numWays(int n) {
        if (n < 2)
            return 1;
        int left = 1;
        int right = 1;
        int sum = 0;
        for (int i = 2; i < n; i++)
        {
            sum = left + right;
            left = right;
            right = sum;
        }
        return right;
    }
    int numWays(int n) {
        return _numWays(n);
    }
};

//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        if (prices.empty())
//            return 0;
//        int min = prices[0];
//        int sum = 0;
//        for (int i = 1; i < prices.size(); i++)
//        {
//            if (prices[i] - min > sum)
//            {
//                sum = prices[i] - min;
//            }
//            if (prices[i] < min)
//            {
//                min = prices[i];
//            }
//        }
//        return sum;
//    }
//};


//class Solution {
//private:
//
//    int _fib(int n) {
//        if (n < 2)
//            return n;
//        int left = 0;
//        int right = 1;
//        int sum = 0;
//        for (int i = 2; i < n; i++)
//        {
//            sum = left + right;
//            left = right;
//            right = sum;
//        }
//        return right;
//    }
//   /* int _fib(int n) {
//        if (n < 2)
//            return 1;
//        return _fib(n - 1)% ((int)(1e9) + 7) + _fib(n - 2) % ((int)(1e9) + 7);
//    }*/
//public:
//    int fib(int n) {
//        return _fib(n);
//    }
//};
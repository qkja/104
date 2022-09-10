#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;
//class Solution {
//public:
//    char firstUniqChar(string s) {
//        if (s.size() == 0)
//            return ' ';
//        map<char, int> m;
//        for (const char& ch : s)
//        {
//            m[ch]++;
//        }
//        for (const char& ch : s)
//        {
//            auto it = m.find(ch);
//            if (it->second == 1)
//                return it->first;
//        }
//        return ' ';
//    }
//};
//class Solution {
//public:
//    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
//        if (matrix.size() == 0)
//            return false;
//        int n = matrix.size();
//        int m = matrix[0].size();
//        int i = 0;
//        int j = m-1;
//
//        while (i<n&&j>=0)
//        {
//            if (matrix[i][j] > target)
//            {
//                j--;
//            }
//            else if (matrix[i][j] < target)
//            {
//                i++;
//            }
//            else
//            {
//                return true;
//            }
//        }
//        return false;
//    }
//};
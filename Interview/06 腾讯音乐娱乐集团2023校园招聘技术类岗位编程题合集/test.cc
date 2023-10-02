#include <type_traits>
#include <unordered_map>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回满足题意的最小操作数
     * @param str string字符串 给定字符串
     * @return int整型
     */
    int minOperations(string str) {
        // write code here
        int count = 0;
        unordered_map<char, int> m;
        for(auto e: str)
        {
            m[e]++;
            if(m[e] % 2 == 0)
            count++;
        }
        int len = str.size() - count;
        if(len> 26)
        {
              count += len - 26;
        }
        return  count;
        // if(str.size() > 26)
        // {
        //     count = str.size() - 26;
        // }
    }
};


#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/////////////////////////////////////////////////////

// day 6
// 字符串 变成整数
//class Solution {
//public:
//    int StrToIntHelper(const string& str, int begin) {
//        long long result = 0;
//        for (int i = begin; i < str.size(); i++)
//        {
//            if (str[i] >= '0' && str[i] <= '9')
//            {
//                result = result * 10 + (str[i] - '0');
//            }
//            else
//            {
//                return 0;
//            }
//        }
//        return result;
//    }
//    int StrToInt(string str) {
//        if (str.empty())
//            return 0;
//        // 这里 需要判断一下 第一个 是不是 + -
//        if (str[0] == '+')
//        {
//            return StrToIntHelper(str, 1);
//        }
//        else if (str[0] == '-')
//        {
//            return -StrToIntHelper(str, 1);
//        }
//        else
//        {
//            return StrToIntHelper(str, 0);
//        }
//        return 0;
//    }
//};

// 这个方法不行
//int main()
//{
//	int col = 0; // 列
//	int row = 0; // 行
//	cin >> col >> row;
//
//	// 计算 不能 放 蛋糕的
//	int count = 0;
//	for (int i = 0; i < row; i += 2)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			count++;
//		}
//	}
//	cout << col * row - count << endl;
//
//	return 0;
//}

// 不要 二 暴力解法
//int main()
//{
//	int col = 0; // 列
//	int row = 0; // 行
//	cin >> col >> row;
//	vector<vector<int>> vv;
//	vector<int> v(col, 1);
//	for (int i = 0; i < row; i++)
//	{
//		vv.push_back(v);
//	}
//
//	//这里遍历整个二维数数组
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			if (vv[i][j] == 1)
//			{
//				// 上下
//				if (i + 2 < row)
//					vv[i + 2][j] = 0;
//				if (i - 2 >= 0)
//					vv[i-2][j] = 0;
//
//			    // 左右
//				if (j + 2 < col)
//					vv[i][j + 2] = 0;
//				if (j - 2 >= 0)
//					vv[i][j - 2] = 0;
//				// 这里 判断 周围的 欧几里得数 等于 2 的全部置为o
//			}
//		}
//	}
//	int count = 0;
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			if (vv[i][j] == 1)
//			{
//				count++;
//			}
//		}
//	}
//	cout << count << endl;
//	return 0;
//}


/////////////////////////////////////////////////////
//day 5 
//bool isPalindrome(const string& str)
//{
//	if (str.empty())
//		return true;
//	int left = 0;
//	int right = str.size() - 1;
//	while (left < right)
//	{
//		if (str[left] != str[right])
//			return false;
//		left++;
//		right--;
//	}
//	return true;
//}
//
//int main()
//{
//	string s1;
//	string s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	string str;
//	int count = 0;
//	for (int i = 0; i <= s1.size(); i++)
//	{
//		str = s1;
//		str.insert(i, s2);
//		// 这里 插入 数据
//		if (isPalindrome(str))
//		{
//			count++;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}
// 连续最大和
// 这里看 dp 的另外一种写法

//int main()
//{
//    int n = 0;
//    cin >> n;
//    vector<int> array;
//    array.resize(n);
//    for (int i = 0; i < n; i++)
//    {
//        cin >> array[i];
//    }
//    这里 就开始
//
//    经典且高频dp问题
//    定义状态# f(i): 以i下标结尾的最大连续子序列的和
//    int max_value = array[0];
//    int total = array[0]; //当前累计的和
//    for 循环，用来检测以i下标结尾的连续子序列的和
//    for (int i = 1; i < array.size(); i++) {
//        if (total >= 0) {
//            如果之前total累计的和>=0,说明当前数据+total，有利于整体增大
//            total += array[i];
//        } 
//        else{
//            如果之前累计的和<0,说明当前数据+total，不利于整体增大,丢弃之前的所有值
//            这里有一个基本事实，就是之前的连续数据和是确定的。
//            连续，是可以从以前到现在，也可以是从现在到以后。至于要不要加以前，就看以前对整体增大又没有
//            贡献度
//            total = array[i];
//        } 
//        走到这，标示以i下标结尾的最大连续子序列的和已经算出，进行最大值统计
//        if (max_value < total) {
//            max_value = total;
//        }
//    }
//    cout << max_value << endl;
//    return 0;
//}

//int main()
//{
//    int arr[][3] = { 0 };
//    cout << sizeof(arr[0]) << endl;
//    cout << sizeof(arr[0]+0) << endl;
//    return 0;
//}
//  strcat 应该是 追加 字符串
//  char *strcat( char *strDestination, const char *strSource );
//  返回值 从strDestination开始追加 找到\0,补充strSource这的的字符串
//void main(void)
//{
//    char string[80];
//    strcpy(string, "Hello world from ");
//    char* ret = strcat(string+1, "strcpy ");
//}
//void main(void)
//{
//    char string[80];
//    strcpy(string, "Hello world from ");
//    strcat(string, "strcpy ");
//
//    strcat(string, "and ");
//    strcat(string, "strcat!");
//    printf("String = %s\n", string);
//}


/////////////////////////////////////////////////////
// day 4
//class Solution {
//public:
//    string solve(int M, int N) {
//        // write code here
//        int flag = 0;
//        if (M <= 0)
//        {
//            flag = 1; //负数
//            M = -M;
//        }
//        char table[] = "0123456789ABCDEF";
//        string str;
//        while (M)
//        {
//            int ret = M % N;
//            str += table[ret];
//            M /= N;
//        }
//        if (flag == 1)
//        {
//            str += '-';
//        }
//        reverse(str.begin(), str.end());
//        return str;
//        // 这个 用 取余法
//    }
//};

//int main()
//{
//	int x = 0;
//	int y = 0;
//	int z = 0;
//	int m = 0;
//	cin >> x >> y >> z >> m;
//	// 计算  b
//	int a = (x + z) / 2;
//	if (2 * a != (x + z))
//	{
//		cout << "No" << endl;
//		return 0;
//	}
//	int b = a - x;
//	int c = m - b;
//	if (a < 0 || b < 0 || c < 0)
//	{
//		cout << "No" << endl;
//	}
//	else
//	{
//		cout << a << " " << b << " " << c << endl;
//	}
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////
// day 3
//class Solution {
//public:
//    //数组中出现次数超过一半的数字
//    int MoreThanHalfNum_Solution(vector<int> numbers) {
//        if (numbers.empty())
//            return 0;
//         //这里我们用 打擂台的方式
//        int ret = 0;
//        int flag = 0;
//
//        for (int i = 0; i < numbers.size(); i++)
//        {
//            if (flag == 0)
//            {
//                ret = numbers[i];
//                flag = 1;
//            }
//            else if (numbers[i] == ret)
//            {
//                flag++; // 遇到相同的 擂台上增加一个
//            }
//            else
//            {
//                flag--;
//            }
//        }
//        // 擂台上站的 一个或者 几个 就是我们要的
//        // 至于是不是要验证一下  这里看题意了
//        int count = 0;
//        for (int i = 0; i < numbers.size(); i++)
//        {
//            if (ret == numbers[i])
//            {
//                count++;
//                if (count > numbers.size() / 2)
//                {
//                    return ret;
//                }
//            }
//        }
//        return 0;
//    }
//};

//int main()
//{
//    string str;
//    getline(cin, str);
//    str += '#'; //这个作用防止 aaaa111222这个情况 或者 不加  i <= str.size()
//    string cur;
//    string ret;
//    for (int i = 0; i < str.size(); i++)
//    {
//        if (str[i] >= '0' && str[i] <= '9')
//        {
//            cur += str[i];
//        }
//        else
//        {
//            if (cur.size() > ret.size())
//            {
//                ret = cur;
//            }
// 
//            cur.clear();
//     
//        }
//    }
//    cout << ret << endl;
//	return 0;
//}

//int main()
//{
//	string str;
//	getline(cin, str);
//	int flag = 0;
//	int begin = 0;
//	int prevBegin = 0;
//	int max = 0;
//	int count = 0;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] >= '0' && str[i] <= '9')
//		{
//			if (flag == 0)
//			{
//				//第一次找到
//				begin = i;
//				flag = 1; // 
//			}
//			count++; //记录连续找到的次数
//		}
//		else
//		{
//			// 找到了 第一个不是 0-9的字符
//			if (flag == 1)
//			{
//				if (count > max)
//				{
//					max = count;
//					prevBegin = begin;
//				}
//				flag = 0;  // 重新开始
//				count = 0; // 重新计数
//			}
//		}
//	}
//	// 这个 最后一次 找到的 也就是尾部  数字
//	if (flag == 1)
//	{
//		if (count > max)
//		{
//			max = count;
//			prevBegin = begin;
//		}
//		flag = 0;
//	}
//
//	for (int i = 0; i < max; i++)
//	{
//		cout << str[prevBegin + i];
//	}
//	cout << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string str;
//	getline(cin, str);
//	int begin = 0;
//	int len = 0;
//	int result = 0;
//	for (int i = 0; i < str.size(); i++)
//	{
//		// 这里 寻找第一个 数字
//		if (str[i] >= '0' && str[i] <= '9')
//		{
//			begin = i;
//			while (i  < str.size() && str[i] >= '0' && str[i] <= '9')
//			{
//				i++;
//			}
//
//			if (i - begin > len)
//			{
//				//len = i
//				result = begin; // 记录开始位置
//				len = i - begin;// 记录长度
//			}
//		}
//	}
//	for (int i = 0;i < len; i++)
//	{
//		cout << str[result + i];
//	}
//	return 0;
//}
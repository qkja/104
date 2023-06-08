/**
* User: Qkj
* Description: 
* Date: 2023-06-08
* Time: 14:57
*/

class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
	
		return (n | (m << j));
	}
};
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;
bool is_prime_numbers(int val)
{
	if (val < 2)
		return false; 

	for (int i = 2; i < val; i++)
	{
		if (val % i == 0)
			return false;
	}
	return true;
}

void pairs_of_prime_numbers(std::vector<int>& result, int val)
{
	result.resize(2, -1);
	std::map<int, int> m; // 一个绝对值 ,一个 有效数据
	for (int i = 2; i < val; i++)
	{
		/*if (i == 0)
		{
			std::cout << i << std::endl;

		}*/
		int ret = val - i;
		if (is_prime_numbers(i) && is_prime_numbers(ret))
		{
			// 求绝对值
			m[abs(ret - i)] = i;
		}
	}

	if (m.empty())
		return;
	result[0] = m.begin()->second;
	result[1] = val - m.begin()->second;
	std::sort(result.begin(), result.end());
}

int main() {
	
	int n = 0;
	std::cin >> n;
    std::vector<int> result;
	pairs_of_prime_numbers(result, n);
	if (result.size() == 2)
	{
		std::cout << result[0] << std::endl;
		std::cout << result[1] << std::endl;
	}
		
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//bool is_perfect_number(int val)
//{
//	int sum = 0;
//	for (int i = 1; i < val; i++)
//	{
//		if (val % i == 0)
//			sum += i;
//	}
//	return  sum == val;
//}
//int main()
//{
//	int n = 0;
//	while (std::cin >> n)
//	{
//		int count = 0;
//		for (int i = 1; i <= n; i++)
//		{
//			if (is_perfect_number(i))
//				count++;
//		}
//		std::cout << count << std::endl;
//	}
//	return  0;
//}
// 64 位输出请用 printf("%lld")
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//void split_hand(const string& s, vector<string>& v) {
//	int begin = 0;
//	while (true) {
//		auto pos = s.find(' ', begin);
//		if (pos == std::string::npos)
//		{
//			v.push_back(s.substr(begin));
//			break;
//		}
//		v.push_back(s.substr(begin, pos-begin));
//		begin = pos + 1;
//	}
//}
//
//
//int main() {
//	std::string hand_cards = "4 4 4 4-joker JOKER";
//
//	// std::getline(std::cin, hand_cards);
//	// 分析手牌
//	auto pos = hand_cards.find('-');
//	std::string hand_cards_one = hand_cards.substr(0, pos);
//	std::string hand_cards_two = hand_cards.substr(pos + 1);
//
//	// 整理排数
//	// 格子 1
//	// 对子 2
//	// 三个 3
//	// 炸 4 或者 两个
//	// 顺子 5
//
//	vector<string> hand_cards_v_one;
//	vector<string> hand_cards_v_two;
//	split_hand(hand_cards_one, hand_cards_v_one);
//	split_hand(hand_cards_two, hand_cards_v_two);
//	for (auto e : hand_cards_v_one)
//	{
//		cout << e << endl;
//	}
//	for (auto e : hand_cards_v_two)
//	{
//		cout << e << endl;
//	}
//	return 0;
//}
// 64 位输出请用 printf("%lld")

//#include <iostream>
//#include <string>
//#include <unordered_map>
//#include <vector>
//
//using namespace std;
//void split_hand(const string& s, vector<string>& v) {
//	int begin = 0;
//	while (true) {
//		auto pos = s.find(' ', begin);
//		if (pos == std::string::npos) {
//			v.push_back(s.substr(begin));
//			break;
//		}
//		v.push_back(s.substr(begin, pos - begin));
//		begin = pos + 1;
//	}
//}
//
//
//int main() {
//
//
//	const char* arr[] = { "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2" };
//	unordered_map<string, int> m;
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		m[arr[i]] = i;
//	}
//	std::string hand_cards;
//
//	std::getline(std::cin, hand_cards);
//	// 分析手牌
//	auto pos = hand_cards.find('-');
//	std::string hand_cards_one = hand_cards.substr(0, pos);
//	std::string hand_cards_two = hand_cards.substr(pos + 1);
//
//	// 整理排数
//	// 格子 1
//	// 对子 2
//	// 三个 3
//	// 炸 4 或者 两个
//	// 顺子 5
//
//	vector<string> hand_cards_v_one;
//	vector<string> hand_cards_v_two;
//	split_hand(hand_cards_one, hand_cards_v_one);
//	split_hand(hand_cards_two, hand_cards_v_two);
//	if (hand_cards_v_one.size() == 4 && hand_cards_v_two.size() == 4) {
//		if (m[hand_cards_v_one[0]] > m[hand_cards_v_two[0]])
//			std::cout << hand_cards_one << std::endl;
//		else
//			std::cout << hand_cards_two << std::endl;
//	}
//	else if (hand_cards_v_one.size() == 4) {
//		// 判断
//		if (hand_cards_v_two.size() == 2 && hand_cards_v_two[0] != hand_cards_v_two[1])
//			std::cout << hand_cards_two << std::endl;
//		else
//			std::cout << hand_cards_one << std::endl;
//
//	}
//	else if (hand_cards_v_two.size() == 4) {
//		// 判断
//		if (hand_cards_v_one.size() == 2 && hand_cards_v_one[0] != hand_cards_v_one[1])
//			std::cout << hand_cards_one << std::endl;
//		else
//			std::cout << hand_cards_two << std::endl;
//	}
//	else if (hand_cards_v_two.size() == 2 &&
//		hand_cards_v_two[0] != hand_cards_v_two[1]) {
//		std::cout << hand_cards_two << std::endl;
//	}
//	else if (hand_cards_v_one.size() == 2 &&
//		hand_cards_v_one[0] != hand_cards_v_one[1]) {
//		std::cout << hand_cards_one << std::endl;
//
//	}
//	else if (hand_cards_v_one.size() == hand_cards_v_two.size()){
//		if (m[hand_cards_v_one[0]] > m[hand_cards_v_two[0]])
//			std::cout << hand_cards_one << std::endl;
//		else
//			std::cout << hand_cards_two << std::endl;
//	}
//	else  {
//		std::cout << "ERROR" << std::endl;
//	}
//
//	// for (auto e : hand_cards_v_one)
//	// {
//	//  cout << e << endl;
//	// }
//	// for (auto e : hand_cards_v_two)
//	// {
//	//  cout << e << endl;
//	// }
//	return 0;
//}
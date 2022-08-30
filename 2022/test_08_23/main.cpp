#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>


using namespace std;
class Solution {
public:
	string replaceSpaces(string S, int length) {
		string str;
		for(int i=0;i < length;i++)
		{

			if (S[i] != ' ')
				str += S[i];
			else
				str += "%20";
		}
		return str;
	}
};
//string abbreviatedWord(string& str)
//{
//	int len = str.size();
//	if (len < 10)
//		return str;
//	string s;
//	s += str[0];
//	s += std::to_string(len - 2);
//	s += str[len - 1];
//	return s;
//}

int main()
{
	int n = 10;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			getchar();
		getline(std::cin, str);
		cout << abbreviatedWord(str) << endl;
	}
	return 0;
}

//class Solution {
//public:
//    bool isUnique(string astr) {
//        int lowerLetters[26] = { 0 };
//        for (char& ch : astr)
//        {
//            int ret = ch - 'a';
//            ++lowerLetters[ret];
//        }
//        for (int i = 0; i < 26; i++)
//        {
//            if (lowerLetters[i] > 1)
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//};
////class Solution {
////public:
//    int FirstNotRepeatingChar(string str) {
//        int upperLetters[26] = { 0 };
//        int lowerLetters[26] = { 0 };
//        /*int upperCount = -1;
//        int lowerCount = -1;*/
//        for (char& ch : str)
//        {
//            int ret = 0;
//            if (ch >= 'a' && ch <= 'z')
//            {
//                ret = ch - 'a';
//                ++lowerLetters[ret];
//                /*if (lowerLetters[ret] == 1)
//                {
//                    lowerCount = ret;
//                }*/
//            }
//            else
//            {
//                ret = ch - 'A';
//                ++upperLetters[ret];
//               /* if (upperLetters[ret] == 1)
//                {
//                    upperCount = ret;
//                }*/
//            }
//        }
//        auto it = str.begin();
//        while (it != str.end())
//        {
//            if (upperLetters[*it - 'A'] == 1 || 1 == lowerLetters[*it - 'a'])
//                return it - str.begin();
//            it++;
//        }
//        /*for (char& ch : str)
//        {
//            if(upperLetters[ch-'A'] == 1 && 1 == lowerLetters[ch-'a'])
//                return 
//        }*/
//        //if()
//        /*for (int i = 0; i < 26; i++)
//        {
//            if (1 == upperLetters[i])
//            {
//                return str.find(i + 'A', 0);
//            }
//        }
//
//        for (int i = 0; i < 26; i++)
//        {
//            if (1 == lowerLetters[i])
//            {
//                return str.find(i + 'a', 0);
//            }
//        }*/
//        return -1;
//    }
////};
//
//int main()
//{
//    string str = "google";
//    cout << FirstNotRepeatingChar(str);
//    //cout << str.find('g', 0);
//    return 0;
//}
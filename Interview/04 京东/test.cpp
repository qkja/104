//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;

// 小红比身高
//int main() {
//    long long n = 0;
//    long long m = 0;
//    long long H = 0;
//    while (cin >> n >> m >> H) {
//        // 朋友的高度
//        vector<long long> friends_height(n, 0);
//        // 朋友占据的位置
//        vector<long long> friends_wait_flore(n, 0);
//        vector<long long> floors_height(m, 0);
//
//        for (int i = 0; i < n; i++) cin >> friends_height[i];
//        for (int i = 0; i < n; i++) cin >> friends_wait_flore[i];
//        for (int i = 0; i < m; i++) cin >> floors_height[i];
//
//
//        unordered_map<long long, long long> mm; //第几个地板, 和高度
//
//        for (int i = 0; i < n; i++) {
//            auto iter = mm.find(friends_wait_flore[i]);
//            if (iter == mm.end() ||
//                (long long)(friends_height[i] + floors_height[friends_wait_flore[i] - 1]) < iter->second) {
//                mm[friends_wait_flore[i]] =
//                    (long long)(friends_height[i] + floors_height[friends_wait_flore[i] - 1]);
//            }
//        }
//
//        // 对于小红来说,站在最高的位置很不错
//
//
//        int max_floor_index = 0;
//        for (int i = 1; i < m; i++) {
//            if (floors_height[i] > floors_height[max_floor_index]) {
//                max_floor_index = i;
//            }
//        }
//        H = floors_height[max_floor_index] + H;
//        long long count = 0;
//        auto iter = mm.begin();
//        while (iter != mm.end()) {
//            if (iter->first != max_floor_index + 1 && iter->second < H) {
//                count++;
//            }
//            ++iter;
//        }
//        cout << count << endl;
//    }
//
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;
//
//int main()
//{
//    int n = 0;
//    int m = 0;
//    int H = 0;
//    cin >> n >> m >> H;
//    // 朋友的高度
//    vector<int> friends_height(n, 0);
//    // 朋友占据的位置
//    vector<int> friends_wait_flore(n, 0);
//    vector<int> floors_height(m, 0);
//
//    for (int i = 0; i < n; i++) cin >> friends_height[i];
//    for (int i = 0; i < n; i++) cin >> friends_wait_flore[i];
//    for (int i = 0; i < m; i++) cin >> floors_height[i];
//
//
//    unordered_map<int, int> mm; //第几个地板, 和高度
//
//    for (int i = 0; i < n; i++)
//    {
//        auto iter = mm.find(friends_wait_flore[i]);
//        if (iter == mm.end() || 
//            friends_height[i] + floors_height[friends_wait_flore[i] - 1] < iter->second)
//        {
//            mm[friends_wait_flore[i]] = 
//                friends_height[i] + floors_height[friends_wait_flore[i] - 1];
//        }
//    }
//
//    // 对于小红来说,站在最高的位置很不错
//
//
//    int max_floor_index = 0;
//    for (int i = 1; i < m; i++)
//    {
//        if (floors_height[i] > floors_height[max_floor_index])
//        {
//            max_floor_index = i;
//        }
//    }
//    H = floors_height[max_floor_index] + H;
//    int count = 0;
//    auto iter = mm.begin();
//    while (iter != mm.end()) 
//    {
//        if (iter->first != max_floor_index+1 && iter->second < H)
//        {
//            count++;
//        }
//        ++iter;
//    }
//    cout << count << endl;
// 
//    return 0;
//}
// 64 位输出请用 printf("%lld")

//int main() 
//{
//    int n = 0;
//    int m = 0;
//    int H = 0;
//    cin >> n >> m >> H;
//    vector<int> friends_height(n, 0);
//    vector<int> floors_height(m, 0);
//
//    for (int i = 0; i < n; i++)
//    {
//        cin >> friends_height[i];
//    }
//    for (int i = 0; i < m; i++)
//    {
//        cin >> floors_height[i];
//    }
//
//    sort(friends_height.begin(), friends_height.end());
//    sort(floors_height.begin(), floors_height.end());
//    // 尽可能让较高的朋友放在较低的台阶
//    
//    
//    int count = 0;
//    int i = 0;
//    int j = m - 1;
//    while (j >=0 && i < n)
//    {
//        if (floors_height[j] + friends_height[i] < H)
//        {
//            i++;
//            j--;
//            count++;
//        }
//        else
//        {
//            j--;
//        }
//    }
//    cout << count << endl;
//    
//    return 0;
//}
//// 64 位输出请用 printf("%lld")


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_multimap<int, int> m;
	m.insert({ 1,1 });
	m.insert({ 1,2 });
	auto iter = m.find(1);
	cout << iter->first << endl;
	cout << iter->second << endl;
	m.erase(iter);
	auto iter2 = m.find(1);
	cout << iter2->first << endl;
	cout << iter2->second << endl;
	return 0;
}

//using namespace std;
//string func(int target, unordered_multimap<int, int>& m)
//{
//   
//    unordered_map<int, unordered_map<int, int>::iterator> s; // 保存叶子节点
//    auto iter = m.begin();
//    while (iter != m.end())
//    {
//        if (m.find(iter->second) == m.end())
//        {
//            // 这是叶子节点
//            s[iter->second] = iter;
//        }
//        ++iter;
//    }
//    // 
//    int count = 1;
//    while (1)
//    {
//        auto iter = m.find(target);
//        if (iter == m.end())
//        {
//            break;
//        }
//        else
//        {
//            // 那么只能删除一个叶子节点了
//            auto it = s.begin();
//            it->second->second = -1;
//            // 这里需要判断下
//            auto f = m.find(it->second->first);
//            m.erase(f);
//            s.erase(it->first);
//            count++;
//        }
//    }
//    if (count % 2 == 1)
//        return "win";
//    else
//        return "lose";
//}
//int main() {
//    int n = 0;
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        int n = 0;
//        int x = 0;
//        cin >> n >> x;
//        unordered_multimap<int, int> m;
//        for (int j = 0; j < n - 1; j++)
//        {
//            int a = 0;
//            int b = 0;
//            cin >> a >> b;
//            m.insert({ a, b });
//        }
//        cout << func(x, m) << endl;
//    }
//    return 0;
//}
//// 64 位输出请用 printf("%lld")